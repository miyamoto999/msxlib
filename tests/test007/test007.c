#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <msxlib/bfile.h>
#include "fcomp.h"

long heap;

#define BUF_SIZE    1024
#define FILE_BUF_SIZE   2048
#define FILE_BUF_SIZE2   256
char buf[BUF_SIZE];

#define FILE1   "testorg.bin"
#define FILE2   "test.bin"

int test1(void)
{
    MSX_FCB fcb;

    printf("Write file(1):");

    msx_fcb_init(&fcb, FILE1);
    dos1_fmake(&fcb);
    fcb.v1.record_size = 1;
    fcb.v1.random_record = 0;

    BFILE_DOS1 *fp2 = bfile_create_dos1(FILE2, FILE_BUF_SIZE);
    if(!fp2) {
        printf("error\n");
        return 0;
    }

    for(int j = 0; j < 64; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        dos1_setdta(buf);
        dos1_wrblk(&fcb, BUF_SIZE);
        bfile_write_dos1(fp2, buf, (int16_t)BUF_SIZE);
    }

    dos1_fclose(&fcb);
    bfile_close_dos1(fp2);

    printf("End\nCompare:");
    assert(fcomp(FILE1, FILE2) == 0);
    printf("OK\n");

    return 0;
}

int test2(void)
{
    MSX_FCB fcb;

    printf("Write file(2):");

    msx_fcb_init(&fcb, FILE1);
    dos1_fmake(&fcb);
    fcb.v1.record_size = 1;
    fcb.v1.random_record = 0;

    BFILE_DOS1 *fp2 = bfile_create_dos1(FILE2, FILE_BUF_SIZE2);
    if(!fp2) {
        printf("error\n");
        return 0;
    }

    for(int j = 0; j < 32; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        int wsize = (rand() % BUF_SIZE) + 1;

        dos1_setdta(buf);
        dos1_wrblk(&fcb, wsize);
        bfile_write_dos1(fp2, buf, (int16_t)wsize);
    }
    for(int j = 0; j < 32; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        int16_t wsize = (rand() % FILE_BUF_SIZE2) + FILE_BUF_SIZE2;
        dos1_setdta(buf);
        dos1_wrblk(&fcb, wsize);
        bfile_write_dos1(fp2, buf, (int16_t)wsize);
    }

    dos1_fclose(&fcb);
    bfile_close_dos1(fp2);
 
    printf("End\nCompare:");
    assert(fcomp(FILE1, FILE2) == 0);
    printf("OK\n");

    return 0;
}

int test3(void)
{
    MSX_FCB fcb;

    printf("Write file(3):");

    msx_fcb_init(&fcb, FILE1);
    dos1_fmake(&fcb);
    fcb.v1.record_size = 1;
    fcb.v1.random_record = 0;

    BFILE_DOS1 *fp2 = bfile_create_dos1(FILE2, FILE_BUF_SIZE2);
    if(!fp2) {
        printf("error\n");
        return 0;
    }

    for(int j = 0; j < 32; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        dos1_setdta(buf);
        dos1_wrblk(&fcb, BUF_SIZE);
        bfile_write_dos1(fp2, buf, BUF_SIZE);
    }
    for(int i = 0; i < BUF_SIZE; i++) {
        buf[i] = rand() % 256;
    }
    dos1_setdta(buf);
    dos1_wrblk(&fcb, 23);
    bfile_write_dos1(fp2, buf, 23);

    dos1_fclose(&fcb);
    bfile_close_dos1(fp2);
 
    printf("End\nCompare:");
    assert(fcomp(FILE1, FILE2) == 0);
    printf("OK\n");

    return 0;
}

int main(void)
{
    MSX_FCB fcb;

    mallinit();
    sbrk((void*)0x8000,16 * 1024); 

    srand((unsigned int)time(NULL));

    dos_scode(1);

    test1();
    test2();
    test3();

    dos_scode(0);

    msx_fcb_init(&fcb, FILE1);
    dos1_fdel(&fcb);
    msx_fcb_init(&fcb, FILE2);
    dos1_fdel(&fcb);

    return 0;
}