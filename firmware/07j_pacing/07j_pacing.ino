/*
 * MIDI Voice Box Synth — Step 7j: paced TX — faster retrigger cut
 * ---------------------------------------------------------------
 * 07i plus ONE change: bytes are metered into the UART at about the line rate
 * instead of being dumped into its 32-byte FIFO. A retrigger can only cut the
 * sound once the bytes already handed to the UART have physically gone out, so
 * keeping that FIFO nearly empty is what makes the cut prompt:
 *   worst-case flush delay  ~37 ms  ->  ~5 ms   (host simulator)
 * Throughput is unchanged; the bytes simply wait in our RAM queue, where a
 * retrigger can still discard them, instead of in the FIFO, where it cannot.
 *
 * Files: 07j_pacing.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7i header follows ----
 *
 * MIDI Voice Box Synth — Step 7i: presets + keyboard functions
 * ------------------------------------------------------------
 * 07h plus the number row and the symbol row:
 *   0-9         recall lyric preset (nothing happens if the slot is empty)
 *   ctrl+0-9    SAVE the current lyric to that slot, in flash
 *   ! @ # $ % ^ & *   the performance commands that used to need the terminal
 * Every one of them confirms itself on a status line on the OLED, because on
 * stage the debug probe isn't connected.
 * ⚠️ Digits and those symbols no longer type into the lyric. No dictionary
 * tier speaks digits, and the symbols are token breaks like space, so nothing
 * is lost.
 *
 * Files: 07i_presets.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7h header follows ----
 *
 * MIDI Voice Box Synth — Step 7h: edit view (cursor + navigation + undo)
 * ----------------------------------------------------------------------
 * 07g plus editing on the Tab5 keyboard. There is no separate "edit mode":
 * the one view is always editable, and the cursor is always on screen.
 *   left/right  one character      ctrl+left/right  one word
 *   up/down     start / end of text
 *   tab         jump to the word the playhead is on
 *   esc         clear the whole lyric      ctrl+z  undo it (press again: redo)
 *   backspace / del as before
 * The blinking bar is the cursor; the inverted block is still the playhead.
 * The window follows the cursor while you type, the playhead otherwise.
 *
 * Presets on the number keys and terminal functions on the symbol row are
 * step 7i.
 *
 * Files: 07h_editview.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7g header follows ----
 *
 * MIDI Voice Box Synth — Step 7g: highlight the SOUNDING word
 * -----------------------------------------------------------
 * 07f plus ONE change: the display shows the word currently being spoken, and
 * the highlight moves to the next word when that word FINISHES — before the
 * next note is played. So it reads as "this is sounding now", then becomes
 * "this is what's next". Until 7f the playhead advanced at note-on, so the
 * display always showed the upcoming word; that read as attractive in theory
 * and wrong in practice over weeks of playing.
 *
 * The end of a word is ESTIMATED from the manual's per-allophone durations
 * (Table D, 10-225 ms each), since the chip's D1/Speaking output is not wired.
 * 'w' prints the estimates and calibrates the scale factor by ear.
 *
 * Files: 07g_sounding.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7f header follows ----
 *
 * MIDI Voice Box Synth — Step 7f: playhead anchored to the text
 * -------------------------------------------------------------
 * 07e plus ONE change: the playhead remembers WHERE IN THE TEXT it is, not
 * which token number. Editing earlier in the lyric used to shift every later
 * token index, so the next word to be sung silently changed. Now inserting or
 * deleting before your place keeps the same word next.
 *
 * Files: 07f_playhead.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7e header follows ----
 *
 * MIDI Voice Box Synth — Step 7e: 30,000-word dictionary
 * ------------------------------------------------------
 * 07d plus ONE change: a third, much larger dictionary (bigdict.cpp) searched
 * after extradict.h and the Sensory standard dictionary. 30,000 of the most
 * frequent English words, pronunciations from CMUdict, converted to SpeakJet
 * codes by a model learned from Sensory's hand-tuned entries (cmu2bigdict.py).
 * Stored as one sorted blob in flash (~600 KB) and found by binary search.
 * '?word' reports which dictionary answered: [extra], [standard] or [cmu].
 *
 * Files: 07e_bigdict.ino, bigdict.cpp, bigdict.h, tab5kbd.h, dict.h,
 *        extradict.h, standardDict.cpp, eltro_font5x7.h
 *
 * ---- step 7d header follows ----
 *
 * MIDI Voice Box Synth — Step 7d: SpeakJet TX queue
 * -------------------------------------------------
 * 07c plus ONE change: note bytes no longer go to Serial2 from inside the MIDI
 * callback. speakNext() enqueues them; sjqService() feeds the UART from loop()
 * without ever blocking. Note logging is deferred to loop() the same way.
 * Host simulator, fxcountdown: note-on callback 35 ms -> ~0 ms.
 * New menu key: 'q' shows TX queue statistics.
 *
 * Files: 07d_txqueue.ino, tab5kbd.h, dict.h, extradict.h, standardDict.cpp,
 *        eltro_font5x7.h
 *
 * ---- step 7c header follows ----
 *
 * MIDI Voice Box Synth — Step 7c: review fixes (no new features)
 * --------------------------------------------------------------
 * 07_synth_kbd plus the known-outcome fixes from the 16 Sep code review:
 *   - note logging defaults OFF (it printed from inside the note-on callback)
 *   - 't' and '?' serial input no longer block loop(): MIDI, keyboard and
 *     display keep running while you type
 *   - a second USB MIDI device is really ignored now (it used to take over),
 *     and unplugging it no longer disconnects the first
 *   - lyric tokeniser also breaks on ! ? ; : " ( )
 *   - dead code and stale comments removed or corrected
 * The SpeakJet TX path is UNCHANGED here; the TX queue is step 7d.
 *
 * Files: 07c_fixes.ino, tab5kbd.h, dict.h, extradict.h, standardDict.cpp,
 *        eltro_font5x7.h
 *
 * ---- step 7 header follows ----
 *
 * MIDI Voice Box Synth — Step 7: + Tab5 keyboard (live lyric editing)
 * --------------------------------------------------------------------
 * 05_synth_oled.ino plus the M5Stack Tab5 Keyboard on I2C0. Typing now edits
 * the lyric buffer live, replacing the 't'-over-serial stand-in (which is
 * retained as a fallback).
 *
 * ⚠️ THE EDIT VIEW IS DELIBERATELY NOT DONE YET. The OLED has a dead segment
 * and is being replaced, so layout decisions are deferred. This build keeps the
 * PLAY view and simply lets typing change the text underneath it — enough to
 * prove the keyboard driver coexists with MIDI, audio and the display.
 *
 * Bus layout (note the counterintuitive naming):
 *   I2C0 = Wire  on GP8/GP9  -> Tab5 Keyboard 0x6D, INT on GP10
 *   I2C1 = Wire1 on GP2/GP3  -> SH1106 OLED   0x3C
 *
 * Files: 07_synth_kbd.ino, tab5kbd.h, dict.h, extradict.h, standardDict.cpp,
 *        eltro_font5x7.h
 *
 * ---- original step 5 header follows ----
 *
 * MIDI Voice Box Synth — Step 5: dictionary + OLED play view
 * -----------------------------------------------------------
 * 04_dictionary.ino plus the SH1106 display. Controller confirmed as SH1106
 * by the 06_oled test (column offset 2), address 0x3C by the 06a scan.
 *
 * DISPLAY DESIGN: while playing, the one thing you can't get from the sound is
 * WHERE YOU ARE IN THE LYRIC. Speed and Bend are audible; the note is under
 * your finger. So the layout spends its pixels on position, not parameters:
 *   - current token large (2x) across the middle, readable at arm's length
 *   - a 3-line lyric window with the playhead inverted, auto-scrolled
 *   - a thin status line: MIDI state, token position, and a miss indicator
 *     (dictionary misses are otherwise invisible — they're just silence)
 *
 * An edit view for the HID keyboard comes later; this is the play view.
 *
 * Files: 05_synth_oled.ino, dict.h, extradict.h, standardDict.cpp,
 *        eltro_font5x7.h
 *
 * ---- original step 4 header follows ----
 *
 * MIDI Voice Box Synth — Step 4: real dictionary, arbitrary lyrics
 * ----------------------------------------------------------------
 * Replaces step 3's six hardcoded token arrays with the 1427-word dictionary
 * from Mike McCauley's SpeakJet library, plus a text buffer that is tokenised
 * on whitespace and hyphens. Each note-on speaks the next token.
 *
 * ARCHITECTURAL NOTE: we took the library's DATA, not its CODE. Its speaking
 * machinery (SoftwareSerial, blocking per-code RDY polling, speak-a-whole-
 * string) conflicts with everything built in steps 1-3: hardware UART,
 * non-blocking FIFO writes, our own parameter block, SCP flush on retrigger,
 * one token per note. Porting it would have meant forking most of it away.
 * Consequence: the "SoftwareSerial vs HardwareSerial fork" open question in
 * the project doc is moot — we never call the library's serial layer at all.
 *
 * Files: 04_dictionary.ino, dict.h, standardDict.cpp
 *
 * Still deliberately excluded:
 *   - HID keyboard (text is set over the debug serial with 't' for now)
 *   - OLED
 *
 * Built on the user's EZ_USB_MIDI_HOST passthrough sketch (rppicomidi), UPDATED to
 * the library's v2.0.0+ API. The passthrough sketch was written against the pre-2.0
 * API, which no longer compiles: v2 made EZ_USB_MIDI_HOST a template parameterised
 * on a settings class, because the Arduino IDE can't configure libraries via
 * preprocessor macros. Instances must now come from RPPICOMIDI_EZ_USB_MIDI_HOST_INSTANCE().
 * v2 also favours per-type handlers (setHandleNoteOn) over the generic setHandleMessage.
 *
 * !! IMPORTANT CHANGE FROM THAT SKETCH !!
 * The passthrough used Serial2 on GP4/GP5 for DIN MIDI at 31250 baud. Those are
 * the SpeakJet's pins in this design. All DIN MIDI objects have been REMOVED and
 * Serial2 now belongs to the SpeakJet at 9600 baud. Do not reintroduce DINmidi.
 *
 * Board:     Raspberry Pi Pico 2 (plain, NOT the W)
 * USB Stack: Tools -> USB Stack -> "Adafruit TinyUSB Host (native)"
 *
 * POWER: feed 5V to VSYS (pin 39) AND tie VBUS (pin 40) to the same 5V. In host
 * mode the Pico must SOURCE VBUS for the bus-powered hub; its internal diode only
 * runs VBUS->VSYS, so without the tie nothing enumerates. Same 5V to the shield
 * and the shifter's HV side. Never put 9-12V on VSYS (5.5V max). ⚠️ With the tie
 * in place, never plug the micro-USB into a computer while this supply is live.
 * See wiring_schematic.md §3.
 */

