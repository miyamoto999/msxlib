    include "msxlib/asm/iot.inc"


    SECTION code_user
    PUBLIC iot_write
    PUBLIC _iot_write
    PUBLIC ___iot_write
    GLOBAL as_iot_puts,as_strlen

; nodeにデータを設定する。
; void iot_write(const char *node, char *buf, uint8_t size);
iot_write:
_iot_write:
___iot_write:
    ; sizeを取り出す
    ld hl,2
    add hl,sp
    
    ld c,(hl)
    inc hl
    inc hl

    ; bufを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; nodeを取り出す
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push hl
    ; nodeの文字数をカウント
    call as_strlen
    pop hl

    jp as_iot_puts