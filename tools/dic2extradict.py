#!/usr/bin/env python3
"""dic2extradict.py -- regenerate sections 2-5 of extradict.h from PhraseALator.Dic.

Needs PhraseALator.Dic, standardDict.cpp, extradict.h in the sketch folder
(firmware/07j_pacing/ by default -- set SKETCH_DIR to use another folder):
    python3 dic2extradict.py
Section 1 (hand-written starter words) and its table entries are preserved from
the existing extradict.h; everything else is rebuilt.

Translation follows the original Phrase-A-Lator (benbaker76/PhraseALator,
SpeakJet.cs). Validated by regenerating all 1427 entries of standardDict.cpp
byte-for-byte, the only differences being McCauley's RESET=30 bug. Run with
--verify to repeat that check.
"""
import re, sys, os

NAMES = {}
for i in range(7): NAMES['P%d' % i] = i
NAMES.update(FAST=7, SLOW=8, STRESS=14, RELAX=15, WAIT=16, SOFT=18, VOLUME=20,
             SPEED=21, PITCH=22, BEND=23, PCTRL=24, POUT=25, REPEAT=26, CALL=28,
             PLAY=29, DELAY=30, RESET=31)
ALLO = ("IY IH EY EH AY AX UX OH AW OW UH UW MM NE NO NGE NGO LE LO WW RR "
        "IYRR EYRR AXRR AWRR OWRR EYIY OHIY OWIY OHIH IYEH EHLE IYUW AXUW IHWW "
        "AYWW OWWW JH VV ZZ ZH DH BE BO EB OB DE DO ED OD GE GO EG OG CH HE HO "
        "WH FF SE SO SH TH TT TU TS KE KO EK OK PE PO").split()
assert len(ALLO) == 72
for i, n in enumerate(ALLO): NAMES[n] = 128 + i
for g, base in zip("RABC", (200, 210, 220, 230)):
    for i in range(10): NAMES['%s%d' % (g, i)] = base + i
for i in range(12): NAMES['D%d' % i] = 240 + i
NAMES.update(M0=252, M1=253, M2=254)

# Original GetNoteFreq table (Hz), verbatim.
NOTE_HZ = {'C1':33,'C#1':35,'D1':37,'D#1':39,'E1':41,'F1':44,'F#1':46,'G1':49,'G#1':52,
 'A1':55,'A#1':58,'B1':62,'C2':65,'C#2':69,'D2':73,'D#2':78,'E2':82,'F2':87,'F#2':93,
 'G2':98,'G#2':104,'A2':110,'A#2':117,'B2':123,'C3':131,'C#3':139,'D3':147,'D#3':156,
 'E3':165,'F3':175,'F#3':185,'G3':196,'G#3':208,'A3':220,'A#3':233,'B3':247}

def load_dic(path):
    d = {}
    for line in open(path, encoding='latin-1'):
        line = line.rstrip('\r\n')
        if '=' not in line or line.startswith('['): continue
        k, v = line.split('=', 1)
        d[k.strip().lower()] = v.strip()
    return d

def norm_key(w): return re.sub(r"[^a-z0-9]", "", w.lower())

class Translator:
    def __init__(self, dic):
        self.dic = dic
        self.bykey = {}
        for k in dic: self.bykey.setdefault(norm_key(k), k)
        self.notes = []          # human-readable notes on intent fixes / misses

    def lookup(self, word):
        w = word.lower()
        if w in self.dic: return w
        k = self.bykey.get(norm_key(w))
        if k: self.notes.append('"%s" resolved to dictionary entry "%s"' % (word, k))
        return k

    def translate(self, value, drop_reset=False, depth=0):
        """Returns list of (code, label) where label is a symbolic name or None."""
        value = re.sub(r'\\\s+(\d+)', r'\\\1', value)   # "\ 1" -> "\1" (intent)
        out = []
        # tokens: backslash token | word | comma run | space run
        for m in re.finditer(r"(\\[A-Za-z0-9#]+)|([A-Za-z0-9'\-]+)|(,+)|( +)", value + ' '):
            bs, word, commas, spaces = m.groups()
            if bs:
                t = bs[1:].upper()
                if t.isdigit():
                    out.append((int(t), None))
                elif t.startswith('NT'):
                    out.append((NAMES['PITCH'], 'SJ_CMD_PITCH'))
                    out.append((NOTE_HZ[t[2:]], None))
                elif t in NAMES:
                    if drop_reset and t == 'RESET': continue
                    out.append((NAMES[t], t))
                else:
                    raise ValueError('unknown token %s' % bs)
            elif word:
                k = self.lookup(word)
                if k is None:
                    self.notes.append('word "%s" not in dictionary -- omitted' % word)
                    continue
                sub = self.translate(self.dic[k], drop_reset, depth + 1)
                out.append(('WORD', k))
                out.extend(sub)
            elif commas:
                out.extend([(2, 'P2')] * len(commas))
            elif spaces and m.end() < len(value) + 1 and m.start() > 0:
                n = len(spaces)
                if n == 2: out.append((6, 'P6'))
                elif n >= 3: out.extend([(4, 'P4'), (1, 'P1')])
        return out

