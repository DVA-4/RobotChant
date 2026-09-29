// extradict.h — add your own words here.
//
// Searched BEFORE the 1427-word standard dictionary, so an entry here also
// overrides a standard pronunciation you don't like. standardDict.cpp stays
// untouched, which keeps it a clean unmodified copy of the library's data.
//
// CONTENTS
//   1. Hand-derived starter words (rhyme + onset swap)
//   2. Entries McCauley's converter DROPPED from PhraseALator.Dic: contractions
//      and "yoyo" (it skipped any key with a non-letter character)
//   3. Corrected overrides for the 9 fx* entries that ARE in standardDict.cpp
//      (they carry the RESET = 30 bug)
//   4. The remaining fx* entries the converter dropped (multi-word, notes, DTMF)
//   5. Long fx* entries, disabled by default -- see EXTRADICT_LONG_FX
//
// Sections 2-5 are GENERATED from PhraseALator.Dic by a translator that follows
// the original Phrase-A-Lator's rules (benbaker76/PhraseALator, SpeakJet.cs) and
// was validated by regenerating all 1427 standardDict.cpp entries byte-for-byte:
// the only differences were the nine \RESET codes. Rules, for hand-editing:
//   \TOKEN      -> its code          \123     -> the byte 123
//   \NTC2 etc.  -> Pitch + fixed Hz   word      -> that word's codes, recursively
//   ,          -> \P2 each           2 spaces  -> \P6     3+ spaces -> \P4 \P1
//
// ---------------------------------------------------------------------------
// HOW TO ADD A WORD
// ---------------------------------------------------------------------------
// 1. Find a RHYME that's already in the dictionary and steal its phonemes.
//    This is far more reliable than deriving from scratch. Use the '?' menu
//    command to see any existing word's codes, or read PhraseALator.Dic, which
//    is human-readable: e.g.  none = \NO \SLOW \UX \NE
// 2. Swap the onset consonant. "done" is "none" with NO -> DO.
// 3. Add a line to EXTRA_DICT below. Terminate the codes with SJ_END.
// 4. Listen, adjust. There's no correct answer, only what sounds right.
//
// Consonants come in -E and -O variants (DE/DO, SE/SO, LE/LO...). Roughly:
// use the -E form before front vowels (IY, IH, EY, EH, AY) and the -O form
// before back vowels (OH, AW, OW, UH, UW, UX). Trust your ear over the rule.
//
// SJ_FAST/SJ_SLOW/SJ_STRESS/SJ_RELAX modify only the NEXT phoneme. The stock
// dictionary uses them heavily — they're what stops words sounding flat.
//
// ⚠️ An argument byte must never be 255 -- it would read as SJ_END.

#ifndef EXTRADICT_H
#define EXTRADICT_H

#include "dict.h"

// Section 5 switch. Leave at 0 until the sketch has a paced sender -- see there.
#ifndef EXTRADICT_LONG_FX
#define EXTRADICT_LONG_FX 0
#endif

// --- modifiers (affect the next phoneme only) ---
#define SJ_PAUSE0   0     // 0 ms
#define SJ_PAUSE1   1     // 100 ms
#define SJ_PAUSE2   2     // 200 ms
#define SJ_PAUSE3   3     // 700 ms
#define SJ_PAUSE4   4     // 30 ms
#define SJ_PAUSE5   5     // 60 ms
#define SJ_PAUSE6   6     // 90 ms
#define SJ_FAST     7     // next phoneme at 0.5x duration
#define SJ_SLOW     8     // next phoneme at 1.5x duration
#define SJ_STRESS   14
#define SJ_RELAX    15
#define SJ_WAIT     16    // stops and waits for an SCP start -- never use in a word
#define SJ_SOFT     18    // Phrase-A-Lator \SOFT; undocumented in the manual, used before B
#define SJ_END      255   // end-of-entry sentinel, never transmitted

// --- commands that take ONE argument byte (Table D) ---
// Named SJ_CMD_* because the sketch already declares SJ_VOLUME/SJ_SPEED/SJ_PITCH/
// SJ_BEND as constants after this header is included; a #define of the same name
// would break those declarations.
#define SJ_CMD_VOLUME 20
#define SJ_CMD_SPEED  21
#define SJ_CMD_PITCH  22    // argument is Hz
#define SJ_CMD_BEND   23
#define SJ_CMD_REPEAT 26    // repeat the NEXT code n times
#define SJ_CMD_DELAY  30    // n x 10 ms
#define SJ_CMD_RESET  31    // no argument. NB: McCauley's converter emitted 30 (Delay)
                            // for \RESET -- see the fx section below.
// --- vowels ---
#define SJ_IY    128
#define SJ_IH    129
#define SJ_EY    130
#define SJ_EH    131
#define SJ_AY    132
#define SJ_AX    133
#define SJ_UX    134
#define SJ_OH    135
#define SJ_AW    136
#define SJ_OW    137
#define SJ_UH    138
#define SJ_UW    139
// --- nasals / resonants ---
#define SJ_MM    140
#define SJ_NE    141
#define SJ_NO    142
#define SJ_NGE   143
#define SJ_NGO   144
#define SJ_LE    145
#define SJ_LO    146
#define SJ_WW    147
#define SJ_RR    148    // NB: McCauley's SpeakJet.h says 149 (collides with IYRR). Manual: 148.
// --- r-coloured vowels ---
#define SJ_IYRR  149
#define SJ_EYRR  150
#define SJ_AXRR  151
#define SJ_AWRR  152
#define SJ_OWRR  153
// --- diphthongs ---
#define SJ_EYIY  154
#define SJ_OHIY  155
#define SJ_OWIY  156
#define SJ_OHIH  157
#define SJ_IYEH  158
#define SJ_EHLE  159
#define SJ_IYUW  160
#define SJ_AXUW  161
#define SJ_IHWW  162
#define SJ_AYWW  163
#define SJ_OWWW  164
// --- voiced consonants ---
#define SJ_JH    165
#define SJ_VV    166
#define SJ_ZZ    167
#define SJ_ZH    168
#define SJ_DH    169
#define SJ_BE    170
#define SJ_BO    171
#define SJ_EB    172
#define SJ_OB    173
#define SJ_DE    174
#define SJ_DO    175    // NB: McCauley's SpeakJet.h says 174 (collides with DE). Manual: 175.
#define SJ_ED    176
#define SJ_OD    177
#define SJ_GE    178
#define SJ_GO    179
#define SJ_EG    180
#define SJ_OG    181
// --- voiceless consonants ---
#define SJ_CH    182
#define SJ_HE    183
#define SJ_HO    184
#define SJ_WH    185
#define SJ_FF    186
#define SJ_SE    187
#define SJ_SO    188
#define SJ_SH    189
#define SJ_TH    190
#define SJ_TT    191
#define SJ_TU    192
#define SJ_TS    193
#define SJ_KE    194
#define SJ_KO    195
#define SJ_EK    196
#define SJ_OK    197
#define SJ_PE    198
#define SJ_PO    199
// --- sound effects 200..254 ---
// robot
#define SJ_R0 200
#define SJ_R1 201
#define SJ_R2 202
#define SJ_R3 203
#define SJ_R4 204
#define SJ_R5 205
#define SJ_R6 206
#define SJ_R7 207
#define SJ_R8 208
#define SJ_R9 209
// alarm
#define SJ_A0 210
#define SJ_A1 211
#define SJ_A2 212
#define SJ_A3 213
#define SJ_A4 214
#define SJ_A5 215
#define SJ_A6 216
#define SJ_A7 217
#define SJ_A8 218
#define SJ_A9 219
// beeps
#define SJ_B0 220
#define SJ_B1 221
#define SJ_B2 222
#define SJ_B3 223
#define SJ_B4 224
#define SJ_B5 225
#define SJ_B6 226
#define SJ_B7 227
#define SJ_B8 228
#define SJ_B9 229
// biological
#define SJ_C0 230
#define SJ_C1 231
#define SJ_C2 232
#define SJ_C3 233
#define SJ_C4 234
#define SJ_C5 235
#define SJ_C6 236
#define SJ_C7 237
#define SJ_C8 238
#define SJ_C9 239
// DTMF: D0..D9 = digits, D10 = *, D11 = #
#define SJ_D0 240
#define SJ_D1 241
#define SJ_D2 242
#define SJ_D3 243
#define SJ_D4 244
#define SJ_D5 245
#define SJ_D6 246
#define SJ_D7 247
#define SJ_D8 248
#define SJ_D9 249
#define SJ_D10 250
#define SJ_D11 251
// miscellaneous
#define SJ_M0 252   // sonar ping
#define SJ_M1 253   // pistol shot
#define SJ_M2 254   // "wow"