#ifndef USE_TINYUSB_HOST
#error "Please Select USB Stack: Adafruit TinyUSB Host"
#else
#warning "All Serial Monitor Output is on Serial1 (via Debug Probe UART bridge)"
#endif

#include "EZ_USB_MIDI_HOST.h"
#include "dict.h"
#include "extradict.h"
#include "bigdict.h"         // generated by cmu2bigdict.py
#include <EEPROM.h>          // flash-backed preset storage (7i)
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <Wire.h>
#include "eltro_font5x7.h"
#include "tab5kbd.h"

// These must precede ANY use of MIDI/EZ types. The Arduino IDE auto-generates
// function prototypes and inserts them straight after the last #include, so
// using-declarations placed further down arrive too late and the prototypes
// fail with "'Channel' was not declared in this scope". Handler signatures are
// also written as midi::Channel rather than bare Channel, belt and braces.
USING_NAMESPACE_MIDI
USING_NAMESPACE_EZ_USB_MIDI_HOST

// Forward declarations: speakNext() and the MIDI connect/disconnect callbacks
// all trigger a redraw, but the play view is defined further down (it depends
// on the token layout and drawing primitives). Declared explicitly rather than
// relying on the IDE's auto-prototyping, which has already bitten once.
static void renderPlayView();
static bool midiConnected = false;

// Set instead of rendering directly. renderPlayView() does a dictionary scan,
// a full framebuffer redraw and a 1024-byte diff — far too much to run inside
// the MIDI note-on callback, which is where it originally sat. Notes were
// being swallowed as a result. The callback now only raises this flag and
// loop() does the work, after MIDI has been serviced.
static volatile bool displayDirty = false;

// Serial line-input mode, used by lineBegin() further down. Declared up here
// because the Arduino IDE inserts auto-generated prototypes before the FIRST
// function definition in the file; any type used in a function signature must
// be declared above that point, or the prototype fails to compile.
enum LineMode : uint8_t { LINE_NONE, LINE_LYRIC, LINE_LOOKUP, LINE_SCALE };

// One deferred note-log record (7d). Up here for the same prototype reason.
struct NoteLog {
  uint8_t note, hz, vel, spd, bnd, token, codes;
  uint8_t kind;                                  // 0 spoken, 1 dictionary miss, 2 queue full
  char    text[24];
};

static Tab5Keyboard kbd;
static bool   kbdOk  = false;
static size_t cursor = 0;          // insertion point in lyricText

// ---------------------------------------------------------------------------
// Pins — see wiring_schematic.md. Shield pins 2/3/13 hardware-verified.
// ---------------------------------------------------------------------------
const uint8_t PIN_SJ_TX  = 4;    // -> shifter ch1 -> shield pin 2  (SpeakJet RX)
const uint8_t PIN_SJ_RX  = 5;    // shifter ch2 — drives NOTHING (the SpeakJet has no TX);
                                 // assigned only because Serial2 needs an RX pin
const uint8_t PIN_SJ_RDY = 6;    // <- shifter ch3 <- shield pin 13 (D0/Ready)
const uint8_t PIN_SJ_RES = 7;    // -> shifter ch4 -> shield pin 3  (RES, active low)

const uint8_t PIN_SMPS_MODE = 23;  // onboard SMPS: HIGH = PWM mode, low ripple

const uint8_t PIN_SDA = 2;         // I2C1 (NOT Wire/I2C0 — those pins are the
const uint8_t PIN_SCL = 3;         // SpeakJet UART). OLED on 3V3, no shifter.

const uint8_t PIN_KBD_SDA = 8;     // I2C0 — Tab5 Keyboard, 3V3, no shifter
const uint8_t PIN_KBD_SCL = 9;
const uint8_t PIN_KBD_INT = 10;

const unsigned long SJ_BAUD  = 9600;
const unsigned long DBG_BAUD = 115200;

// ---------------------------------------------------------------------------
// SpeakJet command codes — User's Manual Table D
// ---------------------------------------------------------------------------
const uint8_t SJ_VOLUME = 20;
const uint8_t SJ_SPEED  = 21;
const uint8_t SJ_PITCH  = 22;
const uint8_t SJ_BEND   = 23;   // formant shift; 0..15, default 5

// Bend is sent with every note for two reasons:
//  1. DETERMINISM. Many fx* entries set Speed, Bend or Pitch mid-entry, and all
//     of those latch. The corrected fx entries in extradict.h deliberately drop
//     Sensory's Reset codes, so this parameter block is the ONLY thing that
//     restores the performer's state on the next note. Keep all four in it.
//  2. It's a live control: mod wheel (CC1) drives it. See onControlChange.
// Fixed overhead per note: the SCP flush and parameter block reach the chip
// before any phoneme sounds (~12 bytes at 9600 baud), plus a little slack.
const uint16_t SPEECH_LATENCY_MS = 15;
const uint8_t SJ_BEND_DEFAULT = 5;    // manual's default
const uint8_t SJ_BEND_MAX     = 15;   // deep hollow (0) .. high metallic (15)

const uint8_t SJ_VOL_FIXED     = 96;    // matches SpeakJet's own default
const uint8_t SJ_SPEED_DEFAULT = 114;   // manual's default; near the TOP of 0..127

// Pitch-bend wheel drives SPEED, not pitch (see project doc). The wheel is
// spring-loaded / self-centring, which suits a "deviate and return" rubato
// gesture better than a one-shot pitch nudge.
//
// NOTE THE ASYMMETRY: default 114 is only 13 below max 127, so a linear map
// across a symmetric wheel would give a negligible "rush" and an enormous
// "drag". Each direction is therefore scaled independently.
const uint8_t SJ_SPEED_MAX = 127;   // full bend UP   -> fastest
const uint8_t SJ_SPEED_MIN = 45;    // full bend DOWN -> slowest; tune by ear.
                                    // 0 is legal but likely absurdly slow.

// Documented singing range, confirmed by ear in step 1: register value == Hz.
const uint8_t SJ_PITCH_MIN = 32;
const uint8_t SJ_PITCH_MAX = 240;

// Playable MIDI range implied by 32..240 Hz: C1 (32.7 Hz) .. Bb3 (233.1 Hz).
// Note that 240 Hz is Bb3 — the ENTIRE instrument lives below middle C.
const int MIDI_NOTE_MIN = 24;
const int MIDI_NOTE_MAX = 58;

// Transpose applied before range folding. Without it the keyboard's natural
// range sits mostly above the instrument's ceiling, so the upper third of the
// keys fold back down an octave and the top sounds LOWER than the middle.
// A KeyStep's 32 keys span MIDI 36..67; -12 maps them to 24..55, which fits
// entirely inside the playable window, so pitch rises monotonically across the
// whole keyboard and the fold never triggers at the default octave setting.
// Adjust if using a controller with a different key span.
const int NOTE_TRANSPOSE = -12;

// ---------------------------------------------------------------------------
// Lyrics: a plain text buffer, tokenised on whitespace AND hyphens.
// Stand-in for what the USB HID keyboard will edit later.
// ---------------------------------------------------------------------------
const size_t LYRIC_MAX = 256;
char lyricText[LYRIC_MAX] = "hello i am a robot and i can sing for you";

const uint8_t TOKEN_MAX = 64;
struct TokenRef { uint16_t start; uint8_t len; };
static TokenRef tokens[TOKEN_MAX];
static uint8_t  tokenCount = 0;

// Declared here rather than in the State section below: the live-editing
// helpers sit in this block and need it, and it is lyric state anyway.
static uint8_t  playhead   = 0;      // index into tokens[]: the word the NEXT note sings
// Character offset in lyricText of that word's first letter. This is the real
// anchor; `playhead` is derived from it after every edit. A token INDEX cannot
// survive editing: inserting a word near the start renumbers every later token,
// so index 4 stops meaning the word you were on. Always move the playhead with
// setPlayhead() / syncPlayheadFromOffset() so the two stay in step.
static uint16_t playheadOffset = 0;
// One-level undo for the destructive edits (esc clear, 't' replace). Pressing
// ctrl+z again swaps back, so it doubles as redo.
static char     undoText[LYRIC_MAX] = "";
static size_t   undoCursor = 0;
static uint16_t undoOffset = 0;
static bool     undoValid  = false;
// Transient message on the status line: what a keyboard command just did.
// On stage there is no terminal, so this is the only feedback there is.
static char          statusMsg[22] = "";
static unsigned long statusUntilMs = 0;
const unsigned long  STATUS_MS = 1800;
// Cursor blink, and which of cursor/playhead the window should follow.
static bool         cursorOn     = true;
static unsigned long cursorBlinkMs = 0;
static unsigned long lastEditMs   = 0;
const unsigned long  CURSOR_BLINK_MS  = 500;
const unsigned long  FOLLOW_CURSOR_MS = 4000;   // after a keystroke, scroll to the cursor
// A word is sounding and the highlight has not moved on yet (7g).
static bool     wordSounding = false;
static uint32_t wordEndsAtMs = 0;

// Hyphens split like spaces. NOTE: far less useful than the design assumed --
// the dictionary is word-based, so fragments only resolve if they happen to be
// words themselves. "ro" and "hel" both miss; "bot" happens to hit.
// The APOSTROPHE must NOT be a break: the contractions in extradict.h
// ("can't", "they're") only match as whole tokens.
static bool isTokenBreak(char c) {
  return c == ' ' || c == '\t' || c == '-' || c == ',' || c == '.' ||
         c == '!' || c == '?' || c == ';' || c == ':' || c == '"' ||
         c == '(' || c == ')' || c == '\r' || c == '\n';
}

static void retokenise() {
  tokenCount = 0;
  size_t i = 0;
  while (lyricText[i] && tokenCount < TOKEN_MAX) {
    while (lyricText[i] && isTokenBreak(lyricText[i])) i++;
    if (!lyricText[i]) break;
    uint16_t start = i;
    while (lyricText[i] && !isTokenBreak(lyricText[i])) i++;
    uint8_t len = (uint8_t)(i - start);
    if (len > 0) { tokens[tokenCount].start = start; tokens[tokenCount].len = len; tokenCount++; }
  }
}

// --- playhead ---------------------------------------------------------------
// Set the playhead by token index and record where that word starts in the text.
static void setPlayhead(uint8_t idx) {
  if (tokenCount == 0) { playhead = 0; playheadOffset = 0; return; }
  if (idx >= tokenCount) idx = tokenCount - 1;
  playhead = idx;
  playheadOffset = tokens[idx].start;
}

