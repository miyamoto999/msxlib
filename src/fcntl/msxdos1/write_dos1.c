#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

int __LIB__ write_dos1(int fd, const void *buf, int size) __smallc
{
    if (fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }
    if (_msx_fcbs[fd].use == 0) {
        return -1;
    }
    if ((_msx_fcbs[fd].flags & 3) == O_RDONLY) {
        return -1;
    }
    if (size <= 0) {
        return 0;
    }
    if(_msx_fcbs[fd].flags & O_APPEND) {
        lseek_dos1(fd, 0, SEEK_END);
    }
    dos1_setdta(buf);
    uint8_t err = dos1_wrblk(&_msx_fcbs[fd].fcb, size);
    if(err) {
        return -1;
    }
    return size;    
}
