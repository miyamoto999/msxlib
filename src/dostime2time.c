#include <msxlib/msxlib.h>
#include <msxlib/time.h>

time_t __LIB__ dostime2time(const uint16_t date, const uint16_t time) __smallc
{
    struct tm tm;
    if(dostime2tm(date, time, &tm) != 0) {
        return -1;
    }
    return mktime(&tm);
}