// Recover the token index from the character offset, after re-tokenising.
// Preference order: the token CONTAINING the offset (so typing inside the
// anchored word keeps it), else the first token starting after it (so deleting
// the anchored word moves on to the next one), else the last token.
static void syncPlayheadFromOffset() {
  if (tokenCount == 0) { playhead = 0; playheadOffset = 0; return; }
  for (uint8_t i = 0; i < tokenCount; i++) {
    const TokenRef &t = tokens[i];
    if (playheadOffset >= t.start && playheadOffset < (uint16_t)(t.start + t.len)) { playhead = i; return; }
    if (t.start >= playheadOffset) { playhead = i; playheadOffset = t.start; return; }
  }
  playhead = tokenCount - 1;
  playheadOffset = tokens[playhead].start;
}

// --- live editing -----------------------------------------------------------
// After any text change: re-tokenise, then recover the playhead from its
// character offset. Each edit first shifts that offset if it happened BEFORE
// the anchored word; an edit inside or after it leaves the offset alone.
// Enter (or '0') resets to the start explicitly when you do want that.
static void textChanged() {
  retokenise();
  syncPlayheadFromOffset();
  displayDirty = true;
}

// Show a short message on the status line for STATUS_MS.
static void status(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(statusMsg, sizeof(statusMsg), fmt, ap);
  va_end(ap);
  statusUntilMs = millis() + STATUS_MS;
  displayDirty  = true;
  Serial1.printf("%s\r\n", statusMsg);        // and on the terminal, if attached
}

// ---------------------------------------------------------------------------
// Lyric presets, 10 slots in flash
// ---------------------------------------------------------------------------
// arduino-pico's EEPROM library is a RAM buffer that is written back to one
// flash sector on commit(). ⚠️ commit() erases and rewrites that sector with
// interrupts off, which stalls everything for a few ms — so it happens ONLY on
// an explicit ctrl+digit save, never automatically.
//
// Layout: magic, version, then 10 fixed-size slots holding a NUL-terminated
// lyric. Fixed size keeps writes simple and the whole thing is 2.5 KB of the
// 4 KB sector. A slot whose first byte is 0 or 0xFF (erased flash) is empty.
const uint16_t PRESET_COUNT = 10;
const uint16_t PRESET_SIZE  = LYRIC_MAX;          // 256 bytes each
const uint16_t PRESET_BASE  = 8;                  // after the header
const uint32_t PRESET_MAGIC = 0x56425831;         // "VBX1"
const uint16_t EEPROM_SIZE  = PRESET_BASE + PRESET_COUNT * PRESET_SIZE;

static void presetsBegin() {
  EEPROM.begin(EEPROM_SIZE);
  uint32_t magic = 0;
  for (uint8_t i = 0; i < 4; i++) magic |= (uint32_t)EEPROM.read(i) << (8 * i);
  if (magic == PRESET_MAGIC) return;
  // Unformatted (new board, or previously used for something else): clear it.
  for (uint16_t i = 0; i < EEPROM_SIZE; i++) EEPROM.write(i, 0);
  for (uint8_t i = 0; i < 4; i++) EEPROM.write(i, (uint8_t)(PRESET_MAGIC >> (8 * i)));
  EEPROM.commit();
  Serial1.println(F("presets: storage initialised (all slots empty)"));
}

static bool presetRead(uint8_t slot, char *out, size_t outSize) {
  if (slot >= PRESET_COUNT) return false;
  uint16_t base = PRESET_BASE + slot * PRESET_SIZE;
  uint8_t  first = EEPROM.read(base);
  if (first == 0 || first == 0xFF) return false;              // empty slot
  size_t i = 0;
  for (; i < PRESET_SIZE - 1 && i < outSize - 1; i++) {
    uint8_t c = EEPROM.read(base + i);
    if (c == 0 || c == 0xFF) break;
    out[i] = (char)c;
  }
  out[i] = '\0';
  return i > 0;
}

static void presetSave(uint8_t slot) {
  if (slot >= PRESET_COUNT) return;
  uint16_t base = PRESET_BASE + slot * PRESET_SIZE;
  size_t   n    = strlen(lyricText);
  if (n > PRESET_SIZE - 1) n = PRESET_SIZE - 1;
  for (uint16_t i = 0; i < PRESET_SIZE; i++)
    EEPROM.write(base + i, (i < n) ? (uint8_t)lyricText[i] : 0);
  EEPROM.commit();                      // the one place flash is written
  status("preset %u saved", slot);
}

// Remember the text before a destructive change, so ctrl+z can bring it back.
static void pushUndo() {
  memcpy(undoText, lyricText, LYRIC_MAX);
  undoCursor = cursor;
  undoOffset = playheadOffset;
  undoValid  = true;
}

// Swap current and remembered text: undo, and undo again to redo.
static void swapUndo() {
  if (!undoValid) return;
  char     tmpText[LYRIC_MAX];
  size_t   tmpCursor = cursor;
  uint16_t tmpOffset = playheadOffset;
  memcpy(tmpText, lyricText, LYRIC_MAX);
  memcpy(lyricText, undoText, LYRIC_MAX);
  memcpy(undoText, tmpText, LYRIC_MAX);
  cursor         = undoCursor < strlen(lyricText) ? undoCursor : strlen(lyricText);
  playheadOffset = undoOffset;
  undoCursor = tmpCursor;
  undoOffset = tmpOffset;
  retokenise();
  syncPlayheadFromOffset();
  displayDirty = true;
}

static void clearLyric() {
  pushUndo();
  lyricText[0] = '\0';
  cursor = 0;
  playheadOffset = 0;
  textChanged();
}

// Recall is destructive, so it is undoable like esc and 't'.
static void presetRecall(uint8_t slot) {
  char buf[LYRIC_MAX];
  if (!presetRead(slot, buf, sizeof(buf))) { status("preset %u empty", slot); return; }
  pushUndo();
  strncpy(lyricText, buf, LYRIC_MAX - 1);
  lyricText[LYRIC_MAX - 1] = '\0';
  cursor = strlen(lyricText);
  playheadOffset = 0;
  textChanged();
  setPlayhead(0);
  status("preset %u loaded", slot);
}

// Cursor movement by whole words: to the start of the previous / next word.
static void cursorWordLeft() {
  if (cursor == 0) return;
  cursor--;
  while (cursor > 0 && isTokenBreak(lyricText[cursor])) cursor--;
  while (cursor > 0 && !isTokenBreak(lyricText[cursor - 1])) cursor--;
}

static void cursorWordRight() {
  size_t n = strlen(lyricText);
  while (cursor < n && !isTokenBreak(lyricText[cursor])) cursor++;
  while (cursor < n && isTokenBreak(lyricText[cursor])) cursor++;
}

static void insertChar(char c) {
  size_t n = strlen(lyricText);
  if (n + 1 >= LYRIC_MAX) return;
  memmove(lyricText + cursor + 1, lyricText + cursor, n - cursor + 1);
  lyricText[cursor] = c;
  // Strictly before: inserting AT the first letter must not push the anchor off
  // the character just typed, or splitting the word with a space would skip it.
  if (cursor < playheadOffset) playheadOffset++;
  cursor++;
  textChanged();
}

static void backspaceChar() {
  if (cursor == 0) return;
  size_t n = strlen(lyricText);
  memmove(lyricText + cursor - 1, lyricText + cursor, n - cursor + 1);
  cursor--;
  if (cursor < playheadOffset) playheadOffset--;   // the deleted character was before it
  textChanged();
}

static void deleteForward() {
  size_t n = strlen(lyricText);
  if (cursor >= n) return;
  memmove(lyricText + cursor, lyricText + cursor + 1, n - cursor);
  if (cursor < playheadOffset) playheadOffset--;
  textChanged();
}

// Case-insensitive compare of a token slice against a dictionary word.
static bool tokenMatches(const TokenRef &t, const char *word) {
  for (uint8_t k = 0; k < t.len; k++) {
    char a = (char)tolower((unsigned char)lyricText[t.start + k]);
    if (word[k] == '\0' || a != word[k]) return false;
  }
  return word[t.len] == '\0';
}

// Binary search in the generated 30k-word dictionary (bigdict.cpp). Entries are
// sorted by the raw bytes of the lowercase word, and this compares the same
// way (lowercased input byte vs stored byte; a shorter word sorts first), so
// the two orders agree. `s` needn't be terminated or lowercase. ~15 steps.
static const uint8_t* bigdictFind(const char *s, uint16_t len) {
  int32_t lo = 0, hi = (int32_t)BIGDICT_COUNT - 1;
  while (lo <= hi) {
    int32_t mid = lo + (hi - lo) / 2;
    const uint8_t *w = BIGDICT_DATA + BIGDICT_INDEX[mid];
    int cmp = 0;
    uint16_t k = 0;
    for (; k < len; k++) {
      uint8_t a = (uint8_t)tolower((unsigned char)s[k]);
      if (w[k] == 0)  { cmp = 1; break; }                  // entry is a prefix of s
      if (a != w[k])  { cmp = (a < w[k]) ? -1 : 1; break; }
    }
    if (k == len) cmp = (w[len] == 0) ? 0 : -1;            // s is a prefix of entry
    if (cmp == 0) return w + len + 1;                      // codes follow the 0
    if (cmp < 0) hi = mid - 1; else lo = mid + 1;
  }
  return nullptr;
}

// Search order: EXTRA_DICT (extradict.h) FIRST, so your own entries override
// anything below; then Sensory's hand-tuned standard dictionary (linear scan,
// 1427 entries); then the generated bigdict. bigdict deliberately contains no
// word that's in the other two, but the order would make them win anyway.
// Returns nullptr on a miss.
static const uint8_t* lookupToken(const TokenRef &t) {
  for (const DictionaryEntry *e = EXTRA_DICT; e->word != nullptr; e++) {
    if (tokenMatches(t, e->word)) return e->codes;
  }
  for (const DictionaryEntry *e = _dict_standard; e->word != nullptr; e++) {
    if (tokenMatches(t, e->word)) return e->codes;
  }
  return bigdictFind(lyricText + t.start, t.len);
}

// Code arrays are terminated by 255 (EndOfPhrase) -- the library's sentinel,
// NOT a SpeakJet command. It must not be transmitted.
static uint8_t codeLength(const uint8_t *codes) {
  uint8_t n = 0;
  while (codes[n] != 255 && n < 64) n++;
  return n;
}

static void copyTokenText(const TokenRef &t, char *out, size_t outSize) {
  size_t n = (t.len < outSize - 1) ? t.len : outSize - 1;
  memcpy(out, lyricText + t.start, n);
  out[n] = '\0';
}


