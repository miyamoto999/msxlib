#include <msxlib/msxbios.h>
#include <msxlib/bcdf.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define STR_SIZE1       256
char str[STR_SIZE1];

int test001();
int test002();
int test003();
int test004();
int test005();
int test006();
int test007();
int test008();
int test009();
int test010();
int test011();
int test012();
int test013();

int main() 
{
    dos_scode(1);
    test001();
    test002();
    test003();
    test004();
    test005();
    test006();
    test007();
    test008();
    test009();
    test010();
    test011();
    test012();
    test013();
    dos_scode(0);
 
    return 0;
}


int test001() {
    char *a = "1e13";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 10000000000000";
    int chk_str_len = strlen(chk_str);

    printf("test046-001:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test002() {
    char *a = "1e14";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 1E+14";
    int chk_str_len = strlen(chk_str);

    printf("test046-002:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test003() {
    char *a = "0";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 0";
    int chk_str_len = strlen(chk_str);

    printf("test046-003:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test004() {
    char *a = "0.01";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " .01";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x3f, 0x10, 0x0, 0, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-004:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test005() {
    char *a = "0.001";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 1E-03";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x3e, 0x10, 0x0, 0, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-005:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test006() {
    char *a = "0.1";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " .1";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x40, 0x10, 0x0, 0, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-006:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test007() {
    char *a = "1";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 1";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x41, 0x10, 0x0, 0, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-007:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test008() {
    char *a = "100";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 100";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x43, 0x10, 0x0, 0, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-008:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test009() {
    char *a = "0.99999999999999e63";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 9.9999999999999E+62";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x7f, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };
    BOOL flag;
    int i;

    printf("test046-009:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test010() {
    char *a = "12345.67890123456";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 12345.678901235";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x45, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x35,
    };
    BOOL flag;
    int i;

    printf("test046-010:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test011() {
    char *a = "1.2345e-64";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 1.2345E-64";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x01, 0x12, 0x34, 0x50, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-011:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test012() {
    char *a = "1.2345e-65";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;
    char *chk_str = " 0";
    int chk_str_len = strlen(chk_str);
    char chk_data[] = {
        0x00, 0x12, 0x34, 0x50, 0, 0, 0, 0,
    };
    BOOL flag;
    int i;

    printf("test046-012:bcd2str(%s):", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(bcdf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    ret = bcdf2str(bcdf, BCDF_DOUBLE_SIZE, str, STR_SIZE1);
    assert(ret == chk_str_len);

    ret = strcmp(str, chk_str);
    assert(ret == 0);

    printf("OK\n");

    return 0;
}

int test013() {
    char *a = "1.2345e-66";
    char bcdf[BCDF_DOUBLE_SIZE];
    int ret;

    printf("test046-013:bcd2str(%s):overflow err:", a);
    ret = str2bcdf(a, strlen(a), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}
