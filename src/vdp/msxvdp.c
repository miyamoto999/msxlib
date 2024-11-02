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

static uint8_t dmy;
const void *g_msxvdp_reg_saves[] = {
    MSXWORK_RG0SAV,MSXWORK_RG1SAV,MSXWORK_RG2SAV,MSXWORK_RG3SAV,MSXWORK_RG4SAV,
    MSXWORK_RG5SAV,MSXWORK_RG6SAV,MSXWORK_RG7SAV,MSXWORK_RG8SAV,MSXWORK_RG9SAV,
    MSXWORK_RG10SAV,MSXWORK_RG11SAV,MSXWORK_RG12SAV,MSXWORK_RG13SAV,MSXWORK_RG14SAV,
    MSXWORK_RG15SAV,MSXWORK_RG16SAV,MSXWORK_RG17SAV,MSXWORK_RG18SAV,MSXWORK_RG19SAV,
    MSXWORK_RG20SAV,MSXWORK_RG21SAV,MSXWORK_RG22SAV,MSXWORK_RG23SAV,&dmy,
    MSXWORK_RG25SAV,MSXWORK_RG26SAV,MSXWORK_RG27SAV,
};