// ===========================================================================
// OLED — SH1106 at 0x3C on I2C1. Library-free.
//
// REFRESH POLICY: audio and MIDI come first. A full 1024-byte refresh at
// 400 kHz blocks for ~26 ms, which would starve USBHost.task(). So:
//   1. Rendering draws into fb[] and compares against shadow[] (what's
//      actually on the glass) to find the changed COLUMN SPAN per page.
//      A playhead move typically dirties two short spans, not the screen.
//   2. displayService() flushes AT MOST ONE page per loop() iteration.
//      Worst case block is one page (~3 ms); typical is far less.
// The display therefore lags by a few loop iterations, which is invisible to
// a human and keeps the MIDI path unblocked.
// ===========================================================================
const uint8_t OLED_ADDR  = 0x3C;
const uint8_t OLED_W     = 128;
const uint8_t OLED_PAGES = 8;
const uint8_t OLED_COL_OFFSET = 2;   // SH1106: 132-column RAM, 128-column panel

static uint8_t fb[OLED_W * OLED_PAGES];
static uint8_t shadow[OLED_W * OLED_PAGES];
static int16_t dirtyMin[OLED_PAGES];
static int16_t dirtyMax[OLED_PAGES];

static void oledCmd(uint8_t c) {
  Wire1.beginTransmission(OLED_ADDR);
  Wire1.write(0x00);
  Wire1.write(c);
  Wire1.endTransmission();
}
static void oledCmd2(uint8_t c, uint8_t a) { oledCmd(c); oledCmd(a); }

static void oledInit() {
  oledCmd(0xAE);
  oledCmd2(0xD5, 0x80);
  oledCmd2(0xA8, 0x3F);
  oledCmd2(0xD3, 0x00);
  oledCmd(0x40);
  oledCmd2(0xAD, 0x8B);      // SH1106 DC-DC on
  oledCmd(0x32);             // pump voltage
  oledCmd(0xA1);
  oledCmd(0xC8);
  oledCmd2(0xDA, 0x12);
  oledCmd2(0x81, 0x7F);
  oledCmd2(0xD9, 0x22);
  oledCmd2(0xDB, 0x35);
  oledCmd(0xA4);
  oledCmd(0xA6);
  oledCmd(0xAF);
  delay(100);
  memset(shadow, 0xFF, sizeof(shadow));   // force a full first paint
  for (uint8_t p = 0; p < OLED_PAGES; p++) { dirtyMin[p] = 0; dirtyMax[p] = OLED_W - 1; }
}

// Flush one page's dirty span, then mark it clean. Returns true if it did work.
static bool displayService() {
  for (uint8_t page = 0; page < OLED_PAGES; page++) {
    if (dirtyMin[page] < 0) continue;

    uint8_t x0 = (uint8_t)dirtyMin[page];
    uint8_t x1 = (uint8_t)dirtyMax[page];
    uint8_t col = x0 + OLED_COL_OFFSET;

    oledCmd(0xB0 + page);
    oledCmd(0x00 | (col & 0x0F));
    oledCmd(0x10 | (col >> 4));

    const uint8_t *p = fb + page * OLED_W;
    for (uint8_t x = x0; x <= x1; ) {
      Wire1.beginTransmission(OLED_ADDR);
      Wire1.write(0x40);
      uint8_t n = 0;
      while (x <= x1 && n < 16) { Wire1.write(p[x]); x++; n++; }
      Wire1.endTransmission();
    }
    memcpy(shadow + page * OLED_W + x0, p + x0, (size_t)(x1 - x0 + 1));
    dirtyMin[page] = -1;
    return true;      // one page per call, deliberately
  }
  return false;
}

static void computeDirty() {
  for (uint8_t page = 0; page < OLED_PAGES; page++) {
    const uint8_t *a = fb + page * OLED_W;
    const uint8_t *b = shadow + page * OLED_W;
    int16_t lo = -1, hi = -1;
    for (uint8_t x = 0; x < OLED_W; x++) {
      if (a[x] != b[x]) { if (lo < 0) lo = x; hi = x; }
    }
    // Keep any span still pending from a previous render, so nothing is lost
    // if two renders happen before the flusher catches up.
    if (lo >= 0) {
      if (dirtyMin[page] < 0) { dirtyMin[page] = lo; dirtyMax[page] = hi; }
      else {
        if (lo < dirtyMin[page]) dirtyMin[page] = lo;
        if (hi > dirtyMax[page]) dirtyMax[page] = hi;
      }
    }
  }
}

// --- drawing primitives ---
static void fbClear() { memset(fb, 0, sizeof(fb)); }

static void setPixel(int x, int y, bool on) {
  if (x < 0 || x >= OLED_W || y < 0 || y >= 64) return;
  uint8_t *b = &fb[(y / 8) * OLED_W + x];
  uint8_t  m = 1 << (y & 7);
  if (on) *b |= m; else *b &= ~m;
}
static void hLine(int x, int y, int w, bool on) { for (int i = 0; i < w; i++) setPixel(x + i, y, on); }

// Invert a pixel. The edit cursor uses this: a lit bar is invisible when it
// falls inside the playhead's inverted block, which is exactly where it lands
// while you edit the word you're on. Inverting shows up on both backgrounds.
static void xorPixel(int x, int y) {
  if (x < 0 || x >= OLED_W || y < 0 || y >= 64) return;
  fb[(y / 8) * OLED_W + x] ^= (uint8_t)(1 << (y & 7));
}
static void xorRect(int x, int y, int w, int h) {
  for (int j = 0; j < h; j++)
    for (int i = 0; i < w; i++) xorPixel(x + i, y + j);
}
static void fillRect(int x, int y, int w, int h, bool on) { for (int j = 0; j < h; j++) hLine(x, y + j, w, on); }

// Font covers 0x20..0x7A only; anything outside renders blank rather than
// reading past the table.
static void drawChar(int x, int y, char c, uint8_t scale, bool inv) {
  if (c < 0x20 || c > 0x7A) c = ' ';
  const uint8_t *g = &font5x7[(c - 0x20) * 5];
  for (uint8_t col = 0; col < 6; col++) {
    uint8_t bits = (col < 5) ? g[col] : 0x00;
    for (uint8_t row = 0; row < 8; row++) {
      bool on = (row < 7) && ((bits >> row) & 1);
      if (inv) on = !on;
      if (scale == 1) setPixel(x + col, y + row, on);
      else for (uint8_t sy = 0; sy < scale; sy++)
             for (uint8_t sx = 0; sx < scale; sx++)
               setPixel(x + col * scale + sx, y + row * scale + sy, on);
    }
  }
}
static void drawText(int x, int y, const char *s, uint8_t scale, bool inv) {
  while (*s) { drawChar(x, y, *s++, scale, inv); x += 6 * scale; }
}

// ---------------------------------------------------------------------------
// USB MIDI host objects
// ---------------------------------------------------------------------------
Adafruit_USBH_Host USBHost;

// v2 API: the instance must be created by this macro, not declared directly.
// Second argument is the settings class; MidiHostSettingsDefault is the stock one.
RPPICOMIDI_EZ_USB_MIDI_HOST_INSTANCE(usbhMIDI, MidiHostSettingsDefault)

static uint8_t midiDevAddr = 0;

// ---------------------------------------------------------------------------
// State
// ---------------------------------------------------------------------------
// playhead is declared up with the lyric/token state it belongs to.
static bool    flushOnNote = true;  // SCP buffer flush before each token; 'f' toggles
// OFF by default. Since 7d the line is printed from loop(), not the note-on
// callback, but ~80 chars at 115200 still block loop() for ~4 ms per note.
static bool    logNotes    = false;
static bool    bendEnabled = true;  // 'v' toggles, for A/B comparison

// Current Speed value, updated by the pitch-bend wheel and applied at the next
// note-on. SpeakJet's Speed latches and cannot be changed mid-phoneme, so
// "update immediately" vs "sample at note-on" is a distinction without a
// difference here: we send Speed with every token anyway, so the wheel's
// position at the moment of note-on is what lands. That settles the open
// question recorded in the project doc.
static uint8_t currentSpeed = SJ_SPEED_DEFAULT;

// Timbre/Bend, driven by the mod wheel (CC1). Starts at the chip's own default
// so the instrument boots sounding stock; the first wheel movement takes over
// and then has the full 0..15 range. Like Speed, it latches and is applied at
// the next note-on rather than mid-syllable.
static uint8_t currentBend    = SJ_BEND_DEFAULT;

static bool    modEnabled     = true;   // 'w' toggles

// ---------------------------------------------------------------------------
// SpeakJet
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// SpeakJet TX queue
// ---------------------------------------------------------------------------
// Serial2.write() -> uart_putc_raw() BLOCKS once the RP2350's 32-byte UART FIFO
// is full, ~1 ms per extra byte at 9600. Writing a note's bytes straight from
// the MIDI callback therefore stalled it for up to ~35 ms on long fx entries
// (host simulator, fxcountdown). Now speakNext() only ENQUEUES, and
// sjqService() moves bytes into the UART FIFO from loop() while there is
// room. It never waits. (availableForWrite() on this core only reports
// "at least one byte free", so bytes move one at a time.)
//
// GROUPS. A command that takes an argument (Table D: 20-26, 28-30) must never
// be separated from its argument, and the 4-byte SCP flush must stay whole —
// otherwise the chip would take a following byte as a stray argument. Each
// queued byte carries its group length on the group's first byte (0 on
// continuation bytes). This is recorded at enqueue time, not inferred from
// byte values, because argument values can be anything.
//
// RETRIGGER. With flush-on-note, a new note DISCARDS whatever is still queued:
// it is stale, and the flush would cut it off anyway. The one exception is
// the remainder of a group already partly in the UART FIFO, which must finish.
//
// The SpeakJet's own 64-byte input buffer is a separate, later limit (56
// codes per note after the parameter block). RDY can't pace anything: per the
// manual it only reports that self-test passed.
// ---------------------------------------------------------------------------
const uint16_t SJQ_SIZE = 512;                  // power of two; one note is <= ~70 bytes
static uint8_t  sjqData[SJQ_SIZE];
static uint8_t  sjqGroup[SJQ_SIZE];             // group length on a group's first byte, else 0
static uint16_t sjqHead = 0;                    // next byte to send
static uint16_t sjqTail = 0;                    // next free slot; head == tail means empty
static uint8_t  sjqGroupLeft = 0;               // unsent bytes of the group now in flight
static uint16_t sjqMaxDepth  = 0;               // statistics for 'q'
static uint32_t sjqDropped   = 0;               // notes that didn't fit
static uint32_t sjqDiscarded = 0;               // stale bytes dropped on retrigger
// TX pacing (7j): release one byte per SJ_BYTE_US, just under the line rate,
// so the UART's FIFO stays nearly empty and a retrigger flush isn't stuck
// behind committed bytes. See sjqService() for the full reasoning.
const uint32_t SJ_BYTE_US = 1150;               // 10 bits at 9600 baud = 1042 us, +10%
static uint32_t sjqNextSendUs = 0;
static bool     sjqUrgent     = false;          // inside a flush group: don't pace it

