    SECTION code_user
    PUBLIC iot_geti
    PUBLIC _iot_geti
    PUBLIC ___iot_geti
    GLOBAL as_strlen,as_iot_geti

; nodeから数値を取得する(C言語IF)
; short iot_geti(const char *node);
iot_geti:
_iot_geti:
___iot_geti:

    ld hl,2
    add hl,sp

    ; nodeのアドレスを取り出して
    ld e,(hl)
    inc hl
    ld d,(hl)
    
    ld h,d
    ld l,e
    ; nodeの文字数をカウント
    call as_strlen

    ex hl,de

    jp as_iot_geti
