# Wiring — MIDI Voice Box Synth

**Raspberry Pi Pico 2** (plain, *not* the W) · SparkFun Voice Box Shield (SpeakJet) · 4-ch level shifter · SH1106 OLED · M5Stack Tab5 Keyboard · Raspberry Pi Debug Probe

**Status: built and working on the bench.** Everything below is verified on hardware unless explicitly marked otherwise. Last revised 18 Sep. **Build finished and cased.**

---

## 1. GPIO assignment

| GPIO | Header pin | Function | Connects to | Level |
|---|---|---|---|---|
| GP0 | 1 | Debug UART TX (`Serial1`, UART0) | Debug Probe UART RX | 3V3 |
| GP1 | 2 | Debug UART RX (`Serial1`, UART0) | Debug Probe UART TX | 3V3 |
| GP2 | 4 | I2C1 SDA (`Wire1`) | SH1106 OLED @ 0x3C | 3V3 |
| GP3 | 5 | I2C1 SCL (`Wire1`) | SH1106 OLED | 3V3 |
| GP4 | 6 | SpeakJet UART TX (`Serial2`, UART1, 9600) | shifter ch1 → shield pin 2 | 3V3↔5V |
| GP5 | 7 | SpeakJet UART RX (`Serial2`, UART1) | shifter ch2 → shield pin 0 | 3V3↔5V |
| GP6 | 9 | SpeakJet RDY input | shifter ch3 → shield pin 13 | 3V3↔5V |
| GP7 | 10 | SpeakJet RES output (active low) | shifter ch4 → shield pin 3 | 3V3↔5V |
| GP8 | 11 | I2C0 SDA (`Wire`) | Tab5 Keyboard @ 0x6D, P1 pin 8 | 3V3 |
| GP9 | 12 | I2C0 SCL (`Wire`) | Tab5 Keyboard, P1 pin 7 | 3V3 |
| GP10 | 14 | Keyboard INT (input, idle high) | Tab5 Keyboard, P1 pin 9 | 3V3 |
| GP23 | — | SMPS power-save control | internal — **must be driven HIGH**, see §7.1 | — |
| GP25 | — | User LED | internal — MIDI-connected indicator | — |

**Free:** GP11–GP22, GP26–GP28. GP24 and GP29 are internal (VBUS sense, VSYS/3 ADC).

⚠️ **Counterintuitive bus naming.** The **keyboard is on `Wire`** (I2C0) and the **OLED is on `Wire1`** (I2C1). The OLED landed on I2C1 because I2C0's other candidate pins (GP0/GP1, GP4/GP5) were already taken by the debug UART and the SpeakJet.

**Two separate I2C buses, deliberately.** Addresses don't collide so one bus would work, but the OLED's page flushes are the long I2C operations here (~3 ms each) and the keyboard wants low-latency interrupt reads. Separating removes any contention question for the cost of two spare pins.

---

## 2. Level shifter (4-ch bidirectional, BSS138-style)

| Ch | LV (3V3, Pico) | HV (5V, shield) | Purpose |
|---|---|---|---|
| 1 | GP4 | Shield pin 2 | Pico → SpeakJet RX |
| 2 | GP5 | Shield pin 0 | **drives nothing — see below** |
| 3 | GP6 | Shield pin 13 | SpeakJet D0/Ready → Pico |
| 4 | GP7 | Shield pin 3 | Pico → SpeakJet RES |

- **LV** → Pico 3V3 (pin 36) · **HV** → 5V rail · **GND** → common star
- **Shifting is required, not precautionary.** The SpeakJet has no separate I/O rail; its output-high level is the supply voltage, and the shield runs it at 5V.
- **Speed is a non-issue** at 9600 baud (a bit is ~104 µs), despite these shifters' slow passive rise times.

✅ **Channel 2 is effectively spare.** Shield pin 0 is not a SpeakJet output — the SpeakJet is receive-only and has no serial transmit pin. See §6. If a future feature needs a shifted line (e.g. D1/Speaking on shield pin 4), this channel is available.

