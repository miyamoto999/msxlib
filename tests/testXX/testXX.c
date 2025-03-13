#include <msxlib/msxdos.h>
#include <stdio.h>
#include <stdio.h>
#ifndef __VSCODE__
#include <unistd.h>
#endif
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

// long heap;

#define TEST_FILE1 "test1.bin"
#define TEST_FILE2 "test2.bin"
#define TEST_FILE3 "test3.bin"

#ifdef __VSCODE__
#define mallinit() 
#define sbrk(a, b) 

#endif

#ifndef S_IRWXU
#define S_IRWXU (_S_IREAD | _S_IWRITE | _S_IEXEC)
#endif

static void test1()
{
    int fd;
    char data = 33;

    fd = creat(TEST_FILE1, S_IRWXU);
    printf("fd = %d\n", fd);
    if(fd < 0) {
        printf("Error creating file\n");
        return;
    }
    int size = write(fd, &data, 1);
    if(size < 0) {
        printf("write error\n", errno);
        close(fd);
        return;
    }
    close(fd);
}

static void test2()
{
    FILE *fp;
    char data = 33;

    fp = fopen(TEST_FILE2, "wb");
    if(!fp) {
        printf("Error creating file\n");
        return;
    }
    int ret = fwrite(&data, 1, 1, fp);
    if(ret < 0) {
        printf("fwrite error\n");
        fclose(fp);
        return;
    }
    fclose(fp);
}

void test3()
{
    int fd;
    char data = 44;

    fd = open(TEST_FILE3, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    printf("fd = %d\n", fd);
    if(fd < 0) {
        printf("open error\n");
        return;
    }

    int size = write(fd, &data, 1);
    if(size < 0) {
        printf("write error\n");

        return;
    }
    close(fd);
    return;
}

int main(void) 
{
    // mallinit();
    // sbrk((void*)0x8000, 8 * 1024); 

    unlink(TEST_FILE1);
    unlink(TEST_FILE2);

    char *buf = malloc(1024);
    if(buf) {
        printf("malloc success = 0x%x\n", buf);
        free(buf);
    } else {
        printf("malloc failed\n");
    }
    
#ifdef __MSXDOS1
    printf("MSX-DOS1\n");
#elif defined(__MSXDOS2)
    printf("MSX-DOS2\n");
#else 
    printf("MSX-DOS not detected\n");
#endif
#ifdef __MSXDOS_MSXDOS1
    printf("MSX-DOS1\n");
#elif defined(__MSXDOS_MSXDOS2)
    printf("MSX-DOS2\n");
#else 
    printf("MSX-DOS not detected\n");
#endif
#ifdef __MSX__
    printf("__MSX__\n");
#else
    printf("not __MSX__\n");
#endif
#ifdef __MSX2__
    printf("__MSX2__\n");
#else
    printf("not __MSX2__\n");
#endif
#ifdef __MSXDOS
    printf("__MSXDOS\n");
#else
    printf("not __MSXDOS\n");
#endif

    char *buf2 = "DOS1 _CONOUT\x0d\x0a";
    for(int i = 0; buf2[i]; i++) {
        dos1_conout(buf2[i]);
    }

#if __MSXDOS__ == 2
    uint16_t size;
    char *buf3 = "DOS2 stdout\x0d\x0a";
    dos2_write(1, buf3, strlen(buf3), &size);
#endif

    float f = 1.1;
    printf("f = %f\n", f);

    printf("## test1()\n");
    test1();
    printf("## test2()\n");
    test2();
    printf("## test3()\n");
    test3();
    printf("## end\n");

    write(0, "hoge", 4);
    return 0;
}