static uint16_t sjqCount() { return (uint16_t)((sjqTail - sjqHead) & (SJQ_SIZE - 1)); }
static uint16_t sjqFree()  { return (uint16_t)(SJQ_SIZE - 1 - sjqCount()); }

static bool sjTakesArg(uint8_t c) { return (c >= 20 && c <= 26) || (c >= 28 && c <= 30); }

static void sjqPush(uint8_t b, uint8_t groupLen) {
  sjqData[sjqTail]  = b;
  sjqGroup[sjqTail] = groupLen;
  sjqTail = (uint16_t)((sjqTail + 1) & (SJQ_SIZE - 1));
}

// Queue SpeakJet codes, grouping each command with its argument. A trailing
// command whose argument is missing is dropped rather than queued, so it can't
// swallow the first byte of the next note. Returns the bytes queued.
static uint16_t sjqPushCodes(const uint8_t *c, uint16_t len) {
  uint16_t i = 0;
  while (i < len) {
    uint8_t g = sjTakesArg(c[i]) ? 2 : 1;
    if (i + g > len) break;
    sjqPush(c[i], g);
    if (g == 2) sjqPush(c[i + 1], 0);
    i += g;
  }
  return i;
}

// SCP escape "\0", Clear Buffer "R", Exit "X". R clears the SpeakJet's 64-byte
// input buffer (manual, SCP command table), and SCP commands execute on
// receipt rather than queueing, so this cuts the current syllable instead of
// waiting behind it. It is Sensory's own stop sequence (Phrase-A-Lator's
// "Shut Up" button sends \0RX followed by Reset and P0).
static void sjqPushFlush() {
  sjqPush('\\', 4);
  sjqPush('0', 0);
  sjqPush('R', 0);
  sjqPush('X', 0);
}

// Retrigger: drop everything queued except the in-flight group's remainder.
// A retrigger is exactly when we want no extra delay: release the next byte
// (the flush) as soon as the UART has room.
static void sjqDiscardStale() {
  sjqNextSendUs = micros();
  uint16_t n    = sjqCount();
  uint16_t keep = (sjqGroupLeft < n) ? sjqGroupLeft : n;
  sjqDiscarded += (uint32_t)(n - keep);
  sjqTail = (uint16_t)((sjqHead + keep) & (SJQ_SIZE - 1));
}

static void sjqClear() {
  sjqHead = sjqTail = 0;
  sjqGroupLeft = 0;
}

// Called from loop(). Moves bytes into the UART FIFO while it has room.
// PACING (7j). Filling the UART's 32-byte FIFO commits those bytes: a retrigger
// flush can only reach the chip after they have all been clocked out, which is
// ~33 ms at 9600 baud. So bytes are released at just under the line rate, one
// per SJ_BYTE_US, leaving at most a byte or two in the FIFO and a worst-case
// cut delay of ~5 ms (one byte in flight + the 4-byte flush).
//
// Throughput is identical — the line was never faster than this. The bytes wait
// in our RAM queue instead, where sjqDiscardStale() can still drop them.
//
// ⚠️ Pace slightly SLOWER than the true line rate, never faster: too slow just
// leaves the FIFO empty for a moment, while too fast lets it silently refill
// and we are back to the old behaviour. Underrun is harmless here — the chip
// speaks at roughly 10 codes/second while the line carries 960 bytes/second,
// so its own 64-byte buffer cannot run dry mid-word.
static void sjqService() {
  while (sjqCount() > 0) {
    // The 4-byte SCP flush is the one thing that must not be paced: it IS the
    // cut. Pacing it would add a byte time per byte, and loop() jitter on top.
    if (sjqGroupLeft == 0) sjqUrgent = (sjqGroup[sjqHead] == 4);
    if (!sjqUrgent && (int32_t)(micros() - sjqNextSendUs) < 0) break;   // not its turn yet
    if (Serial2.availableForWrite() <= 0) break;              // FIFO full: never block
    if (sjqGroupLeft == 0) {
      uint8_t g = sjqGroup[sjqHead];
      sjqGroupLeft = (g > 0) ? g : 1;       // defensive: a stray continuation byte
    }
    Serial2.write(sjqData[sjqHead]);
    sjqHead = (uint16_t)((sjqHead + 1) & (SJQ_SIZE - 1));
    sjqGroupLeft--;
    if (sjqGroupLeft == 0) sjqUrgent = false;
    sjqNextSendUs = micros() + SJ_BYTE_US;
  }
}

// ---------------------------------------------------------------------------
// How long does a word take to say?
// ---------------------------------------------------------------------------
// The SpeakJet gives no "finished" signal we can read: D0/Ready is only a
// self-test flag and D1/Speaking isn't wired to the Pico (wiring §6 — shield
// pin 4, and shifter channel 2 is free if we ever want it). So the duration is
// computed from the manual's per-allophone times (Table D), which are exact
// for the default speed:
//   phoneme    its table value below (10-225 ms)
//   7 FAST     next phoneme at 1/2 time     8 SLOW  next phoneme at 1.5x
//   pauses     0/100/200/700/30/60/90 ms for codes 0-6
//   14/15/18   stress, relax, soft: no effect on length
// ⚠️ The Speed register's effect on duration is NOT documented. We assume
// duration scales as 114/speed (114 is the default). That assumption, plus the
// UART and chip latency, is what SPEECH_SCALE_PCT calibrates away by ear.
static const uint8_t PHONEME_MS[72] = {
   70,  70,  70,  70,  70,  70,  70,  70,   // 128 IY IH EY EH AY AX UX OH
   70,  70,  70,  70,  70,  70,  70,  70,   // 136 AW OW UH UW MM NE NO NGE
   70,  70,  70,  70,  70, 200, 200, 190,   // 144 NGO LE LO WW RR IYRR EYRR AXRR
  200, 185, 165, 200, 225, 185, 170, 140,   // 152 AWRR OWRR EYIY OHIY OWIY OHIH IYEH EHLL
  180, 170, 170, 200, 131,  70,  70,  70,   // 160 IYUW AXUW IHWW AYWW OWWW JH VV ZZ
   70,  70,  45,  45,  10,  10,  45,  45,   // 168 ZH DH BE BO EB OB DE DO
   10,  10,  55,  55,  55,  55,  70,  70,   // 176 ED OD GE GO EG OG CH HE
   70,  70,  70,  40,  40,  50,  40,  50,   // 184 HO WH FF SE SO SH TH TT
   70, 170,  55,  55,  55,  45,  99,  99,   // 192 TU TS KE KO EK OK PE PO
};
static const uint16_t PAUSE_MS[7] = { 0, 100, 200, 700, 30, 60, 90 };
static uint16_t speechScalePct = 100;         // 'w' adjusts this at runtime

static uint32_t estimateWordMs(const uint8_t *codes, uint8_t len, uint8_t speed) {
  uint32_t ms = 0;
  uint16_t mult = 100;                        // pending FAST/SLOW, in percent
  for (uint8_t i = 0; i < len; i++) {
    uint8_t c = codes[i];
    if (c >= 128 && c <= 199) {
      ms += (uint32_t)PHONEME_MS[c - 128] * mult / 100;
      mult = 100;
    } else if (c <= 6) {
      ms += PAUSE_MS[c];
    } else if (c == 7) {
      mult = 50;
    } else if (c == 8) {
      mult = 150;
    } else if (c == 30 && i + 1 < len) {      // Delay, X: n x 10 ms
      ms += (uint32_t)codes[i + 1] * 10; i++;
    } else if ((c >= 20 && c <= 26) || (c >= 28 && c <= 30)) {
      i++;                                    // command argument: no duration
    }
  }
  if (speed < 1) speed = 1;
  ms = ms * SJ_SPEED_DEFAULT / speed;         // faster speed, shorter word
  return ms * speechScalePct / 100 + SPEECH_LATENCY_MS;
}

// ---------------------------------------------------------------------------
// Deferred note log. speakNext() records; loop() prints one line per pass.
// ---------------------------------------------------------------------------
// (struct NoteLog is declared near the top of the file, with LineMode.)
const uint8_t LOG_RING = 8;
static NoteLog  logRing[LOG_RING];
static uint8_t  logHead = 0, logTail = 0;
static uint32_t logLost = 0;

static void logPush(const NoteLog &e) {
  uint8_t next = (uint8_t)((logTail + 1) % LOG_RING);
  if (next == logHead) { logLost++; return; }   // ring full: drop, never block
  logRing[logTail] = e;
  logTail = next;
}

static void logService() {
  if (logHead == logTail) return;
  const NoteLog &e = logRing[logHead];
  if (e.kind == 1) {
    Serial1.printf("note %3u -> token[%u] \"%s\"  *** NOT IN DICTIONARY ***\r\n",
                   e.note, e.token, e.text);
  } else if (e.kind == 2) {
    Serial1.printf("note %3u -> token[%u] \"%s\"  *** TX QUEUE FULL, NOTE DROPPED ***\r\n",
                   e.note, e.token, e.text);
  } else {
    Serial1.printf("note %3u -> %3u Hz vel %3u spd %3u bnd %2u  token[%u] \"%s\" (%u codes)\r\n",
                   e.note, e.hz, e.vel, e.spd, e.bnd, e.token, e.text, e.codes);
  }
  logHead = (uint8_t)((logHead + 1) % LOG_RING);
  if (logHead == logTail && logLost) {
    Serial1.printf("(%lu log lines lost: ring full)\r\n", (unsigned long)logLost);
    logLost = 0;
  }
}

static void sjReset() {
  sjqClear();                           // anything queued is meaningless after a reset
  Serial1.println(F("[RES] pulse low->high"));
  digitalWrite(PIN_SJ_RES, LOW);
  delay(100);
  digitalWrite(PIN_SJ_RES, HIGH);
  delay(100);
  Serial1.print(F("[RES] done, RDY = "));
  Serial1.println(digitalRead(PIN_SJ_RDY) ? F("HIGH") : F("LOW"));
}

