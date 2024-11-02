#include <stdio.h>
#include <ctype.h>
#include <msxlib/iot.h>

int main(int argc, char *argv[])
{
#if __MSXDOS__ == 1
    int cmd_len = *((uint8_t *)0x0080);
    *((uint8_t *)0x0081 + cmd_len) = 0;
#endif

    if(argc != 3) {
        fprintf(stderr, "iotputi NODEPATH INT_VAL\n");
        return 1;
    }

    iot_puti(argv[1], atoi(argv[2]));
    return 0;
}