// ===========================================================================
// YOUR WORDS — starter set of common words the standard dictionary lacks.
// Each is derived from a rhyme that IS in the standard dictionary; the source
// is noted so you can hear what it was modelled on and judge the result.
// All 24 checked by ear and sounded right first time (15 Sep).
// ===========================================================================

static const uint8_t xd_done[]  = { SJ_DO, SJ_SLOW, SJ_UX, SJ_NE, SJ_END };
                                  // from: none = NO SLOW UX NE
static const uint8_t xd_gone[]  = { SJ_GO, SJ_SLOW, SJ_AW, SJ_NE, SJ_END };
                                  // from: on/long vowel; compare all = SLOW AW SLOW LO
static const uint8_t xd_been[]  = { SJ_BE, SJ_IH, SJ_NE, SJ_END };
static const uint8_t xd_said[]  = { SJ_SE, SJ_EH, SJ_ED, SJ_END };
static const uint8_t xd_were[]  = { SJ_WW, SJ_AXRR, SJ_END };
static const uint8_t xd_has[]   = { SJ_HE, SJ_AY, SJ_ZZ, SJ_END };
static const uint8_t xd_had[]   = { SJ_HE, SJ_AY, SJ_ED, SJ_END };
static const uint8_t xd_did[]   = { SJ_DE, SJ_IH, SJ_ED, SJ_END };
static const uint8_t xd_seen[]  = { SJ_SE, SJ_FAST, SJ_IY, SJ_NE, SJ_END };
static const uint8_t xd_lost[]  = { SJ_LO, SJ_AW, SJ_SE, SJ_TT, SJ_END };
static const uint8_t xd_found[] = { SJ_FF, SJ_AYWW, SJ_NE, SJ_ED, SJ_END };
static const uint8_t xd_real[]  = { SJ_RR, SJ_IYRR, SJ_EHLE, SJ_END };
static const uint8_t xd_true[]  = { SJ_TU, SJ_FAST, SJ_RR, SJ_IHWW, SJ_END };
static const uint8_t xd_false[] = { SJ_FF, SJ_AW, SJ_LE, SJ_SE, SJ_END };
static const uint8_t xd_dream[] = { SJ_DE, SJ_FAST, SJ_RR, SJ_IY, SJ_MM, SJ_END };
static const uint8_t xd_wake[]  = { SJ_WW, SJ_EYIY, SJ_OK, SJ_END };
static const uint8_t xd_dead[]  = { SJ_DE, SJ_EH, SJ_ED, SJ_END };
static const uint8_t xd_body[]  = { SJ_BO, SJ_OH, SJ_DE, SJ_IY, SJ_END };
static const uint8_t xd_soul[]  = { SJ_SO, SJ_OWWW, SJ_LO, SJ_END };
static const uint8_t xd_hate[]  = { SJ_HE, SJ_EYIY, SJ_TT, SJ_END };
static const uint8_t xd_hope[]  = { SJ_HO, SJ_OWWW, SJ_PO, SJ_END };
static const uint8_t xd_later[] = { SJ_LE, SJ_EYIY, SJ_TT, SJ_FAST, SJ_AXRR, SJ_END };
static const uint8_t xd_felt[]  = { SJ_FF, SJ_EH, SJ_LE, SJ_TT, SJ_END };
static const uint8_t xd_kept[]  = { SJ_KE, SJ_EH, SJ_PE, SJ_TT, SJ_END };

// ===========================================================================
// 2. DROPPED BY THE CONVERTER — Sensory's own pronunciations, not derived.
// The apostrophe is not a token break, so "can't" typed on the keyboard matches.
// ===========================================================================

// can't=\KE \AY \NE \P4 \TT
static const uint8_t xd_cant[] = {  // 5 codes
  SJ_KE, SJ_AY, SJ_NE, SJ_PAUSE4, SJ_TT,
  SJ_END };

// o'clock=\OW \P4 \KO \LO \OH \OK
static const uint8_t xd_oclock[] = {  // 6 codes
  SJ_OW, SJ_PAUSE4, SJ_KO, SJ_LO, SJ_OH, SJ_OK,
  SJ_END };

// shouldn't=\SH \SLOW \UW \SLOW \DO \NO \TT
static const uint8_t xd_shouldnt[] = {  // 7 codes
  SJ_SH, SJ_SLOW, SJ_UW, SJ_SLOW, SJ_DO, SJ_NO, SJ_TT,
  SJ_END };

// that's=\DH \SLOW \AY \SLOW \TS
static const uint8_t xd_thats[] = {  // 5 codes
  SJ_DH, SJ_SLOW, SJ_AY, SJ_SLOW, SJ_TS,
  SJ_END };

// they're=\SLOW \DH \EYRR
static const uint8_t xd_theyre[] = {  // 3 codes
  SJ_SLOW, SJ_DH, SJ_EYRR,
  SJ_END };

// yo-yo=\IY \OWWW \IY \OWWW
// Stored as "yoyo": the tokeniser splits on hyphens, so "yo-yo" can never match. (x-ray needs no
// entry: "xray" is already in the standard dictionary.)
static const uint8_t xd_yoyo[] = {  // 4 codes
  SJ_IY, SJ_OWWW, SJ_IY, SJ_OWWW,
  SJ_END };