// Fold out-of-range notes by whole octaves until they land in the playable
// window, preserving pitch class. Chosen over clamping so every key on the
// keyboard does something musical rather than the top half going dead.
static uint8_t noteToPitchHz(uint8_t note) {
  int n = (int)note + NOTE_TRANSPOSE;

  // Fold remains as the safety net for the controller's own octave buttons —
  // it just shouldn't be reachable during normal playing any more.
  while (n > MIDI_NOTE_MAX) n -= 12;
  while (n < MIDI_NOTE_MIN) n += 12;

  float hz = 440.0f * powf(2.0f, (n - 69) / 12.0f);
  if (hz < SJ_PITCH_MIN) hz = SJ_PITCH_MIN;   // belt and braces
  if (hz > SJ_PITCH_MAX) hz = SJ_PITCH_MAX;
  return (uint8_t)(hz + 0.5f);
}

static void speakNext(uint8_t note, uint8_t velocity) {
  if (tokenCount == 0) { Serial1.println(F("(lyric buffer empty)")); return; }

  // A note arriving while the previous word is still sounding cuts it short
  // (§4.3), so the highlight has to move on now — otherwise this note would
  // speak the same word again.
  if (wordSounding) {
    wordSounding = false;
    setPlayhead((playhead + 1) % tokenCount);
  }

  const TokenRef &t = tokens[playhead];
  const uint8_t *codes = lookupToken(t);
  uint8_t pitchHz = noteToPitchHz(note);

  NoteLog e;
  e.note = note; e.hz = pitchHz; e.vel = velocity; e.spd = currentSpeed;
  e.bnd = currentBend; e.token = playhead; e.codes = 0; e.kind = 0;
  copyTokenText(t, e.text, sizeof(e.text));

  if (codes == nullptr) {
    // MISS. Advance anyway, so the lyric stays in sync with the notes played
    // rather than sticking on an unspeakable word. Silence is the feedback;
    // use 'c' to pre-check the whole buffer before performing. Nothing sounds,
    // so the highlight moves on at once rather than after a duration.
    e.kind = 1;
  } else {
    uint8_t len = codeLength(codes);
    if (flushOnNote) sjqDiscardStale();
    uint16_t need = (uint16_t)((flushOnNote ? 4 : 0) + 8 + len);
    if (sjqFree() < need) {
      // Only reachable with flush-on-note OFF and notes arriving faster than
      // 9600 baud drains them. Dropping the whole note keeps the stream valid.
      sjqDropped++;
      e.kind = 2;
    } else {
      if (flushOnNote) sjqPushFlush();
      uint8_t params[8] = { SJ_VOLUME, velocity,
                            SJ_PITCH,  pitchHz,
                            SJ_SPEED,  currentSpeed,
                            SJ_BEND,   currentBend };
      sjqPushCodes(params, sizeof(params));
      sjqPushCodes(codes, len);
      e.codes = len;
      if (sjqCount() > sjqMaxDepth) sjqMaxDepth = sjqCount();
    }
  }
  if (logNotes) logPush(e);

  // The highlight stays on the word now sounding; playheadService() moves it
  // on when the word ends. A miss has nothing to wait for.
  if (e.kind == 0) {
    wordEndsAtMs = millis() + estimateWordMs(codes, codeLength(codes), currentSpeed);
    wordSounding = true;
  } else {
    wordSounding = false;
    setPlayhead((playhead + 1) % tokenCount);
  }
  displayDirty = true;
}

// Move the highlight on when the sounding word finishes. Called from loop().
// This is what shows the performer the NEXT word without having played it.
static void playheadService() {
  if (!wordSounding) return;
  if ((int32_t)(millis() - wordEndsAtMs) < 0) return;
  wordSounding = false;
  if (tokenCount) setPlayhead((playhead + 1) % tokenCount);
  displayDirty = true;
}

// ---------------------------------------------------------------------------
// MIDI
// ---------------------------------------------------------------------------
// Note Off is deliberately NOT handled: no handler is registered for it at all.
// A key release must not interrupt the sounding syllable, and nothing is "held",
// so there is no note state to track and no stuck-note failure mode.

static void onNoteOn(midi::Channel channel, byte note, byte velocity)
{
  (void)channel;   // channel is ignored: OMNI behaviour

  // A Note On with velocity 0 IS a note-off (running-status convention, very
  // common on real controllers). The MIDI library passes it here unchanged, so
  // without this check every key RELEASE fires a second syllable and the
  // playhead advances at double rate.
  if (velocity == 0) return;

  // Velocity path is plumbed end-to-end but pinned to a constant for now.
  // Deleting the next line is all that's needed to enable real dynamics.
  velocity = SJ_VOL_FIXED;

  speakNext(note, velocity);
}

// Pitch-bend wheel -> Speed. inBend is 14-bit signed: -8192 .. +8191, 0 = centre.
static void onPitchBend(midi::Channel channel, int inBend)
{
  (void)channel;
  if (!bendEnabled) return;

  if (inBend >= 0) {
    // Upward: 0..+8191 maps across the small headroom above the default.
    long span = (long)SJ_SPEED_MAX - SJ_SPEED_DEFAULT;
    currentSpeed = (uint8_t)(SJ_SPEED_DEFAULT + (inBend * span) / 8191L);
  } else {
    // Downward: 0..-8192 maps across the much larger range below the default.
    long span = (long)SJ_SPEED_DEFAULT - SJ_SPEED_MIN;
    currentSpeed = (uint8_t)(SJ_SPEED_DEFAULT - ((-(long)inBend) * span) / 8192L);
  }
  // Deliberately NOT sent to the chip here — Speed latches and takes effect on
  // the next token, so it is sent as part of the next note-on's parameter block.
}

// Mod wheel (CC1) -> Timbre/Bend. Bend shifts the oscillator formants: 0 is a
// deep hollow voice, 15 a high metallic one, 5 is the chip's default.
// A set-and-leave control rather than a gesture, which suits a wheel that holds
// its position — unlike the self-centring pitch strip driving Speed.
static void onControlChange(midi::Channel channel, byte number, byte value)
{
  (void)channel;
  if (number != 1) return;            // CC1 = modulation; ignore everything else
  if (!modEnabled) return;

  currentBend = (uint8_t)(((uint16_t)value * SJ_BEND_MAX) / 127);
  // Not sent here — Bend latches, so it goes out with the next note's block.
}

static void onMIDIconnect(uint8_t devAddr, uint8_t nInCables, uint8_t nOutCables)
{
  if (midiDevAddr != 0) {
    // Previously this printed but fell through, so the second device took over.
    Serial1.printf("MIDI device at address %u ignored: only one handled at a time\r\n", devAddr);
    return;
  }
  Serial1.printf("MIDI device at address %u: %u IN cables, %u OUT cables\r\n",
                 devAddr, nInCables, nOutCables);
  midiDevAddr = devAddr;
  auto intf = usbhMIDI.getInterfaceFromDeviceAndCable(midiDevAddr, 0);
  if (intf == nullptr) return;
  midiConnected = true;
  displayDirty = true;
  intf->setHandleNoteOn(onNoteOn);      // note-off intentionally unregistered
  intf->setHandlePitchBend(onPitchBend);          // strip drives Speed, not pitch
  intf->setHandleControlChange(onControlChange);  // CC1 drives Timbre/Bend
  digitalWrite(LED_BUILTIN, HIGH);      // steady = MIDI device connected
}

static void onMIDIdisconnect(uint8_t devAddr)
{
  Serial1.printf("MIDI device at address %u unplugged\r\n", devAddr);
  if (devAddr != midiDevAddr) return;   // an ignored second device: not ours
  midiDevAddr = 0;
  midiConnected = false;
  displayDirty = true;
  digitalWrite(LED_BUILTIN, LOW);
}


// ---------------------------------------------------------------------------
// Play view
//
//   y  0..7   status: MIDI state | token position | miss indicator
//   y  9      rule
//   y 13..28  current token at 2x — the thing you read at arm's length
//   y 31      rule
//   y 36,45,54  three-line lyric window, playhead inverted, auto-scrolled
// ---------------------------------------------------------------------------
const uint8_t VIEW_COLS = 21;    // 128 / 6
const uint8_t VIEW_ROWS = 3;

// Which token the cursor is in, or the one it sits just before. The window
// scrolls to keep this visible while editing; the playhead takes over once
// typing stops, so performing looks exactly as it did before.
static uint8_t cursorToken() {
  for (uint8_t i = 0; i < tokenCount; i++) {
    const TokenRef &t = tokens[i];
    if (cursor < (size_t)(t.start + t.len)) return i;
  }
  return tokenCount ? tokenCount - 1 : 0;
}

static uint8_t followToken() {
  bool editing = (millis() - lastEditMs) < FOLLOW_CURSOR_MS;
  return editing ? cursorToken() : playhead;
}

// Lay tokens out from `start`; report whether `target` landed on screen.
static bool layoutFits(uint8_t start, uint8_t target) {
  uint8_t line = 0, col = 0;
  for (uint8_t i = start; i < tokenCount; i++) {
    uint8_t len = tokens[i].len; if (len > VIEW_COLS) len = VIEW_COLS;
    if (col > 0 && col + 1 + len > VIEW_COLS) { line++; col = 0; }
    if (line >= VIEW_ROWS) return false;
    if (col > 0) col++;
    col += len;
    if (i == target) return true;
  }
  return true;
}

static void drawLyricWindow() {
  const int rowY[VIEW_ROWS] = { 36, 45, 54 };
  if (tokenCount == 0) {
    // Empty lyric: still show a cursor, or the instrument looks dead.
    if (cursorOn) xorRect(0, rowY[0] - 1, 1, 9);
    return;
  }

  // Scroll just far enough that the followed token is visible.
  uint8_t target = followToken();
  uint8_t start = 0;
  while (start < target && !layoutFits(start, target)) start++;

  uint8_t line = 0, col = 0;
  char w[32];
  // Where the cursor lands, in character cells: decided during layout, because
  // wrapping and collapsed whitespace are what place it.
  bool curSeen = false;
  int  curLine = 0, curCol = 0;

  for (uint8_t i = start; i < tokenCount && line < VIEW_ROWS; i++) {
    uint8_t len = tokens[i].len; if (len > VIEW_COLS) len = VIEW_COLS;
    if (col > 0 && col + 1 + len > VIEW_COLS) { line++; col = 0; }
    if (line >= VIEW_ROWS) break;
    if (col > 0) col++;

    const TokenRef &t = tokens[i];
    if (!curSeen && cursor <= (size_t)t.start) {
      curSeen = true; curLine = line; curCol = col;                        // in the gap before this word
    } else if (!curSeen && cursor <= (size_t)(t.start + len)) {
      curSeen = true; curLine = line; curCol = col + (int)(cursor - t.start);  // inside this word
    }

    copyTokenText(tokens[i], w, sizeof(w));
    w[VIEW_COLS] = '\0';
    if (i == playhead) {
      // Inverted strip marks where we are. One pixel of bleed each side so
      // the block doesn't crowd the glyphs.
      fillRect(col * 6 - 1, rowY[line] - 1, len * 6 + 1, 9, true);
      drawText(col * 6, rowY[line], w, 1, true);
    } else {
      drawText(col * 6, rowY[line], w, 1, false);
    }
    col += len;
    if (!curSeen && i == tokenCount - 1) { curSeen = true; curLine = line; curCol = col; }
  }

  // A 1-px bar between characters, blinking, so it can't be mistaken for the
  // playhead's inverted block. Drawn last and INVERTED, so it stays visible
  // inside that block as well as on plain background.
  if (curSeen && cursorOn && curLine < VIEW_ROWS) {
    int x = curCol * 6 - 1; if (x < 0) x = 0;
    xorRect(x, rowY[curLine] - 1, 1, 9);
  }
}

