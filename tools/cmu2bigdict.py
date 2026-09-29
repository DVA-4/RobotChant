#!/usr/bin/env python3
"""cmu2bigdict.py -- build a large SpeakJet dictionary from CMUdict.

The phoneme->allophone conversion is LEARNED from Sensory's hand-tuned
dictionary (standardDict.cpp): each Sensory word is aligned against its CMUdict
pronunciation, and the converter learns which allophones AND timing modifiers
(FAST/SLOW/STRESS/RELAX/SOFT, pauses) Sensory used for each phoneme in each
context (stress, neighbouring phonemes, word position).

Usage (needs cmudict.dict, standardDict.cpp, extradict.h in the sketch folder,
firmware/07j_pacing/ by default -- set SKETCH_DIR to use another folder):
    pip install wordfreq            # word ranking only (Apache-2.0)
    python3 cmu2bigdict.py --eval   # 5-fold cross-validation against Sensory
    python3 cmu2bigdict.py 30000    # writes bigdict.cpp (+ bigdict.h)

Words already in standardDict.cpp or extradict.h are skipped: those tables are
searched first on the device and always win.
"""
import re, sys, math, random, collections, os

# The sketch folder: inputs are read from it and bigdict.cpp/.h written to it.
HERE = os.environ.get('SKETCH_DIR') or os.path.join(
    os.path.dirname(os.path.abspath(__file__)), '..', 'firmware', '07j_pacing')

# ---------------------------------------------------------------- SpeakJet names
ALLO = ("IY IH EY EH AY AX UX OH AW OW UH UW MM NE NO NGE NGO LE LO WW RR "
        "IYRR EYRR AXRR AWRR OWRR EYIY OHIY OWIY OHIH IYEH EHLE IYUW AXUW IHWW "
        "AYWW OWWW JH VV ZZ ZH DH BE BO EB OB DE DO ED OD GE GO EG OG CH HE HO "
        "WH FF SE SO SH TH TT TU TS KE KO EK OK PE PO").split()
A2C = {n: 128 + i for i, n in enumerate(ALLO)}
C2A = {v: k for k, v in A2C.items()}
MODS = {0, 1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 18}        # pauses + FAST SLOW STRESS RELAX SOFT
ARGCMD = set(range(20, 27)) | {28, 29, 30}

# Loose phoneme -> plausible allophones, used ONLY to seed the first alignment.
SEED = {
 'AA': 'AW OH AWRR', 'AE': 'AY EH', 'AH': 'AX UX UH', 'AO': 'OH AW OWRR', 'AW': 'AXUW AYWW AW',
 'AY': 'OHIY OHIH AY', 'EH': 'EH EYRR EHLE', 'ER': 'AXRR RR', 'EY': 'EY EYIY EYRR', 'IH': 'IH IY IYRR',
 'IY': 'IY IH IYRR', 'OW': 'OW OWWW OWRR', 'OY': 'OWIY', 'UH': 'UH UW', 'UW': 'UW IYUW IHWW',
 'B': 'BE BO EB OB', 'D': 'DE DO ED OD', 'G': 'GE GO EG OG', 'K': 'KE KO EK OK', 'P': 'PE PO',
 'T': 'TT TU TS', 'S': 'SE SO TS', 'HH': 'HE HO', 'N': 'NE NO', 'NG': 'NGE NGO', 'L': 'LE LO EHLE',
 'M': 'MM', 'R': 'RR', 'W': 'WW WH', 'Y': 'IYEH IY', 'CH': 'CH', 'JH': 'JH', 'DH': 'DH', 'TH': 'TH',
 'SH': 'SH', 'ZH': 'ZH', 'Z': 'ZZ', 'V': 'VV', 'F': 'FF'}
SEED = {k: set(v.split()) for k, v in SEED.items()}
FRONT = {'IY', 'IH', 'EY', 'EH', 'AE'}
BACK = {'AA', 'AO', 'OW', 'UH', 'UW', 'AH', 'AW', 'AY', 'OY', 'ER'}

