#include <msxlib/msxlib.h>
#include <msxlib/bcdf.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief MSXのBCD形式の浮動小数点をdoubleに変換する。
 * 
 * @param bcd_val BCD形式の浮動小数点
 * @param bcd_val_size bcd_valのサイズ
 * @return double 変換後の値
 */
double __LIB__ bcdf2dbl(const char *bcd_val, int bcd_val_size) __smallc
{
    double ret;
    int i, e = 0;

    e = (bcd_val[0] & 0x7f) - 0x40 - ((bcd_val_size - 1) << 1);
    ret = 0.0;
    for(i = 1; i < bcd_val_size; i++) {
        ret *= 100;
        ret += ((bcd_val[i] >> 4) & 0x0f) * 10 + (bcd_val[i] & 0x0f);
    }
    /* 10の-n乗のときret*=pow(10,e)やret/=pow(10,-e)だと誤差が
        ひどいのでループで処理をた。それでも誤差がある。
     */
    /*     ret *= pow(10, e); */
    if(e > 0) {
        ret *= pow(10, e);
    } else {
        for(i = 0; i < -e; i++) {
            ret /= 10;
        }
    }
    if(bcd_val[0] & 0x80) {
        ret *= -1;
    }

    return ret;
}
