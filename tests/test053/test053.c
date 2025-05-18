#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcntl.h>
#include <msxlib/time.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

#define TEST_FILE "test.bin"
#define TEST_FILE2 "test2.bin"
const char *str = "Hello, world!\n";
#define BUF_SIZE 128
char buf[BUF_SIZE];
static MSX_FCB fcb;

int test1(void) {
    int fd;
    int len = strlen(str);

    printf("test053:creat & write test:");
    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    int size = write(fd, str, len);
    assert(size == len);
    assert(fsync(fd) == 0);
    close(fd);

    assert(fsync(fd) == -1);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);


    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    printf("OK\n");

    return 0;
}

int test2(void) {
    int fd;
    int len = strlen(str);

    printf("test053:open(create) & write test:");

    fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0);
    assert(fd != -1);
    int size = write(fd, str, len);
    assert(size == len);
    close(fd);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);


    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    printf("OK\n");

    return 0;
}

int test3(void) {
    int fd;
    int len = strlen(str);

    printf("test053:read test:");

    fd = open(TEST_FILE,  O_WRONLY | O_CREAT | O_TRUNC, 0);
    assert(fd != -1);
    int size = write(fd, str, len);
    assert(size == len);
    close(fd);

    fd = open(TEST_FILE,  O_RDONLY, 0);
    assert(fd != -1);
    size = read(fd, buf, BUF_SIZE);
    assert(fsync(fd) == -1);
    assert(size == len);
    assert(memcmp(buf, str, len) == 0);
    close(fd);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    printf("OK\n");

    return 0;
}

int test4(void) {
    int fd;
    int len = strlen(str);
    int size;
    long pos;

    printf("test053:lseek test1:");

    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    pos = lseek(fd, 0, SEEK_SET);
    assert(pos == 0);
    size = read(fd, buf, BUF_SIZE);
    assert(size == -1);
    size = write(fd, "hoge", 4);
    assert(size == 4);
    close(fd);

    fd = open(TEST_FILE,  O_RDONLY, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == -1);
    size = read(fd, buf, BUF_SIZE);
    assert(size == len);
    assert(memcmp(buf, "hogeo, world!\n", len) == 0);
    close(fd);

    printf("OK\n");

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    return 0;
}

int test5(void) {
    int fd;
    int len = strlen(str);
    int size;
    long pos;

    printf("test053:lseek test2:");

    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    pos = lseek(fd, 0, SEEK_CUR);
    assert(pos == size);
    size = write(fd, "hoge", 4);
    assert(size == 4);
    close(fd);

    fd = open(TEST_FILE,  O_RDONLY, 0);
    assert(fd != -1);
    size = read(fd, buf, BUF_SIZE);
    assert(size == len + 4);
    assert(memcmp(buf, "Hello, world!\nhoge", len + 4) == 0);
    close(fd);

    printf("OK\n");

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len + 4);
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    return 0;
}

int test6(void) {
    int fd;
    int len = strlen(str);
    int size;
    long pos;

    printf("test053:lseek test3:");

    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    pos = lseek(fd, 10, SEEK_CUR);
    assert(pos == size + 10);
    size = write(fd, "hoge", 4);
    assert(size == 4);
    close(fd);

    fd = open(TEST_FILE, O_RDONLY, 0);
    assert(fd != -1);
    size = read(fd, buf, BUF_SIZE);
    assert(size == len + 4 + 10);
    assert(memcmp(buf, str, len) == 0);
    assert(memcmp(buf + len + 10, "hoge", 4) == 0);
    close(fd);

    fd = open(TEST_FILE, O_RDONLY, 0);
    assert(fd != -1);
    size = read(fd, buf, len);
    assert(size == len);
    assert(memcmp(buf, str, len) == 0);
    pos = lseek(fd, 10, SEEK_CUR);
    assert(pos == len + 10);
    size = read(fd, buf, BUF_SIZE);
    assert(size == 4);
    assert(memcmp(buf, "hoge", 4) == 0);

    pos = lseek(fd, len + 10, SEEK_SET);
    assert(pos == len + 10);
    size = read(fd, buf, BUF_SIZE);
    assert(size == 4);
    assert(memcmp(buf, "hoge", 4) == 0);
    close(fd);

    printf("OK\n");

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len + 4 + 10);
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    return 0;
}

