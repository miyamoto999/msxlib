#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>
#include <stdio.h>

int main() {
#ifdef __MSXDOS1
    printf("MSX-DOS1:__MSXDOS1\n");
#elif defined(__MSXDOS2)
    printf("MSX-DOS2:__MSXDOS2\n");
#else 
    printf("__MSXDOS1 and __MSXDOS2 not detected\n");
#endif
#ifdef __MSXDOS_MSXDOS1
    printf("MSX-DOS1:__MSXDOS_MSXDOS1\n");
#elif defined(__MSXDOS_MSXDOS2)
    printf("MSX-DOS2:__MSXDOS_MSXDOS2\n");
#else 
    printf("__MSXDOS_MSXDOS1 and __MSXDOS_MSXDOS2 not detected\n");
#endif
#ifdef __MSX__
    printf("__MSX__\n");
#else
    printf("not __MSX__\n");
#endif
#ifdef __MSX2__
    printf("__MSX2__\n");
#else
    printf("not __MSX2__\n");
#endif
#ifdef __MSXDOS
    printf("__MSXDOS = 0x%x\n", __MSXDOS);
#else
    printf("not __MSXDOS\n");
#endif
#ifdef __MSXDOS2
    printf("__MSXDOS2 = 0x%x\n", __MSXDOS2);
#else
    printf("not __MSXDOS2\n");
#endif

#ifdef __MSXDOS_MSXDOS2
    uint16_t val;
    uint8_t ret = dos2_ioctl(0, 0, &val);
    printf("dos2_ioctl(0,0,val):ret=%d, val=0x%x\n", ret, val);
    ret = dos2_ioctl(1, 0, &val);
    printf("dos2_ioctl(1,0,val):ret=%d, val=0x%x\n", ret, val);
#endif

    char *hello = "hello\x0d\x0a";
    while(*hello) {
        dos1_conout(*hello);
        hello++;
    }
    while (getchar() != 's') {
    }

    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fwrite("Hello, World!\n", 1, 14, fp);
    fclose(fp);

    return 0;
}