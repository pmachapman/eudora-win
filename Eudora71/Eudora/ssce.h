/* SSCE: Sentry Spelling Checker Engine
 * Copyright 1993 by Wintertree Software Inc.
 *
 * Use, duplication, and disclosure of this file is governed by
 * a license agreement between Wintertree Software Inc. and
 * the licensee.
 *
 * @VERSION: 4.20
 * @DATE: 961002
 */

#if !defined(SSCE_H_)
#define SSCE_H_

#include <stddef.h>

#if defined(_WIN16) || defined(_WIN32)
  #include <windows.h>
#endif

/* Limits. */
#define SSCE_MAX_WORD_LEN 63
#define SSCE_MAX_WORD_SZ (SSCE_MAX_WORD_LEN + 1)
#define SSCE_MAX_SESSIONS 16
#define SSCE_MAX_LEX_PER_SESSION 16
#define SSCE_MAX_BLOCKS_PER_SESSION 4

/* Error codes. Note that these are always negative. */
#define SSCE_TOO_MANY_SESSIONS_ERR (-1)
#define SSCE_BAD_SESSION_ID_ERR (-2)
#define SSCE_WORD_NOT_FOUND_ERR (-3)
#define SSCE_FILE_NOT_FOUND_ERR (-4)
#define SSCE_TOO_MANY_LEXICONS_ERR (-5)
#define SSCE_UNKNOWN_LEXICON_TYPE_ERR (-6)
#define SSCE_BAD_LEXICON_ID_ERR (-7)
#define SSCE_BUFFER_TOO_SMALL_ERR (-8)
#define SSCE_READ_ONLY_LEXICON_ERR (-9)
#define SSCE_TWO_WORDS_REQUIRED_ERR (-10)
#define SSCE_ONE_WORD_REQUIRED_ERR (-11)
#define SSCE_OUT_OF_MEMORY_ERR (-12)
#define SSCE_UNSUPPORTED_ACTION_ERR (-13)
#define SSCE_LEXICON_EXISTS_ERR (-14)
#define SSCE_TOO_MANY_BLOCKS_ERR (-15)
#define SSCE_BAD_BLOCK_ID_ERR (-16)
#define SSCE_CANCEL_ERR (-17)
#define SSCE_TOO_MANY_SUFFIXES_ERR (-18)
#define SSCE_INVALID_WORD_ERR (-19)
#define SSCE_WORD_OUT_OF_SEQUENCE_ERR (-20)
#define SSCE_TOO_MANY_SMALL_WORDS_ERR (-21)
#define SSCE_FILE_READ_ERR (-22)
#define SSCE_FILE_WRITE_ERR (-23)
#define SSCE_FILE_OPEN_ERR (-24)
#define SSCE_BUSY_ERR (-25)

/* Spell-check result masks. Note that these will always result in a
 * positive value.
 */
#define SSCE_OK_RSLT 0x0
#define SSCE_MISSPELLED_WORD_RSLT (1 << 0)
#define SSCE_CHANGE_WORD_RSLT (1 << 1)
#define SSCE_SUGGEST_WORD_RSLT (1 << 2)
#define SSCE_UNCAPPED_WORD_RSLT (1 << 3)
#define SSCE_MIXED_CASE_WORD_RSLT (1 << 4)
#define SSCE_MIXED_DIGITS_WORD_RSLT (1 << 5)
#define SSCE_END_OF_BLOCK_RSLT (1 << 6)
#define SSCE_DOUBLED_WORD_RSLT (1 << 7)

/* Options. */
#define SSCE_IGNORE_CAPPED_WORD_OPT (1L << 0)
#define SSCE_IGNORE_MIXED_CASE_OPT (1L << 1)
#define SSCE_IGNORE_MIXED_DIGITS_OPT (1L << 2)
#define SSCE_IGNORE_ALL_CAPS_WORD_OPT (1L << 3)
#define SSCE_REPORT_UNCAPPED_OPT (1L << 4)
#define SSCE_REPORT_MIXED_CASE_OPT (1L << 5)
#define SSCE_REPORT_MIXED_DIGITS_OPT (1L << 6)
#define SSCE_REPORT_SPELLING_OPT (1L << 7)
#define SSCE_REPORT_DOUBLED_WORD_OPT (1L << 8)
#define SSCE_CASE_SENSITIVE_OPT (1L << 9)
#define SSCE_SPLIT_HYPHENATED_WORDS_OPT (1L << 10)
#define SSCE_SPLIT_CONTRACTED_WORDS_OPT (1L << 11)
#define SSCE_SPLIT_WORDS_OPT (1L << 12)
#define SSCE_SUGGEST_SPLIT_WORDS_OPT (1L << 13)
#define SSCE_SUGGEST_PHONETIC_OPT (1L << 14)
#define SSCE_SUGGEST_TYPOGRAPHICAL_OPT (1L << 15)
#define SSCE_STRIP_POSSESSIVES_OPT (1L << 16)
#define SSCE_MATCH_CASE_ON_REPLACE_OPT (1L << 17)
#define SSCE_CHAR_SET_OPT 0x80000001L
#define SSCE_LANGUAGE_OPT 0x80000002L

