    SECTION code_user
    PUBLIC iot_node_write
    PUBLIC _iot_node_write
    PUBLIC ___iot_node_write
    GLOBAL as_strlen, as_iot_node_write

; nodeをIOT_PORT1に書き込む(C言語)
; int8_t iot_node_write(const char *node);
iot_node_write:
_iot_node_write:
___iot_node_write:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld h,d
    ld l,e
    ; 文字数をカウントする。
    call as_strlen

    ; iot_node_writeを呼ぶ
    ex hl,de

    call as_iot_node_write

    ld l,a
    ret