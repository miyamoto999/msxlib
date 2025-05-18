#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifdef __GNUC__
#define dos_scode(a)
#define dos1_fclose(f)
#define dos1_fopen(f)
#define msx_fcb_init(a, b)
#endif

#define TEST_FILE "test.bin"
#define TEST_FILE2 "test2.bin"
const char *str = "Hello, world!\n";
#define BUF_SIZE 128
char buf[BUF_SIZE];
static MSX_FCB fcb;

int test1(void)
{
    FILE *fp;
    int len = strlen(str);

    printf("test055:fopen & fwrite test:");
    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    int size = fwrite(str, 1, len, fp);
    assert(size == len);
    fclose(fp);

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    printf("OK\n");

    return 0;
}

int test3(void) {
    FILE *fp;
    int len = strlen(str);

    printf("test055:fread test:");

    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    int size = fwrite(str, 1, len, fp);
    assert(size == len);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == len);
    assert(memcmp(buf, str, len) == 0);
    fclose(fp);

    remove(TEST_FILE);

    printf("OK\n");

    return 0;
}

int test4(void) {
    FILE *fp;
    int len = strlen(str);
    int size;
    int ret;

    printf("test055:fseek test1:");

    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    ret = fseek(fp, 0, SEEK_SET);
    assert(ret == 0);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == 0);
    size = fwrite("hoge", 1, 4, fp);
    assert(size == 4);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == 0);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == len);
    assert(memcmp(buf, "hogeo, world!\n", len) == 0);
    fclose(fp);

    printf("OK\n");

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    return 0;
}

int test5(void) {
    FILE *fp;
    int len = strlen(str);
    int size;
    int ret;

    printf("test055:fseek test2:");

    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    ret = fseek(fp, 0, SEEK_CUR);
    assert(ret == 0);
    size = fwrite("hoge", 1, 4, fp);
    assert(size == 4);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == len + 4);
    assert(memcmp(buf, "Hello, world!\nhoge", len + 4) == 0);
    fclose(fp);

    printf("OK\n");

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len + 4);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    return 0;
}

int test6(void) {
    FILE *fp;
    int len = strlen(str);
    int size;
    int ret;

    printf("test055:fseek test3:");

    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    ret = fseek(fp, 10, SEEK_CUR);
    assert(ret == 0);
    size = fwrite("hoge", 1, 4, fp);
    assert(size == 4);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == len + 4 + 10);
    assert(memcmp(buf, str, len) == 0);
    assert(memcmp(buf + len + 10, "hoge", 4) == 0);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fread(buf, 1, len, fp);
    assert(size == len);
    assert(memcmp(buf, str, len) == 0);
    ret = fseek(fp, 10, SEEK_CUR);
    assert(ret == 0);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == 4);
    assert(memcmp(buf, "hoge", 4) == 0);

    ret = fseek(fp, len + 10, SEEK_SET);
    assert(ret == 0);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == 4);
    assert(memcmp(buf, "hoge", 4) == 0);
    fclose(fp);

    printf("OK\n");

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len + 4 + 10);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    return 0;
}

int test7(void)
{
    FILE *fp;
    int len = strlen(str);
    int size;
    int ret;

    printf("test055:fseek test4:");

    fp = fopen(TEST_FILE, "wb");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    ret = fseek(fp, 10, SEEK_CUR);
    assert(ret == 0);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == 0);
    fclose(fp);

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);
#endif

    fp = fopen(TEST_FILE, "r+b");
    assert(fp != NULL);
    ret = fseek(fp, 0, SEEK_END);
    assert(ret == 0);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    fclose(fp);

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len * 2);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    printf("OK\n");

    return 0;
}

int test8(void)
{
    FILE *fp;
    int len = strlen(str);
    int size;
    long pos;
    fpos_t fpos;
    int ret;

    printf("test055:fopen(\"ab\") test:");

    remove(TEST_FILE);

    fp = fopen(TEST_FILE, "ab");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    fclose(fp);

    fp = fopen(TEST_FILE, "ab");
    assert(fp != NULL);
    size = fwrite(str, 1, len, fp);
    assert(size == len);
    fclose(fp);

    fp = fopen(TEST_FILE, "rb");
    assert(fp != NULL);
    size = fread(buf, 1, BUF_SIZE, fp);
    assert(size == len * 2);
    assert(memcmp(buf, str, len) == 0);
    assert(memcmp(buf + len, str, len) == 0);

    ret = fgetpos(fp, &fpos);
    assert(ret == 0);
    assert(fpos == len * 2);

    pos = ftell(fp);
    assert(pos == len * 2);

    fclose(fp);

#ifndef __GNUC__
    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len * 2);
    dos1_fclose(&fcb);
#endif
    remove(TEST_FILE);

    printf("OK\n");

    return 0;
}

int test9(void)
{
    FILE *fp;

    printf("test055:fopen test:");

    remove(TEST_FILE2);

    fp = fopen(TEST_FILE2, "rb");
    assert(fp == NULL);
 
    remove(TEST_FILE2);

    printf("OK\n");
    return 0;
}

int main(void)
{
    dos_scode(1);

    test1();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    dos_scode(0);
}


