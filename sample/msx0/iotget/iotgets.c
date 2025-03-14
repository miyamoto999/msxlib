#include <stdio.h>
#include <msxlib/iot.h>

int main(int argc, char *argv[])
{
#if __MSXDOS__ == 1
    int cmd_len = *((uint8_t *)0x0080);
    *((uint8_t *)0x0081 + cmd_len) = 0;
#endif

    if(argc != 2) {
        fprintf(stderr, "iotgets NODEPATH\n");
        return 1;
    }

    puts(iot_gets(argv[1]));
    return 0;
}