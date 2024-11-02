#include <msxlib/slot.h>
#include <msxlib/vdp.h>
#include <msxlib/slot.h>

void __LIB__ msxvdp_dct_init() __smallc
{
    g_msxvdp_port_m = *(uint8_t*)(0x0006);
    g_msxvdp_port_n = *(uint8_t*)(0x0007);
    g_msxvdp_read_port_1 = g_msxvdp_port_m + 1;
    g_msxvdp_write_port_1 = g_msxvdp_port_n + 1;
    g_msxvdp_write_port_2 = g_msxvdp_port_n + 2;
    g_msxvdp_write_port_3 = g_msxvdp_port_n + 3;
}

