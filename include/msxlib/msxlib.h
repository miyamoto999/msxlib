#ifndef __MSXLIB_MSXLIB_H__
#define __MSXLIB_MSXLIB_H__

#include <stdint.h>

#ifndef BOOL
#define BOOL    char
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif


#if defined(__GNUC__) || defined(__VSCODE__)
void z80_ei(void);
void z80_di(void);

#ifndef __LIB__
#define __LIB__
#endif
#define __smallc
#define __stdc
#define __z88dk_sdccdecl
#else
#define z80_ei()    __asm__("ei")
#define z80_di()    __asm__("di")
#endif

/**
 * @brief キーボードバッファから1文字入力する。
 * @details
 *      キーボードバッファから1文字入力する。
 *      キーボードバッファが空のときは-1が変える。
 * 
 * @return int16_t -1:キーボードバッファがから
 * @return int16_t 文字コード
 */
int16_t __LIB__ msx_dct_inpkey(void) __smallc;
int16_t __LIB__ msx_dos_inpkey(void) __smallc;

#ifdef __MSXDOS__
#define msx_inpkey()        msx_dos_inpkey()
#else
#define msx_inpkey()        msx_dct_inpkey()
#endif

int __LIB__ pre_printf_scc(const char *fmt, ...) __smallc;
int __LIB__ pre_printf_sdcc(const char *fmt, ...) __z88dk_sdccdecl;

#ifdef __SCCZ80
#define pre_printf(...)     pre_printf_scc(__VA_ARGS__)
#else
#define pre_printf(...)     pre_printf_sdcc(__VA_ARGS__)
#endif

uint16_t __LIB__ msx_get_reg_sp(void) __smallc;

#endif