def codes_only(seq): return [c for c, l in seq if c != 'WORD']

# The sketch folder: inputs are read from it and extradict.h rewritten in it.
HERE = os.environ.get('SKETCH_DIR') or os.path.join(
    os.path.dirname(os.path.abspath(__file__)), '..', 'firmware', '07j_pacing')

if '--verify' in sys.argv:
    dic = load_dic(os.path.join(HERE, 'PhraseALator.Dic'))
    src = open(os.path.join(HERE, 'standardDict.cpp')).read()
    words = dict(re.findall(r'_dict_standard_word_(\d+)\[\] = "([^"]*)"', src))
    codes = {k: [int(x) for x in v.split(',')][:-1]
             for k, v in re.findall(r'_dict_standard_code_(\d+)\[\] = \{([^}]*)\}', src)}
    T = Translator(dic); bad = []
    for k, w in words.items():
        mine = codes_only(T.translate(dic[w]))
        if mine != codes[k]:
            bad.append((w, sorted(set((a, b) for a, b in zip(mine, codes[k]) if a != b))))
    print('%d entries checked, %d differ:' % (len(words), len(bad)))
    for b in bad: print('  %-24s (mine, theirs): %s' % b)
    sys.exit(0)
import textwrap, os

dic = load_dic(os.path.join(HERE, 'PhraseALator.Dic'))
src = open(os.path.join(HERE, 'standardDict.cpp')).read()
std = set(re.findall(r'_dict_standard_word_\d+\[\] = "([^"]*)"', src))
T = Translator(dic)
BUDGET = 56          # SpeakJet 64-byte input buffer minus the 8-byte parameter block

SIMPLE = {'FAST','SLOW','STRESS','RELAX','SOFT','WAIT'}
CMDS = {'VOLUME','SPEED','PITCH','BEND','PCTRL','POUT','REPEAT','CALL','PLAY','DELAY','RESET'}

def sym(code, label):
    if label is None: return str(code)
    if label.startswith('NOTE:'): return '%d /*%s*/' % (code, label[5:])
    if re.fullmatch(r'P\d', label): return 'SJ_PAUSE' + label[1]
    if label in SIMPLE: return 'SJ_' + label
    if label in CMDS: return 'SJ_CMD_' + label
    return 'SJ_' + label

def translate_labeled(value):
    # re-run translation but keep note names for comments
    seq = T.translate(value, drop_reset=True)
    out, i = [], 0
    while i < len(seq):
        c, l = seq[i]
        if l == 'SJ_CMD_PITCH':
            out.append((c, 'PITCH'))
            hz = seq[i+1][0]
            name = [n for n, v in NOTE_HZ.items() if v == hz]
            out.append((hz, 'NOTE:' + name[0] if name else None)); i += 2; continue
        out.append((c, l)); i += 1
    return out

def ident(word): return 'xd_' + re.sub(r'[^a-z0-9]', '', word.lower())

def emit_array(key, word, value, note=None):
    seq = translate_labeled(value)
    n = len(codes_only(seq))
    lines = []
    orig = '%s=%s' % (word, value)
    if len(orig) <= 110:
        lines.append('// %s' % orig)
    else:
        lines.append('// %s = ... (%d chars, see PhraseALator.Dic)' % (word, len(value)))
    if note:
        for ln in textwrap.wrap(note, 96): lines.append('// ' + ln)
    head = 'static const uint8_t %s[] = {  // %d codes' % (ident(key), n)
    lines.append(head)
    # group: split at WORD markers
    groups, cur, curlabel = [], [], None
    for c, l in seq:
        if c == 'WORD':
            if cur: groups.append((curlabel, cur))
            cur, curlabel = [], l
        else:
            cur.append(sym(c, l))
    if cur or curlabel: groups.append((curlabel, cur))
    for lab, items in groups:
        prefix = '  /* %s */ ' % lab if lab else '  '
        body = ', '.join(items) + ','
        wrapped = textwrap.wrap(body, 100 - len(prefix), break_long_words=False, break_on_hyphens=False)
        for j, w in enumerate(wrapped):
            lines.append((prefix if j == 0 else ' ' * len(prefix)) + w)
    lines.append('  SJ_END };')
    return '\n'.join(lines), n

# ---- select entries -------------------------------------------------------
contractions = ["can't", "o'clock", "shouldn't", "that's", "they're"]
fx_over  = sorted(w for w in std if w.startswith('fx'))
fx_new   = sorted(w for w in dic if w.startswith('fx') and w not in std)