---

## 3. Power

As built (18 Sep): a **regulated step-down module inside the case** feeds the 5V rail. Its output was checked on a scope and is clean; the audio line out is clean with it. During development this was an official RPi 5.1V PSU through a USB receptacle — either works, the requirement is a solid 5V at the shield.

```
5V supply (regulated step-down module in the case; was an RPi 5.1V PSU on the bench)
   │
   ├── Pico VSYS (pin 39) ─┐
   ├── Pico VBUS (pin 40) ─┘ tied together — see warnings below
   ├── Shield 5V
   └── Level shifter HV
GND ── common star point (NOT daisy-chained)

Pico 3V3 (pin 36) ── Level shifter LV · OLED VCC · Tab5 Keyboard 3V3 (P1 pin 5)
```

⚠️ **VBUS must be driven externally.** In USB host mode the Pico is expected to *source* VBUS for downstream devices. Its internal Schottky runs VBUS→VSYS only and cannot back-feed the connector. Without a VBUS feed, nothing on the hub enumerates.

⚠️ **Never connect the Pico's micro-USB to a computer while this supply is live.** Tying VBUS to VSYS bypasses the diode that normally blocks back-feed. Worth labelling on the enclosure.

⚠️ **VSYS accepts 1.8–5.5 V only.** If an upstream 9–12 V supply is ever used, it goes into a regulator first — never to pin 39.

- **Star topology matters.** Shield and shifter tap the supply node directly. The shield's amp current must never flow through the Pico's VSYS pin and traces.
- The USB hub is **bus-powered**, so devices draw through VBUS from this rail.

---

## 4. I2C devices

| Device | Bus | Address | Notes |
|---|---|---|---|
| SH1106 OLED, 128×64 | I2C1 (`Wire1`) | 0x3C | **SH1106, confirmed** — column offset **2** (132-col RAM, 128-col panel). Driving it as an SSD1306 shifts everything 2 px and wraps edge columns. *Identical replacement fitted 17 Sep; the dead segment is gone.* |
| M5Stack Tab5 Keyboard | I2C0 (`Wire`) | 0x6D | 70 keys, STM32F030C8T6, 3.3V, 128 × 59.4 × 13.1 mm. Protocol in `tab5_keyboard_reference.md`. |

**Tab5 Keyboard P1 header** (2×5, 2.54 mm) — *confirmed against the PCB silkscreen*:

| Pin | Signal |
|---|---|
| 3, 4 | GND |
| 5 | 3V3 |
| 7 | SCL |
| 8 | SDA |
| 9 | INT |

**No I2C pull-ups fitted**, and none needed at bench cable length. ⚠️ If characters skip or arrive mangled — **especially once the keyboard is panel-mounted on a longer cable** — fit 4.7 kΩ from SDA and SCL to 3V3 before suspecting the driver.

**Neither I2C device needs level shifting.** Both are 3.3V parts sharing the Pico's logic level.

---

## 5. Audio output

**Shield signal path** (from the shield schematic):

```
SpeakJet V_OUT
  → 2-pole LP filter (R11/R12 28k, C4/C7 10nF) — NOT buffered, see §5.3
  → C5 1µF → IC1A inverting ×10 (R3 10k in, R2 100k ∥ C1 100pF fb)
  → R8 10k TRIMPOT          ← sits BETWEEN the gain stages
  → C6 1µF → IC1B inverting ×10 (R6 10k in, R5 100k ∥ C3 100pF fb)
  → C9 100µF → audio header JP3 + 3.5mm jack JP6

Each stage's + input is biased to VCC/2:
  IC1A: R9 10k to VCC, R4 10k to GND, C11 1µF to GND
  IC1B: R10 10k to VCC, R7 10k to GND, C10 1µF to GND   ← see §5.1
Op-amp supply decoupling: C2 0.1µF only.
```

*Values read from a schematic screenshot (15 Sep), not measured. Note the schematic uses the designator **R11 twice** — the 28k filter resistor and a 10k pull-up by the SpeakJet.*