// ===========================================================================
// 3. fx OVERRIDES — the RESET bug
// ---------------------------------------------------------------------------
// Phrase-A-Lator defines \RESET as 31 (Reset Defaults). McCauley's converter
// emitted 30, which is Delay-with-argument, so in standardDict.cpp every one
// of these swallows the byte after its leading "reset" and ends on a Delay
// still waiting for its argument -- which becomes the first byte of the NEXT
// note.
//
// The fix here DROPS the Resets rather than correcting them to 31:
//   - A leading Reset would wipe the parameter block sent just before the
//     codes, so the effect would ignore the key's pitch and the Speed/Bend
//     controls.
//   - A trailing Reset is redundant: every note re-sends Volume, Pitch, Speed
//     and Bend, so anything an effect latches is undone on the next note.
// Consequence: effects now start from the performer's current state instead
// of the chip's defaults. To hear Sensory's original behaviour, put
// SJ_CMD_RESET back as the first code.
// ===========================================================================

// fxalarm=\RESET \REPEAT \3 \A7 \REPEAT \3 \A6 \REPEAT \3 \A4 \REPEAT \3 \A3 \A1 \REPEAT \3 \A0 \RESET
static const uint8_t xd_fxalarm[] = {  // 16 codes
  SJ_CMD_REPEAT, 3, SJ_A7, SJ_CMD_REPEAT, 3, SJ_A6, SJ_CMD_REPEAT, 3, SJ_A4, SJ_CMD_REPEAT, 3,
  SJ_A3, SJ_A1, SJ_CMD_REPEAT, 3, SJ_A0,
  SJ_END };

// fxburningfusewithbang=\RESET \SPEED \114 \CH \P1 \CH \P1 \CH \SPEED \0 \REPEAT \6 \SH \SE \M1 \RESET
static const uint8_t xd_fxburningfusewithbang[] = {  // 14 codes
  SJ_CMD_SPEED, 114, SJ_CH, SJ_PAUSE1, SJ_CH, SJ_PAUSE1, SJ_CH, SJ_CMD_SPEED, 0, SJ_CMD_REPEAT, 6,
  SJ_SH, SJ_SE, SJ_M1,
  SJ_END };

// fxping=\RESET \SPEED \50 \BEND \0 \M0 \M0 \M0 \RESET
static const uint8_t xd_fxping[] = {  // 7 codes
  SJ_CMD_SPEED, 50, SJ_CMD_BEND, 0, SJ_M0, SJ_M0, SJ_M0,
  SJ_END };

// fxrobotbede = ... (105 chars, see PhraseALator.Dic)
static const uint8_t xd_fxrobotbede[] = {  // 22 codes
  SJ_CMD_SPEED, 127, SJ_BE, SJ_IY, SJ_DE, SJ_IY, SJ_BE, SJ_IY, SJ_DE, SJ_IY, SJ_BE, SJ_IY, SJ_DE,
  SJ_IY, SJ_BE, SJ_IY, SJ_DE, SJ_IY, SJ_BE, SJ_IY, SJ_DE, SJ_IY,
  SJ_END };

// fxrobotdroid = ... (102 chars, see PhraseALator.Dic)
static const uint8_t xd_fxrobotdroid[] = {  // 24 codes
  SJ_B3, SJ_PAUSE4, SJ_B2, SJ_PAUSE5, SJ_R7, SJ_R0, SJ_R7, SJ_R2, SJ_R7, SJ_R4, SJ_R7, SJ_R6, SJ_R8,
  SJ_R3, SJ_R3, SJ_R3, SJ_PAUSE4, SJ_B6, SJ_PAUSE4, SJ_B6, SJ_PAUSE4, SJ_C8, SJ_PAUSE4, SJ_C9,
  SJ_END };

// fxrobotsad=\Reset \BEND \0 \SPEED \61 \B8 \P1 \B3 \B0 \P1 \C9 \P1 \Reset
static const uint8_t xd_fxrobotsad[] = {  // 11 codes
  SJ_CMD_BEND, 0, SJ_CMD_SPEED, 61, SJ_B8, SJ_PAUSE1, SJ_B3, SJ_B0, SJ_PAUSE1, SJ_C9, SJ_PAUSE1,
  SJ_END };

// fxstatus1=\RESET \B6 \P3 \B6 \P3 \B6 \P3 \B7 \B0 \RESET
static const uint8_t xd_fxstatus1[] = {  // 8 codes
  SJ_B6, SJ_PAUSE3, SJ_B6, SJ_PAUSE3, SJ_B6, SJ_PAUSE3, SJ_B7, SJ_B0,
  SJ_END };

// fxstatus2=\Reset \B0 \P2 \B0 \P2 \B0 \P2 \B6 \P2 \B0 \P2 \B6
static const uint8_t xd_fxstatus2[] = {  // 11 codes
  SJ_B0, SJ_PAUSE2, SJ_B0, SJ_PAUSE2, SJ_B0, SJ_PAUSE2, SJ_B6, SJ_PAUSE2, SJ_B0, SJ_PAUSE2, SJ_B6,
  SJ_END };

// fxufo=\RESET \REPEAT \5 \A5
static const uint8_t xd_fxufo[] = {  // 3 codes
  SJ_CMD_REPEAT, 5, SJ_A5,
  SJ_END };


// ===========================================================================
// 4. fx ENTRIES THE CONVERTER DROPPED (fit the 56-code budget)
// ---------------------------------------------------------------------------
// Budget: SpeakJet input buffer 64 bytes - 8-byte parameter block = 56 codes.
// Resets dropped, as in section 3. Entries with NT note commands play their own
// pitches and ignore the key; the rest follow it.
// ⚠️ Anything over ~24 codes also exceeds the RP2350's 32-byte UART FIFO, so
// Serial2.write() blocks inside the note-on callback for ~1 ms per excess byte.
// ===========================================================================

// fxberzerkchickenfightlikearobot=\SPEED \120 \BEND \4 \NTA1 chicken,, fight  like  a  robot \Reset
static const uint8_t xd_fxberzerkchickenfightlikearobot[] = {  // 39 codes
  SJ_CMD_SPEED, 120, SJ_CMD_BEND, 4, SJ_CMD_PITCH, 55 /*A1*/,
  /* chicken */ SJ_CH, SJ_IH, SJ_KE, SJ_EH, SJ_NE, SJ_PAUSE2, SJ_PAUSE2,
  /* fight */ SJ_SLOW, SJ_FF, SJ_FAST, SJ_OHIY, SJ_PAUSE4, SJ_TT, SJ_PAUSE6,
  /* like */ SJ_LE, SJ_FAST, SJ_OH, SJ_FAST, SJ_OHIY, SJ_EK, SJ_PAUSE6,
  /* a */ SJ_EYIY, SJ_IY, SJ_PAUSE6,
  /* robot */ SJ_RR, SJ_FAST, SJ_OW, SJ_FAST, SJ_OWWW, SJ_SOFT, SJ_BO, SJ_OH, SJ_TT,
  SJ_END };

