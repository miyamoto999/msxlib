#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <msxlib/msxdos.h>

int test1(void)
{
    char buf[FCB_NAME_SIZE + FCB_EXT_SIZE + 1];
    char *last_str;
    uint8_t flag;

    printf("dos2_pfile test1:");
    dos2_pfile("test.txt", buf, &last_str, &flag);
    buf[FCB_NAME_SIZE + FCB_EXT_SIZE] = 0;
    assert(strcmp(buf, "TEST    TXT") == 0);
    assert(strlen(last_str) == 0);
    assert(flag == 0x19);
    printf("OK\n");

    return 0;
}

int main(void)
{
    test1();
    return 0;
}