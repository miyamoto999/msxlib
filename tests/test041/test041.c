#include <msxlib/msxlib.h>
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
    char *a = "0";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;

    printf("test041-001:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 1);
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
    char *a = "1";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x41, 0x10, 0, 0, 0, 0, 0, 0,
    };

    printf("test041-002:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 1);

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
    char *a = "1234567890";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x4a, 0x12, 0x34, 0x56, 0x78, 0x90, 0, 0,
    };

    printf("test041-003:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 10);

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
    char *a = " 00001200 345   ";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x47, 0x12, 0x00, 0x34, 0x50, 0x00, 0, 0,
    };

    printf("test041-004:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 13);

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
    char *a = "12345678901234";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x4e, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34,
    };

    printf("test041-005:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 14);

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
    char *a = "12345678901234567";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x51, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x35,
    };

    printf("test041-006:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 17);

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
    char *a = "99999999999999999";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x52, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    printf("test041-007:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 17);

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
    char *a = "999999999999990000000000000000000000000000000000000000000000000";
    BOOL flag;
    int ret;
    char buf[BCDF_DOUBLE_SIZE];
    int i;
    char chk_data[] = {
        0x7f, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,
    };

    printf("test041-008:test str2bcdf(\"%s\"):", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == 63);

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
    char *a = "9999999999999900000000000000000000000000000000000000000000000000";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test041-009:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}

int test010() {
    char *a = "999999999999995000000000000000000000000000000000000000000000000";
    int ret;
    char buf[BCDF_DOUBLE_SIZE];

    printf("test041-010:test str2bcdf(\"%s\") is overflow error.:", a);
    ret = str2bcdf(a, strlen(a), buf, BCDF_DOUBLE_SIZE);
    assert(ret == BCDF_OVERFLOW_ERR);

    printf("OK\n");

    return 0;
}
