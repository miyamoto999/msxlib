#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

long heap;

#define BUF_SIZE    128
char buf[BUF_SIZE];
#define TEST_FILE   "test.bin"
#define TEST1_SIZE  5000
#define TEST2_SIZE  3451
#define RECORD_SIZE 128

static void test1(void);
static void test2(void);
static void test3(void);
void makefile(const char *filename, int size);

int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
    
    dos_scode(1);

    test1();
    test2();
    test3();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t ret;
    MSX_FCB fcb;

    printf("dos1_fsize() test1:");

    /* テスト用ファイルを作る */
    makefile(TEST_FILE, TEST1_SIZE);
    
    /* ファイルサイズチェック */
    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fsize(&fcb);
    assert(ret == 0);

    assert(cpm_fcb_get_random_record(&fcb) == (TEST1_SIZE + RECORD_SIZE - 1) / RECORD_SIZE);

    /* テスト用ファイルを作る */
    makefile(TEST_FILE, TEST2_SIZE);
    
    /* ファイルサイズチェック */
    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fsize(&fcb);
    assert(ret == 0);

    assert(cpm_fcb_get_random_record(&fcb) == (TEST2_SIZE + RECORD_SIZE - 1) / RECORD_SIZE);

    dos1_remove(TEST_FILE);

    printf("OK\n");
}

static void test2(void)
{
    uint8_t ret;
    MSX_FCB fcb;

    printf("dos1_fsize() test2:");

    /* ファイルサイズチェック */
    msx_fcb_init(&fcb, "12345678.bin");
    ret = dos1_fsize(&fcb);
    assert(ret == 0xff);

    printf("OK\n");
}

static void test3(void)
{
    uint8_t ret;
    MSX_FCB fcb;

    printf("dos1_fsize() test3:");

    /* テスト用ファイルを作る */
    makefile(TEST_FILE, TEST1_SIZE);
    
    /* ファイルサイズチェック */
    msx_fcb_init(&fcb, "t*.bin");
    ret = dos1_fsize(&fcb);
    assert(ret == 0);

    assert(cpm_fcb_get_random_record(&fcb) == (TEST1_SIZE + RECORD_SIZE - 1) / RECORD_SIZE);

    dos1_remove(TEST_FILE);

    printf("OK\n");
}

void makefile(const char *filename, int file_size)
{
    BFILE *bfp;
    int size, i;

    bfp = bfile_create(filename, BUF_SIZE);
    assert(bfp);
    for(i = 0; i < BUF_SIZE; i++) {
        buf[i] = i;
    }

    for(i = 0; i < file_size / BUF_SIZE; i++) {
        size = bfile_write(bfp, buf, BUF_SIZE);
        assert(size == BUF_SIZE);
    }
    if(i % BUF_SIZE != 0) {
        size = bfile_write(bfp, buf, i % BUF_SIZE);
        assert(size == i % BUF_SIZE);
    }
    bfile_close(bfp);
}