// fxberzerkthehumaniodmustnotescape=\SPEED \120 \BEND \10 \NTA1 thu    humaniod    must    not    escape \RESET
static const uint8_t xd_fxberzerkthehumaniodmustnotescape[] = {  // 44 codes
  SJ_CMD_SPEED, 120, SJ_CMD_BEND, 10, SJ_CMD_PITCH, 55 /*A1*/,
  /* thu */ SJ_SLOW, SJ_DH, SJ_SLOW, SJ_UX, SJ_PAUSE4, SJ_PAUSE1,
  /* humaniod */ SJ_HO, SJ_FAST, SJ_IYUW, SJ_MM, SJ_UX, SJ_FAST, SJ_NO, SJ_FAST, SJ_OW, SJ_FAST,
                 SJ_OWIY, SJ_ED, SJ_PAUSE4, SJ_PAUSE1,
  /* must */ SJ_MM, SJ_UX, SJ_SE, SJ_TT, SJ_PAUSE4, SJ_PAUSE1,
  /* not */ SJ_NE, SJ_OH, SJ_TT, SJ_PAUSE4, SJ_PAUSE1,
  /* escape */ SJ_EH, SJ_SE, SJ_KE, SJ_FAST, SJ_EYIY, SJ_PAUSE4, SJ_PE,
  SJ_END };

// fxburp=\Reset \SPEED \74 \BEND \0 \NTC1 \AXRR \SPEED \0 \P0
static const uint8_t xd_fxburp[] = {  // 10 codes
  SJ_CMD_SPEED, 74, SJ_CMD_BEND, 0, SJ_CMD_PITCH, 33 /*C1*/, SJ_AXRR, SJ_CMD_SPEED, 0, SJ_PAUSE0,
  SJ_END };

// fxcountdown=\RESET ten \P3 nine \P3 eight \P3 seven \P3 six \P3 five \P3 four \P3 three \P3 two \P3 one
static const uint8_t xd_fxcountdown[] = {  // 54 codes
  /* ten */ SJ_TT, SJ_EH, SJ_EH, SJ_NE, SJ_PAUSE3,
  /* nine */ SJ_NE, SJ_STRESS, SJ_OHIH, SJ_NE, SJ_PAUSE3,
  /* eight */ SJ_EYIY, SJ_PAUSE4, SJ_TT, SJ_PAUSE3,
  /* seven */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_EH, SJ_VV, SJ_EH, SJ_NE, SJ_PAUSE3,
  /* six */ SJ_SLOW, SJ_SE, SJ_IH, SJ_STRESS, SJ_KE, SJ_FAST, SJ_SE, SJ_PAUSE3,
  /* five */ SJ_FF, SJ_OHIH, SJ_VV, SJ_PAUSE3,
  /* four */ SJ_FF, SJ_FAST, SJ_OW, SJ_OWRR, SJ_PAUSE3,
  /* three */ SJ_SLOW, SJ_TH, SJ_RR, SJ_SLOW, SJ_IY, SJ_PAUSE3,
  /* two */ SJ_SLOW, SJ_TT, SJ_IHWW, SJ_PAUSE3,
  /* one */ SJ_WW, SJ_STRESS, SJ_OH, SJ_SLOW, SJ_NE,
  SJ_END };

// fxcrickets = ... (110 chars, see PhraseALator.Dic)
static const uint8_t xd_fxcrickets[] = {  // 24 codes
  SJ_C3, SJ_PAUSE4, SJ_C3, SJ_PAUSE3, SJ_CMD_PITCH, 65 /*C2*/, SJ_C3, SJ_PAUSE6, SJ_C3, SJ_PAUSE2,
  SJ_C3, SJ_PAUSE6, SJ_C3, SJ_PAUSE2, SJ_CMD_BEND, 14, SJ_CMD_PITCH, 147 /*D3*/, SJ_CMD_SPEED, 90,
  SJ_C3, SJ_PAUSE2, SJ_C3, SJ_PAUSE4,
  SJ_END };

// fxdanger=\RESET \NTA#2 \BEND \1 \A5 \P5 danger \P5 \A5 \P5 danger \P5 \A5 \P5 danger \RESET
// INTENT FIX: the original tool strips "#" from words, so \NTA#2 would have played A2 (110 Hz).
// A#2 (117 Hz) as written is used here.
static const uint8_t xd_fxdanger[] = {  // 36 codes
  SJ_CMD_PITCH, 117 /*A#2*/, SJ_CMD_BEND, 1, SJ_A5, SJ_PAUSE5,
  /* danger */ SJ_DE, SJ_EYIY, SJ_FAST, SJ_NE, SJ_FAST, SJ_JH, SJ_FAST, SJ_AXRR, SJ_PAUSE5, SJ_A5,
               SJ_PAUSE5,
  /* danger */ SJ_DE, SJ_EYIY, SJ_FAST, SJ_NE, SJ_FAST, SJ_JH, SJ_FAST, SJ_AXRR, SJ_PAUSE5, SJ_A5,
               SJ_PAUSE5,
  /* danger */ SJ_DE, SJ_EYIY, SJ_FAST, SJ_NE, SJ_FAST, SJ_JH, SJ_FAST, SJ_AXRR,
  SJ_END };

// fxrobotbeeps=\R2 \A4 \C6 \C1 \D5 \R3 \B4 \B2
static const uint8_t xd_fxrobotbeeps[] = {  // 8 codes
  SJ_R2, SJ_A4, SJ_C6, SJ_C1, SJ_D5, SJ_R3, SJ_B4, SJ_B2,
  SJ_END };

// fxsongironman = ... (205 chars, see PhraseALator.Dic)
static const uint8_t xd_fxsongironman[] = {  // 40 codes
  SJ_CMD_BEND, 2, SJ_CMD_SPEED, 72, SJ_CMD_PITCH, 55 /*A1*/, SJ_OHIH, SJ_IH, SJ_CMD_DELAY, 23,
  SJ_CMD_SPEED, 68, SJ_CMD_PITCH, 65 /*C2*/, SJ_AY, SJ_FAST, SJ_AY, SJ_MM, SJ_CMD_DELAY, 25,
  SJ_FAST, SJ_OHIH, SJ_IH, SJ_FAST, SJ_CMD_PITCH, 73 /*D2*/, SJ_AX, SJ_CMD_SPEED, 90, SJ_RR,
  SJ_FAST, SJ_NO, SJ_FAST, SJ_STRESS, SJ_MM, SJ_AY, SJ_FAST, SJ_AY, SJ_SLOW, SJ_NE,
  SJ_END };

// fxsongscales=\RESET \NTC2 doe  \NTD2 ray  \NTE2 me  \NTF2 fah  \NTG2 so  \NTA2 la  \NTB2 tee  \NTC3 doe \RESET
static const uint8_t xd_fxsongscales[] = {  // 48 codes
  SJ_CMD_PITCH, 65 /*C2*/,
  /* doe */ SJ_DO, SJ_OWWW, SJ_PAUSE6, SJ_CMD_PITCH, 73 /*D2*/,
  /* ray */ SJ_RR, SJ_RR, SJ_EYIY, SJ_PAUSE6, SJ_CMD_PITCH, 82 /*E2*/,
  /* me */ SJ_MM, SJ_IY, SJ_IY, SJ_PAUSE6, SJ_CMD_PITCH, 87 /*F2*/,
  /* fah */ SJ_FF, SJ_OH, SJ_OH, SJ_PAUSE6, SJ_CMD_PITCH, 98 /*G2*/,
  /* so */ SJ_SLOW, SJ_SO, SJ_FAST, SJ_OWWW, SJ_FAST, SJ_WW, SJ_PAUSE6, SJ_CMD_PITCH, 110 /*A2*/,
  /* la */ SJ_LO, SJ_OH, SJ_OH, SJ_PAUSE6, SJ_CMD_PITCH, 123 /*B2*/,
  /* tee */ SJ_TU, SJ_IY, SJ_IY, SJ_PAUSE6, SJ_CMD_PITCH, 131 /*C3*/,
  /* doe */ SJ_DO, SJ_OWWW,
  SJ_END };

