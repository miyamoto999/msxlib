#include <msxlib/msxlib.h>
#include <stdio.h>

void __LIB__ test_msg1(void) __smallc;
void __LIB__ test2(void) __smallc;

char buf[256];

int main(void)
{
    printf("Hello world\n");

    test_msg1();

    fgets(buf, 256, stdin);

    printf("%s\n", buf);
    
    return 0;
}

void __LIB__ test2(void)
{
    printf("Test2\n");
}