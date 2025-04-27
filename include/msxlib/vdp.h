#ifndef __MSXLIB_VDP_H__
#define __MSXLIB_VDP_H__

#include <stdint.h>
#include <stdlib.h>
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

#define g_msxvdp_read_port_0   (g_msxvdp_port_m)
#define g_msxvdp_write_port_0   (g_msxvdp_port_n)
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
/** 
 * @brief VDPレジスタに値を設定
 * 
 *      VDPレジスタに値を設定する。
 * 
 * @param reg VDPレジスタ番号
 * @param val 設定する値
 */
void __LIB__ msxvdp_set_reg(uint8_t reg, uint8_t val) __smallc;
/* msxvdp_set_reg()の割り込み禁止を行わないバージョン */
void __LIB__ msxvdp_set_reg_ndi(uint8_t reg, uint8_t val) __smallc;

/* 間接指定のVDPレジスタ番号を設定する。　*/
void __LIB__ msxvdp_set_reg_indirect(uint8_t reg) __smallc;
/* 間接指定でレジスタへの値の設定 */
#define msxvdp_set_reg_indirect_val(val)    outp(MSXVDP_WRITE_PORT_3, val)

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

/* VRAMにデータを書き込む */
void __LIB__ msxvdp_poke(uint32_t addr, uint8_t data) __smallc;
/* 次のデータをVRAMに書き込む */
#define msxvdp_poke_next(data)  outp(MSXVDP_WRITE_PORT_0, data)
/* VRAMからデータを読み込む */
uint8_t __LIB__ msxvdp_peek(uint32_t addr) __smallc;
/* 次のデータをVRAMから読み込む */
#define msxvdp_peek_next()  inp(MSXVDP_READ_PORT_0)

/* VRAMにブロックデータを書き込む */
void __LIB__ msxvdp_write(uint32_t addr, uint8_t *data, uint16_t size) __smallc;
/* VRAMにブロックデータを書き込む(つづき) */
void __LIB__ msxvdp_write_next(uint8_t *data, uint16_t size) __smallc;
/* VRAMからブロックデータを読み込む */
void __LIB__ msxvdp_read(uint32_t addr, uint8_t *data, uint16_t size) __smallc;
/* VRAMからブロックデータを読み込む(つづき) */
void __LIB__ msxvdp_read_next(uint8_t *data, uint16_t size) __smallc;

/* ステータスレジスタの読み込み */
uint8_t __LIB__ msxvdp_get_status(uint8_t st_reg) __smallc;
/* ステータスレジスタの読み込み(割り込み禁止を行わない) */
uint8_t __LIB__ msxvdp_get_status_ndi(uint8_t st_reg) __smallc;

/* SCREEN 7の表示ページを変更する。 */
void __LIB__ msxvdp_setpage_sc7(uint8_t page) __smallc;


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
#define MSXVDP_LOGIOP_XOR          MSXVDP_LOGIOP_EOR
#define MSXVDP_LOGIOP_NOT          4

#define MSXVDP_LOGIOP_TIMP         8
#define MSXVDP_LOGIOP_TAND         9
#define MSXVDP_LOGIOP_TOR          10
#define MSXVDP_LOGIOP_TEOR         11
#define MSXVDP_LOGIOP_TXOR         MSXVDP_LOGIOP_TEOR
#define MSXVDP_LOGIOP_TNOT         12

#define MSXVDP_STATUS2_CE          0x01
#define MSXVDP_STATUS2_EO          0x02
#define MSXVDP_STATUS2_BD          0x10
#define MSXVDP_STATUS2_HR          0x20
#define MSXVDP_STATUS2_VR          0x40
#define MSXVDP_STATUS2_TR          0x80

/* VDPのコマンドが終了するのを待つ*/
void __LIB__ msxvdp_cmd_wait(void) __smallc;

/* HMMC */
typedef struct _reg_data_hmmc {
    uint16_t dx;            /* 転送先基準点 X座標(0-511) */
    uint16_t dy;            /* 転送先基準点 Y座標(0-1023)*/
    uint16_t nx;            /* X方向転送ドット数(1-512) 512の時は0を入れる */
    uint16_t ny;            /* Y方向転送ドット数(1-1024) 1024の時は0を入れる　*/
    uint8_t first_data;     /* 最初に書き込むデータ */
    uint8_t arg;            /* bit2:転送先基準点からのNXの方向(0:右、1:左) */
                            /* bit3:転送先基準点からのNYの方向(0:下、1:上) */
} MSXVDP_REG_DATA_HMMC;

#define MSXVDP_CMD_DATA_ARG_DIX     0x04
#define MSXVDP_CMD_DATA_ARG_DIY     0x08
#define MSXVDP_CMD_HMMC             0xf0

/* HMMCのコマンド送信 */
void __LIB__ msxvdp_hmmc_start(MSXVDP_REG_DATA_HMMC *reg_data) __smallc;

/* HMMCの次のデータを送信 */
BOOL __LIB__ msxvdp_hmmc_next(uint8_t data) __smallc;
/* HMMCコマンドの実行 */
void __LIB__ msxvdp_hmmc(MSXVDP_REG_DATA_HMMC *reg_data, char *datas, uint16_t size) __smallc;

#endif