/* SSCE_Suggest sentinel for automatic depth selection: */
#define SSCE_AUTO_SEARCH_DEPTH (-1)

/* Lexicon formats: */
#define SSCE_COMPRESSED_LEX_FMT 0
#define SSCE_TEXT_LEX_FMT 1

/* Lexicon types: */
#define SSCE_CHANGE_LEX_TYPE 0
#define SSCE_IGNORE_LEX_TYPE 1
#define SSCE_SUGGEST_LEX_TYPE 2
#define SSCE_EXCLUDE_LEX_TYPE 3

/* Language ids: */
#define SSCE_AMER_ENGLISH_LANG 1033    /* American English */
#define SSCE_BRIT_ENGLISH_LANG 2057    /* British English */
#define SSCE_CATALAN_LANG 1027
#define SSCE_CZECH_LANG 1029
#define SSCE_DANISH_LANG 1030
#define SSCE_DUTCH_LANG 1043
#define SSCE_FINNISH_LANG 1035
#define SSCE_FRENCH_LANG 1036
#define SSCE_GERMAN_LANG 1031
#define SSCE_HUNGARIAN_LANG 1038
#define SSCE_ITALIAN_LANG 1040
#define SSCE_NORWEGIAN_BOKMAL_LANG 1044
#define SSCE_NORWEGIAN_NYNORSK_LANG 2068
#define SSCE_POLISH_LANG 1045
#define SSCE_PORTUGUESE_BRAZIL_LANG 1046
#define SSCE_PORTUGUESE_IBERIAN_LANG 2070
#define SSCE_RUSSIAN_LANG 1049
#define SSCE_SPANISH_LANG 1034
#define SSCE_SWEDISH_LANG 1053

/* Character sets: */
#define SSCE_ISO_8859_1_CHARSET 0      /* Latin 1 */
#define SSCE_ISO_8859_2_CHARSET 1      /* Latin 2 */
#define SSCE_ISO_8859_3_CHARSET 2      /* Latin 3 */
#define SSCE_ISO_8859_4_CHARSET 3      /* Latin 4 */
#define SSCE_ISO_8859_5_CHARSET 4
#define SSCE_ISO_8859_6_CHARSET 5
#define SSCE_ISO_8859_7_CHARSET 6
#define SSCE_ISO_8859_8_CHARSET 7
#define SSCE_ISO_8859_9_CHARSET 8      /* Latin 5 */
#define SSCE_ISO_8859_10_CHARSET 9     /* Latin 6 */

/* Data types used to ensure portability across compilers and O/Ss. These
 * may need to be redefined to suit a particular platform. The types are
 * named as follows: S = signed; U = unsigned; the number following is the
 * (minimum) width in bits.
 */
#if !defined(S8)
  #define S8 signed char
#endif
#if !defined(U8)
  #define U8 unsigned char
#endif
#if !defined(S16)
  #define S16 signed short
#endif
#if !defined(U16)
  #define U16 unsigned short
#endif
#if !defined(S32)
  #define S32 signed long
#endif
#if !defined(U32)
  #define U32 unsigned long
#endif

/* Non-local pointer qualifier for segmented architectures: */
#if !defined(FAR)
  #if defined(_WIN16)
   #define FAR _far
  #else
   #define FAR
  #endif
#endif

/* API function declaration qualifier: */
#if !defined(API)
  #if defined(_WIN16) || defined(_WIN32)
   #define API WINAPI
  #else
   #define API
  #endif
#endif

/* Some useful boolean constants: */
#if !defined(TRUE)
  #define TRUE 1
#endif
#if !defined(FALSE)
  #define FALSE 0
#endif

/* Data type used to represent text. This can be redefined to just "char"
 * if your application never uses accented characters.
 */
#if !defined(SSCE_CHAR)
  #define SSCE_CHAR unsigned char
#endif

/* Function definitions: */

