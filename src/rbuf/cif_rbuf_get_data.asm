    SECTION code_user
    PUBLIC rbuf_get_data
    PUBLIC _rbuf_get_data
    PUBLIC ___rbuf_get_data
    GLOBAL as_rbuf_get_data

;
; リングバッファに入っているデータ取得する(C言語IF)
;
rbuf_get_data:
_rbuf_get_data:
___rbuf_get_data:
    ld hl,2
    add hl,sp

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push ix
    push hl
    pop ix

    call as_rbuf_get_data

    pop ix

    ret