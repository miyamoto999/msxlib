#include <stdio.h>
#include <stdarg.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxbios.h>
#include <msxlib/msxdos.h>

int main(void)
{
#ifdef __SCCZ80
    pre_printf("SCCZ80\n");
#else
    pre_printf("SDCC\n");
#endif
    pre_printf("%ld,%s,%c,%d\n", (long)123456, "hoge", '$', 123);
    return 0;
}
