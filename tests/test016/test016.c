#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <msxlib/bfile.h>

#define TEST_FILENAME   "test.txt"
#define BUF_SIZE        256

static char buf[BUF_SIZE];

/*
long heap;
*/

static int test1(void)
{
    BFILE *fp;
    int16_t size;
    int32_t pos;

    printf("bfile_fseek test1:");
    fp = bfile_create(TEST_FILENAME, BUF_SIZE);
    assert(fp);

    for(int i = 0; i < 20; i++) {
        buf[i] = (i % 10) + '0'; 
    }
    size = bfile_write(fp, buf, 20);
    assert(size == 20);
    pos = bfile_fseek(fp, 30, BFILE_SEEK_CUR);
    assert(pos == 50);
    for(int i = 0; i < 20; i++) {
        buf[i] = (i % 10) + 'A'; 
    }
    size = bfile_write(fp, buf, 10);
    assert(size == 10);
    bfile_close(fp);

    /* チェック */
    fp = bfile_open(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE);
    assert(fp);
    size = bfile_read(fp, buf, BUF_SIZE);
    assert(size == 60);
    for(int i = 0; i < 60; i++) {
        if(i < 20) {
            assert(buf[i] == (i % 10) + '0');
        } else if (i < 50) {
            assert(buf[i] == 0);
        } else {
            assert(buf[i] == ((i - 50) % 10) + 'A');
        }
    }
    bfile_close(fp);

    printf("OK\n");

    return 0;
}

static int test2(void)
{
    BFILE *fp;
    int16_t size;
    int32_t pos;

    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = i;
    }
    printf("bfile_fseek test2:");
    fp = bfile_create(TEST_FILENAME, BUF_SIZE);
    assert(fp);

    size = bfile_write(fp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    pos = bfile_fseek(fp, 10, BFILE_SEEK_SET);
    assert(pos == 10);
    size = bfile_write(fp, &buf[20], 10);
    assert(size == 10);
    
    /* このままリードチェック(たぶｆんエラー) */
    pos = bfile_fseek(fp, 0, BFILE_SEEK_SET);
    assert(pos == 0);
    size = bfile_read(fp, buf, BUF_SIZE);
    assert(size == 0);
    assert(bfile_error(fp) != 0);

    bfile_close(fp);

    /* チェック */
    fp = bfile_open(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE);
    assert(fp);
    size = bfile_read(fp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    for(int i = 0; i < BUF_SIZE; i++) {
        if(i >= 10 && i < 20) {
            assert(buf[i] == (char)(i - 10 + 20));
        } else {
            assert(buf[i] == (char)i);
        }
    }
    bfile_close(fp);

    printf("OK\n");

    return 0;
}

static int test3(void)
{
    BFILE *fp;
    int16_t size;
    int32_t pos;

    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = i;
    }
    printf("bfile_fseek test3:");
    fp = bfile_create(TEST_FILENAME, BUF_SIZE);
    assert(fp);
    size = bfile_write(fp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    bfile_close(fp);

    fp = bfile_open(TEST_FILENAME, BFILE_O_RDWR, BUF_SIZE);
    assert(fp);
    pos = bfile_fseek(fp, -100, BFILE_SEEK_END);
    assert(pos == BUF_SIZE - 100);
    size = bfile_write(fp, buf, BUF_SIZE);
    assert(size == BUF_SIZE);
    /* RDWRリードチェック */
    pos = bfile_fseek(fp, -100, BFILE_SEEK_CUR);
    assert(pos == BUF_SIZE * 2 - 100 - 100);
    size = bfile_read(fp, buf, BUF_SIZE);
    assert(size == 100);
    for(int i = 0; i < 100; i++) {
        assert(buf[i] == (char)(BUF_SIZE - 100 + i));
    }
    bfile_close(fp);

    /* チェック */
    fp = bfile_open(TEST_FILENAME, BFILE_O_RDONLY, BUF_SIZE);
    assert(fp);
    for(int i = 0; i < BUF_SIZE * 2 - 100; i++) {
        char ch;
        size = bfile_read(fp, &ch, 1);
        assert(size == 1);
        if(i >= BUF_SIZE - 100) {
            assert(ch == (char)(i - (BUF_SIZE - 100)));
        } else {
            assert(ch == (char)i);
        }
    }
    bfile_close(fp);

    printf("OK\n");

    return 0;
}

int main(void)
{
/*
    mallinit();
#ifdef __DSKBAS__
    sbrk((void*)0xc000, 1024); 
#else
    sbrk((void*)0x8000, 8 * 1024); 
#endif
*/
    dos_scode(1);

#if __DSKBAS__ == 1
    puts("DSKBAS1 Version");
#elif __DSKBAS__ == 2
    puts("DSKBAS2 Version");
#elif defined(__CPM__)
    puts("CP/M Version");
#elif __MSXDOS__ == 1
    puts("DOS1 Version");
#elif __MSXDOS__ == 2
    puts("DOS2 Version");
#endif

    test1();
    test2();
    test3();

    dos_scode(0);

    MSX_FCB fcb;
    msx_fcb_init(&fcb, TEST_FILENAME);
    dos1_fdel(&fcb);

    return 0;
}