def base(p): return re.sub(r'\d', '', p)
def pclass(p):
    b = base(p)
    return '#' if p == '#' else 'F' if b in FRONT else 'B' if b in BACK else 'C'

# ---------------------------------------------------------------- loading
def load_sensory(path):
    src = open(path, encoding='utf-8').read()
    words = dict(re.findall(r'_dict_standard_word_(\d+)\[\] = "([^"]*)"', src))
    codes = {words[k]: [int(x) for x in v.split(',')][:-1]
             for k, v in re.findall(r'_dict_standard_code_(\d+)\[\] = \{([^}]*)\}', src)}
    return codes

def units(codes):
    """Split a code array into units: (modifier prefix, allophone). None if it
    contains anything a word shouldn't (commands with arguments, sound effects)."""
    out, pre = [], []
    for c in codes:
        if c in ARGCMD or c >= 200 or 9 <= c <= 13 or c in (16, 17, 19, 27, 31): return None
        if c in MODS: pre.append(c); continue
        if 128 <= c <= 199: out.append((tuple(pre), C2A[c])); pre = []
    if pre: return None
    return out

def load_cmu(path):
    d = {}
    for line in open(path, encoding='latin-1'):
        parts = line.split('#')[0].split()
        if len(parts) < 2 or '(' in parts[0]: continue
        if not re.fullmatch(r"[a-z']+", parts[0]): continue
        d[parts[0]] = parts[1:]
    return d

# ---------------------------------------------------------------- alignment
MAXK = 3
def align(ph, un, cost):
    """Monotonic alignment: each phoneme takes 0..MAXK consecutive units.
    Returns list of unit-tuples, one per phoneme, or None."""
    n, m = len(ph), len(un)
    INF = float('inf')
    best = [[INF] * (m + 1) for _ in range(n + 1)]
    back = [[0] * (m + 1) for _ in range(n + 1)]
    best[0][0] = 0.0
    for i in range(n):
        for j in range(m + 1):
            if best[i][j] == INF: continue
            for k in range(0, MAXK + 1):
                if j + k > m: break
                c = best[i][j] + cost(ph[i], tuple(a for _, a in un[j:j + k]))
                if c < best[i + 1][j + k]:
                    best[i + 1][j + k] = c; back[i + 1][j + k] = k
    if best[n][m] == INF: return None
    segs, j = [], m
    for i in range(n, 0, -1):
        k = back[i][j]; segs.append(tuple(un[j - k:j])); j -= k
    return segs[::-1]

def seed_cost(p, seq):
    b = base(p)
    if not seq: return 2.5
    return sum(0.0 if a in SEED.get(b, ()) else 3.0 for a in seq) + 0.5 * (len(seq) - 1)

def train_alignments(pairs, iters=4):
    cost = seed_cost
    for _ in range(iters):
        counts = collections.defaultdict(collections.Counter)
        aligned = []
        for w, ph, un in pairs:
            segs = align(ph, un, cost)
            if segs is None: continue
            aligned.append((w, ph, segs))
            for p, s in zip(ph, segs):
                counts[base(p)][tuple(a for _, a in s)] += 1
        def cost(p, seq, counts=counts):
            c = counts[base(p)]; tot = sum(c.values())
            if c[seq]: return -math.log(c[seq] / (tot + 1.0))
            return 4.0 + seed_cost(p, seq)             # unseen: back off to the seed, penalised
    return aligned

