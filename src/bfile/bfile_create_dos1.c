/* MSX-DOS1用バッファードファイル生成関係 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>


/*
  ファイルを生成する。

    filename:ファイル名
    buf_size:バッファサイズ

  戻り値
    BFILE_DOS1構造体のポインタ
    NULL:エラー
 */
BFILE_DOS1 __LIB__ *bfile_create_dos1(const char *filename, int16_t buf_size) __smallc
{
    BFILE_DOS1 *fp = NULL;

    fp = bfile_malloc_dos1(filename, buf_size);
    if(!fp) {
        return NULL;
    }
    uint8_t err = dos1_fmake(&fp->fcb);
    if(err) {
        free(fp->buf);
        free(fp);
        return NULL;
    }
    fp->fcb.v1.record_size = 1;
    fp->fcb.v1.random_record = 0;
    fp->mode = BFILE_O_WRONLY;
    fp->dirty = TRUE;
    fp->update = FALSE;

    return fp;
}

