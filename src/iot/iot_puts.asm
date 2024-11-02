    include "msxlib/asm/iot.inc"


    SECTION code_user
    PUBLIC as_iot_puts
    GLOBAL as_iot_node_write, as_iot_str_write

; nodeに文字列を設定する。
;   hl <- nodeの文字列の先頭アドレス
;   b <- nodeの文字列の文字数
;   de <- 設定する文字列の先頭アドレス
;   c <- 設定する文字列の文字数
; 戻り値
;   a <- 0:失敗、1:成功
;
;    https://github.com/hra1129/for_MSX0/tree/main/sample_program/002_device/2023_05_30_1st_update_version/basicn
;    こちらのコードを元にしています。

as_iot_puts:
    push bc
    call as_iot_node_write
    pop bc

    rlca
    jr nc,NEXT

    xor a

    ret

NEXT:

    ld a, 0xe0
    out (IOT_PORT1),a
    ld a,1
    out (IOT_PORT1),a

    ld a,0x43           ; 値が文字列なら0x43
    out (IOT_PORT1),a

    ld b,c
    ex hl,de    
    call as_iot_str_write

    ld a,1

    ret