NOTES = {
 'fxwomwom': 'INTENT FIX: the Dic writes "\\BEND \\ 1" (stray space) twice. The original tool '
             'would drop the 1 and send the following C0/C2 code (230/232) as the Bend value. '
             'Bend 1 is clearly intended and is used here.',
 'fxdanger': 'INTENT FIX: the original tool strips "#" from words, so \\NTA#2 would have played '
             'A2 (110 Hz). A#2 (117 Hz) as written is used here.',
 'fxdemowords': 'Contains NT note commands, so it plays its own melody regardless of the key.',
}

out_blocks = {'contr': [], 'over': [], 'new_short': [], 'new_long': []}
table = {'contr': [], 'over': [], 'new_short': [], 'new_long': []}
report = []
for w in contractions:
    b, n = emit_array(w, w, dic[w]); out_blocks['contr'].append(b); table['contr'].append(w)
# yo-yo: hyphen is a token break, so store under "yoyo"
b, n = emit_array('yoyo', 'yo-yo', dic['yo-yo'],
    'Stored as "yoyo": the tokeniser splits on hyphens, so "yo-yo" can never match. '
    '(x-ray needs no entry: "xray" is already in the standard dictionary.)')
out_blocks['contr'].append(b); table['contr'].append('yoyo')
for w in fx_over:
    b, n = emit_array(w, w, dic[w], NOTES.get(w)); out_blocks['over'].append(b); table['over'].append(w)
    report.append((w, n, 'override'))
for w in fx_new:
    b, n = emit_array(w, w, dic[w], NOTES.get(w))
    k = 'new_short' if n <= BUDGET else 'new_long'
    out_blocks[k].append(b); table[k].append((w, n) if k == 'new_long' else w)
    report.append((w, n, k))

# ---- macros --------------------------------------------------------------
def macro_block():
    L = []
    L.append('// --- modifiers (affect the next phoneme only) ---')
    for i, ms in enumerate(['0 ms','100 ms','200 ms','700 ms','30 ms','60 ms','90 ms']):
        L.append('#define SJ_PAUSE%d   %d     // %s' % (i, i, ms))
    L += ['#define SJ_FAST     7     // next phoneme at 0.5x duration',
          '#define SJ_SLOW     8     // next phoneme at 1.5x duration',
          '#define SJ_STRESS   14',
          '#define SJ_RELAX    15',
          '#define SJ_WAIT     16    // stops and waits for an SCP start -- never use in a word',
          '#define SJ_SOFT     18    // Phrase-A-Lator \\SOFT; undocumented in the manual, used before B',
          '#define SJ_END      255   // end-of-entry sentinel, never transmitted',
          '',
          '// --- commands that take ONE argument byte (Table D) ---',
          '// Named SJ_CMD_* because the sketch already declares SJ_VOLUME/SJ_SPEED/SJ_PITCH/',
          '// SJ_BEND as constants after this header is included; a #define of the same name',
          '// would break those declarations.',
          '#define SJ_CMD_VOLUME 20',
          '#define SJ_CMD_SPEED  21',
          '#define SJ_CMD_PITCH  22    // argument is Hz',
          '#define SJ_CMD_BEND   23',
          '#define SJ_CMD_REPEAT 26    // repeat the NEXT code n times',
          '#define SJ_CMD_DELAY  30    // n x 10 ms',
          '#define SJ_CMD_RESET  31    // no argument. NB: McCauley\'s converter emitted 30 (Delay)',
          '                            // for \\RESET -- see the fx section below.']
    return '\n'.join(L)

ALLO_GROUPS = [
 ('vowels', 'IY IH EY EH AY AX UX OH AW OW UH UW'),
 ('nasals / resonants', 'MM NE NO NGE NGO LE LO WW RR'),
 ('r-coloured vowels', 'IYRR EYRR AXRR AWRR OWRR'),
 ('diphthongs', 'EYIY OHIY OWIY OHIH IYEH EHLE IYUW AXUW IHWW AYWW OWWW'),
 ('voiced consonants', 'JH VV ZZ ZH DH BE BO EB OB DE DO ED OD GE GO EG OG'),
 ('voiceless consonants', 'CH HE HO WH FF SE SO SH TH TT TU TS KE KO EK OK PE PO'),
]
def allo_block():
    L = []
    for title, names in ALLO_GROUPS:
        L.append('// --- %s ---' % title)
        for nm in names.split():
            line = '#define SJ_%-5s %d' % (nm, NAMES[nm])
            if nm == 'RR': line += "    // NB: McCauley's SpeakJet.h says 149 (collides with IYRR). Manual: 148."
            if nm == 'DO': line += "    // NB: McCauley's SpeakJet.h says 174 (collides with DE). Manual: 175."
            L.append(line)
    L.append('// --- sound effects 200..254 ---')
    for g, title in zip('RABC', ['robot', 'alarm', 'beeps', 'biological']):
        L.append('// %s' % title)
        for i in range(10):
            L.append('#define SJ_%s%d %d' % (g, i, NAMES['%s%d' % (g, i)]))
    L.append('// DTMF: D0..D9 = digits, D10 = *, D11 = #')
    for i in range(12):
        L.append('#define SJ_D%d %d' % (i, 240 + i))
    L.append('// miscellaneous')
    L.append('#define SJ_M0 252   // sonar ping')
    L.append('#define SJ_M1 253   // pistol shot')
    L.append('#define SJ_M2 254   // "wow"')
    return '\n'.join(L)

