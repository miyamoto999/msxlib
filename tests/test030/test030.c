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
    uint16_t year, year2;
    uint8_t month, mday, wday;
    uint8_t month2, mday2, wday2;
    uint8_t ret;

    printf("dos1_sdate() test:");
    dos1_gdate(&year, &month, &mday, &wday);

    ret = dos1_sdate(2000,1,10);
    assert(ret == 0);
    dos1_gdate(&year2, &month2, &mday2, &wday);
    assert(year2 == 2000);
    assert(month2 == 1);
    assert(mday2 == 10);
    ret = dos1_sdate(2024,2,29);
    assert(ret == 0);
    ret = dos1_sdate(2024,14,29);
    assert(ret == 0xff);
    ret = dos1_sdate(2023,2,29);
    assert(ret == 0xff);

    dos1_sdate(year, month, mday);

    printf("OK\n");
}
