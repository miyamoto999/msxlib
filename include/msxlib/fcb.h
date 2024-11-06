#ifndef __FCB_H__
#define __FCB_H__

#include <stdint.h>

#define FCB_NAME_SIZE   8
#define FCB_EXT_SIZE    3

typedef struct msx_fcb1 {
    uint8_t     drive;      /* ドライブ番号 */
    char        name[FCB_NAME_SIZE];    /* ファイル名 */
    char        ext[FCB_EXT_SIZE];     /* ファイルタイプ */
    uint8_t     cur_blk;    /* カレントブロック */
    char        dmy1;
    uint16_t    record_size;    /* レコードサイズ */
    long        file_size;      /* ファイルサイズ */
    uint8_t     date[2];        /* 日付 */
    uint8_t     time[2];        /* 時刻 */
    uint8_t     dev_id;         /* デバイスID */
    uint8_t     dir_loc;        /* ディレクトリロケーション */
    uint16_t    start_cluster;  /* 先頭クラスタ */
    uint16_t    end_cluster;    /* 最終クラスタ */
    uint16_t    relative_pos;   /* 相対位置 */
    uint8_t     cur_record;     /* カレントレコード */
    long        random_record;  /* ランダムレコード */
} MSX_FCB1;

typedef struct msx_fcb2 {
    uint8_t     drive;      /* ドライブ番号 */
    char        name[FCB_NAME_SIZE];    /* ファイル名 */
    char        ext[FCB_EXT_SIZE];     /* ファイルタイプ */
    uint8_t     ext_num_low;    /* エクステント番号(下位) */
    char        attr;           /* ファイル属性 */
    uint8_t     ext_num_high;   /* エクステント番号(上位) */
    uint8_t     rec_count;      /* レコードカウント */
    long        file_size;      /* ファイルサイズ */
    uint32_t    vol_id;         /* ボリュームID */
    uint8_t     dmy1[8];
    uint8_t     cur_record;     /* カレントレコード */
    long        random_record;  /* ランダムレコード */
} MSX_FCB2;

typedef union msx_fcb {
    MSX_FCB1 v1;
    MSX_FCB2 v2;
} MSX_FCB;

BOOL __LIB__ msx_fcb_init(MSX_FCB *fcb, const char *filename) __smallc;

#endif