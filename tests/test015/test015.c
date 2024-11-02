#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <msxlib/bfile.h>

#define TEST_FILENAME   "test1.txt"
#define BUF_SIZE        256
#define BUF_SIZE2       15
#define TEST1_SIZE      20

static char buf[BUF_SIZE];

long heap;

static void make_testfile1(void)
{
    BFILE_DOS2 *fp = bfile_create_dos2(TEST_FILENAME, BUF_SIZE);
    assert(fp);
    for(int i = 0; i < TEST1_SIZE; i++) {
        char ch = (i % 10) + '0';
        int16_t ret = bfile_write_dos2(fp, &ch, 1);
        assert(ret == 1);
    }
    bfile_close_dos2(fp);
}

static int test1(void)
{
    printf("bfile_read_dos2 test1:");

    BFILE_DOS2 *fp = bfile_open_dos2(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE);
    assert(fp);
    int16_t ret = bfile_read_dos2(fp, buf, BUF_SIZE);
    assert(ret == TEST1_SIZE);
    ret = bfile_read_dos2(fp, buf, BUF_SIZE);
    assert(ret == 0);
    for(int i = 0; i < TEST1_SIZE; i++) {
        assert(buf[i] == (i % 10) + '0');
    }

    bfile_close_dos2(fp);

    printf("OK\n");
    return 0;
}

static int test2(void)
{
    printf("bfile_read_dos2 test2:");

    BFILE_DOS2 *fp = bfile_open_dos2(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE2);
    assert(fp);
    int8_t ret = bfile_read_dos2(fp, buf, BUF_SIZE);
    assert(ret == TEST1_SIZE);
    ret = bfile_read_dos2(fp, buf, BUF_SIZE);
    assert(ret == 0);
    for(int i = 0; i < TEST1_SIZE; i++) {
        assert(buf[i] == (i % 10) + '0');
    }

    bfile_close_dos2(fp);

    printf("OK\n");
    return 0;
}

int main(void)
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 

    uint16_t addr = *((uint16_t *)0x0006);

    make_testfile1();
    test1();
    test2();

    return 0;
}