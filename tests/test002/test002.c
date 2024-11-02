#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/vdp.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxwork.h>

static int drawCode(int start_code, int end_code)
{
    int ret = -1;
    int w;

    msxvdp_cls();
    msxvdp_set_pos(0, 0);
    msxvdp_set_logi_op(0);

    if(MSXWORK_SCRMOD_VAL == 6 || MSXWORK_SCRMOD_VAL == 7) {
        w = 512;
    } else {
        w = 256;
    }
    for(int i = start_code; i <= end_code; i++) {
        if(MSXWORK_GRPACX_VAL >= w) {
            MSXWORK_GRPACX_VAL = 0;
            MSXWORK_GRPACY_VAL += 16;
        }
        if(MSXWORK_GRPACY_VAL >= 192) {
            ret = i;
            break;
        }
        if(i < 0x20) {
            MSXWORK_GRPHED_VAL = 1;
            msxvdp_draw_char16_nopos(0, i + 0x40);
        } else {
            msxvdp_draw_char16_nopos(0, i);
        }
    }
    return ret;
}

int main(void)
{
    int start_code = 0;

    msxvdp_init();

    msxvdp_set_screen(5);

    while(start_code != -1) {
        start_code = drawCode(start_code, 255);
        msxvdp_draw_string(0, 212-8, "HIT ANY KEY!", 0);
        while(msx_inpkey() == -1){}
    }

    msxvdp_set_screen(1);

    return 0;
}