#ifndef __VDP_H__
#define __VDP_H__

#include <stdint.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxwork.h>

extern uint8_t g_msxvdp_port_m;      /* MAIN ROMのアドレス0x0006番地の値*/
extern uint8_t g_msxvdp_port_n;      /* MAIN ROMのアドレス0x0007番地の値*/
extern uint8_t g_msxvdp_read_port_1;
extern uint8_t g_msxvdp_write_port_1;
extern uint8_t g_msxvdp_write_port_2;
extern uint8_t g_msxvdp_write_port_3;

extern const uint16_t g_msxvdp_ascii2knjcode[];

#define MSXVDP_READ_PORT_0     (g_msxvdp_port_m)
#define MSXVDP_WRITE_PORT_0     (g_msxvdp_port_n)
#define MSXVDP_READ_PORT_1     (g_msxvdp_read_port_1)
#define MSXVDP_WRITE_PORT_1     (g_msxvdp_write_port_1)
#define MSXVDP_WRITE_PORT_2     (g_msxvdp_write_port_2)
#define MSXVDP_WRITE_PORT_3     (g_msxvdp_write_port_3)

/* VDPライブラリの初期化 */
void __LIB__ msxvdp_dct_init(void) __smallc;
void __LIB__ msxvdp_dos_init(void) __smallc;
/* SCREENモードを変更 */
#define msxvdp_set_screen(mode)    msxsub_chgmdp(mode)
/* カラーを設定 */
#define msxvdp_set_color(fg, bg, bd)   msxmain_chgclr(fg, bg, bd)
/* 画面クリア */
#define msxvdp_cls()   msxsub_cls()
/* VDPレジスタに値を設定 */
void __LIB__ msxvdp_set_reg(uint8_t reg, uint8_t val) __smallc;
/* パレットの設定 */
void __LIB__ msxvdp_set_palette2(uint8_t pal, uint8_t r, uint8_t g, uint8_t b) __smallc;
/* グラフィック画面へ文字を描画 */
void __LIB__ msxvdp_dct_draw_char(int16_t x, int16_t y, char ch, uint8_t logi_op) __smallc;
void __LIB__ msxvdp_dos_draw_char(int16_t x, int16_t y, char ch, uint8_t logi_op) __smallc;
/* グラフィック画面へ文字列を描画 */
void __LIB__ msxvdp_dct_draw_string(int16_t x, int16_t y, char *str, uint8_t logi_op) __smallc;
void __LIB__ msxvdp_dos_draw_string(int16_t x, int16_t y, char *str, uint8_t logi_op) __smallc;
/* グラフィックの座標を設定する。 */
#define msxvdp_set_pos(x,y)     {                               \
                                MSXWORK_GRPACX_VAL = x;     \
                                MSXWORK_GRPACY_VAL = y;     \
                            }
/* ロジカルオペレーションの設定 */
#define msxvdp_set_logi_op(op)   MSXWORK_LOGOPR_VAL = op
/* グラフィック画面へ16x16ドット文字を描画 */
void __LIB__ msxvdp_dct_draw_char16(int16_t x, int16_t y, char ch, uint8_t mode, uint8_t logi_op) __smallc;
void __LIB__ msxvdp_dos_draw_char16(int16_t x, int16_t y, char ch, uint8_t mode, uint8_t logi_op) __smallc;
/* グラフィック画面へ16x16ドットで文字列を描画
   半角文字を全角文字に変換して描画します。 */
void __LIB__ msxvdp_dct_draw_string16(int16_t x, int16_t y, char *str, uint8_t mode, uint8_t logi_op) __smallc;
void __LIB__ msxvdp_dos_draw_string16(int16_t x, int16_t y, char *str, uint8_t mode, uint8_t logi_op) __smallc;

#if defined(__MSXDOS__)
#define msxvdp_init()  msxvdp_dos_init()
#define msxvdp_draw_char(x, y, ch, logi_op)     msxvdp_dos_draw_char(x, y, ch, logi_op)
#define msxvdp_draw_char16(x, y, ch, mode, logi_op)     msxvdp_dos_draw_char16(x, y, ch, mode, logi_op)
#define msxvdp_draw_string(x, y, str, logi_op)     msxvdp_dos_draw_string(x, y, str, logi_op)
#define msxvdp_draw_string16(x, y, str, mode, logi_op)     msxvdp_dos_draw_string16(x, y, str, mode, logi_op)
#else
#define msxvdp_init()  msxvdp_dct_init()
#define msxvdp_draw_char(x, y, ch, logi_op)     msxvdp_dct_draw_char(x, y, ch, logi_op)
#define msxvdp_draw_char16(x, y, ch, mode, logi_op)     msxvdp_dct_draw_char16(x, y, ch, mode, logi_op)
#define msxvdp_draw_string(x, y, str, logi_op)     msxvdp_dct_draw_string(x, y, str, logi_op)
#define msxvdp_draw_string16(x, y, str, mode, logi_op)     msxvdp_dct_draw_string16(x, y, str, mode, logi_op)
#endif

/* パレットを設定する */
#define msxvdp_set_palette(pal,r,g,b)           msxsub_setplt(pal,r,g,b)
/* 文字を描画 */
#define msxvdp_draw_char_nopos(ch)        msxmain_grpprt(ch)

/* 16x16ドット文字を描画 */
#define msxvdp_draw_char16_nopos(mode,ch)    if(MSXWORK_GRPHED_VAL) {    \
                                            MSXWORK_GRPHED_VAL = 0; \
                                            msxsub_knjprt(mode, g_msxvdp_ascii2knjcode[((int)((ch) - 0x40)) & 0xff]);     \
                                        } else {    \
                                            msxsub_knjprt(mode, g_msxvdp_ascii2knjcode[((int)(ch)) & 0xff]);  \
                                        }


/* ロジカルオペレーション */
#define MSXVDP_LOGIOP_IMP          0
#define MSXVDP_LOGIOP_AND          1
#define MSXVDP_LOGIOP_OR           2
#define MSXVDP_LOGIOP_EOR          3
#define MSXVDP_LOGIOP_XOR          VDP_LOGIOP_EOR
#define MSXVDP_LOGIOP_NOT          4

#define MSXVDP_LOGIOP_TIMP         8
#define MSXVDP_LOGIOP_TAND         9
#define MSXVDP_LOGIOP_TOR          10
#define MSXVDP_LOGIOP_TEOR         11
#define MSXVDP_LOGIOP_TXOR         VDP_LOGIOP_TEOR
#define MSXVDP_LOGIOP_TNOT         12

#endif