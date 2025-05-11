#ifndef __MSXLIB__TIME_H__
#define __MSXLIB__TIME_H__


#include <msxlib/msxlib.h>
#include <time.h>

time_t __LIB__ dostime2time(const uint16_t date, const uint16_t time) __smallc;
int __LIB__ dostime2tm(const uint16_t date, const uint16_t time, struct tm *tm) __smallc;

#endif