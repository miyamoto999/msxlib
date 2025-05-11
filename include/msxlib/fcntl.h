#ifndef __MSXLIB_FCNTL_H__
#define __MSXLIB_FCNTL_H__

#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

struct _msx_fcb_data {
    MSX_FCB fcb;
    uint8_t use;
    int flags;
};

#ifndef CLIB_OPEN_MAX
extern void *_CLIB_OPEN_MAX;
#define CLIB_OPEN_MAX (int)&_CLIB_OPEN_MAX
#endif

#define MSX_FCB_MAX CLIB_OPEN_MAX
extern struct _msx_fcb_data _msx_fcbs[0];

int __LIB__ creat_dos1(const char *filename, int mode) __smallc;
int __LIB__ open_dos1(const char *filename, int flags, int mode) __smallc;
int __LIB__ close_dos1(int fd) __smallc;
int __LIB__ read_dos1(int fd, void *buf, int size) __smallc;
int __LIB__ write_dos1(int fd, const void *buf, int size) __smallc;
long __LIB__ lseek_dos1(int fd, long pos, int whence) __smallc;
long __LIB__ fdtell_dos1(int fd) __smallc;
int __LIB__ fdgetpos_dos1(int fd, fpos_t *pos) __smallc;
int __LIB__ stat_dos1(char *filename, struct stat *buf) __smallc;


#endif