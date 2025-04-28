#include <msxlib/msxlib.h>
#include <msxlib/msxbios.h>
#include <stdio.h>
#include <string.h>

char __LIB__ fgetc_cons_dos(void) __smallc;
extern int _MSXLIB_BDOS;
extern int _bdos;
extern int _testtest;

char buf[256];

int main(void)
{
    printf("Hello world\n");
    // printf("_testtest=0x%x\n", _testtest);
    // printf("_bdos=0x%x\n", _bdos);
    // printf("MSXLIB_BDOS=0x%x\n", _MSXLIB_BDOS);
    // printf("0x%x\n", *((int *)_MSXLIB_BDOS));

    printf("fgets\n");
    char *tmp = fgets(buf, 256, stdin);
    if(!tmp) {
        printf("Error\n");
        return 1;
    }
    int len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n') {
        buf[len-1] = '\0';
        len--;
    }
    for(int i = 0; i < len; i++) {
        printf("%x ", buf[i]);
    }
    printf("\n");

    printf("%s\n", buf);

    int ch;

    printf("chget\n");
    while((ch = msxmain_chget()) != 0x1a) {
        printf(":%x\n", ch);
    }
    printf("\n");

    printf("fgetc_cons_native_dos2\n");
    while((ch = fgetc_cons_dos()) != 0x1a) {
        printf(":%x\n", (ch & 0xff));
    }
    printf("\n");

    printf("fgetc\n");
    while((ch = fgetc(stdin)) != EOF) {
        printf(":%x\n", (ch & 0xff));
    }
    printf("\n");
    
    return 0;
}
