#ifndef __FIB_H__
#define __FIB_H__

#include <stdint.h>

#define FIB_FILENAME_SIZE       13

typedef struct _msx_fib {
    uint8_t ff;
    char filename[FIB_FILENAME_SIZE];
    uint8_t attr;
    uint8_t time[2];
    uint8_t date[2];
    uint16_t start_cluster;
    long file_size;
    uint8_t logical_drive;
    uint8_t dmy[38];
} MSX_FIB;

#endif