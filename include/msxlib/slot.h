#ifndef __SLOT_H__
#define __SLOT_H__

#include <stdint.h>
#include <msxlib/msxlib.h>

/* 指定スロットの指定アドレスのデータを読む */
uint8_t __LIB__ msxslot_rdslt(uint8_t slot, void *addr) __smallc;

#endif