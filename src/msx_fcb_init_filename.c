#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <msxlib/msxlib.h>
#include <msxlib/fcb.h>

/* FCBのファイル名部分を初期化 */
BOOL __LIB__ msx_fcb_init_filename(MSX_FCB *fcb, const char *filename) __smallc
{
    int idx_start = 0, idx_colon = -1;
    int len = strlen(filename);
    int idx_dot = len;
    char *p;
    int drv = 0;
    BOOL wild_card = FALSE;

    memset(fcb->v1.name, ' ', FCB_NAME_SIZE + FCB_EXT_SIZE);

   /* 最初のスペースはとばす */
    while(filename[idx_start] == ' ') {
        idx_start++;
    }
    /* : の位置を探す */
    p = strchr(&filename[idx_start], ':');
    if(p) {
        idx_colon = p - &filename[idx_start] + idx_start;
        if(idx_colon - idx_start  == 1) {
            drv = toupper(filename[idx_start]);
            if(!(drv >= 'A' && drv <= 'Z')) {
                return FALSE;
            }
            drv -= 'A';
            fcb->v1.drive = drv + 1;
        }
        idx_start = idx_colon + 1;
    }
    /* 後ろから"."を探す */
    p = strrchr(&filename[idx_start], '.');
    if(p) {
        idx_dot = p - &filename[idx_start] + idx_start;
    }

    if(idx_start == idx_dot) {
        return FALSE;
    }
    if(idx_start == len) {
        return FALSE;
    }
    /* ファイル名をコピーする */
    for(int i = 0; i < FCB_NAME_SIZE; i++) {
        if(filename[idx_start + i] == '*') {
            wild_card = TRUE;
        }
        if(!wild_card && idx_start + i >= idx_dot) {
            break;
        }
        if(wild_card) {
            fcb->v1.name[i] = '?';
        } else {
            fcb->v1.name[i] = toupper(filename[idx_start + i]);
        }
    }
    wild_card = FALSE;
    /* 拡張子部分をコピーする */
    for(int i = 0; i < FCB_EXT_SIZE; i++) {
        if(filename[idx_dot + 1 + i] == '*') {
            wild_card = TRUE;
        }
        if(!wild_card && idx_dot + 1 + i >= len) {
            break;
        }
        if(wild_card) {
            fcb->v1.ext[i] = '?';
        } else {
            fcb->v1.ext[i] = toupper(filename[idx_dot + 1 + i]);
        }
    }
    return TRUE;
}
