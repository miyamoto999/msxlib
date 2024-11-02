/*********************************************************
 bfile/bfile_open_dsk2.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_open_dsk2.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <stdio.h>
#include <string.h>
#include <msxlib/bfile.h>
#include <msxlib/msxdos.h>

BFILE_DOS2 __LIB__ *bfile_open_dsk2(const char *filename, uint8_t mode, int16_t buf_size) __smallc
{
    uint8_t dsk2_open_mode = 0;

    BFILE_DOS2 *fp = malloc(sizeof(BFILE_DOS2));
    if(!fp) {
        return NULL;
    }
    memset(fp, 0, sizeof(BFILE_DOS2));

    fp->buf_size = buf_size > 0 ? buf_size:DEF_BUF_SIZE;
    fp->buf = malloc(fp->buf_size);
    if(!fp->buf) {
        free(fp);
        return NULL;
    }
    switch(mode) {
        case BFILE_O_RDONLY:
            dsk2_open_mode = FILE_MODE_READ_ONLY | FILE_MODE_INHELITANCE;
            break;
        case BFILE_O_WRONLY:
            dsk2_open_mode = FILE_MODE_WRITE_ONLY | FILE_MODE_INHELITANCE;
            break;
        case BFILE_O_RDWR:
            dsk2_open_mode = FILE_MODE_READ_WRITE | FILE_MODE_INHELITANCE;
            break;
    }

    uint8_t err = dsk2_open(filename, dsk2_open_mode, &(fp->handle));
    if(err) {
        free(fp->buf);
        free(fp);
        return NULL;
    }
    fp->mode = mode;
    fp->dirty = TRUE;

    return fp;
}
