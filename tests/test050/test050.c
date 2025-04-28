#include <msxlib/msxlib.h>
#include <msxlib/msxwork.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>
#include <msxlib/vdp.h>
#include <msxlib/kanji.h>
#include <stdio.h>
#include <assert.h>

static uint8_t buf[256];

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
    BOOL errflag = FALSE;
    int x,y;

    msxvdp_set_screen(7);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(y = 0; y < 212; y++) {
        for(x = 0; x < 512; x+=2) {
            if(x == 0 && y == 0) {
                msxvdp_poke(0, x+y);
            } else {
                msxvdp_poke_next(x+y);
            }
        }
    }    

    for(y = 0; y < 212; y++) {
        for(x = 0; x < 512; x+=2) {
            if(x == 0 && y == 0) {
                uint8_t data = msxvdp_peek(0);
                if(data != 0) {
                    errflag = TRUE;
                    break;
                }
            } else {
                uint8_t data = msxvdp_peek_next();
                if(data != ((x+y) & 0xff)) {
                    errflag = TRUE;
                    break;
                }
            }
        }
        if(errflag) {
            break;
        }
    }
    if(errflag) {
        msxvdp_set_screen(0);
        printf("test2:msxvdp_peek error(x:%d, y:%d)\n", x, y);
        abort();
    }    
}

static void test3()
{
    int x,y;
    BOOL errflag = FALSE;

    msxvdp_set_screen(7);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(y = 0; y < 212; y++) {
        for(x = 0; x < 512; x+=2) {
            buf[x/2] = x - y;
        }
        if(y == 0) {
            msxvdp_write(0, buf, 256);
        } else {
            msxvdp_write_next(buf, 256);
        }
    }
    for(y = 0; y < 212; y++) {
        if(y == 0) {
            msxvdp_read(0, buf, 256);
        } else {
            msxvdp_read_next(buf, 256);
        }
        for(x = 0; x < 512; x+=2) {
            if(buf[x/2] != ((x - y) & 0xff)) {
                errflag = TRUE;
                break;
            }
        }
        if(errflag) {
            break;
        }
    }
    if(errflag) {
        msxvdp_set_screen(0);
        printf("test3:msxvdp_read error(x:%d, y:%d)\n", x, y);
        abort();
    }    
}

static void test4()
{
    int x,y;
    BOOL errflag = FALSE;

    msxvdp_set_screen(7);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(x = 0; x < 512; x+=2) {
        buf[x/2] = x;
    }
    for(y = 0; y < 212; y++) {
        msxvdp_write((long)y * 256, buf, 256);
    }
    for(y = 0; y < 212; y++) {
        msxvdp_read((long)y * 256, buf, 256);
        for(x = 0; x < 512; x+=2) {
            if(buf[x/2] != (x & 0xff)) {
                errflag = TRUE;
                break;
            }
        }
        if(errflag) {
            break;
        }
    }
    if(errflag) {
        msxvdp_set_screen(0);
        printf("test4:msxvdp_read error(x:%d, y:%d)\n", x, y);
        abort();
    }    
}

static void test5()
{
    int x,y;
    BOOL errflag = FALSE;

    msxvdp_set_screen(7);
    msxvdp_setpage_sc7(0);
    msxvdp_cls();
    msxvdp_setpage_sc7(1);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    for(x = 0; x < 512; x+=2) {
        buf[x/2] = x;
    }
    for(y = 0; y < 212; y++) {
        msxvdp_write((long)y * 256 + 0x10000, buf, 256);
    }
    for(y = 0; y < 212; y++) {
        msxvdp_read((long)y * 256 + 0x10000, buf, 256);
        for(x = 0; x < 512; x+=2) {
            if(buf[x/2] != (x & 0xff)) {
                errflag = TRUE;
                break;
            }
        }
        if(errflag) {
            break;
        }
    }
    if(errflag) {
        msxvdp_set_screen(0);
        printf("test5:msxvdp_read error(x:%d, y:%d)\n", x, y);
        abort();
    }    
}

int main(void) 
{
    msxvdp_init();
    uint16_t test1_jiffy, test2_jiffy, test3_jiffy, test4_jiffy, test5_jiffy;

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

    test3_jiffy = MSXWORK_JIFFY_VAL;
    test3();
    test3_jiffy = MSXWORK_JIFFY_VAL - test3_jiffy;
    msxvdp_draw_string(0, 212-8, "Hit any key", 0);
    while(!dos1_dirio(0xff)){}

    test4_jiffy = MSXWORK_JIFFY_VAL;
    test4();
    test4_jiffy = MSXWORK_JIFFY_VAL - test4_jiffy;
    msxvdp_draw_string(0, 212-8, "Hit any key", 0);
    while(!dos1_dirio(0xff)){}

    test5_jiffy = MSXWORK_JIFFY_VAL;
    test5();
    test5_jiffy = MSXWORK_JIFFY_VAL - test5_jiffy;
    msxvdp_draw_string(0, 212-8, "Hit any key", 0);
    while(!dos1_dirio(0xff)){}

    msxvdp_set_screen(0);

    printf("test1: %u jiffies\n", test1_jiffy);
    printf("test2: %u jiffies\n", test2_jiffy);
    printf("test3: %u jiffies\n", test3_jiffy);
    printf("test4: %u jiffies\n", test4_jiffy);
    printf("test5: %u jiffies\n", test5_jiffy);

    return 0;
}

