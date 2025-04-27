#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

uint8_t g_msxvdp_port_m = 0x98;      /* MAIN ROMのアドレス0x0006番地の値*/
uint8_t g_msxvdp_port_n = 0x98;      /* MAIN ROMのアドレス0x0007番地の値*/
uint8_t g_msxvdp_read_port_1 = 0x99;
uint8_t g_msxvdp_write_port_1 = 0x99;
uint8_t g_msxvdp_write_port_2  = 0x9a;
uint8_t g_msxvdp_write_port_3 = 0x9b;
uint8_t g_msxvdp_vram_addr_msb = 0;  /* VRAMアドレスの最上位ビットを指定する */
uint8_t g_msxvdp_vram_write_flag = 0; /* VRAM書き込みフラグ */
