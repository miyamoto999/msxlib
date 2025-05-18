#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

int __LIB__ open_dos1(const char *filename, int flags, int mode) __smallc {
    int fd = -1;
    int8_t err;

    for(int i = 0; i < MSX_FCB_MAX; i++) {
        if (_msx_fcbs[i].use == 0) {
            _msx_fcbs[i].use = 1;
            fd = i;
            break;
        }
    }
    if (fd == -1) {
        return -1;
    }

    msx_fcb_init(&_msx_fcbs[fd].fcb, filename);
    if(flags & O_TRUNC) {
        dos1_fdel(&_msx_fcbs[fd].fcb);
        msx_fcb_init(&_msx_fcbs[fd].fcb, filename);
    }
    err = dos1_fopen(&_msx_fcbs[fd].fcb);
    if(err != 0 && (flags & O_CREAT)) {
        err = dos1_fmake(&_msx_fcbs[fd].fcb);
    }
    if(err) {
        _msx_fcbs[fd].use = 0;
        return -1;
    }
    _msx_fcbs[fd].flags = flags;
    _msx_fcbs[fd].fcb.v1.record_size = 1;
    _msx_fcbs[fd].fcb.v1.random_record = 0;

    return fd;
}