int test7(void)
{
    int fd;
    int len = strlen(str);
    int size;
    long pos;

    printf("test053:lseek test4:");

    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    pos = lseek(fd, 10, SEEK_CUR);
    assert(pos == size + 10);
    size = read(fd, buf, BUF_SIZE);
    assert(size == -1);
    close(fd);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len);
    dos1_fclose(&fcb);

    fd = open(TEST_FILE, O_RDWR, 0);
    assert(fd != -1);
    pos = lseek(fd, 0, SEEK_END);
    assert(pos == len);
    size = write(fd, str, len);
    assert(size == len);
    close(fd);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len * 2);
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);
    
    printf("OK\n");

    return 0;
}

int test8(void)
{
    int fd;
    int len = strlen(str);
    int size;
    long pos;
    fpos_t fpos;

    printf("test053:open(creat O_APPEND) test:");

    fd = open(TEST_FILE, O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    close(fd);

    fd = open(TEST_FILE, O_WRONLY | O_APPEND, 0);
    assert(fd != -1);
    size = write(fd, str, len);
    assert(size == len);
    close(fd);

    fd = open(TEST_FILE, O_RDONLY, 0);
    assert(fd != -1);
    size = read(fd, buf, BUF_SIZE);
    assert(size == len * 2);
    assert(memcmp(buf, str, len) == 0);
    assert(memcmp(buf + len, str, len) == 0);

    int ret = fdgetpos(fd, &fpos);
    assert(ret == 0);
    assert(fpos == len * 2);

    pos = fdtell(fd);
    assert(pos == len * 2);

    close(fd);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fopen(&fcb);
    assert(fcb.v1.file_size == len * 2);
    dos1_fclose(&fcb);

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    printf("OK\n");

    return 0;
}

int test9(void)
{
    int fd;

    printf("test053:open test:");

    msx_fcb_init(&fcb, TEST_FILE2);
    dos1_fdel(&fcb);

    fd = open(TEST_FILE2, O_RDONLY, 0);
    assert(fd == -1);

    msx_fcb_init(&fcb, TEST_FILE2);
    dos1_fdel(&fcb);

    printf("OK\n");
    return 0;
}

int test10(void)
{
    uint16_t year;
    uint8_t mon, mday, wday;
    uint8_t hour, min, sec, prev_sec = 100;
    int fd;
    struct stat buf;

    printf("Wait...");
    while(prev_sec > 50) {
        dos1_gdate(&year, &mon, &mday, &wday);
        dos1_gtime(&hour, &min, &prev_sec);
    }
    printf("OK\n");
    
    printf("test053:stat test:");
    do {
        dos1_gdate(&year, &mon, &mday, &wday);
        dos1_gtime(&hour, &min, &sec);
    } while(sec == prev_sec);
    fd = creat(TEST_FILE, 0);
    assert(fd != -1);
    close(fd);

    int ret = stat(TEST_FILE, &buf);
    assert(ret == 0);
    assert(buf.st_mode == (S_IFREG | S_IRUSR | S_IWUSR | S_IXUSR \
                | S_IRGRP | S_IWGRP | S_IXGRP \
                | S_IROTH | S_IWOTH | S_IXOTH));
    assert(buf.st_size == 0);
    assert(buf.st_blksize == 512);
    struct tm *tm = localtime(&buf.st_mtime);
    assert(tm->tm_year + 1900 == year);
    assert(tm->tm_mon + 1 == mon);
    assert(tm->tm_mday == mday);
    assert(tm->tm_hour == hour);
    assert(tm->tm_min == min);
    assert(tm->tm_sec >= sec && tm->tm_sec < sec + 5);  /* ファイルの生成に時間がかかるんで5秒のマージンを用意している。 */

    msx_fcb_init(&fcb, TEST_FILE);
    dos1_fdel(&fcb);

    printf("OK\n");

    return 0;
}

int main(void)
{
    dos_scode(1);

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

    dos_scode(0);
    return 0;
}