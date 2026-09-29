// dict.h — minimal replacement for the parts of SpeakJet.h that standardDict.cpp
// actually needs. Lets us use the library's 1427-word dictionary DATA without
// pulling in its SoftwareSerial-based speaking CODE, which conflicts with this
// project's hardware UART / non-blocking / one-token-per-note design.

#ifndef DICT_H
#define DICT_H

#include <Arduino.h>

// Same layout as SpeakJet::DictionaryEntry.
// The table is terminated by an entry with both pointers null.
typedef struct {
  const char    *word;    // ASCII, lowercase
  const uint8_t *codes;   // SpeakJet codes, terminated by 255 (EndOfPhrase)
} DictionaryEntry;

extern const DictionaryEntry _dict_standard[];

// NOTE ON PROGMEM: standardDict.cpp is littered with PROGMEM markers, which
// matter on AVR where flash is a separate address space needing pgm_read_*.
// On RP2350 flash is memory-mapped, PROGMEM is a no-op, and ordinary pointer
// dereferencing works. So we read the dictionary directly — no pgm_read_byte,
// no strcmp_P. The markers are left in place purely to keep the diff against
// the original file minimal.

#endif