**Op-amp part: unknown** — the schematic just says "OPAMP-DUALU". Read the marking. It mattered for setting the trimpot (§5.1): if it's an LM358-class part, its output can't swing near the 5 V rail, so clipping around the 2.5 V bias starts earlier than a rail-to-rail part would.

**It is not a power amp** — a dual op-amp with a 100 µF output cap, sized for headphones or a small speaker. Driving a line input is electrically fine but far too hot.

### 5.1 Noise floor — RESOLVED (18 Sep)

**✅ Fixed by the transformer (§5.2) plus the trimpot setting. With the instrument panel-mounted and the amp up, the line out is quiet.** Neither capacitor mod was needed; both are kept below as contingency, not as pending work. The trimpot was set the intended way: turned up until distortion appeared on loud syllables, then backed off.

**Symptom (as it was):** output very loud (trimpot nearly fully down), loud noise floor **largely unaffected by trimpot position**.

**Diagnosis:** the trimpot sits *between* the gain stages. Noise before it is attenuated with the signal; noise after it — in IC1B or on its supply — is not. **Pot-independence localises the noise to stage 2 or its VCC.** Op-amp PSRR is poor at high frequencies and this 5V rail is shared with the Pico and the switcher.

**Likely mechanism — the bias node (identified from the schematic, 16 Sep).** Each stage's + input sits at VCC/2 via a 10k/10k divider decoupled by only **1 µF**. That's a Thévenin 5k with 1 µF: a **32 Hz** corner. Supply noise reaches the bias node, and the stage then amplifies it by its noise gain, 1 + 100k/10k ≈ **×11 (+21 dB)**:

| Bias cap | Corner | VCC ripple at output, 100 Hz | at 1 kHz | Power-up settle (τ) |
|---|---|---|---|---|
| **1 µF (fitted)** | 32 Hz | **+4 dB** (amplified) | −15 dB | 5 ms |
| 10 µF | 3.2 Hz | −15 dB | −35 dB | 50 ms |
| 47 µF | 0.7 Hz | −29 dB | −49 dB | 235 ms |

IC1A's copy passes through the trimpot; **IC1B's (C10) does not** — exactly the pot-independent noise observed. *Modelled, not measured.*

**What actually fixed it:**

1. **The isolation transformer** (§5.2), which also removed the ground-loop path into the amp.
2. **Setting the trimpot as high as it goes without audible distortion on loud syllables** — turn up until distortion appears, then back off. This is where the SNR gain comes from. ⚠️ Not maximum: IC1B is ×10 on a single 5V rail and will clip, which is worse than hiss.

**If it ever returns** — a different amp, a different supply, a rebuild — try these in this order. ⚠️ Don't open a working instrument for an inaudible noise floor.

1. **Bulk decoupling at the shield's connector: 100 nF ceramic ‖ 220–470 µF electrolytic across VCC/GND, shortest possible leads.** Non-invasive, reversible, no rework. The shield carries only 10 µF + 0.1 µF, so this is where the easy gain is. It lowers the rail impedance *at the shield* and gives the audio stage a local reservoir instead of pulling current through the wiring. Helps most with noise that tracks display or LED activity; it does nothing for hiss, which is set by the gain stages and the trimpot position.
2. **10 µF across C10 (and C11)** — the bias-node fix modelled above. If the 0402 parts are too small to rework, the same node is the op-amp's + input pin: tack the electrolytic from **IC1B pin 5 to ground, + to the pin**. Electrically identical to paralleling C10. *(Check pin numbering against the board first.)*
3. **Clean the shield's VCC** — small LDO or RC filter feeding only the shield. Attacks the cause.
4. **Attenuate externally** to reach line level.

