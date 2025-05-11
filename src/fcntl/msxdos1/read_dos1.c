#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>
#include <stdio.h>

int __LIB__ read_dos1(int fd, void *buf, int size) __smallc
{
    uint16_t read_size;

    if (fd < 0 || fd >= MSX_FCB_MAX) {
        return -1;
    }
    if (_msx_fcbs[fd].use == 0) {
        return -1;
    }
    if ((_msx_fcbs[fd].flags & 3) == O_WRONLY) {
        return -1;
    }
    if (size <= 0) {
        return 0;
    }
    dos1_setdta(buf);
    read_size = size;
    int8_t err = dos1_rdblk(&_msx_fcbs[fd].fcb, size, &read_size);
    return read_size;
}