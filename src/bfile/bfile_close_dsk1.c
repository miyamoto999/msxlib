/*********************************************************
 bfile/bfile_close_dsk1.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_close_dsk1.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <stdlib.h>
#include <msxlib/bfile.h>

/*
  ファイルのクローズ

      fp:BFILE_DOS1構造体のポインタ

  戻り値
    0:成功
    0以外:失敗
*/
int __LIB__ bfile_close_dsk1(BFILE_DOS1 *fp) __smallc
{
    uint8_t err = 0, err2;

    if(fp->mode == BFILE_O_WRONLY || fp->mode == BFILE_O_RDWR) {
        if(fp->buf_offset != 0 && fp->err == 0) {
            dsk1_setdta(fp->buf);
            err = dsk1_wrblk(&fp->fcb, fp->buf_offset);
        }
    }

    err2 = dsk1_fclose(&fp->fcb);

    if(err == 0 && err2) {
        err = err2;
    }

    free(fp->buf);
    free(fp);

    return err;
}


