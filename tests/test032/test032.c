#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

long heap;
static void test1(void);


int main()
{
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
    
    dos_scode(1);

    test1();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t ret;
    uint8_t hour, min, sec;
    uint8_t hour2, min2, sec2;

    printf("dos1_stime() test:");
    dos1_gtime(&hour, &min, &sec);

    ret = dos1_stime(50,0,0);
    assert(ret == 0xff);
    ret = dos1_stime(12,70,0);
    assert(ret == 0xff);
    ret = dos1_stime(12,10,80);
    assert(ret == 0xff);
    ret = dos1_stime(12,34,0);
    assert(ret == 0);
    dos1_gtime(&hour2, &min2, &sec2);
    assert(hour2 == 12);
    assert(min2 == 34);
    assert(sec2 <= 2);

    dos1_stime(hour, min, sec);

    printf("OK\n");
}
