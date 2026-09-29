# RobotChant - Hardware MIDI speech synthesiser

A monophonic **speech synthesiser played from a MIDI keyboard**. Each note-on
speaks the next word of a lyric, pitched by the note. It is deliberately
robotic; the reference points are Cylob's *Rewind* and Daft Punk's *Discovery*.

A Raspberry Pi Pico 2 hosts a USB MIDI controller and drives a SpeakJet chip on
SparkFun's Voice Box Shield. The lyric is edited live on an M5Stack Tab5
keyboard and shown on a 128×64 SH1106 OLED, with the sounding word large and a
playhead that follows the performance.

---
<img src="docs/images/RoboChant.jpg" width="409">
---

**Status:** finished, cased and played. See [`docs/project.md`](docs/project.md)
for the full design record.

## Features

- **Three-tier dictionary, 31,000+ words.** Hand-written overrides, Sensory's
  hand-tuned 1,427 words, and 30,000 words converted from CMUdict by a model
  *learned* from Sensory's tuning. Covers 99% of the 1,000 commonest English
  words.
- **Cut, not drop.** A new note cuts the sounding word (worst case 5 ms), like a
  monosynth stealing its voice. Overplaying clips words; it never loses notes.
- **Live lyric editing** with a cursor, word navigation and undo, while playing.
  There is no separate edit mode.
- **10 lyric presets in flash**, and performance commands on the keyboard's
  symbol row, each confirmed on the display.
- **Expression:** note → pitch, pitch-bend strip → speaking speed, mod strip →
  timbre (SpeakJet Bend).
- **MIDI first.** Nothing heavy runs in the MIDI callback; serial output, the
  display and the SpeakJet UART are all fed incrementally from `loop()`.

## Hardware

| Part | Notes |
|---|---|
| Raspberry Pi Pico 2 | The plain one, not the W |
| SparkFun Voice Box Shield | SpeakJet, run at 5 V |
| 4-channel level shifter | BSS138-style, 3.3 V ↔ 5 V for the SpeakJet lines |
| SH1106 OLED, 128×64, I2C | 0x3C on I2C1 |
| M5Stack Tab5 Keyboard (A164) | 0x6D on I2C0, INT on GP10 |
| USB OTG hub + MIDI controller | Developed with an Arturia KeyStep |
| Regulated 5 V supply | Feeds VSYS **and** VBUS — see the warning below |
| Line-output transformer | Neutrik NTE 10/3 (optional, fixes the noise floor) |

Full pin assignment, power, grounding and audio output:
[`docs/wiring_schematic.md`](docs/wiring_schematic.md).

> ⚠️ **Power.** In USB host mode the Pico must *source* VBUS, so VBUS is tied to
> the 5 V supply. With that tie in place, **never plug the Pico's micro-USB into
> a computer while the supply is live.** Details in the wiring doc, §3.

## Building the firmware

1. **Arduino IDE 2.x** with the
   [arduino-pico](https://github.com/earlephilhower/arduino-pico) core
   (Earle Philhower).
2. Library Manager: install **EZ_USB_MIDI_HOST, version 2.0 or later**, and
   accept its dependencies. Pre-2.0 versions have a different API and won't
   compile.
3. Open `firmware/07j_pacing/07j_pacing.ino`.
4. **Tools → Board:** Raspberry Pi Pico 2.
   **Tools → USB Stack:** Adafruit TinyUSB Host (native). The sketch refuses to
   compile with anything else.
5. Upload. In host mode the Pico's own USB port disappears, so use BOOTSEL/UF2
   or a Debug Probe over SWD.

Debug output and the serial menu are on `Serial1` (GP0/GP1, 115200 baud), meant
for a Raspberry Pi Debug Probe's UART bridge. The menu is printed at boot, and
`?` + Enter shows it again. It works without a MIDI device attached: `t` types a
new lyric, `c` lists every word no dictionary knows, `?word` looks a word up, and
`n` / `m` play a test note.

The dictionaries take about 650 KB of flash; nothing is loaded into RAM.

## Playing

Every key press edits the lyric; every note speaks the next word. The keyboard
map is in [`docs/project.md`](docs/project.md) §3.4. In brief:

| Key | Action |
|---|---|
| left / right (ctrl: by word) | move the cursor |
| up / down | start / end of the lyric |
| tab | jump to the word the playhead is on |
| esc, ctrl+z | clear the lyric, undo the clear |
| 0–9, ctrl+0–9 | recall / save a preset |
| `! @ # $ % ^ & *` | pre-flight check, playhead reset, flush toggle, speed default, bend default, bend strip on/off, mod wheel on/off, SpeakJet reset |

To add or fix a word, add one line to `extradict.h`, which is searched first.
The file explains how, and the quickest method is to take a rhyme that already
sounds right and swap its first consonant.

## Regenerating the dictionaries

`bigdict.cpp` and parts of `extradict.h` are generated, and committed so the
sketch builds straight away. You only need these tools to change them.

```sh
# 30,000-word tier. Needs cmudict.dict in firmware/07j_pacing/
pip install wordfreq
python3 tools/cmu2bigdict.py --eval   # cross-validation against Sensory's tuning
python3 tools/cmu2bigdict.py 30000    # rewrites bigdict.cpp / bigdict.h

# extradict.h sections 2-5. Needs PhraseALator.Dic in firmware/07j_pacing/
python3 tools/dic2extradict.py --verify
python3 tools/dic2extradict.py
```

`cmudict.dict` comes from [cmusphinx/cmudict](https://github.com/cmusphinx/cmudict).
`PhraseALator.Dic` ships with Sensory's Phrase-A-Lator software and isn't
included here. Both files are git-ignored. Set `SKETCH_DIR` to point the tools at
a different folder.

Regenerating the 30,000-word tier from the current inputs reproduces the
committed `bigdict.cpp` byte for byte.

## Repository layout

```
firmware/07j_pacing/   the sketch and everything it compiles
tools/                 dictionary generators (offline, Python 3)
docs/                  design record, wiring, keyboard protocol
```

The Arduino IDE only compiles files inside the sketch's own folder, which is why
the shared headers live next to the `.ino`.

**About the docs:** they are the working record of the whole build, so they also
mention earlier step sketches, a host simulator (`hostsim/`) and reference files
that aren't part of this repository. Only the final build, step 7j, is published
here.

## Licence

The firmware and tools are released under the **GNU General Public License,
version 2** — see [`LICENSE`](LICENSE). The exception is the 5×7 display font,
`eltro_font5x7.h`, which is MIT-licensed so it can be reused anywhere.

The licence is set by `standardDict.cpp`, which comes from Mike McCauley's
SpeakJet library (GPL v2). Other third-party material, including the CMUdict
notice that `bigdict.cpp` requires, is listed in
[`THIRD_PARTY.md`](THIRD_PARTY.md).

Copyright © 2026 Fabian Rieber