# ---------------------------------------------------------------- the model
class Model:
    LEVELS = [lambda p, pv, nx: (p, pv, nx),
              lambda p, pv, nx: (p, nx),
              lambda p, pv, nx: (p, pclass(pv), pclass(nx)),
              lambda p, pv, nx: (p, pv),
              lambda p, pv, nx: (p, pclass(nx)),
              lambda p, pv, nx: (p,),
              lambda p, pv, nx: (base(p), base(nx)),
              lambda p, pv, nx: (base(p),)]
    MINCOUNT = [2, 2, 2, 2, 1, 1, 1, 1]

    def __init__(self, aligned):
        self.tables = [collections.defaultdict(collections.Counter) for _ in self.LEVELS]
        for w, ph, segs in aligned:
            for i, (p, s) in enumerate(zip(ph, segs)):
                pv = base(ph[i - 1]) if i > 0 else '#'
                nx = base(ph[i + 1]) if i + 1 < len(ph) else '#'
                for L, t in zip(self.LEVELS, self.tables):
                    t[L(p, pv, nx)][s] += 1

    def convert(self, ph):
        out = []
        for i, p in enumerate(ph):
            pv = base(ph[i - 1]) if i > 0 else '#'
            nx = base(ph[i + 1]) if i + 1 < len(ph) else '#'
            for L, t, mc in zip(self.LEVELS, self.tables, self.MINCOUNT):
                c = t.get(L(p, pv, nx))
                if c and sum(c.values()) >= mc:
                    out.extend(c.most_common(1)[0][0]); break
            else:
                out.append(((), sorted(SEED[base(p)])[0]))
        # A trailing modifier-less word is fine; make sure no dangling modifiers.
        codes = []
        for pre, a in out:
            codes.extend(pre); codes.append(A2C[a])
        return codes

# ---------------------------------------------------------------- evaluation
def edit(a, b):
    d = list(range(len(b) + 1))
    for i in range(1, len(a) + 1):
        prev, d[0] = d[0], i
        for j in range(1, len(b) + 1):
            prev, d[j] = d[j], min(d[j] + 1, d[j - 1] + 1, prev + (a[i - 1] != b[j - 1]))
    return d[len(b)]

NAIVE = dict(AA='AW', AE='AY', AO='OH', AW='AXUW', AY='OHIY', EH='EH', ER='AXRR', EY='EY', IH='IH',
             IY='IY', OW='OW', OY='OWIY', UH='UH', UW='UW', B='BO', CH='CH', D='DO', DH='DH', F='FF',
             G='GO', HH='HO', JH='JH', K='KO', L='LO', M='MM', N='NO', NG='NGO', P='PO', R='RR', S='SO',
             SH='SH', T='TT', TH='TH', V='VV', W='WW', Y='IYEH', Z='ZZ', ZH='ZH')
def naive(ph):
    return [A2C['AX' if p == 'AH0' else 'UX' if base(p) == 'AH' else NAIVE[base(p)]] for p in ph]

def allo_only(codes): return [c for c in codes if c >= 128]

def evaluate(pairs, folds=5):
    random.seed(7)
    order = pairs[:]; random.shuffle(order)
    res = collections.defaultdict(list)
    for f in range(folds):
        test = order[f::folds]; train = [x for i, x in enumerate(order) if i % folds != f]
        model = Model(train_alignments(train))
        for w, ph, un in test:
            ref = [c for pre, a in un for c in list(pre) + [A2C[a]]]
            for name, hyp in (('naive', naive(ph)), ('learned', model.convert(ph))):
                res[name, 'codes_exact'].append(hyp == ref)
                res[name, 'codes_ed'].append(edit(hyp, ref) / len(ref))
                ra, ha = allo_only(ref), allo_only(hyp)
                res[name, 'allo_exact'].append(ha == ra)
                res[name, 'allo_ed'].append(edit(ha, ra) / len(ra))
    n = len(res['naive', 'codes_exact'])
    print("5-fold cross-validation over %d Sensory words (each scored by a model that never saw it)\n" % n)
    print("                      allophones only           full codes incl. modifiers")
    print("                      exact    differing        exact    differing")
    for name in ('naive', 'learned'):
        m = lambda k: 100.0 * sum(res[name, k]) / n
        print("  %-18s  %4.0f%%     %4.0f%%          %4.0f%%     %4.0f%%" %
              (name, m('allo_exact'), m('allo_ed'), m('codes_exact'), m('codes_ed')))

