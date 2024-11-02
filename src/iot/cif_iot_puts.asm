
    SECTION code_user
    PUBLIC iot_puts
    PUBLIC _iot_puts
    PUBLIC ___iot_puts
    GLOBAL as_strlen,as_iot_puts

; nodeに文字列を設定する。(C言語)
; BOOL iot_puts(const char *node, const char *val);
iot_puts:
_iot_puts:
___iot_puts:

    ; valのアドレスを取り出して
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld h,d
    ld l,e
    ; valの文字数をカウント
    call as_strlen
    ld c,b

    ; nodeのアドレスを取り出して
    ld hl,4
    add hl,sp

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push hl
    ; nodeの文字数をカウント
    call as_strlen
    pop hl

    call as_iot_puts

    ld l,a

    ret
