#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

/*
long heap;
*/

#define BUF_SIZE    128
char buf[BUF_SIZE], buf2[BUF_SIZE];
#define TEST_FILE   "test.bin"

void mem_init(char *buf, int val_offset);
static void test1(void);

int main()
{
    /* 
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
    */

    dos_scode(1);

    test1();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t ret;

    printf("dos1_wrrnd() test1:");

    MSX_FCB fcb;
    msx_fcb_init(&fcb, TEST_FILE);

    dos1_setdta(buf);

    /* ファイルを書き込む */
    ret = dos1_fmake(&fcb);
    assert(ret == 0);

    cpm_fcb_set_random_record(&fcb, 0);
    mem_init(buf, 0);
    ret = dos1_wrrnd(&fcb);
    assert(ret == 0);
    assert(cpm_fcb_get_random_record(&fcb) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.ext_num_high == 0);
    assert(fcb.cpm.cur_record == 0);

    cpm_fcb_set_random_record(&fcb, 130);
    mem_init(buf, 100);
    ret = dos1_wrrnd(&fcb);
    assert(ret == 0);
    assert(cpm_fcb_get_random_record(&fcb) == 130);
    assert(fcb.cpm.ext_num_low == 1);
    assert(fcb.cpm.ext_num_high == 0);
    assert(fcb.cpm.cur_record == 2);

    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    /* 読み込みチェック */
    msx_fcb_init(&fcb, TEST_FILE);

    ret = dos1_fopen(&fcb);
    assert(ret == 0);
    assert(fcb.v1.file_size == 131 * 128);

    cpm_fcb_set_random_record(&fcb, 0);
    mem_init(buf2, 0);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    assert(cpm_fcb_get_random_record(&fcb) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.ext_num_high == 0);
    assert(fcb.cpm.cur_record == 0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);

    cpm_fcb_set_random_record(&fcb, 130);
    mem_init(buf2, 100);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    assert(cpm_fcb_get_random_record(&fcb) == 130);
    assert(fcb.cpm.ext_num_low == 1);
    assert(fcb.cpm.ext_num_high == 0);
    assert(fcb.cpm.cur_record == 2);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);

    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    dos1_remove(TEST_FILE);

    printf("OK\n");
}

void mem_init(char *buf, int val_offset)
{
    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = (char)(i + val_offset);
    }
}

