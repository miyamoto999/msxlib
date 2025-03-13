#ifndef __MSXLIB_FCB_H__
#define __MSXLIB_FCB_H__

#include <stdint.h>

#define FCB_NAME_SIZE   8
#define FCB_EXT_SIZE    3

/* DOS1用のFCB構成 */
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

/* DOS2用のFCB構成 */
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

/* CP/M用のFCB構成 */
typedef struct cpm_fcb {
    uint8_t     drive;      /* ドライブ番号 */
    char        name[FCB_NAME_SIZE];    /* ファイル名 */
    char        ext[FCB_EXT_SIZE];     /* ファイルタイプ */
    uint8_t     ext_num_low;    /* エクステント番号(下位) */
    uint8_t     dmy1;
    uint8_t     ext_num_high;   /* エクステント番号(上位) */
    uint8_t     rec_count;      /* レコードカウント */
    uint8_t     al[16];
    uint8_t     cur_record;     /* カレントレコード */
    uint8_t     random_record[3];  /* ランダムレコード */
} CPM_FCB;

/* _FREN用のFCB構成 */
typedef struct msx_fcb_ren {
    uint8_t     old_drive;      /* 旧ドライブ番号 */
    char        old_name[FCB_NAME_SIZE];    /* 旧ファイル名 */
    char        old_ext[FCB_EXT_SIZE];     /* 旧ファイルタイプ */
    char        dmy[4];                 /* ダミー _*/
    uint8_t     new_drive;      /* 新ドライブ番号(無視) */
    char        new_name[FCB_NAME_SIZE];    /* 新ファイル名 */
    char        new_ext[FCB_EXT_SIZE];     /* 新ファイルタイプ */
} MSX_FCB_REN;

typedef union msx_fcb {
    MSX_FCB1 v1;
    MSX_FCB2 v2;
    MSX_FCB_REN ren;
    CPM_FCB cpm;
} MSX_FCB;

/* FCBの初期化 */
BOOL __LIB__ msx_fcb_init(MSX_FCB *fcb, const char *filename) __smallc;

/* _FREN用のFCB初期化 */
BOOL __LIB__ msx_fcb_init_ren(MSX_FCB *fcb, const char *old_filename, const char *new_filename) __smallc;

/* FCBのファイル名部分を初期化 */
BOOL __LIB__ msx_fcb_init_filename(MSX_FCB *fcb, const char *filename) __smallc;

/* CP/MのFCBのランダムレコードを設定 */
#define cpm_fcb_set_random_record(fcb, rec)     (fcb)->cpm.random_record[0] = (long)rec & 0xff; \
                                                (fcb)->cpm.random_record[1] = ((long)rec >> 8) & 0xff; \
                                                (fcb)->cpm.random_record[2] = ((long)rec >> 16) & 0xff    
/* CP/M用のFCBのランダムレコードを取得 */
#define cpm_fcb_get_random_record(fcb)          ((fcb)->v1.random_record & 0x00ffffff)      

#endif