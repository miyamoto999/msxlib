/*********************************************************
 bfile/bfile_create_dsk2.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_create_dsk2.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <stdlib.h>
#include <string.h>
#include <msxlib/bfile.h>

/*
  ファイルを生成する。

    filename:ファイル名
    buf_size:バッファサイズ

  戻り値
    BFILE_DOS2構造体のポインタ
    NULL:エラー
 */
BFILE_DOS2 __LIB__ *bfile_create_dsk2(const char *filename, int16_t buf_size) __smallc
{
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

    uint8_t err = dsk2_create(filename, FILE_MODE_WRITE_ONLY, FILE_ATTR_NORMAL, &(fp->handle));
    if(err) {
        free(fp->buf);
        free(fp);
        return NULL;
    }
    fp->mode = BFILE_O_WRONLY;
    fp->dirty = TRUE;
    fp->update = FALSE;

    return fp;
}
