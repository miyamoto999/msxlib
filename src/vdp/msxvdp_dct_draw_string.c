#include <stdint.h>
#include <msxlib/vdp.h>
#include <msxlib/msxwork.h>

void __LIB__ msxvdp_dct_draw_string(int16_t x, int16_t y, char *str, uint8_t logi_op) __smallc
{
    MSXWORK_LOGOPR_VAL = logi_op;
    MSXWORK_GRPACX_VAL = x;
    MSXWORK_GRPACY_VAL = y;
    
    int i = 0;
    while(str[i] != 0) {
        if(str[i] == 0x01) {
            MSXWORK_GRPHED_VAL = 1;
        } else if(str[i] >= 0x20) {
            msxmain_dct_grpprt(str[i]);
        }
        i++;
    }
}
