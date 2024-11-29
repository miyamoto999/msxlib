#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

long heap;

#define BUF_SIZE    128
#define LAST_WSIZE  50
char buf[BUF_SIZE] ,buf2[BUF_SIZE];
#define TEST_FILE   "test.bin"

void mem_init(char *buf, int val_offset);
void makeFile(char *filename);
static void test1(void);
static void test2(void);

#define REC0    0
#define REC1    22
#define REC2    50
#define REC3    80

void dump(char *datas, int size)
{
    for(int i = 0; i < size; i+=8) {
        printf("%04X:", i & 0xffff);
        for(int j = 0; j < 8 && i+j < size; j++) {
            printf("%02X ", datas[i+j] & 0xff);
        }
        printf("\n");
    }
}

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
    
    dos_scode(1);

    /* テストファイル書き込み */
    printf("test file write:");
    makeFile(TEST_FILE);
    printf("OK\n");

    test1();
    test2();

    dos1_remove(TEST_FILE);

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t ret;
    printf("dos1_rdrnd() test1:");

    MSX_FCB fcb;
    msx_fcb_init(&fcb, TEST_FILE);

    ret = dos1_fopen(&fcb);
    assert(ret == 0);

    cpm_fcb_set_random_record(&fcb, 0x01020304);
    assert(fcb.cpm.random_record[0] == 0x04);
    assert(fcb.cpm.random_record[1] == 0x03);
    assert(fcb.cpm.random_record[2] == 0x02);
    assert(fcb.cpm.random_record[3] == 0x00);
    assert(cpm_fcb_get_random_record(&fcb) == 0x00020304);

    dos1_setdta(buf);

    /* レコード0の読み込みテスト */
    cpm_fcb_set_random_record(&fcb, 0);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    mem_init(buf2, REC0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 0);
    ret = dos1_rdrnd(&fcb);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 0);

    /* レコード1の読み込み */
    cpm_fcb_set_random_record(&fcb, 1);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    mem_init(buf2, REC1);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 1);
    /* シーケンシャルな読み込みをやってみる。*/
    ret = dos1_rdseq(&fcb);
    assert(ret == 0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 2);
    assert(cpm_fcb_get_random_record(&fcb) == 1);
    /* もう一度読み込む */
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 1);

    /* レコード3を読み込む */
    cpm_fcb_set_random_record(&fcb, 3);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    mem_init(buf2, REC3);
    memset(&buf2[LAST_WSIZE], 0, BUF_SIZE - LAST_WSIZE);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.ext_num_low == 0);
    assert(fcb.cpm.cur_record == 3);
    assert(cpm_fcb_get_random_record(&fcb) == 3);

    /* レコード4を読み込む */
    cpm_fcb_set_random_record(&fcb, 4);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 1);

    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    printf("OK\n");
}

static void test2(void)
{
    MSX_FCB fcb;
    uint8_t ret;

    printf("dos1_wrseq() & dos1_rdrnd() test2:");

    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fmake(&fcb);
    assert(ret == 0);
    dos1_setdta(buf);
    for(int i = 0; i < 300; i++) {
        mem_init(buf, i);
        ret = dos1_wrseq(&fcb);
        assert(ret == 0);
        uint8_t tmp = i & 0x7f;
        // printf("ex_low = %d\x1b\x4b\n", fcb.cpm.ext_num_low);
        // printf("ex_high = %d\x1b\x4b\n", fcb.cpm.ext_num_high);
        // printf("cur_record = %d\x1b\x4b\n", fcb.cpm.cur_record);
        // printf("\x1e\x1e\x1e");
        assert(fcb.cpm.cur_record == (i + 1) % 128);
        assert(fcb.cpm.ext_num_low == (i + 1) / 128);
    }
    // printf("\n\n\n");
    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fopen(&fcb);
    assert(ret == 0);
    dos1_setdta(buf);

    int rec_num = 128;
    mem_init(buf2, rec_num);
    cpm_fcb_set_random_record(&fcb, rec_num);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.cur_record == 0);
    assert(fcb.cpm.ext_num_low == 1);

    rec_num = 200;
    mem_init(buf2, rec_num);
    cpm_fcb_set_random_record(&fcb, rec_num);
    ret = dos1_rdrnd(&fcb);
    assert(ret == 0);
    assert(memcmp(buf, buf2, BUF_SIZE) == 0);
    assert(fcb.cpm.cur_record == rec_num % 128);
    assert(fcb.cpm.ext_num_low == rec_num / 128);

    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    printf("OK\n");
}

void mem_init(char *buf, int val_offset)
{
    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = (char)(i + val_offset);
    }
}

void makeFile(char *filename)
{
    BFILE *bfp;
    int size;

    bfp = bfile_create(TEST_FILE, BUF_SIZE);
    assert(bfp);
    mem_init(buf, REC0);
    size = bfile_write(bfp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    mem_init(buf, REC1);
    size = bfile_write(bfp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    mem_init(buf, REC2);
    size = bfile_write(bfp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    mem_init(buf, REC3);
    size = bfile_write(bfp, buf, LAST_WSIZE);
    assert(size == LAST_WSIZE);
    bfile_close(bfp);
}