// fxsongstar = ... (175 chars, see PhraseALator.Dic)
static const uint8_t xd_fxsongstar[] = {  // 39 codes
  SJ_CMD_PITCH, 98 /*G2*/, SJ_DE, SJ_CMD_REPEAT, 6, SJ_IY, SJ_CMD_PITCH, 82 /*E2*/, SJ_DO,
  SJ_CMD_REPEAT, 2, SJ_UX, SJ_CMD_PITCH, 65 /*C2*/, SJ_DO, SJ_CMD_REPEAT, 8, SJ_UW, SJ_CMD_PITCH, 82
  /*E2*/, SJ_DO, SJ_CMD_REPEAT, 8, SJ_UX, SJ_CMD_PITCH, 98 /*G2*/, SJ_DO, SJ_CMD_REPEAT, 8, SJ_IY,
  SJ_CMD_PITCH, 131 /*C3*/, SJ_DO, SJ_CMD_REPEAT, 8, SJ_UX, SJ_MM, SJ_MM, SJ_PAUSE0,
  SJ_END };

// fxtest=\Reset testing,, testing,, one two three
static const uint8_t xd_fxtest[] = {  // 31 codes
  /* testing */ SJ_TT, SJ_EH, SJ_SLOW, SJ_SE, SJ_TT, SJ_IH, SJ_NGE, SJ_PAUSE2, SJ_PAUSE2,
  /* testing */ SJ_TT, SJ_EH, SJ_SLOW, SJ_SE, SJ_TT, SJ_IH, SJ_NGE, SJ_PAUSE2, SJ_PAUSE2,
  /* one */ SJ_WW, SJ_STRESS, SJ_OH, SJ_SLOW, SJ_NE,
  /* two */ SJ_SLOW, SJ_TT, SJ_IHWW,
  /* three */ SJ_SLOW, SJ_TH, SJ_RR, SJ_SLOW, SJ_IY,
  SJ_END };


// ===========================================================================
// 5. LONG fx ENTRIES — disabled unless EXTRADICT_LONG_FX is 1
// ---------------------------------------------------------------------------
// These exceed the 56-code budget. Sent in one burst they overflow the
// SpeakJet's 64-byte input buffer (it speaks far slower than 9600 baud
// delivers), and the sketch as it stands would also mangle them:
//   - codeLength() stops counting at 64, truncating mid-entry -- possibly
//     between a command and its argument
//   - speakNext() holds the length in a uint8_t; fxdemowords is 280 codes
// Enabling them needs codeLength()/len widened to uint16_t AND a sender that
// trickles bytes from loop() instead of writing them from the callback. There
// is no buffer-level feedback on this shield (D2/Buffer Half Full is not
// connected; D0/Ready only signals self-test passed), so pacing would have to
// be time-based or use D1/Speaking via the spare shifter channel.
// ===========================================================================
#if EXTRADICT_LONG_FX


// fxalpha=a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
static const uint8_t xd_fxalpha[] = {  // 98 codes
  /* a */ SJ_EYIY, SJ_IY, SJ_PAUSE6,
  /* b */ SJ_BE, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* c */ SJ_SE, SJ_SE, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* d */ SJ_DE, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* e */ SJ_IY, SJ_IY, SJ_PAUSE6,
  /* f */ SJ_SLOW, SJ_EH, SJ_FF, SJ_PAUSE6,
  /* g */ SJ_JH, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* h */ SJ_EYIY, SJ_CH, SJ_PAUSE6,
  /* i */ SJ_OHIH, SJ_PAUSE6,
  /* j */ SJ_JH, SJ_EYIY, SJ_PAUSE6,
  /* k */ SJ_KE, SJ_EYIY, SJ_PAUSE6,
  /* l */ SJ_EH, SJ_EHLE, SJ_PAUSE6,
  /* m */ SJ_EH, SJ_EH, SJ_MM, SJ_PAUSE6,
  /* n */ SJ_EH, SJ_EH, SJ_NE, SJ_PAUSE6,
  /* o */ SJ_OW, SJ_OWWW, SJ_PAUSE6,
  /* p */ SJ_PE, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* q */ SJ_KE, SJ_IYUW, SJ_PAUSE6,
  /* r */ SJ_AWRR, SJ_PAUSE6,
  /* s */ SJ_EH, SJ_SE, SJ_SE, SJ_PAUSE6,
  /* t */ SJ_TU, SJ_IY, SJ_IY, SJ_PAUSE6,
  /* u */ SJ_SLOW, SJ_IYUW, SJ_PAUSE6,
  /* v */ SJ_SLOW, SJ_VV, SJ_SLOW, SJ_IY, SJ_PAUSE6,
  /* w */ SJ_DO, SJ_FAST, SJ_UX, SJ_SOFT, SJ_BO, SJ_EHLE, SJ_IYUW, SJ_UW, SJ_PAUSE6,
  /* x */ SJ_EH, SJ_EH, SJ_KO, SJ_SE, SJ_PAUSE6,
  /* y */ SJ_WW, SJ_OHIH, SJ_PAUSE6,
  /* z */ SJ_SLOW, SJ_ZZ, SJ_IY, SJ_IY,
  SJ_END };

// fxberzerkgotthehumaniod = ... (101 chars, see PhraseALator.Dic)
static const uint8_t xd_fxberzerkgotthehumaniod[] = {  // 59 codes
  SJ_CMD_SPEED, 120, SJ_CMD_BEND, 3, SJ_CMD_PITCH, 98 /*G2*/,
  /* got */ SJ_SLOW, SJ_GO, SJ_OH, SJ_OH, SJ_TT, SJ_PAUSE6,
  /* thu */ SJ_SLOW, SJ_DH, SJ_SLOW, SJ_UX, SJ_PAUSE6,
  /* humaniod */ SJ_HO, SJ_FAST, SJ_IYUW, SJ_MM, SJ_UX, SJ_FAST, SJ_NO, SJ_FAST, SJ_OW, SJ_FAST,
                 SJ_OWIY, SJ_ED, SJ_PAUSE2, SJ_PAUSE2, SJ_CMD_SPEED, 120, SJ_CMD_BEND, 10,
                 SJ_CMD_PITCH, 110 /*A2*/,
  /* got */ SJ_SLOW, SJ_GO, SJ_OH, SJ_OH, SJ_TT, SJ_PAUSE6,
  /* thu */ SJ_SLOW, SJ_DH, SJ_SLOW, SJ_UX, SJ_PAUSE6,
  /* intruder */ SJ_IH, SJ_NE, SJ_TT, SJ_RR, SJ_UW, SJ_FAST, SJ_DE, SJ_FAST, SJ_AX, SJ_FAST,
                 SJ_AXRR,
  SJ_END };

