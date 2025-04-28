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

/*
long heap;
*/

static void test022_1();
static void test022_2();
static void test022_3();
static void test022_4();
static void test022_5();
static void test022_6();
static void test022_7();

int main()
{
/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024); 
*/

    dos_scode(1);

    test022_1();
    test022_2();
    test022_3();
    test022_4();
    test022_5();
    test022_6();
    test022_7();

    dos_scode(0);

    return 0;
}

static void test022_1()
{
    MSX_FCB fcb;

    printf("FCB_REN test:");

    assert(&fcb.ren.new_drive - &fcb == 16);

    printf("OK\n");
}

static void test022_2()
{
    MSX_FCB fcb;
    BOOL ret;

    printf("msx_fcb_init_ren test:");

    ret = msx_fcb_init_ren(&fcb, "b:abc.txt", "def.bin");
    assert(ret);
    assert(fcb.ren.old_drive == 2);
    assert(memcmp(fcb.ren.old_name, "ABC     TXT", 11) == 0);
    assert(memcmp(fcb.ren.new_name, "DEF     BIN", 11) == 0);

    printf("OK\n");
}

static void test022_3()
{
    BFILE *file;
    BOOL bret;
    MSX_FCB fcb;

    printf("dos1_rename() test1:");

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);

    file = bfile_create("hoge.txt", BUF_SIZE);
    assert(file);
    bfile_close(file);

    bret = dos1_rename("hoge.txt", "hoge2.txt");
    assert(bret);

    file = bfile_open("hoge.txt", BFILE_O_RDONLY, BUF_SIZE);
    assert(file == NULL);

    file = bfile_open("hoge2.txt", BFILE_O_RDONLY, BUF_SIZE);
    assert(file != NULL);
    bfile_close(file);

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    
    printf("OK\n");
}

static void test022_4()
{
    BFILE *file;
    BOOL bret;
    MSX_FCB fcb;

    printf("dos1_rename() test2:");

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);

    file = bfile_create("hoge.txt", BUF_SIZE);
    assert(file);
    bfile_close(file);
    file = bfile_create("hoge2.txt", BUF_SIZE);
    assert(file);
    bfile_close(file);

    bret = dos1_rename("hoge.txt", "hoge2.txt");
    assert(!bret);

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    
    printf("OK\n");
}

static void test022_5()
{
    BFILE *file;
    BOOL bret;
    MSX_FCB fcb;

    printf("dos1_rename() test3:");

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);

    bret = dos1_rename("hoge.txt", "hoge2.txt");
    assert(!bret);

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    
    printf("OK\n");
}

static void test022_6()
{
    BFILE *file;
    BOOL bret;
    MSX_FCB fcb;
    int ret;

    printf("dos1_rename() test4:");

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aoge.bin");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aoge2.bin");
    dos1_fdel(&fcb);

    file = bfile_create("hoge.txt", BUF_SIZE);
    assert(file);
    bfile_write(file, "123", 3);
    ret = bfile_close(file);
    assert(ret == 0);
    file = bfile_create("hoge2.txt", BUF_SIZE);
    assert(file);
    bfile_write(file, "123", 3);
    ret = bfile_close(file);
    assert(ret == 0);

    bret = dos1_rename("h*.txt", "a*.bin");
    assert(bret);

    file = bfile_open("aoge.bin", BFILE_O_RDONLY, BUF_SIZE);
    assert(file);
    bfile_close(file);
    file = bfile_open("aoge2.bin", BFILE_O_RDONLY, BUF_SIZE);
    assert(file);
    bfile_close(file);

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aoge.bin");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aoge2.bin");
    dos1_fdel(&fcb);
    
    printf("OK\n");
}

static void test022_7()
{
    BFILE *file;
    BOOL bret;
    MSX_FCB fcb;
    int ret;

    printf("dos1_rename() test5:");

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aaae.bin");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aaae2.bin");
    dos1_fdel(&fcb);

    file = bfile_create("hoge.txt", BUF_SIZE);
    assert(file);
    bfile_write(file, "123", 3);
    ret = bfile_close(file);
    assert(ret == 0);
    file = bfile_create("hoge2.txt", BUF_SIZE);
    assert(file);
    bfile_write(file, "123", 3);
    ret = bfile_close(file);
    assert(ret == 0);

    bret = dos1_rename("h*.txt", "aaa*.bin");
    assert(bret);

    file = bfile_open("aaae.bin", BFILE_O_RDONLY, BUF_SIZE);
    assert(file);
    bfile_close(file);
    file = bfile_open("aaae2.bin", BFILE_O_RDONLY, BUF_SIZE);
    assert(file);
    bfile_close(file);

    msx_fcb_init(&fcb, "hoge.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "hoge2.txt");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aaae.bin");
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, "aaae2.bin");
    dos1_fdel(&fcb);
    
    printf("OK\n");
}
