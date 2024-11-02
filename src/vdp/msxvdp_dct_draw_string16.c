#include <msxlib/msxlib.h>
#include <stdint.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

void __LIB__ msxvdp_dct_draw_string16(int16_t x, int16_t y, char *str, uint8_t mode, uint8_t logi_op) __smallc
{
    BOOL grp = FALSE;
    MSXWORK_LOGOPR_VAL = logi_op;
    MSXWORK_GRPACX_VAL = x;
    MSXWORK_GRPACY_VAL = y;
    
    int i = 0;
    while(str[i] != 0) {
        if(str[i] == 0x01) {
            grp = TRUE;
        } else if(str[i] >= 0x20) {
            if(grp) {
                msxsub_dct_knjprt(mode, g_msxvdp_ascii2knjcode[((int)str[i] - 0x40) & 0xff]);
                grp = FALSE;
            } else {
                msxsub_dct_knjprt(mode, g_msxvdp_ascii2knjcode[((int)str[i]) & 0xff]);
            }
        }
        i++;
    }
}
