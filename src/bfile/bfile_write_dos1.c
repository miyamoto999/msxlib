#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/bfile.h>

/*
  ファイル書き込み

    fp:BFILE_DOS1構造体のポインタ
    buf:書き込むデータへのポインタ
    size:データサイズ

  戻り値
      書き込んだサイズ
*/
int16_t __LIB__ bfile_write_dos1(BFILE_DOS1 *fp, const void *buf, int16_t size) __smallc
{
    uint8_t err;

    if(fp->err) {
        return 0;
    }

    if(size >= fp->buf_size) {
        /* バッファサイズより大きいデータを書き込もうとした場合
           まず、バッファの内容を書き込む */
        if(fp->update) {
            if(!bfile_flush_dos1(fp)) {
                return 0;
            }
        }
        /* 渡されたデータを書き込む */
        dos1_setdta(buf);
        err = dos1_wrblk(&fp->fcb, size);
        if(err) {
            fp->err = err;
            return 0;
        }
        fp->buf_offset = 0;
        fp->dirty = TRUE;
        fp->update = FALSE;
    } else {
        /* バッファより小さいデータを渡された場合
           まず、バッファに追加する */
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
            /* データをバッファに追加できるだけ追加する */
            memcpy(&fp->buf[fp->buf_offset], &buf[idx], copy_size);
            fp->buf_offset += copy_size;
            idx += copy_size;
            fp->dirty = FALSE;
            fp->update = TRUE;
            if(fp->buf_offset == fp->buf_size) {
                if(!bfile_flush_dos1(fp)) {
                    return 0;
                }
            }
        }
    }
    return size;
}