existing = open(os.path.join(HERE, 'extradict.h'), encoding='utf-8').read()
m = re.search(r'(// =+\n// YOUR WORDS.*?)(\n// =+\n// 2\. DROPPED|static const DictionaryEntry EXTRA_DICT)', existing, re.S)
starter = m.group(1).rstrip()
starter_entries = re.search(r'EXTRA_DICT\[\] = \{\n(?:  // 1\. starter words\n)?(.*?)(?:\n  // 2\. dropped|\n  \{ 0, 0 \})', existing, re.S).group(1).rstrip()

# ---- assemble -------------------------------------------------------------
H = []
H.append('''// extradict.h — add your own words here.
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
// the only differences were the nine \\RESET codes. Rules, for hand-editing:
//   \\TOKEN      -> its code          \\123     -> the byte 123
//   \\NTC2 etc.  -> Pitch + fixed Hz   word      -> that word's codes, recursively
//   ,          -> \\P2 each           2 spaces  -> \\P6     3+ spaces -> \\P4 \\P1
//
// ---------------------------------------------------------------------------
// HOW TO ADD A WORD
// ---------------------------------------------------------------------------
// 1. Find a RHYME that's already in the dictionary and steal its phonemes.
//    This is far more reliable than deriving from scratch. Use the '?' menu
//    command to see any existing word's codes, or read PhraseALator.Dic, which
//    is human-readable: e.g.  none = \\NO \\SLOW \\UX \\NE
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
''')
H.append(macro_block())
H.append(allo_block())
H.append('\n' + starter)

H.append('''
// ===========================================================================
// 2. DROPPED BY THE CONVERTER — Sensory's own pronunciations, not derived.
// The apostrophe is not a token break, so "can't" typed on the keyboard matches.
// ===========================================================================
''')
H.append('\n\n'.join(out_blocks['contr']))

H.append('''

// ===========================================================================
// 3. fx OVERRIDES — the RESET bug
// ---------------------------------------------------------------------------
// Phrase-A-Lator defines \\RESET as 31 (Reset Defaults). McCauley's converter
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
''')
H.append('\n\n'.join(out_blocks['over']))

H.append('''

// ===========================================================================
// 4. fx ENTRIES THE CONVERTER DROPPED (fit the %d-code budget)
// ---------------------------------------------------------------------------
// Budget: SpeakJet input buffer 64 bytes - 8-byte parameter block = %d codes.
// Resets dropped, as in section 3. Entries with NT note commands play their own
// pitches and ignore the key; the rest follow it.
// ⚠️ Anything over ~24 codes also exceeds the RP2350's 32-byte UART FIFO, so
// Serial2.write() blocks inside the note-on callback for ~1 ms per excess byte.
// ===========================================================================
''' % (BUDGET, BUDGET))
H.append('\n\n'.join(out_blocks['new_short']))

H.append('''

// ===========================================================================
// 5. LONG fx ENTRIES — disabled unless EXTRADICT_LONG_FX is 1
// ---------------------------------------------------------------------------
// These exceed the %d-code budget. Sent in one burst they overflow the
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

''' % BUDGET)
H.append('\n\n'.join(out_blocks['new_long']))
H.append('\n\n#endif  // EXTRADICT_LONG_FX\n')

# table
def entries(ws):
    return '\n'.join('  { %-36s %s },' % ('"%s",' % w, ident(w)) for w in ws)
H.append('''
// ===========================================================================
static const DictionaryEntry EXTRA_DICT[] = {
  // 1. starter words
%s
  // 2. dropped by the converter
%s
  // 3. fx overrides (RESET bug)
%s
  // 4. dropped fx entries
%s
#if EXTRADICT_LONG_FX
  // 5. long fx entries
%s
#endif
  { 0, 0 }   // terminator — keep this last
};

#endif
''' % (starter_entries, entries(table['contr']), entries(table['over']),
       entries(table['new_short']), entries([w for w, n in table['new_long']])))

open(os.path.join(HERE, 'extradict.h'), 'w', encoding='utf-8').write('\n'.join(H))
print('wrote extradict.h')
for r in report: print('  %-36s %4d codes  %s' % r)
