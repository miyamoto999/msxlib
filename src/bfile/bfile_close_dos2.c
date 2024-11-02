/* MSX-DOS2用バッファードファイル生成関係 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>


/*
  ファイルのクローズ

      fp:BFILE_DOS2構造体のポインタ

  戻り値
    0:成功
    0以外:失敗
*/
int __LIB__ bfile_close_dos2(BFILE_DOS2 *fp) __smallc
{
    uint8_t err = 0, err2;
    uint16_t tmp_size;

    if(fp->buf_offset != 0 && fp->err == 0) {
        err = dos2_write(fp->handle, fp->buf, fp->buf_offset, &tmp_size);
    }

    err2 = dos2_close(fp->handle);

    if(err == 0 && err2) {
        err = err2;
    }

    free(fp->buf);
    free(fp);
    return err;
}
