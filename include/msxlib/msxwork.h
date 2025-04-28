#ifndef __MSXLIB_MSXWORK_H__
#define __MSXLIB_MSXWORK_H__

#include <stdint.h>
#include "msxworkaddr.h"

/* MAIN ROMのスロット */
#define MSXWORK_EXPTBL_VAL  *((uint8_t *)(MSXWORK_EXPTBL))

/* キークリック音 0:off 0以外:on */
#define MSXWORK_CLIKSW_VAL  *((uint8_t *)(MSXWORK_CLIKSW))

/* 前景色 */
#define MSXWORK_FORCLR_VAL  *((uint8_t *)(MSXWORK_FORCLR))
/* 背景色 */
#define MSXWORK_BAKCLR_VAL  *((uint8_t *)(MSXWORK_BAKCLR))
/* 周辺色 */
#define MSXWORK_BDRCLR_VAL  *((uint8_t *)(MSXWORK_BDRCLR))
/* ロジカルオペレーションコード */
#define MSXWORK_LOGOPR_VAL  *((uint8_t *)(MSXWORK_LOGOPR))
/* X座標 */
#define MSXWORK_GXPOS_VAL   *((int16_t *)(MSXWORK_GXPOS))
/* Y座標 */
#define MSXWORK_GYPOS_VAL   *((int16_t *)(MSXWORK_GYPOS))
/* グラフィックアキュムレータX */
#define MSXWORK_GRPACX_VAL  *((int16_t *)(MSXWORK_GRPACX))
/* グラフィックアキュムレータX */
#define MSXWORK_GRPACY_VAL  *((int16_t *)(MSXWORK_GRPACY))
/* GRPHED グラフィック文字を出すときのフラグ */
#define MSXWORK_GRPHED_VAL  *((uint8_t *)(MSXWORK_GRPHED))

/* SCRMOD スクリーンモード番号 */
#define MSXWORK_SCRMOD_VAL  *((uint8_t *)(MSXWORK_SCRMOD))
/* OLDSCR スクリーンモードの保存場所 */
#define MSXWORK_OLDSCR_VAL  *((uint8_t *)(MSXWORK_OLDSCR))

/* JIFFY システムカウンタ(PLAY文が内部で使用する) */
#define MSXWORK_JIFFY_VAL   *((uint16_t *)(MSXWORK_JIFFY))

/* DPPAGE ディスプレイページ番号 */
#define MSXWORK_DPPAGE_VAL  *((uint8_t *)(MSXWORK_DPPAGE))
/* ACPAGE アクティブページ番号 */
#define MSXWORK_ACPAGE_VAL  *((uint8_t *)(MSXWORK_ACPAGE))

/* マシン語領域 */
#define MSXWORK_HIMEM_VAL   *((uint16_t *)(MSXWORK_HIMEM))
/* ファイルコントロールブロック */
#define MSXWORK_MEMSIZ_VAL  *((uint16_t *)(MSXWORK_MEMSIZ))
/* 文字列領域 */
#define MSXWORK_STKTOP_VAL  *((uint16_t *)(MSXWORK_STKTOP))

#endif