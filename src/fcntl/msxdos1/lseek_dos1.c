#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

long __LIB__ lseek_dos1(int fd, long pos, int whence) __smallc
{
    if(fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }
    if(_msx_fcbs[fd].use == 0) {
        return -1;
    }
    if(whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
        return -1;
    }
    MSX_FCB *fcb = &_msx_fcbs[fd];

    switch(whence) {
        case SEEK_SET:
            fcb->v1.random_record = pos;
            break;
        case SEEK_CUR:
            fcb->v1.random_record += pos;
            break;
        case SEEK_END:
            fcb->v1.random_record = fcb->v1.file_size + pos;
            break;
        default:
            return -1;
    }

    return fcb->v1.random_record;
}