#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

/*
long heap;
*/
static void test1(void);


int main()
{
/*
    mallinit();
    sbrk((void*)0x8000, 8 * 1024);
*/    
    dos_scode(1);

    test1();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint8_t hour, min, sec;

    dos1_gtime(&hour, &min, &sec);
    printf("%02u:%02u:%02u\n", hour, min, sec);
}
