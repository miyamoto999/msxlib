#ifndef __BFILE_H__
#define __BFILE_H__

#include <stdio.h>
#include <stdint.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

#define DEF_BUF_SIZE    512

typedef struct __bfile_dos1 {
    MSX_FCB fcb;
    char *buf;
    int16_t buf_size;           /* bufのサイズ */
    uint16_t buf_offset;
    int16_t read_size;
    uint8_t err;
    uint8_t mode;
    BOOL dirty;
    BOOL eof;
    BOOL update;
} BFILE_DOS1;

typedef struct __bfile_dos2 {
    uint8_t handle;
    char *buf;
    int16_t buf_size;           /* bufのサイズ */
    uint16_t buf_offset;
    int16_t read_size;
    uint8_t err;
    uint8_t mode;
    BOOL dirty;
    BOOL eof;
    BOOL update;
} BFILE_DOS2;

#if __MSXDOS__ == 1 || __DSKBAS__ == 1
typedef BFILE_DOS1 BFILE;
#elif __MSXDOS__ == 2 || __DSKBAS__ == 2
typedef BFILE_DOS2 BFILE;
#endif

BOOL __LIB__ msx_fcb_init(MSX_FCB *fcb, const char *filename) __smallc;

BFILE_DOS1 __LIB__ *bfile_malloc_dos1(const char *filename, int16_t buf_size) __smallc;
BFILE_DOS1 __LIB__ *bfile_malloc_dsk1(const char *filename, int16_t buf_size) __smallc;

BFILE_DOS1 __LIB__ *bfile_create_dos1(const char *filename, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_write_dos1(BFILE_DOS1 *fp, const void *buf, int16_t size) __smallc;
int __LIB__ bfile_close_dos1(BFILE_DOS1 *fp) __smallc;
BFILE_DOS1 __LIB__ *bfile_open_dos1(const char *filename, uint8_t mode, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_read_dos1(BFILE_DOS1 *fp, void *buf, int16_t size) __smallc;
int32_t __LIB__ bfile_fseek_dos1(BFILE_DOS1 *fp, int32_t offset, int whence) __smallc;
BOOL __LIB__ bfile_flush_dos1(BFILE_DOS1 *fp) __smallc;

BFILE_DOS2 __LIB__ *bfile_create_dos2(const char *filename, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_write_dos2(BFILE_DOS2 *fp, const void *buf, int16_t size) __smallc;
int __LIB__ bfile_close_dos2(BFILE_DOS2 *fp) __smallc;
BFILE_DOS2 __LIB__ *bfile_open_dos2(const char *filename, uint8_t mode, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_read_dos2(BFILE_DOS2 *fp, void *buf, int16_t size) __smallc;
int32_t __LIB__ bfile_fseek_dos2(BFILE_DOS2 *fp, int32_t offset, int whence) __smallc;
BOOL __LIB__ bfile_flush_dos2(BFILE_DOS2 *fp) __smallc;

BFILE_DOS1 __LIB__ *bfile_create_dsk1(const char *filename, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_write_dsk1(BFILE_DOS1 *fp, const void *buf, int16_t size) __smallc;
int __LIB__ bfile_close_dsk1(BFILE_DOS1 *fp) __smallc;
BFILE_DOS1 __LIB__ *bfile_open_dsk1(const char *filename, uint8_t mode, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_read_dsk1(BFILE_DOS1 *fp, void *buf, int16_t size) __smallc;
int32_t __LIB__ bfile_fseek_dsk1(BFILE_DOS1 *fp, int32_t offset, int whence) __smallc;
BOOL __LIB__ bfile_flush_dsk1(BFILE_DOS1 *fp) __smallc;

BFILE_DOS2 __LIB__ *bfile_create_dsk2(const char *filename, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_write_dsk2(BFILE_DOS2 *fp, const void *buf, int16_t size) __smallc;
int __LIB__ bfile_close_dsk2(BFILE_DOS2 *fp) __smallc;
BFILE_DOS2 __LIB__ *bfile_open_dsk2(const char *filename, uint8_t mode, int16_t buf_size) __smallc;
int16_t __LIB__ bfile_read_dsk2(BFILE_DOS2 *fp, void *buf, int16_t size) __smallc;
int32_t __LIB__ bfile_fseek_dsk2(BFILE_DOS2 *fp, int32_t offset, int whence) __smallc;
BOOL __LIB__ bfile_flush_dsk2(BFILE_DOS2 *fp) __smallc;

#if __MSXDOS__ == 1
#define bfile_create(fname, size)      bfile_create_dos1(fname,size)
#define bfile_write(fp, buf, size)   bfile_write_dos1(fp, buf, size)
#define bfile_close(fp)         bfile_close_dos1(fp)
#define bfile_open(filename, mode, buf_size)   bfile_open_dos1(filename, mode, buf_size)
#define bfile_read(fp, buf, size)              bfile_read_dos1(fp, buf, size)
#define bfile_fseek(fp, offset, whence)         bfile_fseek_dos1(fp, offset, whence)
#define bfile_flush(fp)                         bfile_flush_dos1(fp)
#elif __MSXDOS__ == 2
#define bfile_create(fname, size)      bfile_create_dos2(fname,size)
#define bfile_write(fp, buf, size)   bfile_write_dos2(fp, buf, size)
#define bfile_close(fp)         bfile_close_dos2(fp)
#define bfile_open(filename, mode, buf_size)   bfile_open_dos2(filename, mode, buf_size)
#define bfile_read(fp, buf, size)              bfile_read_dos2(fp, buf, size)
#define bfile_fseek(fp, offset, whence)         bfile_fseek_dos2(fp, offset, whence)
#define bfile_flush(fp)                         bfile_flush_dos2(fp)
#elif __DSKBAS__ == 1
#define bfile_create(fname, size)      bfile_create_dsk1(fname,size)
#define bfile_write(fp, buf, size)   bfile_write_dsk1(fp, buf, size)
#define bfile_close(fp)         bfile_close_dsk1(fp)
#define bfile_open(filename, mode, buf_size)   bfile_open_dsk1(filename, mode, buf_size)
#define bfile_read(fp, buf, size)              bfile_read_dsk1(fp, buf, size)
#define bfile_fseek(fp, offset, whence)         bfile_fseek_dsk1(fp, offset, whence)
#define bfile_flush(fp)                         bfile_flush_dsk1(fp)
#elif __DSKBAS__ == 2
#define bfile_create(fname, size)      bfile_create_dsk2(fname,size)
#define bfile_write(fp, buf, size)   bfile_write_dsk2(fp, buf, size)
#define bfile_close(fp)         bfile_close_dsk2(fp)
#define bfile_open(filename, mode, buf_size)   bfile_open_dsk2(filename, mode, buf_size)
#define bfile_read(fp, buf, size)              bfile_read_dsk2(fp, buf, size)
#define bfile_fseek(fp, offset, whence)         bfile_fseek_dsk2(fp, offset, whence)
#define bfile_flush(fp)                         bfile_flush_dsk2(fp)
#endif

#define bfile_error(fp)         (fp)->err
#define bfile_clearerr(fp)      (fp)->err = 0
#define bfile_eof(fp)           (fp)->eof

#define BFILE_O_RDONLY          0
#define BFILE_O_WRONLY          1
#define BFILE_O_RDWR            2

#define BFILE_SEEK_SET          0
#define BFILE_SEEK_CUR          1
#define BFILE_SEEK_END          2

#endif