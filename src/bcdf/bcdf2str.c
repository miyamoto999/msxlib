#include <msxlib/msxlib.h>
#include <msxlib/bcdf.h>

static int bcdf2str_e(const char *bcd_val, int bcd_val_size, char *str, const int str_len);
static int bcdf2str_ne(const char *bcd_val, int bcd_val_size, char *str, const int str_len);

/**
 * @brief MSXのBCD形式の浮動小数点を文字列に変換する。
 * 
 * @param bcd_val BCD形式の浮動小数点
 * @param bcd_val_size bcdf_valのサイズ
 * @param str 変換後の文字列を格納するバッファ
 * @param str_len strのサイズ
 * @return int 文字数
 */
int __LIB__ bcdf2str(const char *bcd_val, int bcd_val_size, char *str, const int str_len) __smallc
{
    int e;
    int ret = -1;

    if(bcd_val[0] == 0) {
        str[0] = ' ';
        str[1] = '0';
        str[2] = 0;
        return 2;
    }

    e = (bcd_val[0] & 0x7f) - 0x40;
    if(e > (int)(bcd_val_size - 1) * 2) {
        ret = bcdf2str_e(bcd_val, bcd_val_size, str, str_len);
    } else if(e > -2) {
        ret = bcdf2str_ne(bcd_val, bcd_val_size, str, str_len);
    } else {
        ret = bcdf2str_e(bcd_val, bcd_val_size, str, str_len);
    }

    return ret;
}

static int bcdf2str_e(const char *bcd_val, int bcd_val_size, char *str, const int str_len)
{
    int i;
    int idx = 0;
    int e;

    if((bcd_val[0] & 0x80) == 0x80) {
        str[idx] = '-';
    } else {
        str[idx] = ' ';
    }
    idx++;
    e = (bcd_val[0] & 0x7f) - 0x40 - 1;

    for(i = 1; i < bcd_val_size; i++) {
        str[idx] = ((bcd_val[i] >> 4) & 0x0f) + '0';
        idx++;
        if(idx == 2) {
            str[idx] = '.';
            idx++;
        }
        str[idx] = (bcd_val[i] & 0x0f) + '0';
        idx++;
    }

    for(i = idx - 1; i > 2; i--) {
        if(str[i] != '0') {
            break;
        } else {
            idx--;
        }
    }
    if(idx == 3) {
        idx--;
    }

    str[idx] = 'E';
    idx++;

    if(e < 0) {
        str[idx] = '-';
        e *= -1;
    } else {
        str[idx] = '+';
    }
    idx++;

    str[idx] = (int)(e / 10) + '0';
    idx++;
    str[idx] = (e % 10) + '0';
    idx++;
    str[idx] = 0;

    return idx;
}

static int bcdf2str_ne(const char *bcd_val, int bcd_val_size, char *str, const int str_len)
{
    int i;
    int idx = 0;
    int e;

    if((bcd_val[0] & 0x80) == 0x80) {
        str[idx] = '-';
    } else {
        str[idx] = ' ';
    }
    idx++;
    e = (bcd_val[0] & 0x7f) - 0x40;
    if(e <= 0) {
        str[idx] = '.';
        idx++;
        e*=-1;
        for(i = 0; i <  e; i++, idx++) {
            str[idx] = '0';
        }
        e = 100;
    }
    for(i = 1; i < bcd_val_size; i++) {
        str[idx] = ((bcd_val[i] >> 4) & 0x0f) + '0';
        idx++;
        e--;
        if(e == 0) {
            str[idx] = '.';
            idx++;
        }
        str[idx] = (bcd_val[i] & 0x0f) + '0';
        idx++;
        e--;
        if(e == 0) {
            str[idx] = '.';
            idx++;
        }
    }
    for(i = idx - 1; i > 2; i--) {
        if(str[i] != '0') {
            break;
        } else {
            idx--;
        }
    }
    if(str[idx - 1] == '.') {
        idx--;
    }
    str[idx] = 0;

    return idx;
}
