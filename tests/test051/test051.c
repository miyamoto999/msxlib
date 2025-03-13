#include <msxlib/msxlib.h>
#include <msxlib/msxwork.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>
#include <msxlib/vdp.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

long heap;

#define BUF_SIZE    1024
#define FILENAME    "g.bin"
char buf[BUF_SIZE];

extern char gra_data[];

static void test1()
{
    MSXVDP_REG_DATA_HMMC hmmc;
    uint16_t w,h;
    BFILE *bfile;
    int idx;
    long counter = 0;
    int size;
    uint8_t data;
    BOOL ret;

    memset(&hmmc, 0, sizeof(MSXVDP_REG_DATA_HMMC));

    bfile = bfile_open(FILENAME, BFILE_O_RDONLY, BUF_SIZE);

    size = bfile_read(bfile, buf, BUF_SIZE);
    w = *(uint16_t*)(buf);
    h = *(uint16_t*)(buf + 2);
    idx = 4;

    if(w == 512) {
        w = 0;
    }
    if(h == 1024) {
        h = 0;
    }
    hmmc.nx = w;
    hmmc.ny = h;

    hmmc.first_data = buf[idx];
    idx++;
    counter++;

    msxvdp_hmmc_start(&hmmc);

    do {
        data = buf[idx];
        idx++;
        if(idx == size) {
            size = bfile_read(bfile, buf, BUF_SIZE);
            idx = 0;
        }
        ret = msxvdp_hmmc_next(data);
    } while(!ret);

    bfile_close(bfile);

}

static void test2()
{
    MSXVDP_REG_DATA_HMMC hmmc;

    for(int j = 0; j < 6; j++) {
        for(int i = 0; i < 4; i++) {
            memset(&hmmc, 0, sizeof(MSXVDP_REG_DATA_HMMC));
            switch(i) {
                case 0:
                    hmmc.dx = 0;
                    hmmc.dy = 32 * j;
                    break;
                case 1:
                    hmmc.arg = MSXVDP_CMD_DATA_ARG_DIX;
                    hmmc.dx = 32 * (i+1) - 1;
                    hmmc.dy = 32 * j;
                    break;
                case 2:
                    hmmc.arg = MSXVDP_CMD_DATA_ARG_DIY;
                    hmmc.dx = 32 * i;
                    hmmc.dy = 32 * (j+1) - 1;
                    break;
                case 3:
                    hmmc.arg = MSXVDP_CMD_DATA_ARG_DIX | MSXVDP_CMD_DATA_ARG_DIY;
                    hmmc.dx = 32 * (i+1) - 1;
                    hmmc.dy = 32 * (j+1) - 1;
                    break;
            }
            hmmc.nx = 32;
            hmmc.ny = 32;
        
            msxvdp_hmmc(&hmmc, gra_data, 32 * 32 / 2);
        }
    }
}

int main(void) 
{
    uint16_t test1_jiffy, test2_jiffy;

    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 

    msxvdp_init();
    msxvdp_set_screen(7);
    msxvdp_set_color(15, 1, 1);
    msxvdp_cls();

    test1_jiffy = MSXWORK_JIFFY_VAL;
    test1();
    test1_jiffy = MSXWORK_JIFFY_VAL - test1_jiffy;
    msxvdp_draw_string(0, 212 - 8, "Hit any key!", 0);
    while(!dos1_dirio(0xff)) {
    }

    msxvdp_cls();
    test2_jiffy = MSXWORK_JIFFY_VAL;
    test2();
    test2_jiffy = MSXWORK_JIFFY_VAL - test2_jiffy;
    msxvdp_draw_string(0, 212 - 8, "Hit any key!", 0);
    while(!dos1_dirio(0xff)) {
    }

    msxvdp_set_screen(0);
    printf("test1:%u jiffies\n", test1_jiffy);
    printf("test2:%u jiffies\n", test2_jiffy);

    return 0;
}

