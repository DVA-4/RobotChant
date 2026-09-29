# M5Stack Tab5 Keyboard (SKU A164) — I2C reference

Extracted from `Tab5_Keyboard-I2C-Protocol-EN-V1.0.pdf` and
`Tab5_Keyboard_User_Manual_EN.pdf` in
`github.com/m5stack/M5Tab5-Keyboard-Internal-FW` (MIT).

Kept here because we write our own driver — M5's `UnitUnified` / `M5Unified`
libraries are ESP32-ecosystem and won't run on a Pico. Same approach that
worked for the SpeakJet dictionary and the SH1106.

## Hardware

| | |
|---|---|
| MCU | STM32F030C8T6 (matrix scanning, RGB, I2C) |
| Keys | 70, 14 × 5 matrix, multi-key rollover |
| I2C address | **0x6D** default (settable 0x08–0x77, stored in flash) |
| Logic / power | **3.3V** — 14.5 mA idle, 21.5 mA with RGB at full white |
| Interface | 2 × 5 pin header, 2.54 mm |
| RGB | 2 × WS2812E-1313 |
| Size | 128 × 59.4 × 13.1 mm |

**3.3V matters:** it matches the Pico's logic level natively, like the OLED, so
it needs no level-shifter channel. (Shifter channel 2 is spare anyway — see
`wiring_schematic.md` §2.)

**0x6D does not collide with the OLED at 0x3C**, so they can share a bus.

## Register map

| Reg | Field | Notes |
|---|---|---|
| 0x00 | INT_CFG | bit2 = Character-mode int enable, bit1 = HID, bit0 = Normal. Default 0x07 (all on) |
| 0x01 | INT_STAT | Same bit layout. **Write 0 to release the interrupt and clear status** |
| 0x02 | EVENT_NUM | Queue length in current mode, 0–32. Auto-decrements as events are read. Write 0 clears the queue |
| 0x03 | Brightness | RGB brightness 0–100, default 20 |
| 0x10 | Keyboard mode | 0 = Normal, 1 = HID, **2 = Character**. Default 0. Switching clears the previous mode's queue |
| 0x11 | RGB mode | 0 = Binding (status indication), 1 = Custom |
| 0x20 | KEY_EVENT | Normal mode: 1 byte. bit7 press/release, bits6:4 row, bits3:0 col. 0xFF = empty |
| 0x30, 0x31 | HID_EVENT | Modifier, Key_code. 2 bytes. 0xFF = empty |
| 0x40 | CHAR_EVENT_LENGTH | String length at head of queue. **0 = empty** |
| 0x50 | CHAR_EVENT Modifier | bit0 = Ctrl, bit2 = Alt |
| 0x51–0x59 | Char0..Char8 | Max string length 9 |
| 0x60–0x62 | RGB1 B, G, R | Custom RGB mode only |
| 0x64–0x66 | RGB2 B, G, R | Note the gap at 0x63 |
| 0xFE | Firmware version | R |
| 0xFF | I2C address | R/W, persists in flash |

⚠️ Flash write caution (from the protocol notes): setting the I2C address takes
~20 ms and wears flash. Don't write it repeatedly. Writing the same value is a
no-op, so it's safe to be idempotent.

## Interrupt behaviour

- INT is **high by default, pulled LOW** when an enabled mode has an event.
- **It does not auto-release.** The host must write 0 to 0x01 to clear it.
- If events remain queued after release, INT asserts again — so the queue
  drains naturally without polling.
- Setting `irq_pin = -1` in M5's own driver falls back to polling at 50 ms,
  which is a reasonable fallback if the INT wiring proves awkward.

## Character mode — the one we want

Event format: **1 modifier byte + N-byte string**.