// fxdemowords = ... (438 chars, see PhraseALator.Dic)
// Contains NT note commands, so it plays its own melody regardless of the key.
static const uint8_t xd_fxdemowords[] = {  // 280 codes
  SJ_CMD_PITCH, 65 /*C2*/,
  /* activated */ SJ_AY, SJ_KE, SJ_TT, SJ_FAST, SJ_IH, SJ_VV, SJ_FAST, SJ_EYIY, SJ_TT, SJ_IH, SJ_ED,
                  SJ_PAUSE2, SJ_CMD_PITCH, 73 /*D2*/,
  /* basic */ SJ_BE, SJ_EYIY, SJ_SE, SJ_IH, SJ_FAST, SJ_PAUSE4, SJ_OK, SJ_PAUSE2, SJ_CMD_PITCH, 82
              /*E2*/,
  /* correct */ SJ_KO, SJ_OWRR, SJ_EH, SJ_EK, SJ_TT, SJ_PAUSE2, SJ_CMD_PITCH, 87 /*F2*/,
  /* discover */ SJ_DE, SJ_FAST, SJ_IH, SJ_SE, SJ_KE, SJ_UX, SJ_VV, SJ_AXRR, SJ_PAUSE2,
                 SJ_CMD_PITCH, 73 /*D2*/,
  /* engage */ SJ_SLOW, SJ_IH, SJ_NE, SJ_PAUSE4, SJ_GE, SJ_EYIY, SJ_JH, SJ_PAUSE2, SJ_CMD_PITCH, 65
               /*C2*/,
  /* favorite */ SJ_FF, SJ_FAST, SJ_EYIY, SJ_VV, SJ_FAST, SJ_RR, SJ_IH, SJ_TT, SJ_PAUSE2, SJ_PAUSE1,
  /* guaging */ SJ_SLOW, SJ_GE, SJ_EYIY, SJ_JH, SJ_IH, SJ_NGE, SJ_PAUSE2, SJ_PAUSE2, SJ_CMD_PITCH,
                123 /*B2*/,
  /* humaniod */ SJ_HO, SJ_FAST, SJ_IYUW, SJ_MM, SJ_UX, SJ_FAST, SJ_NO, SJ_FAST, SJ_OW, SJ_FAST,
                 SJ_OWIY, SJ_ED, SJ_PAUSE2, SJ_CMD_PITCH, 110 /*A2*/,
  /* innovations */ SJ_SLOW, SJ_IH, SJ_NE, SJ_FAST, SJ_OW, SJ_VV, SJ_FAST, SJ_EYIY, SJ_SH, SJ_AX,
                    SJ_NO, SJ_SE, SJ_PAUSE2, SJ_CMD_PITCH, 98 /*G2*/,
  /* january */ SJ_JH, SJ_AY, SJ_NE, SJ_FAST, SJ_IYUW, SJ_FAST, SJ_EYRR, SJ_IY, SJ_PAUSE2,
                SJ_CMD_PITCH, 87 /*F2*/,
  /* keep */ SJ_KE, SJ_SLOW, SJ_IY, SJ_PE, SJ_PAUSE2, SJ_CMD_PITCH, 82 /*E2*/,
  /* learn */ SJ_LE, SJ_AXRR, SJ_NE, SJ_PAUSE2,
  /* music */ SJ_MM, SJ_IYUW, SJ_ZZ, SJ_IH, SJ_EK, SJ_PAUSE2, SJ_CMD_PITCH, 65 /*C2*/,
  /* new */ SJ_NE, SJ_IYUW, SJ_PAUSE2, SJ_CMD_PITCH, 73 /*D2*/,
  /* often */ SJ_OH, SJ_FF, SJ_TT, SJ_EH, SJ_NE, SJ_PAUSE2, SJ_PAUSE2, SJ_CMD_PITCH, 65 /*C2*/,
  /* plenty */ SJ_PO, SJ_FAST, SJ_LE, SJ_EH, SJ_NE, SJ_TT, SJ_IY, SJ_PAUSE2, SJ_CMD_PITCH, 82
               /*E2*/,
  /* quick */ SJ_KO, SJ_FAST, SJ_WW, SJ_SLOW, SJ_IH, SJ_PAUSE4, SJ_EK, SJ_PAUSE2, SJ_CMD_PITCH, 73
              /*D2*/,
  /* ready */ SJ_SLOW, SJ_RR, SJ_EY, SJ_DE, SJ_IY, SJ_PAUSE2, SJ_CMD_PITCH, 65 /*C2*/,
  /* sincerity */ SJ_SE, SJ_IH, SJ_NE, SJ_SE, SJ_EH, SJ_RR, SJ_IH, SJ_TT, SJ_IY, SJ_PAUSE2,
                  SJ_PAUSE2, SJ_CMD_PITCH, 131 /*C3*/,
  /* teacher */ SJ_TT, SJ_SLOW, SJ_IY, SJ_CH, SJ_FAST, SJ_AXRR, SJ_FAST, SJ_RR, SJ_PAUSE2,
                SJ_PAUSE6, SJ_CMD_PITCH, 123 /*B2*/,
  /* uncle */ SJ_SLOW, SJ_UX, SJ_FAST, SJ_NGO, SJ_KO, SJ_UH, SJ_SLOW, SJ_LO, SJ_PAUSE2,
              SJ_CMD_PITCH, 110 /*A2*/,
  /* vacation */ SJ_VV, SJ_FAST, SJ_EYIY, SJ_KE, SJ_EYIY, SJ_SH, SJ_UX, SJ_NO, SJ_PAUSE2,
                 SJ_CMD_PITCH, 98 /*G2*/,
  /* welcome */ SJ_WW, SJ_EHLE, SJ_KE, SJ_UX, SJ_MM, SJ_PAUSE2, SJ_CMD_PITCH, 87 /*F2*/,
  /* xray */ SJ_EH, SJ_EH, SJ_KO, SJ_SE, SJ_RR, SJ_EYIY, SJ_PAUSE2, SJ_CMD_PITCH, 82 /*E2*/,
  /* yes */ SJ_IYEH, SJ_SE, SJ_SE, SJ_PAUSE2, SJ_PAUSE2, SJ_CMD_SPEED, 120,
  /* and */ SJ_SLOW, SJ_AY, SJ_SLOW, SJ_NE, SJ_OD, SJ_CMD_PITCH, 73 /*D2*/,
  /* finally */ SJ_FF, SJ_FAST, SJ_OHIY, SJ_NO, SJ_FAST, SJ_LE, SJ_IY, SJ_PAUSE2, SJ_PAUSE2,
                SJ_PAUSE6, SJ_CMD_SPEED, 100, SJ_CMD_PITCH, 65 /*C2*/,
  /* zebra */ SJ_ZZ, SJ_FAST, SJ_IY, SJ_SOFT, SJ_BE, SJ_FAST, SJ_RR, SJ_UX, SJ_CMD_SPEED, 0,
              SJ_PAUSE0,
  SJ_END };

