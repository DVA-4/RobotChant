// standardDict.cpp — 1427-word dictionary from Mike McCauley's SpeakJet library
// (converted by his convertDict.pl from SpeakJet's own PhraseALator.Dic).
//
// MODIFIED FOR THIS PROJECT — two changes only, data untouched:
//   1. #include <SpeakJet.h>  ->  #include "dict.h"
//   2. SpeakJet::DictionaryEntry -> DictionaryEntry, and dropped the stray
//      'extern' on a definition with an initialiser.
// We take the library's DATA but not its CODE: its speaking machinery uses
// SoftwareSerial, blocking per-code RDY polling, and speak-a-whole-string,
// all of which conflict with this project's hardware UART + non-blocking
// FIFO writes + one-token-per-note design.
// SpeakJet library dictionary file
// created by:
// convertDict.pl -name standard PhraseALator.Dic
// You probably dont want to edit this by hand, but instead alter the .dic file
// and rerun the converter
//
#include "dict.h"
PROGMEM const char _dict_standard_word_0[] = "a";
PROGMEM const uint8_t _dict_standard_code_0[] = { 154, 128, 255 };
PROGMEM const char _dict_standard_word_1[] = "able";
PROGMEM const uint8_t _dict_standard_code_1[] = { 7, 154, 171, 138, 145, 255 };
PROGMEM const char _dict_standard_word_2[] = "about";
PROGMEM const uint8_t _dict_standard_code_2[] = { 134, 173, 163, 191, 255 };
PROGMEM const char _dict_standard_word_3[] = "across";
PROGMEM const uint8_t _dict_standard_code_3[] = { 133, 196, 7, 148, 135, 187, 187, 255 };
PROGMEM const char _dict_standard_word_4[] = "act";
PROGMEM const uint8_t _dict_standard_code_4[] = { 132, 196, 191, 255 };
PROGMEM const char _dict_standard_word_5[] = "acting";
PROGMEM const uint8_t _dict_standard_code_5[] = { 132, 196, 191, 14, 129, 143, 255 };
PROGMEM const char _dict_standard_word_6[] = "activated";
PROGMEM const uint8_t _dict_standard_code_6[] = { 132, 194, 191, 7, 129, 166, 7, 154, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_7[] = "add";
PROGMEM const uint8_t _dict_standard_code_7[] = { 132, 132, 176, 255 };
PROGMEM const char _dict_standard_word_8[] = "address";
PROGMEM const uint8_t _dict_standard_code_8[] = { 8, 132, 176, 7, 148, 131, 8, 187, 255 };
PROGMEM const char _dict_standard_word_9[] = "adorn";
PROGMEM const uint8_t _dict_standard_code_9[] = { 8, 133, 175, 7, 153, 141, 255 };
PROGMEM const char _dict_standard_word_10[] = "afraid";
PROGMEM const uint8_t _dict_standard_code_10[] = { 133, 186, 7, 148, 154, 176, 255 };
PROGMEM const char _dict_standard_word_11[] = "after";
PROGMEM const uint8_t _dict_standard_code_11[] = { 132, 186, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_12[] = "afternoon";
PROGMEM const uint8_t _dict_standard_code_12[] = { 132, 186, 7, 191, 7, 151, 7, 141, 139, 8, 141, 255 };
PROGMEM const char _dict_standard_word_13[] = "again";
PROGMEM const uint8_t _dict_standard_code_13[] = { 133, 178, 8, 130, 141, 255 };
PROGMEM const char _dict_standard_word_14[] = "against";
PROGMEM const uint8_t _dict_standard_code_14[] = { 133, 178, 130, 141, 187, 8, 191, 255 };
PROGMEM const char _dict_standard_word_15[] = "air";
PROGMEM const uint8_t _dict_standard_code_15[] = { 150, 255 };
PROGMEM const char _dict_standard_word_16[] = "airplane";
PROGMEM const uint8_t _dict_standard_code_16[] = { 150, 199, 7, 145, 154, 141, 255 };
PROGMEM const char _dict_standard_word_17[] = "alarm";
PROGMEM const uint8_t _dict_standard_code_17[] = { 8, 134, 145, 152, 140, 255 };
PROGMEM const char _dict_standard_word_18[] = "alert";
PROGMEM const uint8_t _dict_standard_code_18[] = { 133, 145, 151, 191, 255 };
PROGMEM const char _dict_standard_word_19[] = "alien";
PROGMEM const uint8_t _dict_standard_code_19[] = { 7, 130, 7, 154, 145, 128, 8, 7, 133, 141, 255 };
PROGMEM const char _dict_standard_word_20[] = "alive";
PROGMEM const uint8_t _dict_standard_code_20[] = { 134, 145, 7, 135, 7, 155, 166, 255 };
PROGMEM const char _dict_standard_word_21[] = "all";
PROGMEM const uint8_t _dict_standard_code_21[] = { 8, 136, 8, 146, 255 };
PROGMEM const char _dict_standard_word_22[] = "alligator";
PROGMEM const uint8_t _dict_standard_code_22[] = { 132, 145, 7, 129, 178, 15, 154, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_23[] = "almost";
PROGMEM const uint8_t _dict_standard_code_23[] = { 135, 7, 146, 140, 14, 137, 188, 191, 255 };
PROGMEM const char _dict_standard_word_24[] = "alone";
PROGMEM const uint8_t _dict_standard_code_24[] = { 134, 146, 137, 137, 8, 141, 255 };
PROGMEM const char _dict_standard_word_25[] = "along";
PROGMEM const uint8_t _dict_standard_code_25[] = { 134, 146, 135, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_26[] = "alpha";
PROGMEM const uint8_t _dict_standard_code_26[] = { 132, 145, 7, 186, 134, 255 };
PROGMEM const char _dict_standard_word_27[] = "alphabet";
PROGMEM const uint8_t _dict_standard_code_27[] = { 132, 146, 7, 186, 7, 133, 14, 18, 170, 130, 8, 191, 255 };
PROGMEM const char _dict_standard_word_28[] = "already";
PROGMEM const uint8_t _dict_standard_code_28[] = { 136, 145, 7, 148, 130, 174, 128, 255 };
PROGMEM const char _dict_standard_word_29[] = "also";
PROGMEM const uint8_t _dict_standard_code_29[] = { 8, 136, 8, 146, 8, 188, 164, 255 };
PROGMEM const char _dict_standard_word_30[] = "although";
PROGMEM const uint8_t _dict_standard_code_30[] = { 7, 135, 8, 146, 169, 8, 164, 255 };
PROGMEM const char _dict_standard_word_31[] = "always";
PROGMEM const uint8_t _dict_standard_code_31[] = { 8, 136, 145, 147, 154, 8, 187, 255 };
PROGMEM const char _dict_standard_word_32[] = "am";
PROGMEM const uint8_t _dict_standard_code_32[] = { 132, 132, 140, 255 };
PROGMEM const char _dict_standard_word_33[] = "among";
PROGMEM const uint8_t _dict_standard_code_33[] = { 15, 134, 140, 134, 144, 255 };
PROGMEM const char _dict_standard_word_34[] = "ample";
PROGMEM const uint8_t _dict_standard_code_34[] = { 8, 132, 7, 140, 199, 134, 146, 255 };
PROGMEM const char _dict_standard_word_35[] = "an";
PROGMEM const uint8_t _dict_standard_code_35[] = { 132, 132, 141, 255 };
PROGMEM const char _dict_standard_word_36[] = "anchor";
PROGMEM const uint8_t _dict_standard_code_36[] = { 7, 154, 143, 194, 148, 255 };
PROGMEM const char _dict_standard_word_37[] = "and";
PROGMEM const uint8_t _dict_standard_code_37[] = { 8, 132, 8, 141, 177, 255 };
PROGMEM const char _dict_standard_word_38[] = "anger";
PROGMEM const uint8_t _dict_standard_code_38[] = { 7, 154, 7, 128, 7, 141, 178, 133, 148, 255 };
PROGMEM const char _dict_standard_word_39[] = "angle";
PROGMEM const uint8_t _dict_standard_code_39[] = { 154, 143, 145, 255 };
PROGMEM const char _dict_standard_word_40[] = "animal";
PROGMEM const uint8_t _dict_standard_code_40[] = { 8, 132, 141, 7, 129, 140, 8, 145, 255 };
PROGMEM const char _dict_standard_word_41[] = "another";
PROGMEM const uint8_t _dict_standard_code_41[] = { 134, 141, 134, 169, 151, 255 };
PROGMEM const char _dict_standard_word_42[] = "answer";
PROGMEM const uint8_t _dict_standard_code_42[] = { 132, 141, 8, 187, 151, 255 };
PROGMEM const char _dict_standard_word_43[] = "ant";
PROGMEM const uint8_t _dict_standard_code_43[] = { 8, 132, 141, 191, 255 };
PROGMEM const char _dict_standard_word_44[] = "any";
PROGMEM const uint8_t _dict_standard_code_44[] = { 14, 130, 141, 128, 128, 255 };
PROGMEM const char _dict_standard_word_45[] = "apart";
PROGMEM const uint8_t _dict_standard_code_45[] = { 134, 14, 199, 152, 191, 255 };
PROGMEM const char _dict_standard_word_46[] = "apartment";
PROGMEM const uint8_t _dict_standard_code_46[] = { 134, 14, 199, 7, 152, 191, 140, 130, 141, 191, 255 };
PROGMEM const char _dict_standard_word_47[] = "ape";
PROGMEM const uint8_t _dict_standard_code_47[] = { 154, 199, 255 };
PROGMEM const char _dict_standard_word_48[] = "appear";
PROGMEM const uint8_t _dict_standard_code_48[] = { 134, 8, 198, 149, 255 };
PROGMEM const char _dict_standard_word_49[] = "apple";
PROGMEM const uint8_t _dict_standard_code_49[] = { 132, 199, 8, 138, 145, 255 };
PROGMEM const char _dict_standard_word_50[] = "april";
PROGMEM const uint8_t _dict_standard_code_50[] = { 154, 198, 148, 145, 255 };
PROGMEM const char _dict_standard_word_51[] = "are";
PROGMEM const uint8_t _dict_standard_code_51[] = { 152, 255 };
PROGMEM const char _dict_standard_word_52[] = "arm";
PROGMEM const uint8_t _dict_standard_code_52[] = { 152, 140, 255 };
PROGMEM const char _dict_standard_word_53[] = "army";
PROGMEM const uint8_t _dict_standard_code_53[] = { 7, 136, 148, 140, 128, 255 };
PROGMEM const char _dict_standard_word_54[] = "around";
PROGMEM const uint8_t _dict_standard_code_54[] = { 134, 7, 148, 163, 141, 177, 255 };
PROGMEM const char _dict_standard_word_55[] = "arrow";
PROGMEM const uint8_t _dict_standard_code_55[] = { 150, 164, 255 };
PROGMEM const char _dict_standard_word_56[] = "art";
PROGMEM const uint8_t _dict_standard_code_56[] = { 152, 191, 255 };
PROGMEM const char _dict_standard_word_57[] = "as";
PROGMEM const uint8_t _dict_standard_code_57[] = { 132, 8, 167, 255 };
PROGMEM const char _dict_standard_word_58[] = "ask";
PROGMEM const uint8_t _dict_standard_code_58[] = { 8, 132, 8, 187, 196, 255 };
PROGMEM const char _dict_standard_word_59[] = "asleep";
PROGMEM const uint8_t _dict_standard_code_59[] = { 133, 8, 187, 145, 128, 7, 198, 255 };
PROGMEM const char _dict_standard_word_60[] = "ass";
PROGMEM const uint8_t _dict_standard_code_60[] = { 132, 132, 8, 187, 255 };
PROGMEM const char _dict_standard_word_61[] = "astronaut";
PROGMEM const uint8_t _dict_standard_code_61[] = { 132, 187, 4, 191, 7, 148, 7, 137, 7, 142, 135, 191, 255 };
PROGMEM const char _dict_standard_word_62[] = "at";
PROGMEM const uint8_t _dict_standard_code_62[] = { 132, 8, 191, 255 };
PROGMEM const char _dict_standard_word_63[] = "ate";
PROGMEM const uint8_t _dict_standard_code_63[] = { 154, 191, 255 };
PROGMEM const char _dict_standard_word_64[] = "aught";
PROGMEM const uint8_t _dict_standard_code_64[] = { 8, 136, 8, 191, 255 };
PROGMEM const char _dict_standard_word_65[] = "august";
PROGMEM const uint8_t _dict_standard_code_65[] = { 8, 136, 179, 133, 187, 191, 255 };
PROGMEM const char _dict_standard_word_66[] = "aunt";
PROGMEM const uint8_t _dict_standard_code_66[] = { 135, 141, 191, 255 };
PROGMEM const char _dict_standard_word_67[] = "automobile";
PROGMEM const uint8_t _dict_standard_code_67[] = { 8, 136, 191, 7, 164, 7, 140, 7, 164, 18, 170, 128, 145, 255 };
PROGMEM const char _dict_standard_word_68[] = "autumn";
PROGMEM const uint8_t _dict_standard_code_68[] = { 135, 191, 133, 140, 140, 255 };
PROGMEM const char _dict_standard_word_69[] = "avenue";
PROGMEM const uint8_t _dict_standard_code_69[] = { 132, 166, 130, 141, 160, 255 };
PROGMEM const char _dict_standard_word_70[] = "awake";
PROGMEM const uint8_t _dict_standard_code_70[] = { 134, 147, 154, 194, 255 };
PROGMEM const char _dict_standard_word_71[] = "away";
PROGMEM const uint8_t _dict_standard_code_71[] = { 133, 147, 154, 255 };
PROGMEM const char _dict_standard_word_72[] = "ax";
PROGMEM const uint8_t _dict_standard_code_72[] = { 132, 132, 196, 187, 255 };
PROGMEM const char _dict_standard_word_73[] = "azure";
PROGMEM const uint8_t _dict_standard_code_73[] = { 8, 133, 168, 7, 162, 148, 255 };
PROGMEM const char _dict_standard_word_74[] = "b";
PROGMEM const uint8_t _dict_standard_code_74[] = { 170, 128, 128, 255 };
PROGMEM const char _dict_standard_word_75[] = "babblebot";
PROGMEM const uint8_t _dict_standard_code_75[] = { 170, 132, 173, 8, 146, 171, 136, 191, 255 };
PROGMEM const char _dict_standard_word_76[] = "baby";
PROGMEM const uint8_t _dict_standard_code_76[] = { 170, 154, 172, 128, 255 };
PROGMEM const char _dict_standard_word_77[] = "back";
PROGMEM const uint8_t _dict_standard_code_77[] = { 170, 8, 132, 4, 196, 255 };
PROGMEM const char _dict_standard_word_78[] = "bad";
PROGMEM const uint8_t _dict_standard_code_78[] = { 170, 132, 132, 176, 255 };
PROGMEM const char _dict_standard_word_79[] = "bag";
PROGMEM const uint8_t _dict_standard_code_79[] = { 170, 132, 132, 180, 255 };
PROGMEM const char _dict_standard_word_80[] = "bake";
PROGMEM const uint8_t _dict_standard_code_80[] = { 170, 154, 194, 255 };
PROGMEM const char _dict_standard_word_81[] = "ball";
PROGMEM const uint8_t _dict_standard_code_81[] = { 171, 8, 135, 146, 255 };
PROGMEM const char _dict_standard_word_82[] = "balloon";
PROGMEM const uint8_t _dict_standard_code_82[] = { 171, 7, 134, 145, 139, 139, 141, 255 };
PROGMEM const char _dict_standard_word_83[] = "banana";
PROGMEM const uint8_t _dict_standard_code_83[] = { 171, 7, 134, 141, 132, 141, 133, 255 };
PROGMEM const char _dict_standard_word_84[] = "band";
PROGMEM const uint8_t _dict_standard_code_84[] = { 170, 8, 132, 141, 177, 255 };
PROGMEM const char _dict_standard_word_85[] = "basic";
PROGMEM const uint8_t _dict_standard_code_85[] = { 170, 154, 187, 129, 7, 4, 197, 255 };
PROGMEM const char _dict_standard_word_86[] = "bathe";
PROGMEM const uint8_t _dict_standard_code_86[] = { 170, 154, 169, 255 };
PROGMEM const char _dict_standard_word_87[] = "bather";
PROGMEM const uint8_t _dict_standard_code_87[] = { 170, 154, 169, 7, 151, 255 };
PROGMEM const char _dict_standard_word_88[] = "bathing";
PROGMEM const uint8_t _dict_standard_code_88[] = { 170, 154, 169, 129, 143, 255 };
PROGMEM const char _dict_standard_word_89[] = "beast";
PROGMEM const uint8_t _dict_standard_code_89[] = { 170, 128, 187, 191, 255 };
PROGMEM const char _dict_standard_word_90[] = "beauty";
PROGMEM const uint8_t _dict_standard_code_90[] = { 170, 160, 191, 128, 255 };
PROGMEM const char _dict_standard_word_91[] = "beer";
PROGMEM const uint8_t _dict_standard_code_91[] = { 170, 149, 255 };
PROGMEM const char _dict_standard_word_92[] = "beige";
PROGMEM const uint8_t _dict_standard_code_92[] = { 170, 130, 154, 165, 255 };
PROGMEM const char _dict_standard_word_93[] = "below";
PROGMEM const uint8_t _dict_standard_code_93[] = { 170, 128, 145, 164, 255 };
PROGMEM const char _dict_standard_word_94[] = "beta";
PROGMEM const uint8_t _dict_standard_code_94[] = { 170, 154, 191, 134, 255 };
PROGMEM const char _dict_standard_word_95[] = "bib";
PROGMEM const uint8_t _dict_standard_code_95[] = { 170, 129, 129, 172, 255 };
PROGMEM const char _dict_standard_word_96[] = "bird";
PROGMEM const uint8_t _dict_standard_code_96[] = { 7, 18, 170, 151, 176, 255 };
PROGMEM const char _dict_standard_word_97[] = "blast";
PROGMEM const uint8_t _dict_standard_code_97[] = { 171, 145, 132, 187, 191, 255 };
PROGMEM const char _dict_standard_word_98[] = "bleed";
PROGMEM const uint8_t _dict_standard_code_98[] = { 171, 145, 128, 174, 255 };
PROGMEM const char _dict_standard_word_99[] = "blue";
PROGMEM const uint8_t _dict_standard_code_99[] = { 171, 7, 146, 162, 255 };
PROGMEM const char _dict_standard_word_100[] = "bong";
PROGMEM const uint8_t _dict_standard_code_100[] = { 171, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_101[] = "book";
PROGMEM const uint8_t _dict_standard_code_101[] = { 171, 8, 138, 197, 255 };
PROGMEM const char _dict_standard_word_102[] = "bot";
PROGMEM const uint8_t _dict_standard_code_102[] = { 171, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_103[] = "boy";
PROGMEM const uint8_t _dict_standard_code_103[] = { 171, 156, 255 };
PROGMEM const char _dict_standard_word_104[] = "brain";
PROGMEM const uint8_t _dict_standard_code_104[] = { 171, 7, 148, 154, 141, 255 };
PROGMEM const char _dict_standard_word_105[] = "bread";
PROGMEM const uint8_t _dict_standard_code_105[] = { 7, 18, 170, 148, 8, 131, 176, 255 };
PROGMEM const char _dict_standard_word_106[] = "bright";
PROGMEM const uint8_t _dict_standard_code_106[] = { 171, 7, 148, 155, 191, 255 };
PROGMEM const char _dict_standard_word_107[] = "brightly";
PROGMEM const uint8_t _dict_standard_code_107[] = { 171, 7, 148, 155, 191, 145, 128, 255 };
PROGMEM const char _dict_standard_word_108[] = "broom";
PROGMEM const uint8_t _dict_standard_code_108[] = { 171, 7, 148, 8, 139, 140, 255 };
PROGMEM const char _dict_standard_word_109[] = "brooms";
PROGMEM const uint8_t _dict_standard_code_109[] = { 171, 7, 148, 8, 139, 140, 187, 255 };
PROGMEM const char _dict_standard_word_110[] = "brown";
PROGMEM const uint8_t _dict_standard_code_110[] = { 171, 7, 148, 161, 141, 255 };
PROGMEM const char _dict_standard_word_111[] = "brush";
PROGMEM const uint8_t _dict_standard_code_111[] = { 171, 7, 148, 8, 133, 189, 189, 255 };
PROGMEM const char _dict_standard_word_112[] = "burn";
PROGMEM const uint8_t _dict_standard_code_112[] = { 170, 151, 141, 255 };
PROGMEM const char _dict_standard_word_113[] = "business";
PROGMEM const uint8_t _dict_standard_code_113[] = { 170, 129, 167, 141, 129, 187, 255 };
PROGMEM const char _dict_standard_word_114[] = "by";
PROGMEM const uint8_t _dict_standard_code_114[] = { 171, 157, 255 };
PROGMEM const char _dict_standard_word_115[] = "c";
PROGMEM const uint8_t _dict_standard_code_115[] = { 187, 187, 128, 128, 255 };
PROGMEM const char _dict_standard_word_116[] = "cab";
PROGMEM const uint8_t _dict_standard_code_116[] = { 194, 132, 132, 172, 255 };
PROGMEM const char _dict_standard_word_117[] = "cake";
PROGMEM const uint8_t _dict_standard_code_117[] = { 194, 154, 15, 196, 255 };
PROGMEM const char _dict_standard_word_118[] = "calendar";
PROGMEM const uint8_t _dict_standard_code_118[] = { 194, 7, 132, 145, 131, 141, 175, 7, 151, 255 };
PROGMEM const char _dict_standard_word_119[] = "call";
PROGMEM const uint8_t _dict_standard_code_119[] = { 195, 8, 135, 146, 255 };
PROGMEM const char _dict_standard_word_120[] = "camel";
PROGMEM const uint8_t _dict_standard_code_120[] = { 194, 132, 140, 134, 145, 255 };
PROGMEM const char _dict_standard_word_121[] = "camp";
PROGMEM const uint8_t _dict_standard_code_121[] = { 194, 132, 140, 199, 255 };
PROGMEM const char _dict_standard_word_122[] = "can";
PROGMEM const uint8_t _dict_standard_code_122[] = { 194, 8, 132, 141, 255 };
PROGMEM const char _dict_standard_word_123[] = "candle";
PROGMEM const uint8_t _dict_standard_code_123[] = { 194, 8, 132, 141, 174, 159, 255 };
PROGMEM const char _dict_standard_word_124[] = "candy";
PROGMEM const uint8_t _dict_standard_code_124[] = { 194, 132, 141, 174, 8, 128, 255 };
PROGMEM const char _dict_standard_word_125[] = "cap";
PROGMEM const uint8_t _dict_standard_code_125[] = { 194, 8, 132, 199, 255 };
PROGMEM const char _dict_standard_word_126[] = "car";
PROGMEM const uint8_t _dict_standard_code_126[] = { 195, 8, 136, 148, 255 };
PROGMEM const char _dict_standard_word_127[] = "care";
PROGMEM const uint8_t _dict_standard_code_127[] = { 196, 130, 150, 255 };
PROGMEM const char _dict_standard_word_128[] = "carpet";
PROGMEM const uint8_t _dict_standard_code_128[] = { 195, 7, 152, 198, 129, 191, 255 };
PROGMEM const char _dict_standard_word_129[] = "carriage";
PROGMEM const uint8_t _dict_standard_code_129[] = { 196, 7, 150, 8, 129, 165, 255 };
PROGMEM const char _dict_standard_word_130[] = "carrot";
PROGMEM const uint8_t _dict_standard_code_130[] = { 196, 7, 150, 133, 191, 255 };
PROGMEM const char _dict_standard_word_131[] = "casual";
PROGMEM const uint8_t _dict_standard_code_131[] = { 194, 132, 168, 7, 162, 133, 145, 255 };
PROGMEM const char _dict_standard_word_132[] = "cat";
PROGMEM const uint8_t _dict_standard_code_132[] = { 194, 132, 191, 255 };
PROGMEM const char _dict_standard_word_133[] = "catch";
PROGMEM const uint8_t _dict_standard_code_133[] = { 194, 8, 132, 4, 182, 255 };
PROGMEM const char _dict_standard_word_134[] = "cent";
PROGMEM const uint8_t _dict_standard_code_134[] = { 187, 130, 141, 4, 191, 255 };
PROGMEM const char _dict_standard_word_135[] = "center";
PROGMEM const uint8_t _dict_standard_code_135[] = { 187, 130, 141, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_136[] = "certain";
PROGMEM const uint8_t _dict_standard_code_136[] = { 8, 187, 7, 151, 191, 131, 141, 255 };
PROGMEM const char _dict_standard_word_137[] = "chair";
PROGMEM const uint8_t _dict_standard_code_137[] = { 182, 150, 255 };
PROGMEM const char _dict_standard_word_138[] = "chalk";
PROGMEM const uint8_t _dict_standard_code_138[] = { 8, 182, 135, 7, 146, 197, 255 };
PROGMEM const char _dict_standard_word_139[] = "change";
PROGMEM const uint8_t _dict_standard_code_139[] = { 182, 154, 141, 165, 255 };
PROGMEM const char _dict_standard_word_140[] = "changeable";
PROGMEM const uint8_t _dict_standard_code_140[] = { 182, 7, 154, 7, 141, 7, 165, 133, 172, 134, 8, 145, 255 };
PROGMEM const char _dict_standard_word_141[] = "check";
PROGMEM const uint8_t _dict_standard_code_141[] = { 182, 131, 131, 196, 255 };
PROGMEM const char _dict_standard_word_142[] = "checked";
PROGMEM const uint8_t _dict_standard_code_142[] = { 182, 131, 131, 196, 191, 255 };
PROGMEM const char _dict_standard_word_143[] = "checker";
PROGMEM const uint8_t _dict_standard_code_143[] = { 182, 131, 131, 194, 133, 148, 255 };
PROGMEM const char _dict_standard_word_144[] = "checkers";
PROGMEM const uint8_t _dict_standard_code_144[] = { 182, 131, 131, 194, 133, 148, 167, 255 };
PROGMEM const char _dict_standard_word_145[] = "checking";
PROGMEM const uint8_t _dict_standard_code_145[] = { 182, 131, 131, 194, 129, 143, 255 };
PROGMEM const char _dict_standard_word_146[] = "checks";
PROGMEM const uint8_t _dict_standard_code_146[] = { 182, 131, 131, 194, 187, 255 };
PROGMEM const char _dict_standard_word_147[] = "cheek";
PROGMEM const uint8_t _dict_standard_code_147[] = { 182, 8, 128, 194, 255 };
PROGMEM const char _dict_standard_word_148[] = "cherry";
PROGMEM const uint8_t _dict_standard_code_148[] = { 8, 182, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_149[] = "chest";
PROGMEM const uint8_t _dict_standard_code_149[] = { 182, 131, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_150[] = "chests";
PROGMEM const uint8_t _dict_standard_code_150[] = { 182, 131, 131, 187, 193, 255 };
PROGMEM const char _dict_standard_word_151[] = "chi";
PROGMEM const uint8_t _dict_standard_code_151[] = { 195, 155, 255 };
PROGMEM const char _dict_standard_word_152[] = "chicken";
PROGMEM const uint8_t _dict_standard_code_152[] = { 182, 129, 194, 131, 141, 255 };
PROGMEM const char _dict_standard_word_153[] = "chip";
PROGMEM const uint8_t _dict_standard_code_153[] = { 182, 129, 129, 198, 255 };
PROGMEM const char _dict_standard_word_154[] = "chips";
PROGMEM const uint8_t _dict_standard_code_154[] = { 182, 129, 129, 198, 187, 255 };
PROGMEM const char _dict_standard_word_155[] = "church";
PROGMEM const uint8_t _dict_standard_code_155[] = { 182, 133, 148, 182, 255 };
PROGMEM const char _dict_standard_word_156[] = "circle";
PROGMEM const uint8_t _dict_standard_code_156[] = { 8, 188, 7, 151, 195, 138, 146, 255 };
PROGMEM const char _dict_standard_word_157[] = "circus";
PROGMEM const uint8_t _dict_standard_code_157[] = { 8, 188, 7, 151, 194, 133, 8, 188, 255 };
PROGMEM const char _dict_standard_word_158[] = "city";
PROGMEM const uint8_t _dict_standard_code_158[] = { 8, 187, 8, 129, 191, 128, 255 };
PROGMEM const char _dict_standard_word_159[] = "clap";
PROGMEM const uint8_t _dict_standard_code_159[] = { 195, 7, 145, 132, 199, 255 };
PROGMEM const char _dict_standard_word_160[] = "class";
PROGMEM const uint8_t _dict_standard_code_160[] = { 8, 195, 7, 145, 8, 132, 8, 187, 255 };
PROGMEM const char _dict_standard_word_161[] = "clean";
PROGMEM const uint8_t _dict_standard_code_161[] = { 8, 195, 7, 145, 8, 128, 141, 255 };
PROGMEM const char _dict_standard_word_162[] = "clear";
PROGMEM const uint8_t _dict_standard_code_162[] = { 8, 195, 7, 145, 149, 255 };
PROGMEM const char _dict_standard_word_163[] = "climb";
PROGMEM const uint8_t _dict_standard_code_163[] = { 8, 195, 7, 145, 157, 8, 140, 255 };
PROGMEM const char _dict_standard_word_164[] = "clock";
PROGMEM const uint8_t _dict_standard_code_164[] = { 8, 195, 7, 146, 8, 135, 197, 255 };
PROGMEM const char _dict_standard_word_165[] = "close";
PROGMEM const uint8_t _dict_standard_code_165[] = { 8, 195, 7, 145, 164, 7, 167, 255 };
PROGMEM const char _dict_standard_word_166[] = "closet";
PROGMEM const uint8_t _dict_standard_code_166[] = { 8, 195, 7, 146, 8, 135, 7, 167, 131, 191, 255 };
PROGMEM const char _dict_standard_word_167[] = "cloth";
PROGMEM const uint8_t _dict_standard_code_167[] = { 8, 195, 7, 145, 8, 135, 190, 190, 255 };
PROGMEM const char _dict_standard_word_168[] = "clothes";
PROGMEM const uint8_t _dict_standard_code_168[] = { 8, 195, 7, 145, 164, 7, 167, 255 };
PROGMEM const char _dict_standard_word_169[] = "cloud";
PROGMEM const uint8_t _dict_standard_code_169[] = { 8, 195, 7, 145, 163, 177, 255 };
PROGMEM const char _dict_standard_word_170[] = "clown";
PROGMEM const uint8_t _dict_standard_code_170[] = { 8, 195, 7, 145, 163, 142, 255 };
PROGMEM const char _dict_standard_word_171[] = "coat";
PROGMEM const uint8_t _dict_standard_code_171[] = { 195, 164, 191, 255 };
PROGMEM const char _dict_standard_word_172[] = "cob";
PROGMEM const uint8_t _dict_standard_code_172[] = { 195, 8, 135, 7, 4, 173, 255 };
PROGMEM const char _dict_standard_word_173[] = "cognitive";
PROGMEM const uint8_t _dict_standard_code_173[] = { 195, 135, 179, 7, 141, 7, 129, 191, 129, 166, 255 };
PROGMEM const char _dict_standard_word_174[] = "coin";
PROGMEM const uint8_t _dict_standard_code_174[] = { 197, 156, 141, 255 };
PROGMEM const char _dict_standard_word_175[] = "cold";
PROGMEM const uint8_t _dict_standard_code_175[] = { 197, 164, 146, 7, 175, 255 };
PROGMEM const char _dict_standard_word_176[] = "collide";
PROGMEM const uint8_t _dict_standard_code_176[] = { 195, 134, 145, 157, 176, 255 };
PROGMEM const char _dict_standard_word_177[] = "color";
PROGMEM const uint8_t _dict_standard_code_177[] = { 195, 8, 134, 146, 7, 151, 255 };
PROGMEM const char _dict_standard_word_178[] = "com";
PROGMEM const uint8_t _dict_standard_code_178[] = { 195, 135, 135, 140, 255 };
PROGMEM const char _dict_standard_word_179[] = "comb";
PROGMEM const uint8_t _dict_standard_code_179[] = { 195, 137, 140, 255 };
PROGMEM const char _dict_standard_word_180[] = "come";
PROGMEM const uint8_t _dict_standard_code_180[] = { 194, 8, 134, 140, 255 };
PROGMEM const char _dict_standard_word_181[] = "computer";
PROGMEM const uint8_t _dict_standard_code_181[] = { 194, 134, 140, 7, 198, 7, 160, 191, 133, 148, 255 };
PROGMEM const char _dict_standard_word_182[] = "computers";
PROGMEM const uint8_t _dict_standard_code_182[] = { 194, 134, 140, 7, 198, 7, 160, 191, 133, 148, 187, 255 };
PROGMEM const char _dict_standard_word_183[] = "contain";
PROGMEM const uint8_t _dict_standard_code_183[] = { 194, 133, 141, 191, 154, 141, 255 };
PROGMEM const char _dict_standard_word_184[] = "container";
PROGMEM const uint8_t _dict_standard_code_184[] = { 194, 133, 141, 191, 7, 154, 141, 7, 151, 255 };
PROGMEM const char _dict_standard_word_185[] = "cook";
PROGMEM const uint8_t _dict_standard_code_185[] = { 195, 8, 138, 195, 255 };
PROGMEM const char _dict_standard_word_186[] = "cookie";
PROGMEM const uint8_t _dict_standard_code_186[] = { 195, 8, 138, 194, 128, 255 };
PROGMEM const char _dict_standard_word_187[] = "cool";
PROGMEM const uint8_t _dict_standard_code_187[] = { 195, 8, 139, 145, 255 };
PROGMEM const char _dict_standard_word_188[] = "coop";
PROGMEM const uint8_t _dict_standard_code_188[] = { 194, 139, 139, 199, 255 };
PROGMEM const char _dict_standard_word_189[] = "copy";
PROGMEM const uint8_t _dict_standard_code_189[] = { 195, 8, 135, 198, 7, 128, 255 };
PROGMEM const char _dict_standard_word_190[] = "core";
PROGMEM const uint8_t _dict_standard_code_190[] = { 195, 8, 153, 255 };
PROGMEM const char _dict_standard_word_191[] = "cork";
PROGMEM const uint8_t _dict_standard_code_191[] = { 195, 153, 196, 255 };
PROGMEM const char _dict_standard_word_192[] = "corn";
PROGMEM const uint8_t _dict_standard_code_192[] = { 195, 153, 142, 255 };
PROGMEM const char _dict_standard_word_193[] = "corner";
PROGMEM const uint8_t _dict_standard_code_193[] = { 195, 7, 153, 141, 7, 151, 255 };
PROGMEM const char _dict_standard_word_194[] = "corona";
PROGMEM const uint8_t _dict_standard_code_194[] = { 195, 137, 148, 137, 142, 133, 255 };
PROGMEM const char _dict_standard_word_195[] = "correct";
PROGMEM const uint8_t _dict_standard_code_195[] = { 195, 153, 131, 196, 191, 255 };
PROGMEM const char _dict_standard_word_196[] = "corrected";
PROGMEM const uint8_t _dict_standard_code_196[] = { 195, 153, 131, 196, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_197[] = "correcting";
PROGMEM const uint8_t _dict_standard_code_197[] = { 195, 153, 131, 196, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_198[] = "corrects";
PROGMEM const uint8_t _dict_standard_code_198[] = { 195, 153, 131, 196, 193, 255 };
PROGMEM const char _dict_standard_word_199[] = "cost";
PROGMEM const uint8_t _dict_standard_code_199[] = { 195, 8, 136, 187, 191, 255 };
PROGMEM const char _dict_standard_word_200[] = "costs";
PROGMEM const uint8_t _dict_standard_code_200[] = { 195, 8, 136, 187, 193, 255 };
PROGMEM const char _dict_standard_word_201[] = "cotton";
PROGMEM const uint8_t _dict_standard_code_201[] = { 195, 8, 135, 191, 133, 141, 255 };
PROGMEM const char _dict_standard_word_202[] = "could";
PROGMEM const uint8_t _dict_standard_code_202[] = { 195, 138, 138, 177, 255 };
PROGMEM const char _dict_standard_word_203[] = "count";
PROGMEM const uint8_t _dict_standard_code_203[] = { 194, 7, 163, 141, 191, 255 };
PROGMEM const char _dict_standard_word_204[] = "country";
PROGMEM const uint8_t _dict_standard_code_204[] = { 195, 134, 141, 191, 148, 128, 255 };
PROGMEM const char _dict_standard_word_205[] = "cover";
PROGMEM const uint8_t _dict_standard_code_205[] = { 195, 134, 166, 151, 255 };
PROGMEM const char _dict_standard_word_206[] = "cow";
PROGMEM const uint8_t _dict_standard_code_206[] = { 195, 163, 255 };
PROGMEM const char _dict_standard_word_207[] = "cracker";
PROGMEM const uint8_t _dict_standard_code_207[] = { 196, 7, 148, 132, 194, 151, 255 };
PROGMEM const char _dict_standard_word_208[] = "crain";
PROGMEM const uint8_t _dict_standard_code_208[] = { 194, 148, 154, 141, 255 };
PROGMEM const char _dict_standard_word_209[] = "crayon";
PROGMEM const uint8_t _dict_standard_code_209[] = { 196, 148, 7, 154, 135, 141, 255 };
PROGMEM const char _dict_standard_word_210[] = "created";
PROGMEM const uint8_t _dict_standard_code_210[] = { 195, 7, 148, 128, 154, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_211[] = "crib";
PROGMEM const uint8_t _dict_standard_code_211[] = { 195, 148, 8, 129, 172, 255 };
PROGMEM const char _dict_standard_word_212[] = "cross";
PROGMEM const uint8_t _dict_standard_code_212[] = { 197, 7, 148, 135, 8, 187, 255 };
PROGMEM const char _dict_standard_word_213[] = "crowd";
PROGMEM const uint8_t _dict_standard_code_213[] = { 195, 7, 148, 163, 177, 255 };
PROGMEM const char _dict_standard_word_214[] = "crown";
PROGMEM const uint8_t _dict_standard_code_214[] = { 194, 7, 148, 163, 141, 255 };
PROGMEM const char _dict_standard_word_215[] = "cry";
PROGMEM const uint8_t _dict_standard_code_215[] = { 195, 7, 148, 155, 255 };
PROGMEM const char _dict_standard_word_216[] = "cub";
PROGMEM const uint8_t _dict_standard_code_216[] = { 195, 8, 134, 172, 255 };
PROGMEM const char _dict_standard_word_217[] = "cup";
PROGMEM const uint8_t _dict_standard_code_217[] = { 195, 8, 134, 4, 199, 255 };
PROGMEM const char _dict_standard_word_218[] = "curb";
PROGMEM const uint8_t _dict_standard_code_218[] = { 195, 151, 172, 255 };
PROGMEM const char _dict_standard_word_219[] = "cut";
PROGMEM const uint8_t _dict_standard_code_219[] = { 194, 134, 4, 191, 255 };
PROGMEM const char _dict_standard_word_220[] = "cute";
PROGMEM const uint8_t _dict_standard_code_220[] = { 194, 160, 4, 191, 255 };
PROGMEM const char _dict_standard_word_221[] = "d";
PROGMEM const uint8_t _dict_standard_code_221[] = { 174, 128, 128, 255 };
PROGMEM const char _dict_standard_word_222[] = "daisy";
PROGMEM const uint8_t _dict_standard_code_222[] = { 174, 154, 167, 7, 128, 255 };
PROGMEM const char _dict_standard_word_223[] = "dance";
PROGMEM const uint8_t _dict_standard_code_223[] = { 174, 8, 132, 141, 8, 187, 255 };
PROGMEM const char _dict_standard_word_224[] = "danger";
PROGMEM const uint8_t _dict_standard_code_224[] = { 174, 154, 7, 141, 7, 165, 7, 151, 255 };
PROGMEM const char _dict_standard_word_225[] = "dark";
PROGMEM const uint8_t _dict_standard_code_225[] = { 175, 152, 4, 196, 255 };
PROGMEM const char _dict_standard_word_226[] = "date";
PROGMEM const uint8_t _dict_standard_code_226[] = { 174, 7, 154, 128, 4, 191, 255 };
PROGMEM const char _dict_standard_word_227[] = "daughter";
PROGMEM const uint8_t _dict_standard_code_227[] = { 174, 8, 136, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_228[] = "day";
PROGMEM const uint8_t _dict_standard_code_228[] = { 174, 154, 255 };
PROGMEM const char _dict_standard_word_229[] = "deactivated";
PROGMEM const uint8_t _dict_standard_code_229[] = { 174, 128, 4, 132, 194, 191, 129, 166, 7, 154, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_230[] = "dear";
PROGMEM const uint8_t _dict_standard_code_230[] = { 174, 128, 7, 149, 255 };
PROGMEM const char _dict_standard_word_231[] = "december";
PROGMEM const uint8_t _dict_standard_code_231[] = { 174, 7, 128, 187, 131, 140, 172, 7, 148, 255 };
PROGMEM const char _dict_standard_word_232[] = "declare";
PROGMEM const uint8_t _dict_standard_code_232[] = { 174, 7, 128, 4, 196, 7, 145, 150, 255 };
PROGMEM const char _dict_standard_word_233[] = "deep";
PROGMEM const uint8_t _dict_standard_code_233[] = { 174, 8, 128, 4, 198, 255 };
PROGMEM const char _dict_standard_word_234[] = "deer";
PROGMEM const uint8_t _dict_standard_code_234[] = { 174, 149, 255 };
PROGMEM const char _dict_standard_word_235[] = "delta";
PROGMEM const uint8_t _dict_standard_code_235[] = { 174, 159, 191, 7, 134, 255 };
PROGMEM const char _dict_standard_word_236[] = "dentist";
PROGMEM const uint8_t _dict_standard_code_236[] = { 174, 7, 130, 141, 191, 129, 187, 191, 255 };
PROGMEM const char _dict_standard_word_237[] = "desert";
PROGMEM const uint8_t _dict_standard_code_237[] = { 174, 14, 131, 167, 7, 151, 191, 255 };
PROGMEM const char _dict_standard_word_238[] = "desk";
PROGMEM const uint8_t _dict_standard_code_238[] = { 174, 131, 187, 194, 255 };
PROGMEM const char _dict_standard_word_239[] = "dessert";
PROGMEM const uint8_t _dict_standard_code_239[] = { 174, 131, 7, 167, 7, 151, 191, 255 };
PROGMEM const char _dict_standard_word_240[] = "dictionary";
PROGMEM const uint8_t _dict_standard_code_240[] = { 7, 174, 7, 14, 129, 194, 182, 133, 141, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_241[] = "different";
PROGMEM const uint8_t _dict_standard_code_241[] = { 174, 7, 129, 186, 148, 7, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_242[] = "difficult";
PROGMEM const uint8_t _dict_standard_code_242[] = { 174, 7, 129, 186, 129, 195, 7, 138, 145, 191, 255 };
PROGMEM const char _dict_standard_word_243[] = "dime";
PROGMEM const uint8_t _dict_standard_code_243[] = { 175, 155, 140, 255 };
PROGMEM const char _dict_standard_word_244[] = "dinner";
PROGMEM const uint8_t _dict_standard_code_244[] = { 174, 129, 141, 7, 151, 255 };
PROGMEM const char _dict_standard_word_245[] = "direction";
PROGMEM const uint8_t _dict_standard_code_245[] = { 174, 7, 151, 131, 194, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_246[] = "dirt";
PROGMEM const uint8_t _dict_standard_code_246[] = { 174, 7, 133, 7, 151, 4, 191, 255 };
PROGMEM const char _dict_standard_word_247[] = "dirty";
PROGMEM const uint8_t _dict_standard_code_247[] = { 174, 7, 151, 191, 8, 128, 255 };
PROGMEM const char _dict_standard_word_248[] = "discover";
PROGMEM const uint8_t _dict_standard_code_248[] = { 174, 7, 129, 187, 194, 134, 166, 151, 255 };
PROGMEM const char _dict_standard_word_249[] = "dish";
PROGMEM const uint8_t _dict_standard_code_249[] = { 174, 8, 129, 8, 189, 255 };
PROGMEM const char _dict_standard_word_250[] = "distance";
PROGMEM const uint8_t _dict_standard_code_250[] = { 174, 7, 129, 187, 191, 133, 141, 8, 187, 255 };
PROGMEM const char _dict_standard_word_251[] = "divide";
PROGMEM const uint8_t _dict_standard_code_251[] = { 174, 7, 129, 166, 157, 174, 255 };
PROGMEM const char _dict_standard_word_252[] = "divided";
PROGMEM const uint8_t _dict_standard_code_252[] = { 174, 7, 129, 166, 157, 174, 8, 129, 176, 255 };
PROGMEM const char _dict_standard_word_253[] = "do";
PROGMEM const uint8_t _dict_standard_code_253[] = { 174, 162, 255 };
PROGMEM const char _dict_standard_word_254[] = "doctor";
PROGMEM const uint8_t _dict_standard_code_254[] = { 175, 135, 194, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_255[] = "dodge";
PROGMEM const uint8_t _dict_standard_code_255[] = { 175, 135, 135, 177, 165, 255 };
PROGMEM const char _dict_standard_word_256[] = "doe";
PROGMEM const uint8_t _dict_standard_code_256[] = { 175, 164, 255 };
PROGMEM const char _dict_standard_word_257[] = "dog";
PROGMEM const uint8_t _dict_standard_code_257[] = { 175, 135, 135, 181, 255 };
PROGMEM const char _dict_standard_word_258[] = "doing";
PROGMEM const uint8_t _dict_standard_code_258[] = { 174, 7, 162, 8, 129, 143, 255 };
PROGMEM const char _dict_standard_word_259[] = "doll";
PROGMEM const uint8_t _dict_standard_code_259[] = { 175, 135, 135, 146, 255 };
PROGMEM const char _dict_standard_word_260[] = "dollar";
PROGMEM const uint8_t _dict_standard_code_260[] = { 175, 7, 135, 8, 145, 151, 255 };
PROGMEM const char _dict_standard_word_261[] = "dolphin";
PROGMEM const uint8_t _dict_standard_code_261[] = { 175, 135, 146, 186, 129, 141, 255 };
PROGMEM const char _dict_standard_word_262[] = "dong";
PROGMEM const uint8_t _dict_standard_code_262[] = { 175, 8, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_263[] = "door";
PROGMEM const uint8_t _dict_standard_code_263[] = { 175, 153, 255 };
PROGMEM const char _dict_standard_word_264[] = "dot";
PROGMEM const uint8_t _dict_standard_code_264[] = { 175, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_265[] = "double";
PROGMEM const uint8_t _dict_standard_code_265[] = { 175, 134, 173, 138, 145, 255 };
PROGMEM const char _dict_standard_word_266[] = "down";
PROGMEM const uint8_t _dict_standard_code_266[] = { 175, 163, 141, 255 };
PROGMEM const char _dict_standard_word_267[] = "dozen";
PROGMEM const uint8_t _dict_standard_code_267[] = { 174, 134, 7, 167, 130, 141, 255 };
PROGMEM const char _dict_standard_word_268[] = "dragon";
PROGMEM const uint8_t _dict_standard_code_268[] = { 175, 7, 148, 132, 7, 178, 133, 141, 255 };
PROGMEM const char _dict_standard_word_269[] = "drain";
PROGMEM const uint8_t _dict_standard_code_269[] = { 174, 7, 148, 154, 141, 255 };
PROGMEM const char _dict_standard_word_270[] = "draw";
PROGMEM const uint8_t _dict_standard_code_270[] = { 175, 7, 148, 135, 135, 255 };
PROGMEM const char _dict_standard_word_271[] = "dress";
PROGMEM const uint8_t _dict_standard_code_271[] = { 174, 7, 148, 8, 130, 187, 255 };
PROGMEM const char _dict_standard_word_272[] = "drill";
PROGMEM const uint8_t _dict_standard_code_272[] = { 174, 7, 148, 8, 129, 145, 255 };
PROGMEM const char _dict_standard_word_273[] = "drink";
PROGMEM const uint8_t _dict_standard_code_273[] = { 174, 7, 148, 15, 128, 143, 196, 255 };
PROGMEM const char _dict_standard_word_274[] = "drive";
PROGMEM const uint8_t _dict_standard_code_274[] = { 175, 7, 148, 157, 166, 255 };
PROGMEM const char _dict_standard_word_275[] = "drop";
PROGMEM const uint8_t _dict_standard_code_275[] = { 175, 7, 148, 8, 135, 7, 199, 255 };
PROGMEM const char _dict_standard_word_276[] = "drum";
PROGMEM const uint8_t _dict_standard_code_276[] = { 174, 7, 148, 8, 134, 140, 255 };
PROGMEM const char _dict_standard_word_277[] = "dry";
PROGMEM const uint8_t _dict_standard_code_277[] = { 175, 7, 148, 155, 255 };
PROGMEM const char _dict_standard_word_278[] = "duck";
PROGMEM const uint8_t _dict_standard_code_278[] = { 175, 8, 134, 194, 255 };
PROGMEM const char _dict_standard_word_279[] = "during";
PROGMEM const uint8_t _dict_standard_code_279[] = { 175, 7, 151, 8, 129, 143, 255 };
PROGMEM const char _dict_standard_word_280[] = "dusts";
PROGMEM const uint8_t _dict_standard_code_280[] = { 175, 133, 187, 4, 193, 255 };
PROGMEM const char _dict_standard_word_281[] = "dwarfs";
PROGMEM const uint8_t _dict_standard_code_281[] = { 175, 7, 147, 153, 186, 187, 255 };
PROGMEM const char _dict_standard_word_282[] = "e";
PROGMEM const uint8_t _dict_standard_code_282[] = { 128, 128, 255 };
PROGMEM const char _dict_standard_word_283[] = "each";
PROGMEM const uint8_t _dict_standard_code_283[] = { 128, 128, 4, 182, 255 };
PROGMEM const char _dict_standard_word_284[] = "eagle";
PROGMEM const uint8_t _dict_standard_code_284[] = { 128, 178, 133, 145, 255 };
PROGMEM const char _dict_standard_word_285[] = "ear";
PROGMEM const uint8_t _dict_standard_code_285[] = { 149, 148, 255 };
PROGMEM const char _dict_standard_word_286[] = "early";
PROGMEM const uint8_t _dict_standard_code_286[] = { 7, 151, 145, 7, 128, 255 };
PROGMEM const char _dict_standard_word_287[] = "earn";
PROGMEM const uint8_t _dict_standard_code_287[] = { 133, 148, 141, 255 };
PROGMEM const char _dict_standard_word_288[] = "earring";
PROGMEM const uint8_t _dict_standard_code_288[] = { 149, 7, 148, 128, 143, 255 };
PROGMEM const char _dict_standard_word_289[] = "earth";
PROGMEM const uint8_t _dict_standard_code_289[] = { 151, 190, 190, 255 };
PROGMEM const char _dict_standard_word_290[] = "easy";
PROGMEM const uint8_t _dict_standard_code_290[] = { 8, 128, 167, 7, 128, 255 };
PROGMEM const char _dict_standard_word_291[] = "eat";
PROGMEM const uint8_t _dict_standard_code_291[] = { 8, 128, 191, 255 };
PROGMEM const char _dict_standard_word_292[] = "effort";
PROGMEM const uint8_t _dict_standard_code_292[] = { 8, 131, 186, 7, 153, 191, 255 };
PROGMEM const char _dict_standard_word_293[] = "egg";
PROGMEM const uint8_t _dict_standard_code_293[] = { 8, 130, 178, 255 };
PROGMEM const char _dict_standard_word_294[] = "eight";
PROGMEM const uint8_t _dict_standard_code_294[] = { 154, 4, 191, 255 };
PROGMEM const char _dict_standard_word_295[] = "eighteen";
PROGMEM const uint8_t _dict_standard_code_295[] = { 154, 4, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_296[] = "eighty";
PROGMEM const uint8_t _dict_standard_code_296[] = { 154, 4, 191, 128, 255 };
PROGMEM const char _dict_standard_word_297[] = "either";
PROGMEM const uint8_t _dict_standard_code_297[] = { 8, 128, 7, 169, 151, 255 };
PROGMEM const char _dict_standard_word_298[] = "elbow";
PROGMEM const uint8_t _dict_standard_code_298[] = { 131, 145, 18, 171, 164, 255 };
PROGMEM const char _dict_standard_word_299[] = "elephant";
PROGMEM const uint8_t _dict_standard_code_299[] = { 159, 7, 134, 186, 8, 133, 141, 191, 255 };
PROGMEM const char _dict_standard_word_300[] = "eleven";
PROGMEM const uint8_t _dict_standard_code_300[] = { 7, 129, 145, 131, 166, 7, 131, 141, 255 };
PROGMEM const char _dict_standard_word_301[] = "emotional";
PROGMEM const uint8_t _dict_standard_code_301[] = { 128, 140, 137, 189, 7, 133, 141, 7, 134, 145, 255 };
PROGMEM const char _dict_standard_word_302[] = "empty";
PROGMEM const uint8_t _dict_standard_code_302[] = { 130, 140, 198, 191, 128, 255 };
PROGMEM const char _dict_standard_word_303[] = "end";
PROGMEM const uint8_t _dict_standard_code_303[] = { 8, 131, 8, 141, 177, 255 };
PROGMEM const char _dict_standard_word_304[] = "engage";
PROGMEM const uint8_t _dict_standard_code_304[] = { 8, 129, 141, 4, 178, 154, 165, 255 };
PROGMEM const char _dict_standard_word_305[] = "engagement";
PROGMEM const uint8_t _dict_standard_code_305[] = { 8, 129, 141, 7, 178, 154, 165, 7, 140, 7, 130, 141, 191, 255 };
PROGMEM const char _dict_standard_word_306[] = "engages";
PROGMEM const uint8_t _dict_standard_code_306[] = { 8, 129, 141, 7, 178, 154, 165, 129, 7, 167, 255 };
PROGMEM const char _dict_standard_word_307[] = "engaging";
PROGMEM const uint8_t _dict_standard_code_307[] = { 8, 129, 141, 7, 178, 154, 165, 129, 143, 255 };
PROGMEM const char _dict_standard_word_308[] = "engine";
PROGMEM const uint8_t _dict_standard_code_308[] = { 130, 141, 7, 165, 8, 129, 141, 255 };
PROGMEM const char _dict_standard_word_309[] = "enjoy";
PROGMEM const uint8_t _dict_standard_code_309[] = { 130, 141, 7, 165, 156, 255 };
PROGMEM const char _dict_standard_word_310[] = "enough";
PROGMEM const uint8_t _dict_standard_code_310[] = { 15, 8, 128, 141, 8, 133, 186, 255 };
PROGMEM const char _dict_standard_word_311[] = "enrage";
PROGMEM const uint8_t _dict_standard_code_311[] = { 8, 129, 141, 7, 148, 154, 165, 255 };
PROGMEM const char _dict_standard_word_312[] = "enraged";
PROGMEM const uint8_t _dict_standard_code_312[] = { 8, 129, 141, 7, 148, 154, 165, 176, 255 };
PROGMEM const char _dict_standard_word_313[] = "enrages";
PROGMEM const uint8_t _dict_standard_code_313[] = { 8, 129, 141, 7, 148, 154, 165, 129, 7, 167, 255 };
PROGMEM const char _dict_standard_word_314[] = "enraging";
PROGMEM const uint8_t _dict_standard_code_314[] = { 8, 129, 141, 7, 148, 154, 165, 129, 143, 255 };
PROGMEM const char _dict_standard_word_315[] = "enter";
PROGMEM const uint8_t _dict_standard_code_315[] = { 8, 130, 141, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_316[] = "entire";
PROGMEM const uint8_t _dict_standard_code_316[] = { 8, 130, 141, 4, 191, 157, 7, 148, 255 };
PROGMEM const char _dict_standard_word_317[] = "epsillon";
PROGMEM const uint8_t _dict_standard_code_317[] = { 131, 199, 187, 8, 129, 7, 146, 7, 135, 142, 255 };
PROGMEM const char _dict_standard_word_318[] = "equal";
PROGMEM const uint8_t _dict_standard_code_318[] = { 128, 195, 7, 147, 134, 145, 255 };
PROGMEM const char _dict_standard_word_319[] = "equals";
PROGMEM const uint8_t _dict_standard_code_319[] = { 128, 195, 7, 147, 134, 145, 7, 167, 255 };
PROGMEM const char _dict_standard_word_320[] = "erection";
PROGMEM const uint8_t _dict_standard_code_320[] = { 8, 128, 7, 148, 131, 194, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_321[] = "error";
PROGMEM const uint8_t _dict_standard_code_321[] = { 7, 150, 153, 255 };
PROGMEM const char _dict_standard_word_322[] = "escape";
PROGMEM const uint8_t _dict_standard_code_322[] = { 131, 187, 194, 7, 154, 4, 198, 255 };
PROGMEM const char _dict_standard_word_323[] = "escaped";
PROGMEM const uint8_t _dict_standard_code_323[] = { 131, 187, 194, 7, 154, 198, 191, 255 };
PROGMEM const char _dict_standard_word_324[] = "escapes";
PROGMEM const uint8_t _dict_standard_code_324[] = { 131, 187, 194, 7, 154, 198, 187, 255 };
PROGMEM const char _dict_standard_word_325[] = "escaping";
PROGMEM const uint8_t _dict_standard_code_325[] = { 131, 187, 194, 7, 154, 198, 129, 143, 255 };
PROGMEM const char _dict_standard_word_326[] = "eta";
PROGMEM const uint8_t _dict_standard_code_326[] = { 154, 191, 7, 134, 255 };
PROGMEM const char _dict_standard_word_327[] = "even";
PROGMEM const uint8_t _dict_standard_code_327[] = { 8, 128, 166, 130, 141, 255 };
PROGMEM const char _dict_standard_word_328[] = "ever";
PROGMEM const uint8_t _dict_standard_code_328[] = { 130, 166, 7, 151, 255 };
PROGMEM const char _dict_standard_word_329[] = "every";
PROGMEM const uint8_t _dict_standard_code_329[] = { 130, 166, 148, 128, 255 };
PROGMEM const char _dict_standard_word_330[] = "extend";
PROGMEM const uint8_t _dict_standard_code_330[] = { 129, 194, 187, 191, 7, 130, 8, 141, 177, 255 };
PROGMEM const char _dict_standard_word_331[] = "extent";
PROGMEM const uint8_t _dict_standard_code_331[] = { 131, 194, 187, 191, 7, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_332[] = "extra";
PROGMEM const uint8_t _dict_standard_code_332[] = { 130, 194, 187, 191, 7, 148, 7, 133, 255 };
PROGMEM const char _dict_standard_word_333[] = "extract";
PROGMEM const uint8_t _dict_standard_code_333[] = { 131, 194, 187, 191, 7, 148, 7, 132, 196, 191, 255 };
PROGMEM const char _dict_standard_word_334[] = "eye";
PROGMEM const uint8_t _dict_standard_code_334[] = { 155, 255 };
PROGMEM const char _dict_standard_word_335[] = "f";
PROGMEM const uint8_t _dict_standard_code_335[] = { 8, 131, 186, 255 };
PROGMEM const char _dict_standard_word_336[] = "face";
PROGMEM const uint8_t _dict_standard_code_336[] = { 186, 154, 187, 255 };
PROGMEM const char _dict_standard_word_337[] = "fah";
PROGMEM const uint8_t _dict_standard_code_337[] = { 186, 135, 135, 255 };
PROGMEM const char _dict_standard_word_338[] = "fall";
PROGMEM const uint8_t _dict_standard_code_338[] = { 186, 8, 135, 146, 255 };
PROGMEM const char _dict_standard_word_339[] = "fallen";
PROGMEM const uint8_t _dict_standard_code_339[] = { 186, 8, 135, 145, 7, 131, 141, 255 };
PROGMEM const char _dict_standard_word_340[] = "falls";
PROGMEM const uint8_t _dict_standard_code_340[] = { 186, 135, 135, 146, 187, 255 };
PROGMEM const char _dict_standard_word_341[] = "family";
PROGMEM const uint8_t _dict_standard_code_341[] = { 186, 132, 140, 7, 133, 145, 128, 255 };
PROGMEM const char _dict_standard_word_342[] = "famous";
PROGMEM const uint8_t _dict_standard_code_342[] = { 186, 154, 140, 133, 187, 255 };
PROGMEM const char _dict_standard_word_343[] = "fan";
PROGMEM const uint8_t _dict_standard_code_343[] = { 186, 132, 132, 141, 255 };
PROGMEM const char _dict_standard_word_344[] = "far";
PROGMEM const uint8_t _dict_standard_code_344[] = { 186, 152, 255 };
PROGMEM const char _dict_standard_word_345[] = "farm";
PROGMEM const uint8_t _dict_standard_code_345[] = { 186, 152, 140, 255 };
PROGMEM const char _dict_standard_word_346[] = "fart";
PROGMEM const uint8_t _dict_standard_code_346[] = { 186, 152, 191, 255 };
PROGMEM const char _dict_standard_word_347[] = "fast";
PROGMEM const uint8_t _dict_standard_code_347[] = { 186, 132, 187, 191, 255 };
PROGMEM const char _dict_standard_word_348[] = "faster";
PROGMEM const uint8_t _dict_standard_code_348[] = { 186, 132, 187, 191, 148, 255 };
PROGMEM const char _dict_standard_word_349[] = "fastest";
PROGMEM const uint8_t _dict_standard_code_349[] = { 186, 132, 187, 191, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_350[] = "father";
PROGMEM const uint8_t _dict_standard_code_350[] = { 186, 8, 136, 169, 133, 148, 255 };
PROGMEM const char _dict_standard_word_351[] = "faucet";
PROGMEM const uint8_t _dict_standard_code_351[] = { 186, 136, 8, 187, 130, 191, 255 };
PROGMEM const char _dict_standard_word_352[] = "faucets";
PROGMEM const uint8_t _dict_standard_code_352[] = { 186, 136, 8, 187, 130, 193, 255 };
PROGMEM const char _dict_standard_word_353[] = "fault";
PROGMEM const uint8_t _dict_standard_code_353[] = { 186, 135, 135, 146, 191, 255 };
PROGMEM const char _dict_standard_word_354[] = "faults";
PROGMEM const uint8_t _dict_standard_code_354[] = { 186, 135, 135, 146, 193, 255 };
PROGMEM const char _dict_standard_word_355[] = "favorite";
PROGMEM const uint8_t _dict_standard_code_355[] = { 186, 7, 154, 166, 7, 148, 129, 191, 255 };
PROGMEM const char _dict_standard_word_356[] = "fear";
PROGMEM const uint8_t _dict_standard_code_356[] = { 186, 149, 255 };
PROGMEM const char _dict_standard_word_357[] = "fears";
PROGMEM const uint8_t _dict_standard_code_357[] = { 186, 149, 187, 255 };
PROGMEM const char _dict_standard_word_358[] = "feature";
PROGMEM const uint8_t _dict_standard_code_358[] = { 186, 128, 182, 133, 148, 255 };
PROGMEM const char _dict_standard_word_359[] = "february";
PROGMEM const uint8_t _dict_standard_code_359[] = { 186, 131, 172, 148, 139, 150, 128, 255 };
PROGMEM const char _dict_standard_word_360[] = "fed";
PROGMEM const uint8_t _dict_standard_code_360[] = { 186, 131, 131, 176, 255 };
PROGMEM const char _dict_standard_word_361[] = "feed";
PROGMEM const uint8_t _dict_standard_code_361[] = { 186, 128, 128, 176, 255 };
PROGMEM const char _dict_standard_word_362[] = "feeding";
PROGMEM const uint8_t _dict_standard_code_362[] = { 186, 128, 128, 174, 129, 143, 255 };
PROGMEM const char _dict_standard_word_363[] = "feeds";
PROGMEM const uint8_t _dict_standard_code_363[] = { 186, 128, 128, 174, 167, 255 };
PROGMEM const char _dict_standard_word_364[] = "feel";
PROGMEM const uint8_t _dict_standard_code_364[] = { 8, 186, 8, 128, 146, 255 };
PROGMEM const char _dict_standard_word_365[] = "feet";
PROGMEM const uint8_t _dict_standard_code_365[] = { 186, 128, 191, 255 };
PROGMEM const char _dict_standard_word_366[] = "fence";
PROGMEM const uint8_t _dict_standard_code_366[] = { 186, 130, 141, 188, 188, 255 };
PROGMEM const char _dict_standard_word_367[] = "fern";
PROGMEM const uint8_t _dict_standard_code_367[] = { 186, 151, 141, 255 };
PROGMEM const char _dict_standard_word_368[] = "few";
PROGMEM const uint8_t _dict_standard_code_368[] = { 186, 160, 255 };
PROGMEM const char _dict_standard_word_369[] = "fibber";
PROGMEM const uint8_t _dict_standard_code_369[] = { 8, 186, 129, 18, 171, 8, 148, 255 };
PROGMEM const char _dict_standard_word_370[] = "fiction";
PROGMEM const uint8_t _dict_standard_code_370[] = { 186, 129, 194, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_371[] = "field";
PROGMEM const uint8_t _dict_standard_code_371[] = { 186, 8, 128, 145, 174, 255 };
PROGMEM const char _dict_standard_word_372[] = "fifteen";
PROGMEM const uint8_t _dict_standard_code_372[] = { 186, 129, 186, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_373[] = "fifty";
PROGMEM const uint8_t _dict_standard_code_373[] = { 186, 129, 186, 191, 128, 255 };
PROGMEM const char _dict_standard_word_374[] = "fight";
PROGMEM const uint8_t _dict_standard_code_374[] = { 8, 186, 7, 155, 4, 191, 255 };
PROGMEM const char _dict_standard_word_375[] = "fighter";
PROGMEM const uint8_t _dict_standard_code_375[] = { 186, 155, 191, 148, 255 };
PROGMEM const char _dict_standard_word_376[] = "fighting";
PROGMEM const uint8_t _dict_standard_code_376[] = { 186, 155, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_377[] = "fights";
PROGMEM const uint8_t _dict_standard_code_377[] = { 186, 155, 193, 255 };
PROGMEM const char _dict_standard_word_378[] = "fill";
PROGMEM const uint8_t _dict_standard_code_378[] = { 186, 8, 15, 129, 145, 255 };
PROGMEM const char _dict_standard_word_379[] = "finally";
PROGMEM const uint8_t _dict_standard_code_379[] = { 186, 7, 155, 142, 7, 145, 128, 255 };
PROGMEM const char _dict_standard_word_380[] = "find";
PROGMEM const uint8_t _dict_standard_code_380[] = { 186, 155, 141, 177, 255 };
PROGMEM const char _dict_standard_word_381[] = "finger";
PROGMEM const uint8_t _dict_standard_code_381[] = { 186, 129, 7, 143, 178, 151, 255 };
PROGMEM const char _dict_standard_word_382[] = "fir";
PROGMEM const uint8_t _dict_standard_code_382[] = { 186, 151, 255 };
PROGMEM const char _dict_standard_word_383[] = "fire";
PROGMEM const uint8_t _dict_standard_code_383[] = { 186, 155, 148, 255 };
PROGMEM const char _dict_standard_word_384[] = "first";
PROGMEM const uint8_t _dict_standard_code_384[] = { 186, 151, 187, 191, 255 };
PROGMEM const char _dict_standard_word_385[] = "fish";
PROGMEM const uint8_t _dict_standard_code_385[] = { 186, 129, 129, 189, 189, 255 };
PROGMEM const char _dict_standard_word_386[] = "fist";
PROGMEM const uint8_t _dict_standard_code_386[] = { 186, 129, 129, 187, 191, 255 };
PROGMEM const char _dict_standard_word_387[] = "fit";
PROGMEM const uint8_t _dict_standard_code_387[] = { 186, 129, 191, 255 };
PROGMEM const char _dict_standard_word_388[] = "five";
PROGMEM const uint8_t _dict_standard_code_388[] = { 186, 157, 166, 255 };
PROGMEM const char _dict_standard_word_389[] = "fix";
PROGMEM const uint8_t _dict_standard_code_389[] = { 186, 129, 194, 187, 255 };
PROGMEM const char _dict_standard_word_390[] = "fixed";
PROGMEM const uint8_t _dict_standard_code_390[] = { 186, 129, 194, 187, 191, 255 };
PROGMEM const char _dict_standard_word_391[] = "flag";
PROGMEM const uint8_t _dict_standard_code_391[] = { 186, 145, 132, 132, 180, 255 };
PROGMEM const char _dict_standard_word_392[] = "flat";
PROGMEM const uint8_t _dict_standard_code_392[] = { 186, 145, 132, 191, 255 };
PROGMEM const char _dict_standard_word_393[] = "flight";
PROGMEM const uint8_t _dict_standard_code_393[] = { 186, 145, 155, 191, 255 };
PROGMEM const char _dict_standard_word_394[] = "flights";
PROGMEM const uint8_t _dict_standard_code_394[] = { 186, 145, 155, 193, 255 };
PROGMEM const char _dict_standard_word_395[] = "float";
PROGMEM const uint8_t _dict_standard_code_395[] = { 186, 145, 164, 191, 255 };
PROGMEM const char _dict_standard_word_396[] = "floor";
PROGMEM const uint8_t _dict_standard_code_396[] = { 186, 146, 153, 255 };
PROGMEM const char _dict_standard_word_397[] = "flour";
PROGMEM const uint8_t _dict_standard_code_397[] = { 186, 146, 163, 148, 255 };
PROGMEM const char _dict_standard_word_398[] = "flower";
PROGMEM const uint8_t _dict_standard_code_398[] = { 186, 146, 163, 148, 255 };
PROGMEM const char _dict_standard_word_399[] = "fly";
PROGMEM const uint8_t _dict_standard_code_399[] = { 186, 146, 155, 255 };
PROGMEM const char _dict_standard_word_400[] = "follow";
PROGMEM const uint8_t _dict_standard_code_400[] = { 186, 136, 146, 164, 255 };
PROGMEM const char _dict_standard_word_401[] = "food";
PROGMEM const uint8_t _dict_standard_code_401[] = { 186, 139, 139, 174, 255 };
PROGMEM const char _dict_standard_word_402[] = "fool";
PROGMEM const uint8_t _dict_standard_code_402[] = { 186, 139, 139, 146, 255 };
PROGMEM const char _dict_standard_word_403[] = "foot";
PROGMEM const uint8_t _dict_standard_code_403[] = { 186, 8, 138, 191, 255 };
PROGMEM const char _dict_standard_word_404[] = "football";
PROGMEM const uint8_t _dict_standard_code_404[] = { 186, 8, 138, 191, 7, 4, 18, 171, 135, 8, 146, 255 };
PROGMEM const char _dict_standard_word_405[] = "for";
PROGMEM const uint8_t _dict_standard_code_405[] = { 186, 153, 255 };
PROGMEM const char _dict_standard_word_406[] = "fore";
PROGMEM const uint8_t _dict_standard_code_406[] = { 186, 153, 255 };
PROGMEM const char _dict_standard_word_407[] = "foreign";
PROGMEM const uint8_t _dict_standard_code_407[] = { 186, 153, 7, 129, 141, 255 };
PROGMEM const char _dict_standard_word_408[] = "forest";
PROGMEM const uint8_t _dict_standard_code_408[] = { 186, 153, 7, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_409[] = "forget";
PROGMEM const uint8_t _dict_standard_code_409[] = { 186, 7, 153, 178, 14, 131, 191, 255 };
PROGMEM const char _dict_standard_word_410[] = "fork";
PROGMEM const uint8_t _dict_standard_code_410[] = { 186, 153, 194, 255 };
PROGMEM const char _dict_standard_word_411[] = "forks";
PROGMEM const uint8_t _dict_standard_code_411[] = { 186, 153, 194, 187, 255 };
PROGMEM const char _dict_standard_word_412[] = "form";
PROGMEM const uint8_t _dict_standard_code_412[] = { 186, 153, 140, 255 };
PROGMEM const char _dict_standard_word_413[] = "fort";
PROGMEM const uint8_t _dict_standard_code_413[] = { 186, 153, 191, 255 };
PROGMEM const char _dict_standard_word_414[] = "forth";
PROGMEM const uint8_t _dict_standard_code_414[] = { 186, 153, 190, 255 };
PROGMEM const char _dict_standard_word_415[] = "forties";
PROGMEM const uint8_t _dict_standard_code_415[] = { 186, 153, 191, 128, 7, 167, 255 };
PROGMEM const char _dict_standard_word_416[] = "forts";
PROGMEM const uint8_t _dict_standard_code_416[] = { 186, 153, 193, 255 };
PROGMEM const char _dict_standard_word_417[] = "fortune";
PROGMEM const uint8_t _dict_standard_code_417[] = { 186, 153, 182, 133, 141, 255 };
PROGMEM const char _dict_standard_word_418[] = "forty";
PROGMEM const uint8_t _dict_standard_code_418[] = { 186, 7, 153, 191, 128, 255 };
PROGMEM const char _dict_standard_word_419[] = "forward";
PROGMEM const uint8_t _dict_standard_code_419[] = { 186, 7, 153, 7, 147, 151, 176, 255 };
PROGMEM const char _dict_standard_word_420[] = "four";
PROGMEM const uint8_t _dict_standard_code_420[] = { 186, 7, 137, 153, 255 };
PROGMEM const char _dict_standard_word_421[] = "fourteen";
PROGMEM const uint8_t _dict_standard_code_421[] = { 186, 7, 153, 7, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_422[] = "fox";
PROGMEM const uint8_t _dict_standard_code_422[] = { 186, 8, 135, 195, 187, 255 };
PROGMEM const char _dict_standard_word_423[] = "free";
PROGMEM const uint8_t _dict_standard_code_423[] = { 8, 186, 148, 8, 128, 255 };
PROGMEM const char _dict_standard_word_424[] = "freeze";
PROGMEM const uint8_t _dict_standard_code_424[] = { 186, 148, 128, 167, 255 };
PROGMEM const char _dict_standard_word_425[] = "freezer";
PROGMEM const uint8_t _dict_standard_code_425[] = { 186, 148, 128, 167, 7, 151, 255 };
PROGMEM const char _dict_standard_word_426[] = "freezers";
PROGMEM const uint8_t _dict_standard_code_426[] = { 186, 148, 128, 167, 7, 151, 167, 255 };
PROGMEM const char _dict_standard_word_427[] = "freezing";
PROGMEM const uint8_t _dict_standard_code_427[] = { 186, 148, 128, 167, 129, 143, 255 };
PROGMEM const char _dict_standard_word_428[] = "friday";
PROGMEM const uint8_t _dict_standard_code_428[] = { 186, 148, 155, 174, 154, 255 };
PROGMEM const char _dict_standard_word_429[] = "friend";
PROGMEM const uint8_t _dict_standard_code_429[] = { 186, 148, 131, 141, 175, 255 };
PROGMEM const char _dict_standard_word_430[] = "fright";
PROGMEM const uint8_t _dict_standard_code_430[] = { 186, 148, 155, 191, 255 };
PROGMEM const char _dict_standard_word_431[] = "frog";
PROGMEM const uint8_t _dict_standard_code_431[] = { 186, 148, 135, 8, 181, 255 };
PROGMEM const char _dict_standard_word_432[] = "from";
PROGMEM const uint8_t _dict_standard_code_432[] = { 186, 148, 134, 8, 140, 255 };
PROGMEM const char _dict_standard_word_433[] = "front";
PROGMEM const uint8_t _dict_standard_code_433[] = { 186, 148, 134, 141, 191, 255 };
PROGMEM const char _dict_standard_word_434[] = "frozen";
PROGMEM const uint8_t _dict_standard_code_434[] = { 186, 148, 137, 167, 131, 141, 255 };
PROGMEM const char _dict_standard_word_435[] = "fruit";
PROGMEM const uint8_t _dict_standard_code_435[] = { 186, 148, 139, 191, 255 };
PROGMEM const char _dict_standard_word_436[] = "full";
PROGMEM const uint8_t _dict_standard_code_436[] = { 186, 15, 138, 15, 138, 146, 255 };
PROGMEM const char _dict_standard_word_437[] = "fun";
PROGMEM const uint8_t _dict_standard_code_437[] = { 186, 8, 134, 141, 255 };
PROGMEM const char _dict_standard_word_438[] = "funny";
PROGMEM const uint8_t _dict_standard_code_438[] = { 186, 8, 134, 7, 141, 128, 255 };
PROGMEM const char _dict_standard_word_439[] = "fur";
PROGMEM const uint8_t _dict_standard_code_439[] = { 186, 151, 255 };
PROGMEM const char _dict_standard_word_440[] = "furniture";
PROGMEM const uint8_t _dict_standard_code_440[] = { 186, 7, 151, 141, 7, 129, 182, 7, 151, 255 };
PROGMEM const char _dict_standard_word_441[] = "fxalarm";
PROGMEM const uint8_t _dict_standard_code_441[] = { 30, 26, 3, 217, 26, 3, 216, 26, 3, 214, 26, 3, 213, 211, 26, 3, 210, 30, 255 };
PROGMEM const char _dict_standard_word_442[] = "fxburningfusewithbang";
PROGMEM const uint8_t _dict_standard_code_442[] = { 30, 21, 114, 182, 1, 182, 1, 182, 21, 0, 26, 6, 189, 187, 253, 30, 255 };
PROGMEM const char _dict_standard_word_443[] = "fxping";
PROGMEM const uint8_t _dict_standard_code_443[] = { 30, 21, 50, 23, 0, 252, 252, 252, 30, 255 };
PROGMEM const char _dict_standard_word_444[] = "fxrobotbede";
PROGMEM const uint8_t _dict_standard_code_444[] = { 30, 21, 127, 170, 128, 174, 128, 170, 128, 174, 128, 170, 128, 174, 128, 170, 128, 174, 128, 170, 128, 174, 128, 30, 255 };
PROGMEM const char _dict_standard_word_445[] = "fxrobotdroid";
PROGMEM const uint8_t _dict_standard_code_445[] = { 30, 223, 4, 222, 5, 207, 200, 207, 202, 207, 204, 207, 206, 208, 203, 203, 203, 4, 226, 4, 226, 4, 238, 4, 239, 255 };
PROGMEM const char _dict_standard_word_446[] = "fxrobotsad";
PROGMEM const uint8_t _dict_standard_code_446[] = { 30, 23, 0, 21, 61, 228, 1, 223, 220, 1, 239, 1, 30, 255 };
PROGMEM const char _dict_standard_word_447[] = "fxstatus1";
PROGMEM const uint8_t _dict_standard_code_447[] = { 30, 226, 3, 226, 3, 226, 3, 227, 220, 30, 255 };
PROGMEM const char _dict_standard_word_448[] = "fxstatus2";
PROGMEM const uint8_t _dict_standard_code_448[] = { 30, 220, 2, 220, 2, 220, 2, 226, 2, 220, 2, 226, 255 };
PROGMEM const char _dict_standard_word_449[] = "fxufo";
PROGMEM const uint8_t _dict_standard_code_449[] = { 30, 26, 5, 215, 255 };
PROGMEM const char _dict_standard_word_450[] = "g";
PROGMEM const uint8_t _dict_standard_code_450[] = { 165, 128, 128, 255 };
PROGMEM const char _dict_standard_word_451[] = "game";
PROGMEM const uint8_t _dict_standard_code_451[] = { 8, 178, 154, 140, 255 };
PROGMEM const char _dict_standard_word_452[] = "gamma";
PROGMEM const uint8_t _dict_standard_code_452[] = { 8, 178, 132, 140, 134, 255 };
PROGMEM const char _dict_standard_word_453[] = "garden";
PROGMEM const uint8_t _dict_standard_code_453[] = { 179, 136, 7, 148, 7, 174, 131, 141, 255 };
PROGMEM const char _dict_standard_word_454[] = "garment";
PROGMEM const uint8_t _dict_standard_code_454[] = { 179, 7, 152, 140, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_455[] = "gate";
PROGMEM const uint8_t _dict_standard_code_455[] = { 8, 178, 154, 191, 255 };
PROGMEM const char _dict_standard_word_456[] = "gates";
PROGMEM const uint8_t _dict_standard_code_456[] = { 8, 178, 154, 8, 193, 255 };
PROGMEM const char _dict_standard_word_457[] = "gauge";
PROGMEM const uint8_t _dict_standard_code_457[] = { 8, 178, 154, 165, 255 };
PROGMEM const char _dict_standard_word_458[] = "gentlemen";
PROGMEM const uint8_t _dict_standard_code_458[] = { 165, 7, 131, 141, 191, 145, 140, 131, 8, 141, 255 };
PROGMEM const char _dict_standard_word_459[] = "get";
PROGMEM const uint8_t _dict_standard_code_459[] = { 8, 178, 8, 131, 191, 255 };
PROGMEM const char _dict_standard_word_460[] = "giant";
PROGMEM const uint8_t _dict_standard_code_460[] = { 165, 155, 7, 130, 141, 191, 255 };
PROGMEM const char _dict_standard_word_461[] = "gift";
PROGMEM const uint8_t _dict_standard_code_461[] = { 8, 178, 129, 186, 191, 255 };
PROGMEM const char _dict_standard_word_462[] = "giraffe";
PROGMEM const uint8_t _dict_standard_code_462[] = { 165, 7, 151, 8, 132, 186, 255 };
PROGMEM const char _dict_standard_word_463[] = "girl";
PROGMEM const uint8_t _dict_standard_code_463[] = { 8, 178, 7, 151, 7, 148, 8, 146, 255 };
PROGMEM const char _dict_standard_word_464[] = "give";
PROGMEM const uint8_t _dict_standard_code_464[] = { 8, 178, 8, 129, 7, 166, 255 };
PROGMEM const char _dict_standard_word_465[] = "glad";
PROGMEM const uint8_t _dict_standard_code_465[] = { 8, 179, 7, 145, 8, 132, 176, 255 };
PROGMEM const char _dict_standard_word_466[] = "glass";
PROGMEM const uint8_t _dict_standard_code_466[] = { 8, 179, 7, 145, 8, 132, 187, 255 };
PROGMEM const char _dict_standard_word_467[] = "glasses";
PROGMEM const uint8_t _dict_standard_code_467[] = { 8, 179, 7, 145, 8, 132, 187, 7, 18, 131, 7, 167, 255 };
PROGMEM const char _dict_standard_word_468[] = "glove";
PROGMEM const uint8_t _dict_standard_code_468[] = { 8, 179, 7, 146, 134, 8, 166, 255 };
PROGMEM const char _dict_standard_word_469[] = "glue";
PROGMEM const uint8_t _dict_standard_code_469[] = { 8, 179, 7, 146, 162, 255 };
PROGMEM const char _dict_standard_word_470[] = "go";
PROGMEM const uint8_t _dict_standard_code_470[] = { 8, 179, 8, 164, 255 };
PROGMEM const char _dict_standard_word_471[] = "goat";
PROGMEM const uint8_t _dict_standard_code_471[] = { 8, 179, 164, 191, 255 };
PROGMEM const char _dict_standard_word_472[] = "gong";
PROGMEM const uint8_t _dict_standard_code_472[] = { 8, 179, 8, 135, 144, 255 };
PROGMEM const char _dict_standard_word_473[] = "good";
PROGMEM const uint8_t _dict_standard_code_473[] = { 8, 179, 138, 138, 177, 255 };
PROGMEM const char _dict_standard_word_474[] = "goodbye";
PROGMEM const uint8_t _dict_standard_code_474[] = { 8, 179, 139, 177, 7, 4, 18, 171, 157, 255 };
PROGMEM const char _dict_standard_word_475[] = "goose";
PROGMEM const uint8_t _dict_standard_code_475[] = { 8, 179, 8, 139, 187, 255 };
PROGMEM const char _dict_standard_word_476[] = "got";
PROGMEM const uint8_t _dict_standard_code_476[] = { 8, 179, 135, 135, 191, 255 };
PROGMEM const char _dict_standard_word_477[] = "grand";
PROGMEM const uint8_t _dict_standard_code_477[] = { 8, 178, 7, 148, 132, 141, 177, 255 };
PROGMEM const char _dict_standard_word_478[] = "grandfather";
PROGMEM const uint8_t _dict_standard_code_478[] = { 8, 178, 7, 148, 132, 141, 175, 186, 8, 136, 169, 133, 148, 255 };
PROGMEM const char _dict_standard_word_479[] = "grandmother";
PROGMEM const uint8_t _dict_standard_code_479[] = { 8, 178, 7, 148, 132, 141, 176, 140, 134, 190, 151, 255 };
PROGMEM const char _dict_standard_word_480[] = "grape";
PROGMEM const uint8_t _dict_standard_code_480[] = { 8, 178, 7, 148, 154, 199, 255 };
PROGMEM const char _dict_standard_word_481[] = "grapefruit";
PROGMEM const uint8_t _dict_standard_code_481[] = { 8, 178, 7, 148, 154, 199, 186, 7, 148, 139, 191, 255 };
PROGMEM const char _dict_standard_word_482[] = "grass";
PROGMEM const uint8_t _dict_standard_code_482[] = { 8, 179, 7, 148, 8, 132, 187, 187, 255 };
PROGMEM const char _dict_standard_word_483[] = "grasshopper";
PROGMEM const uint8_t _dict_standard_code_483[] = { 8, 179, 7, 148, 132, 187, 184, 135, 199, 7, 151, 255 };
PROGMEM const char _dict_standard_word_484[] = "gray";
PROGMEM const uint8_t _dict_standard_code_484[] = { 8, 179, 7, 148, 8, 154, 255 };
PROGMEM const char _dict_standard_word_485[] = "grease";
PROGMEM const uint8_t _dict_standard_code_485[] = { 8, 179, 7, 148, 8, 128, 187, 255 };
PROGMEM const char _dict_standard_word_486[] = "great";
PROGMEM const uint8_t _dict_standard_code_486[] = { 8, 179, 7, 148, 154, 191, 255 };
PROGMEM const char _dict_standard_word_487[] = "green";
PROGMEM const uint8_t _dict_standard_code_487[] = { 8, 179, 7, 148, 8, 128, 141, 255 };
PROGMEM const char _dict_standard_word_488[] = "grey";
PROGMEM const uint8_t _dict_standard_code_488[] = { 8, 179, 7, 148, 154, 255 };
PROGMEM const char _dict_standard_word_489[] = "ground";
PROGMEM const uint8_t _dict_standard_code_489[] = { 8, 179, 7, 148, 132, 7, 163, 7, 141, 177, 255 };
PROGMEM const char _dict_standard_word_490[] = "group";
PROGMEM const uint8_t _dict_standard_code_490[] = { 8, 179, 7, 148, 139, 139, 199, 255 };
PROGMEM const char _dict_standard_word_491[] = "grow";
PROGMEM const uint8_t _dict_standard_code_491[] = { 8, 179, 7, 148, 137, 164, 255 };
PROGMEM const char _dict_standard_word_492[] = "guaged";
PROGMEM const uint8_t _dict_standard_code_492[] = { 8, 178, 154, 165, 18, 174, 255 };
PROGMEM const char _dict_standard_word_493[] = "guages";
PROGMEM const uint8_t _dict_standard_code_493[] = { 8, 178, 154, 165, 129, 167, 255 };
PROGMEM const char _dict_standard_word_494[] = "guaging";
PROGMEM const uint8_t _dict_standard_code_494[] = { 8, 178, 154, 165, 129, 143, 255 };
PROGMEM const char _dict_standard_word_495[] = "guest";
PROGMEM const uint8_t _dict_standard_code_495[] = { 8, 178, 131, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_496[] = "h";
PROGMEM const uint8_t _dict_standard_code_496[] = { 154, 182, 255 };
PROGMEM const char _dict_standard_word_497[] = "hair";
PROGMEM const uint8_t _dict_standard_code_497[] = { 183, 130, 150, 255 };
PROGMEM const char _dict_standard_word_498[] = "half";
PROGMEM const uint8_t _dict_standard_code_498[] = { 184, 8, 132, 186, 255 };
PROGMEM const char _dict_standard_word_499[] = "hammer";
PROGMEM const uint8_t _dict_standard_code_499[] = { 183, 132, 140, 151, 255 };
PROGMEM const char _dict_standard_word_500[] = "hand";
PROGMEM const uint8_t _dict_standard_code_500[] = { 183, 132, 8, 141, 177, 255 };
PROGMEM const char _dict_standard_word_501[] = "handle";
PROGMEM const uint8_t _dict_standard_code_501[] = { 183, 8, 132, 141, 7, 174, 7, 133, 8, 145, 255 };
PROGMEM const char _dict_standard_word_502[] = "handstands";
PROGMEM const uint8_t _dict_standard_code_502[] = { 183, 132, 141, 174, 187, 191, 132, 141, 176, 187, 255 };
PROGMEM const char _dict_standard_word_503[] = "happen";
PROGMEM const uint8_t _dict_standard_code_503[] = { 183, 132, 199, 131, 141, 255 };
PROGMEM const char _dict_standard_word_504[] = "happy";
PROGMEM const uint8_t _dict_standard_code_504[] = { 183, 132, 198, 128, 255 };
PROGMEM const char _dict_standard_word_505[] = "hard";
PROGMEM const uint8_t _dict_standard_code_505[] = { 184, 152, 177, 255 };
PROGMEM const char _dict_standard_word_506[] = "hat";
PROGMEM const uint8_t _dict_standard_code_506[] = { 183, 8, 132, 191, 255 };
PROGMEM const char _dict_standard_word_507[] = "have";
PROGMEM const uint8_t _dict_standard_code_507[] = { 183, 8, 132, 166, 255 };
PROGMEM const char _dict_standard_word_508[] = "he";
PROGMEM const uint8_t _dict_standard_code_508[] = { 183, 128, 255 };
PROGMEM const char _dict_standard_word_509[] = "head";
PROGMEM const uint8_t _dict_standard_code_509[] = { 183, 8, 131, 174, 255 };
PROGMEM const char _dict_standard_word_510[] = "health";
PROGMEM const uint8_t _dict_standard_code_510[] = { 183, 8, 131, 145, 8, 190, 255 };
PROGMEM const char _dict_standard_word_511[] = "hear";
PROGMEM const uint8_t _dict_standard_code_511[] = { 183, 149, 255 };
PROGMEM const char _dict_standard_word_512[] = "heart";
PROGMEM const uint8_t _dict_standard_code_512[] = { 183, 152, 191, 255 };
PROGMEM const char _dict_standard_word_513[] = "heat";
PROGMEM const uint8_t _dict_standard_code_513[] = { 183, 8, 128, 191, 255 };
PROGMEM const char _dict_standard_word_514[] = "heavy";
PROGMEM const uint8_t _dict_standard_code_514[] = { 183, 131, 166, 128, 255 };
PROGMEM const char _dict_standard_word_515[] = "hell";
PROGMEM const uint8_t _dict_standard_code_515[] = { 183, 131, 145, 145, 255 };
PROGMEM const char _dict_standard_word_516[] = "hello";
PROGMEM const uint8_t _dict_standard_code_516[] = { 183, 7, 159, 146, 164, 255 };
PROGMEM const char _dict_standard_word_517[] = "help";
PROGMEM const uint8_t _dict_standard_code_517[] = { 183, 159, 199, 255 };
PROGMEM const char _dict_standard_word_518[] = "her";
PROGMEM const uint8_t _dict_standard_code_518[] = { 183, 151, 255 };
PROGMEM const char _dict_standard_word_519[] = "here";
PROGMEM const uint8_t _dict_standard_code_519[] = { 183, 149, 255 };
PROGMEM const char _dict_standard_word_520[] = "hers";
PROGMEM const uint8_t _dict_standard_code_520[] = { 183, 7, 151, 167, 255 };
PROGMEM const char _dict_standard_word_521[] = "herself";
PROGMEM const uint8_t _dict_standard_code_521[] = { 183, 7, 151, 187, 131, 146, 186, 255 };
PROGMEM const char _dict_standard_word_522[] = "hex";
PROGMEM const uint8_t _dict_standard_code_522[] = { 183, 8, 131, 194, 187, 255 };
PROGMEM const char _dict_standard_word_523[] = "hexagon";
PROGMEM const uint8_t _dict_standard_code_523[] = { 183, 131, 194, 187, 7, 133, 179, 135, 142, 255 };
PROGMEM const char _dict_standard_word_524[] = "hi";
PROGMEM const uint8_t _dict_standard_code_524[] = { 184, 155, 255 };
PROGMEM const char _dict_standard_word_525[] = "hide";
PROGMEM const uint8_t _dict_standard_code_525[] = { 184, 155, 4, 8, 176, 255 };
PROGMEM const char _dict_standard_word_526[] = "high";
PROGMEM const uint8_t _dict_standard_code_526[] = { 184, 155, 255 };
PROGMEM const char _dict_standard_word_527[] = "him";
PROGMEM const uint8_t _dict_standard_code_527[] = { 183, 8, 129, 140, 255 };
PROGMEM const char _dict_standard_word_528[] = "himself";
PROGMEM const uint8_t _dict_standard_code_528[] = { 183, 129, 140, 187, 131, 146, 186, 255 };
PROGMEM const char _dict_standard_word_529[] = "his";
PROGMEM const uint8_t _dict_standard_code_529[] = { 183, 129, 167, 255 };
PROGMEM const char _dict_standard_word_530[] = "hit";
PROGMEM const uint8_t _dict_standard_code_530[] = { 183, 129, 191, 255 };
PROGMEM const char _dict_standard_word_531[] = "hobbies";
PROGMEM const uint8_t _dict_standard_code_531[] = { 184, 135, 7, 170, 8, 128, 7, 187, 255 };
PROGMEM const char _dict_standard_word_532[] = "hobby";
PROGMEM const uint8_t _dict_standard_code_532[] = { 184, 135, 7, 170, 8, 128, 255 };
PROGMEM const char _dict_standard_word_533[] = "hoe";
PROGMEM const uint8_t _dict_standard_code_533[] = { 183, 137, 164, 255 };
PROGMEM const char _dict_standard_word_534[] = "hold";
PROGMEM const uint8_t _dict_standard_code_534[] = { 184, 137, 8, 146, 177, 255 };
PROGMEM const char _dict_standard_word_535[] = "hole";
PROGMEM const uint8_t _dict_standard_code_535[] = { 184, 164, 8, 146, 255 };
PROGMEM const char _dict_standard_word_536[] = "holiday";
PROGMEM const uint8_t _dict_standard_code_536[] = { 184, 135, 145, 129, 174, 154, 255 };
PROGMEM const char _dict_standard_word_537[] = "hollow";
PROGMEM const uint8_t _dict_standard_code_537[] = { 184, 135, 146, 7, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_538[] = "home";
PROGMEM const uint8_t _dict_standard_code_538[] = { 184, 137, 137, 8, 140, 255 };
PROGMEM const char _dict_standard_word_539[] = "honest";
PROGMEM const uint8_t _dict_standard_code_539[] = { 135, 141, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_540[] = "honey";
PROGMEM const uint8_t _dict_standard_code_540[] = { 184, 134, 141, 128, 255 };
PROGMEM const char _dict_standard_word_541[] = "hook";
PROGMEM const uint8_t _dict_standard_code_541[] = { 184, 138, 197, 255 };
PROGMEM const char _dict_standard_word_542[] = "hop";
PROGMEM const uint8_t _dict_standard_code_542[] = { 184, 135, 199, 255 };
PROGMEM const char _dict_standard_word_543[] = "horn";
PROGMEM const uint8_t _dict_standard_code_543[] = { 184, 153, 141, 255 };
PROGMEM const char _dict_standard_word_544[] = "horse";
PROGMEM const uint8_t _dict_standard_code_544[] = { 184, 153, 187, 255 };
PROGMEM const char _dict_standard_word_545[] = "hot";
PROGMEM const uint8_t _dict_standard_code_545[] = { 183, 135, 191, 255 };
PROGMEM const char _dict_standard_word_546[] = "hour";
PROGMEM const uint8_t _dict_standard_code_546[] = { 163, 148, 255 };
PROGMEM const char _dict_standard_word_547[] = "house";
PROGMEM const uint8_t _dict_standard_code_547[] = { 184, 163, 187, 255 };
PROGMEM const char _dict_standard_word_548[] = "how";
PROGMEM const uint8_t _dict_standard_code_548[] = { 184, 8, 163, 255 };
PROGMEM const char _dict_standard_word_549[] = "hug";
PROGMEM const uint8_t _dict_standard_code_549[] = { 184, 8, 134, 8, 181, 255 };
PROGMEM const char _dict_standard_word_550[] = "human";
PROGMEM const uint8_t _dict_standard_code_550[] = { 183, 7, 160, 140, 131, 141, 255 };
PROGMEM const char _dict_standard_word_551[] = "humaniod";
PROGMEM const uint8_t _dict_standard_code_551[] = { 184, 7, 160, 140, 134, 7, 142, 7, 137, 7, 156, 176, 255 };
PROGMEM const char _dict_standard_word_552[] = "hundred";
PROGMEM const uint8_t _dict_standard_code_552[] = { 184, 134, 141, 176, 7, 148, 131, 176, 255 };
PROGMEM const char _dict_standard_word_553[] = "hung";
PROGMEM const uint8_t _dict_standard_code_553[] = { 183, 8, 134, 8, 144, 255 };
PROGMEM const char _dict_standard_word_554[] = "hunger";
PROGMEM const uint8_t _dict_standard_code_554[] = { 184, 134, 7, 143, 178, 148, 255 };
PROGMEM const char _dict_standard_word_555[] = "hungry";
PROGMEM const uint8_t _dict_standard_code_555[] = { 184, 134, 143, 178, 7, 148, 128, 255 };
PROGMEM const char _dict_standard_word_556[] = "hurry";
PROGMEM const uint8_t _dict_standard_code_556[] = { 184, 151, 128, 255 };
PROGMEM const char _dict_standard_word_557[] = "hurt";
PROGMEM const uint8_t _dict_standard_code_557[] = { 184, 151, 191, 255 };
PROGMEM const char _dict_standard_word_558[] = "i";
PROGMEM const uint8_t _dict_standard_code_558[] = { 157, 255 };
PROGMEM const char _dict_standard_word_559[] = "ice";
PROGMEM const uint8_t _dict_standard_code_559[] = { 155, 187, 187, 255 };
PROGMEM const char _dict_standard_word_560[] = "icecream";
PROGMEM const uint8_t _dict_standard_code_560[] = { 7, 155, 7, 128, 8, 187, 7, 4, 194, 148, 128, 140, 255 };
PROGMEM const char _dict_standard_word_561[] = "if";
PROGMEM const uint8_t _dict_standard_code_561[] = { 129, 186, 186, 255 };
PROGMEM const char _dict_standard_word_562[] = "ill";
PROGMEM const uint8_t _dict_standard_code_562[] = { 129, 146, 255 };
PROGMEM const char _dict_standard_word_563[] = "in";
PROGMEM const uint8_t _dict_standard_code_563[] = { 8, 129, 8, 141, 255 };
PROGMEM const char _dict_standard_word_564[] = "infinitive";
PROGMEM const uint8_t _dict_standard_code_564[] = { 8, 129, 7, 141, 8, 186, 129, 141, 129, 191, 129, 166, 255 };
PROGMEM const char _dict_standard_word_565[] = "injure";
PROGMEM const uint8_t _dict_standard_code_565[] = { 8, 129, 141, 165, 7, 151, 255 };
PROGMEM const char _dict_standard_word_566[] = "innovate";
PROGMEM const uint8_t _dict_standard_code_566[] = { 8, 129, 141, 7, 137, 166, 154, 191, 255 };
PROGMEM const char _dict_standard_word_567[] = "innovations";
PROGMEM const uint8_t _dict_standard_code_567[] = { 8, 129, 141, 7, 137, 166, 7, 154, 189, 133, 142, 187, 255 };
PROGMEM const char _dict_standard_word_568[] = "insect";
PROGMEM const uint8_t _dict_standard_code_568[] = { 129, 141, 187, 131, 194, 191, 255 };
PROGMEM const char _dict_standard_word_569[] = "inside";
PROGMEM const uint8_t _dict_standard_code_569[] = { 129, 141, 8, 187, 155, 176, 255 };
PROGMEM const char _dict_standard_word_570[] = "instead";
PROGMEM const uint8_t _dict_standard_code_570[] = { 129, 141, 187, 191, 8, 14, 131, 176, 255 };
PROGMEM const char _dict_standard_word_571[] = "instruct";
PROGMEM const uint8_t _dict_standard_code_571[] = { 129, 141, 187, 191, 7, 148, 7, 133, 197, 191, 255 };
PROGMEM const char _dict_standard_word_572[] = "interrupt";
PROGMEM const uint8_t _dict_standard_code_572[] = { 129, 141, 191, 133, 7, 148, 134, 198, 191, 255 };
PROGMEM const char _dict_standard_word_573[] = "into";
PROGMEM const uint8_t _dict_standard_code_573[] = { 129, 141, 191, 162, 255 };
PROGMEM const char _dict_standard_word_574[] = "intrigue";
PROGMEM const uint8_t _dict_standard_code_574[] = { 129, 141, 191, 7, 148, 128, 180, 255 };
PROGMEM const char _dict_standard_word_575[] = "intrigued";
PROGMEM const uint8_t _dict_standard_code_575[] = { 129, 141, 191, 7, 148, 128, 178, 176, 255 };
PROGMEM const char _dict_standard_word_576[] = "intrigues";
PROGMEM const uint8_t _dict_standard_code_576[] = { 129, 141, 191, 7, 148, 128, 178, 167, 255 };
PROGMEM const char _dict_standard_word_577[] = "intriguing";
PROGMEM const uint8_t _dict_standard_code_577[] = { 129, 141, 191, 7, 148, 128, 178, 129, 143, 255 };
PROGMEM const char _dict_standard_word_578[] = "intruder";
PROGMEM const uint8_t _dict_standard_code_578[] = { 129, 141, 191, 148, 139, 7, 174, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_579[] = "investigate";
PROGMEM const uint8_t _dict_standard_code_579[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 255 };
PROGMEM const char _dict_standard_word_580[] = "investigated";
PROGMEM const uint8_t _dict_standard_code_580[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_581[] = "investigates";
PROGMEM const uint8_t _dict_standard_code_581[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 187, 255 };
PROGMEM const char _dict_standard_word_582[] = "investigating";
PROGMEM const uint8_t _dict_standard_code_582[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_583[] = "investigator";
PROGMEM const uint8_t _dict_standard_code_583[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_584[] = "investigators";
PROGMEM const uint8_t _dict_standard_code_584[] = { 7, 129, 141, 166, 131, 187, 191, 129, 178, 7, 130, 7, 154, 191, 7, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_585[] = "invite";
PROGMEM const uint8_t _dict_standard_code_585[] = { 7, 129, 141, 166, 155, 191, 255 };
PROGMEM const char _dict_standard_word_586[] = "iota";
PROGMEM const uint8_t _dict_standard_code_586[] = { 155, 137, 191, 134, 255 };
PROGMEM const char _dict_standard_word_587[] = "iron";
PROGMEM const uint8_t _dict_standard_code_587[] = { 7, 135, 7, 157, 7, 133, 148, 142, 255 };
PROGMEM const char _dict_standard_word_588[] = "is";
PROGMEM const uint8_t _dict_standard_code_588[] = { 8, 129, 167, 255 };
PROGMEM const char _dict_standard_word_589[] = "island";
PROGMEM const uint8_t _dict_standard_code_589[] = { 7, 157, 7, 129, 145, 131, 141, 175, 255 };
PROGMEM const char _dict_standard_word_590[] = "it";
PROGMEM const uint8_t _dict_standard_code_590[] = { 8, 129, 8, 191, 255 };
PROGMEM const char _dict_standard_word_591[] = "j";
PROGMEM const uint8_t _dict_standard_code_591[] = { 165, 154, 255 };
PROGMEM const char _dict_standard_word_592[] = "jacket";
PROGMEM const uint8_t _dict_standard_code_592[] = { 165, 132, 194, 129, 191, 255 };
PROGMEM const char _dict_standard_word_593[] = "jam";
PROGMEM const uint8_t _dict_standard_code_593[] = { 165, 8, 132, 8, 140, 255 };
PROGMEM const char _dict_standard_word_594[] = "january";
PROGMEM const uint8_t _dict_standard_code_594[] = { 165, 132, 141, 7, 160, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_595[] = "jar";
PROGMEM const uint8_t _dict_standard_code_595[] = { 165, 152, 255 };
PROGMEM const char _dict_standard_word_596[] = "jelly";
PROGMEM const uint8_t _dict_standard_code_596[] = { 165, 131, 145, 128, 255 };
PROGMEM const char _dict_standard_word_597[] = "jet";
PROGMEM const uint8_t _dict_standard_code_597[] = { 165, 131, 131, 191, 255 };
PROGMEM const char _dict_standard_word_598[] = "job";
PROGMEM const uint8_t _dict_standard_code_598[] = { 165, 136, 136, 4, 173, 255 };
PROGMEM const char _dict_standard_word_599[] = "joke";
PROGMEM const uint8_t _dict_standard_code_599[] = { 7, 165, 8, 137, 197, 255 };
PROGMEM const char _dict_standard_word_600[] = "joy";
PROGMEM const uint8_t _dict_standard_code_600[] = { 165, 156, 255 };
PROGMEM const char _dict_standard_word_601[] = "judge";
PROGMEM const uint8_t _dict_standard_code_601[] = { 165, 133, 133, 176, 165, 255 };
PROGMEM const char _dict_standard_word_602[] = "juice";
PROGMEM const uint8_t _dict_standard_code_602[] = { 165, 160, 187, 187, 255 };
PROGMEM const char _dict_standard_word_603[] = "july";
PROGMEM const uint8_t _dict_standard_code_603[] = { 165, 7, 162, 145, 157, 255 };
PROGMEM const char _dict_standard_word_604[] = "jump";
PROGMEM const uint8_t _dict_standard_code_604[] = { 165, 134, 140, 199, 255 };
PROGMEM const char _dict_standard_word_605[] = "jumped";
PROGMEM const uint8_t _dict_standard_code_605[] = { 165, 133, 140, 198, 191, 255 };
PROGMEM const char _dict_standard_word_606[] = "june";
PROGMEM const uint8_t _dict_standard_code_606[] = { 165, 160, 142, 255 };
PROGMEM const char _dict_standard_word_607[] = "just";
PROGMEM const uint8_t _dict_standard_code_607[] = { 165, 133, 187, 191, 255 };
PROGMEM const char _dict_standard_word_608[] = "k";
PROGMEM const uint8_t _dict_standard_code_608[] = { 194, 154, 255 };
PROGMEM const char _dict_standard_word_609[] = "kangaroo";
PROGMEM const uint8_t _dict_standard_code_609[] = { 194, 132, 7, 128, 143, 7, 133, 148, 138, 138, 255 };
PROGMEM const char _dict_standard_word_610[] = "kappa";
PROGMEM const uint8_t _dict_standard_code_610[] = { 194, 132, 199, 134, 255 };
PROGMEM const char _dict_standard_word_611[] = "keep";
PROGMEM const uint8_t _dict_standard_code_611[] = { 194, 8, 128, 198, 255 };
PROGMEM const char _dict_standard_word_612[] = "key";
PROGMEM const uint8_t _dict_standard_code_612[] = { 194, 128, 128, 255 };
PROGMEM const char _dict_standard_word_613[] = "kick";
PROGMEM const uint8_t _dict_standard_code_613[] = { 194, 129, 194, 255 };
PROGMEM const char _dict_standard_word_614[] = "kitchen";
PROGMEM const uint8_t _dict_standard_code_614[] = { 194, 129, 182, 131, 141, 255 };
PROGMEM const char _dict_standard_word_615[] = "kite";
PROGMEM const uint8_t _dict_standard_code_615[] = { 194, 157, 191, 255 };
PROGMEM const char _dict_standard_word_616[] = "knee";
PROGMEM const uint8_t _dict_standard_code_616[] = { 141, 128, 128, 255 };
PROGMEM const char _dict_standard_word_617[] = "knife";
PROGMEM const uint8_t _dict_standard_code_617[] = { 141, 155, 186, 255 };
PROGMEM const char _dict_standard_word_618[] = "knob";
PROGMEM const uint8_t _dict_standard_code_618[] = { 142, 135, 135, 173, 255 };
PROGMEM const char _dict_standard_word_619[] = "knock";
PROGMEM const uint8_t _dict_standard_code_619[] = { 141, 135, 195, 255 };
PROGMEM const char _dict_standard_word_620[] = "knot";
PROGMEM const uint8_t _dict_standard_code_620[] = { 141, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_621[] = "know";
PROGMEM const uint8_t _dict_standard_code_621[] = { 142, 137, 164, 255 };
PROGMEM const char _dict_standard_word_622[] = "l";
PROGMEM const uint8_t _dict_standard_code_622[] = { 131, 159, 255 };
PROGMEM const char _dict_standard_word_623[] = "la";
PROGMEM const uint8_t _dict_standard_code_623[] = { 146, 135, 135, 255 };
PROGMEM const char _dict_standard_word_624[] = "ladder";
PROGMEM const uint8_t _dict_standard_code_624[] = { 145, 132, 174, 151, 255 };
PROGMEM const char _dict_standard_word_625[] = "lake";
PROGMEM const uint8_t _dict_standard_code_625[] = { 145, 154, 196, 255 };
PROGMEM const char _dict_standard_word_626[] = "lambda";
PROGMEM const uint8_t _dict_standard_code_626[] = { 145, 132, 140, 175, 134, 255 };
PROGMEM const char _dict_standard_word_627[] = "lamp";
PROGMEM const uint8_t _dict_standard_code_627[] = { 145, 132, 140, 199, 255 };
PROGMEM const char _dict_standard_word_628[] = "land";
PROGMEM const uint8_t _dict_standard_code_628[] = { 145, 132, 141, 175, 255 };
PROGMEM const char _dict_standard_word_629[] = "lapel";
PROGMEM const uint8_t _dict_standard_code_629[] = { 145, 134, 198, 131, 159, 255 };
PROGMEM const char _dict_standard_word_630[] = "large";
PROGMEM const uint8_t _dict_standard_code_630[] = { 145, 152, 165, 255 };
PROGMEM const char _dict_standard_word_631[] = "last";
PROGMEM const uint8_t _dict_standard_code_631[] = { 145, 8, 132, 187, 191, 255 };
PROGMEM const char _dict_standard_word_632[] = "late";
PROGMEM const uint8_t _dict_standard_code_632[] = { 145, 154, 191, 255 };
PROGMEM const char _dict_standard_word_633[] = "laugh";
PROGMEM const uint8_t _dict_standard_code_633[] = { 145, 132, 132, 186, 255 };
PROGMEM const char _dict_standard_word_634[] = "lay";
PROGMEM const uint8_t _dict_standard_code_634[] = { 145, 154, 7, 128, 255 };
PROGMEM const char _dict_standard_word_635[] = "lazy";
PROGMEM const uint8_t _dict_standard_code_635[] = { 145, 154, 7, 167, 128, 255 };
PROGMEM const char _dict_standard_word_636[] = "lead";
PROGMEM const uint8_t _dict_standard_code_636[] = { 145, 131, 131, 176, 255 };
PROGMEM const char _dict_standard_word_637[] = "leaf";
PROGMEM const uint8_t _dict_standard_code_637[] = { 145, 128, 186, 255 };
PROGMEM const char _dict_standard_word_638[] = "lean";
PROGMEM const uint8_t _dict_standard_code_638[] = { 145, 128, 141, 255 };
PROGMEM const char _dict_standard_word_639[] = "leap";
PROGMEM const uint8_t _dict_standard_code_639[] = { 145, 128, 198, 255 };
PROGMEM const char _dict_standard_word_640[] = "learn";
PROGMEM const uint8_t _dict_standard_code_640[] = { 145, 151, 141, 255 };
PROGMEM const char _dict_standard_word_641[] = "leash";
PROGMEM const uint8_t _dict_standard_code_641[] = { 145, 128, 128, 189, 189, 255 };
PROGMEM const char _dict_standard_word_642[] = "leave";
PROGMEM const uint8_t _dict_standard_code_642[] = { 145, 128, 166, 255 };
PROGMEM const char _dict_standard_word_643[] = "left";
PROGMEM const uint8_t _dict_standard_code_643[] = { 145, 131, 186, 191, 255 };
PROGMEM const char _dict_standard_word_644[] = "leg";
PROGMEM const uint8_t _dict_standard_code_644[] = { 145, 131, 180, 255 };
PROGMEM const char _dict_standard_word_645[] = "legislate";
PROGMEM const uint8_t _dict_standard_code_645[] = { 145, 131, 165, 131, 187, 145, 7, 154, 191, 255 };
PROGMEM const char _dict_standard_word_646[] = "legislated";
PROGMEM const uint8_t _dict_standard_code_646[] = { 145, 131, 165, 131, 187, 145, 7, 154, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_647[] = "legislates";
PROGMEM const uint8_t _dict_standard_code_647[] = { 145, 131, 165, 131, 187, 145, 7, 154, 191, 187, 255 };
PROGMEM const char _dict_standard_word_648[] = "legislating";
PROGMEM const uint8_t _dict_standard_code_648[] = { 145, 131, 165, 131, 187, 145, 7, 154, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_649[] = "legislature";
PROGMEM const uint8_t _dict_standard_code_649[] = { 145, 131, 165, 131, 187, 145, 7, 154, 182, 151, 255 };
PROGMEM const char _dict_standard_word_650[] = "lei";
PROGMEM const uint8_t _dict_standard_code_650[] = { 145, 154, 255 };
PROGMEM const char _dict_standard_word_651[] = "lemon";
PROGMEM const uint8_t _dict_standard_code_651[] = { 145, 131, 140, 133, 141, 255 };
PROGMEM const char _dict_standard_word_652[] = "length";
PROGMEM const uint8_t _dict_standard_code_652[] = { 145, 131, 143, 190, 255 };
PROGMEM const char _dict_standard_word_653[] = "less";
PROGMEM const uint8_t _dict_standard_code_653[] = { 145, 131, 187, 187, 255 };
PROGMEM const char _dict_standard_word_654[] = "let";
PROGMEM const uint8_t _dict_standard_code_654[] = { 145, 131, 191, 255 };
PROGMEM const char _dict_standard_word_655[] = "letter";
PROGMEM const uint8_t _dict_standard_code_655[] = { 145, 131, 191, 133, 148, 255 };
PROGMEM const char _dict_standard_word_656[] = "lettuce";
PROGMEM const uint8_t _dict_standard_code_656[] = { 145, 131, 191, 133, 187, 187, 255 };
PROGMEM const char _dict_standard_word_657[] = "library";
PROGMEM const uint8_t _dict_standard_code_657[] = { 145, 155, 172, 148, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_658[] = "lid";
PROGMEM const uint8_t _dict_standard_code_658[] = { 145, 8, 129, 176, 255 };
PROGMEM const char _dict_standard_word_659[] = "lie";
PROGMEM const uint8_t _dict_standard_code_659[] = { 145, 155, 7, 128, 255 };
PROGMEM const char _dict_standard_word_660[] = "lift";
PROGMEM const uint8_t _dict_standard_code_660[] = { 145, 129, 186, 191, 255 };
PROGMEM const char _dict_standard_word_661[] = "light";
PROGMEM const uint8_t _dict_standard_code_661[] = { 145, 155, 191, 255 };
PROGMEM const char _dict_standard_word_662[] = "like";
PROGMEM const uint8_t _dict_standard_code_662[] = { 145, 7, 135, 7, 155, 196, 255 };
PROGMEM const char _dict_standard_word_663[] = "line";
PROGMEM const uint8_t _dict_standard_code_663[] = { 145, 155, 141, 255 };
PROGMEM const char _dict_standard_word_664[] = "linguist";
PROGMEM const uint8_t _dict_standard_code_664[] = { 145, 129, 143, 7, 147, 129, 187, 191, 255 };
PROGMEM const char _dict_standard_word_665[] = "lion";
PROGMEM const uint8_t _dict_standard_code_665[] = { 145, 155, 133, 141, 255 };
PROGMEM const char _dict_standard_word_666[] = "liquid";
PROGMEM const uint8_t _dict_standard_code_666[] = { 145, 129, 194, 7, 147, 129, 176, 255 };
PROGMEM const char _dict_standard_word_667[] = "listen";
PROGMEM const uint8_t _dict_standard_code_667[] = { 145, 129, 187, 131, 141, 255 };
PROGMEM const char _dict_standard_word_668[] = "lists";
PROGMEM const uint8_t _dict_standard_code_668[] = { 145, 129, 187, 193, 255 };
PROGMEM const char _dict_standard_word_669[] = "litter";
PROGMEM const uint8_t _dict_standard_code_669[] = { 145, 129, 191, 151, 255 };
PROGMEM const char _dict_standard_word_670[] = "little";
PROGMEM const uint8_t _dict_standard_code_670[] = { 145, 129, 191, 159, 255 };
PROGMEM const char _dict_standard_word_671[] = "lock";
PROGMEM const uint8_t _dict_standard_code_671[] = { 146, 135, 197, 255 };
PROGMEM const char _dict_standard_word_672[] = "long";
PROGMEM const uint8_t _dict_standard_code_672[] = { 146, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_673[] = "look";
PROGMEM const uint8_t _dict_standard_code_673[] = { 146, 8, 14, 138, 197, 255 };
PROGMEM const char _dict_standard_word_674[] = "loose";
PROGMEM const uint8_t _dict_standard_code_674[] = { 145, 139, 139, 187, 255 };
PROGMEM const char _dict_standard_word_675[] = "lose";
PROGMEM const uint8_t _dict_standard_code_675[] = { 146, 8, 139, 7, 167, 255 };
PROGMEM const char _dict_standard_word_676[] = "loud";
PROGMEM const uint8_t _dict_standard_code_676[] = { 146, 163, 175, 255 };
PROGMEM const char _dict_standard_word_677[] = "love";
PROGMEM const uint8_t _dict_standard_code_677[] = { 146, 8, 134, 8, 166, 255 };
PROGMEM const char _dict_standard_word_678[] = "low";
PROGMEM const uint8_t _dict_standard_code_678[] = { 8, 146, 164, 255 };
PROGMEM const char _dict_standard_word_679[] = "luke";
PROGMEM const uint8_t _dict_standard_code_679[] = { 145, 162, 197, 255 };
PROGMEM const char _dict_standard_word_680[] = "lunch";
PROGMEM const uint8_t _dict_standard_code_680[] = { 146, 134, 8, 141, 182, 255 };
PROGMEM const char _dict_standard_word_681[] = "lynxmotion";
PROGMEM const uint8_t _dict_standard_code_681[] = { 145, 7, 129, 143, 195, 7, 188, 7, 140, 137, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_682[] = "m";
PROGMEM const uint8_t _dict_standard_code_682[] = { 131, 131, 140, 255 };
PROGMEM const char _dict_standard_word_683[] = "machine";
PROGMEM const uint8_t _dict_standard_code_683[] = { 140, 7, 134, 8, 189, 128, 141, 255 };
PROGMEM const char _dict_standard_word_684[] = "magnevation";
PROGMEM const uint8_t _dict_standard_code_684[] = { 7, 140, 132, 178, 7, 141, 129, 166, 7, 154, 189, 133, 142, 255 };
PROGMEM const char _dict_standard_word_685[] = "mail";
PROGMEM const uint8_t _dict_standard_code_685[] = { 140, 154, 146, 255 };
PROGMEM const char _dict_standard_word_686[] = "make";
PROGMEM const uint8_t _dict_standard_code_686[] = { 140, 154, 196, 255 };
PROGMEM const char _dict_standard_word_687[] = "male";
PROGMEM const uint8_t _dict_standard_code_687[] = { 140, 154, 146, 255 };
PROGMEM const char _dict_standard_word_688[] = "mama";
PROGMEM const uint8_t _dict_standard_code_688[] = { 140, 135, 135, 140, 135, 255 };
PROGMEM const char _dict_standard_word_689[] = "man";
PROGMEM const uint8_t _dict_standard_code_689[] = { 140, 8, 132, 8, 141, 255 };
PROGMEM const char _dict_standard_word_690[] = "many";
PROGMEM const uint8_t _dict_standard_code_690[] = { 140, 131, 141, 128, 255 };
PROGMEM const char _dict_standard_word_691[] = "march";
PROGMEM const uint8_t _dict_standard_code_691[] = { 140, 152, 182, 255 };
PROGMEM const char _dict_standard_word_692[] = "marry";
PROGMEM const uint8_t _dict_standard_code_692[] = { 140, 150, 128, 255 };
PROGMEM const char _dict_standard_word_693[] = "match";
PROGMEM const uint8_t _dict_standard_code_693[] = { 140, 132, 8, 182, 255 };
PROGMEM const char _dict_standard_word_694[] = "may";
PROGMEM const uint8_t _dict_standard_code_694[] = { 140, 154, 255 };
PROGMEM const char _dict_standard_word_695[] = "maybe";
PROGMEM const uint8_t _dict_standard_code_695[] = { 140, 154, 172, 128, 255 };
PROGMEM const char _dict_standard_word_696[] = "me";
PROGMEM const uint8_t _dict_standard_code_696[] = { 140, 128, 128, 255 };
PROGMEM const char _dict_standard_word_697[] = "mean";
PROGMEM const uint8_t _dict_standard_code_697[] = { 140, 8, 128, 141, 255 };
PROGMEM const char _dict_standard_word_698[] = "measure";
PROGMEM const uint8_t _dict_standard_code_698[] = { 140, 131, 168, 7, 151, 255 };
PROGMEM const char _dict_standard_word_699[] = "measures";
PROGMEM const uint8_t _dict_standard_code_699[] = { 140, 131, 168, 7, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_700[] = "melt";
PROGMEM const uint8_t _dict_standard_code_700[] = { 140, 131, 145, 191, 255 };
PROGMEM const char _dict_standard_word_701[] = "memories";
PROGMEM const uint8_t _dict_standard_code_701[] = { 140, 131, 140, 7, 151, 128, 7, 167, 255 };
PROGMEM const char _dict_standard_word_702[] = "memory";
PROGMEM const uint8_t _dict_standard_code_702[] = { 140, 131, 140, 7, 151, 128, 255 };
PROGMEM const char _dict_standard_word_703[] = "men";
PROGMEM const uint8_t _dict_standard_code_703[] = { 140, 131, 131, 141, 255 };
PROGMEM const char _dict_standard_word_704[] = "mend";
PROGMEM const uint8_t _dict_standard_code_704[] = { 140, 131, 141, 177, 255 };
PROGMEM const char _dict_standard_word_705[] = "merry";
PROGMEM const uint8_t _dict_standard_code_705[] = { 140, 131, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_706[] = "metal";
PROGMEM const uint8_t _dict_standard_code_706[] = { 140, 131, 191, 159, 255 };
PROGMEM const char _dict_standard_word_707[] = "mice";
PROGMEM const uint8_t _dict_standard_code_707[] = { 140, 7, 135, 7, 155, 187, 187, 255 };
PROGMEM const char _dict_standard_word_708[] = "middle";
PROGMEM const uint8_t _dict_standard_code_708[] = { 140, 129, 175, 146, 255 };
PROGMEM const char _dict_standard_word_709[] = "might";
PROGMEM const uint8_t _dict_standard_code_709[] = { 140, 7, 135, 7, 155, 191, 255 };
PROGMEM const char _dict_standard_word_710[] = "milk";
PROGMEM const uint8_t _dict_standard_code_710[] = { 140, 129, 7, 145, 196, 255 };
PROGMEM const char _dict_standard_word_711[] = "million";
PROGMEM const uint8_t _dict_standard_code_711[] = { 140, 129, 7, 145, 7, 158, 8, 141, 255 };
PROGMEM const char _dict_standard_word_712[] = "mind";
PROGMEM const uint8_t _dict_standard_code_712[] = { 140, 7, 157, 7, 129, 141, 177, 255 };
PROGMEM const char _dict_standard_word_713[] = "mine";
PROGMEM const uint8_t _dict_standard_code_713[] = { 140, 155, 141, 255 };
PROGMEM const char _dict_standard_word_714[] = "minus";
PROGMEM const uint8_t _dict_standard_code_714[] = { 140, 7, 157, 7, 129, 7, 142, 8, 134, 187, 255 };
PROGMEM const char _dict_standard_word_715[] = "minute";
PROGMEM const uint8_t _dict_standard_code_715[] = { 140, 7, 129, 141, 129, 191, 255 };
PROGMEM const char _dict_standard_word_716[] = "mirror";
PROGMEM const uint8_t _dict_standard_code_716[] = { 140, 149, 153, 255 };
PROGMEM const char _dict_standard_word_717[] = "mistake";
PROGMEM const uint8_t _dict_standard_code_717[] = { 140, 7, 129, 187, 191, 154, 196, 255 };
PROGMEM const char _dict_standard_word_718[] = "mitten";
PROGMEM const uint8_t _dict_standard_code_718[] = { 140, 129, 8, 191, 7, 130, 141, 255 };
PROGMEM const char _dict_standard_word_719[] = "mix";
PROGMEM const uint8_t _dict_standard_code_719[] = { 140, 129, 194, 187, 255 };
PROGMEM const char _dict_standard_word_720[] = "monday";
PROGMEM const uint8_t _dict_standard_code_720[] = { 140, 134, 141, 174, 154, 255 };
PROGMEM const char _dict_standard_word_721[] = "money";
PROGMEM const uint8_t _dict_standard_code_721[] = { 140, 134, 141, 128, 255 };
PROGMEM const char _dict_standard_word_722[] = "monkey";
PROGMEM const uint8_t _dict_standard_code_722[] = { 140, 134, 141, 194, 128, 255 };
PROGMEM const char _dict_standard_word_723[] = "month";
PROGMEM const uint8_t _dict_standard_code_723[] = { 140, 134, 141, 190, 255 };
PROGMEM const char _dict_standard_word_724[] = "moon";
PROGMEM const uint8_t _dict_standard_code_724[] = { 140, 139, 141, 255 };
PROGMEM const char _dict_standard_word_725[] = "more";
PROGMEM const uint8_t _dict_standard_code_725[] = { 140, 7, 137, 153, 255 };
PROGMEM const char _dict_standard_word_726[] = "morning";
PROGMEM const uint8_t _dict_standard_code_726[] = { 140, 7, 137, 7, 153, 141, 129, 143, 255 };
PROGMEM const char _dict_standard_word_727[] = "most";
PROGMEM const uint8_t _dict_standard_code_727[] = { 140, 8, 137, 187, 191, 255 };
PROGMEM const char _dict_standard_word_728[] = "mother";
PROGMEM const uint8_t _dict_standard_code_728[] = { 140, 134, 190, 7, 151, 255 };
PROGMEM const char _dict_standard_word_729[] = "motor";
PROGMEM const uint8_t _dict_standard_code_729[] = { 140, 137, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_730[] = "mountain";
PROGMEM const uint8_t _dict_standard_code_730[] = { 140, 7, 163, 141, 191, 130, 141, 255 };
PROGMEM const char _dict_standard_word_731[] = "mouse";
PROGMEM const uint8_t _dict_standard_code_731[] = { 140, 163, 187, 255 };
PROGMEM const char _dict_standard_word_732[] = "mouth";
PROGMEM const uint8_t _dict_standard_code_732[] = { 140, 163, 8, 190, 255 };
PROGMEM const char _dict_standard_word_733[] = "move";
PROGMEM const uint8_t _dict_standard_code_733[] = { 140, 8, 139, 166, 255 };
PROGMEM const char _dict_standard_word_734[] = "mu";
PROGMEM const uint8_t _dict_standard_code_734[] = { 140, 160, 255 };
PROGMEM const char _dict_standard_word_735[] = "much";
PROGMEM const uint8_t _dict_standard_code_735[] = { 140, 134, 182, 255 };
PROGMEM const char _dict_standard_word_736[] = "mud";
PROGMEM const uint8_t _dict_standard_code_736[] = { 140, 8, 134, 175, 255 };
PROGMEM const char _dict_standard_word_737[] = "museum";
PROGMEM const uint8_t _dict_standard_code_737[] = { 140, 160, 7, 167, 128, 7, 134, 140, 255 };
PROGMEM const char _dict_standard_word_738[] = "music";
PROGMEM const uint8_t _dict_standard_code_738[] = { 140, 160, 167, 129, 196, 255 };
PROGMEM const char _dict_standard_word_739[] = "must";
PROGMEM const uint8_t _dict_standard_code_739[] = { 140, 134, 187, 191, 255 };
PROGMEM const char _dict_standard_word_740[] = "my";
PROGMEM const uint8_t _dict_standard_code_740[] = { 140, 155, 255 };
PROGMEM const char _dict_standard_word_741[] = "myself";
PROGMEM const uint8_t _dict_standard_code_741[] = { 140, 155, 187, 131, 145, 186, 255 };
PROGMEM const char _dict_standard_word_742[] = "n";
PROGMEM const uint8_t _dict_standard_code_742[] = { 131, 131, 141, 255 };
PROGMEM const char _dict_standard_word_743[] = "nail";
PROGMEM const uint8_t _dict_standard_code_743[] = { 141, 154, 146, 255 };
PROGMEM const char _dict_standard_word_744[] = "name";
PROGMEM const uint8_t _dict_standard_code_744[] = { 141, 154, 140, 255 };
PROGMEM const char _dict_standard_word_745[] = "narrow";
PROGMEM const uint8_t _dict_standard_code_745[] = { 141, 150, 164, 255 };
PROGMEM const char _dict_standard_word_746[] = "nation";
PROGMEM const uint8_t _dict_standard_code_746[] = { 141, 154, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_747[] = "near";
PROGMEM const uint8_t _dict_standard_code_747[] = { 141, 149, 255 };
PROGMEM const char _dict_standard_word_748[] = "nearly";
PROGMEM const uint8_t _dict_standard_code_748[] = { 141, 7, 149, 145, 128, 255 };
PROGMEM const char _dict_standard_word_749[] = "neck";
PROGMEM const uint8_t _dict_standard_code_749[] = { 141, 131, 196, 255 };
PROGMEM const char _dict_standard_word_750[] = "need";
PROGMEM const uint8_t _dict_standard_code_750[] = { 141, 8, 128, 176, 255 };
PROGMEM const char _dict_standard_word_751[] = "needle";
PROGMEM const uint8_t _dict_standard_code_751[] = { 141, 128, 175, 146, 255 };
PROGMEM const char _dict_standard_word_752[] = "neighbor";
PROGMEM const uint8_t _dict_standard_code_752[] = { 141, 154, 172, 151, 255 };
PROGMEM const char _dict_standard_word_753[] = "neither";
PROGMEM const uint8_t _dict_standard_code_753[] = { 141, 128, 190, 7, 151, 255 };
PROGMEM const char _dict_standard_word_754[] = "net";
PROGMEM const uint8_t _dict_standard_code_754[] = { 141, 131, 191, 255 };
PROGMEM const char _dict_standard_word_755[] = "network";
PROGMEM const uint8_t _dict_standard_code_755[] = { 141, 131, 191, 7, 147, 7, 151, 196, 255 };
PROGMEM const char _dict_standard_word_756[] = "never";
PROGMEM const uint8_t _dict_standard_code_756[] = { 141, 131, 7, 166, 151, 255 };
PROGMEM const char _dict_standard_word_757[] = "new";
PROGMEM const uint8_t _dict_standard_code_757[] = { 141, 160, 255 };
PROGMEM const char _dict_standard_word_758[] = "next";
PROGMEM const uint8_t _dict_standard_code_758[] = { 141, 131, 194, 187, 191, 255 };
PROGMEM const char _dict_standard_word_759[] = "nickel";
PROGMEM const uint8_t _dict_standard_code_759[] = { 141, 129, 194, 159, 255 };
PROGMEM const char _dict_standard_word_760[] = "night";
PROGMEM const uint8_t _dict_standard_code_760[] = { 141, 155, 191, 255 };
PROGMEM const char _dict_standard_word_761[] = "nine";
PROGMEM const uint8_t _dict_standard_code_761[] = { 141, 14, 157, 141, 255 };
PROGMEM const char _dict_standard_word_762[] = "nineteen";
PROGMEM const uint8_t _dict_standard_code_762[] = { 141, 7, 15, 155, 141, 191, 128, 8, 141, 255 };
PROGMEM const char _dict_standard_word_763[] = "ninety";
PROGMEM const uint8_t _dict_standard_code_763[] = { 141, 7, 15, 155, 141, 191, 128, 255 };
PROGMEM const char _dict_standard_word_764[] = "nip";
PROGMEM const uint8_t _dict_standard_code_764[] = { 141, 129, 198, 255 };
PROGMEM const char _dict_standard_word_765[] = "nipped";
PROGMEM const uint8_t _dict_standard_code_765[] = { 141, 129, 198, 4, 191, 255 };
PROGMEM const char _dict_standard_word_766[] = "nipping";
PROGMEM const uint8_t _dict_standard_code_766[] = { 141, 129, 198, 129, 143, 255 };
PROGMEM const char _dict_standard_word_767[] = "nips";
PROGMEM const uint8_t _dict_standard_code_767[] = { 141, 129, 198, 187, 255 };
PROGMEM const char _dict_standard_word_768[] = "no";
PROGMEM const uint8_t _dict_standard_code_768[] = { 142, 164, 255 };
PROGMEM const char _dict_standard_word_769[] = "nobody";
PROGMEM const uint8_t _dict_standard_code_769[] = { 142, 137, 7, 4, 18, 171, 135, 174, 128, 255 };
PROGMEM const char _dict_standard_word_770[] = "noise";
PROGMEM const uint8_t _dict_standard_code_770[] = { 142, 156, 7, 128, 187, 255 };
PROGMEM const char _dict_standard_word_771[] = "none";
PROGMEM const uint8_t _dict_standard_code_771[] = { 142, 8, 134, 141, 255 };
PROGMEM const char _dict_standard_word_772[] = "noon";
PROGMEM const uint8_t _dict_standard_code_772[] = { 142, 8, 139, 141, 255 };
PROGMEM const char _dict_standard_word_773[] = "nose";
PROGMEM const uint8_t _dict_standard_code_773[] = { 142, 164, 167, 255 };
PROGMEM const char _dict_standard_word_774[] = "not";
PROGMEM const uint8_t _dict_standard_code_774[] = { 141, 135, 191, 255 };
PROGMEM const char _dict_standard_word_775[] = "notice";
PROGMEM const uint8_t _dict_standard_code_775[] = { 142, 137, 191, 129, 187, 255 };
PROGMEM const char _dict_standard_word_776[] = "november";
PROGMEM const uint8_t _dict_standard_code_776[] = { 142, 137, 166, 7, 131, 140, 172, 7, 151, 255 };
PROGMEM const char _dict_standard_word_777[] = "now";
PROGMEM const uint8_t _dict_standard_code_777[] = { 142, 163, 255 };
PROGMEM const char _dict_standard_word_778[] = "nu";
PROGMEM const uint8_t _dict_standard_code_778[] = { 142, 162, 255 };
PROGMEM const char _dict_standard_word_779[] = "number";
PROGMEM const uint8_t _dict_standard_code_779[] = { 141, 134, 140, 18, 171, 148, 255 };
PROGMEM const char _dict_standard_word_780[] = "nurse";
PROGMEM const uint8_t _dict_standard_code_780[] = { 142, 151, 187, 255 };
PROGMEM const char _dict_standard_word_781[] = "nut";
PROGMEM const uint8_t _dict_standard_code_781[] = { 142, 134, 191, 255 };
PROGMEM const char _dict_standard_word_782[] = "o";
PROGMEM const uint8_t _dict_standard_code_782[] = { 137, 164, 255 };
PROGMEM const char _dict_standard_word_783[] = "oar";
PROGMEM const uint8_t _dict_standard_code_783[] = { 153, 7, 148, 255 };
PROGMEM const char _dict_standard_word_784[] = "obey";
PROGMEM const uint8_t _dict_standard_code_784[] = { 8, 137, 18, 171, 154, 255 };
PROGMEM const char _dict_standard_word_785[] = "object";
PROGMEM const uint8_t _dict_standard_code_785[] = { 135, 173, 165, 131, 196, 191, 255 };
PROGMEM const char _dict_standard_word_786[] = "ocean";
PROGMEM const uint8_t _dict_standard_code_786[] = { 137, 189, 133, 141, 255 };
PROGMEM const char _dict_standard_word_787[] = "october";
PROGMEM const uint8_t _dict_standard_code_787[] = { 135, 197, 191, 137, 18, 171, 7, 151, 255 };
PROGMEM const char _dict_standard_word_788[] = "octopus";
PROGMEM const uint8_t _dict_standard_code_788[] = { 7, 135, 195, 191, 7, 133, 199, 7, 138, 187, 255 };
PROGMEM const char _dict_standard_word_789[] = "of";
PROGMEM const uint8_t _dict_standard_code_789[] = { 8, 134, 166, 255 };
PROGMEM const char _dict_standard_word_790[] = "off";
PROGMEM const uint8_t _dict_standard_code_790[] = { 135, 135, 186, 186, 255 };
PROGMEM const char _dict_standard_word_791[] = "often";
PROGMEM const uint8_t _dict_standard_code_791[] = { 135, 186, 191, 131, 141, 255 };
PROGMEM const char _dict_standard_word_792[] = "old";
PROGMEM const uint8_t _dict_standard_code_792[] = { 137, 146, 175, 255 };
PROGMEM const char _dict_standard_word_793[] = "omega";
PROGMEM const uint8_t _dict_standard_code_793[] = { 137, 140, 154, 178, 134, 255 };
PROGMEM const char _dict_standard_word_794[] = "omicron";
PROGMEM const uint8_t _dict_standard_code_794[] = { 137, 140, 129, 195, 148, 135, 142, 255 };
PROGMEM const char _dict_standard_word_795[] = "on";
PROGMEM const uint8_t _dict_standard_code_795[] = { 135, 135, 142, 255 };
PROGMEM const char _dict_standard_word_796[] = "once";
PROGMEM const uint8_t _dict_standard_code_796[] = { 147, 134, 141, 187, 255 };
PROGMEM const char _dict_standard_word_797[] = "one";
PROGMEM const uint8_t _dict_standard_code_797[] = { 147, 14, 135, 8, 141, 255 };
PROGMEM const char _dict_standard_word_798[] = "only";
PROGMEM const uint8_t _dict_standard_code_798[] = { 137, 142, 145, 128, 255 };
PROGMEM const char _dict_standard_word_799[] = "oopic";
PROGMEM const uint8_t _dict_standard_code_799[] = { 8, 139, 199, 8, 129, 196, 255 };
PROGMEM const char _dict_standard_word_800[] = "open";
PROGMEM const uint8_t _dict_standard_code_800[] = { 137, 199, 131, 142, 255 };
PROGMEM const char _dict_standard_word_801[] = "or";
PROGMEM const uint8_t _dict_standard_code_801[] = { 153, 255 };
PROGMEM const char _dict_standard_word_802[] = "orange";
PROGMEM const uint8_t _dict_standard_code_802[] = { 153, 141, 165, 255 };
PROGMEM const char _dict_standard_word_803[] = "other";
PROGMEM const uint8_t _dict_standard_code_803[] = { 134, 190, 151, 255 };
PROGMEM const char _dict_standard_word_804[] = "ouch";
PROGMEM const uint8_t _dict_standard_code_804[] = { 163, 182, 255 };
PROGMEM const char _dict_standard_word_805[] = "ought";
PROGMEM const uint8_t _dict_standard_code_805[] = { 136, 136, 191, 255 };
PROGMEM const char _dict_standard_word_806[] = "our";
PROGMEM const uint8_t _dict_standard_code_806[] = { 163, 148, 255 };
PROGMEM const char _dict_standard_word_807[] = "out";
PROGMEM const uint8_t _dict_standard_code_807[] = { 163, 191, 255 };
PROGMEM const char _dict_standard_word_808[] = "outdoors";
PROGMEM const uint8_t _dict_standard_code_808[] = { 163, 191, 8, 175, 153, 187, 255 };
PROGMEM const char _dict_standard_word_809[] = "over";
PROGMEM const uint8_t _dict_standard_code_809[] = { 8, 137, 7, 166, 151, 255 };
PROGMEM const char _dict_standard_word_810[] = "owl";
PROGMEM const uint8_t _dict_standard_code_810[] = { 163, 146, 255 };
PROGMEM const char _dict_standard_word_811[] = "own";
PROGMEM const uint8_t _dict_standard_code_811[] = { 137, 8, 141, 255 };
PROGMEM const char _dict_standard_word_812[] = "oz";
PROGMEM const uint8_t _dict_standard_code_812[] = { 135, 135, 167, 255 };
PROGMEM const char _dict_standard_word_813[] = "p";
PROGMEM const uint8_t _dict_standard_code_813[] = { 198, 128, 128, 255 };
PROGMEM const char _dict_standard_word_814[] = "package";
PROGMEM const uint8_t _dict_standard_code_814[] = { 198, 8, 132, 194, 131, 165, 255 };
PROGMEM const char _dict_standard_word_815[] = "paint";
PROGMEM const uint8_t _dict_standard_code_815[] = { 198, 7, 130, 7, 154, 141, 191, 255 };
PROGMEM const char _dict_standard_word_816[] = "paintbrush";
PROGMEM const uint8_t _dict_standard_code_816[] = { 198, 7, 154, 141, 191, 18, 171, 7, 148, 134, 189, 255 };
PROGMEM const char _dict_standard_word_817[] = "pan";
PROGMEM const uint8_t _dict_standard_code_817[] = { 199, 8, 132, 142, 255 };
PROGMEM const char _dict_standard_word_818[] = "pants";
PROGMEM const uint8_t _dict_standard_code_818[] = { 199, 132, 142, 191, 187, 255 };
PROGMEM const char _dict_standard_word_819[] = "paper";
PROGMEM const uint8_t _dict_standard_code_819[] = { 198, 7, 154, 198, 151, 255 };
PROGMEM const char _dict_standard_word_820[] = "parakeet";
PROGMEM const uint8_t _dict_standard_code_820[] = { 198, 7, 150, 134, 194, 128, 191, 255 };
PROGMEM const char _dict_standard_word_821[] = "parent";
PROGMEM const uint8_t _dict_standard_code_821[] = { 199, 132, 7, 148, 7, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_822[] = "park";
PROGMEM const uint8_t _dict_standard_code_822[] = { 199, 7, 152, 7, 148, 196, 255 };
PROGMEM const char _dict_standard_word_823[] = "parrot";
PROGMEM const uint8_t _dict_standard_code_823[] = { 198, 150, 134, 191, 255 };
PROGMEM const char _dict_standard_word_824[] = "part";
PROGMEM const uint8_t _dict_standard_code_824[] = { 199, 152, 191, 255 };
PROGMEM const char _dict_standard_word_825[] = "parts";
PROGMEM const uint8_t _dict_standard_code_825[] = { 199, 152, 193, 255 };
PROGMEM const char _dict_standard_word_826[] = "pass";
PROGMEM const uint8_t _dict_standard_code_826[] = { 199, 132, 187, 255 };
PROGMEM const char _dict_standard_word_827[] = "past";
PROGMEM const uint8_t _dict_standard_code_827[] = { 199, 132, 8, 187, 191, 255 };
PROGMEM const char _dict_standard_word_828[] = "paste";
PROGMEM const uint8_t _dict_standard_code_828[] = { 198, 154, 187, 191, 255 };
PROGMEM const char _dict_standard_word_829[] = "path";
PROGMEM const uint8_t _dict_standard_code_829[] = { 199, 132, 8, 190, 255 };
PROGMEM const char _dict_standard_word_830[] = "paw";
PROGMEM const uint8_t _dict_standard_code_830[] = { 199, 8, 135, 135, 255 };
PROGMEM const char _dict_standard_word_831[] = "pea";
PROGMEM const uint8_t _dict_standard_code_831[] = { 198, 128, 128, 255 };
PROGMEM const char _dict_standard_word_832[] = "peace";
PROGMEM const uint8_t _dict_standard_code_832[] = { 198, 8, 128, 187, 255 };
PROGMEM const char _dict_standard_word_833[] = "peach";
PROGMEM const uint8_t _dict_standard_code_833[] = { 198, 8, 128, 182, 255 };
PROGMEM const char _dict_standard_word_834[] = "peanut";
PROGMEM const uint8_t _dict_standard_code_834[] = { 198, 7, 128, 142, 134, 191, 255 };
PROGMEM const char _dict_standard_word_835[] = "pear";
PROGMEM const uint8_t _dict_standard_code_835[] = { 199, 150, 255 };
PROGMEM const char _dict_standard_word_836[] = "peck";
PROGMEM const uint8_t _dict_standard_code_836[] = { 198, 131, 131, 196, 255 };
PROGMEM const char _dict_standard_word_837[] = "peg";
PROGMEM const uint8_t _dict_standard_code_837[] = { 198, 131, 131, 8, 180, 255 };
PROGMEM const char _dict_standard_word_838[] = "pen";
PROGMEM const uint8_t _dict_standard_code_838[] = { 198, 131, 141, 255 };
PROGMEM const char _dict_standard_word_839[] = "pencil";
PROGMEM const uint8_t _dict_standard_code_839[] = { 198, 7, 131, 141, 187, 133, 146, 255 };
PROGMEM const char _dict_standard_word_840[] = "penguin";
PROGMEM const uint8_t _dict_standard_code_840[] = { 198, 130, 7, 143, 7, 147, 129, 141, 255 };
PROGMEM const char _dict_standard_word_841[] = "penny";
PROGMEM const uint8_t _dict_standard_code_841[] = { 198, 131, 141, 128, 255 };
PROGMEM const char _dict_standard_word_842[] = "people";
PROGMEM const uint8_t _dict_standard_code_842[] = { 198, 7, 128, 198, 8, 145, 255 };
PROGMEM const char _dict_standard_word_843[] = "peppers";
PROGMEM const uint8_t _dict_standard_code_843[] = { 198, 131, 199, 7, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_844[] = "perhaps";
PROGMEM const uint8_t _dict_standard_code_844[] = { 199, 7, 151, 184, 132, 198, 187, 255 };
PROGMEM const char _dict_standard_word_845[] = "pet";
PROGMEM const uint8_t _dict_standard_code_845[] = { 199, 131, 191, 255 };
PROGMEM const char _dict_standard_word_846[] = "peter";
PROGMEM const uint8_t _dict_standard_code_846[] = { 198, 7, 128, 191, 133, 148, 255 };
PROGMEM const char _dict_standard_word_847[] = "phase";
PROGMEM const uint8_t _dict_standard_code_847[] = { 186, 154, 167, 255 };
PROGMEM const char _dict_standard_word_848[] = "phi";
PROGMEM const uint8_t _dict_standard_code_848[] = { 186, 155, 255 };
PROGMEM const char _dict_standard_word_849[] = "physical";
PROGMEM const uint8_t _dict_standard_code_849[] = { 186, 129, 167, 129, 194, 159, 255 };
PROGMEM const char _dict_standard_word_850[] = "pi";
PROGMEM const uint8_t _dict_standard_code_850[] = { 199, 155, 255 };
PROGMEM const char _dict_standard_word_851[] = "piano";
PROGMEM const uint8_t _dict_standard_code_851[] = { 198, 128, 132, 142, 137, 255 };
PROGMEM const char _dict_standard_word_852[] = "pick";
PROGMEM const uint8_t _dict_standard_code_852[] = { 198, 129, 195, 255 };
PROGMEM const char _dict_standard_word_853[] = "picked";
PROGMEM const uint8_t _dict_standard_code_853[] = { 198, 129, 195, 191, 255 };
PROGMEM const char _dict_standard_word_854[] = "pickled";
PROGMEM const uint8_t _dict_standard_code_854[] = { 198, 129, 194, 145, 145, 176, 255 };
PROGMEM const char _dict_standard_word_855[] = "picnic";
PROGMEM const uint8_t _dict_standard_code_855[] = { 198, 129, 194, 141, 129, 196, 255 };
PROGMEM const char _dict_standard_word_856[] = "pie";
PROGMEM const uint8_t _dict_standard_code_856[] = { 199, 155, 255 };
PROGMEM const char _dict_standard_word_857[] = "piece";
PROGMEM const uint8_t _dict_standard_code_857[] = { 198, 128, 187, 255 };
PROGMEM const char _dict_standard_word_858[] = "pig";
PROGMEM const uint8_t _dict_standard_code_858[] = { 199, 129, 180, 255 };
PROGMEM const char _dict_standard_word_859[] = "pillow";
PROGMEM const uint8_t _dict_standard_code_859[] = { 199, 8, 129, 146, 7, 164, 255 };
PROGMEM const char _dict_standard_word_860[] = "pilot";
PROGMEM const uint8_t _dict_standard_code_860[] = { 199, 7, 157, 146, 133, 191, 255 };
PROGMEM const char _dict_standard_word_861[] = "pin";
PROGMEM const uint8_t _dict_standard_code_861[] = { 198, 129, 141, 255 };
PROGMEM const char _dict_standard_word_862[] = "ping";
PROGMEM const uint8_t _dict_standard_code_862[] = { 198, 129, 129, 8, 143, 255 };
PROGMEM const char _dict_standard_word_863[] = "pink";
PROGMEM const uint8_t _dict_standard_code_863[] = { 198, 7, 128, 143, 196, 255 };
PROGMEM const char _dict_standard_word_864[] = "pinned";
PROGMEM const uint8_t _dict_standard_code_864[] = { 198, 8, 129, 8, 141, 177, 255 };
PROGMEM const char _dict_standard_word_865[] = "pinning";
PROGMEM const uint8_t _dict_standard_code_865[] = { 198, 8, 129, 141, 129, 143, 255 };
PROGMEM const char _dict_standard_word_866[] = "pins";
PROGMEM const uint8_t _dict_standard_code_866[] = { 198, 129, 129, 141, 7, 167, 255 };
PROGMEM const char _dict_standard_word_867[] = "piper";
PROGMEM const uint8_t _dict_standard_code_867[] = { 199, 7, 157, 7, 129, 198, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_868[] = "plant";
PROGMEM const uint8_t _dict_standard_code_868[] = { 199, 7, 146, 132, 141, 191, 255 };
PROGMEM const char _dict_standard_word_869[] = "plate";
PROGMEM const uint8_t _dict_standard_code_869[] = { 199, 7, 145, 154, 191, 255 };
PROGMEM const char _dict_standard_word_870[] = "play";
PROGMEM const uint8_t _dict_standard_code_870[] = { 199, 7, 145, 131, 154, 255 };
PROGMEM const char _dict_standard_word_871[] = "played";
PROGMEM const uint8_t _dict_standard_code_871[] = { 198, 7, 145, 131, 7, 154, 176, 255 };
PROGMEM const char _dict_standard_word_872[] = "playground";
PROGMEM const uint8_t _dict_standard_code_872[] = { 199, 7, 145, 131, 7, 154, 178, 7, 148, 7, 163, 142, 177, 255 };
PROGMEM const char _dict_standard_word_873[] = "plaything";
PROGMEM const uint8_t _dict_standard_code_873[] = { 199, 7, 145, 131, 7, 154, 190, 129, 8, 143, 255 };
PROGMEM const char _dict_standard_word_874[] = "please";
PROGMEM const uint8_t _dict_standard_code_874[] = { 199, 7, 145, 128, 167, 255 };
PROGMEM const char _dict_standard_word_875[] = "pleasure";
PROGMEM const uint8_t _dict_standard_code_875[] = { 198, 7, 145, 131, 168, 133, 148, 255 };
PROGMEM const char _dict_standard_word_876[] = "pledge";
PROGMEM const uint8_t _dict_standard_code_876[] = { 198, 7, 145, 8, 131, 165, 255 };
PROGMEM const char _dict_standard_word_877[] = "pledged";
PROGMEM const uint8_t _dict_standard_code_877[] = { 198, 7, 145, 8, 131, 165, 177, 255 };
PROGMEM const char _dict_standard_word_878[] = "pledges";
PROGMEM const uint8_t _dict_standard_code_878[] = { 198, 7, 145, 8, 131, 165, 129, 167, 255 };
PROGMEM const char _dict_standard_word_879[] = "pledging";
PROGMEM const uint8_t _dict_standard_code_879[] = { 198, 7, 145, 8, 131, 165, 129, 143, 255 };
PROGMEM const char _dict_standard_word_880[] = "plenty";
PROGMEM const uint8_t _dict_standard_code_880[] = { 199, 7, 145, 131, 141, 191, 128, 255 };
PROGMEM const char _dict_standard_word_881[] = "plus";
PROGMEM const uint8_t _dict_standard_code_881[] = { 199, 7, 146, 134, 187, 255 };
PROGMEM const char _dict_standard_word_882[] = "pocket";
PROGMEM const uint8_t _dict_standard_code_882[] = { 199, 135, 194, 131, 191, 255 };
PROGMEM const char _dict_standard_word_883[] = "police";
PROGMEM const uint8_t _dict_standard_code_883[] = { 199, 7, 134, 145, 128, 187, 255 };
PROGMEM const char _dict_standard_word_884[] = "polite";
PROGMEM const uint8_t _dict_standard_code_884[] = { 199, 7, 137, 145, 155, 191, 255 };
PROGMEM const char _dict_standard_word_885[] = "pond";
PROGMEM const uint8_t _dict_standard_code_885[] = { 199, 8, 135, 141, 177, 255 };
PROGMEM const char _dict_standard_word_886[] = "pong";
PROGMEM const uint8_t _dict_standard_code_886[] = { 199, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_887[] = "pony";
PROGMEM const uint8_t _dict_standard_code_887[] = { 199, 7, 137, 7, 164, 141, 7, 128, 255 };
PROGMEM const char _dict_standard_word_888[] = "poor";
PROGMEM const uint8_t _dict_standard_code_888[] = { 199, 7, 137, 153, 255 };
PROGMEM const char _dict_standard_word_889[] = "pop";
PROGMEM const uint8_t _dict_standard_code_889[] = { 199, 8, 135, 199, 255 };
PROGMEM const char _dict_standard_word_890[] = "popcorn";
PROGMEM const uint8_t _dict_standard_code_890[] = { 199, 135, 199, 195, 153, 141, 255 };
PROGMEM const char _dict_standard_word_891[] = "possible";
PROGMEM const uint8_t _dict_standard_code_891[] = { 199, 135, 187, 129, 173, 146, 255 };
PROGMEM const char _dict_standard_word_892[] = "post";
PROGMEM const uint8_t _dict_standard_code_892[] = { 199, 7, 137, 7, 164, 187, 191, 255 };
PROGMEM const char _dict_standard_word_893[] = "pot";
PROGMEM const uint8_t _dict_standard_code_893[] = { 199, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_894[] = "potato";
PROGMEM const uint8_t _dict_standard_code_894[] = { 199, 137, 191, 7, 154, 191, 137, 255 };
PROGMEM const char _dict_standard_word_895[] = "pottery";
PROGMEM const uint8_t _dict_standard_code_895[] = { 199, 7, 135, 191, 7, 151, 7, 148, 128, 255 };
PROGMEM const char _dict_standard_word_896[] = "pour";
PROGMEM const uint8_t _dict_standard_code_896[] = { 199, 7, 137, 153, 255 };
PROGMEM const char _dict_standard_word_897[] = "prepare";
PROGMEM const uint8_t _dict_standard_code_897[] = { 199, 7, 148, 7, 128, 198, 150, 255 };
PROGMEM const char _dict_standard_word_898[] = "pretend";
PROGMEM const uint8_t _dict_standard_code_898[] = { 199, 7, 148, 128, 191, 131, 141, 175, 255 };
PROGMEM const char _dict_standard_word_899[] = "pretty";
PROGMEM const uint8_t _dict_standard_code_899[] = { 199, 7, 148, 129, 191, 128, 255 };
PROGMEM const char _dict_standard_word_900[] = "price";
PROGMEM const uint8_t _dict_standard_code_900[] = { 199, 7, 148, 155, 187, 255 };
PROGMEM const char _dict_standard_word_901[] = "prize";
PROGMEM const uint8_t _dict_standard_code_901[] = { 199, 7, 148, 155, 7, 167, 255 };
PROGMEM const char _dict_standard_word_902[] = "promise";
PROGMEM const uint8_t _dict_standard_code_902[] = { 199, 7, 148, 135, 140, 129, 187, 255 };
PROGMEM const char _dict_standard_word_903[] = "prove";
PROGMEM const uint8_t _dict_standard_code_903[] = { 198, 7, 148, 8, 139, 8, 166, 255 };
PROGMEM const char _dict_standard_word_904[] = "psi";
PROGMEM const uint8_t _dict_standard_code_904[] = { 188, 155, 255 };
PROGMEM const char _dict_standard_word_905[] = "pudding";
PROGMEM const uint8_t _dict_standard_code_905[] = { 199, 7, 138, 174, 129, 143, 178, 255 };
PROGMEM const char _dict_standard_word_906[] = "puddle";
PROGMEM const uint8_t _dict_standard_code_906[] = { 199, 134, 175, 145, 255 };
PROGMEM const char _dict_standard_word_907[] = "pull";
PROGMEM const uint8_t _dict_standard_code_907[] = { 199, 138, 8, 146, 255 };
PROGMEM const char _dict_standard_word_908[] = "pumpkin";
PROGMEM const uint8_t _dict_standard_code_908[] = { 199, 134, 7, 140, 4, 194, 7, 18, 128, 7, 129, 142, 255 };
PROGMEM const char _dict_standard_word_909[] = "puppet";
PROGMEM const uint8_t _dict_standard_code_909[] = { 199, 134, 199, 131, 191, 255 };
PROGMEM const char _dict_standard_word_910[] = "purple";
PROGMEM const uint8_t _dict_standard_code_910[] = { 199, 7, 151, 199, 8, 146, 255 };
PROGMEM const char _dict_standard_word_911[] = "push";
PROGMEM const uint8_t _dict_standard_code_911[] = { 199, 8, 138, 8, 189, 255 };
PROGMEM const char _dict_standard_word_912[] = "put";
PROGMEM const uint8_t _dict_standard_code_912[] = { 199, 8, 134, 191, 255 };
PROGMEM const char _dict_standard_word_913[] = "puzzle";
PROGMEM const uint8_t _dict_standard_code_913[] = { 199, 8, 134, 7, 167, 145, 255 };
PROGMEM const char _dict_standard_word_914[] = "q";
PROGMEM const uint8_t _dict_standard_code_914[] = { 194, 160, 255 };
PROGMEM const char _dict_standard_word_915[] = "quack";
PROGMEM const uint8_t _dict_standard_code_915[] = { 195, 7, 147, 132, 196, 255 };
PROGMEM const char _dict_standard_word_916[] = "quantity";
PROGMEM const uint8_t _dict_standard_code_916[] = { 194, 7, 147, 135, 141, 191, 7, 129, 191, 128, 255 };
PROGMEM const char _dict_standard_word_917[] = "quart";
PROGMEM const uint8_t _dict_standard_code_917[] = { 195, 7, 137, 153, 191, 255 };
PROGMEM const char _dict_standard_word_918[] = "quarter";
PROGMEM const uint8_t _dict_standard_code_918[] = { 195, 7, 137, 7, 153, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_919[] = "question";
PROGMEM const uint8_t _dict_standard_code_919[] = { 195, 7, 147, 131, 187, 191, 7, 129, 134, 142, 255 };
PROGMEM const char _dict_standard_word_920[] = "quick";
PROGMEM const uint8_t _dict_standard_code_920[] = { 195, 7, 147, 8, 129, 4, 196, 255 };
PROGMEM const char _dict_standard_word_921[] = "quickly";
PROGMEM const uint8_t _dict_standard_code_921[] = { 195, 7, 147, 8, 129, 196, 145, 128, 255 };
PROGMEM const char _dict_standard_word_922[] = "quiet";
PROGMEM const uint8_t _dict_standard_code_922[] = { 195, 7, 147, 155, 131, 191, 255 };
PROGMEM const char _dict_standard_word_923[] = "quilt";
PROGMEM const uint8_t _dict_standard_code_923[] = { 195, 7, 147, 129, 145, 191, 255 };
PROGMEM const char _dict_standard_word_924[] = "quit";
PROGMEM const uint8_t _dict_standard_code_924[] = { 195, 7, 147, 8, 129, 191, 255 };
PROGMEM const char _dict_standard_word_925[] = "r";
PROGMEM const uint8_t _dict_standard_code_925[] = { 152, 255 };
PROGMEM const char _dict_standard_word_926[] = "rabbit";
PROGMEM const uint8_t _dict_standard_code_926[] = { 8, 148, 132, 170, 15, 129, 191, 255 };
PROGMEM const char _dict_standard_word_927[] = "race";
PROGMEM const uint8_t _dict_standard_code_927[] = { 148, 154, 187, 255 };
PROGMEM const char _dict_standard_word_928[] = "radio";
PROGMEM const uint8_t _dict_standard_code_928[] = { 148, 154, 174, 7, 128, 8, 137, 255 };
PROGMEM const char _dict_standard_word_929[] = "railroad";
PROGMEM const uint8_t _dict_standard_code_929[] = { 148, 7, 154, 7, 128, 145, 7, 148, 7, 137, 7, 164, 177, 255 };
PROGMEM const char _dict_standard_word_930[] = "rain";
PROGMEM const uint8_t _dict_standard_code_930[] = { 148, 154, 141, 255 };
PROGMEM const char _dict_standard_word_931[] = "rainbow";
PROGMEM const uint8_t _dict_standard_code_931[] = { 148, 7, 154, 141, 18, 171, 7, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_932[] = "raise";
PROGMEM const uint8_t _dict_standard_code_932[] = { 148, 7, 130, 7, 154, 167, 255 };
PROGMEM const char _dict_standard_word_933[] = "rather";
PROGMEM const uint8_t _dict_standard_code_933[] = { 148, 132, 190, 151, 255 };
PROGMEM const char _dict_standard_word_934[] = "ray";
PROGMEM const uint8_t _dict_standard_code_934[] = { 148, 148, 154, 255 };
PROGMEM const char _dict_standard_word_935[] = "rays";
PROGMEM const uint8_t _dict_standard_code_935[] = { 8, 148, 130, 7, 154, 167, 255 };
PROGMEM const char _dict_standard_word_936[] = "reach";
PROGMEM const uint8_t _dict_standard_code_936[] = { 148, 8, 128, 182, 255 };
PROGMEM const char _dict_standard_word_937[] = "read";
PROGMEM const uint8_t _dict_standard_code_937[] = { 7, 148, 8, 128, 176, 255 };
PROGMEM const char _dict_standard_word_938[] = "ready";
PROGMEM const uint8_t _dict_standard_code_938[] = { 8, 148, 130, 174, 128, 255 };
PROGMEM const char _dict_standard_word_939[] = "receive";
PROGMEM const uint8_t _dict_standard_code_939[] = { 148, 7, 128, 187, 8, 128, 166, 255 };
PROGMEM const char _dict_standard_word_940[] = "red";
PROGMEM const uint8_t _dict_standard_code_940[] = { 148, 8, 131, 176, 255 };
PROGMEM const char _dict_standard_word_941[] = "remember";
PROGMEM const uint8_t _dict_standard_code_941[] = { 148, 128, 7, 140, 131, 140, 172, 7, 151, 255 };
PROGMEM const char _dict_standard_word_942[] = "repair";
PROGMEM const uint8_t _dict_standard_code_942[] = { 148, 7, 128, 198, 8, 150, 255 };
PROGMEM const char _dict_standard_word_943[] = "repeat";
PROGMEM const uint8_t _dict_standard_code_943[] = { 148, 7, 128, 199, 128, 191, 255 };
PROGMEM const char _dict_standard_word_944[] = "reply";
PROGMEM const uint8_t _dict_standard_code_944[] = { 148, 128, 199, 146, 7, 7, 135, 155, 255 };
PROGMEM const char _dict_standard_word_945[] = "rest";
PROGMEM const uint8_t _dict_standard_code_945[] = { 148, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_946[] = "return";
PROGMEM const uint8_t _dict_standard_code_946[] = { 148, 128, 191, 151, 141, 255 };
PROGMEM const char _dict_standard_word_947[] = "rho";
PROGMEM const uint8_t _dict_standard_code_947[] = { 148, 137, 255 };
PROGMEM const char _dict_standard_word_948[] = "rib";
PROGMEM const uint8_t _dict_standard_code_948[] = { 148, 8, 129, 172, 255 };
PROGMEM const char _dict_standard_word_949[] = "ribbon";
PROGMEM const uint8_t _dict_standard_code_949[] = { 148, 129, 7, 18, 171, 134, 141, 255 };
PROGMEM const char _dict_standard_word_950[] = "ride";
PROGMEM const uint8_t _dict_standard_code_950[] = { 148, 155, 174, 255 };
PROGMEM const char _dict_standard_word_951[] = "right";
PROGMEM const uint8_t _dict_standard_code_951[] = { 148, 7, 155, 7, 128, 191, 255 };
PROGMEM const char _dict_standard_word_952[] = "ring";
PROGMEM const uint8_t _dict_standard_code_952[] = { 148, 128, 8, 143, 255 };
PROGMEM const char _dict_standard_word_953[] = "river";
PROGMEM const uint8_t _dict_standard_code_953[] = { 148, 129, 166, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_954[] = "road";
PROGMEM const uint8_t _dict_standard_code_954[] = { 148, 7, 137, 7, 164, 177, 255 };
PROGMEM const char _dict_standard_word_955[] = "rob";
PROGMEM const uint8_t _dict_standard_code_955[] = { 148, 8, 135, 173, 255 };
PROGMEM const char _dict_standard_word_956[] = "robot";
PROGMEM const uint8_t _dict_standard_code_956[] = { 148, 7, 137, 7, 164, 18, 171, 135, 191, 255 };
PROGMEM const char _dict_standard_word_957[] = "robotics";
PROGMEM const uint8_t _dict_standard_code_957[] = { 148, 7, 137, 7, 164, 18, 171, 135, 191, 7, 129, 7, 4, 194, 7, 187, 255 };
PROGMEM const char _dict_standard_word_958[] = "robots";
PROGMEM const uint8_t _dict_standard_code_958[] = { 148, 7, 137, 7, 164, 18, 171, 135, 193, 255 };
PROGMEM const char _dict_standard_word_959[] = "rock";
PROGMEM const uint8_t _dict_standard_code_959[] = { 148, 135, 197, 255 };
PROGMEM const char _dict_standard_word_960[] = "roll";
PROGMEM const uint8_t _dict_standard_code_960[] = { 148, 8, 137, 8, 146, 255 };
PROGMEM const char _dict_standard_word_961[] = "roller";
PROGMEM const uint8_t _dict_standard_code_961[] = { 7, 148, 8, 137, 146, 151, 255 };
PROGMEM const char _dict_standard_word_962[] = "roof";
PROGMEM const uint8_t _dict_standard_code_962[] = { 7, 148, 8, 139, 186, 255 };
PROGMEM const char _dict_standard_word_963[] = "room";
PROGMEM const uint8_t _dict_standard_code_963[] = { 148, 8, 139, 140, 255 };
PROGMEM const char _dict_standard_word_964[] = "rope";
PROGMEM const uint8_t _dict_standard_code_964[] = { 148, 7, 137, 7, 164, 199, 255 };
PROGMEM const char _dict_standard_word_965[] = "rose";
PROGMEM const uint8_t _dict_standard_code_965[] = { 148, 7, 137, 7, 164, 167, 255 };
PROGMEM const char _dict_standard_word_966[] = "rough";
PROGMEM const uint8_t _dict_standard_code_966[] = { 148, 134, 186, 255 };
PROGMEM const char _dict_standard_word_967[] = "round";
PROGMEM const uint8_t _dict_standard_code_967[] = { 148, 163, 142, 177, 255 };
PROGMEM const char _dict_standard_word_968[] = "row";
PROGMEM const uint8_t _dict_standard_code_968[] = { 148, 7, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_969[] = "rug";
PROGMEM const uint8_t _dict_standard_code_969[] = { 148, 134, 181, 255 };
PROGMEM const char _dict_standard_word_970[] = "ruler";
PROGMEM const uint8_t _dict_standard_code_970[] = { 148, 7, 139, 145, 151, 255 };
PROGMEM const char _dict_standard_word_971[] = "run";
PROGMEM const uint8_t _dict_standard_code_971[] = { 148, 134, 141, 255 };
PROGMEM const char _dict_standard_word_972[] = "rural";
PROGMEM const uint8_t _dict_standard_code_972[] = { 148, 7, 133, 148, 8, 159, 255 };
PROGMEM const char _dict_standard_word_973[] = "rush";
PROGMEM const uint8_t _dict_standard_code_973[] = { 148, 134, 8, 189, 255 };
PROGMEM const char _dict_standard_word_974[] = "s";
PROGMEM const uint8_t _dict_standard_code_974[] = { 131, 187, 187, 255 };
PROGMEM const char _dict_standard_word_975[] = "sad";
PROGMEM const uint8_t _dict_standard_code_975[] = { 187, 8, 132, 176, 255 };
PROGMEM const char _dict_standard_word_976[] = "saddle";
PROGMEM const uint8_t _dict_standard_code_976[] = { 8, 187, 132, 174, 159, 145, 255 };
PROGMEM const char _dict_standard_word_977[] = "sail";
PROGMEM const uint8_t _dict_standard_code_977[] = { 187, 154, 146, 255 };
PROGMEM const char _dict_standard_word_978[] = "same";
PROGMEM const uint8_t _dict_standard_code_978[] = { 187, 154, 140, 255 };
PROGMEM const char _dict_standard_word_979[] = "sand";
PROGMEM const uint8_t _dict_standard_code_979[] = { 187, 8, 132, 141, 177, 255 };
PROGMEM const char _dict_standard_word_980[] = "sandwich";
PROGMEM const uint8_t _dict_standard_code_980[] = { 187, 7, 132, 141, 176, 7, 147, 129, 182, 255 };
PROGMEM const char _dict_standard_word_981[] = "sap";
PROGMEM const uint8_t _dict_standard_code_981[] = { 8, 187, 8, 132, 199, 255 };
PROGMEM const char _dict_standard_word_982[] = "sat";
PROGMEM const uint8_t _dict_standard_code_982[] = { 8, 187, 8, 132, 191, 255 };
PROGMEM const char _dict_standard_word_983[] = "saturday";
PROGMEM const uint8_t _dict_standard_code_983[] = { 8, 187, 7, 132, 191, 7, 151, 174, 154, 255 };
PROGMEM const char _dict_standard_word_984[] = "saucer";
PROGMEM const uint8_t _dict_standard_code_984[] = { 188, 135, 187, 151, 255 };
PROGMEM const char _dict_standard_word_985[] = "savage";
PROGMEM const uint8_t _dict_standard_code_985[] = { 8, 187, 132, 166, 7, 129, 8, 165, 255 };
PROGMEM const char _dict_standard_word_986[] = "save";
PROGMEM const uint8_t _dict_standard_code_986[] = { 187, 7, 154, 7, 128, 8, 166, 255 };
PROGMEM const char _dict_standard_word_987[] = "saw";
PROGMEM const uint8_t _dict_standard_code_987[] = { 187, 187, 136, 136, 255 };
PROGMEM const char _dict_standard_word_988[] = "say";
PROGMEM const uint8_t _dict_standard_code_988[] = { 187, 7, 130, 154, 255 };
PROGMEM const char _dict_standard_word_989[] = "scarf";
PROGMEM const uint8_t _dict_standard_code_989[] = { 187, 195, 152, 186, 255 };
PROGMEM const char _dict_standard_word_990[] = "school";
PROGMEM const uint8_t _dict_standard_code_990[] = { 187, 195, 8, 139, 146, 255 };
PROGMEM const char _dict_standard_word_991[] = "scissors";
PROGMEM const uint8_t _dict_standard_code_991[] = { 187, 7, 129, 7, 167, 7, 133, 7, 151, 188, 255 };
PROGMEM const char _dict_standard_word_992[] = "score";
PROGMEM const uint8_t _dict_standard_code_992[] = { 187, 195, 137, 7, 153, 255 };
PROGMEM const char _dict_standard_word_993[] = "scott";
PROGMEM const uint8_t _dict_standard_code_993[] = { 8, 187, 195, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_994[] = "sea";
PROGMEM const uint8_t _dict_standard_code_994[] = { 187, 187, 128, 128, 255 };
PROGMEM const char _dict_standard_word_995[] = "seat";
PROGMEM const uint8_t _dict_standard_code_995[] = { 8, 187, 8, 128, 191, 255 };
PROGMEM const char _dict_standard_word_996[] = "second";
PROGMEM const uint8_t _dict_standard_code_996[] = { 8, 187, 131, 195, 133, 141, 177, 255 };
PROGMEM const char _dict_standard_word_997[] = "secret";
PROGMEM const uint8_t _dict_standard_code_997[] = { 187, 128, 195, 7, 148, 7, 131, 191, 255 };
PROGMEM const char _dict_standard_word_998[] = "see";
PROGMEM const uint8_t _dict_standard_code_998[] = { 187, 187, 128, 128, 255 };
PROGMEM const char _dict_standard_word_999[] = "seed";
PROGMEM const uint8_t _dict_standard_code_999[] = { 187, 128, 128, 176, 255 };
PROGMEM const char _dict_standard_word_1000[] = "seem";
PROGMEM const uint8_t _dict_standard_code_1000[] = { 187, 128, 128, 140, 255 };
PROGMEM const char _dict_standard_word_1001[] = "seesaw";
PROGMEM const uint8_t _dict_standard_code_1001[] = { 187, 128, 187, 8, 135, 255 };
PROGMEM const char _dict_standard_word_1002[] = "send";
PROGMEM const uint8_t _dict_standard_code_1002[] = { 187, 131, 141, 177, 255 };
PROGMEM const char _dict_standard_word_1003[] = "sensitive";
PROGMEM const uint8_t _dict_standard_code_1003[] = { 8, 187, 7, 131, 141, 187, 129, 191, 7, 129, 8, 166, 255 };
PROGMEM const char _dict_standard_word_1004[] = "sensitivity";
PROGMEM const uint8_t _dict_standard_code_1004[] = { 8, 187, 7, 131, 141, 187, 129, 191, 129, 166, 129, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1005[] = "sent";
PROGMEM const uint8_t _dict_standard_code_1005[] = { 187, 8, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_1006[] = "september";
PROGMEM const uint8_t _dict_standard_code_1006[] = { 8, 187, 7, 131, 198, 7, 191, 131, 7, 140, 172, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1007[] = "seven";
PROGMEM const uint8_t _dict_standard_code_1007[] = { 8, 187, 7, 131, 166, 131, 141, 255 };
PROGMEM const char _dict_standard_word_1008[] = "seventeen";
PROGMEM const uint8_t _dict_standard_code_1008[] = { 8, 187, 7, 131, 7, 166, 7, 131, 141, 7, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_1009[] = "seventy";
PROGMEM const uint8_t _dict_standard_code_1009[] = { 8, 187, 7, 131, 7, 166, 131, 7, 141, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1010[] = "several";
PROGMEM const uint8_t _dict_standard_code_1010[] = { 8, 187, 7, 131, 166, 7, 148, 7, 159, 7, 145, 255 };
PROGMEM const char _dict_standard_word_1011[] = "sew";
PROGMEM const uint8_t _dict_standard_code_1011[] = { 187, 8, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_1012[] = "shade";
PROGMEM const uint8_t _dict_standard_code_1012[] = { 8, 189, 154, 176, 255 };
PROGMEM const char _dict_standard_word_1013[] = "shadow";
PROGMEM const uint8_t _dict_standard_code_1013[] = { 189, 132, 175, 7, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_1014[] = "shall";
PROGMEM const uint8_t _dict_standard_code_1014[] = { 189, 8, 132, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1015[] = "shallowest";
PROGMEM const uint8_t _dict_standard_code_1015[] = { 189, 132, 146, 137, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1016[] = "share";
PROGMEM const uint8_t _dict_standard_code_1016[] = { 189, 8, 130, 7, 150, 255 };
PROGMEM const char _dict_standard_word_1017[] = "sharp";
PROGMEM const uint8_t _dict_standard_code_1017[] = { 189, 152, 199, 255 };
PROGMEM const char _dict_standard_word_1018[] = "she";
PROGMEM const uint8_t _dict_standard_code_1018[] = { 8, 189, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1019[] = "sheep";
PROGMEM const uint8_t _dict_standard_code_1019[] = { 8, 189, 8, 128, 198, 255 };
PROGMEM const char _dict_standard_word_1020[] = "sheet";
PROGMEM const uint8_t _dict_standard_code_1020[] = { 8, 189, 8, 128, 191, 255 };
PROGMEM const char _dict_standard_word_1021[] = "shell";
PROGMEM const uint8_t _dict_standard_code_1021[] = { 8, 189, 8, 130, 145, 255 };
PROGMEM const char _dict_standard_word_1022[] = "shift";
PROGMEM const uint8_t _dict_standard_code_1022[] = { 8, 189, 8, 129, 186, 191, 255 };
PROGMEM const char _dict_standard_word_1023[] = "shine";
PROGMEM const uint8_t _dict_standard_code_1023[] = { 8, 189, 7, 157, 7, 129, 141, 255 };
PROGMEM const char _dict_standard_word_1024[] = "ship";
PROGMEM const uint8_t _dict_standard_code_1024[] = { 8, 189, 8, 129, 199, 255 };
PROGMEM const char _dict_standard_word_1025[] = "shirt";
PROGMEM const uint8_t _dict_standard_code_1025[] = { 8, 189, 133, 7, 151, 191, 255 };
PROGMEM const char _dict_standard_word_1026[] = "shoe";
PROGMEM const uint8_t _dict_standard_code_1026[] = { 8, 189, 139, 139, 255 };
PROGMEM const char _dict_standard_word_1027[] = "short";
PROGMEM const uint8_t _dict_standard_code_1027[] = { 8, 189, 7, 137, 7, 153, 191, 255 };
PROGMEM const char _dict_standard_word_1028[] = "shortest";
PROGMEM const uint8_t _dict_standard_code_1028[] = { 189, 7, 137, 7, 153, 191, 7, 133, 7, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1029[] = "should";
PROGMEM const uint8_t _dict_standard_code_1029[] = { 8, 189, 8, 139, 177, 255 };
PROGMEM const char _dict_standard_word_1030[] = "shout";
PROGMEM const uint8_t _dict_standard_code_1030[] = { 8, 189, 7, 163, 7, 147, 191, 255 };
PROGMEM const char _dict_standard_word_1031[] = "shovel";
PROGMEM const uint8_t _dict_standard_code_1031[] = { 8, 189, 7, 134, 8, 166, 159, 255 };
PROGMEM const char _dict_standard_word_1032[] = "show";
PROGMEM const uint8_t _dict_standard_code_1032[] = { 8, 189, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_1033[] = "shut";
PROGMEM const uint8_t _dict_standard_code_1033[] = { 8, 189, 8, 134, 191, 255 };
PROGMEM const char _dict_standard_word_1034[] = "sick";
PROGMEM const uint8_t _dict_standard_code_1034[] = { 8, 187, 8, 129, 196, 255 };
PROGMEM const char _dict_standard_word_1035[] = "side";
PROGMEM const uint8_t _dict_standard_code_1035[] = { 8, 187, 155, 176, 255 };
PROGMEM const char _dict_standard_word_1036[] = "sidewalk";
PROGMEM const uint8_t _dict_standard_code_1036[] = { 8, 187, 155, 176, 7, 147, 135, 197, 255 };
PROGMEM const char _dict_standard_word_1037[] = "sight";
PROGMEM const uint8_t _dict_standard_code_1037[] = { 8, 187, 7, 155, 7, 128, 191, 255 };
PROGMEM const char _dict_standard_word_1038[] = "sigma";
PROGMEM const uint8_t _dict_standard_code_1038[] = { 8, 187, 129, 178, 140, 7, 134, 255 };
PROGMEM const char _dict_standard_word_1039[] = "sign";
PROGMEM const uint8_t _dict_standard_code_1039[] = { 8, 187, 155, 141, 255 };
PROGMEM const char _dict_standard_word_1040[] = "silent";
PROGMEM const uint8_t _dict_standard_code_1040[] = { 8, 187, 7, 155, 145, 7, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_1041[] = "since";
PROGMEM const uint8_t _dict_standard_code_1041[] = { 8, 187, 129, 141, 187, 255 };
PROGMEM const char _dict_standard_word_1042[] = "sincere";
PROGMEM const uint8_t _dict_standard_code_1042[] = { 8, 187, 129, 141, 187, 149, 255 };
PROGMEM const char _dict_standard_word_1043[] = "sincerely";
PROGMEM const uint8_t _dict_standard_code_1043[] = { 8, 187, 129, 141, 187, 7, 149, 145, 128, 255 };
PROGMEM const char _dict_standard_word_1044[] = "sincerity";
PROGMEM const uint8_t _dict_standard_code_1044[] = { 187, 129, 141, 187, 131, 148, 129, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1045[] = "sine";
PROGMEM const uint8_t _dict_standard_code_1045[] = { 8, 187, 155, 141, 255 };
PROGMEM const char _dict_standard_word_1046[] = "sing";
PROGMEM const uint8_t _dict_standard_code_1046[] = { 8, 187, 128, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1047[] = "sink";
PROGMEM const uint8_t _dict_standard_code_1047[] = { 8, 187, 15, 128, 7, 141, 196, 255 };
PROGMEM const char _dict_standard_word_1048[] = "sister";
PROGMEM const uint8_t _dict_standard_code_1048[] = { 8, 187, 129, 187, 191, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1049[] = "sit";
PROGMEM const uint8_t _dict_standard_code_1049[] = { 8, 187, 129, 129, 191, 255 };
PROGMEM const char _dict_standard_word_1050[] = "six";
PROGMEM const uint8_t _dict_standard_code_1050[] = { 8, 187, 129, 14, 194, 7, 187, 255 };
PROGMEM const char _dict_standard_word_1051[] = "sixteen";
PROGMEM const uint8_t _dict_standard_code_1051[] = { 8, 187, 7, 129, 14, 194, 187, 7, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_1052[] = "sixty";
PROGMEM const uint8_t _dict_standard_code_1052[] = { 8, 187, 129, 14, 194, 187, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1053[] = "size";
PROGMEM const uint8_t _dict_standard_code_1053[] = { 8, 187, 155, 167, 255 };
PROGMEM const char _dict_standard_word_1054[] = "skin";
PROGMEM const uint8_t _dict_standard_code_1054[] = { 8, 187, 194, 8, 129, 141, 255 };
PROGMEM const char _dict_standard_word_1055[] = "skirt";
PROGMEM const uint8_t _dict_standard_code_1055[] = { 187, 194, 7, 133, 7, 151, 191, 255 };
PROGMEM const char _dict_standard_word_1056[] = "sky";
PROGMEM const uint8_t _dict_standard_code_1056[] = { 187, 194, 157, 7, 129, 255 };
PROGMEM const char _dict_standard_word_1057[] = "sleep";
PROGMEM const uint8_t _dict_standard_code_1057[] = { 187, 7, 145, 8, 128, 199, 255 };
PROGMEM const char _dict_standard_word_1058[] = "sleeve";
PROGMEM const uint8_t _dict_standard_code_1058[] = { 187, 7, 145, 8, 128, 166, 255 };
PROGMEM const char _dict_standard_word_1059[] = "slice";
PROGMEM const uint8_t _dict_standard_code_1059[] = { 187, 7, 146, 155, 8, 187, 255 };
PROGMEM const char _dict_standard_word_1060[] = "slide";
PROGMEM const uint8_t _dict_standard_code_1060[] = { 187, 7, 146, 155, 176, 255 };
PROGMEM const char _dict_standard_word_1061[] = "slipper";
PROGMEM const uint8_t _dict_standard_code_1061[] = { 188, 7, 146, 129, 199, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1062[] = "slow";
PROGMEM const uint8_t _dict_standard_code_1062[] = { 187, 7, 146, 8, 164, 255 };
PROGMEM const char _dict_standard_word_1063[] = "smell";
PROGMEM const uint8_t _dict_standard_code_1063[] = { 187, 7, 140, 8, 131, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1064[] = "smile";
PROGMEM const uint8_t _dict_standard_code_1064[] = { 187, 7, 140, 7, 135, 7, 155, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1065[] = "smooth";
PROGMEM const uint8_t _dict_standard_code_1065[] = { 187, 7, 140, 139, 139, 8, 190, 255 };
PROGMEM const char _dict_standard_word_1066[] = "snail";
PROGMEM const uint8_t _dict_standard_code_1066[] = { 187, 7, 141, 7, 130, 7, 154, 146, 255 };
PROGMEM const char _dict_standard_word_1067[] = "snake";
PROGMEM const uint8_t _dict_standard_code_1067[] = { 187, 7, 141, 7, 130, 7, 154, 194, 255 };
PROGMEM const char _dict_standard_word_1068[] = "snow";
PROGMEM const uint8_t _dict_standard_code_1068[] = { 188, 7, 142, 137, 7, 164, 255 };
PROGMEM const char _dict_standard_word_1069[] = "so";
PROGMEM const uint8_t _dict_standard_code_1069[] = { 8, 188, 7, 164, 7, 147, 255 };
PROGMEM const char _dict_standard_word_1070[] = "sock";
PROGMEM const uint8_t _dict_standard_code_1070[] = { 8, 187, 8, 135, 197, 255 };
PROGMEM const char _dict_standard_word_1071[] = "soft";
PROGMEM const uint8_t _dict_standard_code_1071[] = { 8, 188, 135, 186, 191, 255 };
PROGMEM const char _dict_standard_word_1072[] = "soil";
PROGMEM const uint8_t _dict_standard_code_1072[] = { 8, 188, 7, 137, 7, 156, 145, 255 };
PROGMEM const char _dict_standard_word_1073[] = "some";
PROGMEM const uint8_t _dict_standard_code_1073[] = { 8, 187, 134, 140, 255 };
PROGMEM const char _dict_standard_word_1074[] = "son";
PROGMEM const uint8_t _dict_standard_code_1074[] = { 8, 188, 134, 141, 255 };
PROGMEM const char _dict_standard_word_1075[] = "song";
PROGMEM const uint8_t _dict_standard_code_1075[] = { 188, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_1076[] = "soon";
PROGMEM const uint8_t _dict_standard_code_1076[] = { 8, 188, 139, 139, 142, 255 };
PROGMEM const char _dict_standard_word_1077[] = "sorry";
PROGMEM const uint8_t _dict_standard_code_1077[] = { 8, 188, 136, 148, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1078[] = "sound";
PROGMEM const uint8_t _dict_standard_code_1078[] = { 187, 163, 142, 177, 255 };
PROGMEM const char _dict_standard_word_1079[] = "soup";
PROGMEM const uint8_t _dict_standard_code_1079[] = { 8, 187, 139, 139, 199, 255 };
PROGMEM const char _dict_standard_word_1080[] = "speak";
PROGMEM const uint8_t _dict_standard_code_1080[] = { 187, 198, 8, 128, 196, 255 };
PROGMEM const char _dict_standard_word_1081[] = "speakjet";
PROGMEM const uint8_t _dict_standard_code_1081[] = { 187, 198, 8, 128, 196, 165, 131, 191, 255 };
PROGMEM const char _dict_standard_word_1082[] = "special";
PROGMEM const uint8_t _dict_standard_code_1082[] = { 187, 198, 131, 189, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1083[] = "speech";
PROGMEM const uint8_t _dict_standard_code_1083[] = { 187, 198, 128, 128, 182, 255 };
PROGMEM const char _dict_standard_word_1084[] = "spell";
PROGMEM const uint8_t _dict_standard_code_1084[] = { 187, 198, 131, 159, 255 };
PROGMEM const char _dict_standard_word_1085[] = "spelled";
PROGMEM const uint8_t _dict_standard_code_1085[] = { 187, 198, 131, 159, 176, 255 };
PROGMEM const char _dict_standard_word_1086[] = "speller";
PROGMEM const uint8_t _dict_standard_code_1086[] = { 187, 198, 7, 131, 159, 133, 148, 255 };
PROGMEM const char _dict_standard_word_1087[] = "spellers";
PROGMEM const uint8_t _dict_standard_code_1087[] = { 187, 198, 7, 131, 159, 7, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1088[] = "spelling";
PROGMEM const uint8_t _dict_standard_code_1088[] = { 187, 198, 7, 131, 159, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1089[] = "spells";
PROGMEM const uint8_t _dict_standard_code_1089[] = { 187, 198, 7, 131, 159, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1090[] = "spend";
PROGMEM const uint8_t _dict_standard_code_1090[] = { 187, 198, 8, 131, 141, 177, 255 };
PROGMEM const char _dict_standard_word_1091[] = "spider";
PROGMEM const uint8_t _dict_standard_code_1091[] = { 187, 199, 7, 135, 7, 155, 174, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1092[] = "spit";
PROGMEM const uint8_t _dict_standard_code_1092[] = { 187, 198, 8, 129, 191, 255 };
PROGMEM const char _dict_standard_word_1093[] = "spoon";
PROGMEM const uint8_t _dict_standard_code_1093[] = { 188, 199, 8, 139, 142, 255 };
PROGMEM const char _dict_standard_word_1094[] = "spread";
PROGMEM const uint8_t _dict_standard_code_1094[] = { 188, 199, 7, 148, 8, 131, 176, 255 };
PROGMEM const char _dict_standard_word_1095[] = "spring";
PROGMEM const uint8_t _dict_standard_code_1095[] = { 187, 199, 7, 148, 128, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1096[] = "square";
PROGMEM const uint8_t _dict_standard_code_1096[] = { 187, 195, 147, 150, 255 };
PROGMEM const char _dict_standard_word_1097[] = "squeeze";
PROGMEM const uint8_t _dict_standard_code_1097[] = { 187, 195, 147, 128, 167, 255 };
PROGMEM const char _dict_standard_word_1098[] = "squirrel";
PROGMEM const uint8_t _dict_standard_code_1098[] = { 187, 195, 7, 147, 133, 7, 151, 145, 255 };
PROGMEM const char _dict_standard_word_1099[] = "stair";
PROGMEM const uint8_t _dict_standard_code_1099[] = { 187, 191, 130, 150, 255 };
PROGMEM const char _dict_standard_word_1100[] = "stamp";
PROGMEM const uint8_t _dict_standard_code_1100[] = { 187, 7, 191, 8, 132, 7, 140, 198, 255 };
PROGMEM const char _dict_standard_word_1101[] = "stand";
PROGMEM const uint8_t _dict_standard_code_1101[] = { 187, 191, 8, 132, 141, 177, 255 };
PROGMEM const char _dict_standard_word_1102[] = "star";
PROGMEM const uint8_t _dict_standard_code_1102[] = { 187, 191, 152, 255 };
PROGMEM const char _dict_standard_word_1103[] = "stare";
PROGMEM const uint8_t _dict_standard_code_1103[] = { 187, 191, 130, 150, 255 };
PROGMEM const char _dict_standard_word_1104[] = "start";
PROGMEM const uint8_t _dict_standard_code_1104[] = { 187, 191, 152, 191, 255 };
PROGMEM const char _dict_standard_word_1105[] = "started";
PROGMEM const uint8_t _dict_standard_code_1105[] = { 187, 191, 136, 148, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_1106[] = "starter";
PROGMEM const uint8_t _dict_standard_code_1106[] = { 187, 191, 136, 148, 191, 133, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1107[] = "starting";
PROGMEM const uint8_t _dict_standard_code_1107[] = { 187, 191, 136, 148, 191, 7, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1108[] = "starts";
PROGMEM const uint8_t _dict_standard_code_1108[] = { 187, 191, 136, 148, 193, 255 };
PROGMEM const char _dict_standard_word_1109[] = "statement";
PROGMEM const uint8_t _dict_standard_code_1109[] = { 187, 191, 154, 191, 140, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_1110[] = "stay";
PROGMEM const uint8_t _dict_standard_code_1110[] = { 187, 191, 154, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1111[] = "steal";
PROGMEM const uint8_t _dict_standard_code_1111[] = { 187, 191, 128, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1112[] = "steel";
PROGMEM const uint8_t _dict_standard_code_1112[] = { 187, 191, 128, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1113[] = "step";
PROGMEM const uint8_t _dict_standard_code_1113[] = { 187, 191, 8, 131, 199, 255 };
PROGMEM const char _dict_standard_word_1114[] = "stick";
PROGMEM const uint8_t _dict_standard_code_1114[] = { 187, 191, 8, 129, 196, 255 };
PROGMEM const char _dict_standard_word_1115[] = "still";
PROGMEM const uint8_t _dict_standard_code_1115[] = { 187, 191, 129, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1116[] = "stir";
PROGMEM const uint8_t _dict_standard_code_1116[] = { 187, 191, 151, 255 };
PROGMEM const char _dict_standard_word_1117[] = "stomach";
PROGMEM const uint8_t _dict_standard_code_1117[] = { 187, 191, 134, 140, 131, 196, 255 };
PROGMEM const char _dict_standard_word_1118[] = "stone";
PROGMEM const uint8_t _dict_standard_code_1118[] = { 187, 191, 164, 142, 255 };
PROGMEM const char _dict_standard_word_1119[] = "stop";
PROGMEM const uint8_t _dict_standard_code_1119[] = { 187, 191, 8, 135, 199, 255 };
PROGMEM const char _dict_standard_word_1120[] = "stopped";
PROGMEM const uint8_t _dict_standard_code_1120[] = { 187, 191, 8, 135, 199, 191, 255 };
PROGMEM const char _dict_standard_word_1121[] = "stopper";
PROGMEM const uint8_t _dict_standard_code_1121[] = { 187, 191, 135, 199, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1122[] = "stopping";
PROGMEM const uint8_t _dict_standard_code_1122[] = { 187, 191, 135, 199, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1123[] = "stops";
PROGMEM const uint8_t _dict_standard_code_1123[] = { 187, 191, 8, 135, 199, 187, 255 };
PROGMEM const char _dict_standard_word_1124[] = "store";
PROGMEM const uint8_t _dict_standard_code_1124[] = { 187, 191, 153, 255 };
PROGMEM const char _dict_standard_word_1125[] = "story";
PROGMEM const uint8_t _dict_standard_code_1125[] = { 187, 191, 153, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1126[] = "straight";
PROGMEM const uint8_t _dict_standard_code_1126[] = { 187, 191, 148, 7, 154, 191, 255 };
PROGMEM const char _dict_standard_word_1127[] = "stranded";
PROGMEM const uint8_t _dict_standard_code_1127[] = { 187, 191, 7, 148, 132, 141, 174, 7, 129, 176, 255 };
PROGMEM const char _dict_standard_word_1128[] = "stranger";
PROGMEM const uint8_t _dict_standard_code_1128[] = { 187, 191, 148, 7, 154, 141, 165, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1129[] = "strawberry";
PROGMEM const uint8_t _dict_standard_code_1129[] = { 187, 191, 7, 148, 135, 18, 170, 7, 150, 128, 255 };
PROGMEM const char _dict_standard_word_1130[] = "street";
PROGMEM const uint8_t _dict_standard_code_1130[] = { 187, 191, 148, 128, 191, 255 };
PROGMEM const char _dict_standard_word_1131[] = "stretch";
PROGMEM const uint8_t _dict_standard_code_1131[] = { 187, 191, 148, 131, 182, 255 };
PROGMEM const char _dict_standard_word_1132[] = "strike";
PROGMEM const uint8_t _dict_standard_code_1132[] = { 187, 191, 7, 148, 155, 196, 255 };
PROGMEM const char _dict_standard_word_1133[] = "string";
PROGMEM const uint8_t _dict_standard_code_1133[] = { 187, 191, 148, 15, 128, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1134[] = "stripe";
PROGMEM const uint8_t _dict_standard_code_1134[] = { 187, 191, 7, 148, 155, 199, 255 };
PROGMEM const char _dict_standard_word_1135[] = "strong";
PROGMEM const uint8_t _dict_standard_code_1135[] = { 187, 191, 7, 148, 135, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1136[] = "sub";
PROGMEM const uint8_t _dict_standard_code_1136[] = { 8, 187, 8, 134, 173, 255 };
PROGMEM const char _dict_standard_word_1137[] = "subject";
PROGMEM const uint8_t _dict_standard_code_1137[] = { 8, 187, 134, 172, 165, 131, 196, 191, 255 };
PROGMEM const char _dict_standard_word_1138[] = "subtract";
PROGMEM const uint8_t _dict_standard_code_1138[] = { 8, 188, 7, 134, 173, 191, 148, 132, 194, 191, 255 };
PROGMEM const char _dict_standard_word_1139[] = "succeed";
PROGMEM const uint8_t _dict_standard_code_1139[] = { 8, 187, 7, 15, 134, 194, 187, 8, 128, 176, 255 };
PROGMEM const char _dict_standard_word_1140[] = "suck";
PROGMEM const uint8_t _dict_standard_code_1140[] = { 8, 187, 8, 134, 196, 255 };
PROGMEM const char _dict_standard_word_1141[] = "sugar";
PROGMEM const uint8_t _dict_standard_code_1141[] = { 189, 138, 7, 179, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1142[] = "suit";
PROGMEM const uint8_t _dict_standard_code_1142[] = { 8, 188, 8, 139, 191, 255 };
PROGMEM const char _dict_standard_word_1143[] = "summer";
PROGMEM const uint8_t _dict_standard_code_1143[] = { 8, 188, 134, 140, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1144[] = "sun";
PROGMEM const uint8_t _dict_standard_code_1144[] = { 8, 188, 134, 8, 141, 255 };
PROGMEM const char _dict_standard_word_1145[] = "sunday";
PROGMEM const uint8_t _dict_standard_code_1145[] = { 8, 187, 134, 141, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1146[] = "supper";
PROGMEM const uint8_t _dict_standard_code_1146[] = { 8, 188, 134, 199, 7, 133, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1147[] = "suppose";
PROGMEM const uint8_t _dict_standard_code_1147[] = { 8, 188, 134, 199, 137, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1148[] = "sure";
PROGMEM const uint8_t _dict_standard_code_1148[] = { 8, 189, 139, 8, 148, 255 };
PROGMEM const char _dict_standard_word_1149[] = "surprise";
PROGMEM const uint8_t _dict_standard_code_1149[] = { 8, 188, 7, 134, 199, 148, 155, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1150[] = "swallow";
PROGMEM const uint8_t _dict_standard_code_1150[] = { 8, 188, 147, 135, 146, 164, 255 };
PROGMEM const char _dict_standard_word_1151[] = "swan";
PROGMEM const uint8_t _dict_standard_code_1151[] = { 8, 187, 147, 135, 142, 255 };
PROGMEM const char _dict_standard_word_1152[] = "sweat";
PROGMEM const uint8_t _dict_standard_code_1152[] = { 8, 188, 7, 147, 131, 191, 255 };
PROGMEM const char _dict_standard_word_1153[] = "sweated";
PROGMEM const uint8_t _dict_standard_code_1153[] = { 8, 188, 7, 147, 131, 191, 129, 176, 255 };
PROGMEM const char _dict_standard_word_1154[] = "sweater";
PROGMEM const uint8_t _dict_standard_code_1154[] = { 8, 188, 7, 147, 131, 191, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1155[] = "sweaters";
PROGMEM const uint8_t _dict_standard_code_1155[] = { 8, 188, 7, 147, 131, 191, 133, 148, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1156[] = "sweating";
PROGMEM const uint8_t _dict_standard_code_1156[] = { 8, 188, 7, 147, 131, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1157[] = "sweats";
PROGMEM const uint8_t _dict_standard_code_1157[] = { 8, 188, 7, 147, 8, 131, 193, 255 };
PROGMEM const char _dict_standard_word_1158[] = "swim";
PROGMEM const uint8_t _dict_standard_code_1158[] = { 8, 187, 7, 147, 129, 140, 255 };
PROGMEM const char _dict_standard_word_1159[] = "swing";
PROGMEM const uint8_t _dict_standard_code_1159[] = { 8, 187, 7, 147, 128, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1160[] = "switch";
PROGMEM const uint8_t _dict_standard_code_1160[] = { 8, 188, 7, 147, 129, 182, 255 };
PROGMEM const char _dict_standard_word_1161[] = "switched";
PROGMEM const uint8_t _dict_standard_code_1161[] = { 8, 188, 7, 147, 129, 182, 191, 255 };
PROGMEM const char _dict_standard_word_1162[] = "switches";
PROGMEM const uint8_t _dict_standard_code_1162[] = { 8, 188, 7, 147, 129, 182, 129, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1163[] = "switching";
PROGMEM const uint8_t _dict_standard_code_1163[] = { 8, 188, 7, 147, 129, 182, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1164[] = "system";
PROGMEM const uint8_t _dict_standard_code_1164[] = { 8, 187, 129, 187, 191, 7, 131, 140, 255 };
PROGMEM const char _dict_standard_word_1165[] = "systems";
PROGMEM const uint8_t _dict_standard_code_1165[] = { 8, 187, 129, 187, 191, 7, 131, 140, 187, 255 };
PROGMEM const char _dict_standard_word_1166[] = "t";
PROGMEM const uint8_t _dict_standard_code_1166[] = { 192, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1167[] = "table";
PROGMEM const uint8_t _dict_standard_code_1167[] = { 191, 7, 130, 7, 154, 18, 170, 7, 134, 146, 255 };
PROGMEM const char _dict_standard_word_1168[] = "tail";
PROGMEM const uint8_t _dict_standard_code_1168[] = { 192, 154, 146, 255 };
PROGMEM const char _dict_standard_word_1169[] = "take";
PROGMEM const uint8_t _dict_standard_code_1169[] = { 192, 154, 196, 255 };
PROGMEM const char _dict_standard_word_1170[] = "tale";
PROGMEM const uint8_t _dict_standard_code_1170[] = { 192, 154, 146, 255 };
PROGMEM const char _dict_standard_word_1171[] = "talk";
PROGMEM const uint8_t _dict_standard_code_1171[] = { 191, 8, 135, 8, 197, 255 };
PROGMEM const char _dict_standard_word_1172[] = "talked";
PROGMEM const uint8_t _dict_standard_code_1172[] = { 191, 8, 135, 8, 197, 191, 255 };
PROGMEM const char _dict_standard_word_1173[] = "talker";
PROGMEM const uint8_t _dict_standard_code_1173[] = { 191, 135, 194, 151, 255 };
PROGMEM const char _dict_standard_word_1174[] = "talkers";
PROGMEM const uint8_t _dict_standard_code_1174[] = { 191, 135, 194, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1175[] = "talking";
PROGMEM const uint8_t _dict_standard_code_1175[] = { 191, 135, 194, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1176[] = "talks";
PROGMEM const uint8_t _dict_standard_code_1176[] = { 191, 8, 135, 195, 188, 255 };
PROGMEM const char _dict_standard_word_1177[] = "tall";
PROGMEM const uint8_t _dict_standard_code_1177[] = { 191, 135, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1178[] = "task";
PROGMEM const uint8_t _dict_standard_code_1178[] = { 191, 8, 132, 187, 8, 196, 255 };
PROGMEM const char _dict_standard_word_1179[] = "taste";
PROGMEM const uint8_t _dict_standard_code_1179[] = { 192, 154, 187, 8, 191, 255 };
PROGMEM const char _dict_standard_word_1180[] = "tau";
PROGMEM const uint8_t _dict_standard_code_1180[] = { 191, 163, 255 };
PROGMEM const char _dict_standard_word_1181[] = "te";
PROGMEM const uint8_t _dict_standard_code_1181[] = { 192, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1182[] = "tea";
PROGMEM const uint8_t _dict_standard_code_1182[] = { 192, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1183[] = "teach";
PROGMEM const uint8_t _dict_standard_code_1183[] = { 191, 8, 128, 182, 255 };
PROGMEM const char _dict_standard_word_1184[] = "teacher";
PROGMEM const uint8_t _dict_standard_code_1184[] = { 191, 8, 128, 182, 7, 151, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1185[] = "team";
PROGMEM const uint8_t _dict_standard_code_1185[] = { 191, 8, 128, 140, 255 };
PROGMEM const char _dict_standard_word_1186[] = "tee";
PROGMEM const uint8_t _dict_standard_code_1186[] = { 192, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1187[] = "telephone";
PROGMEM const uint8_t _dict_standard_code_1187[] = { 191, 7, 131, 145, 7, 131, 186, 8, 137, 142, 255 };
PROGMEM const char _dict_standard_word_1188[] = "television";
PROGMEM const uint8_t _dict_standard_code_1188[] = { 191, 7, 131, 145, 7, 131, 166, 129, 168, 134, 142, 255 };
PROGMEM const char _dict_standard_word_1189[] = "tell";
PROGMEM const uint8_t _dict_standard_code_1189[] = { 191, 8, 131, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1190[] = "ten";
PROGMEM const uint8_t _dict_standard_code_1190[] = { 191, 131, 131, 141, 255 };
PROGMEM const char _dict_standard_word_1191[] = "tennessee";
PROGMEM const uint8_t _dict_standard_code_1191[] = { 191, 131, 141, 7, 131, 187, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1192[] = "tent";
PROGMEM const uint8_t _dict_standard_code_1192[] = { 191, 131, 8, 142, 191, 255 };
PROGMEM const char _dict_standard_word_1193[] = "test";
PROGMEM const uint8_t _dict_standard_code_1193[] = { 191, 131, 8, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1194[] = "testing";
PROGMEM const uint8_t _dict_standard_code_1194[] = { 191, 131, 8, 187, 191, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1195[] = "tests";
PROGMEM const uint8_t _dict_standard_code_1195[] = { 191, 131, 8, 187, 193, 255 };
PROGMEM const char _dict_standard_word_1196[] = "than";
PROGMEM const uint8_t _dict_standard_code_1196[] = { 169, 8, 132, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1197[] = "that";
PROGMEM const uint8_t _dict_standard_code_1197[] = { 169, 8, 132, 8, 191, 255 };
PROGMEM const char _dict_standard_word_1198[] = "the";
PROGMEM const uint8_t _dict_standard_code_1198[] = { 8, 169, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1199[] = "theater";
PROGMEM const uint8_t _dict_standard_code_1199[] = { 8, 190, 128, 154, 191, 133, 148, 255 };
PROGMEM const char _dict_standard_word_1200[] = "theaters";
PROGMEM const uint8_t _dict_standard_code_1200[] = { 8, 190, 128, 154, 191, 133, 148, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1201[] = "their";
PROGMEM const uint8_t _dict_standard_code_1201[] = { 8, 169, 150, 255 };
PROGMEM const char _dict_standard_word_1202[] = "them";
PROGMEM const uint8_t _dict_standard_code_1202[] = { 8, 169, 131, 8, 140, 255 };
PROGMEM const char _dict_standard_word_1203[] = "then";
PROGMEM const uint8_t _dict_standard_code_1203[] = { 8, 169, 131, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1204[] = "there";
PROGMEM const uint8_t _dict_standard_code_1204[] = { 8, 169, 150, 255 };
PROGMEM const char _dict_standard_word_1205[] = "these";
PROGMEM const uint8_t _dict_standard_code_1205[] = { 8, 169, 8, 128, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1206[] = "theta";
PROGMEM const uint8_t _dict_standard_code_1206[] = { 190, 154, 191, 134, 255 };
PROGMEM const char _dict_standard_word_1207[] = "they";
PROGMEM const uint8_t _dict_standard_code_1207[] = { 8, 169, 154, 255 };
PROGMEM const char _dict_standard_word_1208[] = "thick";
PROGMEM const uint8_t _dict_standard_code_1208[] = { 8, 190, 8, 129, 196, 255 };
PROGMEM const char _dict_standard_word_1209[] = "thin";
PROGMEM const uint8_t _dict_standard_code_1209[] = { 8, 190, 8, 129, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1210[] = "thing";
PROGMEM const uint8_t _dict_standard_code_1210[] = { 8, 190, 8, 129, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1211[] = "think";
PROGMEM const uint8_t _dict_standard_code_1211[] = { 8, 190, 8, 129, 143, 196, 255 };
PROGMEM const char _dict_standard_word_1212[] = "thinks";
PROGMEM const uint8_t _dict_standard_code_1212[] = { 8, 190, 8, 129, 143, 196, 7, 187, 255 };
PROGMEM const char _dict_standard_word_1213[] = "thirsty";
PROGMEM const uint8_t _dict_standard_code_1213[] = { 8, 190, 7, 151, 187, 191, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1214[] = "thirteen";
PROGMEM const uint8_t _dict_standard_code_1214[] = { 8, 190, 7, 151, 191, 128, 141, 255 };
PROGMEM const char _dict_standard_word_1215[] = "thirty";
PROGMEM const uint8_t _dict_standard_code_1215[] = { 8, 190, 7, 151, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1216[] = "this";
PROGMEM const uint8_t _dict_standard_code_1216[] = { 8, 169, 8, 129, 187, 255 };
PROGMEM const char _dict_standard_word_1217[] = "those";
PROGMEM const uint8_t _dict_standard_code_1217[] = { 8, 169, 8, 137, 167, 255 };
PROGMEM const char _dict_standard_word_1218[] = "though";
PROGMEM const uint8_t _dict_standard_code_1218[] = { 8, 169, 164, 255 };
PROGMEM const char _dict_standard_word_1219[] = "thousand";
PROGMEM const uint8_t _dict_standard_code_1219[] = { 8, 190, 7, 163, 167, 7, 133, 8, 141, 255 };
PROGMEM const char _dict_standard_word_1220[] = "thread";
PROGMEM const uint8_t _dict_standard_code_1220[] = { 8, 190, 148, 8, 131, 176, 255 };
PROGMEM const char _dict_standard_word_1221[] = "threaded";
PROGMEM const uint8_t _dict_standard_code_1221[] = { 8, 190, 148, 131, 174, 129, 176, 255 };
PROGMEM const char _dict_standard_word_1222[] = "threader";
PROGMEM const uint8_t _dict_standard_code_1222[] = { 8, 190, 148, 131, 174, 133, 148, 255 };
PROGMEM const char _dict_standard_word_1223[] = "threading";
PROGMEM const uint8_t _dict_standard_code_1223[] = { 8, 190, 148, 131, 174, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1224[] = "threads";
PROGMEM const uint8_t _dict_standard_code_1224[] = { 8, 190, 148, 131, 174, 167, 255 };
PROGMEM const char _dict_standard_word_1225[] = "three";
PROGMEM const uint8_t _dict_standard_code_1225[] = { 8, 190, 148, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1226[] = "threw";
PROGMEM const uint8_t _dict_standard_code_1226[] = { 8, 190, 148, 8, 139, 255 };
PROGMEM const char _dict_standard_word_1227[] = "through";
PROGMEM const uint8_t _dict_standard_code_1227[] = { 8, 190, 148, 8, 139, 255 };
PROGMEM const char _dict_standard_word_1228[] = "throw";
PROGMEM const uint8_t _dict_standard_code_1228[] = { 8, 190, 148, 164, 255 };
PROGMEM const char _dict_standard_word_1229[] = "thu";
PROGMEM const uint8_t _dict_standard_code_1229[] = { 8, 169, 8, 134, 255 };
PROGMEM const char _dict_standard_word_1230[] = "thumb";
PROGMEM const uint8_t _dict_standard_code_1230[] = { 8, 190, 8, 134, 140, 255 };
PROGMEM const char _dict_standard_word_1231[] = "thursday";
PROGMEM const uint8_t _dict_standard_code_1231[] = { 8, 190, 151, 167, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1232[] = "tickle";
PROGMEM const uint8_t _dict_standard_code_1232[] = { 8, 191, 129, 194, 159, 255 };
PROGMEM const char _dict_standard_word_1233[] = "tie";
PROGMEM const uint8_t _dict_standard_code_1233[] = { 8, 191, 155, 255 };
PROGMEM const char _dict_standard_word_1234[] = "tiger";
PROGMEM const uint8_t _dict_standard_code_1234[] = { 8, 191, 155, 178, 133, 148, 255 };
PROGMEM const char _dict_standard_word_1235[] = "tight";
PROGMEM const uint8_t _dict_standard_code_1235[] = { 8, 191, 155, 191, 255 };
PROGMEM const char _dict_standard_word_1236[] = "till";
PROGMEM const uint8_t _dict_standard_code_1236[] = { 8, 191, 8, 129, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1237[] = "time";
PROGMEM const uint8_t _dict_standard_code_1237[] = { 8, 191, 157, 8, 140, 255 };
PROGMEM const char _dict_standard_word_1238[] = "times";
PROGMEM const uint8_t _dict_standard_code_1238[] = { 8, 191, 157, 8, 140, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1239[] = "tiny";
PROGMEM const uint8_t _dict_standard_code_1239[] = { 8, 191, 155, 8, 141, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1240[] = "tip";
PROGMEM const uint8_t _dict_standard_code_1240[] = { 8, 191, 8, 129, 199, 255 };
PROGMEM const char _dict_standard_word_1241[] = "tiptoe";
PROGMEM const uint8_t _dict_standard_code_1241[] = { 8, 191, 8, 129, 199, 8, 191, 137, 255 };
PROGMEM const char _dict_standard_word_1242[] = "tire";
PROGMEM const uint8_t _dict_standard_code_1242[] = { 8, 191, 155, 148, 255 };
PROGMEM const char _dict_standard_word_1243[] = "tired";
PROGMEM const uint8_t _dict_standard_code_1243[] = { 8, 191, 155, 148, 177, 255 };
PROGMEM const char _dict_standard_word_1244[] = "titans";
PROGMEM const uint8_t _dict_standard_code_1244[] = { 8, 191, 155, 191, 7, 132, 141, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1245[] = "to";
PROGMEM const uint8_t _dict_standard_code_1245[] = { 8, 191, 162, 255 };
PROGMEM const char _dict_standard_word_1246[] = "toast";
PROGMEM const uint8_t _dict_standard_code_1246[] = { 191, 8, 137, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1247[] = "today";
PROGMEM const uint8_t _dict_standard_code_1247[] = { 8, 191, 139, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1248[] = "toe";
PROGMEM const uint8_t _dict_standard_code_1248[] = { 8, 191, 164, 255 };
PROGMEM const char _dict_standard_word_1249[] = "together";
PROGMEM const uint8_t _dict_standard_code_1249[] = { 8, 191, 139, 178, 131, 169, 151, 255 };
PROGMEM const char _dict_standard_word_1250[] = "tomato";
PROGMEM const uint8_t _dict_standard_code_1250[] = { 8, 191, 137, 140, 154, 191, 164, 255 };
PROGMEM const char _dict_standard_word_1251[] = "tomorrow";
PROGMEM const uint8_t _dict_standard_code_1251[] = { 8, 191, 139, 140, 152, 164, 255 };
PROGMEM const char _dict_standard_word_1252[] = "tong";
PROGMEM const uint8_t _dict_standard_code_1252[] = { 8, 191, 135, 144, 181, 255 };
PROGMEM const char _dict_standard_word_1253[] = "tongue";
PROGMEM const uint8_t _dict_standard_code_1253[] = { 8, 191, 134, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1254[] = "tonight";
PROGMEM const uint8_t _dict_standard_code_1254[] = { 8, 191, 139, 142, 155, 191, 255 };
PROGMEM const char _dict_standard_word_1255[] = "too";
PROGMEM const uint8_t _dict_standard_code_1255[] = { 8, 191, 162, 255 };
PROGMEM const char _dict_standard_word_1256[] = "took";
PROGMEM const uint8_t _dict_standard_code_1256[] = { 8, 191, 138, 138, 197, 255 };
PROGMEM const char _dict_standard_word_1257[] = "tool";
PROGMEM const uint8_t _dict_standard_code_1257[] = { 8, 191, 8, 139, 145, 255 };
PROGMEM const char _dict_standard_word_1258[] = "tooth";
PROGMEM const uint8_t _dict_standard_code_1258[] = { 8, 191, 8, 139, 8, 190, 255 };
PROGMEM const char _dict_standard_word_1259[] = "toothbrush";
PROGMEM const uint8_t _dict_standard_code_1259[] = { 8, 191, 8, 139, 190, 18, 171, 7, 148, 134, 189, 255 };
PROGMEM const char _dict_standard_word_1260[] = "top";
PROGMEM const uint8_t _dict_standard_code_1260[] = { 8, 191, 135, 199, 255 };
PROGMEM const char _dict_standard_word_1261[] = "touch";
PROGMEM const uint8_t _dict_standard_code_1261[] = { 8, 191, 8, 134, 182, 255 };
PROGMEM const char _dict_standard_word_1262[] = "toward";
PROGMEM const uint8_t _dict_standard_code_1262[] = { 8, 191, 7, 164, 153, 177, 255 };
PROGMEM const char _dict_standard_word_1263[] = "towel";
PROGMEM const uint8_t _dict_standard_code_1263[] = { 8, 191, 163, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1264[] = "town";
PROGMEM const uint8_t _dict_standard_code_1264[] = { 8, 191, 163, 142, 255 };
PROGMEM const char _dict_standard_word_1265[] = "toy";
PROGMEM const uint8_t _dict_standard_code_1265[] = { 8, 191, 156, 255 };
PROGMEM const char _dict_standard_word_1266[] = "tractor";
PROGMEM const uint8_t _dict_standard_code_1266[] = { 8, 191, 148, 132, 194, 191, 151, 255 };
PROGMEM const char _dict_standard_word_1267[] = "traffic";
PROGMEM const uint8_t _dict_standard_code_1267[] = { 8, 191, 148, 132, 186, 129, 196, 255 };
PROGMEM const char _dict_standard_word_1268[] = "train";
PROGMEM const uint8_t _dict_standard_code_1268[] = { 8, 191, 7, 148, 154, 142, 255 };
PROGMEM const char _dict_standard_word_1269[] = "travel";
PROGMEM const uint8_t _dict_standard_code_1269[] = { 8, 191, 7, 148, 132, 166, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1270[] = "tray";
PROGMEM const uint8_t _dict_standard_code_1270[] = { 8, 191, 7, 148, 154, 255 };
PROGMEM const char _dict_standard_word_1271[] = "treasures";
PROGMEM const uint8_t _dict_standard_code_1271[] = { 8, 191, 7, 148, 131, 168, 133, 148, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1272[] = "treat";
PROGMEM const uint8_t _dict_standard_code_1272[] = { 8, 191, 7, 148, 8, 128, 191, 255 };
PROGMEM const char _dict_standard_word_1273[] = "tree";
PROGMEM const uint8_t _dict_standard_code_1273[] = { 8, 191, 7, 148, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1274[] = "triangle";
PROGMEM const uint8_t _dict_standard_code_1274[] = { 8, 191, 7, 148, 155, 154, 143, 145, 255 };
PROGMEM const char _dict_standard_word_1275[] = "trip";
PROGMEM const uint8_t _dict_standard_code_1275[] = { 8, 191, 7, 148, 8, 129, 198, 255 };
PROGMEM const char _dict_standard_word_1276[] = "triple";
PROGMEM const uint8_t _dict_standard_code_1276[] = { 8, 191, 7, 148, 129, 199, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1277[] = "trousers";
PROGMEM const uint8_t _dict_standard_code_1277[] = { 8, 191, 7, 148, 163, 167, 7, 151, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1278[] = "truck";
PROGMEM const uint8_t _dict_standard_code_1278[] = { 8, 191, 7, 148, 134, 197, 255 };
PROGMEM const char _dict_standard_word_1279[] = "trusts";
PROGMEM const uint8_t _dict_standard_code_1279[] = { 8, 191, 7, 148, 134, 187, 193, 255 };
PROGMEM const char _dict_standard_word_1280[] = "truth";
PROGMEM const uint8_t _dict_standard_code_1280[] = { 8, 191, 7, 148, 8, 139, 8, 190, 255 };
PROGMEM const char _dict_standard_word_1281[] = "try";
PROGMEM const uint8_t _dict_standard_code_1281[] = { 8, 191, 7, 148, 155, 255 };
PROGMEM const char _dict_standard_word_1282[] = "tub";
PROGMEM const uint8_t _dict_standard_code_1282[] = { 8, 191, 134, 134, 173, 255 };
PROGMEM const char _dict_standard_word_1283[] = "tube";
PROGMEM const uint8_t _dict_standard_code_1283[] = { 8, 191, 8, 139, 173, 255 };
PROGMEM const char _dict_standard_word_1284[] = "tuesday";
PROGMEM const uint8_t _dict_standard_code_1284[] = { 8, 191, 139, 167, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1285[] = "tulip";
PROGMEM const uint8_t _dict_standard_code_1285[] = { 8, 191, 139, 146, 129, 198, 255 };
PROGMEM const char _dict_standard_word_1286[] = "tunnel";
PROGMEM const uint8_t _dict_standard_code_1286[] = { 8, 191, 134, 142, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1287[] = "turkey";
PROGMEM const uint8_t _dict_standard_code_1287[] = { 8, 191, 151, 194, 128, 255 };
PROGMEM const char _dict_standard_word_1288[] = "turn";
PROGMEM const uint8_t _dict_standard_code_1288[] = { 8, 191, 151, 141, 255 };
PROGMEM const char _dict_standard_word_1289[] = "turned";
PROGMEM const uint8_t _dict_standard_code_1289[] = { 8, 191, 151, 141, 177, 255 };
PROGMEM const char _dict_standard_word_1290[] = "turning";
PROGMEM const uint8_t _dict_standard_code_1290[] = { 8, 191, 133, 7, 148, 141, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1291[] = "turns";
PROGMEM const uint8_t _dict_standard_code_1291[] = { 8, 191, 133, 148, 141, 187, 255 };
PROGMEM const char _dict_standard_word_1292[] = "turtle";
PROGMEM const uint8_t _dict_standard_code_1292[] = { 8, 191, 151, 191, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1293[] = "twelve";
PROGMEM const uint8_t _dict_standard_code_1293[] = { 8, 191, 7, 147, 131, 145, 166, 255 };
PROGMEM const char _dict_standard_word_1294[] = "twenty";
PROGMEM const uint8_t _dict_standard_code_1294[] = { 8, 7, 191, 7, 147, 131, 141, 7, 191, 128, 255 };
PROGMEM const char _dict_standard_word_1295[] = "twice";
PROGMEM const uint8_t _dict_standard_code_1295[] = { 8, 191, 7, 147, 155, 187, 255 };
PROGMEM const char _dict_standard_word_1296[] = "twin";
PROGMEM const uint8_t _dict_standard_code_1296[] = { 8, 191, 7, 147, 129, 142, 255 };
PROGMEM const char _dict_standard_word_1297[] = "two";
PROGMEM const uint8_t _dict_standard_code_1297[] = { 8, 191, 162, 255 };
PROGMEM const char _dict_standard_word_1298[] = "typewriter";
PROGMEM const uint8_t _dict_standard_code_1298[] = { 8, 191, 7, 155, 199, 7, 147, 7, 148, 7, 155, 7, 191, 151, 255 };
PROGMEM const char _dict_standard_word_1299[] = "u";
PROGMEM const uint8_t _dict_standard_code_1299[] = { 8, 160, 255 };
PROGMEM const char _dict_standard_word_1300[] = "umbrella";
PROGMEM const uint8_t _dict_standard_code_1300[] = { 134, 7, 140, 173, 148, 131, 146, 134, 255 };
PROGMEM const char _dict_standard_word_1301[] = "uncle";
PROGMEM const uint8_t _dict_standard_code_1301[] = { 8, 134, 7, 144, 195, 138, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1302[] = "under";
PROGMEM const uint8_t _dict_standard_code_1302[] = { 134, 141, 175, 151, 255 };
PROGMEM const char _dict_standard_word_1303[] = "understand";
PROGMEM const uint8_t _dict_standard_code_1303[] = { 134, 7, 141, 175, 7, 151, 187, 7, 191, 132, 142, 177, 255 };
PROGMEM const char _dict_standard_word_1304[] = "unicorn";
PROGMEM const uint8_t _dict_standard_code_1304[] = { 160, 141, 129, 195, 153, 141, 255 };
PROGMEM const char _dict_standard_word_1305[] = "unless";
PROGMEM const uint8_t _dict_standard_code_1305[] = { 134, 142, 145, 131, 187, 255 };
PROGMEM const char _dict_standard_word_1306[] = "until";
PROGMEM const uint8_t _dict_standard_code_1306[] = { 134, 141, 191, 129, 146, 255 };
PROGMEM const char _dict_standard_word_1307[] = "unusual";
PROGMEM const uint8_t _dict_standard_code_1307[] = { 134, 141, 128, 7, 139, 168, 139, 159, 255 };
PROGMEM const char _dict_standard_word_1308[] = "up";
PROGMEM const uint8_t _dict_standard_code_1308[] = { 8, 134, 199, 255 };
PROGMEM const char _dict_standard_word_1309[] = "upon";
PROGMEM const uint8_t _dict_standard_code_1309[] = { 134, 199, 135, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1310[] = "upsilon";
PROGMEM const uint8_t _dict_standard_code_1310[] = { 139, 198, 187, 129, 146, 135, 142, 255 };
PROGMEM const char _dict_standard_word_1311[] = "us";
PROGMEM const uint8_t _dict_standard_code_1311[] = { 8, 134, 187, 255 };
PROGMEM const char _dict_standard_word_1312[] = "use";
PROGMEM const uint8_t _dict_standard_code_1312[] = { 160, 167, 255 };
PROGMEM const char _dict_standard_word_1313[] = "usually";
PROGMEM const uint8_t _dict_standard_code_1313[] = { 160, 168, 139, 159, 128, 255 };
PROGMEM const char _dict_standard_word_1314[] = "v";
PROGMEM const uint8_t _dict_standard_code_1314[] = { 8, 166, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1315[] = "vacation";
PROGMEM const uint8_t _dict_standard_code_1315[] = { 166, 7, 154, 194, 154, 189, 134, 142, 255 };
PROGMEM const char _dict_standard_word_1316[] = "valentine";
PROGMEM const uint8_t _dict_standard_code_1316[] = { 166, 7, 132, 145, 131, 142, 191, 155, 142, 255 };
PROGMEM const char _dict_standard_word_1317[] = "vase";
PROGMEM const uint8_t _dict_standard_code_1317[] = { 166, 154, 187, 255 };
PROGMEM const char _dict_standard_word_1318[] = "vegetable";
PROGMEM const uint8_t _dict_standard_code_1318[] = { 166, 131, 165, 191, 134, 7, 18, 171, 134, 146, 255 };
PROGMEM const char _dict_standard_word_1319[] = "version";
PROGMEM const uint8_t _dict_standard_code_1319[] = { 166, 8, 148, 168, 133, 141, 255 };
PROGMEM const char _dict_standard_word_1320[] = "very";
PROGMEM const uint8_t _dict_standard_code_1320[] = { 166, 150, 7, 128, 255 };
PROGMEM const char _dict_standard_word_1321[] = "vest";
PROGMEM const uint8_t _dict_standard_code_1321[] = { 166, 8, 131, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1322[] = "village";
PROGMEM const uint8_t _dict_standard_code_1322[] = { 166, 129, 8, 145, 131, 165, 255 };
PROGMEM const char _dict_standard_word_1323[] = "vine";
PROGMEM const uint8_t _dict_standard_code_1323[] = { 166, 155, 142, 255 };
PROGMEM const char _dict_standard_word_1324[] = "violet";
PROGMEM const uint8_t _dict_standard_code_1324[] = { 166, 155, 7, 137, 145, 7, 131, 191, 255 };
PROGMEM const char _dict_standard_word_1325[] = "violin";
PROGMEM const uint8_t _dict_standard_code_1325[] = { 166, 155, 7, 137, 145, 129, 141, 255 };
PROGMEM const char _dict_standard_word_1326[] = "visit";
PROGMEM const uint8_t _dict_standard_code_1326[] = { 166, 129, 167, 129, 191, 255 };
PROGMEM const char _dict_standard_word_1327[] = "voice";
PROGMEM const uint8_t _dict_standard_code_1327[] = { 166, 156, 187, 187, 255 };
PROGMEM const char _dict_standard_word_1328[] = "voices";
PROGMEM const uint8_t _dict_standard_code_1328[] = { 166, 156, 187, 129, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1329[] = "voyage";
PROGMEM const uint8_t _dict_standard_code_1329[] = { 166, 156, 131, 165, 255 };
PROGMEM const char _dict_standard_word_1330[] = "w";
PROGMEM const uint8_t _dict_standard_code_1330[] = { 175, 7, 134, 18, 171, 159, 160, 139, 255 };
PROGMEM const char _dict_standard_word_1331[] = "wagon";
PROGMEM const uint8_t _dict_standard_code_1331[] = { 147, 132, 179, 134, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1332[] = "wait";
PROGMEM const uint8_t _dict_standard_code_1332[] = { 147, 154, 191, 255 };
PROGMEM const char _dict_standard_word_1333[] = "walk";
PROGMEM const uint8_t _dict_standard_code_1333[] = { 147, 8, 135, 8, 197, 255 };
PROGMEM const char _dict_standard_word_1334[] = "want";
PROGMEM const uint8_t _dict_standard_code_1334[] = { 147, 8, 135, 142, 191, 255 };
PROGMEM const char _dict_standard_word_1335[] = "war";
PROGMEM const uint8_t _dict_standard_code_1335[] = { 147, 7, 137, 153, 255 };
PROGMEM const char _dict_standard_word_1336[] = "warm";
PROGMEM const uint8_t _dict_standard_code_1336[] = { 147, 153, 8, 140, 255 };
PROGMEM const char _dict_standard_word_1337[] = "warning";
PROGMEM const uint8_t _dict_standard_code_1337[] = { 147, 7, 137, 7, 148, 141, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1338[] = "warrant";
PROGMEM const uint8_t _dict_standard_code_1338[] = { 147, 153, 133, 141, 191, 255 };
PROGMEM const char _dict_standard_word_1339[] = "was";
PROGMEM const uint8_t _dict_standard_code_1339[] = { 147, 134, 167, 255 };
PROGMEM const char _dict_standard_word_1340[] = "wash";
PROGMEM const uint8_t _dict_standard_code_1340[] = { 147, 8, 135, 189, 255 };
PROGMEM const char _dict_standard_word_1341[] = "watch";
PROGMEM const uint8_t _dict_standard_code_1341[] = { 147, 135, 8, 182, 255 };
PROGMEM const char _dict_standard_word_1342[] = "water";
PROGMEM const uint8_t _dict_standard_code_1342[] = { 147, 135, 191, 7, 151, 255 };
PROGMEM const char _dict_standard_word_1343[] = "watermelon";
PROGMEM const uint8_t _dict_standard_code_1343[] = { 147, 135, 191, 7, 151, 140, 131, 146, 134, 142, 255 };
PROGMEM const char _dict_standard_word_1344[] = "wave";
PROGMEM const uint8_t _dict_standard_code_1344[] = { 147, 154, 166, 255 };
PROGMEM const char _dict_standard_word_1345[] = "we";
PROGMEM const uint8_t _dict_standard_code_1345[] = { 147, 8, 128, 255 };
PROGMEM const char _dict_standard_word_1346[] = "weak";
PROGMEM const uint8_t _dict_standard_code_1346[] = { 147, 8, 128, 196, 255 };
PROGMEM const char _dict_standard_word_1347[] = "wear";
PROGMEM const uint8_t _dict_standard_code_1347[] = { 147, 150, 255 };
PROGMEM const char _dict_standard_word_1348[] = "weather";
PROGMEM const uint8_t _dict_standard_code_1348[] = { 147, 131, 169, 151, 255 };
PROGMEM const char _dict_standard_word_1349[] = "wednesday";
PROGMEM const uint8_t _dict_standard_code_1349[] = { 147, 131, 141, 167, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1350[] = "week";
PROGMEM const uint8_t _dict_standard_code_1350[] = { 147, 128, 196, 255 };
PROGMEM const char _dict_standard_word_1351[] = "weight";
PROGMEM const uint8_t _dict_standard_code_1351[] = { 147, 154, 191, 255 };
PROGMEM const char _dict_standard_word_1352[] = "welcome";
PROGMEM const uint8_t _dict_standard_code_1352[] = { 147, 159, 194, 134, 140, 255 };
PROGMEM const char _dict_standard_word_1353[] = "well";
PROGMEM const uint8_t _dict_standard_code_1353[] = { 147, 159, 255 };
PROGMEM const char _dict_standard_word_1354[] = "went";
PROGMEM const uint8_t _dict_standard_code_1354[] = { 147, 131, 141, 191, 255 };
PROGMEM const char _dict_standard_word_1355[] = "wet";
PROGMEM const uint8_t _dict_standard_code_1355[] = { 147, 131, 191, 255 };
PROGMEM const char _dict_standard_word_1356[] = "whale";
PROGMEM const uint8_t _dict_standard_code_1356[] = { 185, 154, 145, 255 };
PROGMEM const char _dict_standard_word_1357[] = "whaler";
PROGMEM const uint8_t _dict_standard_code_1357[] = { 185, 154, 145, 133, 7, 148, 255 };
PROGMEM const char _dict_standard_word_1358[] = "whalers";
PROGMEM const uint8_t _dict_standard_code_1358[] = { 185, 154, 145, 133, 7, 148, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1359[] = "whales";
PROGMEM const uint8_t _dict_standard_code_1359[] = { 185, 154, 159, 167, 255 };
PROGMEM const char _dict_standard_word_1360[] = "whaling";
PROGMEM const uint8_t _dict_standard_code_1360[] = { 185, 154, 145, 129, 143, 255 };
PROGMEM const char _dict_standard_word_1361[] = "what";
PROGMEM const uint8_t _dict_standard_code_1361[] = { 185, 8, 135, 191, 255 };
PROGMEM const char _dict_standard_word_1362[] = "wheel";
PROGMEM const uint8_t _dict_standard_code_1362[] = { 185, 128, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1363[] = "when";
PROGMEM const uint8_t _dict_standard_code_1363[] = { 185, 8, 131, 8, 141, 255 };
PROGMEM const char _dict_standard_word_1364[] = "where";
PROGMEM const uint8_t _dict_standard_code_1364[] = { 147, 150, 255 };
PROGMEM const char _dict_standard_word_1365[] = "whether";
PROGMEM const uint8_t _dict_standard_code_1365[] = { 147, 131, 169, 151, 255 };
PROGMEM const char _dict_standard_word_1366[] = "which";
PROGMEM const uint8_t _dict_standard_code_1366[] = { 185, 129, 8, 182, 255 };
PROGMEM const char _dict_standard_word_1367[] = "whig";
PROGMEM const uint8_t _dict_standard_code_1367[] = { 185, 129, 129, 180, 255 };
PROGMEM const char _dict_standard_word_1368[] = "while";
PROGMEM const uint8_t _dict_standard_code_1368[] = { 185, 155, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1369[] = "whim";
PROGMEM const uint8_t _dict_standard_code_1369[] = { 185, 129, 129, 140, 255 };
PROGMEM const char _dict_standard_word_1370[] = "whisker";
PROGMEM const uint8_t _dict_standard_code_1370[] = { 185, 129, 187, 194, 151, 255 };
PROGMEM const char _dict_standard_word_1371[] = "whisper";
PROGMEM const uint8_t _dict_standard_code_1371[] = { 185, 129, 187, 199, 151, 255 };
PROGMEM const char _dict_standard_word_1372[] = "whistle";
PROGMEM const uint8_t _dict_standard_code_1372[] = { 185, 129, 187, 4, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1373[] = "white";
PROGMEM const uint8_t _dict_standard_code_1373[] = { 185, 155, 191, 255 };
PROGMEM const char _dict_standard_word_1374[] = "whole";
PROGMEM const uint8_t _dict_standard_code_1374[] = { 184, 164, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1375[] = "why";
PROGMEM const uint8_t _dict_standard_code_1375[] = { 185, 157, 255 };
PROGMEM const char _dict_standard_word_1376[] = "wide";
PROGMEM const uint8_t _dict_standard_code_1376[] = { 147, 7, 155, 7, 128, 176, 255 };
PROGMEM const char _dict_standard_word_1377[] = "wig";
PROGMEM const uint8_t _dict_standard_code_1377[] = { 147, 129, 129, 180, 255 };
PROGMEM const char _dict_standard_word_1378[] = "will";
PROGMEM const uint8_t _dict_standard_code_1378[] = { 147, 129, 8, 145, 255 };
PROGMEM const char _dict_standard_word_1379[] = "win";
PROGMEM const uint8_t _dict_standard_code_1379[] = { 147, 129, 8, 142, 255 };
PROGMEM const char _dict_standard_word_1380[] = "wind";
PROGMEM const uint8_t _dict_standard_code_1380[] = { 147, 129, 141, 177, 255 };
PROGMEM const char _dict_standard_word_1381[] = "winter";
PROGMEM const uint8_t _dict_standard_code_1381[] = { 147, 129, 142, 191, 151, 255 };
PROGMEM const char _dict_standard_word_1382[] = "wipe";
PROGMEM const uint8_t _dict_standard_code_1382[] = { 147, 155, 199, 255 };
PROGMEM const char _dict_standard_word_1383[] = "wire";
PROGMEM const uint8_t _dict_standard_code_1383[] = { 147, 155, 148, 255 };
PROGMEM const char _dict_standard_word_1384[] = "wish";
PROGMEM const uint8_t _dict_standard_code_1384[] = { 147, 129, 8, 189, 255 };
PROGMEM const char _dict_standard_word_1385[] = "with";
PROGMEM const uint8_t _dict_standard_code_1385[] = { 147, 129, 8, 8, 190, 255 };
PROGMEM const char _dict_standard_word_1386[] = "woman";
PROGMEM const uint8_t _dict_standard_code_1386[] = { 147, 7, 137, 14, 140, 134, 142, 255 };
PROGMEM const char _dict_standard_word_1387[] = "won";
PROGMEM const uint8_t _dict_standard_code_1387[] = { 147, 14, 135, 8, 141, 255 };
PROGMEM const char _dict_standard_word_1388[] = "wood";
PROGMEM const uint8_t _dict_standard_code_1388[] = { 147, 8, 138, 177, 255 };
PROGMEM const char _dict_standard_word_1389[] = "wool";
PROGMEM const uint8_t _dict_standard_code_1389[] = { 147, 8, 138, 8, 146, 255 };
PROGMEM const char _dict_standard_word_1390[] = "word";
PROGMEM const uint8_t _dict_standard_code_1390[] = { 147, 151, 7, 148, 177, 255 };
PROGMEM const char _dict_standard_word_1391[] = "words";
PROGMEM const uint8_t _dict_standard_code_1391[] = { 147, 151, 176, 7, 167, 255 };
PROGMEM const char _dict_standard_word_1392[] = "work";
PROGMEM const uint8_t _dict_standard_code_1392[] = { 147, 151, 8, 196, 255 };
PROGMEM const char _dict_standard_word_1393[] = "world";
PROGMEM const uint8_t _dict_standard_code_1393[] = { 147, 151, 145, 176, 255 };
PROGMEM const char _dict_standard_word_1394[] = "worm";
PROGMEM const uint8_t _dict_standard_code_1394[] = { 147, 151, 8, 140, 255 };
PROGMEM const char _dict_standard_word_1395[] = "worse";
PROGMEM const uint8_t _dict_standard_code_1395[] = { 147, 151, 8, 187, 255 };
PROGMEM const char _dict_standard_word_1396[] = "worst";
PROGMEM const uint8_t _dict_standard_code_1396[] = { 147, 151, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1397[] = "would";
PROGMEM const uint8_t _dict_standard_code_1397[] = { 147, 8, 138, 177, 255 };
PROGMEM const char _dict_standard_word_1398[] = "wrist";
PROGMEM const uint8_t _dict_standard_code_1398[] = { 148, 8, 129, 187, 191, 255 };
PROGMEM const char _dict_standard_word_1399[] = "wristwatch";
PROGMEM const uint8_t _dict_standard_code_1399[] = { 148, 129, 187, 191, 147, 135, 182, 255 };
PROGMEM const char _dict_standard_word_1400[] = "write";
PROGMEM const uint8_t _dict_standard_code_1400[] = { 148, 155, 191, 255 };
PROGMEM const char _dict_standard_word_1401[] = "wrong";
PROGMEM const uint8_t _dict_standard_code_1401[] = { 148, 135, 8, 144, 255 };
PROGMEM const char _dict_standard_word_1402[] = "x";
PROGMEM const uint8_t _dict_standard_code_1402[] = { 131, 131, 195, 187, 255 };
PROGMEM const char _dict_standard_word_1403[] = "xi";
PROGMEM const uint8_t _dict_standard_code_1403[] = { 195, 187, 155, 255 };
PROGMEM const char _dict_standard_word_1404[] = "xray";
PROGMEM const uint8_t _dict_standard_code_1404[] = { 131, 131, 195, 187, 148, 154, 255 };
PROGMEM const char _dict_standard_word_1405[] = "xylophone";
PROGMEM const uint8_t _dict_standard_code_1405[] = { 167, 155, 146, 137, 186, 137, 142, 255 };
PROGMEM const char _dict_standard_word_1406[] = "y";
PROGMEM const uint8_t _dict_standard_code_1406[] = { 147, 157, 255 };
PROGMEM const char _dict_standard_word_1407[] = "yarn";
PROGMEM const uint8_t _dict_standard_code_1407[] = { 128, 152, 141, 255 };
PROGMEM const char _dict_standard_word_1408[] = "year";
PROGMEM const uint8_t _dict_standard_code_1408[] = { 143, 149, 255 };
PROGMEM const char _dict_standard_word_1409[] = "yell";
PROGMEM const uint8_t _dict_standard_code_1409[] = { 128, 131, 146, 255 };
PROGMEM const char _dict_standard_word_1410[] = "yellow";
PROGMEM const uint8_t _dict_standard_code_1410[] = { 128, 131, 146, 137, 255 };
PROGMEM const char _dict_standard_word_1411[] = "yes";
PROGMEM const uint8_t _dict_standard_code_1411[] = { 158, 187, 187, 255 };
PROGMEM const char _dict_standard_word_1412[] = "yesterday";
PROGMEM const uint8_t _dict_standard_code_1412[] = { 158, 187, 191, 7, 151, 174, 154, 255 };
PROGMEM const char _dict_standard_word_1413[] = "yet";
PROGMEM const uint8_t _dict_standard_code_1413[] = { 158, 191, 255 };
PROGMEM const char _dict_standard_word_1414[] = "you";
PROGMEM const uint8_t _dict_standard_code_1414[] = { 8, 160, 255 };
PROGMEM const char _dict_standard_word_1415[] = "young";
PROGMEM const uint8_t _dict_standard_code_1415[] = { 128, 134, 8, 143, 255 };
PROGMEM const char _dict_standard_word_1416[] = "your";
PROGMEM const uint8_t _dict_standard_code_1416[] = { 128, 153, 255 };
PROGMEM const char _dict_standard_word_1417[] = "yourself";
PROGMEM const uint8_t _dict_standard_code_1417[] = { 128, 153, 187, 131, 145, 186, 255 };
PROGMEM const char _dict_standard_word_1418[] = "z";
PROGMEM const uint8_t _dict_standard_code_1418[] = { 8, 167, 128, 128, 255 };
PROGMEM const char _dict_standard_word_1419[] = "zap";
PROGMEM const uint8_t _dict_standard_code_1419[] = { 167, 8, 132, 199, 255 };
PROGMEM const char _dict_standard_word_1420[] = "zapped";
PROGMEM const uint8_t _dict_standard_code_1420[] = { 167, 8, 132, 199, 191, 255 };
PROGMEM const char _dict_standard_word_1421[] = "zebra";
PROGMEM const uint8_t _dict_standard_code_1421[] = { 167, 7, 128, 18, 170, 7, 148, 134, 255 };
PROGMEM const char _dict_standard_word_1422[] = "zero";
PROGMEM const uint8_t _dict_standard_code_1422[] = { 167, 7, 128, 7, 149, 164, 255 };
PROGMEM const char _dict_standard_word_1423[] = "zeta";
PROGMEM const uint8_t _dict_standard_code_1423[] = { 167, 154, 191, 134, 255 };
PROGMEM const char _dict_standard_word_1424[] = "zipper";
PROGMEM const uint8_t _dict_standard_code_1424[] = { 167, 129, 198, 151, 255 };
PROGMEM const char _dict_standard_word_1425[] = "zone";
PROGMEM const uint8_t _dict_standard_code_1425[] = { 8, 167, 164, 8, 141, 255 };
PROGMEM const char _dict_standard_word_1426[] = "zoo";
PROGMEM const uint8_t _dict_standard_code_1426[] = { 8, 167, 162, 255 };
const DictionaryEntry _dict_standard[] =
{
  { _dict_standard_word_0, _dict_standard_code_0 },
  { _dict_standard_word_1, _dict_standard_code_1 },
  { _dict_standard_word_2, _dict_standard_code_2 },
  { _dict_standard_word_3, _dict_standard_code_3 },
  { _dict_standard_word_4, _dict_standard_code_4 },
  { _dict_standard_word_5, _dict_standard_code_5 },
  { _dict_standard_word_6, _dict_standard_code_6 },
  { _dict_standard_word_7, _dict_standard_code_7 },
  { _dict_standard_word_8, _dict_standard_code_8 },
  { _dict_standard_word_9, _dict_standard_code_9 },
  { _dict_standard_word_10, _dict_standard_code_10 },
  { _dict_standard_word_11, _dict_standard_code_11 },
  { _dict_standard_word_12, _dict_standard_code_12 },
  { _dict_standard_word_13, _dict_standard_code_13 },
  { _dict_standard_word_14, _dict_standard_code_14 },
  { _dict_standard_word_15, _dict_standard_code_15 },
  { _dict_standard_word_16, _dict_standard_code_16 },
  { _dict_standard_word_17, _dict_standard_code_17 },
  { _dict_standard_word_18, _dict_standard_code_18 },
  { _dict_standard_word_19, _dict_standard_code_19 },
  { _dict_standard_word_20, _dict_standard_code_20 },
  { _dict_standard_word_21, _dict_standard_code_21 },
  { _dict_standard_word_22, _dict_standard_code_22 },
  { _dict_standard_word_23, _dict_standard_code_23 },
  { _dict_standard_word_24, _dict_standard_code_24 },
  { _dict_standard_word_25, _dict_standard_code_25 },
  { _dict_standard_word_26, _dict_standard_code_26 },
  { _dict_standard_word_27, _dict_standard_code_27 },
  { _dict_standard_word_28, _dict_standard_code_28 },
  { _dict_standard_word_29, _dict_standard_code_29 },
  { _dict_standard_word_30, _dict_standard_code_30 },
  { _dict_standard_word_31, _dict_standard_code_31 },
  { _dict_standard_word_32, _dict_standard_code_32 },
  { _dict_standard_word_33, _dict_standard_code_33 },
  { _dict_standard_word_34, _dict_standard_code_34 },
  { _dict_standard_word_35, _dict_standard_code_35 },
  { _dict_standard_word_36, _dict_standard_code_36 },
  { _dict_standard_word_37, _dict_standard_code_37 },
  { _dict_standard_word_38, _dict_standard_code_38 },
  { _dict_standard_word_39, _dict_standard_code_39 },
  { _dict_standard_word_40, _dict_standard_code_40 },
  { _dict_standard_word_41, _dict_standard_code_41 },
  { _dict_standard_word_42, _dict_standard_code_42 },
  { _dict_standard_word_43, _dict_standard_code_43 },
  { _dict_standard_word_44, _dict_standard_code_44 },
  { _dict_standard_word_45, _dict_standard_code_45 },
  { _dict_standard_word_46, _dict_standard_code_46 },
  { _dict_standard_word_47, _dict_standard_code_47 },
  { _dict_standard_word_48, _dict_standard_code_48 },
  { _dict_standard_word_49, _dict_standard_code_49 },
  { _dict_standard_word_50, _dict_standard_code_50 },
  { _dict_standard_word_51, _dict_standard_code_51 },
  { _dict_standard_word_52, _dict_standard_code_52 },
  { _dict_standard_word_53, _dict_standard_code_53 },
  { _dict_standard_word_54, _dict_standard_code_54 },
  { _dict_standard_word_55, _dict_standard_code_55 },
  { _dict_standard_word_56, _dict_standard_code_56 },
  { _dict_standard_word_57, _dict_standard_code_57 },
  { _dict_standard_word_58, _dict_standard_code_58 },
  { _dict_standard_word_59, _dict_standard_code_59 },
  { _dict_standard_word_60, _dict_standard_code_60 },
  { _dict_standard_word_61, _dict_standard_code_61 },
  { _dict_standard_word_62, _dict_standard_code_62 },
  { _dict_standard_word_63, _dict_standard_code_63 },
  { _dict_standard_word_64, _dict_standard_code_64 },
  { _dict_standard_word_65, _dict_standard_code_65 },
  { _dict_standard_word_66, _dict_standard_code_66 },
  { _dict_standard_word_67, _dict_standard_code_67 },
  { _dict_standard_word_68, _dict_standard_code_68 },
  { _dict_standard_word_69, _dict_standard_code_69 },
  { _dict_standard_word_70, _dict_standard_code_70 },
  { _dict_standard_word_71, _dict_standard_code_71 },
  { _dict_standard_word_72, _dict_standard_code_72 },
  { _dict_standard_word_73, _dict_standard_code_73 },
  { _dict_standard_word_74, _dict_standard_code_74 },
  { _dict_standard_word_75, _dict_standard_code_75 },
  { _dict_standard_word_76, _dict_standard_code_76 },
  { _dict_standard_word_77, _dict_standard_code_77 },
  { _dict_standard_word_78, _dict_standard_code_78 },
  { _dict_standard_word_79, _dict_standard_code_79 },
  { _dict_standard_word_80, _dict_standard_code_80 },
  { _dict_standard_word_81, _dict_standard_code_81 },
  { _dict_standard_word_82, _dict_standard_code_82 },
  { _dict_standard_word_83, _dict_standard_code_83 },
  { _dict_standard_word_84, _dict_standard_code_84 },
  { _dict_standard_word_85, _dict_standard_code_85 },
  { _dict_standard_word_86, _dict_standard_code_86 },
  { _dict_standard_word_87, _dict_standard_code_87 },
  { _dict_standard_word_88, _dict_standard_code_88 },
  { _dict_standard_word_89, _dict_standard_code_89 },
  { _dict_standard_word_90, _dict_standard_code_90 },
  { _dict_standard_word_91, _dict_standard_code_91 },
  { _dict_standard_word_92, _dict_standard_code_92 },
  { _dict_standard_word_93, _dict_standard_code_93 },
  { _dict_standard_word_94, _dict_standard_code_94 },
  { _dict_standard_word_95, _dict_standard_code_95 },
  { _dict_standard_word_96, _dict_standard_code_96 },
  { _dict_standard_word_97, _dict_standard_code_97 },
  { _dict_standard_word_98, _dict_standard_code_98 },
  { _dict_standard_word_99, _dict_standard_code_99 },
  { _dict_standard_word_100, _dict_standard_code_100 },
  { _dict_standard_word_101, _dict_standard_code_101 },
  { _dict_standard_word_102, _dict_standard_code_102 },
  { _dict_standard_word_103, _dict_standard_code_103 },
  { _dict_standard_word_104, _dict_standard_code_104 },
  { _dict_standard_word_105, _dict_standard_code_105 },
  { _dict_standard_word_106, _dict_standard_code_106 },
  { _dict_standard_word_107, _dict_standard_code_107 },
  { _dict_standard_word_108, _dict_standard_code_108 },
  { _dict_standard_word_109, _dict_standard_code_109 },
  { _dict_standard_word_110, _dict_standard_code_110 },
  { _dict_standard_word_111, _dict_standard_code_111 },
  { _dict_standard_word_112, _dict_standard_code_112 },
  { _dict_standard_word_113, _dict_standard_code_113 },
  { _dict_standard_word_114, _dict_standard_code_114 },
  { _dict_standard_word_115, _dict_standard_code_115 },
  { _dict_standard_word_116, _dict_standard_code_116 },
  { _dict_standard_word_117, _dict_standard_code_117 },
  { _dict_standard_word_118, _dict_standard_code_118 },
  { _dict_standard_word_119, _dict_standard_code_119 },
  { _dict_standard_word_120, _dict_standard_code_120 },
  { _dict_standard_word_121, _dict_standard_code_121 },
  { _dict_standard_word_122, _dict_standard_code_122 },
  { _dict_standard_word_123, _dict_standard_code_123 },
  { _dict_standard_word_124, _dict_standard_code_124 },
  { _dict_standard_word_125, _dict_standard_code_125 },
  { _dict_standard_word_126, _dict_standard_code_126 },
  { _dict_standard_word_127, _dict_standard_code_127 },
  { _dict_standard_word_128, _dict_standard_code_128 },
  { _dict_standard_word_129, _dict_standard_code_129 },
  { _dict_standard_word_130, _dict_standard_code_130 },
  { _dict_standard_word_131, _dict_standard_code_131 },
  { _dict_standard_word_132, _dict_standard_code_132 },
  { _dict_standard_word_133, _dict_standard_code_133 },
  { _dict_standard_word_134, _dict_standard_code_134 },
  { _dict_standard_word_135, _dict_standard_code_135 },
  { _dict_standard_word_136, _dict_standard_code_136 },
  { _dict_standard_word_137, _dict_standard_code_137 },
  { _dict_standard_word_138, _dict_standard_code_138 },
  { _dict_standard_word_139, _dict_standard_code_139 },
  { _dict_standard_word_140, _dict_standard_code_140 },
  { _dict_standard_word_141, _dict_standard_code_141 },
  { _dict_standard_word_142, _dict_standard_code_142 },
  { _dict_standard_word_143, _dict_standard_code_143 },
  { _dict_standard_word_144, _dict_standard_code_144 },
  { _dict_standard_word_145, _dict_standard_code_145 },
  { _dict_standard_word_146, _dict_standard_code_146 },
  { _dict_standard_word_147, _dict_standard_code_147 },
  { _dict_standard_word_148, _dict_standard_code_148 },
  { _dict_standard_word_149, _dict_standard_code_149 },
  { _dict_standard_word_150, _dict_standard_code_150 },
  { _dict_standard_word_151, _dict_standard_code_151 },
  { _dict_standard_word_152, _dict_standard_code_152 },
  { _dict_standard_word_153, _dict_standard_code_153 },
  { _dict_standard_word_154, _dict_standard_code_154 },
  { _dict_standard_word_155, _dict_standard_code_155 },
  { _dict_standard_word_156, _dict_standard_code_156 },
  { _dict_standard_word_157, _dict_standard_code_157 },
  { _dict_standard_word_158, _dict_standard_code_158 },
  { _dict_standard_word_159, _dict_standard_code_159 },
  { _dict_standard_word_160, _dict_standard_code_160 },
  { _dict_standard_word_161, _dict_standard_code_161 },
  { _dict_standard_word_162, _dict_standard_code_162 },
  { _dict_standard_word_163, _dict_standard_code_163 },
  { _dict_standard_word_164, _dict_standard_code_164 },
  { _dict_standard_word_165, _dict_standard_code_165 },
  { _dict_standard_word_166, _dict_standard_code_166 },
  { _dict_standard_word_167, _dict_standard_code_167 },
  { _dict_standard_word_168, _dict_standard_code_168 },
  { _dict_standard_word_169, _dict_standard_code_169 },
  { _dict_standard_word_170, _dict_standard_code_170 },
  { _dict_standard_word_171, _dict_standard_code_171 },
  { _dict_standard_word_172, _dict_standard_code_172 },
  { _dict_standard_word_173, _dict_standard_code_173 },
  { _dict_standard_word_174, _dict_standard_code_174 },
  { _dict_standard_word_175, _dict_standard_code_175 },
  { _dict_standard_word_176, _dict_standard_code_176 },
  { _dict_standard_word_177, _dict_standard_code_177 },
  { _dict_standard_word_178, _dict_standard_code_178 },
  { _dict_standard_word_179, _dict_standard_code_179 },
  { _dict_standard_word_180, _dict_standard_code_180 },
  { _dict_standard_word_181, _dict_standard_code_181 },
  { _dict_standard_word_182, _dict_standard_code_182 },
  { _dict_standard_word_183, _dict_standard_code_183 },
  { _dict_standard_word_184, _dict_standard_code_184 },
  { _dict_standard_word_185, _dict_standard_code_185 },
  { _dict_standard_word_186, _dict_standard_code_186 },
  { _dict_standard_word_187, _dict_standard_code_187 },
  { _dict_standard_word_188, _dict_standard_code_188 },
  { _dict_standard_word_189, _dict_standard_code_189 },
  { _dict_standard_word_190, _dict_standard_code_190 },
  { _dict_standard_word_191, _dict_standard_code_191 },
  { _dict_standard_word_192, _dict_standard_code_192 },
  { _dict_standard_word_193, _dict_standard_code_193 },
  { _dict_standard_word_194, _dict_standard_code_194 },
  { _dict_standard_word_195, _dict_standard_code_195 },
  { _dict_standard_word_196, _dict_standard_code_196 },
  { _dict_standard_word_197, _dict_standard_code_197 },
  { _dict_standard_word_198, _dict_standard_code_198 },
  { _dict_standard_word_199, _dict_standard_code_199 },
  { _dict_standard_word_200, _dict_standard_code_200 },
  { _dict_standard_word_201, _dict_standard_code_201 },
  { _dict_standard_word_202, _dict_standard_code_202 },
  { _dict_standard_word_203, _dict_standard_code_203 },
  { _dict_standard_word_204, _dict_standard_code_204 },
  { _dict_standard_word_205, _dict_standard_code_205 },
  { _dict_standard_word_206, _dict_standard_code_206 },
  { _dict_standard_word_207, _dict_standard_code_207 },
  { _dict_standard_word_208, _dict_standard_code_208 },
  { _dict_standard_word_209, _dict_standard_code_209 },
  { _dict_standard_word_210, _dict_standard_code_210 },
  { _dict_standard_word_211, _dict_standard_code_211 },
  { _dict_standard_word_212, _dict_standard_code_212 },
  { _dict_standard_word_213, _dict_standard_code_213 },
  { _dict_standard_word_214, _dict_standard_code_214 },
  { _dict_standard_word_215, _dict_standard_code_215 },
  { _dict_standard_word_216, _dict_standard_code_216 },
  { _dict_standard_word_217, _dict_standard_code_217 },
  { _dict_standard_word_218, _dict_standard_code_218 },
  { _dict_standard_word_219, _dict_standard_code_219 },
  { _dict_standard_word_220, _dict_standard_code_220 },
  { _dict_standard_word_221, _dict_standard_code_221 },
  { _dict_standard_word_222, _dict_standard_code_222 },
  { _dict_standard_word_223, _dict_standard_code_223 },
  { _dict_standard_word_224, _dict_standard_code_224 },
  { _dict_standard_word_225, _dict_standard_code_225 },
  { _dict_standard_word_226, _dict_standard_code_226 },
  { _dict_standard_word_227, _dict_standard_code_227 },
  { _dict_standard_word_228, _dict_standard_code_228 },
  { _dict_standard_word_229, _dict_standard_code_229 },
  { _dict_standard_word_230, _dict_standard_code_230 },
  { _dict_standard_word_231, _dict_standard_code_231 },
  { _dict_standard_word_232, _dict_standard_code_232 },
  { _dict_standard_word_233, _dict_standard_code_233 },
  { _dict_standard_word_234, _dict_standard_code_234 },
  { _dict_standard_word_235, _dict_standard_code_235 },
  { _dict_standard_word_236, _dict_standard_code_236 },
  { _dict_standard_word_237, _dict_standard_code_237 },
  { _dict_standard_word_238, _dict_standard_code_238 },
  { _dict_standard_word_239, _dict_standard_code_239 },
  { _dict_standard_word_240, _dict_standard_code_240 },
  { _dict_standard_word_241, _dict_standard_code_241 },
  { _dict_standard_word_242, _dict_standard_code_242 },
  { _dict_standard_word_243, _dict_standard_code_243 },
  { _dict_standard_word_244, _dict_standard_code_244 },
  { _dict_standard_word_245, _dict_standard_code_245 },
  { _dict_standard_word_246, _dict_standard_code_246 },
  { _dict_standard_word_247, _dict_standard_code_247 },
  { _dict_standard_word_248, _dict_standard_code_248 },
  { _dict_standard_word_249, _dict_standard_code_249 },
  { _dict_standard_word_250, _dict_standard_code_250 },
  { _dict_standard_word_251, _dict_standard_code_251 },
  { _dict_standard_word_252, _dict_standard_code_252 },
  { _dict_standard_word_253, _dict_standard_code_253 },
  { _dict_standard_word_254, _dict_standard_code_254 },
  { _dict_standard_word_255, _dict_standard_code_255 },
  { _dict_standard_word_256, _dict_standard_code_256 },
  { _dict_standard_word_257, _dict_standard_code_257 },
  { _dict_standard_word_258, _dict_standard_code_258 },
  { _dict_standard_word_259, _dict_standard_code_259 },
  { _dict_standard_word_260, _dict_standard_code_260 },
  { _dict_standard_word_261, _dict_standard_code_261 },
  { _dict_standard_word_262, _dict_standard_code_262 },
  { _dict_standard_word_263, _dict_standard_code_263 },
  { _dict_standard_word_264, _dict_standard_code_264 },
  { _dict_standard_word_265, _dict_standard_code_265 },
  { _dict_standard_word_266, _dict_standard_code_266 },
  { _dict_standard_word_267, _dict_standard_code_267 },
  { _dict_standard_word_268, _dict_standard_code_268 },
  { _dict_standard_word_269, _dict_standard_code_269 },
  { _dict_standard_word_270, _dict_standard_code_270 },
  { _dict_standard_word_271, _dict_standard_code_271 },
  { _dict_standard_word_272, _dict_standard_code_272 },
  { _dict_standard_word_273, _dict_standard_code_273 },
  { _dict_standard_word_274, _dict_standard_code_274 },
  { _dict_standard_word_275, _dict_standard_code_275 },
  { _dict_standard_word_276, _dict_standard_code_276 },
  { _dict_standard_word_277, _dict_standard_code_277 },
  { _dict_standard_word_278, _dict_standard_code_278 },
  { _dict_standard_word_279, _dict_standard_code_279 },
  { _dict_standard_word_280, _dict_standard_code_280 },
  { _dict_standard_word_281, _dict_standard_code_281 },
  { _dict_standard_word_282, _dict_standard_code_282 },
  { _dict_standard_word_283, _dict_standard_code_283 },
  { _dict_standard_word_284, _dict_standard_code_284 },
  { _dict_standard_word_285, _dict_standard_code_285 },
  { _dict_standard_word_286, _dict_standard_code_286 },
  { _dict_standard_word_287, _dict_standard_code_287 },
  { _dict_standard_word_288, _dict_standard_code_288 },
  { _dict_standard_word_289, _dict_standard_code_289 },
  { _dict_standard_word_290, _dict_standard_code_290 },
  { _dict_standard_word_291, _dict_standard_code_291 },
  { _dict_standard_word_292, _dict_standard_code_292 },
  { _dict_standard_word_293, _dict_standard_code_293 },
  { _dict_standard_word_294, _dict_standard_code_294 },
  { _dict_standard_word_295, _dict_standard_code_295 },
  { _dict_standard_word_296, _dict_standard_code_296 },
  { _dict_standard_word_297, _dict_standard_code_297 },
  { _dict_standard_word_298, _dict_standard_code_298 },
  { _dict_standard_word_299, _dict_standard_code_299 },
  { _dict_standard_word_300, _dict_standard_code_300 },
  { _dict_standard_word_301, _dict_standard_code_301 },
  { _dict_standard_word_302, _dict_standard_code_302 },
  { _dict_standard_word_303, _dict_standard_code_303 },
  { _dict_standard_word_304, _dict_standard_code_304 },
  { _dict_standard_word_305, _dict_standard_code_305 },
  { _dict_standard_word_306, _dict_standard_code_306 },
  { _dict_standard_word_307, _dict_standard_code_307 },
  { _dict_standard_word_308, _dict_standard_code_308 },
  { _dict_standard_word_309, _dict_standard_code_309 },
  { _dict_standard_word_310, _dict_standard_code_310 },
  { _dict_standard_word_311, _dict_standard_code_311 },
  { _dict_standard_word_312, _dict_standard_code_312 },
  { _dict_standard_word_313, _dict_standard_code_313 },
  { _dict_standard_word_314, _dict_standard_code_314 },
  { _dict_standard_word_315, _dict_standard_code_315 },
  { _dict_standard_word_316, _dict_standard_code_316 },
  { _dict_standard_word_317, _dict_standard_code_317 },
  { _dict_standard_word_318, _dict_standard_code_318 },
  { _dict_standard_word_319, _dict_standard_code_319 },
  { _dict_standard_word_320, _dict_standard_code_320 },
  { _dict_standard_word_321, _dict_standard_code_321 },
  { _dict_standard_word_322, _dict_standard_code_322 },
  { _dict_standard_word_323, _dict_standard_code_323 },
  { _dict_standard_word_324, _dict_standard_code_324 },
  { _dict_standard_word_325, _dict_standard_code_325 },
  { _dict_standard_word_326, _dict_standard_code_326 },
  { _dict_standard_word_327, _dict_standard_code_327 },
  { _dict_standard_word_328, _dict_standard_code_328 },
  { _dict_standard_word_329, _dict_standard_code_329 },
  { _dict_standard_word_330, _dict_standard_code_330 },
  { _dict_standard_word_331, _dict_standard_code_331 },
  { _dict_standard_word_332, _dict_standard_code_332 },
  { _dict_standard_word_333, _dict_standard_code_333 },
  { _dict_standard_word_334, _dict_standard_code_334 },
  { _dict_standard_word_335, _dict_standard_code_335 },
  { _dict_standard_word_336, _dict_standard_code_336 },
  { _dict_standard_word_337, _dict_standard_code_337 },
  { _dict_standard_word_338, _dict_standard_code_338 },
  { _dict_standard_word_339, _dict_standard_code_339 },
  { _dict_standard_word_340, _dict_standard_code_340 },
  { _dict_standard_word_341, _dict_standard_code_341 },
  { _dict_standard_word_342, _dict_standard_code_342 },
  { _dict_standard_word_343, _dict_standard_code_343 },
  { _dict_standard_word_344, _dict_standard_code_344 },
  { _dict_standard_word_345, _dict_standard_code_345 },
  { _dict_standard_word_346, _dict_standard_code_346 },
  { _dict_standard_word_347, _dict_standard_code_347 },
  { _dict_standard_word_348, _dict_standard_code_348 },
  { _dict_standard_word_349, _dict_standard_code_349 },
  { _dict_standard_word_350, _dict_standard_code_350 },
  { _dict_standard_word_351, _dict_standard_code_351 },
  { _dict_standard_word_352, _dict_standard_code_352 },
  { _dict_standard_word_353, _dict_standard_code_353 },
  { _dict_standard_word_354, _dict_standard_code_354 },
  { _dict_standard_word_355, _dict_standard_code_355 },
  { _dict_standard_word_356, _dict_standard_code_356 },
  { _dict_standard_word_357, _dict_standard_code_357 },
  { _dict_standard_word_358, _dict_standard_code_358 },
  { _dict_standard_word_359, _dict_standard_code_359 },
  { _dict_standard_word_360, _dict_standard_code_360 },
  { _dict_standard_word_361, _dict_standard_code_361 },
  { _dict_standard_word_362, _dict_standard_code_362 },
  { _dict_standard_word_363, _dict_standard_code_363 },
  { _dict_standard_word_364, _dict_standard_code_364 },
  { _dict_standard_word_365, _dict_standard_code_365 },
  { _dict_standard_word_366, _dict_standard_code_366 },
  { _dict_standard_word_367, _dict_standard_code_367 },
  { _dict_standard_word_368, _dict_standard_code_368 },
  { _dict_standard_word_369, _dict_standard_code_369 },
  { _dict_standard_word_370, _dict_standard_code_370 },
  { _dict_standard_word_371, _dict_standard_code_371 },
  { _dict_standard_word_372, _dict_standard_code_372 },
  { _dict_standard_word_373, _dict_standard_code_373 },
  { _dict_standard_word_374, _dict_standard_code_374 },
  { _dict_standard_word_375, _dict_standard_code_375 },
  { _dict_standard_word_376, _dict_standard_code_376 },
  { _dict_standard_word_377, _dict_standard_code_377 },
  { _dict_standard_word_378, _dict_standard_code_378 },
  { _dict_standard_word_379, _dict_standard_code_379 },
  { _dict_standard_word_380, _dict_standard_code_380 },
  { _dict_standard_word_381, _dict_standard_code_381 },
  { _dict_standard_word_382, _dict_standard_code_382 },
  { _dict_standard_word_383, _dict_standard_code_383 },
  { _dict_standard_word_384, _dict_standard_code_384 },
  { _dict_standard_word_385, _dict_standard_code_385 },
  { _dict_standard_word_386, _dict_standard_code_386 },
  { _dict_standard_word_387, _dict_standard_code_387 },
  { _dict_standard_word_388, _dict_standard_code_388 },
  { _dict_standard_word_389, _dict_standard_code_389 },
  { _dict_standard_word_390, _dict_standard_code_390 },
  { _dict_standard_word_391, _dict_standard_code_391 },
  { _dict_standard_word_392, _dict_standard_code_392 },
  { _dict_standard_word_393, _dict_standard_code_393 },
  { _dict_standard_word_394, _dict_standard_code_394 },
  { _dict_standard_word_395, _dict_standard_code_395 },
  { _dict_standard_word_396, _dict_standard_code_396 },
  { _dict_standard_word_397, _dict_standard_code_397 },
  { _dict_standard_word_398, _dict_standard_code_398 },
  { _dict_standard_word_399, _dict_standard_code_399 },
  { _dict_standard_word_400, _dict_standard_code_400 },
  { _dict_standard_word_401, _dict_standard_code_401 },
  { _dict_standard_word_402, _dict_standard_code_402 },
  { _dict_standard_word_403, _dict_standard_code_403 },
  { _dict_standard_word_404, _dict_standard_code_404 },
  { _dict_standard_word_405, _dict_standard_code_405 },
  { _dict_standard_word_406, _dict_standard_code_406 },
  { _dict_standard_word_407, _dict_standard_code_407 },
  { _dict_standard_word_408, _dict_standard_code_408 },
  { _dict_standard_word_409, _dict_standard_code_409 },
  { _dict_standard_word_410, _dict_standard_code_410 },
  { _dict_standard_word_411, _dict_standard_code_411 },
  { _dict_standard_word_412, _dict_standard_code_412 },
  { _dict_standard_word_413, _dict_standard_code_413 },
  { _dict_standard_word_414, _dict_standard_code_414 },
  { _dict_standard_word_415, _dict_standard_code_415 },
  { _dict_standard_word_416, _dict_standard_code_416 },
  { _dict_standard_word_417, _dict_standard_code_417 },
  { _dict_standard_word_418, _dict_standard_code_418 },
  { _dict_standard_word_419, _dict_standard_code_419 },
  { _dict_standard_word_420, _dict_standard_code_420 },
  { _dict_standard_word_421, _dict_standard_code_421 },
  { _dict_standard_word_422, _dict_standard_code_422 },
  { _dict_standard_word_423, _dict_standard_code_423 },
  { _dict_standard_word_424, _dict_standard_code_424 },
  { _dict_standard_word_425, _dict_standard_code_425 },
  { _dict_standard_word_426, _dict_standard_code_426 },
  { _dict_standard_word_427, _dict_standard_code_427 },
  { _dict_standard_word_428, _dict_standard_code_428 },
  { _dict_standard_word_429, _dict_standard_code_429 },
  { _dict_standard_word_430, _dict_standard_code_430 },
  { _dict_standard_word_431, _dict_standard_code_431 },
  { _dict_standard_word_432, _dict_standard_code_432 },
  { _dict_standard_word_433, _dict_standard_code_433 },
  { _dict_standard_word_434, _dict_standard_code_434 },
  { _dict_standard_word_435, _dict_standard_code_435 },
  { _dict_standard_word_436, _dict_standard_code_436 },
  { _dict_standard_word_437, _dict_standard_code_437 },
  { _dict_standard_word_438, _dict_standard_code_438 },
  { _dict_standard_word_439, _dict_standard_code_439 },
  { _dict_standard_word_440, _dict_standard_code_440 },
  { _dict_standard_word_441, _dict_standard_code_441 },
  { _dict_standard_word_442, _dict_standard_code_442 },
  { _dict_standard_word_443, _dict_standard_code_443 },
  { _dict_standard_word_444, _dict_standard_code_444 },
  { _dict_standard_word_445, _dict_standard_code_445 },
  { _dict_standard_word_446, _dict_standard_code_446 },
  { _dict_standard_word_447, _dict_standard_code_447 },
  { _dict_standard_word_448, _dict_standard_code_448 },
  { _dict_standard_word_449, _dict_standard_code_449 },
  { _dict_standard_word_450, _dict_standard_code_450 },
  { _dict_standard_word_451, _dict_standard_code_451 },
  { _dict_standard_word_452, _dict_standard_code_452 },
  { _dict_standard_word_453, _dict_standard_code_453 },
  { _dict_standard_word_454, _dict_standard_code_454 },
  { _dict_standard_word_455, _dict_standard_code_455 },
  { _dict_standard_word_456, _dict_standard_code_456 },
  { _dict_standard_word_457, _dict_standard_code_457 },
  { _dict_standard_word_458, _dict_standard_code_458 },
  { _dict_standard_word_459, _dict_standard_code_459 },
  { _dict_standard_word_460, _dict_standard_code_460 },
  { _dict_standard_word_461, _dict_standard_code_461 },
  { _dict_standard_word_462, _dict_standard_code_462 },
  { _dict_standard_word_463, _dict_standard_code_463 },
  { _dict_standard_word_464, _dict_standard_code_464 },
  { _dict_standard_word_465, _dict_standard_code_465 },
  { _dict_standard_word_466, _dict_standard_code_466 },
  { _dict_standard_word_467, _dict_standard_code_467 },
  { _dict_standard_word_468, _dict_standard_code_468 },
  { _dict_standard_word_469, _dict_standard_code_469 },
  { _dict_standard_word_470, _dict_standard_code_470 },
  { _dict_standard_word_471, _dict_standard_code_471 },
  { _dict_standard_word_472, _dict_standard_code_472 },
  { _dict_standard_word_473, _dict_standard_code_473 },
  { _dict_standard_word_474, _dict_standard_code_474 },
  { _dict_standard_word_475, _dict_standard_code_475 },
  { _dict_standard_word_476, _dict_standard_code_476 },
  { _dict_standard_word_477, _dict_standard_code_477 },
  { _dict_standard_word_478, _dict_standard_code_478 },
  { _dict_standard_word_479, _dict_standard_code_479 },
  { _dict_standard_word_480, _dict_standard_code_480 },
  { _dict_standard_word_481, _dict_standard_code_481 },
  { _dict_standard_word_482, _dict_standard_code_482 },
  { _dict_standard_word_483, _dict_standard_code_483 },
  { _dict_standard_word_484, _dict_standard_code_484 },
  { _dict_standard_word_485, _dict_standard_code_485 },
  { _dict_standard_word_486, _dict_standard_code_486 },
  { _dict_standard_word_487, _dict_standard_code_487 },
  { _dict_standard_word_488, _dict_standard_code_488 },
  { _dict_standard_word_489, _dict_standard_code_489 },
  { _dict_standard_word_490, _dict_standard_code_490 },
  { _dict_standard_word_491, _dict_standard_code_491 },
  { _dict_standard_word_492, _dict_standard_code_492 },
  { _dict_standard_word_493, _dict_standard_code_493 },
  { _dict_standard_word_494, _dict_standard_code_494 },
  { _dict_standard_word_495, _dict_standard_code_495 },
  { _dict_standard_word_496, _dict_standard_code_496 },
  { _dict_standard_word_497, _dict_standard_code_497 },
  { _dict_standard_word_498, _dict_standard_code_498 },
  { _dict_standard_word_499, _dict_standard_code_499 },
  { _dict_standard_word_500, _dict_standard_code_500 },
  { _dict_standard_word_501, _dict_standard_code_501 },
  { _dict_standard_word_502, _dict_standard_code_502 },
  { _dict_standard_word_503, _dict_standard_code_503 },
  { _dict_standard_word_504, _dict_standard_code_504 },
  { _dict_standard_word_505, _dict_standard_code_505 },
  { _dict_standard_word_506, _dict_standard_code_506 },
  { _dict_standard_word_507, _dict_standard_code_507 },
  { _dict_standard_word_508, _dict_standard_code_508 },
  { _dict_standard_word_509, _dict_standard_code_509 },
  { _dict_standard_word_510, _dict_standard_code_510 },
  { _dict_standard_word_511, _dict_standard_code_511 },
  { _dict_standard_word_512, _dict_standard_code_512 },
  { _dict_standard_word_513, _dict_standard_code_513 },
  { _dict_standard_word_514, _dict_standard_code_514 },
  { _dict_standard_word_515, _dict_standard_code_515 },
  { _dict_standard_word_516, _dict_standard_code_516 },
  { _dict_standard_word_517, _dict_standard_code_517 },
  { _dict_standard_word_518, _dict_standard_code_518 },
  { _dict_standard_word_519, _dict_standard_code_519 },
  { _dict_standard_word_520, _dict_standard_code_520 },
  { _dict_standard_word_521, _dict_standard_code_521 },
  { _dict_standard_word_522, _dict_standard_code_522 },
  { _dict_standard_word_523, _dict_standard_code_523 },
  { _dict_standard_word_524, _dict_standard_code_524 },
  { _dict_standard_word_525, _dict_standard_code_525 },
  { _dict_standard_word_526, _dict_standard_code_526 },
  { _dict_standard_word_527, _dict_standard_code_527 },
  { _dict_standard_word_528, _dict_standard_code_528 },
  { _dict_standard_word_529, _dict_standard_code_529 },
  { _dict_standard_word_530, _dict_standard_code_530 },
  { _dict_standard_word_531, _dict_standard_code_531 },
  { _dict_standard_word_532, _dict_standard_code_532 },
  { _dict_standard_word_533, _dict_standard_code_533 },
  { _dict_standard_word_534, _dict_standard_code_534 },
  { _dict_standard_word_535, _dict_standard_code_535 },
  { _dict_standard_word_536, _dict_standard_code_536 },
  { _dict_standard_word_537, _dict_standard_code_537 },
  { _dict_standard_word_538, _dict_standard_code_538 },
  { _dict_standard_word_539, _dict_standard_code_539 },
  { _dict_standard_word_540, _dict_standard_code_540 },
  { _dict_standard_word_541, _dict_standard_code_541 },
  { _dict_standard_word_542, _dict_standard_code_542 },
  { _dict_standard_word_543, _dict_standard_code_543 },
  { _dict_standard_word_544, _dict_standard_code_544 },
  { _dict_standard_word_545, _dict_standard_code_545 },
  { _dict_standard_word_546, _dict_standard_code_546 },
  { _dict_standard_word_547, _dict_standard_code_547 },
  { _dict_standard_word_548, _dict_standard_code_548 },
  { _dict_standard_word_549, _dict_standard_code_549 },
  { _dict_standard_word_550, _dict_standard_code_550 },
  { _dict_standard_word_551, _dict_standard_code_551 },
  { _dict_standard_word_552, _dict_standard_code_552 },
  { _dict_standard_word_553, _dict_standard_code_553 },
  { _dict_standard_word_554, _dict_standard_code_554 },
  { _dict_standard_word_555, _dict_standard_code_555 },
  { _dict_standard_word_556, _dict_standard_code_556 },
  { _dict_standard_word_557, _dict_standard_code_557 },
  { _dict_standard_word_558, _dict_standard_code_558 },
  { _dict_standard_word_559, _dict_standard_code_559 },
  { _dict_standard_word_560, _dict_standard_code_560 },
  { _dict_standard_word_561, _dict_standard_code_561 },
  { _dict_standard_word_562, _dict_standard_code_562 },
  { _dict_standard_word_563, _dict_standard_code_563 },
  { _dict_standard_word_564, _dict_standard_code_564 },
  { _dict_standard_word_565, _dict_standard_code_565 },
  { _dict_standard_word_566, _dict_standard_code_566 },
  { _dict_standard_word_567, _dict_standard_code_567 },
  { _dict_standard_word_568, _dict_standard_code_568 },
  { _dict_standard_word_569, _dict_standard_code_569 },
  { _dict_standard_word_570, _dict_standard_code_570 },
  { _dict_standard_word_571, _dict_standard_code_571 },
  { _dict_standard_word_572, _dict_standard_code_572 },
  { _dict_standard_word_573, _dict_standard_code_573 },
  { _dict_standard_word_574, _dict_standard_code_574 },
  { _dict_standard_word_575, _dict_standard_code_575 },
  { _dict_standard_word_576, _dict_standard_code_576 },
  { _dict_standard_word_577, _dict_standard_code_577 },
  { _dict_standard_word_578, _dict_standard_code_578 },
  { _dict_standard_word_579, _dict_standard_code_579 },
  { _dict_standard_word_580, _dict_standard_code_580 },
  { _dict_standard_word_581, _dict_standard_code_581 },
  { _dict_standard_word_582, _dict_standard_code_582 },
  { _dict_standard_word_583, _dict_standard_code_583 },
  { _dict_standard_word_584, _dict_standard_code_584 },
  { _dict_standard_word_585, _dict_standard_code_585 },
  { _dict_standard_word_586, _dict_standard_code_586 },
  { _dict_standard_word_587, _dict_standard_code_587 },
  { _dict_standard_word_588, _dict_standard_code_588 },
  { _dict_standard_word_589, _dict_standard_code_589 },
  { _dict_standard_word_590, _dict_standard_code_590 },
  { _dict_standard_word_591, _dict_standard_code_591 },
  { _dict_standard_word_592, _dict_standard_code_592 },
  { _dict_standard_word_593, _dict_standard_code_593 },
  { _dict_standard_word_594, _dict_standard_code_594 },
  { _dict_standard_word_595, _dict_standard_code_595 },
  { _dict_standard_word_596, _dict_standard_code_596 },
  { _dict_standard_word_597, _dict_standard_code_597 },
  { _dict_standard_word_598, _dict_standard_code_598 },
  { _dict_standard_word_599, _dict_standard_code_599 },
  { _dict_standard_word_600, _dict_standard_code_600 },
  { _dict_standard_word_601, _dict_standard_code_601 },
  { _dict_standard_word_602, _dict_standard_code_602 },
  { _dict_standard_word_603, _dict_standard_code_603 },
  { _dict_standard_word_604, _dict_standard_code_604 },
  { _dict_standard_word_605, _dict_standard_code_605 },
  { _dict_standard_word_606, _dict_standard_code_606 },
  { _dict_standard_word_607, _dict_standard_code_607 },
  { _dict_standard_word_608, _dict_standard_code_608 },
  { _dict_standard_word_609, _dict_standard_code_609 },
  { _dict_standard_word_610, _dict_standard_code_610 },
  { _dict_standard_word_611, _dict_standard_code_611 },
  { _dict_standard_word_612, _dict_standard_code_612 },
  { _dict_standard_word_613, _dict_standard_code_613 },
  { _dict_standard_word_614, _dict_standard_code_614 },
  { _dict_standard_word_615, _dict_standard_code_615 },
  { _dict_standard_word_616, _dict_standard_code_616 },
  { _dict_standard_word_617, _dict_standard_code_617 },
  { _dict_standard_word_618, _dict_standard_code_618 },
  { _dict_standard_word_619, _dict_standard_code_619 },
  { _dict_standard_word_620, _dict_standard_code_620 },
  { _dict_standard_word_621, _dict_standard_code_621 },
  { _dict_standard_word_622, _dict_standard_code_622 },
  { _dict_standard_word_623, _dict_standard_code_623 },
  { _dict_standard_word_624, _dict_standard_code_624 },
  { _dict_standard_word_625, _dict_standard_code_625 },
  { _dict_standard_word_626, _dict_standard_code_626 },
  { _dict_standard_word_627, _dict_standard_code_627 },
  { _dict_standard_word_628, _dict_standard_code_628 },
  { _dict_standard_word_629, _dict_standard_code_629 },
  { _dict_standard_word_630, _dict_standard_code_630 },
  { _dict_standard_word_631, _dict_standard_code_631 },
  { _dict_standard_word_632, _dict_standard_code_632 },
  { _dict_standard_word_633, _dict_standard_code_633 },
  { _dict_standard_word_634, _dict_standard_code_634 },
  { _dict_standard_word_635, _dict_standard_code_635 },
  { _dict_standard_word_636, _dict_standard_code_636 },
  { _dict_standard_word_637, _dict_standard_code_637 },
  { _dict_standard_word_638, _dict_standard_code_638 },
  { _dict_standard_word_639, _dict_standard_code_639 },
  { _dict_standard_word_640, _dict_standard_code_640 },
  { _dict_standard_word_641, _dict_standard_code_641 },
  { _dict_standard_word_642, _dict_standard_code_642 },
  { _dict_standard_word_643, _dict_standard_code_643 },
  { _dict_standard_word_644, _dict_standard_code_644 },
  { _dict_standard_word_645, _dict_standard_code_645 },
  { _dict_standard_word_646, _dict_standard_code_646 },
  { _dict_standard_word_647, _dict_standard_code_647 },
  { _dict_standard_word_648, _dict_standard_code_648 },
  { _dict_standard_word_649, _dict_standard_code_649 },
  { _dict_standard_word_650, _dict_standard_code_650 },
  { _dict_standard_word_651, _dict_standard_code_651 },
  { _dict_standard_word_652, _dict_standard_code_652 },
  { _dict_standard_word_653, _dict_standard_code_653 },
  { _dict_standard_word_654, _dict_standard_code_654 },
  { _dict_standard_word_655, _dict_standard_code_655 },
  { _dict_standard_word_656, _dict_standard_code_656 },
  { _dict_standard_word_657, _dict_standard_code_657 },
  { _dict_standard_word_658, _dict_standard_code_658 },
  { _dict_standard_word_659, _dict_standard_code_659 },
  { _dict_standard_word_660, _dict_standard_code_660 },
  { _dict_standard_word_661, _dict_standard_code_661 },
  { _dict_standard_word_662, _dict_standard_code_662 },
  { _dict_standard_word_663, _dict_standard_code_663 },
  { _dict_standard_word_664, _dict_standard_code_664 },
  { _dict_standard_word_665, _dict_standard_code_665 },
  { _dict_standard_word_666, _dict_standard_code_666 },
  { _dict_standard_word_667, _dict_standard_code_667 },
  { _dict_standard_word_668, _dict_standard_code_668 },
  { _dict_standard_word_669, _dict_standard_code_669 },
  { _dict_standard_word_670, _dict_standard_code_670 },
  { _dict_standard_word_671, _dict_standard_code_671 },
  { _dict_standard_word_672, _dict_standard_code_672 },
  { _dict_standard_word_673, _dict_standard_code_673 },
  { _dict_standard_word_674, _dict_standard_code_674 },
  { _dict_standard_word_675, _dict_standard_code_675 },
  { _dict_standard_word_676, _dict_standard_code_676 },
  { _dict_standard_word_677, _dict_standard_code_677 },
  { _dict_standard_word_678, _dict_standard_code_678 },
  { _dict_standard_word_679, _dict_standard_code_679 },
  { _dict_standard_word_680, _dict_standard_code_680 },
  { _dict_standard_word_681, _dict_standard_code_681 },
  { _dict_standard_word_682, _dict_standard_code_682 },
  { _dict_standard_word_683, _dict_standard_code_683 },
  { _dict_standard_word_684, _dict_standard_code_684 },
  { _dict_standard_word_685, _dict_standard_code_685 },
  { _dict_standard_word_686, _dict_standard_code_686 },
  { _dict_standard_word_687, _dict_standard_code_687 },
  { _dict_standard_word_688, _dict_standard_code_688 },
  { _dict_standard_word_689, _dict_standard_code_689 },
  { _dict_standard_word_690, _dict_standard_code_690 },
  { _dict_standard_word_691, _dict_standard_code_691 },
  { _dict_standard_word_692, _dict_standard_code_692 },
  { _dict_standard_word_693, _dict_standard_code_693 },
  { _dict_standard_word_694, _dict_standard_code_694 },
  { _dict_standard_word_695, _dict_standard_code_695 },
  { _dict_standard_word_696, _dict_standard_code_696 },
  { _dict_standard_word_697, _dict_standard_code_697 },
  { _dict_standard_word_698, _dict_standard_code_698 },
  { _dict_standard_word_699, _dict_standard_code_699 },
  { _dict_standard_word_700, _dict_standard_code_700 },
  { _dict_standard_word_701, _dict_standard_code_701 },
  { _dict_standard_word_702, _dict_standard_code_702 },
  { _dict_standard_word_703, _dict_standard_code_703 },
  { _dict_standard_word_704, _dict_standard_code_704 },
  { _dict_standard_word_705, _dict_standard_code_705 },
  { _dict_standard_word_706, _dict_standard_code_706 },
  { _dict_standard_word_707, _dict_standard_code_707 },
  { _dict_standard_word_708, _dict_standard_code_708 },
  { _dict_standard_word_709, _dict_standard_code_709 },
  { _dict_standard_word_710, _dict_standard_code_710 },
  { _dict_standard_word_711, _dict_standard_code_711 },
  { _dict_standard_word_712, _dict_standard_code_712 },
  { _dict_standard_word_713, _dict_standard_code_713 },
  { _dict_standard_word_714, _dict_standard_code_714 },
  { _dict_standard_word_715, _dict_standard_code_715 },
  { _dict_standard_word_716, _dict_standard_code_716 },
  { _dict_standard_word_717, _dict_standard_code_717 },
  { _dict_standard_word_718, _dict_standard_code_718 },
  { _dict_standard_word_719, _dict_standard_code_719 },
  { _dict_standard_word_720, _dict_standard_code_720 },
  { _dict_standard_word_721, _dict_standard_code_721 },
  { _dict_standard_word_722, _dict_standard_code_722 },
  { _dict_standard_word_723, _dict_standard_code_723 },
  { _dict_standard_word_724, _dict_standard_code_724 },
  { _dict_standard_word_725, _dict_standard_code_725 },
  { _dict_standard_word_726, _dict_standard_code_726 },
  { _dict_standard_word_727, _dict_standard_code_727 },
  { _dict_standard_word_728, _dict_standard_code_728 },
  { _dict_standard_word_729, _dict_standard_code_729 },
  { _dict_standard_word_730, _dict_standard_code_730 },
  { _dict_standard_word_731, _dict_standard_code_731 },
  { _dict_standard_word_732, _dict_standard_code_732 },
  { _dict_standard_word_733, _dict_standard_code_733 },
  { _dict_standard_word_734, _dict_standard_code_734 },
  { _dict_standard_word_735, _dict_standard_code_735 },
  { _dict_standard_word_736, _dict_standard_code_736 },
  { _dict_standard_word_737, _dict_standard_code_737 },
  { _dict_standard_word_738, _dict_standard_code_738 },
  { _dict_standard_word_739, _dict_standard_code_739 },
  { _dict_standard_word_740, _dict_standard_code_740 },
  { _dict_standard_word_741, _dict_standard_code_741 },
  { _dict_standard_word_742, _dict_standard_code_742 },
  { _dict_standard_word_743, _dict_standard_code_743 },
  { _dict_standard_word_744, _dict_standard_code_744 },
  { _dict_standard_word_745, _dict_standard_code_745 },
  { _dict_standard_word_746, _dict_standard_code_746 },
  { _dict_standard_word_747, _dict_standard_code_747 },
  { _dict_standard_word_748, _dict_standard_code_748 },
  { _dict_standard_word_749, _dict_standard_code_749 },
  { _dict_standard_word_750, _dict_standard_code_750 },
  { _dict_standard_word_751, _dict_standard_code_751 },
  { _dict_standard_word_752, _dict_standard_code_752 },
  { _dict_standard_word_753, _dict_standard_code_753 },
  { _dict_standard_word_754, _dict_standard_code_754 },
  { _dict_standard_word_755, _dict_standard_code_755 },
  { _dict_standard_word_756, _dict_standard_code_756 },
  { _dict_standard_word_757, _dict_standard_code_757 },
  { _dict_standard_word_758, _dict_standard_code_758 },
  { _dict_standard_word_759, _dict_standard_code_759 },
  { _dict_standard_word_760, _dict_standard_code_760 },
  { _dict_standard_word_761, _dict_standard_code_761 },
  { _dict_standard_word_762, _dict_standard_code_762 },
  { _dict_standard_word_763, _dict_standard_code_763 },
  { _dict_standard_word_764, _dict_standard_code_764 },
  { _dict_standard_word_765, _dict_standard_code_765 },
  { _dict_standard_word_766, _dict_standard_code_766 },
  { _dict_standard_word_767, _dict_standard_code_767 },
  { _dict_standard_word_768, _dict_standard_code_768 },
  { _dict_standard_word_769, _dict_standard_code_769 },
  { _dict_standard_word_770, _dict_standard_code_770 },
  { _dict_standard_word_771, _dict_standard_code_771 },
  { _dict_standard_word_772, _dict_standard_code_772 },
  { _dict_standard_word_773, _dict_standard_code_773 },
  { _dict_standard_word_774, _dict_standard_code_774 },
  { _dict_standard_word_775, _dict_standard_code_775 },
  { _dict_standard_word_776, _dict_standard_code_776 },
  { _dict_standard_word_777, _dict_standard_code_777 },
  { _dict_standard_word_778, _dict_standard_code_778 },
  { _dict_standard_word_779, _dict_standard_code_779 },
  { _dict_standard_word_780, _dict_standard_code_780 },
  { _dict_standard_word_781, _dict_standard_code_781 },
  { _dict_standard_word_782, _dict_standard_code_782 },
  { _dict_standard_word_783, _dict_standard_code_783 },
  { _dict_standard_word_784, _dict_standard_code_784 },
  { _dict_standard_word_785, _dict_standard_code_785 },
  { _dict_standard_word_786, _dict_standard_code_786 },
  { _dict_standard_word_787, _dict_standard_code_787 },
  { _dict_standard_word_788, _dict_standard_code_788 },
  { _dict_standard_word_789, _dict_standard_code_789 },
  { _dict_standard_word_790, _dict_standard_code_790 },
  { _dict_standard_word_791, _dict_standard_code_791 },
  { _dict_standard_word_792, _dict_standard_code_792 },
  { _dict_standard_word_793, _dict_standard_code_793 },
  { _dict_standard_word_794, _dict_standard_code_794 },
  { _dict_standard_word_795, _dict_standard_code_795 },
  { _dict_standard_word_796, _dict_standard_code_796 },
  { _dict_standard_word_797, _dict_standard_code_797 },
  { _dict_standard_word_798, _dict_standard_code_798 },
  { _dict_standard_word_799, _dict_standard_code_799 },
  { _dict_standard_word_800, _dict_standard_code_800 },
  { _dict_standard_word_801, _dict_standard_code_801 },
  { _dict_standard_word_802, _dict_standard_code_802 },
  { _dict_standard_word_803, _dict_standard_code_803 },
  { _dict_standard_word_804, _dict_standard_code_804 },
  { _dict_standard_word_805, _dict_standard_code_805 },
  { _dict_standard_word_806, _dict_standard_code_806 },
  { _dict_standard_word_807, _dict_standard_code_807 },
  { _dict_standard_word_808, _dict_standard_code_808 },
  { _dict_standard_word_809, _dict_standard_code_809 },
  { _dict_standard_word_810, _dict_standard_code_810 },
  { _dict_standard_word_811, _dict_standard_code_811 },
  { _dict_standard_word_812, _dict_standard_code_812 },
  { _dict_standard_word_813, _dict_standard_code_813 },
  { _dict_standard_word_814, _dict_standard_code_814 },
  { _dict_standard_word_815, _dict_standard_code_815 },
  { _dict_standard_word_816, _dict_standard_code_816 },
  { _dict_standard_word_817, _dict_standard_code_817 },
  { _dict_standard_word_818, _dict_standard_code_818 },
  { _dict_standard_word_819, _dict_standard_code_819 },
  { _dict_standard_word_820, _dict_standard_code_820 },
  { _dict_standard_word_821, _dict_standard_code_821 },
  { _dict_standard_word_822, _dict_standard_code_822 },
  { _dict_standard_word_823, _dict_standard_code_823 },
  { _dict_standard_word_824, _dict_standard_code_824 },
  { _dict_standard_word_825, _dict_standard_code_825 },
  { _dict_standard_word_826, _dict_standard_code_826 },
  { _dict_standard_word_827, _dict_standard_code_827 },
  { _dict_standard_word_828, _dict_standard_code_828 },
  { _dict_standard_word_829, _dict_standard_code_829 },
  { _dict_standard_word_830, _dict_standard_code_830 },
  { _dict_standard_word_831, _dict_standard_code_831 },
  { _dict_standard_word_832, _dict_standard_code_832 },
  { _dict_standard_word_833, _dict_standard_code_833 },
  { _dict_standard_word_834, _dict_standard_code_834 },
  { _dict_standard_word_835, _dict_standard_code_835 },
  { _dict_standard_word_836, _dict_standard_code_836 },
  { _dict_standard_word_837, _dict_standard_code_837 },
  { _dict_standard_word_838, _dict_standard_code_838 },
  { _dict_standard_word_839, _dict_standard_code_839 },
  { _dict_standard_word_840, _dict_standard_code_840 },
  { _dict_standard_word_841, _dict_standard_code_841 },
  { _dict_standard_word_842, _dict_standard_code_842 },
  { _dict_standard_word_843, _dict_standard_code_843 },
  { _dict_standard_word_844, _dict_standard_code_844 },
  { _dict_standard_word_845, _dict_standard_code_845 },
  { _dict_standard_word_846, _dict_standard_code_846 },
  { _dict_standard_word_847, _dict_standard_code_847 },
  { _dict_standard_word_848, _dict_standard_code_848 },
  { _dict_standard_word_849, _dict_standard_code_849 },
  { _dict_standard_word_850, _dict_standard_code_850 },
  { _dict_standard_word_851, _dict_standard_code_851 },
  { _dict_standard_word_852, _dict_standard_code_852 },
  { _dict_standard_word_853, _dict_standard_code_853 },
  { _dict_standard_word_854, _dict_standard_code_854 },
  { _dict_standard_word_855, _dict_standard_code_855 },
  { _dict_standard_word_856, _dict_standard_code_856 },
  { _dict_standard_word_857, _dict_standard_code_857 },
  { _dict_standard_word_858, _dict_standard_code_858 },
  { _dict_standard_word_859, _dict_standard_code_859 },
  { _dict_standard_word_860, _dict_standard_code_860 },
  { _dict_standard_word_861, _dict_standard_code_861 },
  { _dict_standard_word_862, _dict_standard_code_862 },
  { _dict_standard_word_863, _dict_standard_code_863 },
  { _dict_standard_word_864, _dict_standard_code_864 },
  { _dict_standard_word_865, _dict_standard_code_865 },
  { _dict_standard_word_866, _dict_standard_code_866 },
  { _dict_standard_word_867, _dict_standard_code_867 },
  { _dict_standard_word_868, _dict_standard_code_868 },
  { _dict_standard_word_869, _dict_standard_code_869 },
  { _dict_standard_word_870, _dict_standard_code_870 },
  { _dict_standard_word_871, _dict_standard_code_871 },
  { _dict_standard_word_872, _dict_standard_code_872 },
  { _dict_standard_word_873, _dict_standard_code_873 },
  { _dict_standard_word_874, _dict_standard_code_874 },
  { _dict_standard_word_875, _dict_standard_code_875 },
  { _dict_standard_word_876, _dict_standard_code_876 },
  { _dict_standard_word_877, _dict_standard_code_877 },
  { _dict_standard_word_878, _dict_standard_code_878 },
  { _dict_standard_word_879, _dict_standard_code_879 },
  { _dict_standard_word_880, _dict_standard_code_880 },
  { _dict_standard_word_881, _dict_standard_code_881 },
  { _dict_standard_word_882, _dict_standard_code_882 },
  { _dict_standard_word_883, _dict_standard_code_883 },
  { _dict_standard_word_884, _dict_standard_code_884 },
  { _dict_standard_word_885, _dict_standard_code_885 },
  { _dict_standard_word_886, _dict_standard_code_886 },
  { _dict_standard_word_887, _dict_standard_code_887 },
  { _dict_standard_word_888, _dict_standard_code_888 },
  { _dict_standard_word_889, _dict_standard_code_889 },
  { _dict_standard_word_890, _dict_standard_code_890 },
  { _dict_standard_word_891, _dict_standard_code_891 },
  { _dict_standard_word_892, _dict_standard_code_892 },
  { _dict_standard_word_893, _dict_standard_code_893 },
  { _dict_standard_word_894, _dict_standard_code_894 },
  { _dict_standard_word_895, _dict_standard_code_895 },
  { _dict_standard_word_896, _dict_standard_code_896 },
  { _dict_standard_word_897, _dict_standard_code_897 },
  { _dict_standard_word_898, _dict_standard_code_898 },
  { _dict_standard_word_899, _dict_standard_code_899 },
  { _dict_standard_word_900, _dict_standard_code_900 },
  { _dict_standard_word_901, _dict_standard_code_901 },
  { _dict_standard_word_902, _dict_standard_code_902 },
  { _dict_standard_word_903, _dict_standard_code_903 },
  { _dict_standard_word_904, _dict_standard_code_904 },
  { _dict_standard_word_905, _dict_standard_code_905 },
  { _dict_standard_word_906, _dict_standard_code_906 },
  { _dict_standard_word_907, _dict_standard_code_907 },
  { _dict_standard_word_908, _dict_standard_code_908 },
  { _dict_standard_word_909, _dict_standard_code_909 },
  { _dict_standard_word_910, _dict_standard_code_910 },
  { _dict_standard_word_911, _dict_standard_code_911 },
  { _dict_standard_word_912, _dict_standard_code_912 },
  { _dict_standard_word_913, _dict_standard_code_913 },
  { _dict_standard_word_914, _dict_standard_code_914 },
  { _dict_standard_word_915, _dict_standard_code_915 },
  { _dict_standard_word_916, _dict_standard_code_916 },
  { _dict_standard_word_917, _dict_standard_code_917 },
  { _dict_standard_word_918, _dict_standard_code_918 },
  { _dict_standard_word_919, _dict_standard_code_919 },
  { _dict_standard_word_920, _dict_standard_code_920 },
  { _dict_standard_word_921, _dict_standard_code_921 },
  { _dict_standard_word_922, _dict_standard_code_922 },
  { _dict_standard_word_923, _dict_standard_code_923 },
  { _dict_standard_word_924, _dict_standard_code_924 },
  { _dict_standard_word_925, _dict_standard_code_925 },
  { _dict_standard_word_926, _dict_standard_code_926 },
  { _dict_standard_word_927, _dict_standard_code_927 },
  { _dict_standard_word_928, _dict_standard_code_928 },
  { _dict_standard_word_929, _dict_standard_code_929 },
  { _dict_standard_word_930, _dict_standard_code_930 },
  { _dict_standard_word_931, _dict_standard_code_931 },
  { _dict_standard_word_932, _dict_standard_code_932 },
  { _dict_standard_word_933, _dict_standard_code_933 },
  { _dict_standard_word_934, _dict_standard_code_934 },
  { _dict_standard_word_935, _dict_standard_code_935 },
  { _dict_standard_word_936, _dict_standard_code_936 },
  { _dict_standard_word_937, _dict_standard_code_937 },
  { _dict_standard_word_938, _dict_standard_code_938 },
  { _dict_standard_word_939, _dict_standard_code_939 },
  { _dict_standard_word_940, _dict_standard_code_940 },
  { _dict_standard_word_941, _dict_standard_code_941 },
  { _dict_standard_word_942, _dict_standard_code_942 },
  { _dict_standard_word_943, _dict_standard_code_943 },
  { _dict_standard_word_944, _dict_standard_code_944 },
  { _dict_standard_word_945, _dict_standard_code_945 },
  { _dict_standard_word_946, _dict_standard_code_946 },
  { _dict_standard_word_947, _dict_standard_code_947 },
  { _dict_standard_word_948, _dict_standard_code_948 },
  { _dict_standard_word_949, _dict_standard_code_949 },
  { _dict_standard_word_950, _dict_standard_code_950 },
  { _dict_standard_word_951, _dict_standard_code_951 },
  { _dict_standard_word_952, _dict_standard_code_952 },
  { _dict_standard_word_953, _dict_standard_code_953 },
  { _dict_standard_word_954, _dict_standard_code_954 },
  { _dict_standard_word_955, _dict_standard_code_955 },
  { _dict_standard_word_956, _dict_standard_code_956 },
  { _dict_standard_word_957, _dict_standard_code_957 },
  { _dict_standard_word_958, _dict_standard_code_958 },
  { _dict_standard_word_959, _dict_standard_code_959 },
  { _dict_standard_word_960, _dict_standard_code_960 },
  { _dict_standard_word_961, _dict_standard_code_961 },
  { _dict_standard_word_962, _dict_standard_code_962 },
  { _dict_standard_word_963, _dict_standard_code_963 },
  { _dict_standard_word_964, _dict_standard_code_964 },
  { _dict_standard_word_965, _dict_standard_code_965 },
  { _dict_standard_word_966, _dict_standard_code_966 },
  { _dict_standard_word_967, _dict_standard_code_967 },
  { _dict_standard_word_968, _dict_standard_code_968 },
  { _dict_standard_word_969, _dict_standard_code_969 },
  { _dict_standard_word_970, _dict_standard_code_970 },
  { _dict_standard_word_971, _dict_standard_code_971 },
  { _dict_standard_word_972, _dict_standard_code_972 },
  { _dict_standard_word_973, _dict_standard_code_973 },
  { _dict_standard_word_974, _dict_standard_code_974 },
  { _dict_standard_word_975, _dict_standard_code_975 },
  { _dict_standard_word_976, _dict_standard_code_976 },
  { _dict_standard_word_977, _dict_standard_code_977 },
  { _dict_standard_word_978, _dict_standard_code_978 },
  { _dict_standard_word_979, _dict_standard_code_979 },
  { _dict_standard_word_980, _dict_standard_code_980 },
  { _dict_standard_word_981, _dict_standard_code_981 },
  { _dict_standard_word_982, _dict_standard_code_982 },
  { _dict_standard_word_983, _dict_standard_code_983 },
  { _dict_standard_word_984, _dict_standard_code_984 },
  { _dict_standard_word_985, _dict_standard_code_985 },
  { _dict_standard_word_986, _dict_standard_code_986 },
  { _dict_standard_word_987, _dict_standard_code_987 },
  { _dict_standard_word_988, _dict_standard_code_988 },
  { _dict_standard_word_989, _dict_standard_code_989 },
  { _dict_standard_word_990, _dict_standard_code_990 },
  { _dict_standard_word_991, _dict_standard_code_991 },
  { _dict_standard_word_992, _dict_standard_code_992 },
  { _dict_standard_word_993, _dict_standard_code_993 },
  { _dict_standard_word_994, _dict_standard_code_994 },
  { _dict_standard_word_995, _dict_standard_code_995 },
  { _dict_standard_word_996, _dict_standard_code_996 },
  { _dict_standard_word_997, _dict_standard_code_997 },
  { _dict_standard_word_998, _dict_standard_code_998 },
  { _dict_standard_word_999, _dict_standard_code_999 },
  { _dict_standard_word_1000, _dict_standard_code_1000 },
  { _dict_standard_word_1001, _dict_standard_code_1001 },
  { _dict_standard_word_1002, _dict_standard_code_1002 },
  { _dict_standard_word_1003, _dict_standard_code_1003 },
  { _dict_standard_word_1004, _dict_standard_code_1004 },
  { _dict_standard_word_1005, _dict_standard_code_1005 },
  { _dict_standard_word_1006, _dict_standard_code_1006 },
  { _dict_standard_word_1007, _dict_standard_code_1007 },
  { _dict_standard_word_1008, _dict_standard_code_1008 },
  { _dict_standard_word_1009, _dict_standard_code_1009 },
  { _dict_standard_word_1010, _dict_standard_code_1010 },
  { _dict_standard_word_1011, _dict_standard_code_1011 },
  { _dict_standard_word_1012, _dict_standard_code_1012 },
  { _dict_standard_word_1013, _dict_standard_code_1013 },
  { _dict_standard_word_1014, _dict_standard_code_1014 },
  { _dict_standard_word_1015, _dict_standard_code_1015 },
  { _dict_standard_word_1016, _dict_standard_code_1016 },
  { _dict_standard_word_1017, _dict_standard_code_1017 },
  { _dict_standard_word_1018, _dict_standard_code_1018 },
  { _dict_standard_word_1019, _dict_standard_code_1019 },
  { _dict_standard_word_1020, _dict_standard_code_1020 },
  { _dict_standard_word_1021, _dict_standard_code_1021 },
  { _dict_standard_word_1022, _dict_standard_code_1022 },
  { _dict_standard_word_1023, _dict_standard_code_1023 },
  { _dict_standard_word_1024, _dict_standard_code_1024 },
  { _dict_standard_word_1025, _dict_standard_code_1025 },
  { _dict_standard_word_1026, _dict_standard_code_1026 },
  { _dict_standard_word_1027, _dict_standard_code_1027 },
  { _dict_standard_word_1028, _dict_standard_code_1028 },
  { _dict_standard_word_1029, _dict_standard_code_1029 },
  { _dict_standard_word_1030, _dict_standard_code_1030 },
  { _dict_standard_word_1031, _dict_standard_code_1031 },
  { _dict_standard_word_1032, _dict_standard_code_1032 },
  { _dict_standard_word_1033, _dict_standard_code_1033 },
  { _dict_standard_word_1034, _dict_standard_code_1034 },
  { _dict_standard_word_1035, _dict_standard_code_1035 },
  { _dict_standard_word_1036, _dict_standard_code_1036 },
  { _dict_standard_word_1037, _dict_standard_code_1037 },
  { _dict_standard_word_1038, _dict_standard_code_1038 },
  { _dict_standard_word_1039, _dict_standard_code_1039 },
  { _dict_standard_word_1040, _dict_standard_code_1040 },
  { _dict_standard_word_1041, _dict_standard_code_1041 },
  { _dict_standard_word_1042, _dict_standard_code_1042 },
  { _dict_standard_word_1043, _dict_standard_code_1043 },
  { _dict_standard_word_1044, _dict_standard_code_1044 },
  { _dict_standard_word_1045, _dict_standard_code_1045 },
  { _dict_standard_word_1046, _dict_standard_code_1046 },
  { _dict_standard_word_1047, _dict_standard_code_1047 },
  { _dict_standard_word_1048, _dict_standard_code_1048 },
  { _dict_standard_word_1049, _dict_standard_code_1049 },
  { _dict_standard_word_1050, _dict_standard_code_1050 },
  { _dict_standard_word_1051, _dict_standard_code_1051 },
  { _dict_standard_word_1052, _dict_standard_code_1052 },
  { _dict_standard_word_1053, _dict_standard_code_1053 },
  { _dict_standard_word_1054, _dict_standard_code_1054 },
  { _dict_standard_word_1055, _dict_standard_code_1055 },
  { _dict_standard_word_1056, _dict_standard_code_1056 },
  { _dict_standard_word_1057, _dict_standard_code_1057 },
  { _dict_standard_word_1058, _dict_standard_code_1058 },
  { _dict_standard_word_1059, _dict_standard_code_1059 },
  { _dict_standard_word_1060, _dict_standard_code_1060 },
  { _dict_standard_word_1061, _dict_standard_code_1061 },
  { _dict_standard_word_1062, _dict_standard_code_1062 },
  { _dict_standard_word_1063, _dict_standard_code_1063 },
  { _dict_standard_word_1064, _dict_standard_code_1064 },
  { _dict_standard_word_1065, _dict_standard_code_1065 },
  { _dict_standard_word_1066, _dict_standard_code_1066 },
  { _dict_standard_word_1067, _dict_standard_code_1067 },
  { _dict_standard_word_1068, _dict_standard_code_1068 },
  { _dict_standard_word_1069, _dict_standard_code_1069 },
  { _dict_standard_word_1070, _dict_standard_code_1070 },
  { _dict_standard_word_1071, _dict_standard_code_1071 },
  { _dict_standard_word_1072, _dict_standard_code_1072 },
  { _dict_standard_word_1073, _dict_standard_code_1073 },
  { _dict_standard_word_1074, _dict_standard_code_1074 },
  { _dict_standard_word_1075, _dict_standard_code_1075 },
  { _dict_standard_word_1076, _dict_standard_code_1076 },
  { _dict_standard_word_1077, _dict_standard_code_1077 },
  { _dict_standard_word_1078, _dict_standard_code_1078 },
  { _dict_standard_word_1079, _dict_standard_code_1079 },
  { _dict_standard_word_1080, _dict_standard_code_1080 },
  { _dict_standard_word_1081, _dict_standard_code_1081 },
  { _dict_standard_word_1082, _dict_standard_code_1082 },
  { _dict_standard_word_1083, _dict_standard_code_1083 },
  { _dict_standard_word_1084, _dict_standard_code_1084 },
  { _dict_standard_word_1085, _dict_standard_code_1085 },
  { _dict_standard_word_1086, _dict_standard_code_1086 },
  { _dict_standard_word_1087, _dict_standard_code_1087 },
  { _dict_standard_word_1088, _dict_standard_code_1088 },
  { _dict_standard_word_1089, _dict_standard_code_1089 },
  { _dict_standard_word_1090, _dict_standard_code_1090 },
  { _dict_standard_word_1091, _dict_standard_code_1091 },
  { _dict_standard_word_1092, _dict_standard_code_1092 },
  { _dict_standard_word_1093, _dict_standard_code_1093 },
  { _dict_standard_word_1094, _dict_standard_code_1094 },
  { _dict_standard_word_1095, _dict_standard_code_1095 },
  { _dict_standard_word_1096, _dict_standard_code_1096 },
  { _dict_standard_word_1097, _dict_standard_code_1097 },
  { _dict_standard_word_1098, _dict_standard_code_1098 },
  { _dict_standard_word_1099, _dict_standard_code_1099 },
  { _dict_standard_word_1100, _dict_standard_code_1100 },
  { _dict_standard_word_1101, _dict_standard_code_1101 },
  { _dict_standard_word_1102, _dict_standard_code_1102 },
  { _dict_standard_word_1103, _dict_standard_code_1103 },
  { _dict_standard_word_1104, _dict_standard_code_1104 },
  { _dict_standard_word_1105, _dict_standard_code_1105 },
  { _dict_standard_word_1106, _dict_standard_code_1106 },
  { _dict_standard_word_1107, _dict_standard_code_1107 },
  { _dict_standard_word_1108, _dict_standard_code_1108 },
  { _dict_standard_word_1109, _dict_standard_code_1109 },
  { _dict_standard_word_1110, _dict_standard_code_1110 },
  { _dict_standard_word_1111, _dict_standard_code_1111 },
  { _dict_standard_word_1112, _dict_standard_code_1112 },
  { _dict_standard_word_1113, _dict_standard_code_1113 },
  { _dict_standard_word_1114, _dict_standard_code_1114 },
  { _dict_standard_word_1115, _dict_standard_code_1115 },
  { _dict_standard_word_1116, _dict_standard_code_1116 },
  { _dict_standard_word_1117, _dict_standard_code_1117 },
  { _dict_standard_word_1118, _dict_standard_code_1118 },
  { _dict_standard_word_1119, _dict_standard_code_1119 },
  { _dict_standard_word_1120, _dict_standard_code_1120 },
  { _dict_standard_word_1121, _dict_standard_code_1121 },
  { _dict_standard_word_1122, _dict_standard_code_1122 },
  { _dict_standard_word_1123, _dict_standard_code_1123 },
  { _dict_standard_word_1124, _dict_standard_code_1124 },
  { _dict_standard_word_1125, _dict_standard_code_1125 },
  { _dict_standard_word_1126, _dict_standard_code_1126 },
  { _dict_standard_word_1127, _dict_standard_code_1127 },
  { _dict_standard_word_1128, _dict_standard_code_1128 },
  { _dict_standard_word_1129, _dict_standard_code_1129 },
  { _dict_standard_word_1130, _dict_standard_code_1130 },
  { _dict_standard_word_1131, _dict_standard_code_1131 },
  { _dict_standard_word_1132, _dict_standard_code_1132 },
  { _dict_standard_word_1133, _dict_standard_code_1133 },
  { _dict_standard_word_1134, _dict_standard_code_1134 },
  { _dict_standard_word_1135, _dict_standard_code_1135 },
  { _dict_standard_word_1136, _dict_standard_code_1136 },
  { _dict_standard_word_1137, _dict_standard_code_1137 },
  { _dict_standard_word_1138, _dict_standard_code_1138 },
  { _dict_standard_word_1139, _dict_standard_code_1139 },
  { _dict_standard_word_1140, _dict_standard_code_1140 },
  { _dict_standard_word_1141, _dict_standard_code_1141 },
  { _dict_standard_word_1142, _dict_standard_code_1142 },
  { _dict_standard_word_1143, _dict_standard_code_1143 },
  { _dict_standard_word_1144, _dict_standard_code_1144 },
  { _dict_standard_word_1145, _dict_standard_code_1145 },
  { _dict_standard_word_1146, _dict_standard_code_1146 },
  { _dict_standard_word_1147, _dict_standard_code_1147 },
  { _dict_standard_word_1148, _dict_standard_code_1148 },
  { _dict_standard_word_1149, _dict_standard_code_1149 },
  { _dict_standard_word_1150, _dict_standard_code_1150 },
  { _dict_standard_word_1151, _dict_standard_code_1151 },
  { _dict_standard_word_1152, _dict_standard_code_1152 },
  { _dict_standard_word_1153, _dict_standard_code_1153 },
  { _dict_standard_word_1154, _dict_standard_code_1154 },
  { _dict_standard_word_1155, _dict_standard_code_1155 },
  { _dict_standard_word_1156, _dict_standard_code_1156 },
  { _dict_standard_word_1157, _dict_standard_code_1157 },
  { _dict_standard_word_1158, _dict_standard_code_1158 },
  { _dict_standard_word_1159, _dict_standard_code_1159 },
  { _dict_standard_word_1160, _dict_standard_code_1160 },
  { _dict_standard_word_1161, _dict_standard_code_1161 },
  { _dict_standard_word_1162, _dict_standard_code_1162 },
  { _dict_standard_word_1163, _dict_standard_code_1163 },
  { _dict_standard_word_1164, _dict_standard_code_1164 },
  { _dict_standard_word_1165, _dict_standard_code_1165 },
  { _dict_standard_word_1166, _dict_standard_code_1166 },
  { _dict_standard_word_1167, _dict_standard_code_1167 },
  { _dict_standard_word_1168, _dict_standard_code_1168 },
  { _dict_standard_word_1169, _dict_standard_code_1169 },
  { _dict_standard_word_1170, _dict_standard_code_1170 },
  { _dict_standard_word_1171, _dict_standard_code_1171 },
  { _dict_standard_word_1172, _dict_standard_code_1172 },
  { _dict_standard_word_1173, _dict_standard_code_1173 },
  { _dict_standard_word_1174, _dict_standard_code_1174 },
  { _dict_standard_word_1175, _dict_standard_code_1175 },
  { _dict_standard_word_1176, _dict_standard_code_1176 },
  { _dict_standard_word_1177, _dict_standard_code_1177 },
  { _dict_standard_word_1178, _dict_standard_code_1178 },
  { _dict_standard_word_1179, _dict_standard_code_1179 },
  { _dict_standard_word_1180, _dict_standard_code_1180 },
  { _dict_standard_word_1181, _dict_standard_code_1181 },
  { _dict_standard_word_1182, _dict_standard_code_1182 },
  { _dict_standard_word_1183, _dict_standard_code_1183 },
  { _dict_standard_word_1184, _dict_standard_code_1184 },
  { _dict_standard_word_1185, _dict_standard_code_1185 },
  { _dict_standard_word_1186, _dict_standard_code_1186 },
  { _dict_standard_word_1187, _dict_standard_code_1187 },
  { _dict_standard_word_1188, _dict_standard_code_1188 },
  { _dict_standard_word_1189, _dict_standard_code_1189 },
  { _dict_standard_word_1190, _dict_standard_code_1190 },
  { _dict_standard_word_1191, _dict_standard_code_1191 },
  { _dict_standard_word_1192, _dict_standard_code_1192 },
  { _dict_standard_word_1193, _dict_standard_code_1193 },
  { _dict_standard_word_1194, _dict_standard_code_1194 },
  { _dict_standard_word_1195, _dict_standard_code_1195 },
  { _dict_standard_word_1196, _dict_standard_code_1196 },
  { _dict_standard_word_1197, _dict_standard_code_1197 },
  { _dict_standard_word_1198, _dict_standard_code_1198 },
  { _dict_standard_word_1199, _dict_standard_code_1199 },
  { _dict_standard_word_1200, _dict_standard_code_1200 },
  { _dict_standard_word_1201, _dict_standard_code_1201 },
  { _dict_standard_word_1202, _dict_standard_code_1202 },
  { _dict_standard_word_1203, _dict_standard_code_1203 },
  { _dict_standard_word_1204, _dict_standard_code_1204 },
  { _dict_standard_word_1205, _dict_standard_code_1205 },
  { _dict_standard_word_1206, _dict_standard_code_1206 },
  { _dict_standard_word_1207, _dict_standard_code_1207 },
  { _dict_standard_word_1208, _dict_standard_code_1208 },
  { _dict_standard_word_1209, _dict_standard_code_1209 },
  { _dict_standard_word_1210, _dict_standard_code_1210 },
  { _dict_standard_word_1211, _dict_standard_code_1211 },
  { _dict_standard_word_1212, _dict_standard_code_1212 },
  { _dict_standard_word_1213, _dict_standard_code_1213 },
  { _dict_standard_word_1214, _dict_standard_code_1214 },
  { _dict_standard_word_1215, _dict_standard_code_1215 },
  { _dict_standard_word_1216, _dict_standard_code_1216 },
  { _dict_standard_word_1217, _dict_standard_code_1217 },
  { _dict_standard_word_1218, _dict_standard_code_1218 },
  { _dict_standard_word_1219, _dict_standard_code_1219 },
  { _dict_standard_word_1220, _dict_standard_code_1220 },
  { _dict_standard_word_1221, _dict_standard_code_1221 },
  { _dict_standard_word_1222, _dict_standard_code_1222 },
  { _dict_standard_word_1223, _dict_standard_code_1223 },
  { _dict_standard_word_1224, _dict_standard_code_1224 },
  { _dict_standard_word_1225, _dict_standard_code_1225 },
  { _dict_standard_word_1226, _dict_standard_code_1226 },
  { _dict_standard_word_1227, _dict_standard_code_1227 },
  { _dict_standard_word_1228, _dict_standard_code_1228 },
  { _dict_standard_word_1229, _dict_standard_code_1229 },
  { _dict_standard_word_1230, _dict_standard_code_1230 },
  { _dict_standard_word_1231, _dict_standard_code_1231 },
  { _dict_standard_word_1232, _dict_standard_code_1232 },
  { _dict_standard_word_1233, _dict_standard_code_1233 },
  { _dict_standard_word_1234, _dict_standard_code_1234 },
  { _dict_standard_word_1235, _dict_standard_code_1235 },
  { _dict_standard_word_1236, _dict_standard_code_1236 },
  { _dict_standard_word_1237, _dict_standard_code_1237 },
  { _dict_standard_word_1238, _dict_standard_code_1238 },
  { _dict_standard_word_1239, _dict_standard_code_1239 },
  { _dict_standard_word_1240, _dict_standard_code_1240 },
  { _dict_standard_word_1241, _dict_standard_code_1241 },
  { _dict_standard_word_1242, _dict_standard_code_1242 },
  { _dict_standard_word_1243, _dict_standard_code_1243 },
  { _dict_standard_word_1244, _dict_standard_code_1244 },
  { _dict_standard_word_1245, _dict_standard_code_1245 },
  { _dict_standard_word_1246, _dict_standard_code_1246 },
  { _dict_standard_word_1247, _dict_standard_code_1247 },
  { _dict_standard_word_1248, _dict_standard_code_1248 },
  { _dict_standard_word_1249, _dict_standard_code_1249 },
  { _dict_standard_word_1250, _dict_standard_code_1250 },
  { _dict_standard_word_1251, _dict_standard_code_1251 },
  { _dict_standard_word_1252, _dict_standard_code_1252 },
  { _dict_standard_word_1253, _dict_standard_code_1253 },
  { _dict_standard_word_1254, _dict_standard_code_1254 },
  { _dict_standard_word_1255, _dict_standard_code_1255 },
  { _dict_standard_word_1256, _dict_standard_code_1256 },
  { _dict_standard_word_1257, _dict_standard_code_1257 },
  { _dict_standard_word_1258, _dict_standard_code_1258 },
  { _dict_standard_word_1259, _dict_standard_code_1259 },
  { _dict_standard_word_1260, _dict_standard_code_1260 },
  { _dict_standard_word_1261, _dict_standard_code_1261 },
  { _dict_standard_word_1262, _dict_standard_code_1262 },
  { _dict_standard_word_1263, _dict_standard_code_1263 },
  { _dict_standard_word_1264, _dict_standard_code_1264 },
  { _dict_standard_word_1265, _dict_standard_code_1265 },
  { _dict_standard_word_1266, _dict_standard_code_1266 },
  { _dict_standard_word_1267, _dict_standard_code_1267 },
  { _dict_standard_word_1268, _dict_standard_code_1268 },
  { _dict_standard_word_1269, _dict_standard_code_1269 },
  { _dict_standard_word_1270, _dict_standard_code_1270 },
  { _dict_standard_word_1271, _dict_standard_code_1271 },
  { _dict_standard_word_1272, _dict_standard_code_1272 },
  { _dict_standard_word_1273, _dict_standard_code_1273 },
  { _dict_standard_word_1274, _dict_standard_code_1274 },
  { _dict_standard_word_1275, _dict_standard_code_1275 },
  { _dict_standard_word_1276, _dict_standard_code_1276 },
  { _dict_standard_word_1277, _dict_standard_code_1277 },
  { _dict_standard_word_1278, _dict_standard_code_1278 },
  { _dict_standard_word_1279, _dict_standard_code_1279 },
  { _dict_standard_word_1280, _dict_standard_code_1280 },
  { _dict_standard_word_1281, _dict_standard_code_1281 },
  { _dict_standard_word_1282, _dict_standard_code_1282 },
  { _dict_standard_word_1283, _dict_standard_code_1283 },
  { _dict_standard_word_1284, _dict_standard_code_1284 },
  { _dict_standard_word_1285, _dict_standard_code_1285 },
  { _dict_standard_word_1286, _dict_standard_code_1286 },
  { _dict_standard_word_1287, _dict_standard_code_1287 },
  { _dict_standard_word_1288, _dict_standard_code_1288 },
  { _dict_standard_word_1289, _dict_standard_code_1289 },
  { _dict_standard_word_1290, _dict_standard_code_1290 },
  { _dict_standard_word_1291, _dict_standard_code_1291 },
  { _dict_standard_word_1292, _dict_standard_code_1292 },
  { _dict_standard_word_1293, _dict_standard_code_1293 },
  { _dict_standard_word_1294, _dict_standard_code_1294 },
  { _dict_standard_word_1295, _dict_standard_code_1295 },
  { _dict_standard_word_1296, _dict_standard_code_1296 },
  { _dict_standard_word_1297, _dict_standard_code_1297 },
  { _dict_standard_word_1298, _dict_standard_code_1298 },
  { _dict_standard_word_1299, _dict_standard_code_1299 },
  { _dict_standard_word_1300, _dict_standard_code_1300 },
  { _dict_standard_word_1301, _dict_standard_code_1301 },
  { _dict_standard_word_1302, _dict_standard_code_1302 },
  { _dict_standard_word_1303, _dict_standard_code_1303 },
  { _dict_standard_word_1304, _dict_standard_code_1304 },
  { _dict_standard_word_1305, _dict_standard_code_1305 },
  { _dict_standard_word_1306, _dict_standard_code_1306 },
  { _dict_standard_word_1307, _dict_standard_code_1307 },
  { _dict_standard_word_1308, _dict_standard_code_1308 },
  { _dict_standard_word_1309, _dict_standard_code_1309 },
  { _dict_standard_word_1310, _dict_standard_code_1310 },
  { _dict_standard_word_1311, _dict_standard_code_1311 },
  { _dict_standard_word_1312, _dict_standard_code_1312 },
  { _dict_standard_word_1313, _dict_standard_code_1313 },
  { _dict_standard_word_1314, _dict_standard_code_1314 },
  { _dict_standard_word_1315, _dict_standard_code_1315 },
  { _dict_standard_word_1316, _dict_standard_code_1316 },
  { _dict_standard_word_1317, _dict_standard_code_1317 },
  { _dict_standard_word_1318, _dict_standard_code_1318 },
  { _dict_standard_word_1319, _dict_standard_code_1319 },
  { _dict_standard_word_1320, _dict_standard_code_1320 },
  { _dict_standard_word_1321, _dict_standard_code_1321 },
  { _dict_standard_word_1322, _dict_standard_code_1322 },
  { _dict_standard_word_1323, _dict_standard_code_1323 },
  { _dict_standard_word_1324, _dict_standard_code_1324 },
  { _dict_standard_word_1325, _dict_standard_code_1325 },
  { _dict_standard_word_1326, _dict_standard_code_1326 },
  { _dict_standard_word_1327, _dict_standard_code_1327 },
  { _dict_standard_word_1328, _dict_standard_code_1328 },
  { _dict_standard_word_1329, _dict_standard_code_1329 },
  { _dict_standard_word_1330, _dict_standard_code_1330 },
  { _dict_standard_word_1331, _dict_standard_code_1331 },
  { _dict_standard_word_1332, _dict_standard_code_1332 },
  { _dict_standard_word_1333, _dict_standard_code_1333 },
  { _dict_standard_word_1334, _dict_standard_code_1334 },
  { _dict_standard_word_1335, _dict_standard_code_1335 },
  { _dict_standard_word_1336, _dict_standard_code_1336 },
  { _dict_standard_word_1337, _dict_standard_code_1337 },
  { _dict_standard_word_1338, _dict_standard_code_1338 },
  { _dict_standard_word_1339, _dict_standard_code_1339 },
  { _dict_standard_word_1340, _dict_standard_code_1340 },
  { _dict_standard_word_1341, _dict_standard_code_1341 },
  { _dict_standard_word_1342, _dict_standard_code_1342 },
  { _dict_standard_word_1343, _dict_standard_code_1343 },
  { _dict_standard_word_1344, _dict_standard_code_1344 },
  { _dict_standard_word_1345, _dict_standard_code_1345 },
  { _dict_standard_word_1346, _dict_standard_code_1346 },
  { _dict_standard_word_1347, _dict_standard_code_1347 },
  { _dict_standard_word_1348, _dict_standard_code_1348 },
  { _dict_standard_word_1349, _dict_standard_code_1349 },
  { _dict_standard_word_1350, _dict_standard_code_1350 },
  { _dict_standard_word_1351, _dict_standard_code_1351 },
  { _dict_standard_word_1352, _dict_standard_code_1352 },
  { _dict_standard_word_1353, _dict_standard_code_1353 },
  { _dict_standard_word_1354, _dict_standard_code_1354 },
  { _dict_standard_word_1355, _dict_standard_code_1355 },
  { _dict_standard_word_1356, _dict_standard_code_1356 },
  { _dict_standard_word_1357, _dict_standard_code_1357 },
  { _dict_standard_word_1358, _dict_standard_code_1358 },
  { _dict_standard_word_1359, _dict_standard_code_1359 },
  { _dict_standard_word_1360, _dict_standard_code_1360 },
  { _dict_standard_word_1361, _dict_standard_code_1361 },
  { _dict_standard_word_1362, _dict_standard_code_1362 },
  { _dict_standard_word_1363, _dict_standard_code_1363 },
  { _dict_standard_word_1364, _dict_standard_code_1364 },
  { _dict_standard_word_1365, _dict_standard_code_1365 },
  { _dict_standard_word_1366, _dict_standard_code_1366 },
  { _dict_standard_word_1367, _dict_standard_code_1367 },
  { _dict_standard_word_1368, _dict_standard_code_1368 },
  { _dict_standard_word_1369, _dict_standard_code_1369 },
  { _dict_standard_word_1370, _dict_standard_code_1370 },
  { _dict_standard_word_1371, _dict_standard_code_1371 },
  { _dict_standard_word_1372, _dict_standard_code_1372 },
  { _dict_standard_word_1373, _dict_standard_code_1373 },
  { _dict_standard_word_1374, _dict_standard_code_1374 },
  { _dict_standard_word_1375, _dict_standard_code_1375 },
  { _dict_standard_word_1376, _dict_standard_code_1376 },
  { _dict_standard_word_1377, _dict_standard_code_1377 },
  { _dict_standard_word_1378, _dict_standard_code_1378 },
  { _dict_standard_word_1379, _dict_standard_code_1379 },
  { _dict_standard_word_1380, _dict_standard_code_1380 },
  { _dict_standard_word_1381, _dict_standard_code_1381 },
  { _dict_standard_word_1382, _dict_standard_code_1382 },
  { _dict_standard_word_1383, _dict_standard_code_1383 },
  { _dict_standard_word_1384, _dict_standard_code_1384 },
  { _dict_standard_word_1385, _dict_standard_code_1385 },
  { _dict_standard_word_1386, _dict_standard_code_1386 },
  { _dict_standard_word_1387, _dict_standard_code_1387 },
  { _dict_standard_word_1388, _dict_standard_code_1388 },
  { _dict_standard_word_1389, _dict_standard_code_1389 },
  { _dict_standard_word_1390, _dict_standard_code_1390 },
  { _dict_standard_word_1391, _dict_standard_code_1391 },
  { _dict_standard_word_1392, _dict_standard_code_1392 },
  { _dict_standard_word_1393, _dict_standard_code_1393 },
  { _dict_standard_word_1394, _dict_standard_code_1394 },
  { _dict_standard_word_1395, _dict_standard_code_1395 },
  { _dict_standard_word_1396, _dict_standard_code_1396 },
  { _dict_standard_word_1397, _dict_standard_code_1397 },
  { _dict_standard_word_1398, _dict_standard_code_1398 },
  { _dict_standard_word_1399, _dict_standard_code_1399 },
  { _dict_standard_word_1400, _dict_standard_code_1400 },
  { _dict_standard_word_1401, _dict_standard_code_1401 },
  { _dict_standard_word_1402, _dict_standard_code_1402 },
  { _dict_standard_word_1403, _dict_standard_code_1403 },
  { _dict_standard_word_1404, _dict_standard_code_1404 },
  { _dict_standard_word_1405, _dict_standard_code_1405 },
  { _dict_standard_word_1406, _dict_standard_code_1406 },
  { _dict_standard_word_1407, _dict_standard_code_1407 },
  { _dict_standard_word_1408, _dict_standard_code_1408 },
  { _dict_standard_word_1409, _dict_standard_code_1409 },
  { _dict_standard_word_1410, _dict_standard_code_1410 },
  { _dict_standard_word_1411, _dict_standard_code_1411 },
  { _dict_standard_word_1412, _dict_standard_code_1412 },
  { _dict_standard_word_1413, _dict_standard_code_1413 },
  { _dict_standard_word_1414, _dict_standard_code_1414 },
  { _dict_standard_word_1415, _dict_standard_code_1415 },
  { _dict_standard_word_1416, _dict_standard_code_1416 },
  { _dict_standard_word_1417, _dict_standard_code_1417 },
  { _dict_standard_word_1418, _dict_standard_code_1418 },
  { _dict_standard_word_1419, _dict_standard_code_1419 },
  { _dict_standard_word_1420, _dict_standard_code_1420 },
  { _dict_standard_word_1421, _dict_standard_code_1421 },
  { _dict_standard_word_1422, _dict_standard_code_1422 },
  { _dict_standard_word_1423, _dict_standard_code_1423 },
  { _dict_standard_word_1424, _dict_standard_code_1424 },
  { _dict_standard_word_1425, _dict_standard_code_1425 },
  { _dict_standard_word_1426, _dict_standard_code_1426 },
  { 0, 0 } // flags the end of the dictionary
};
