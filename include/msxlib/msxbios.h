#ifndef __MSXBIOS_H__
#define __MSXBIOS_H__

#include <stdint.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxbiosaddr.h>

/* SNSMAT キーマトリックスの指定行を読み出す */
uint8_t __LIB__ msxmain_dct_snsmat(uint8_t m) __smallc;
uint8_t __LIB__ msxmain_dos_snsmat(uint8_t m) __smallc;

/* キー入力バッファをクリア */
void __LIB__ msxmain_dct_kilbuf(void) __smallc;
void __LIB__ msxmain_dos_kilbuf(void) __smallc;

/* SCREENモードの切り替え */
void __LIB__ msxmain_dct_chgmod(uint8_t mode) __smallc;
void __LIB__ msxmain_dos_chgmod(uint8_t mode) __smallc;

/* 画面の色を変える */
void __LIB__ msxmain_dct_chgclr(uint8_t fg, uint8_t bg, uint8_t bd) __smallc;
void __LIB__ msxmain_dos_chgclr(uint8_t fg, uint8_t bg, uint8_t bd) __smallc;

/* 各種入出力機器の状態取得 */
uint8_t __LIB__ msxmain_dct_gtpad(uint8_t id) __smallc;
uint8_t __LIB__ msxmain_dos_gtpad(uint8_t id) __smallc;

/* グラフィック画面に文字を描画 */
void __LIB__ msxmain_dct_grpprt(char ch) __smallc;
void __LIB__ msxmain_dos_grpprt(char ch) __smallc;

/* 文字を1文字出力する */
void __LIB__ msxmain_dct_chput(char ch) __smallc;
void __LIB__ msxmain_dos_chput(char ch) __smallc;

/* パレットを初期化 */
void __LIB__ msxsub_dct_iniplt(void) __smallc;
void __LIB__ msxsub_dos_iniplt(void) __smallc;

/* SCREENモードの切り替え */
void __LIB__ msxsub_dct_chgmdp(uint8_t mode) __smallc;
void __LIB__ msxsub_dos_chgmdp(uint8_t mode) __smallc;

/* 画面クリア */
void __LIB__ msxsub_dct_cls(void) __smallc;
void __LIB__ msxsub_dos_cls(void) __smallc;

/* CLOCK-ICのデータを読み出します。 */
uint8_t __LIB__ msxsub_dct_redclk(uint8_t addr) __smallc;
uint8_t __LIB__ msxsub_dos_redclk(uint8_t addr) __smallc;

/* グラフィック画面に漢字を描画する。 */
void __LIB__ msxsub_dct_knjprt(uint8_t mode, uint16_t code) __smallc;
void __LIB__ msxsub_dos_knjprt(uint8_t mode, uint16_t code) __smallc;

/* パレットを設定する。 */
void __LIB__ msxsub_dct_setplt(uint8_t pal, uint8_t r, uint8_t g, uint8_t b) __smallc;
void __LIB__ msxsub_dos_setplt(uint8_t pal, uint8_t r, uint8_t g, uint8_t b) __smallc;

#ifdef __MSXDOS__
#define msxmain_snsmat(m)               msxmain_dos_snsmat(m)
#define msxmain_kilbuf()                msxmain_dos_kilbuf()
#define msxmain_chgmod(mode)            msxmain_dos_chgmod(mode)
#define msxmain_chgclr(fg, bg, bd)      msxmain_dos_chgclr(fg, bg, bd)
#define msxsub_iniplt()                 msxsub_dos_iniplt()
#define msxmain_gtpad(id)               msxmain_dos_gtpad(id)
#define msxsub_chgmdp(mode)             msxsub_dos_chgmdp(mode)
#define msxsub_cls()                    msxsub_dos_cls()
#define msxmain_grpprt(ch)              msxmain_dos_grpprt(ch)
#define msxsub_redclk(addr)             msxsub_dos_redclk(addr)
#define msxsub_knjprt(mode,code)        msxsub_dos_knjprt(mode,code)
#define msxsub_setplt(pal,r,g,b)        msxsub_dos_setplt(pal,r,g,b)
#define msxmain_chput(ch)               msxmain_dos_chput(ch)
#else
#define msxmain_snsmat(m)               msxmain_dct_snsmat(m)
#define msxmain_kilbuf()                msxmain_dct_kilbuf()
#define msxmain_chgmod(mode)            msxmain_dct_chgmod(mode)
#define msxmain_chgclr(fg, bg, bd)      msxmain_dct_chgclr(fg, bg, bd)
#define msxsub_iniplt()                 msxsub_dct_iniplt()
#define msxmain_gtpad(id)               msxmain_dct_gtpad(id)
#define msxsub_chgmdp(mode)             msxsub_dct_chgmdp(mode)
#define msxsub_cls()                    msxsub_dct_cls()
#define msxmain_grpprt(ch)              msxmain_dct_grpprt(ch)
#define msxsub_redclk(addr)             msxsub_dct_redclk(addr)
#define msxsub_knjprt(mode, code)       msxsub_dct_knjprt(mode, code)
#define msxsub_setplt(pal,r,g,b)        msxsub_dct_setplt(pal,r,g,b)
#define msxmain_chput(ch)               msxmain_dct_chput(ch)
#endif

#endif