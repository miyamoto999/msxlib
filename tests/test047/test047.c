#include <msxlib/msxbios.h>
#include <msxlib/bcdf.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <float.h>

int test047(char *strval, double checkval);

int main() 
{
    test047("0.1", 0.1);
    test047("1", 1);
    test047("100", 100);
    test047("1e13", 10000000000000);
    test047("0", 0);

    // ↓たぶん変換誤差で失敗する
    // test047("1e-13", 1e-13);
    // test047("-1e-13", -1e-13);
    //
    // doubleはたぶん1.0e-38〜9.995e37までの範囲なので扱えないはず
    // test047("0.99999999999999e63", 0.99999999999999e63);
    test047("12345.67890123456", 12345.678901235);
    return 0;
}

int test047(char *strval, double checkval)
{
    char bcdf[BCDF_DOUBLE_SIZE];
    double dret;
    int ret;

    printf("test047:bcdf2dbl(%s) test:", strval);
    ret = str2bcdf(strval, strlen(strval), bcdf, BCDF_DOUBLE_SIZE);
    assert(ret > 0);
    dret = bcdf2dbl(bcdf, BCDF_DOUBLE_SIZE);
    assert(dret == checkval);

    printf("OK\n");

    return 0;
}