// Blink the cursor from loop(): one narrow span, redrawn twice a second.
static void cursorService() {
  if (millis() - cursorBlinkMs < CURSOR_BLINK_MS) return;
  cursorBlinkMs = millis();
  cursorOn = !cursorOn;
  displayDirty = true;
}

static void renderPlayView() {
  fbClear();

  char line[32];
  char cur[32] = "";
  bool miss = false;

  if (tokenCount > 0) {
    copyTokenText(tokens[playhead], cur, sizeof(cur));
    // A full dictionary scan per render — acceptable because rendering runs in
    // loop(), never in the MIDI callback. While a word sounds this is that
    // word; once it finishes the highlight has moved on, so it becomes a
    // warning about the word the next note will speak.
    miss = (lookupToken(tokens[playhead]) == nullptr);
  }

  // status
  if (statusMsg[0] && (int32_t)(millis() - statusUntilMs) < 0) {
    // A command just ran: its confirmation takes the status line for a moment.
    snprintf(line, sizeof(line), "%s", statusMsg);
  } else {
    statusMsg[0] = '\0';
    snprintf(line, sizeof(line), "%s %2u/%-2u%s",
             midiConnected ? "MIDI" : "----",
             (unsigned)(tokenCount ? playhead + 1 : 0),
             (unsigned)tokenCount,
             miss ? "  NOT FOUND" : "");
  }
  drawText(0, 0, line, 1, false);

  hLine(0, 9, OLED_W, true);

  // current token, 2x, centred; truncated rather than overflowing
  cur[10] = '\0';
  int w2 = (int)strlen(cur) * 12;
  drawText((OLED_W - w2) / 2, 13, cur, 2, false);

  hLine(0, 31, OLED_W, true);

  drawLyricWindow();

  computeDirty();
}

// ---------------------------------------------------------------------------
// Debug menu — lets you test without a MIDI device attached
// ---------------------------------------------------------------------------
// Pre-flight: report which words won't speak, BEFORE performing rather than
// discovering it as silence mid-phrase.
static void checkLyric() {
  uint8_t misses = 0;
  for (uint8_t i = 0; i < tokenCount; i++) {
    if (lookupToken(tokens[i]) == nullptr) {
      char w[32]; copyTokenText(tokens[i], w, sizeof(w));
      Serial1.printf("  MISSING: \"%s\" (token %u)\r\n", w, i);
      misses++;
    }
  }
  if (misses == 0) Serial1.printf("all %u tokens found in dictionary\r\n", tokenCount);
  else             Serial1.printf("%u of %u tokens missing -- these stay silent\r\n",
                                  misses, tokenCount);
}

static void printMenu() {
  Serial1.println();
  Serial1.println(F("=== step 7j: MIDI -> SpeakJet ==="));
  Serial1.println(F("  n  simulate note-on at MIDI 48 (KeyStep low end)"));
  Serial1.println(F("  m  simulate note-on at MIDI 67 (KeyStep high end)"));
  Serial1.println(F("  0  reset playhead to start of lyrics"));
  Serial1.println(F("  t  type new lyric, Enter to finish (empty = keep current)"));
  Serial1.println(F("  c  CHECK lyric against dictionary (pre-flight)"));
  Serial1.println(F("  d  show current lyric + token list"));
  Serial1.println(F("  f  toggle SCP flush-on-note (retrigger cut-off)"));
  Serial1.println(F("  l  toggle note logging"));
  Serial1.println(F("  q  TX queue statistics"));
  Serial1.println(F("  e  word-length estimates; e<pct> sets the scale, e.g. e120"));
  Serial1.println(F("  v  toggle pitch-bend -> Speed"));
  Serial1.println(F("  w  toggle mod wheel -> Timbre/Bend"));
  Serial1.println(F("  <  Bend -1    >  Bend +1    #  Bend back to 5"));
  Serial1.println(F("  [  Speed -10 (manual test)"));
  Serial1.println(F("  ]  Speed +10 (manual test)"));
  Serial1.println(F("  =  Speed back to default 114"));
  Serial1.println(F("  r  pulse RES"));
  Serial1.println(F("  ?  then Enter: this menu"));
  Serial1.println(F("  ?word then Enter: dictionary lookup, e.g. ?fxping"));
  Serial1.println();
}

// ---------------------------------------------------------------------------
// Serial line input for 't' (new lyric) and '?' (menu / word lookup).
// NON-BLOCKING: loop() feeds it one character at a time as they arrive, so
// MIDI, the keyboard and the display keep running while you type. (Both used
// to sit in a busy-wait for up to 60 s / 1 s.) Waits for Enter rather than
// guessing from arrival timing, so character-mode terminals and line-mode ones
// (Arduino Serial Monitor) both work; "tsome words" on one line works too.
// ---------------------------------------------------------------------------
// (enum LineMode is declared near the top of the file — see the note there.)
static LineMode      lineMode   = LINE_NONE;
static char          lineBuf[LYRIC_MAX];
static size_t        lineLen    = 0;
static unsigned long lineLastMs = 0;
const unsigned long  LINE_IDLE_TIMEOUT_MS = 60000;   // since the last keystroke
const size_t         LOOKUP_MAX = 31;

static void lineBegin(LineMode m, const char *prompt) {
  lineMode   = m;
  lineLen    = 0;
  lineLastMs = millis();
  Serial1.print(prompt);
}

static void lookupWord(const char *w) {
  bool found = false;
  const DictionaryEntry *tables[2] = { EXTRA_DICT, _dict_standard };
  const char *names[2] = { "extra", "standard" };
  for (int ti = 0; ti < 2 && !found; ti++)
  for (const DictionaryEntry *e = tables[ti]; e->word != nullptr; e++) {
    if (strcmp(w, e->word) == 0) {
      Serial1.printf("\"%s\" [%s] -> %u codes:", w, names[ti], codeLength(e->codes));
      for (uint8_t k = 0; k < codeLength(e->codes); k++)
        Serial1.printf(" %u", e->codes[k]);
      Serial1.println();
      found = true;
      break;
    }
  }
  if (!found) {
    const uint8_t *codes = bigdictFind(w, (uint16_t)strlen(w));
    if (codes != nullptr) {
      Serial1.printf("\"%s\" [cmu] -> %u codes:", w, codeLength(codes));
      for (uint8_t k = 0; k < codeLength(codes); k++) Serial1.printf(" %u", codes[k]);
      Serial1.println();
      found = true;
    }
  }
  if (!found) Serial1.printf("\"%s\" not in dictionary\r\n", w);
}

static void lineFinish() {
  lineBuf[lineLen] = '\0';
  Serial1.println();
  LineMode m = lineMode;
  lineMode = LINE_NONE;
  if (m == LINE_LYRIC) {
    if (lineLen == 0) { Serial1.println(F("(lyric unchanged)")); return; }
    pushUndo();                          // ctrl+z restores the previous lyric
    memcpy(lyricText, lineBuf, lineLen + 1);
    retokenise();
    setPlayhead(0);
    cursor = strlen(lyricText);
    displayDirty = true;
    Serial1.printf("%u tokens\r\n", tokenCount);
    checkLyric();
  } else if (m == LINE_LOOKUP) {
    if (lineLen == 0) printMenu();
    else              lookupWord(lineBuf);
  } else if (m == LINE_SCALE) {
    if (lineLen > 0) {
      int v = atoi(lineBuf);
      if (v >= 25 && v <= 400) speechScalePct = (uint16_t)v;
      else Serial1.println(F("(scale must be 25..400 %)"));
    }
    Serial1.printf("speech scale %u%%, speed %u — word estimates:\r\n",
                   speechScalePct, currentSpeed);
    for (uint8_t i = 0; i < tokenCount; i++) {
      char w[32];
      copyTokenText(tokens[i], w, sizeof(w));
      const uint8_t *c = lookupToken(tokens[i]);
      if (c) Serial1.printf("  %-16s %4lu ms\r\n", w, (unsigned long)estimateWordMs(c, codeLength(c), currentSpeed));
      else   Serial1.printf("  %-16s    — not in dictionary\r\n", w);
    }
  }
}

static void lineInput(char ch) {
  lineLastMs = millis();
  if (ch == '\r' || ch == '\n') { lineFinish(); return; }
  if (ch == 8 || ch == 127) {                     // backspace
    if (lineLen > 0) { lineLen--; Serial1.print(F("\b \b")); }
    return;
  }
  size_t cap = (lineMode == LINE_LYRIC) ? LYRIC_MAX - 1 : LOOKUP_MAX;
  if ((unsigned char)ch < 32 || lineLen >= cap) return;
  lineBuf[lineLen++] = (lineMode == LINE_LYRIC) ? ch : (char)tolower((unsigned char)ch);
  Serial1.print(ch);                              // echo: char-mode terminals don't
}

static void lineService() {
  if (lineMode == LINE_NONE) return;
  if (millis() - lineLastMs > LINE_IDLE_TIMEOUT_MS) {
    lineMode = LINE_NONE;
    Serial1.println();
    Serial1.println(F("(timed out, nothing changed)"));
  }
}

