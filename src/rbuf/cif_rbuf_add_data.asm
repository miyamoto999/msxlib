    SECTION code_user
    PUBLIC rbuf_add_data
    PUBLIC _rbuf_add_data
    PUBLIC ___rbuf_add_data
    GLOBAL as_rbuf_get_size, as_rbuf_add_data

; リングバッファにデータを追加(C言語IF)
; ; BOOL rbuf_add_data(RBUF *rbuf, const char data);
;
rbuf_add_data:
_rbuf_add_data:
___rbuf_add_data:
    ld hl,2
    add hl,sp

    ld a,(hl)
    inc hl
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)

    push ix
    push de
    pop ix

    call as_rbuf_add_data

    ld l,a
    pop ix
    
    ret