// fxfrogs = ... (301 chars, see PhraseALator.Dic)
static const uint8_t xd_fxfrogs[] = {  // 62 codes
  SJ_CMD_PITCH, 33 /*C1*/, SJ_CMD_SPEED, 20, SJ_CMD_BEND, 0, SJ_BO, SJ_FAST, SJ_UX, SJ_ED,
  SJ_PAUSE2, SJ_CMD_BEND, 10, SJ_CMD_PITCH, 73 /*D2*/, SJ_FAST, SJ_WW, SJ_FAST, SJ_OHIY, SJ_FAST,
  SJ_ZZ, SJ_SLOW, SJ_PAUSE1, SJ_CMD_PITCH, 55 /*A1*/, SJ_CMD_SPEED, 60, SJ_CMD_BEND, 3, SJ_FAST,
  SJ_AXRR, SJ_PAUSE2, SJ_CMD_PITCH, 33 /*C1*/, SJ_CMD_SPEED, 20, SJ_CMD_BEND, 0, SJ_BO, SJ_FAST,
  SJ_UX, SJ_ED, SJ_CMD_BEND, 10, SJ_CMD_PITCH, 73 /*D2*/, SJ_FAST, SJ_WW, SJ_FAST, SJ_OHIY, SJ_FAST,
  SJ_ZZ, SJ_SLOW, SJ_PAUSE4, SJ_CMD_PITCH, 55 /*A1*/, SJ_CMD_SPEED, 60, SJ_CMD_BEND, 3, SJ_FAST,
  SJ_AXRR,
  SJ_END };

// fxmonths = ... (103 chars, see PhraseALator.Dic)
static const uint8_t xd_fxmonths[] = {  // 90 codes
  /* january */ SJ_JH, SJ_AY, SJ_NE, SJ_FAST, SJ_IYUW, SJ_FAST, SJ_EYRR, SJ_IY, SJ_PAUSE2,
  /* february */ SJ_FF, SJ_EH, SJ_EB, SJ_RR, SJ_UW, SJ_EYRR, SJ_IY, SJ_PAUSE2,
  /* march */ SJ_MM, SJ_AWRR, SJ_CH, SJ_PAUSE2,
  /* april */ SJ_EYIY, SJ_PE, SJ_RR, SJ_LE, SJ_PAUSE2,
  /* may */ SJ_MM, SJ_EYIY, SJ_PAUSE2,
  /* june */ SJ_JH, SJ_IYUW, SJ_NO, SJ_PAUSE2,
  /* july */ SJ_JH, SJ_FAST, SJ_IHWW, SJ_LE, SJ_OHIH, SJ_PAUSE2,
  /* august */ SJ_SLOW, SJ_AW, SJ_GO, SJ_AX, SJ_SE, SJ_TT, SJ_PAUSE2,
  /* september */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_EH, SJ_PE, SJ_FAST, SJ_TT, SJ_EH, SJ_FAST, SJ_MM,
                  SJ_EB, SJ_FAST, SJ_AX, SJ_FAST, SJ_AXRR, SJ_PAUSE2,
  /* october */ SJ_OH, SJ_OK, SJ_TT, SJ_OW, SJ_SOFT, SJ_BO, SJ_FAST, SJ_AXRR, SJ_PAUSE2,
  /* november */ SJ_NO, SJ_OW, SJ_VV, SJ_FAST, SJ_EH, SJ_MM, SJ_EB, SJ_FAST, SJ_AXRR, SJ_PAUSE2,
  /* december */ SJ_DE, SJ_FAST, SJ_IY, SJ_SE, SJ_EH, SJ_MM, SJ_EB, SJ_FAST, SJ_RR,
  SJ_END };

// fxnumbers = ... (239 chars, see PhraseALator.Dic)
static const uint8_t xd_fxnumbers[] = {  // 228 codes
  /* one */ SJ_WW, SJ_STRESS, SJ_OH, SJ_SLOW, SJ_NE, SJ_PAUSE2,
  /* two */ SJ_SLOW, SJ_TT, SJ_IHWW, SJ_PAUSE2,
  /* three */ SJ_SLOW, SJ_TH, SJ_RR, SJ_SLOW, SJ_IY, SJ_PAUSE2,
  /* four */ SJ_FF, SJ_FAST, SJ_OW, SJ_OWRR, SJ_PAUSE2,
  /* five */ SJ_FF, SJ_OHIH, SJ_VV, SJ_PAUSE2,
  /* six */ SJ_SLOW, SJ_SE, SJ_IH, SJ_STRESS, SJ_KE, SJ_FAST, SJ_SE, SJ_PAUSE2,
  /* seven */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_EH, SJ_VV, SJ_EH, SJ_NE, SJ_PAUSE2,
  /* eight */ SJ_EYIY, SJ_PAUSE4, SJ_TT, SJ_PAUSE2,
  /* nine */ SJ_NE, SJ_STRESS, SJ_OHIH, SJ_NE, SJ_PAUSE2,
  /* ten */ SJ_TT, SJ_EH, SJ_EH, SJ_NE, SJ_PAUSE2,
  /* eleven */ SJ_FAST, SJ_IH, SJ_LE, SJ_EH, SJ_VV, SJ_FAST, SJ_EH, SJ_NE, SJ_PAUSE2,
  /* twelve */ SJ_SLOW, SJ_TT, SJ_FAST, SJ_WW, SJ_EH, SJ_LE, SJ_VV, SJ_PAUSE2,
  /* thirteen */ SJ_SLOW, SJ_TH, SJ_FAST, SJ_AXRR, SJ_TT, SJ_IY, SJ_NE, SJ_PAUSE2,
  /* fourteen */ SJ_FF, SJ_FAST, SJ_OWRR, SJ_FAST, SJ_TT, SJ_IY, SJ_NE, SJ_PAUSE2,
  /* fifteen */ SJ_FF, SJ_IH, SJ_FF, SJ_TT, SJ_IY, SJ_NE, SJ_PAUSE2,
  /* sixteen */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_IH, SJ_STRESS, SJ_KE, SJ_SE, SJ_FAST, SJ_TT, SJ_IY,
                SJ_NE, SJ_PAUSE2,
  /* seventeen */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_EH, SJ_FAST, SJ_VV, SJ_FAST, SJ_EH, SJ_NE, SJ_FAST,
                  SJ_TT, SJ_IY, SJ_NE, SJ_PAUSE2,
  /* eighteen */ SJ_EYIY, SJ_PAUSE4, SJ_TT, SJ_IY, SJ_NE, SJ_PAUSE2,
  /* nineteen */ SJ_NE, SJ_FAST, SJ_RELAX, SJ_OHIY, SJ_NE, SJ_TT, SJ_IY, SJ_SLOW, SJ_NE, SJ_PAUSE2,
  /* twenty */ SJ_SLOW, SJ_FAST, SJ_TT, SJ_FAST, SJ_WW, SJ_EH, SJ_NE, SJ_FAST, SJ_TT, SJ_IY,
               SJ_PAUSE2,
  /* thirty */ SJ_SLOW, SJ_TH, SJ_FAST, SJ_AXRR, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* forty */ SJ_FF, SJ_FAST, SJ_OWRR, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* fifty */ SJ_FF, SJ_IH, SJ_FF, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* sixty */ SJ_SLOW, SJ_SE, SJ_IH, SJ_STRESS, SJ_KE, SJ_SE, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* seventy */ SJ_SLOW, SJ_SE, SJ_FAST, SJ_EH, SJ_FAST, SJ_VV, SJ_EH, SJ_FAST, SJ_NE, SJ_TT, SJ_IY,
                SJ_PAUSE2,
  /* eighty */ SJ_EYIY, SJ_PAUSE4, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* ninety */ SJ_NE, SJ_FAST, SJ_RELAX, SJ_OHIY, SJ_NE, SJ_TT, SJ_IY, SJ_PAUSE2,
  /* hundred */ SJ_HO, SJ_UX, SJ_NE, SJ_ED, SJ_FAST, SJ_RR, SJ_EH, SJ_ED, SJ_PAUSE2,
  /* thousand */ SJ_SLOW, SJ_TH, SJ_FAST, SJ_AYWW, SJ_ZZ, SJ_FAST, SJ_AX, SJ_SLOW, SJ_NE, SJ_PAUSE2,
  /* million */ SJ_MM, SJ_IH, SJ_FAST, SJ_LE, SJ_FAST, SJ_IYEH, SJ_SLOW, SJ_NE,
  SJ_END };

