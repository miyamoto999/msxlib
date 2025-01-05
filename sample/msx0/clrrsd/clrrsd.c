#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <msxlib/iot.h>

#define NODE_FMT "msx/u%d/pm/clear"

static char node[64];

static void print_usage(void)
{
    printf("Usage: clrrsd [u0 | u1 | <num> ]\n");
    printf("  Clear resume data command.\n");
    printf("\n");
    printf("Options:\n");
    printf("  u0       Clear unit0 resume data.\n");
    printf("  u1       Clear unit1 resume data.\n");
    printf("  <num>     1-7 Resume data num.\n");
    printf("  -h        Show this help.\n");
}

int main(int argc, char *argv[])
{
    int unit_num = 0;
    int resume_num = 0;
    int errflag = 0;

#if __MSXDOS__ == 1
    int cmd_len = *((uint8_t *)0x0080);
    *((uint8_t *)0x0081 + cmd_len) = 0;
#endif
    if(argc == 1) {
        print_usage();
        return 1;
    }

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "u0") == 0) {
            unit_num = 0;
        } else if(strcmp(argv[i], "u1") == 0) {
            unit_num = 1;
        } else if(strcmp(argv[i], "-h") == 0) {
            print_usage();
            return 0;
        } else {
            for(int j = 0; j < strlen(argv[i]); j++) {
                if(argv[i][j] < '0' || argv[i][j] > '7') {
                    errflag = 1;
                    break;
                }
            }
            if(errflag) {
                break;
            }
            resume_num = atoi(argv[i]);
            if(resume_num < 1 || resume_num > 7) {
                errflag = 1;
                break;
            }
        }
    }
    if(errflag) {
        print_usage();
        return 1;
    }

    printf("Clear resume data for Unit%d, Num%d.\n", unit_num, resume_num);
    sprintf(node, NODE_FMT, unit_num);
    iot_puti(node, resume_num);

    return 0;
}