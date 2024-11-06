#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

long heap;

#define TEST_FILE       "test.txt"

int test1(void)
{
    MSX_FCB fcb;
    uint8_t ret;

    printf("dos1_fdel test1:");

    msx_fcb_init(&fcb, TEST_FILE);

    ret = dos1_fmake(&fcb);
    assert(ret == 0);
    ret = dos1_fclose(&fcb);
    assert(ret == 0);

    msx_fcb_init(&fcb, TEST_FILE);

    ret = dos1_fdel(&fcb);
    assert(ret == 0);
    ret = dos1_fopen(&fcb);
    assert(ret != 0);
    
    ret = dos1_fdel(&fcb);
    assert(ret != 0);

    printf("OK\n");

    return 0;
}

int main(void)
{
    mallinit();
    sbrk((void*)0x8000,16 * 1024); 

    srand((unsigned int)time(NULL));

#ifndef __CPM__
    dos_scode(1);
#endif
    test1();

#ifndef __CPM__
    dos_scode(0);
#endif
    return 0;
}