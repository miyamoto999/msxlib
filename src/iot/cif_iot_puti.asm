    SECTION code_user
    PUBLIC iot_puti
    PUBLIC _iot_puti
    PUBLIC ___iot_puti
    GLOBAL as_strlen,as_iot_puti

; nodeに数値を設定する。(C言語)
; BOOL iot_puti(const char *node, const int val);
iot_puti:
_iot_puti:
___iot_puti:

    ; valを取り出して
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; nodeのアドレスを取り出して
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push hl
    ; nodeの文字数をカウント
    call as_strlen
    pop hl

    call as_iot_puti

    ld l,a

    ret
