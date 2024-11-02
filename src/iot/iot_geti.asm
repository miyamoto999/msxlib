    include "msxlib/asm/iot.inc"


    SECTION code_user
    PUBLIC as_iot_geti
    GLOBAL as_iot_node_write

; nodeから数値を取得する
;   hl <- nodeの文字列の先頭アドレス
;   b <- nodeの文字列の文字数
;
;   戻り値
;   hl <- nodeの値
;
;    https://github.com/hra1129/for_MSX0/tree/main/sample_program/002_device/2023_05_30_1st_update_version/basicn
;    こちらのコードを元にしています。
;
; short iot_geti(const char *node)
; {
;     iot_node_write(node);
; ///
;     outp(IOT_PORT1, 0xe0);
;     outp(IOT_PORT1, 1);
;     outp(IOT_PORT1, 1);
;     outp(IOT_PORT1, 0x80);

;     short ret = 0;

;     int r = inp(IOT_PORT1);

;     r = inp(IOT_PORT1);
;     ret = r;
;     r = inp(IOT_PORT1);
;     ret |= (r << 8);

;     return ret;
; }


as_iot_geti:
    call as_iot_node_write
    rlca
    jr nc,NEXT

    ld hl,0
    ret

NEXT:

    ld a, 0xe0
    out (IOT_PORT1),a
    ld a,1
    out (IOT_PORT1),a
    ld a,1              ; 取得するデータの型(1は整数値、3は文字列)
    out (IOT_PORT1),a

    ;
    ld a,0x80
    out (IOT_PORT1),a

    in a,(IOT_PORT1)

    in a,(IOT_PORT1)
    ld l,a
    in a,(IOT_PORT1)
    ld h,a

    ret
