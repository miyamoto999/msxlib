#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>

int __LIB__ fsync_dos1(int fd) __smallc
{
    if(fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }

    if(_msx_fcbs[fd].use == 0) {
        return -1;
    }
    if ((_msx_fcbs[fd].flags & 3) == O_WRONLY || (_msx_fcbs[fd].flags & 3) == O_RDWR)  {
        return 0;
    }
    return -1;
}