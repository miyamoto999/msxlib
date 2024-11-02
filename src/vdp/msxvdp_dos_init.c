#include <msxlib/slot.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

void __LIB__ msxvdp_dos_init() __smallc
{
    g_msxvdp_port_m = msxslot_rdslt(MSXWORK_EXPTBL_VAL, 0x0006);
    g_msxvdp_port_n = msxslot_rdslt(MSXWORK_EXPTBL_VAL, 0x0007);
    g_msxvdp_read_port_1 = g_msxvdp_port_m + 1;
    g_msxvdp_write_port_1 = g_msxvdp_port_n + 1;
    g_msxvdp_write_port_2 = g_msxvdp_port_n + 2;
    g_msxvdp_write_port_3 = g_msxvdp_port_n + 3;
}

