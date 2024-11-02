    SECTION code_user
    PUBLIC iot_gets
    PUBLIC _iot_gets
    PUBLIC ___iot_gets
    GLOBAL as_strlen,as_iot_gets

; nodeから文字列を取得する。(C言語IF)
; char *iot_gets(const char *node);
iot_gets:
_iot_gets:
___iot_gets:

    ld hl,2
    add hl,sp

    ; nodeのアドレスを取り出して
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ld d,h
    ld e,l
    ; nodeの文字数をカウント
    call as_strlen

    ex hl,de

    jp as_iot_gets