Procedure (from the manual's flowchart):

1. Write `0x10 = 2` — character mode
2. Ensure character-mode interrupts are enabled in `0x00` (default 0x07 already does)
3. Wait for INT to go low
4. Read `0x01` to confirm the trigger source
5. Read `0x02` for the number of queued events
6. For each event: **read `0x40` first** for the length N, then read N+1 bytes
   from `0x50` (modifier + string)
7. Write 0 to `0x01` to clear and release INT

Constraints called out explicitly in the manual:

- **Only one event can be read at a time.**
- **Event length varies per event** — 0x40 must be re-read each time.

### Key behaviour

- **Sym, Aa, Ctrl, Alt generate no character events.** They update state /
  modifier flags in real time instead.
- **Sym** is the symbol toggle: unpressed gives the left-hand character, held
  gives the upper-right one.
- **Aa** toggles case, handled entirely inside the keyboard's own firmware —
  including tap-for-next-char, hold-for-temporary, and lock modes, with LED
  feedback. **We don't implement shift logic at all.**
- **All other keys emit on press only, not on release.** No key-up handling.

### Key name strings — RESOLVED, no longer unknown

Not in M5's PDFs, and not in their Arduino library (`M5Unit-KEYBOARD`, which
just passes the device's string through). They live in the keyboard's own STM32
firmware: `code/Keyboard_APP/Core/User/keyboard/user_keyboard_handle.c` in
`M5Tab5-Keyboard-Internal-FW`. Each key is stored as
`{unshifted_string, hid_mod, hid_code, shifted_string, hid_mod, hid_code}`,
where "shifted" means Sym or Aa applied; the Character-mode event string is the
1st or 4th field.

**Complete set of multi-character names:**

| Unshifted | Shifted (Aa active) |
|---|---|
| `tab` | `tab` |
| `backspace` | `BACKSPACE` |
| `enter` | `ENTER` |
| `esc` | `ESC` |
| `del` | `DEL` |
| `up` / `down` / `left` / `right` | `UP` / `DOWN` / `LEFT` / `RIGHT` |
| `sym`, `Aa`, `ctrl`, `alt` | — **never emitted as character events** |

Everything else is a **single character**: `a`–`z` / `A`–`Z`, `0`–`9`, and
punctuation `! # $ % & ' ( ) * + , - . / : ; < = > ? @ [ ] \ ^ _ \` { | } " ~`.

**Two facts that make the parser trivial:**

1. **Space is the 1-character string `" "`.** So "length 1 → literal character"
   needs no special case for it.
2. **Named keys appear in both cases** (`enter` vs `ENTER`) depending on whether
   Aa is active. **Compare case-insensitively.**

`backspace` at 9 characters is exactly the protocol's stated maximum, which
corroborates the whole table.

### ⚠️ CORRECTION, verified on hardware 15 Sep: **length INCLUDES the null terminator**

The protocol PDF says register 0x40 holds "the length of the string", which reads
as a character count. **It is the buffer length including a trailing `0x00`.**
Observed:

```
single char '3'  -> len 2   hex: 33 00
space            -> len 2   hex: 20 00
BACKSPACE        -> len 10  hex: 42 41 43 4B 53 50 41 43 45 00
```

This also explains why the PDF states a maximum character length of 9 alongside
a Char0..Char8 register range: 9 characters + terminator = 10.

**Two consequences, both convenient:**
- Read `len + 1` bytes from 0x50 — 1 modifier + the string *including* its
  terminator. (The same arithmetic as reading a modifier plus an unterminated
  string, so code written on the wrong assumption still works by accident.)
- The bytes from 0x51 onward are **already a valid C string**. No copying or
  manual termination needed.

**Parser rule (corrected):**
```
len == 2  -> single literal character (includes space)
len >  2  -> named key, len-1 chars, strcasecmp against:
             enter, backspace, del, esc, tab, up, down, left, right
```

### Other hardware-confirmed behaviour (15 Sep)

- `INT_STAT` reads **0x04** in Character mode — bit 2, matching the mode.
- **One event per keypress.** INT releases cleanly once the queue is drained.
- **⚠️ Clearing `INT_STAT` does NOT consume events.** Doing only that with a
  non-empty queue makes INT re-assert within ~2 ms, forever. The correct order
  is: read `EVENT_NUM` → read that many events (0x40 then 0x50, reading an event
  auto-decrements the count) → *then* write 0 to `INT_STAT`. Writing 0 to
  `EVENT_NUM` (0x02) clears the queue outright, and switching modes (0x10) also
  clears the queue and releases the interrupt — either is a way out of a stuck
  full queue.
- **Queue maximum is 32**, as documented, and it does fill in normal use if
  nothing drains it.
- **`BACKSPACE` arrived uppercase with `mod 0x00`.** The firmware source implies
  lowercase is the unshifted form — so don't assume which case will arrive.
  Matching case-insensitively makes this moot.
- Keycap legends and emitted characters don't always agree (the backslash key
  emitted `0x5C` unshifted). The real layout is discovered by typing.
Sym/Aa/Ctrl/Alt never arrive as events, so they need no handling — Ctrl and Alt
show up only as bits in the modifier byte.

## Wiring — resolved

- **Own bus: I2C0 (`Wire`) on GP8/GP9**, separate from the OLED on I2C1. The
  OLED's page flushes are the long I2C operations (~3 ms each); isolating the
  keyboard removes any contention with its low-latency interrupt reads.
- **INT on GP10.**
- Full pin table and the P1 header pinout: `wiring_schematic.md` §1 and §4.