# ---------------------------------------------------------------- generation
def build_pairs(sensory, cmu):
    pairs = []
    for w, codes in sensory.items():
        if w.startswith('fx') or w not in cmu: continue
        un = units(codes)
        if un: pairs.append((w, cmu[w], un))
    return pairs

def extradict_words(path):
    try: return set(re.findall(r'\{\s*"([^"]+)",\s*xd_', open(path, encoding='utf-8').read()))
    except FileNotFoundError: return set()

def generate(n_words, sensory, cmu, pairs):
    from wordfreq import top_n_list
    model = Model(train_alignments(pairs))
    skip = set(sensory) | extradict_words(os.path.join(HERE, 'extradict.h'))
    chosen, ranked = [], top_n_list('en', n_words * 4)
    for w in ranked:
        if w in skip or w not in cmu or not re.fullmatch(r"[a-z']+", w): continue
        codes = model.convert(cmu[w])
        if len(codes) > 56: continue                   # SpeakJet buffer budget per note
        chosen.append((w, codes))
        if len(chosen) == n_words: break
    chosen.sort(key=lambda e: e[0].encode('ascii'))   # byte order == device compare order
    data, index = bytearray(), []
    for w, codes in chosen:
        index.append(len(data))
        data += w.encode('ascii') + b'\0' + bytes(codes) + b'\xff'
    write_outputs(chosen, data, index, len(ranked))
    return chosen

def write_outputs(chosen, data, index, ranked_n):
    def rows(vals, per=24):
        vals = list(vals)
        return '\n'.join('  ' + ','.join(str(v) for v in vals[i:i + per]) + ',' for i in range(0, len(vals), per))
    head = """// bigdict.h / bigdict.cpp — GENERATED by cmu2bigdict.py. Do not edit by hand:
// override a word by adding it to extradict.h, which is searched first.
//
// %d words: the most frequent English words (wordfreq ranking) that are in
// CMUdict and NOT already in standardDict.cpp or extradict.h. Pronunciations
// are CMUdict's, converted to SpeakJet codes by a model learned from Sensory's
// hand-tuned dictionary. Sources: CMUdict (BSD), wordfreq (Apache-2.0).
//
// FORMAT. BIGDICT_DATA holds entries back to back:  word bytes, 0, codes, 255.
// BIGDICT_INDEX[i] is the offset of entry i. Entries are sorted by the raw
// bytes of the lowercase word, so a binary search comparing lowercase bytes
// finds them. Every entry is <= 56 codes.
""" % len(chosen)
    h = head + """
#ifndef BIGDICT_H
#define BIGDICT_H
#include <stdint.h>
extern const uint32_t BIGDICT_COUNT;
extern const uint32_t BIGDICT_INDEX[];
extern const uint8_t  BIGDICT_DATA[];
#endif
"""
    cpp = head + """
#include "bigdict.h"
const uint32_t BIGDICT_COUNT = %d;
const uint32_t BIGDICT_INDEX[] = {
%s
};
const uint8_t BIGDICT_DATA[] = {
%s
};
""" % (len(chosen), rows(index, 12), rows(data, 32))
    open(os.path.join(HERE, 'bigdict.h'), 'w').write(h)
    open(os.path.join(HERE, 'bigdict.cpp'), 'w').write(cpp)
    print("wrote bigdict.cpp/.h: %d words, %d data bytes + %d index bytes = %.0f KB flash"
          % (len(chosen), len(data), 4 * len(index), (len(data) + 4 * len(index)) / 1024))

if __name__ == '__main__':
    sensory = load_sensory(os.path.join(HERE, 'standardDict.cpp'))
    cmu = load_cmu(os.path.join(HERE, 'cmudict.dict'))
    pairs = build_pairs(sensory, cmu)
    if '--eval' in sys.argv:
        evaluate(pairs)
    else:
        n = int(sys.argv[1]) if len(sys.argv) > 1 else 30000
        generate(n, sensory, cmu, pairs)
