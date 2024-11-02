#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <msxlib/bfile.h>

void test1(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(!ret);
    printf("OK\n");
}

void test2(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "  ";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(!ret);
    printf("OK\n");
}

void test3(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "a:hoge";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 1);
    assert(memcmp(fcb.v1.name, "HOGE       ", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

void test4(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "b:hoge.a";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 2);
    assert(memcmp(fcb.v1.name, "HOGE    A  ", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

void test5(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "c:hogehogehoge.abcdef";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 3);
    assert(memcmp(fcb.v1.name, "HOGEHOGEABC", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

void test6(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "hogehogehoge.abcdef";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 0);
    assert(memcmp(fcb.v1.name, "HOGEHOGEABC", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

void test7(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "1:hoge.txt";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(!ret);
    printf("OK\n");
}

void test8(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "hogehogehogehoge";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 0);
    assert(memcmp(fcb.v1.name, "HOGEHOGE   ", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

void test9(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = ".hoge";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(!ret);
    printf("OK\n");
}

void test10(void)
{
    MSX_FCB fcb;
    BOOL ret;
    const char *filename = "   a:hoge .txt";

    printf("fcb init:\"%s\":", filename);
    ret = msx_fcb_init(&fcb, filename);
    assert(ret);
    assert(fcb.v1.drive == 1);
    assert(memcmp(fcb.v1.name, "HOGE    TXT", FCB_NAME_SIZE + FCB_EXT_SIZE) == 0);
    printf("OK\n");
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}

