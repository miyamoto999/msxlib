/*********************************************************
 bfile/bfile_fseek_dsk1.c mk_dskcallversion.sh によって自動生成されるファイルなので
 書き換えないでください。

  Do not rewrite bfile/bfile_fseek_dsk1.c as this file is
 automatically generated by mk_dskcallversion.sh.

 *********************************************************/

#include <msxlib/msxdos.h>
#include <msxlib/bfile.h>

int32_t __LIB__ bfile_fseek_dsk1(BFILE_DOS1 *fp, int32_t offset, int whence) __smallc
{
    if(fp->update) {
        if(!bfile_flush_dsk1(fp)) {
            return 0;
        }
    }
    switch(whence) {
        case BFILE_SEEK_CUR:
            fp->fcb.v1.random_record = fp->fcb.v1.random_record + fp->buf_offset + offset;
            break;
        case BFILE_SEEK_SET:
            fp->fcb.v1.random_record = offset;
            break;
        case BFILE_SEEK_END:
            fp->fcb.v1.random_record = fp->fcb.v1.file_size + offset;
            break;
    }
    fp->dirty = TRUE;
    return fp->fcb.v1.random_record;
}