#if defined(__cplusplus)
extern "C" {
#endif

/* Functions available in the basic SSCE API: */

extern S16 API SSCE_AddToLex(S16 sid, S16 lexId, const SSCE_CHAR FAR *word,
  const SSCE_CHAR FAR *otherWord);

extern S16 API SSCE_CheckBlock(S16 sid, S16 blkId, U32 options,
  SSCE_CHAR FAR *errWord, S16 errWordSz,
  SSCE_CHAR FAR *repWord, S16 repWordSz);

extern S16 API SSCE_CheckWord(S16 sid, U32 options,
  const SSCE_CHAR FAR *word, SSCE_CHAR FAR *replWord, S16 replWordSz);

extern S16 API SSCE_ClearLex(S16 sid, S16 lexId);

extern S16 API SSCE_CloseBlock(S16 sid, S16 blkId);

extern S16 API SSCE_CloseLex(S16 sid, S16 lexId);

extern S16 API SSCE_CloseSession(S16 sid);

extern void API SSCE_CompressLexAbort(S16 sid);

extern S16 API SSCE_CompressLexInit(S16 sid, const char *lexFileName,
  const char *suffixFileName, S16 langId, S16 charSet, U32 *errLine);

extern S16 API SSCE_CompressLexEnd(S16 sid);

extern S16 API SSCE_CompressLexFile(S16 sid, const char *fileName,
  U32 *errLine);
 
extern S16 API SSCE_CreateLex(S16 sid, const char FAR *fileName, S16 type,
  S16 lang);

extern S16 API SSCE_DelBlockWord(S16 sid, S16 blkId);

extern S16 API SSCE_DelFromLex(S16 sid, S16 lexId,
  const SSCE_CHAR FAR *word);

extern S32 API SSCE_GetBlock(S16 sid, S16 blkId, SSCE_CHAR FAR *block,
  S32 blkSz);

extern S16 API SSCE_GetBlockInfo(S16 sid, S16 blkId, S32 FAR *blkLen,
  S32 FAR *blkSz, S32 FAR *curPos, S32 FAR *wordCount);

extern S16 API SSCE_GetBlockWord(S16 sid, S16 blkId, SSCE_CHAR FAR *word,
  S16 wordSz);

extern S32 API SSCE_GetLex(S16 sid, S16 lexId, SSCE_CHAR FAR *lexBfr,
  S32 lexBfrSz);

extern S16 API SSCE_GetLexInfo(S16 sid, S16 lexId, S32 FAR *size,
  S16 FAR *format, S16 FAR *type, S16 FAR *lang);

extern U32 API SSCE_GetOption(S16 sid, U32 opt);

extern S16 API SSCE_NextBlockWord(S16 sid, S16 blkId);

extern S16 API SSCE_OpenBlock(S16 sid, SSCE_CHAR FAR *block, S32 blkLen,
  S32 blkSz, S16 copyBlock);

extern S16 API SSCE_OpenLex(S16 sid, const char FAR *fileName,
  S32 memBudget);

extern S16 API SSCE_OpenSession(void);

extern S16 API SSCE_ReplaceBlockWord(S16 sid, S16 blkId,
  const SSCE_CHAR FAR *word);

extern S16 API SSCE_SetBlockCursor(S16 sid, S16 blkId, S32 cursor);

extern void API SSCE_SetDebugFile(const char FAR *debugFile);

extern U32 API SSCE_SetOption(S16 sid, U32 opt, U32 val);

extern S16 API SSCE_Suggest(S16 sid, const SSCE_CHAR FAR *word, S16 depth,
  SSCE_CHAR FAR *suggBfr, S32 suggBfrSz, S16 FAR *scores, S16 scoreSz);

extern void API SSCE_Version(S16 FAR *major, S16 FAR *minor);

/* Functions available in the Windows API only: */

#if defined(_WIN16) || defined(_WIN32)

extern S32 API SSCE_CheckBlockDlg(HWND parent, SSCE_CHAR FAR *block,
  S32 blkLen, S32 blkSz);

extern S16 API SSCE_CheckCtrlDlg(HWND parent, HWND ctrlWin, S16 selTextOnly);

extern S16 API SSCE_EditLexDlg(HWND parent);

extern S16 API SSCE_GetAlwaysSuggest(void);

extern void API SSCE_GetHelpFile(char FAR *fileName, U16 fileNameSz);

extern S16 API SSCE_GetLexId(const char *lexFileName);

extern void API SSCE_GetMainLexPath(char FAR *path, U16 pathSz);

extern void API SSCE_GetMainLexFiles(char FAR *fileList, U16 fileListSz);

extern void API SSCE_GetRegTreeName(char FAR *regTreeName, U16 regTreeNameSz);

extern S16 API SSCE_GetSid(void);

extern void API SSCE_GetStatistics(U32 *wordsChecked, U32 *wordsChanged,
  U32 *errorsDetected);

extern void API SSCE_GetUserLexFiles(char *fileList, U16 fileListSz);

extern void API SSCE_GetUserLexPath(char FAR *path, U16 pathSz);

extern S16 API SSCE_OptionsDlg(HWND parent);

extern S16 API SSCE_ResetLex(void);

extern S16 API SSCE_SetAlwaysSuggest(S16 alwaysSuggest);

extern void API SSCE_SetDialogOrigin(S16 x, S16 y);

extern S16 API SSCE_SetHelpFile(const char *helpFile);

extern S16 API SSCE_SetIniFile(const char FAR *iniFile);

extern S16 API SSCE_SetMainLexPath(const char FAR *path);

extern S16 API SSCE_SetMainLexFiles(const char FAR *fileList);

extern S16 API SSCE_SetRegTreeName(const char *regTreeName);

extern S16 API SSCE_SetUserLexFiles(const char *fileList);

extern S16 API SSCE_SetUserLexPath(const char FAR *path);

#endif

#if defined(__cplusplus)
}
#endif

#endif /* SSCE_H_ */
