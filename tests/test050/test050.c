#include <msxlib/msxlib.h>
#include <msxlib/msxwork.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>
#include <msxlib/vdp.h>
#include <msxlib/kanji.h>
#include <stdio.h>
#include <assert.h>

static void test1()
{
    uint8_t data;

    msxvdp_set_screen(0);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    printf("\n\n");
    for(int i = 0; i < 80; i++) {
        if(i == 0) {
            msxvdp_poke(i, '0' + i);
        } else {
            msxvdp_poke_next('0' + (i % 10));
        }
    }

    for(int i = 0; i < 80; i++) {
        if(i == 0) {
            msxvdp_poke(i + 80 * 10 + 20, '0' + i);
        } else {
            msxvdp_poke_next('0' + (i % 10));
        }
    }

    for(int i = 0; i < 80; i++) {
        if(i == 0) {
            data = msxvdp_peek(i + 80 * 10 + 20);
            assert(data == '0' + i);
        } else {
            data = msxvdp_peek_next();
            assert(data == '0' + (i % 10));
        }
    }
}

static void test2()
{
    msxvdp_set_screen(7);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(int y = 0; y < 212; y++) {
        for(int x = 0; x < 512; x+=2) {
            if(x == 0 && y == 0) {
                msxvdp_poke(0, x);
            } else {
                msxvdp_poke_next(x);
            }
        }
    }    
}

int main(void) 
{
    msxvdp_init();
    uint8_t test1_jiffy, test2_jiffy;

    if(msx_chk_knjdrv()) {
        msx_set_knjmode(0);
    }

    test1_jiffy = MSXWORK_JIFFY_VAL;
    test1();
    test1_jiffy = MSXWORK_JIFFY_VAL - test1_jiffy;
    printf("hit any key");
    while(!dos1_dirio(0xff)){}

    test2_jiffy = MSXWORK_JIFFY_VAL;
    test2();
    test2_jiffy = MSXWORK_JIFFY_VAL - test2_jiffy;
    msxvdp_draw_string(0, 212-8, "Hit any key", 0);
    while(!dos1_dirio(0xff)){}

    msxvdp_set_screen(0);

    printf("test1: %d jiffies\n", test1_jiffy);
    printf("test2: %d jiffies\n", test2_jiffy);

    return 0;
}

