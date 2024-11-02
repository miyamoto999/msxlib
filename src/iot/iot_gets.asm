    include "msxlib/asm/iot.inc"


    SECTION code_user
    PUBLIC as_iot_gets
    GLOBAL as_iot_node_write,_g_iot_common_buf

; nodeから文字列を取得する。
;   hl <- nodeの文字列の先頭アドレス
;   b <- nodeの文字列の文字数
;
;   戻り値
;   hl <- 取得した文字列のアドレス
;           0:エラー
;
;    https://github.com/hra1129/for_MSX0/tree/main/sample_program/002_device/2023_05_30_1st_update_version/basicn
;    こちらのコードを元にしています。
;
; char *iot_gets(const char *node)
; {
;     iot_node_write(node);

;     outp(IOT_PORT1, 0xe0);
;     outp(IOT_PORT1, 1);
;     outp(IOT_PORT1, 3);
;     outp(IOT_PORT1, 0x80);

;     int len = inp(IOT_PORT1);
;     int i;
;     for(i = 0; i < len; i++) {
;         g_iot_common_buf[i] = inp(IOT_PORT1);
;     }
;     g_iot_common_buf[i] = 0;

;     return g_iot_common_buf;
; }


as_iot_gets:
    call as_iot_node_write
    rlca
    jr nc,NEXT

    ld hl,0
    ret

NEXT:

    ; 取得するデータ型をセット
    ld a, 0xe0
    out (IOT_PORT1),a
    ld a,1
    out (IOT_PORT1),a
    ld a,3                  ; 取得するデータの型をセット(3は文字列、1は整数値)
    out (IOT_PORT1),a

    ld a,0x80
    out (IOT_PORT1),a

    in a,(IOT_PORT1)        ; 文字数(データ数)
    ld b,a

    ld c,IOT_PORT1
    ld hl,_g_iot_common_buf
    inir
    ld (hl),0

    ld hl,_g_iot_common_buf

    ret

