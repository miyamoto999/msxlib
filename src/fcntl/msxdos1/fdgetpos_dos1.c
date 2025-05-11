#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

int __LIB__ fdgetpos_dos1(int fd, fpos_t *pos) __smallc
{
    if (fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }
    if (_msx_fcbs[fd].use == 0) {
        return -1;
    }
    if (pos == NULL) {
        return -1;
    }
    *pos = _msx_fcbs[fd].fcb.v1.random_record;
    return 0;
}