static void handleKey(char c) {
  switch (c) {
    case 'n': speakNext(48, SJ_VOL_FIXED); break;   // -> MIDI 36 after transpose
    case 'm': speakNext(67, SJ_VOL_FIXED); break;   // -> MIDI 55, top of KeyStep
    case '0': setPlayhead(0); displayDirty = true; Serial1.println(F("playhead reset")); break;

    case 't':
      lineBegin(LINE_LYRIC, "type lyric, Enter to finish (empty = keep current):\r\n");
      break;

    case 'c': checkLyric(); break;

    case 'd': {
      Serial1.printf("lyric: \"%s\"\r\n", lyricText);
      Serial1.printf("%u tokens, playhead at %u (text offset %u)\r\n",
                     tokenCount, playhead, playheadOffset);
      for (uint8_t i = 0; i < tokenCount; i++) {
        char w[32]; copyTokenText(tokens[i], w, sizeof(w));
        Serial1.printf("  [%2u] %-16s %s\r\n", i, w,
                       lookupToken(tokens[i]) ? "ok" : "MISSING");
      }
      break;
    }
    case 'f':
      flushOnNote = !flushOnNote;
      Serial1.print(F("flush-on-note: "));
      Serial1.println(flushOnNote ? F("ON (new note cuts off current syllable)")
                                  : F("OFF (syllables queue in FIFO)"));
      break;
    case 'e':
      lineBegin(LINE_SCALE, "e");
      break;
    case 'q':
      Serial1.printf("TX queue (paced %lu us/byte): %u bytes now, max %u since last 'q', "
                     "%lu stale bytes discarded, %lu notes dropped\r\n",
                     (unsigned long)SJ_BYTE_US, sjqCount(), sjqMaxDepth,
                     (unsigned long)sjqDiscarded, (unsigned long)sjqDropped);
      sjqMaxDepth = sjqCount();
      break;
    case 'l':
      logNotes = !logNotes;
      Serial1.print(F("note logging: "));
      Serial1.println(logNotes ? F("ON") : F("OFF"));
      break;
    case 'w':
      modEnabled = !modEnabled;
      Serial1.print(F("mod wheel -> Bend: "));
      Serial1.println(modEnabled ? F("ON") : F("OFF"));
      break;

    case '<':
      if (currentBend > 0) currentBend--;
      Serial1.printf("bend %u\r\n", currentBend);
      break;

    case '>':
      if (currentBend < SJ_BEND_MAX) currentBend++;
      Serial1.printf("bend %u\r\n", currentBend);
      break;

    case '#':
      currentBend = SJ_BEND_DEFAULT;
      Serial1.printf("bend reset to %u\r\n", currentBend);
      break;

    case 'v':
      bendEnabled = !bendEnabled;
      Serial1.print(F("pitch-bend -> Speed: "));
      Serial1.println(bendEnabled ? F("ON") : F("OFF"));
      break;

    case '[':
      currentSpeed = (currentSpeed > SJ_SPEED_MIN + 10) ? currentSpeed - 10 : SJ_SPEED_MIN;
      Serial1.printf("speed %u\r\n", currentSpeed);
      break;

    case ']':
      currentSpeed = (currentSpeed < SJ_SPEED_MAX - 10) ? currentSpeed + 10 : SJ_SPEED_MAX;
      Serial1.printf("speed %u\r\n", currentSpeed);
      break;

    case '=':
      currentSpeed = SJ_SPEED_DEFAULT;
      Serial1.printf("speed reset to %u\r\n", currentSpeed);
      break;

    case 'r': sjReset(); break;
    case '?':
      lineBegin(LINE_LOOKUP, "? ");
      break;
    default: break;
  }
}

// --- keyboard performance commands (symbol row) -----------------------------
// The serial menu is unreachable on stage, so the symbol row carries the
// commands that change how the instrument behaves. Each one reports on the
// status line. Commands that only PRINT (token list, queue stats, word
// estimates) are deliberately not here — they'd do nothing visible.
// Returns true if the character was a command and must not be typed.
static bool keyboardCommand(char c) {
  switch (c) {
    case '!': {                       // pre-flight: is every word speakable?
      uint8_t missing = 0;
      for (uint8_t i = 0; i < tokenCount; i++)
        if (lookupToken(tokens[i]) == nullptr) missing++;
      if (missing) status("%u of %u NOT FOUND", missing, tokenCount);
      else         status("all %u words ok", tokenCount);
      return true;
    }
    case '@':                          // back to the start of the lyric
      setPlayhead(0);
      wordSounding = false;
      status("playhead reset");
      return true;
    case '#':                          // retrigger behaviour
      flushOnNote = !flushOnNote;
      status("flush %s", flushOnNote ? "ON (cut)" : "OFF (queue)");
      return true;
    case '$':
      currentSpeed = SJ_SPEED_DEFAULT;
      status("speed %u", currentSpeed);
      return true;
    case '%':
      currentBend = SJ_BEND_DEFAULT;
      status("bend %u", currentBend);
      return true;
    case '^':
      bendEnabled = !bendEnabled;
      status("bend strip %s", bendEnabled ? "ON" : "OFF");
      return true;
    case '&':
      modEnabled = !modEnabled;
      status("mod wheel %s", modEnabled ? "ON" : "OFF");
      return true;
    case '*':
      sjReset();
      status("SpeakJet reset");
      return true;
    default:
      return false;
  }
}

// ---------------------------------------------------------------------------
// Keyboard. Called from loop() AFTER MIDI, like the display. tab5kbd returns
// at most one event per call and touches I2C only when INT is asserted, so a
// burst of typing spreads across iterations instead of stalling the note path.
// ---------------------------------------------------------------------------
static void serviceKeyboard() {
  Tab5Key k;
  if (!kbd.read(k)) return;
  lastEditMs   = millis();      // the window follows the cursor for a few seconds
  cursorOn     = true;          // and the cursor shows solid while you type
  cursorBlinkMs = millis();
  displayDirty = true;

  switch (k.code) {
    case TAB5_CHAR:
      if (k.ctrl()) {
        if (k.c == 'z' || k.c == 'Z')      swapUndo();          // undo / redo
        else if (k.c >= '0' && k.c <= '9') presetSave(k.c - '0');
        break;
      }
      if (k.c >= '0' && k.c <= '9') { presetRecall(k.c - '0'); break; }
      if (keyboardCommand(k.c)) break;        // symbol row: performance commands
      insertChar(k.c);
      break;

    case TAB5_BACKSPACE: backspaceChar(); break;
    case TAB5_DEL:       deleteForward(); break;

    case TAB5_LEFT:
      if (k.ctrl()) cursorWordLeft();
      else if (cursor > 0) cursor--;
      break;
    case TAB5_RIGHT:
      if (k.ctrl()) cursorWordRight();
      else if (cursor < strlen(lyricText)) cursor++;
      break;

    case TAB5_UP:   cursor = 0;                 break;   // start of text
    case TAB5_DOWN: cursor = strlen(lyricText); break;   // end of text

    case TAB5_ESC:  clearLyric();               break;   // ctrl+z brings it back
    case TAB5_TAB:                                       // jump to the playhead
      if (tokenCount) cursor = tokens[playhead].start;
      break;

    case TAB5_ENTER:
      // Explicit "start the lyric from the beginning".
      setPlayhead(0);
      displayDirty = true;
      Serial1.printf("playhead reset — \"%s\" (%u tokens)\r\n",
                     lyricText, tokenCount);
      break;

    case TAB5_UNKNOWN:
      break;
  }
}

// ---------------------------------------------------------------------------
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Onboard SMPS into PWM mode. Without this, PFM pulse-skipping puts an
  // audible noise floor into the SpeakJet's output. Confirmed in step 1.
  pinMode(PIN_SMPS_MODE, OUTPUT);
  digitalWrite(PIN_SMPS_MODE, HIGH);

  pinMode(PIN_SJ_RDY, INPUT);
  pinMode(PIN_SJ_RES, OUTPUT);
  digitalWrite(PIN_SJ_RES, HIGH);       // active low, idle high

  Serial1.begin(DBG_BAUD);              // GP0/GP1 -> Debug Probe UART bridge

  // Serial2 belongs to the SpeakJet now, NOT DIN MIDI.
  Serial2.setTX(PIN_SJ_TX);
  Serial2.setRX(PIN_SJ_RX);
  Serial2.begin(SJ_BAUD);

  // v2 API: usbhMIDI.begin() calls tuh_init() internally and takes the
  // connect/disconnect callbacks. Do NOT also call USBHost.begin() or
  // tuh_init() separately.
  usbhMIDI.begin(&USBHost, 0, onMIDIconnect, onMIDIdisconnect);

  delay(2000);
  Serial1.println();
  Serial1.println(F("=== MIDI Voice Box Synth — step 7j ==="));
  Serial1.printf("transpose %+d, then playable range MIDI %d..%d (%u..%u Hz)\r\n",
                 NOTE_TRANSPOSE, MIDI_NOTE_MIN, MIDI_NOTE_MAX,
                 SJ_PITCH_MIN, SJ_PITCH_MAX);
  Serial1.printf("so incoming notes %d..%d play in range; outside that, folded\r\n",
                 MIDI_NOTE_MIN - NOTE_TRANSPOSE, MIDI_NOTE_MAX - NOTE_TRANSPOSE);
  uint16_t dictSize = 0;
  while (_dict_standard[dictSize].word != nullptr) dictSize++;
  uint16_t extraSize = 0;
  while (EXTRA_DICT[extraSize].word != nullptr) extraSize++;
  Serial1.printf("dictionary: %u standard + %u extra + %lu cmu words\r\n",
                 dictSize, extraSize, (unsigned long)BIGDICT_COUNT);

  Wire.setSDA(PIN_KBD_SDA);
  Wire.setSCL(PIN_KBD_SCL);
  Wire.begin();
  Wire.setClock(400000);
  kbdOk = kbd.begin(Wire, PIN_KBD_INT);
  if (kbdOk) Serial1.printf("keyboard ok, firmware 0x%02X\r\n", kbd.firmwareVersion());
  else       Serial1.println(F("keyboard NOT responding — 't' over serial still works"));

  Wire1.setSDA(PIN_SDA);
  Wire1.setSCL(PIN_SCL);
  Wire1.begin();
  Wire1.setClock(400000);
  oledInit();

  presetsBegin();
  cursor = strlen(lyricText);
  retokenise();
  setPlayhead(0);
  Serial1.printf("lyric: \"%s\" (%u tokens)\r\n", lyricText, tokenCount);
  checkLyric();

  sjReset();
  renderPlayView();
  printMenu();
}

void loop() {
  USBHost.task();
  usbhMIDI.readAll();
  sjqService();               // straight after MIDI: a new note's bytes start moving at once
  usbhMIDI.writeFlushAll();   // nothing is sent, but keeps the API contract

  if (kbdOk) serviceKeyboard();     // after MIDI, before display

  // Display work happens LAST, and only ever outside the MIDI callback.
  // Rendering and flushing are also split across separate iterations so a
  // single loop() pass never does both.
  if (displayDirty) {
    displayDirty = false;
    renderPlayView();
  } else {
    displayService();      // at most one page per iteration
  }

  while (Serial1.available()) {
    char ch = (char)Serial1.read();
    if (lineMode != LINE_NONE) lineInput(ch);
    else                       handleKey(ch);
  }
  lineService();
  playheadService();          // moves the highlight on when a word finishes
  cursorService();            // blinks the edit cursor
  logService();               // prints at most one queued note line per pass
  sjqService();               // top the UART FIFO up again before the next pass
}
