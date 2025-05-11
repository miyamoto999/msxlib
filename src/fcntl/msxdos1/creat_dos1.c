#include <msxlib/msxlib.h>
#include <msxlib/fcntl.h>

int __LIB__ creat_dos1(const char *filename, int mode) __smallc
{
    return open_dos1(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
}

