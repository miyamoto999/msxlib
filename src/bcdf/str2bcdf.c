#include <msxlib/msxlib.h>
#include <msxlib/bcdf.h>
#include <string.h>

static int round_up(char *buf, int buf_size);

/**
 * @brief 数値文字列をMSXのBCD形式に変換する。
 * 
 * @param str 数値文字列
 * @param str_len strの文字数
 * @param buf MSXのBCD形式に変換した値を格納するバッファ
 * @param buf_size bufのサイズ
 * @return int 
 */
int __LIB__ str2bcdf(const char *str, const int str_len, char *buf, int buf_size) __smallc
{
    char sign = 0;
    int ret = 0, ret2;
    int i;
    int k, e, e2;
    char ch, tmp;
    int level = 0;
    int e_sign = 1;
    BOOL zero_flag = TRUE;

    memset(buf, 0, buf_size);

    k = 0;
    e = 0;
    for(i = 0; i < str_len; i++) {
        ch = str[i];
        if(ch == ' ') {
            continue;
        }
        if(level == 0 && k == 0 && ch == '0') {
            ret = i + 1;
        } else if(level == 1 && k == 0 && ch == '0') {
            e--;
            ret = i + 1;
        } else if(level == 0 && k == 0 && ch == '-')  {
            sign = 0x80;
            ret = i + 1;
        } else if(level == 0 && k == 0 && ch == '+')  {
            sign = 0;
            ret = i + 1;
        } else if(level == 0 && ch == '.') {
            ret = i + 1;
            level++;
        } else if(ch >= '0' && ch <= '9') {
            if(k == (buf_size - 1) * 2) {
                tmp = ch - 0x30;
                if(tmp >= 5) {
                    ret2 = round_up(buf, buf_size);
                    if(ret2 < 0) {
                        return ret2;
                    }
                    if(buf[0] != 0) {
                        buf[0] = 0;
                        e++;
                    }
                }
                k++;
                if(level == 0) {
                    e++;
                }
                ret = i + 1;
            } else if(k > (buf_size - 1) * 2) {
                k++;
                if(level == 0) {
                    e++;
                }
                ret = i + 1;
            } else {
                tmp = ch - 0x30;
                if(k % 2 == 0) {
                    tmp <<= 4;
                }
                buf[k / 2 + 1] |= tmp;
                ret = i + 1;
                k++;
                if(level == 0) {
                    e++;
                }
            }
        } else {
            break;
        }
    }

    level = 0;
    e2 = 0;
    ret2 = ret;
    for(; i < str_len; i++) {
        ch = str[i];
        if(ch == ' ') {
            continue;
        }
        if(level == 0 && (ch == 'e' || ch == 'E')) {
            level++;
        } else if(level == 1 && ch == '+') {
            e_sign = 1;
            level++;
        } else if(level == 1 && ch == '-') {
            e_sign = -1;
            level++;
        } else if(level != 0 && ch >= '0' && ch <= '9') {
            e2 = e2 * 10 + (ch - '0');
            ret = i + 1;
        } else {
            break;
        }
    }
    e = e + e2 * e_sign;
    if(e > 63 || e < -64) {
        return BCDF_OVERFLOW_ERR;
    }
    buf[0] = sign | (e + 0x40);
    if((buf[0] & 0xff) == 0x80) {
        buf[0] = 0;
    } else {
        for(i = 1; i < buf_size; i++) {
            if(buf[i] != 0) {
                zero_flag = FALSE;
                break;
            }
        }
        if(zero_flag) {
            buf[0] = 0;
        }
    }

    return ret;
}

static int round_up(char *buf, int buf_size)
{
    int i;
    char tmp;

    tmp = buf[0];
    buf[buf_size - 1]++;
    for(i = buf_size - 1; i >=1; i--) {
        if((buf[i] & 0x0f) <= 9) {
            return 0;
        } else {
            buf[i] += 0x10;
            buf[i] &= 0xf0;
        }
        if((buf[i] & 0xf0) <= 0x90) {
            return 0;
        } else {
            buf[i-1]++;
            buf[i] &= 0x0f;
        }
    }
    if(buf[0] == tmp) {
        return 0;
    }
    for(i = buf_size - 1; i >=1; i--) {
        buf[i] = (buf[i] >> 4) & 0x0f;
        buf[i] = buf[i] | (buf[i-1] << 4);
    }
    return 0;
}