#ifndef __MSXDOS_H__
#define __MSXDOS_H__

#include <stdint.h>
#include <msxlib/msxlib.h>
#include <msxlib/msxdos.h>

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
    uint16_t    start_cluster;  /* 戦闘クラスタ */
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

/* ディスク転送アドレスのセット */
void __LIB__ dos1_setdta(void *dta) __smallc;
/* ファイルのクローズ */
int8_t __LIB__ dos1_fclose(void *fcb) __smallc;
/* ファイルの作成 */
int8_t __LIB__ dos1_fmake(void *fcb) __smallc;
/* ランダムブロック書き込み */
int8_t __LIB__ dos1_wrblk(void *fcb, uint16_t rec_num) __smallc;
/* 直接コンソールI/O */
char __LIB__ dos1_dirio(char code) __smallc;
/* コンソールステータス */
uint8_t __LIB__ dos1_const(void) __smallc;
/* ファイルのオープン */
int8_t __LIB__ dos1_fopen(void *fcb) __smallc;
/* ランダムブロック読み込み */
uint8_t __LIB__ dos1_rdblk(void *fcb, uint16_t rec_num, uint16_t *read_size) __smallc;

/* アボート終了ルーチンの定義 */
void __LIB__ dos2_defab(BOOL (*abort_routine)(uint8_t err1, uint8_t err2)) __smallc;
/* ディスクエラー処理ルーチンの定義 */
void __LIB__ dos2_defer(uint8_t (*dsker_routine)(uint8_t err, uint8_t drv, uint8_t flag, uint16_t sec_no)) __smallc;

/* ファイルハンドルの作成 */
uint8_t __LIB__ dos2_create(const char *filepath, uint8_t mode, uint8_t attr, uint8_t *handle) __smallc;

/* ファイルハンドルのクローズ */
uint8_t __LIB__ dos2_close(uint8_t handle) __smallc;
/* ファイルハンドルへの書き込み */
uint8_t __LIB__ dos2_write(uint8_t handle, void *buf, uint16_t count, uint16_t *bytes) __smallc;

/* MSX-DOSのバーション番号の取得 */
uint8_t __LIB__ dos2_dosver(uint16_t *kernel_ver, uint16_t *dos_ver) __smallc;

/* パス名の解析 */
uint8_t __LIB__ dos2_parse(const char *path, uint8_t vol_flag, char **last_str, char **start_filename, uint8_t *analysis_flag, uint8_t *drv) __smallc;
/* ファイル名の解析 */
void __LIB__ dos2_pfile(const char *filenmae, char *buf, char **last_str, uint8_t *analysis_flag) __smallc;
/* ファイルハンドルのオープン */
uint8_t __LIB__ dos2_open(const char *filepath, uint8_t mode, uint8_t *handle) __smallc;
/* ファイルハンドルからの読み出し */
uint8_t __LIB__ dos2_read(uint8_t handle, void *buf, uint16_t count, uint16_t *bytes) __smallc;

/****** DISK BASIC用 ******/
/* ディスク転送アドレスのセット */
void __LIB__ dsk1_setdta(void *dta) __smallc;
/* ファイルのクローズ */
int8_t __LIB__ dsk1_fclose(void *fcb) __smallc;
/* ファイルの作成 */
int8_t __LIB__ dsk1_fmake(void *fcb) __smallc;
/* ランダムブロック書き込み */
int8_t __LIB__ dsk1_wrblk(void *fcb, uint16_t rec_num) __smallc;
/* 直接コンソールI/O */
char __LIB__ dsk1_dirio(char code) __smallc;
/* コンソールステータス */
uint8_t __LIB__ dsk1_const(void) __smallc;
/* ファイルのオープン */
int8_t __LIB__ dsk1_fopen(void *fcb) __smallc;
/* ランダムブロック読み込み */
uint8_t __LIB__ dsk1_rdblk(void *fcb, uint16_t rec_num, uint16_t *read_size) __smallc;

/* アボート終了ルーチンの定義 */
void __LIB__ dsk2_defab(BOOL (*abort_routine)(uint8_t err1, uint8_t err2)) __smallc;
/* ディスクエラー処理ルーチンの定義 */
void __LIB__ dsk2_defer(uint8_t (*dsker_routine)(uint8_t err, uint8_t drv, uint8_t flag, uint16_t sec_no)) __smallc;

/* ファイルハンドルの作成 */
uint8_t __LIB__ dsk2_create(const char *filepath, uint8_t mode, uint8_t attr, uint8_t *handle) __smallc;

/* ファイルハンドルのクローズ */
uint8_t __LIB__ dsk2_close(uint8_t handle) __smallc;
/* ファイルハンドルへの書き込み */
uint8_t __LIB__ dsk2_write(uint8_t handle, void *buf, uint16_t count, uint16_t *bytes) __smallc;

/* MSX-DOSのバーション番号の取得 */
uint8_t __LIB__ dsk2_dosver(uint16_t *kernel_ver, uint16_t *dos_ver) __smallc;

/* パス名の解析 */
uint8_t __LIB__ dsk2_parse(const char *path, uint8_t vol_flag, char **last_str, char **start_filename, uint8_t *analysis_flag, uint8_t *drv) __smallc;
/* ファイル名の解析 */
void __LIB__ dsk2_pfile(const char *filenmae, char *buf, char **last_str, uint8_t *analysis_flag) __smallc;
/* ファイルハンドルのオープン */
uint8_t __LIB__ dsk2_open(const char *filepath, uint8_t mode, uint8_t *handle) __smallc;
/* ファイルハンドルからの読み出し */
uint8_t __LIB__ dsk2_read(uint8_t handle, void *buf, uint16_t count, uint16_t *bytes) __smallc;
/************/


/* ファイルオープンモード */
#define FILE_MODE_READ_ONLY      0x01
#define FILE_MODE_WRITE_ONLY     0x02
#define FILE_MODE_READ_WRITE     0x00
#define FILE_MODE_INHELITANCE    0x04
/* ファイルアトリビュート */
#define FILE_ATTR_READONLY      0x01
#define FILE_ATTR_HIDDEN        0x02
#define FILE_ATTR_SYSTEM        0x04
#define FILE_ATTR_VOL           0x08
#define FILE_ATTR_SUBDIR        0x10
#define FILE_ATTR_ARCH          0x20
#define FILE_ATTR_DEVICE        0x80
#define FILE_ATTR_NORMAL        0x00
#define FILE_ATTR_NEW           0x80

#define ERR_STOP        0x9f
#define ERR_CTRLC       0x9e
#define ERR_EOF         0xc7

#endif