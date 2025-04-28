#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <msxlib/bfile.h>
#include "fcomp.h"

/*
long heap;
*/

#define BUF_SIZE    1024
#define FILE_BUF_SIZE   2048
#define FILE_BUF_SIZE2   256
char buf[BUF_SIZE];

#define FILE1   "testorg.bin"
#define FILE2   "test.bin"

int test1(void)
{
    printf("Write file(1):");
    FILE *fp = fopen(FILE1, "wb");
    if(!fp) {
        printf("fopen error\n");
        return 1;
    }
    BFILE_DOS2 *fp2 = bfile_create_dos2(FILE2, FILE_BUF_SIZE);
    if(!fp2) {
        printf("bfile_create_dos2 error\n");
        return 1;
    }

    for(int j = 0; j < 64; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        fwrite(buf, 1, BUF_SIZE, fp);
        bfile_write_dos2(fp2, buf, (int16_t)BUF_SIZE);
    }

    fclose(fp);
    bfile_close_dos2(fp2);

    printf("End\nCompare:");
    assert(fcomp(FILE1, FILE2) == 0);
    printf("OK\n");

    return 0;
}

int test2(void)
{
    printf("Write file(2):");
    FILE *fp = fopen(FILE1, "wb");
    BFILE_DOS2 *fp2 = bfile_create_dos2(FILE2, FILE_BUF_SIZE2);
    if(!fp2) {
        printf("error\n");
        return 0;
    }

    for(int j = 0; j < 32; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        int wsize = (rand() % BUF_SIZE) + 1;
        fwrite(buf, 1, wsize, fp);
        bfile_write_dos2(fp2, buf, (int16_t)wsize);
    }
    for(int j = 0; j < 32; j++) {
        for(int i = 0; i < BUF_SIZE; i++) {
            buf[i] = rand() % 256;
        }
        int wsize = (rand() % FILE_BUF_SIZE2) + FILE_BUF_SIZE2;
        fwrite(buf, 1, wsize, fp);
        bfile_write_dos2(fp2, buf, (int16_t)wsize);
    }

    fclose(fp);
    bfile_close_dos2(fp2);

    printf("End\nCompare:");
    assert(fcomp(FILE1, FILE2) == 0);
    printf("OK\n");

    return 0;
}

int main(void)
{
/*
    mallinit();
    sbrk((void*)0x8000,16 * 1024); 
*/
    srand((unsigned int)time(NULL));

    dos_scode(1);

    test1();
    test2();

    dos_scode(0);
    
    return 0;
}