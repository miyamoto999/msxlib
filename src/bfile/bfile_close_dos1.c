#include <stdlib.h>
#include <msxlib/bfile.h>

/*
  ファイルのクローズ

      fp:BFILE_DOS1構造体のポインタ

  戻り値
    0:成功
    0以外:失敗
*/
int __LIB__ bfile_close_dos1(BFILE_DOS1 *fp) __smallc
{
    uint8_t err = 0, err2;

    if(fp->mode == BFILE_O_WRONLY || fp->mode == BFILE_O_RDWR) {
        if(fp->buf_offset != 0 && fp->err == 0) {
            dos1_setdta(fp->buf);
            err = dos1_wrblk(&fp->fcb, fp->buf_offset);
        }
    }

    err2 = dos1_fclose(&fp->fcb);

    if(err == 0 && err2) {
        err = err2;
    }

    free(fp->buf);
    free(fp);

    return err;
}

