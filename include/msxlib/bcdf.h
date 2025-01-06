#ifndef __BCDF_H__
#define __BCDF_H__

#include <msxlib/msxlib.h>

#define BCDF_SINGLE_SIZE     4
#define BCDF_DOUBLE_SIZE     8
#define BCDF_OVERFLOW_ERR    -2

#ifdef __cplusplus__
extern "C" {
#endif

int __LIB__ str2bcdf(const char *str, const int str_len, char *buf, int buf_size) __smallc;
int __LIB__ bcdf2str(const char *bcd_val, int bcd_val_size, char *str, const int str_len) __smallc;

double __LIB__ bcdf2dbl(const char *bcd_val, int bcd_val_size);

#ifdef __cplusplus__
}
#endif

#endif
