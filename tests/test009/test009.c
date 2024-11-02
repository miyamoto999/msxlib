#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxdos.h>

static int test1(void)
{
    char *last_str = NULL;
    char *start_filename = NULL;
    uint8_t drv = 0;
    uint8_t flag = 0;
    uint8_t ret;

    printf("dos2_parse test1:");
    ret = dos2_parse("test.txt", 0, &last_str, &start_filename, &flag, &drv);
    assert(ret == 0);
    assert(strlen(last_str) == 0);
    assert(strcmp(start_filename, "test.txt") == 0);
    assert(flag == 0x19);
    assert(drv == 1);

    printf("OK\n");

    return 0;
}

static int test2(void)
{
    char *last_str = NULL;
    char *start_filename = NULL;
    uint8_t drv = 0;
    uint8_t flag = 0;
    uint8_t ret;

    printf("dos2_parse test2:");
    ret = dos2_parse("testhogehoge.txthogehogeho", 0, &last_str, &start_filename, &flag, &drv);
    assert(ret == 0);
    assert(strlen(last_str) == 0);
    assert(strcmp(start_filename, "testhogehoge.txthogehogeho") == 0);
    assert(flag == 0x19);
    assert(drv == 1);

    printf("OK\n");

    return 0;
}

static int test3(void)
{
    char *last_str = NULL;
    char *start_filename = NULL;
    uint8_t drv = 0;
    uint8_t flag = 0;
    uint8_t ret;

    printf("dos2_parse test3:");
    ret = dos2_parse("c:\\hoge\\hoge.a", 0, &last_str, &start_filename, &flag, &drv);
    assert(ret == 0);
    assert(strlen(last_str) == 0);
    assert(strcmp(start_filename, "hoge.a") == 0);
    assert(flag == 0x1f);
    assert(drv == 3);

    printf("OK\n");

    return 0;
}

static int test4(void)
{
    char *last_str = NULL;
    char *start_filename = NULL;
    uint8_t drv = 0;
    uint8_t flag = 0;
    uint8_t ret;

    printf("dos2_parse test4:");
    ret = dos2_parse("c:\\hoge\\aaa\\", 0, &last_str, &start_filename, &flag, &drv);
    assert(ret == 0);
    assert(strlen(last_str) == 0);
    assert(strlen(start_filename) == 0);
    assert(flag == 0x07);
    assert(drv == 3);

    printf("OK\n");

    return 0;
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}