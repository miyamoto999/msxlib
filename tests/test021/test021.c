#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcb.h>
#include <msxlib/bfile.h>

#define BUF_SIZE    128
#define TEST_FILE   "test.bin"
static char buf[BUF_SIZE];

long heap;

int main()
{
    MSX_FCB fcb;
    BFILE_DOS1 *bfp;
    int size;
    int8_t ret;

    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 

    dos_scode(1);

    printf("write start\n");
    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = i;
    }

    bfp = bfile_create_dos1(TEST_FILE, BUF_SIZE);
    assert(bfp != NULL);
    size = bfile_write_dos1(bfp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = i + BUF_SIZE;
    }
    size = bfile_write_dos1(bfp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    bfile_close_dos1(bfp);
    printf("write end\n");
    
    printf("read check start\n");
    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fopen(&fcb);
    assert(ret == 0);
    dos1_setdta(buf);
    memset(buf, 0, BUF_SIZE);
    ret = dos1_rdseq(&fcb);
    assert(ret == 0);
    for(int i = 0; i < BUF_SIZE; i++) {
        assert(buf[i] == i);
    }
    memset(buf, 0, BUF_SIZE);
    ret = dos1_rdseq(&fcb);
    assert(ret == 0);
    for(int i = 0; i < BUF_SIZE; i++) {
        assert(buf[i] == (i + BUF_SIZE) & 0xff);
    }
    memset(buf, 0, BUF_SIZE);
    ret = dos1_rdseq(&fcb);
    assert(ret == 1);
    ret = dos1_fclose(&fcb);
    assert(ret == 0);
    printf("read check end\n");

    printf("test file del\n");
    msx_fcb_init(&fcb, TEST_FILE);
    ret = dos1_fdel(&fcb);
    assert(ret == 0);
    printf("test file del end\n");

    dos_scode(0);

    return 0;
}