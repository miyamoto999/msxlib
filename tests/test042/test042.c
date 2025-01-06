#include <msxlib/msxbios.h>
#include <msxlib/bcdf.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

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
    dos_scode(0);

    return 0;
}

int test001() {
    char *a = "-0";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;

    printf("test042-001:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 2);
    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != 0) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test002() {
    char *a = "-1";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xc1, 0x10, 0, 0, 0, 0, 0, 0,
    };

    printf("test042-002:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 2);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test003() {
    char *a = "-1234567890";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xca, 0x12, 0x34, 0x56, 0x78, 0x90, 0, 0,
    };

    printf("test042-003:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 11);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test004() {
    char *a = " - 00001200 345   ";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xc7, 0x12, 0x00, 0x34, 0x50, 0x00, 0, 0,
    };

    printf("test042-004:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 15);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test005() {
    char *a = "-12345678901234";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xce, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34,
    };

    printf("test042-005:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 15);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test006() {
    char *a = "-12345678901234567";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xd1, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x35,
    };

    printf("test042-006:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 18);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test007() {
    char *a = "-99999999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xd2, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    printf("test042-007:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 18);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test008() {
    char *a = "-999999999999990000000000000000000000000000000000000000000000000";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0xff, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };

    printf("test042-008:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 64);

    flag = FALSE;
    for(i = 0; i < BCDF_DOUBLE_SIZE; i++) {
        if(buf[i] != chk_data[i]) {
            flag = TRUE;
        }
    }
    assert(flag == FALSE);

    printf("OK\n");

    return 0;
}

int test009() {
    char *a = "-9999999999999900000000000000000000000000000000000000000000000000";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test042-009:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}

int test010() {
    char *a = "-999999999999995000000000000000000000000000000000000000000000000";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test042-010:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}