// fxwomwom = ... (441 chars, see PhraseALator.Dic)
// INTENT FIX: the Dic writes "\BEND \ 1" (stray space) twice. The original tool would drop the 1
// and send the following C0/C2 code (230/232) as the Bend value. Bend 1 is clearly intended and is
// used here.
static const uint8_t xd_fxwomwom[] = {  // 98 codes
  SJ_CMD_SPEED, 120, SJ_CMD_BEND, 0, SJ_C0, SJ_CMD_BEND, 1, SJ_C0, SJ_CMD_BEND, 2, SJ_C0,
  SJ_CMD_BEND, 3, SJ_C0, SJ_CMD_BEND, 4, SJ_C0, SJ_CMD_BEND, 5, SJ_C0, SJ_CMD_BEND, 6, SJ_C0,
  SJ_CMD_BEND, 7, SJ_C0, SJ_CMD_BEND, 8, SJ_C0, SJ_CMD_BEND, 9, SJ_C0, SJ_CMD_BEND, 10, SJ_C0,
  SJ_CMD_BEND, 11, SJ_C0, SJ_CMD_BEND, 12, SJ_C0, SJ_CMD_BEND, 13, SJ_C0, SJ_CMD_BEND, 14, SJ_C0,
  SJ_CMD_BEND, 15, SJ_C0, SJ_CMD_BEND, 0, SJ_C2, SJ_CMD_BEND, 1, SJ_C2, SJ_CMD_BEND, 2, SJ_C2,
  SJ_CMD_BEND, 3, SJ_C2, SJ_CMD_BEND, 4, SJ_C2, SJ_CMD_BEND, 5, SJ_C2, SJ_CMD_BEND, 6, SJ_C2,
  SJ_CMD_BEND, 7, SJ_C2, SJ_CMD_BEND, 8, SJ_C2, SJ_CMD_BEND, 9, SJ_C2, SJ_CMD_BEND, 10, SJ_C2,
  SJ_CMD_BEND, 11, SJ_C2, SJ_CMD_BEND, 12, SJ_C2, SJ_CMD_BEND, 13, SJ_C2, SJ_CMD_BEND, 14, SJ_C2,
  SJ_CMD_BEND, 15, SJ_C2,
  SJ_END };


#endif  // EXTRADICT_LONG_FX


// ===========================================================================
static const DictionaryEntry EXTRA_DICT[] = {
  // 1. starter words
  { "done",  xd_done  },
  { "gone",  xd_gone  },
  { "been",  xd_been  },
  { "said",  xd_said  },
  { "were",  xd_were  },
  { "has",   xd_has   },
  { "had",   xd_had   },
  { "did",   xd_did   },
  { "seen",  xd_seen  },
  { "lost",  xd_lost  },
  { "found", xd_found },
  { "real",  xd_real  },
  { "true",  xd_true  },
  { "false", xd_false },
  { "dream", xd_dream },
  { "wake",  xd_wake  },
  { "dead",  xd_dead  },
  { "body",  xd_body  },
  { "soul",  xd_soul  },
  { "hate",  xd_hate  },
  { "hope",  xd_hope  },
  { "later", xd_later },
  { "felt",  xd_felt  },
  { "kept",  xd_kept  },
  // 2. dropped by the converter
  { "can't",                             xd_cant },
  { "o'clock",                           xd_oclock },
  { "shouldn't",                         xd_shouldnt },
  { "that's",                            xd_thats },
  { "they're",                           xd_theyre },
  { "yoyo",                              xd_yoyo },
  // 3. fx overrides (RESET bug)
  { "fxalarm",                           xd_fxalarm },
  { "fxburningfusewithbang",             xd_fxburningfusewithbang },
  { "fxping",                            xd_fxping },
  { "fxrobotbede",                       xd_fxrobotbede },
  { "fxrobotdroid",                      xd_fxrobotdroid },
  { "fxrobotsad",                        xd_fxrobotsad },
  { "fxstatus1",                         xd_fxstatus1 },
  { "fxstatus2",                         xd_fxstatus2 },
  { "fxufo",                             xd_fxufo },
  // 4. dropped fx entries
  { "fxberzerkchickenfightlikearobot",   xd_fxberzerkchickenfightlikearobot },
  { "fxberzerkthehumaniodmustnotescape", xd_fxberzerkthehumaniodmustnotescape },
  { "fxburp",                            xd_fxburp },
  { "fxcountdown",                       xd_fxcountdown },
  { "fxcrickets",                        xd_fxcrickets },
  { "fxdanger",                          xd_fxdanger },
  { "fxrobotbeeps",                      xd_fxrobotbeeps },
  { "fxsongironman",                     xd_fxsongironman },
  { "fxsongscales",                      xd_fxsongscales },
  { "fxsongstar",                        xd_fxsongstar },
  { "fxtest",                            xd_fxtest },
#if EXTRADICT_LONG_FX
  // 5. long fx entries
  { "fxalpha",                           xd_fxalpha },
  { "fxberzerkgotthehumaniod",           xd_fxberzerkgotthehumaniod },
  { "fxdemowords",                       xd_fxdemowords },
  { "fxfrogs",                           xd_fxfrogs },
  { "fxmonths",                          xd_fxmonths },
  { "fxnumbers",                         xd_fxnumbers },
  { "fxwomwom",                          xd_fxwomwom },
#endif
  { 0, 0 }   // terminator — keep this last
};

#endif
