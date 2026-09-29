/*
 * tab5kbd.h — M5Stack Tab5 Keyboard (SKU A164) driver, Character mode.
 *
 * Library-free, non-blocking, one event per call. Written against
 * tab5_keyboard_reference.md; all register values and the length semantics
 * were verified on hardware 15 Sep.
 *
 * WHY NOT M5's LIBRARY: UnitUnified/M5Unified are ESP32-ecosystem and won't
 * build on a Pico. More importantly they own their own update loop, and this
 * project's priority is that MIDI and audio are never stalled by anything.
 *
 * DESIGN RULES, both consequences of that priority:
 *   - read() returns AT MOST ONE event per call and never blocks or retries.
 *     A burst of keypresses is spread across loop iterations rather than
 *     drained in one go.
 *   - I2C is only touched when INT is asserted or events are known pending.
 *     An idle keyboard costs one digitalRead() per loop.
 *
 * ⚠️ THE TRAP (cost a debugging session): clearing INT_STAT acknowledges the
 * interrupt but does NOT consume events. With a non-empty queue INT re-asserts
 * within ~2 ms, forever. INT_STAT is therefore cleared here only once the
 * queue is actually drained.
 */

#ifndef TAB5KBD_H
#define TAB5KBD_H

#include <Arduino.h>
#include <Wire.h>

enum Tab5KeyCode : uint8_t {
  TAB5_CHAR = 0,     // literal character, use Tab5Key::c
  TAB5_ENTER,
  TAB5_BACKSPACE,
  TAB5_DEL,
  TAB5_ESC,
  TAB5_TAB,
  TAB5_UP,
  TAB5_DOWN,
  TAB5_LEFT,
  TAB5_RIGHT,
  TAB5_UNKNOWN       // name not recognised; raw string still in Tab5Key::name
};

struct Tab5Key {
  Tab5KeyCode code;
  char        c;        // valid when code == TAB5_CHAR
  const char *name;     // always the raw string from the device
  uint8_t     mod;      // bit0 = Ctrl, bit2 = Alt
  bool ctrl() const { return mod & 0x01; }
  bool alt()  const { return mod & 0x04; }
};

class Tab5Keyboard {
public:
  // intPin = -1 falls back to polling every pollMs.
  bool begin(TwoWire &bus, int intPin, uint8_t addr = 0x6D, uint16_t pollMs = 20) {
    _bus = &bus; _int = intPin; _addr = addr; _pollMs = pollMs;
    if (_int >= 0) pinMode(_int, INPUT);

    uint8_t v;
    if (!readReg(REG_FW_VER, &v, 1)) return false;   // real comms, not just ACK
    _fwVersion = v;

    // Character mode. Switching modes also clears the previous mode's queue
    // and releases the interrupt — which is the clean way to start.
    if (!writeReg(REG_MODE, 2)) return false;
    writeReg(REG_EVENT_NUM, 0);     // belt and braces
    writeReg(REG_INT_STAT, 0);
    _pending = 0;
    return true;
  }

  uint8_t firmwareVersion() const { return _fwVersion; }

  // Returns true and fills `out` if an event was available. Never blocks.
  bool read(Tab5Key &out) {
    if (_pending == 0) {
      if (_int >= 0) {
        if (digitalRead(_int) != LOW) return false;      // idle: no I2C at all
      } else {
        if (millis() - _lastPoll < _pollMs) return false;
        _lastPoll = millis();
      }
      if (!readReg(REG_EVENT_NUM, &_pending, 1)) return false;
      if (_pending == 0) {            // spurious assert; acknowledge and go
        writeReg(REG_INT_STAT, 0);
        return false;
      }
    }

    uint8_t len = 0;
    if (!readReg(REG_CHAR_LEN, &len, 1) || len == 0) { finish(); return false; }
    if (len > sizeof(_buf) - 1) len = sizeof(_buf) - 1;

    // len INCLUDES the null terminator (2 for one char, 10 for "BACKSPACE").
    // So read len+1 bytes: modifier, then the already-terminated string.
    uint8_t raw[20];
    if (!readReg(REG_CHAR_EVT, raw, len + 1)) { finish(); return false; }

    out.mod = raw[0];
    memcpy(_buf, raw + 1, len);
    _buf[len] = '\0';                 // defensive; device already terminates
    out.name = _buf;
    out.c    = _buf[0];
    out.code = classify(_buf, len);

    if (_pending) _pending--;
    if (_pending == 0) finish();      // only NOW is it safe to clear INT_STAT
    return true;
  }

