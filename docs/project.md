# MIDI Voice Box Synth — project summary

A monophonic **speech synthesiser played from a MIDI keyboard**. Each note-on speaks the next word of a lyric, pitched by the note number. Deliberately robotic — the aesthetic reference points are Cylob's *Rewind* and Daft Punk's *Discovery*.

**Status: FINISHED AND IN ITS CASE.** All seven build steps plus 7c–7j are done and confirmed on hardware, the noise floor is resolved, and the instrument runs from a regulated step-down supply inside the enclosure. What remains (§3.3) is optional and none of it is in the way of playing. Last revised 18 Sep.

Companion documents:
- `wiring_schematic.md` — hardware, pin assignment, power, audio output
- `tab5_keyboard_reference.md` — Tab5 Keyboard I2C protocol
- `PhraseALator.Dic` — Sensory's original dictionary source, the input to McCauley's converter. Reference only, not compiled
- `hostsim/` — host simulator: compiles the sketch on a PC against mock Pico hardware (§2.1)

---

## 1. What works today

| | |
|---|---|
| **Sound** | Pico drives SpeakJet over hardware UART at 9600 baud; notes are queued and fed to the UART from `loop()`, never from the MIDI callback (§4.4) |
| **MIDI** | USB host via `EZ_USB_MIDI_HOST` behind a generic OTG hub; Arturia KeyStep |
| **Pitch** | Note number → Hz directly, transposed −12, folded into range |
| **Lyrics** | Three dictionaries, searched in order: `extradict.h` (hand-written + the entries McCauley's converter dropped + corrected `fx*`), Sensory's 1427, and 30,000 CMUdict-derived words (§4.5). 99% of the 1000 commonest English words are covered. Tokenised on whitespace, hyphens and `,` `.` `!` `?` `;` `:` `"` `(` `)` — not apostrophes |
| **Display** | SH1106 play view — the **sounding** word large, 3-line lyric window, playhead inverted; the highlight moves on when a word ends (§4.6) |
| **Keyboard** | M5Stack Tab5 Keyboard on I2C: live lyric editing with a cursor, 10 flash presets, performance commands on the symbol row (§3.4) |
| **Expression** | Pitch strip → Speed · Mod strip → Timbre/Bend · velocity plumbed but pinned |

**Current sketch: `07j_pacing`** — the full instrument.

---

## 2. Sketch inventory

Each builds on the last; earlier ones are kept because they isolate one subsystem for debugging.

| Sketch | Purpose | USB Stack |
|---|---|---|
| `01_speakjet_raw` | Raw phoneme codes over UART, no library, no USB. Menu-driven. | either |
| `03_midi_speakjet` | + MIDI host, hardcoded tokens, pitch mapping | TinyUSB Host |
| `03a_speakjet_nousb` | Same engine, no USB host — bench work without the host stack | Pico SDK |
| `04_dictionary` | + real dictionary, text buffer, `t`/`c`/`d`/`?` menu commands | TinyUSB Host |
| `05_synth_oled` | + SH1106 play view | TinyUSB Host |
| `06a_i2c_scan` | Standalone I2C scan (OLED) | either |
| `06_oled` | Standalone display test, runtime SH1106/SSD1306 offset toggle | either |
| `07a_kbd_scan` | Standalone keyboard scan, mode switch, event dump | either |
| `07b_kbd_driver` | Keyboard driver + edit logic over serial, no display | either |
| `07_synth_kbd` | Keyboard integrated; superseded by 7c | TinyUSB Host |
| `07c_fixes` | Review fixes: logging off by default, non-blocking `t`/`?`, second MIDI device ignored, more token breaks, comment drift | TinyUSB Host |
| `07d_txqueue` | SpeakJet TX queue + deferred logging; `q` statistics | TinyUSB Host |
| `07e_bigdict` | + 30,000-word dictionary | TinyUSB Host |
| `07f_playhead` | Playhead anchored to the text, not a token index | TinyUSB Host |
| `07g_sounding` | Highlight follows the sounding word | TinyUSB Host |
| `07h_editview` | Edit cursor, navigation keys, clear + undo | TinyUSB Host |
| `07i_presets` | Lyric presets in flash, symbol-row commands | TinyUSB Host |
| **`07j_pacing`** | **Current full build** — paced TX, retrigger cut 37 ms → 5 ms | TinyUSB Host |

Shared files: `dict.h`, `extradict.h`, `standardDict.cpp`, `bigdict.cpp`, `bigdict.h`, `eltro_font5x7.h`, `tab5kbd.h`. Reference only: `PhraseALator.Dic`, `speakjetusermanual.pdf`.

Tooling (offline, Python): `dic2extradict.py` regenerates `extradict.h` sections 2–5 from `PhraseALator.Dic`; `cmu2bigdict.py` regenerates `bigdict.cpp` from CMUdict. Both have a self-check mode.

### 2.1 Host simulator

`hostsim/` compiles the **real sketch** on a PC against mock Pico APIs, so logic and timing structure can be checked before flashing. It does not model electrical behaviour or sound.

- **Mock UART** models the RP2350's 32-byte FIFO at the configured baud, and blocks in simulated time exactly where `uart_putc_raw` would. This is how the 35 ms note-on callback was measured.
- **Mock I2C** decodes address 0x3C into an SH1106 framebuffer, so the play view can be printed as a picture.
- **Scripted MIDI** is delivered from `readAll()`, i.e. in real callback context, and the callback's duration is measured.
- ⚠️ **`arduino_proto.py` must be run first.** It emulates the IDE's prototype insertion (§5); plain `g++` misses that class of error, and 07c failed to compile in the IDE after passing the simulator.
- **The Tab5 keyboard is emulated** over mock I2C (register protocol, INT held low while events are queued), so typing in a test takes the real path: INT → driver → `serviceKeyboard()`.
- **The EEPROM mock** is a RAM buffer that persists across a simulated reboot (calling `setup()` again), so preset persistence is tested rather than assumed.
- Test suites: `test_07c.cpp`, `test_07d.cpp` (includes a model of the SpeakJet's input parser), `test_07e.cpp` (exhaustive dictionary search), `test_07f.cpp` (editing vs the playhead), `test_07g.cpp` (word-length timing), `test_07h.cpp` (cursor, located by framebuffer diff), `test_07i.cpp` (presets, flash, symbol row), `lateness.cpp`. `shim.h` / `shim_offset.h` let one test source run against several steps; 7g+ need `-DSKETCH_HAS_SOUNDING`, 7i+ `-DSKETCH_HAS_PRESETS`.
- **Tests are run against the previous step too**, which is how each fix is shown to matter: `test_07f` fails on 07e exactly where the anchoring bug is.

---

## 3. Remaining work

### 3.1 Step 7 — keyboard integration (done; decisions recorded)

**The edit view is built** (7h, 7i — see §3.4 for the key map and the reasoning). The questions that were open here are answered:

- **Editing and playing coexist with no mode switch.** Typing always edits, notes always play.
- **The window follows the cursor for 4 s after a keystroke, the playhead otherwise.**
- **The cursor is a blinking 1-px bar, drawn inverted** — inversion was already taken by the playhead block, and a *lit* bar disappears inside it.
- **The 2× word and the highlight move together**, which surprised the performer but reads well — left as is, revisit only if it starts to grate in practice.

Already decided and implemented:

- **The large word and the inverted block show the word currently SOUNDING**, and the highlight moves to the next word when that word finishes — before the next note arrives (§4.6). Showing the *upcoming* word (which is what advancing the playhead at note-on produced) was attractive in theory as performance read-ahead, but kept feeling unnatural over weeks of playing. Moving on at the end of the word gives the read-ahead without the wrongness.

- **The playhead is anchored to a character offset, not a token index** (7f). A token index cannot survive editing: inserting a word near the start renumbers every later token, so index 4 stops meaning the word you were on — with "hello i am a robot" and "robot" next, typing "there" after "hello" used to make "a" next. `playheadOffset` holds the character position of the next word's first letter; edits before it shift it, edits inside or after it don't; `syncPlayheadFromOffset()` recovers the index after `retokenise()`. It prefers the token *containing* the offset (typing inside the anchored word keeps it), then the first token starting after it (deleting the anchored word moves on), then the last (clamping at the end). Move the playhead only via `setPlayhead()` so index and offset stay in step.
- **Enter** (and menu `0`) resets to the start explicitly; `d` prints the offset alongside the index.

### 3.2 Hardware

- ✅ **Noise floor is resolved** — transformer + trimpot; no capacitor mods were needed. Contingency steps if it ever returns: `wiring_schematic.md` §5.1.
- ✅ **Output transformer fitted and trimpot set.** §5.2.
- ✅ **Regulated step-down supply fitted**, verified clean on the scope; line out clean with it.
- ✅ **Case finished**, everything mounted and working.

### 3.3 Smaller open items

- `SJ_SPEED_MIN` (currently 45) — a guess, wants tuning by ear
- ~~Brighten the voice by changing C4/C7 to 4.7 nF~~ — **decided against.** The voice sounds right as built, and the stock values bury the 32 kHz PWM carrier by ≈67 dB; the designers chose them for a reason. `wiring_schematic.md` §5.3
- Two devices on the hub is still unproven — no longer needed, but untested
- **Digits don't speak.** `1` isn't a dictionary word in any tier (CMUdict has `one`, not `1`). Mapping digits to number words in the tokeniser would fix it
- **Long `fx*` entries are still off** (`EXTRADICT_LONG_FX`, 7 entries of 59–280 codes). Needs `codeLength()`/`len` widened to `uint16_t` plus a paced sender; the TX queue (§4.4) is the groundwork
- **A letter-to-sound fallback** would remove misses entirely — see §6 for why that is the one dictionary failure that actually matters. **Deferred:** in practice a missing word can be approximated by spelling it as a similar word that *is* in the 30k, which is good enough for now

### 3.4 Editing and the keyboard (7h, 7i)

**There is no separate edit mode.** The single view is always editable and the cursor is always on screen — one fewer piece of state to be in the wrong half of during a performance.

| Key | Action |
|---|---|
| left / right | one character; **ctrl+** them for whole words |
| up / down | start / end of the text |
| tab | jump the cursor to the word the playhead is on |
| esc | clear the lyric — **ctrl+z** restores it (press again to redo) |
| backspace / del | as before |
| **0–9** | recall lyric preset; **ctrl+0–9** saves the current lyric to that slot |
| **! @ # $ % ^ & &ast;** | pre-flight check · playhead reset · flush toggle · speed default · bend default · bend strip on/off · mod wheel on/off · SpeakJet reset |

- ⚠️ **The cursor is drawn INVERTED, not lit.** A lit bar is invisible inside the playhead's inverted block, which is exactly where it sits while editing the word you're on. The bug survived code review and was caught by a framebuffer diff in the simulator; `test_07h.cpp` guards it.
- **The window follows the cursor for 4 s after a keystroke**, then goes back to following the playhead, so performing looks unchanged.
- **Digits and those symbols no longer type.** No dictionary tier speaks digits, and the symbols are token breaks like space, so nothing is lost.
- **Every keyboard command reports on a status line** that takes over the header for 1.8 s. On stage the debug probe isn't attached, so a command with no feedback may as well not exist. Commands that only *print* (token list, queue stats, word estimates) are deliberately not on the keyboard.
- **Presets live in one flash sector** via arduino-pico's EEPROM emulation: magic, then 10 fixed 256-byte slots, 2.5 KB of 4 KB. A slot starting 0 or 0xFF is empty — erased flash reads 0xFF, so an unformatted board formats itself once at boot. ⚠️ `commit()` erases and rewrites the sector with interrupts off, a few ms, which is why it happens **only** on an explicit ctrl+digit save. Recall is undoable like any other destructive edit.
- **Long-press was the original idea for saving** and is impossible: in character mode the keyboard emits on press only, with no key-up events (`tab5_keyboard_reference.md`). Ctrl+digit replaced it.

### 3.5 Code review items (16 Sep) — status

**Fixed in 7c:** note logging defaults off; `t` and `?` no longer block `loop()` (they wait for Enter, which also made them work with character-mode terminals — the old 20 ms timing guess meant `?` always opened the menu); a second USB MIDI device is ignored for real, and unplugging it no longer disconnects the first; the tokeniser breaks on `! ? ; : " ( )`; dead `currentIsMiss` removed; comment drift corrected (GP5, VBUS, banners, the `fxping` misreading).

**Fixed in 7d:** `Serial2.write()` blocking inside the note-on callback, and note logging is deferred to `loop()`.

**Still open:** long `fx*` entries and the digits gap (§3.3); the playhead's token-index anchoring (§3.1); font covers 0x20–0x7A, so `{ | } ~` render blank.

**`renderPlayView()` still scans the dictionary** for the miss indicator. Left alone deliberately: rendering runs in `loop()`, never in the callback, so a 1427-entry scan is affordable and the alternative (caching the result) adds state for no audible gain.

---

## 4. Key design decisions

### 4.1 Pitch mapping

**The SpeakJet Pitch register value IS the frequency in Hz**, one-to-one. Confirmed by ear: the same phrase at 40/80/160/240 stepped in octaves. An early revision of this doc wrongly claimed 0–255 mapped onto 32–240 Hz.

```c
pitch = round(440 * 2^((note + NOTE_TRANSPOSE - 69) / 12)), clamped 32..240
```

- Documented singing range **32–240 Hz = MIDI 24 (C1) to 58 (Bb3)**. The whole instrument lives *below middle C*.
- **`NOTE_TRANSPOSE = -12`.** Without it the keyboard's natural range sits above the ceiling and the top third folds back down, making high keys sound lower than the middle. −12 maps a KeyStep's 36–67 onto 24–55, entirely in range.
- **Fold, don't clamp**, for out-of-range notes — preserves pitch class so every key does something musical. With the transpose applied it rarely triggers.
- Resolution is poor at the bottom (integer Hz ≈ ±15 cents near 33 Hz) but the bottom key was checked and sounds fine.
- Pitch only affects **voiced** sounds. A token of entirely unvoiced phonemes ignores the note.

### 4.2 Note handling

- **Note Off is not handled at all** — no handler registered. Key release must not interrupt the sounding syllable, nothing is held, so no state and no stuck-note class of bug.
- ⚠️ **Note On with velocity 0 must be discarded** inside the note-on handler. Many controllers send this instead of a true Note Off; without the check every key *release* fires a second syllable. (The KeyStep sends true note-offs, so it isn't needed there — but the instrument should accept arbitrary controllers.)
- **Velocity is plumbed end-to-end but pinned to 96** (SpeakJet's own Volume default) at the MIDI boundary. The engine takes it as a real parameter. Deleting one line in the handler enables dynamics. Deferred because it may complicate playing.

### 4.3 Retrigger: cut, not drop

**A new note-on flushes the buffer and cuts off the sounding syllable.** SCP escape `\0 R X` before each token — SCP commands execute on receipt rather than queueing, and `R` clears the SpeakJet's 64-byte input buffer (manual, SCP command table). **This is Sensory's own stop sequence:** Phrase-A-Lator's "Shut Up" button sends `\0RX` followed by Reset and P0.

This was decided, reversed, and re-decided; the reasoning matters more than the conclusion. Burst testing at 150 ms showed long tokens consistently cut ("hello" lost entirely) while short ones survived, which initially read as an arbitrary fault. The reversal to a "drop" scheme was wrong for three reasons:

1. **Truncation isn't constant** — it's the instrument responding to being overplayed. At moderate pace nothing is cut.
2. **Drop has the worse failure mode.** With cut, every note produces an attack at the right moment and a clipped word is legible feedback to slow down. With drop, notes randomly produce *nothing* — indistinguishable from a dropout or a dead key, and it destroys rhythm.
3. **Cut is idiomatic.** A monosynth steals its voice on every new note. No instrument behaves like drop.

**The player's lever is word choice** — shorter words complete faster. (Hyphenation was meant to serve this but mostly doesn't; see §4.5.)

### 4.4 SpeakJet command handling

**Per-note parameter block:** `20,vol · 22,pitch · 21,speed · 23,bend` then the token's phoneme codes.

- All four parameters **latch** — they hold until changed. Sending all four every note makes each note deterministic.
- ⚠️ **The block is what makes `fx*` entries safe.** Many of them set Speed, Bend or Pitch (`\NT` notes) mid-entry, and those latch. The corrected entries in `extradict.h` deliberately drop Sensory's Resets (§4.5), so the next note's block is the only thing restoring the performer's state. It must stay complete. *(An earlier revision said `fxping`/`fxrobotsad` "embed a Bend that latches" — a misreading of data corrupted by the RESET bug.)*
- **Buffer budget: 64 − 8 = 56 codes per note.** The SpeakJet's input buffer is 64 bytes and it speaks far slower than 9600 baud delivers, so a longer entry overflows. SCP commands (the flush) execute immediately and are *not* stored in that buffer, per the manual.
- ⚠️ **`Serial2.write()` blocks past 32 bytes, so notes are queued instead (7d).** arduino-pico's `SerialUART::write` calls `uart_putc_raw`, which blocks once the RP2350's 32-byte hardware FIFO is full — ≈1 ms per excess byte at 9600. `fxcountdown` (66 bytes) stalled the note-on callback for 35 ms. `speakNext()` now only enqueues; `sjqService()` feeds the UART from `loop()` while `availableForWrite()` says there is room. *(An earlier revision cited the SpeakJet's 64-byte buffer as the budget; that's the chip's limit, not the Pico's.)*
  - **Groups must stay intact.** A command with an argument (20–26, 28–30) must never be separated from it, and the 4-byte SCP flush must go out whole, or the chip takes a following byte as a stray argument. Each queued byte carries its group length, recorded at enqueue time — *not* inferred from byte values, since an argument can be any byte, including 92 (`\`).
  - **Retrigger discards stale queued bytes** (the flush would cut them anyway), except the remainder of a group already partly in the FIFO. A trailing command with no argument is dropped at enqueue.
  - **Latency is unchanged, ≈4 ms at normal playing speeds.** Worst case under fast retriggering is ≈37 ms in both the queued and unqueued versions, set by the bytes already committed to the FIFO. *A prediction that the unqueued version would fall progressively behind was measured and disproved.*
  - ⚠️ **Bytes are PACED into the UART (7j), one per 1150 µs** — just under the 1042 µs line rate. Filling the 32-byte FIFO *commits* those bytes: a retrigger flush can only cut the sound after they have all clocked out, which was the entire 37 ms worst case. Held in our RAM queue instead, they can still be discarded. Measured worst-case cut: **37 ms → 5 ms**, confirmed by ear as noticeably snappier; throughput unchanged, since the line was never faster than this.
  - **The 4-byte flush is exempt from pacing** — it *is* the cut. Pacing it added a byte time each plus `loop()` jitter (a display page flush costs ~3 ms), which left the first attempt at 11–15 ms instead of the predicted 5.
  - **Pace slightly SLOWER than the line, never faster.** Too slow leaves the FIFO empty for a moment, which is harmless: the chip speaks ~10 codes/s while the line carries 960 bytes/s, so its 64-byte buffer cannot run dry mid-word. Too fast lets the FIFO silently refill and restores the old latency.
  - Queue is 512 bytes; `q` prints the pacing interval, depth, stale bytes discarded and notes dropped. Notes are only dropped with flush-on-note **off**, and then whole, keeping the stream valid.
- **Never poll RDY per code — and RDY couldn't pace anyway.** Per the manual, D0/Ready only signals that self-test passed. Buffer Half Full (D2) is the flow-control line, and this shield doesn't connect it.
- **Code arrays are terminated by 255** (EndOfPhrase) — the dictionary's sentinel, *not* a SpeakJet command. Must not be transmitted.

### 4.5 Dictionary — data, not code

**We took the SpeakJet library's dictionary data and discarded its code.** Its speaking machinery (SoftwareSerial, blocking per-code RDY polling, speak-a-whole-string) conflicts with everything here. `standardDict.cpp` needed exactly two edits: the include, and the type name. **Do not install the SpeakJet library.**

Both flagged unknowns evaporated: PROGMEM is a no-op on RP2350 (flash is memory-mapped, ordinary dereferencing works), and the SoftwareSerial question is moot because the library's serial layer is never called.

⚠️ **Hyphenation mostly doesn't work as intended.** It's a *word* dictionary, so fragments only resolve if they happen to be words — `ro`, `hel`, `lo` all miss (`bot` happens to hit). The responsiveness lever is therefore word choice, not punctuation.

**Misses stay silent but still advance the playhead**, so the lyric tracks the notes played. Pre-flight checking is the real answer — `'c'` reports every missing word.

**Adding words is one line** in `extradict.h`, which is searched *before* the standard dictionary (so it also overrides pronunciations). **Technique: find a rhyme already in the dictionary and swap the onset consonant** — `done` is `none` with `NO`→`DO`. `PhraseALator.Dic` is human-readable for this; `?word` prints any word's codes. 24 common words were added this way and all sounded right first time.

⚠️ **Two typos in McCauley's `SpeakJet.h`:** it gives `RR = 149` (colliding with `IYRR`) and `DO = 174` (colliding with `DE`). The manual's correct values are 148 and 175; `extradict.h` uses those. These are only in the header — the converted *data* uses 148 and 175 correctly.

⚠️ **A third converter bug IS in the data: `\RESET` was emitted as 30.** Phrase-A-Lator (and the manual) define Reset Defaults as **31**; 30 is *Delay, X*, which takes the next byte as its argument. All 9 `fx*` entries in `standardDict.cpp` are affected. Each one swallows the byte after its leading "reset" (in `fxping` that eats the Speed command) and ends on a Delay still waiting for its argument — which becomes the first byte of the *next* note. `extradict.h` overrides all 9.

**The correction drops the Resets instead of changing them to 31.** A leading Reset would wipe the parameter block sent just before the codes, so effects would ignore the key's pitch and both strips. A trailing Reset is redundant because every note re-sends all four parameters (§4.4). Consequence: effects start from the performer's current state rather than chip defaults, and any without `\NT` notes follow the key.

**McCauley's converter silently dropped 25 entries** — every key containing a non-letter character or an unsupported token: 5 contractions (`can't`, `o'clock`, `shouldn't`, `that's`, `they're`), `x-ray` and `yo-yo`, and 18 `fx*` entries using plain words, `\NT` notes, DTMF codes, `\DELAY` or a malformed token. All are now in `extradict.h`: contractions verbatim (the apostrophe isn't a token break, so they match), `yo-yo` stored as `yoyo` (hyphen *is* a break), `x-ray` unnecessary (`xray` already exists), and all 18 `fx*` entries.

**Those sections of `extradict.h` are generated** by `dic2extradict.py` (run it in the sketch folder; `--verify` repeats the validation below), a translator following the original tool's rules (`benbaker76/PhraseALator`, a C# port of Phrase-A-Lator, `SpeakJet.cs`). It was validated by regenerating all 1427 standard entries: byte-for-byte identical apart from the nine RESET codes. The rules, for hand-editing: `\TOKEN` → code; `\123` → byte 123; `\NTC2` → Pitch + Hz from a fixed table (scientific pitch, integer Hz); a plain word → that word's codes, recursively; each `,` → `\P2`; two spaces → `\P6`; three or more → `\P4 \P1`.

Two data errors in the Dic were fixed to intent: `fxwomwom` writes `\BEND \ 1` (stray space, which the original tool would turn into Bend = the next sound code), and `fxdanger`'s `\NTA#2` (the original tool strips `#`, playing A2).

**`\SOFT` is code 18.** A real Phrase-A-Lator command used before B phonemes in 27 words, but undocumented in the manual. "robot" uses it and sounds fine.

#### The 30,000-word tier (7e)

Sensory's 1427 words covered under half of the 1000 commonest English words. `bigdict.cpp` adds 30,000 more, taking that to **99%**.

- **No large SpeakJet dictionary exists to borrow.** Sensory's is still the biggest hand-tuned one. `lexconvert` can output SpeakJet codes but maps each phoneme to one fixed allophone (every D → `DO`) and adds no modifiers; it matched Sensory's allophones for 11% of shared words. The TTS256 chip did letter-to-sound rules in hardware and is retired.
- **The converter is LEARNED from Sensory's entries.** `cmu2bigdict.py` aligns each Sensory word against its CMUdict pronunciation, then learns which allophone *and* which modifiers Sensory used per phoneme in context (stress, neighbours, word position), with backoff from specific to general contexts.
- **Measured by 5-fold cross-validation**, so no word is scored by a model that saw it: allophones exactly right for **39%** of words (naive 11%), 22% of allophones differing on average (naive 49%). With modifiers included, 19% exact (naive 3%). Model variants all landed within a percent, so this is the plateau for this training data — some of the gap is irreducible, since CMUdict and Sensory genuinely disagree (`tonight` is T-AH-N vs `TT UW NO`) and Sensory isn't self-consistent.
- ⚠️ **That score measures agreement with Sensory, not whether a word sounds good.** The words tested on hardware sounded fine. §6 explains why this bar is the right one.
- **Storage and lookup.** One sorted blob in flash (~600 KB): `word 0 codes 255`, with a `uint32` offset index; binary search comparing lowercased bytes, ~15 steps, no RAM cost. Python sorts by raw bytes so the two orders agree. Verified in the simulator: all 30,000 words found in lower, upper and mixed case with byte-exact codes, and no false hits among 1,240 near-miss spellings.
- **`bigdict` deliberately contains no word already in the other two tiers**, and is searched last anyway, so hand-tuned pronunciations always win. `?word` reports which tier answered: `[extra]`, `[standard]`, `[cmu]`.
- Sources: CMUdict (BSD), `wordfreq` for ranking only (Apache-2.0). Pronunciations are US English, first variant only, so homographs (`read`, `live`) get one reading.

### 4.6 Word duration — how we know a word has ended

The highlight moves on when a word finishes (§3.1), so the sketch needs to know when that is. **The chip won't tell us**: D0/Ready is only a self-test flag, and D1/Speaking isn't wired to the Pico — it's on shield pin 4, and level-shifter channel 2 is free if we ever want it (`wiring_schematic.md` §2, §6). So the duration is **computed**:

- **Per-allophone times from the manual's Table D** (10–225 ms each; most phonemes 70 ms, `TS` and the diphthongs up to 225).
- **`7` FAST halves the next phoneme, `8` SLOW multiplies it by 1.5**, pause codes 0–6 add 0/100/200/700/30/60/90 ms, `30` Delay adds its argument × 10 ms. Stress, relax and soft don't change length.
- ⚠️ **The Speed register's effect on duration is undocumented.** We assume it scales as `114/speed`. Combined with UART and chip latency (a flat 15 ms), that is what `SPEECH_SCALE_PCT` / the `e` command calibrates by ear.
- **`e`** prints the estimate for every word in the lyric; **`e<pct>`** (25–400) scales all estimates at runtime, so calibration doesn't need a reflash.
- A **dictionary miss** advances at once — nothing is sounding to wait for.
- **A note arriving while a word still sounds advances first**, because that note cuts the word off (§4.3). Verified in the simulator at 400, 120 and 40 ms spacing: words stay strictly consecutive, none repeated or skipped.

If the estimate ever proves too crude, wiring D1/Speaking to the spare shifter channel would replace it with the real thing.

### 4.7 Expression mapping

| Control | Target | Rationale |
|---|---|---|
| Note number | Pitch (22) | §4.1 |
| Pitch-bend strip | **Speed** (21) | Self-centring, suits a "deviate and return" rubato gesture |
| Mod strip | **Timbre/Bend** (23) | Holds position, suits set-and-leave |
| Velocity | Volume (20) | Plumbed, pinned to 96 |

- **Speed is asymmetric and needs per-direction scaling.** Default 114 is only 13 below max 127 but 114 above zero; a linear map would give negligible "rush" and enormous "drag". Up maps 114→127, down maps 114→`SJ_SPEED_MIN` (45).
- Higher Speed = faster. Confirmed.
- **Bend's full 0–15 range is usable** and far less extreme than the manual's "deep hollow to high metallic" suggests — a timbral tint, not a transformation. Boots at 5 (chip default); the first wheel movement takes over.
- **Both land on the *next* syllable, never the sounding one.** These parameters latch and can't change mid-phoneme. You aim rather than steer — a real difference from a conventional synth.

### 4.8 Real-time priority: audio and MIDI first

This shaped several decisions and is easy to violate by accident.

- **Nothing heavy runs in the MIDI callback.** ⚠️ `renderPlayView()` was originally called synchronously from `speakNext()` inside the note-on callback — a dictionary scan, a second scan for the miss check, a full redraw and a 1024-byte diff per note. **Notes were audibly swallowed.** The callback now only sets `displayDirty`.
- **Display refresh is lazy and incremental.** Rendering diffs against a shadow buffer to find changed *column spans* per page; `displayService()` flushes **at most one page per `loop()` iteration**, called last. A full 1024-byte refresh would block ~26 ms. Render and flush never share an iteration.
- **The keyboard driver returns at most one event per call** and touches I2C only when INT is asserted.
- **The TX path and the note log are both deferred to `loop()`** (7d). The callback does a dictionary lookup and a queue append, nothing else. Serial logging *anywhere* costs ~4 ms per 80-character line at 115200, which is why it stays off by default even now that it prints from `loop()`.
- **Serial line input is incremental** (7c): one character per pass, no busy-wait, so typing a lyric or a lookup no longer stops MIDI, the keyboard or the display.
- Loop order: **MIDI → drain TX queue → keyboard → serial input → playhead service → note log → display → top up TX queue.**

---

## 5. Gotchas

**Macro names in `extradict.h` must not match the sketch's constants.** The sketch declares `const uint8_t SJ_VOLUME/SJ_SPEED/SJ_PITCH/SJ_BEND` *after* including it, so a `#define` of the same name turns those into `const uint8_t 21 = 21;`. That's why the header's command macros are `SJ_CMD_*`.

**Arduino IDE auto-prototyping** generates a prototype for every function and inserts them all **just before the first function definition** in the sketch. So any type used in *any* function signature must be declared above that point. Keep `USING_NAMESPACE_*` next to the includes, write handler signatures as `midi::Channel`, and declare enums and structs used in signatures (`LineMode`, `NoteLog`) at the top of the file, where both now sit with a comment saying why. This bit twice: once when adding an include broke unchanged handlers, and once when 7c's `LineMode` was declared 800 lines below its use in a signature. `hostsim/arduino_proto.py` reproduces the insertion, and is validated in both directions — it produces the IDE's exact errors on the broken file and none on a file known to compile.

**`EZ_USB_MIDI_HOST` v2 API** — pre-2.0 sketches don't compile. Instances come from `RPPICOMIDI_EZ_USB_MIDI_HOST_INSTANCE(usbhMIDI, MidiHostSettingsDefault)`; `usbhMIDI.begin(&USBHost, 0, onConnect, onDisconnect)` calls `tuh_init()` internally (don't also call `USBHost.begin()`); per-type handlers (`setHandleNoteOn`) rather than `setHandleMessage`.

**`PIN_LED` is already a macro** in the `rpipico2` variant header — don't use it as a variable name.

**The KeyStep's arpeggiator** generates its own note stream from held keys. Notes appearing to "double" was this, not a firmware bug. Worth knowing as a feature: with the arp on, the instrument becomes a **step sequencer for lyrics** — hold a chord and it recites.

**Keyboard: clearing `INT_STAT` does not consume events.** With a non-empty queue INT re-asserts within ~2 ms, forever. Read `EVENT_NUM` → read that many events → *then* clear. See `tab5_keyboard_reference.md`.

---

## 6. Aesthetic notes — read before "improving" anything

**It feels awkward to play, and the awkwardness is inherent, not a defect.** It comes from the same constraints those reference records lean into: discrete syllabic events, no legato, no continuous bend, the instrument committing to a phoneme and not renegotiating mid-flight.

⚠️ **Do not engineer the awkwardness away.** If the dictionary layer, the display, or a future control tempts toward smoothing out the discrete, committed feel, that works against the instrument's character. This was liked, deliberately, on first contact.

Both expressive controls and the retrigger behaviour landed on the same verdict: works, requires getting used to, no objection. Two independent controls reaching that conclusion suggests a consistent instrument rather than an awkward one.

**A word that doesn't sound is a bug; a word that sounds odd is character.** This is the standard the dictionary work is held to, and it sets the priority plainly: coverage beats fidelity. A silent miss breaks the performance — the note arrives with nothing on it — while a slightly wrong vowel is just the instrument's accent. It is why 39% agreement with Sensory's tuning is a perfectly good result, why the CMU tier is searched last rather than tuned further, and why a letter-to-sound fallback (§3.3) is the most valuable dictionary work left: it would remove misses entirely.

The `fx*` sound effects in the dictionary are cheesy — they were built to demo a chip in 2005 — but they're just words to the tokeniser if a track ever wants one. Since the Reset fix, the ones without `\NT` notes (`fxrobotbede`, `fxcountdown`, `fxtest`…) follow the key and both strips, so they're playable rather than fixed samples.

---

## 7. Working method

Worth continuing, since it's what kept this moving:

- **One unknown per step.** Raw codes before the library, library before MIDI, MIDI before the display. When something failed, the cause was unambiguous.
- **Standalone diagnostic sketches** for each new peripheral (`06a`, `06`, `07a`, `07b`) before integrating. Cheap, and they isolate "wiring wrong" from "driver wrong".
- **Libraries are read for their data, not linked for their code.** The SpeakJet dictionary, the SH1106 driver, the Tab5 key-name table were all extracted rather than depended on. Each time, the library's own machinery would have fought the MIDI-first loop.
- **Decisions get recorded with the reasoning**, including reversals. The retrigger section exists in that form because the conclusion is re-derivable wrongly from the same starting evidence.
- **Measure instead of estimating.** Three plausible predictions were wrong: `fxcountdown`'s callback cost (estimated 25 ms, measured 35), the claim that the unqueued sender fell progressively behind (it doesn't — the FIFO bounds it), and the assumption that a g++ build proves the IDE will compile it. The simulator exists so these are cheap to check.
- **Validate a tool in both directions.** Every generator here is checked against known-good data before its output is trusted: `dic2extradict.py` regenerates all 1427 standard entries byte-for-byte, `arduino_proto.py` reproduces a real IDE error *and* passes a file known to compile, `cmu2bigdict.py` is cross-validated against words held out of training.
