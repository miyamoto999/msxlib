#include <stdint.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

void __LIB__ msxvdp_dct_draw_char16(int16_t x, int16_t y, char ch, uint8_t mode,  uint8_t logi_op) __smallc
{
    MSXWORK_LOGOPR_VAL = logi_op;
    MSXWORK_GRPACX_VAL = x;
    MSXWORK_GRPACY_VAL = y;
    msxsub_dct_knjprt(mode, g_msxvdp_ascii2knjcode[((int)ch) & 0xff]);
}