  // Discard anything queued (e.g. when switching between edit and play).
  void flush() {
    writeReg(REG_EVENT_NUM, 0);
    writeReg(REG_INT_STAT, 0);
    _pending = 0;
  }

  // RGB: mode 1 = custom, then per-LED colour. Handy as a mode indicator.
  void setRgbCustom(bool on) { writeReg(REG_RGB_MODE, on ? 1 : 0); }
  void setRgb(uint8_t idx, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t base = (idx == 0) ? 0x60 : 0x64;     // note the gap at 0x63
    writeReg(base + 0, b);
    writeReg(base + 1, g);
    writeReg(base + 2, r);
  }
  void setBrightness(uint8_t pct) { writeReg(REG_BRIGHT, pct > 100 ? 100 : pct); }

private:
  static const uint8_t REG_INT_CFG   = 0x00;
  static const uint8_t REG_INT_STAT  = 0x01;
  static const uint8_t REG_EVENT_NUM = 0x02;
  static const uint8_t REG_BRIGHT    = 0x03;
  static const uint8_t REG_MODE      = 0x10;
  static const uint8_t REG_RGB_MODE  = 0x11;
  static const uint8_t REG_CHAR_LEN  = 0x40;
  static const uint8_t REG_CHAR_EVT  = 0x50;
  static const uint8_t REG_FW_VER    = 0xFE;

  TwoWire *_bus     = nullptr;
  int      _int     = -1;
  uint8_t  _addr    = 0x6D;
  uint8_t  _pending = 0;
  uint8_t  _fwVersion = 0;
  uint16_t _pollMs  = 20;
  uint32_t _lastPoll = 0;
  char     _buf[16];

  void finish() { writeReg(REG_INT_STAT, 0); _pending = 0; }

  bool readReg(uint8_t reg, uint8_t *buf, uint8_t len) {
    _bus->beginTransmission(_addr);
    _bus->write(reg);
    if (_bus->endTransmission(false) != 0) return false;     // repeated start
    if (_bus->requestFrom(_addr, len) != len) return false;
    for (uint8_t i = 0; i < len; i++) buf[i] = _bus->read();
    return true;
  }

  bool writeReg(uint8_t reg, uint8_t val) {
    _bus->beginTransmission(_addr);
    _bus->write(reg);
    _bus->write(val);
    return _bus->endTransmission() == 0;
  }

  static bool ieq(const char *a, const char *b) {
    while (*a && *b) {
      if (tolower((unsigned char)*a++) != tolower((unsigned char)*b++)) return false;
    }
    return *a == *b;
  }

  // len includes the terminator, so len==2 means exactly one character.
  // Named keys arrive in either case depending on Aa state ("enter"/"ENTER"),
  // hence the case-insensitive compare.
  static Tab5KeyCode classify(const char *s, uint8_t len) {
    if (len <= 2) return TAB5_CHAR;
    if (ieq(s, "enter"))     return TAB5_ENTER;
    if (ieq(s, "backspace")) return TAB5_BACKSPACE;
    if (ieq(s, "del"))       return TAB5_DEL;
    if (ieq(s, "esc"))       return TAB5_ESC;
    if (ieq(s, "tab"))       return TAB5_TAB;
    if (ieq(s, "up"))        return TAB5_UP;
    if (ieq(s, "down"))      return TAB5_DOWN;
    if (ieq(s, "left"))      return TAB5_LEFT;
    if (ieq(s, "right"))     return TAB5_RIGHT;
    return TAB5_UNKNOWN;
  }
};

#endif
