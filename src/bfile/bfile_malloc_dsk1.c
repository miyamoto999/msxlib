/*********************************************************
 bfile/bfile_malloc_dsk1.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_malloc_dsk1.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <stdio.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/bfile.h>

BFILE_DOS1 __LIB__ *bfile_malloc_dsk1(const char *filename, int16_t buf_size) __smallc
{
    BFILE_DOS1 *fp = malloc(sizeof(BFILE_DOS1));
    if(!fp) {
        return NULL;
    }
    memset(fp, 0, sizeof(BFILE_DOS1));
    msx_fcb_init(&fp->fcb, filename);
    fp->buf_size = buf_size > 0 ? buf_size:DEF_BUF_SIZE;
    fp->buf = malloc(fp->buf_size);
    if(!fp->buf) {
        free(fp);
        return NULL;
    }
    fp->dirty = TRUE;
    return fp;
}