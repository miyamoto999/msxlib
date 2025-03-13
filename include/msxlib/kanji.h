#ifndef __MSXLIB_KANJI_H__
#define __MSXLIB_KANJI_H__

#include <msxlib/msxlib.h>

#define MSX_KMODE_ANK       0
#define MSX_KMODE_KANJI0    1
#define MSX_KMODE_KANJI1    2
#define MSX_KMODE_KANJI2    3
#define MSX_KMODE_KANJI3    4

/**
 * @brief 漢字ドライバのチェック
 * 
 * @return BOOL TRUE: 漢字ドライバが存在する
 *              FALSE: 漢字ドライバが存在しない
 */
BOOL __LIB__ msx_chk_knjdrv(void) __smallc;

/* 漢字モードの設定　*/
void __LIB__ msx_set_knjmode(uint8_t mode) __smallc;
/* 現在の漢字モードの取得 */
int8_t __LIB__ msx_get_knjmode(void) __smallc;

#endif