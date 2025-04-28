#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <msxlib/bfile.h>

#define TEST_FILENAME   "test1.txt"
#define BUF_SIZE        256
#define BUF_SIZE2       15
#define TEST1_SIZE      20

static char buf[BUF_SIZE];

/*
long heap;
*/

static void make_testfile1(void)
{
    BFILE_DOS1 *fp = bfile_create_dos1(TEST_FILENAME, BUF_SIZE);
    assert(fp);
    for(int i = 0; i < TEST1_SIZE; i++) {
        char ch = (i % 10) + '0';
        int16_t ret = bfile_write_dos1(fp, &ch, 1);
        assert(ret == 1);
    }
    bfile_close_dos1(fp);
}

static int test1(void)
{
    printf("bfile_read_dos1 test1:");

    BFILE_DOS1 *fp = bfile_open_dos1(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE);
    assert(fp);
    int16_t ret = bfile_read_dos1(fp, buf, BUF_SIZE);
    assert(ret == TEST1_SIZE);
    ret = bfile_read_dos1(fp, buf, BUF_SIZE);
    assert(ret == 0);
    for(int i = 0; i < TEST1_SIZE; i++) {
        assert(buf[i] == (i % 10) + '0');
    }

    bfile_close_dos1(fp);

    printf("OK\n");
    return 0;
}

static int test2(void)
{
    printf("bfile_read_dos1 test2:");

    BFILE_DOS1 *fp = bfile_open_dos1(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE2);
    assert(fp);
    int8_t ret = bfile_read_dos1(fp, buf, BUF_SIZE);
    assert(ret == TEST1_SIZE);
    ret = bfile_read_dos1(fp, buf, BUF_SIZE);
    assert(ret == 0);
    for(int i = 0; i < TEST1_SIZE; i++) {
        assert(buf[i] == (i % 10) + '0');
    }

    bfile_close_dos1(fp);

    printf("OK\n");
    return 0;
}

int main(void)
{
/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 
*/
    MSX_FCB fcb;
    uint16_t addr = *((uint16_t *)0x0006);

    dos_scode(1);

    make_testfile1();
    test1();
    test2();

    dos_scode(0);

    msx_fcb_init(&fcb, TEST_FILENAME);
    dos1_fdel(&fcb);

    return 0;
}