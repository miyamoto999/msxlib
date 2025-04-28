#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

static void test1(void);

const char *str_wday[] = {
    "Sun.",
    "Mon.",
    "Tue.",
    "Wed.",
    "Thu.",
    "Fri.",
    "Sta."
};

int main()
{
    dos_scode(1);

    test1();

    dos_scode(0);

    return 0;
}

static void test1(void)
{
    uint16_t year;
    uint8_t month, mday, wday;

    dos1_gdate(&year, &month, &mday, &wday);
    assert(month >= 1 && month <= 12);
    assert(mday >= 1 && mday <= 31);
    assert(wday >= 0 && wday <=6);

    printf("%u/%u/%u %s\n", year, month, mday, str_wday[wday]);
}
