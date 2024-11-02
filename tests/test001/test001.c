#include <stdio.h>
#include <msxlib/msxlib.h>
#include <msxlib/vdp.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxwork.h>

int main(void)
{
    msxvdp_init();

    printf("HIT ANY KEY!\n");
    while(msx_inpkey() == -1){}

    msxvdp_set_screen(5);

    msxvdp_cls();
    msxvdp_draw_string(0, 0, "\x01\x41\x01\x42\x01\x43\x01\x44", 0);
    msxvdp_draw_string(0, 8, "HIT ANY KEY!", 0);
    while(msx_inpkey() == -1){}

    msxvdp_cls();
    msxvdp_set_pos(0, 0);
    msxvdp_set_logi_op(0);
    int i;
    for(i = 0; i < 256; i++) {
        if(i < 0x20) {
            MSXWORK_GRPHED_VAL = 1;
            msxvdp_draw_char_nopos(i + 0x40);
        } else {
            msxvdp_draw_char_nopos(i);
        }
    }
    msxvdp_draw_string(0, 212-8, "HIT ANY KEY!", 0);
    while(msx_inpkey() == -1){}

    msxvdp_cls();
    msxvdp_draw_string(0,0,"hoge", 0);
    //
    msxvdp_draw_string(0,8,"hoge", 0);
    msxvdp_draw_string(0,8,"hoge", 3);
    //
    msxvdp_draw_string(0,16,"hoge", 0);
    msxvdp_draw_string(0,16,"hoge", 3);
    msxvdp_draw_string(0,16,"hoge", 3);
    while(msx_inpkey() == -1){}

    msxvdp_cls();
    msxvdp_draw_char16(0, 0, 'A', 0, MSXVDP_LOGIOP_IMP);
    msxvdp_draw_char16(16, 0, 'B', 0, MSXVDP_LOGIOP_IMP);
    msxvdp_draw_char16(32, 0, 'C', 0, MSXVDP_LOGIOP_IMP);
    msxvdp_draw_string16(0, 16, "ABCDEFG", 0, MSXVDP_LOGIOP_IMP);
    msxvdp_draw_string16(0, 32, "\x01\x41\x01\x42\x01\x43\x01\x44", 0, MSXVDP_LOGIOP_IMP);

    while(msx_inpkey() == -1){}

    msxvdp_set_screen(1);

    return 0;
}