**Diagnose before soldering.** With a working line out, record ~30 s of silence and look at the spectrum: spikes at 50/100 Hz are hum (capacitors barely help; check grounding and the transformer), a peak in the tens of kHz is switcher noise (steps 1–3 help), a flat floor is hiss (nothing here helps — it's the gain structure).

### 5.2 Line output — Neutrik NTE 10/3 transformer

Chosen over a resistive divider only because one was on hand; it adds galvanic isolation if a ground loop ever appears.

- ⚠️ **It is a mic input STEP-UP transformer — run it BACKWARDS.** 1:3 (1:10 on the third tap), 200 Ω primary, 1.8k/20k secondary. Drive the high-impedance winding, take output from the 200 Ω primary.
- **Use the 1:10 tap:** −20 dB rather than −9.5 dB, and ten times the voltage headroom on the driven winding.
- ⚠️ **Saturation lands on the LOW notes.** Max input is specified at 50 Hz because saturation is a volts-per-hertz limit. Driving the 20k winding gives roughly 3.5 V at 50 Hz, ~1.7 V at 25 Hz. **This instrument's fundamentals are 33–240 Hz with the bottom key at 33 Hz**, and the shield's filter doesn't attenuate that end. **Test the bottom octave loud before settling the level.**
- **Take the feed after C9 (100 µF)** — DC through a winding saturates it outright.
- Datasheet wiring verified against the part: white/yellow = primary, blue/red/black = secondary with 3 and 10 taps. The 1:10 tap measures the higher DCR.
- **It does not fix the noise floor** — signal and noise attenuate equally.

### 5.3 Input filter — the real response

**The ≈570 Hz corner quoted previously is wrong.** It's the corner of a single 28k/10nF section. Here the two sections aren't buffered, and the second feeds R3 (10k) into IC1A's virtual ground through C5, which loads it. Modelling the whole network (ideal source and op-amp):

- **−3 dB ≈ 840 Hz**, **−10 dB at 2 kHz**, **−15 dB at 3 kHz** — right across the band that carries consonant clarity. This is a plausible cause of the muffled character.
- **The 28k + 28k into a 10k load costs ≈17 dB** of signal before IC1A, so stage 1's effective signal gain is ≈×1.5, not ×10. Its *noise* gain is still ×11.
- The feedback caps (100 pF ∥ 100k) add a pole at ≈16 kHz per stage — about −14 dB at 32 kHz for the pair.

| C4/C7 | −3 dB | at 2 kHz | at 3 kHz | 32 kHz carrier (incl. op-amp poles) |
|---|---|---|---|---|
| **10 nF (fitted)** | 840 Hz | −10 dB | −15 dB | −67 dB |
| **4.7 nF** | 1.8 kHz | −4 dB | −6.5 dB | −54 dB |
| 2.2 nF | 3.8 kHz | −1 dB | −2 dB | −42 dB |
| 1 nF | 8.4 kHz | 0 dB | −0.3 dB | −30 dB |

**Decided against (18 Sep): leave the filter as built.** The voice sounds right, and the stock 10 nF values put the 32 kHz carrier ≈67 dB down — the reason they are there. The options below stand only if the voice ever needs opening up.

**If it did: 4.7 nF** — doubles the bandwidth and still buries the carrier. Two SMD parts. *If V_OUT has significant output impedance it adds to R11 and lowers the corner further; unmeasured.*

---

## 6. Voice Box Shield reference

The shield schematic was located (15 Sep); earlier revisions of these docs wrongly stated none existed.

| Shield pin | Function | Status |
|---|---|---|
| 0 | JP2 jumper only — selects whether SpeakJet RX is fed from Arduino hardware TX or D2 | **Not a SpeakJet output.** The SpeakJet has no serial TX; it reports status solely via D0/D1/D2. |
| 2 | SpeakJet RX | In use |
| 3 | RES (active low) | In use |
| 4 | **D1/SPK — Speaking output** | Unused. *(Earlier docs called this a "Speak button" — wrong.)* |
| 5–12 | E0–E7 parallel event triggers | Unused (serial control only) |
| 13 | **D0/RDY — Ready** | In use, diagnostic only. Per the manual it signals *self-test passed / ready to accept data* — **not** buffer level, so it can't pace a sender |
| — | D2/BHF (Buffer Half Full) | **Not connected on this shield.** Hardware flow control unavailable. Moot for single words (≤56 codes fit the 64-byte buffer with the parameter block), but it's why the long `fx*` entries need a time-paced sender. |

**RES timing:** `LOW; delay(100); HIGH;` at boot — empirically proven, not just a datasheet minimum.

---

## 7. Build notes

### 7.1 GP23 — mandatory in every sketch

```cpp
pinMode(23, OUTPUT);
digitalWrite(23, HIGH);   // SMPS → PWM mode, low ripple
```

Without it the Pico's onboard SMPS runs in PFM mode, pulse-skipping irregularly at light load, and puts an **audible noise floor into the SpeakJet output**. Confirmed by removing an LED-synchronous noise floor *with the LED still running* — a real fix to rail behaviour, not just removal of one aggravating load. Costs light-load efficiency; irrelevant on a mains-powered desktop instrument. **Only possible because this is a non-W Pico 2** (GP23 is WL_ON on a W).

### 7.2 Grounding

All grounds common, **star not daisy-chain**: Pico, shifter, shield, OLED, keyboard each back to one point. Mismatched ground causes erratic level-shifter behaviour, and shared return paths put load current into the audio reference.

### 7.3 Enclosure

- **Trimpot access.** R8 is on the shield and was set against two competing constraints (§5.1 noise vs §5.2 saturation), and may need resetting if the amp changes. Leave an access hole.
- **Keyboard sets the width** at 128 mm. Two M3 holes on the back.
- **Debug Probe leads** should stay reachable.
- **Keep the shield's analog section away from the regulator**, and give the audio output its own short ground run to the star point.

### 7.4 Toolchain

- Board: **"Raspberry Pi Pico 2"**, not the W. Core: `arduino-pico` (earlephilhower).
- USB Stack: **"Adafruit TinyUSB Host (native)"** for any sketch using MIDI.
- **Two serial devices appear.** The Pico's own CDC is labelled "Raspberry Pi Pico 2" in the port list; the **Debug Probe's UART bridge is the other one**, and that's where `Serial1` comes out.
- **Set the IDE Port to the Pico's CDC** so SWD upload's 1200-baud touch resolves, and read debug separately: `screen /dev/cu.usbmodemXXXX 115200`. Arduino 2.x's monitor is unreliable at reclaiming ports after a reset.
- In host mode the Pico's CDC disappears; use BOOTSEL/UF2 if SWD upload complains.
- Explicit `setTX()`/`setRX()` on both UARTs avoids all `Serial1`/`Serial2` naming ambiguity.

---

## 8. Superseded — recorded so they aren't re-proposed

| Decision | Why it changed |
|---|---|
| Pico 2 **W** | No wireless used; the non-W frees GP23 for the SMPS fix and GP25 as a plain LED. No pin assignments changed. |
| Olimex USB-NeoHub | Available in USB-C only. A generic €3 OTG hub was substituted and has worked from the first MIDI test. Olimex remains the fallback. |
| Self-powered hub | The hub in use is bus-powered. Fine for one device; watch power if more are added. |
| Swap RDY → D1/Speaking on ch3 | Only needed for a "drop" retrigger scheme that was reversed. Channel stays as wired; pin 4 carries D1 if ever needed. |
| USB HID keyboard | Replaced by the I2C Tab5 Keyboard — better physically *and* simpler firmware, and it removed the last unproven architectural risk (two devices behind the hub). |
| "No spare shifter channels" | Never true — channel 2 drives nothing. |
| Input filter corner ≈570 Hz | Single-section figure. The loaded 2-pole network is ≈840 Hz and much steeper above it. §5.3. |
| "Clean VCC" as the first noise fix | Superseded twice: the bias-node cap was to be the cheap diagnostic, and in the end neither was needed — transformer + trimpot fixed it (§5.1). |
| 9–12 V input + switching regulator | Not currently in use; a 5.1 V USB supply feeds the rail directly. The regulator remains an untested noise source if reintroduced. |
