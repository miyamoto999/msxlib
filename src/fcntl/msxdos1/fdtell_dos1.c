#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

long __LIB__ fdtell_dos1(int fd) __smallc
{
    if (fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }
    if (_msx_fcbs[fd].use == 0) {
        return -1;
    }
    return _msx_fcbs[fd].fcb.v1.random_record;
}