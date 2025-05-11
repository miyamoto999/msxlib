#include <msxlib/msxlib.h>
#include <msxlib/time.h>
#include <string.h>

int __LIB__ dostime2tm(const uint16_t date, const uint16_t time, struct tm *tm) __smallc
{
    memset(tm, 0, sizeof(struct tm));

    tm->tm_year = ((date >> 9) & 0x7f) + 1980 - 1900;
    tm->tm_mon = ((date >> 5) & 0x0f) - 1;
    tm->tm_mday = date & 0x1f;
    tm->tm_hour = (time >> 11) & 0x1f;
    tm->tm_min = (time >> 5) & 0x3f;
    tm->tm_sec = (time & 0x1f) << 1;

    return 0;
}
