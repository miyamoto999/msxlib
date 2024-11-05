/*********************************************************
 bfile/bfile_write_dsk2.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_write_dsk2.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <string.h>
#include <msxlib/bfile.h>

/*
  ファイル書き込み

    fp:BFILE_DOS2構造体のポインタ
    buf:書き込むデータへのポインタ
    size:データサイズ

  戻り値
      書き込んだサイズ
*/
int16_t __LIB__ bfile_write_dsk2(BFILE_DOS2 *fp, const void *buf, int16_t size) __smallc
{
    uint16_t tmp_size;
    uint8_t err;

    if(fp->err) {
        return 0;
    }

    if(size >= fp->buf_size) {
        if(fp->update) {
            if(!bfile_flush_dsk2(fp)) {
                return 0;
            }
        }
        err = dsk2_write(fp->handle, buf, size, &tmp_size);
        if(err) {
            fp->err = err;
            return 0;
        }
        fp->update = FALSE;
    } else {
        int copy_size, rest_size = size;
        int idx = 0;
        while(rest_size != 0) {
            if(fp->buf_size - fp->buf_offset < rest_size) {
                copy_size = fp->buf_size - fp->buf_offset;
                rest_size -= copy_size;
            } else {
                copy_size = rest_size;
                rest_size = 0;
            }
            memcpy(&fp->buf[fp->buf_offset], &buf[idx], copy_size);
            fp->buf_offset += copy_size;
            idx += copy_size;
            fp->dirty = FALSE;
            fp->update = TRUE;
            if(fp->buf_offset == fp->buf_size) {
                if(!bfile_flush_dsk2(fp)) {
                    return 0;
                }
            }
        }
    }
    return size;
}

