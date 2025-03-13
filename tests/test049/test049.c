#include <msxlib/msxlib.h>
#include <msxlib/msxwork.h>
#include <msxlib/msxbios.h>
#include <msxlib/vdp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
    msxvdp_init();

    srand((unsigned int)time(NULL));

    msxvdp_set_screen(5);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(int i = 0; i < 5; i++) {
        int r = rand() % 0x07;
        int g = rand() % 0x07;
        int b = rand() % 0x07;
        uint8_t tmp1 = (r << 4) | b;

        // パレット番号1を変更する
        msxvdp_set_reg(16, 1);
        outp(g_msxvdp_write_port_2, tmp1);
        outp(g_msxvdp_write_port_2, g);

        uint16_t start_jiffy = MSXWORK_JIFFY_VAL;
        while(MSXWORK_JIFFY_VAL - start_jiffy < 30) {
        }
    }
    for(int i = 0; i < 5; i++) {
        int r = rand() % 0x07;
        int g = rand() % 0x07;
        int b = rand() % 0x07;
        msxvdp_set_palette2(1, r, g, b);

        uint16_t start_jiffy = MSXWORK_JIFFY_VAL;
        while(MSXWORK_JIFFY_VAL - start_jiffy < 30) {
        }
    }
    // パレット番号1を変更する
    msxvdp_set_reg(16, 1);
    outp(g_msxvdp_write_port_2, 0);
    outp(g_msxvdp_write_port_2, 0);
    
    msxvdp_set_screen(0);
    msxvdp_cls();

    return 0;
}

