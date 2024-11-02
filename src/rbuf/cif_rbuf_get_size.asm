    SECTION code_user
    GLOBAL as_rbuf_get_size
    PUBLIC rbuf_get_size
    PUBLIC _rbuf_get_size
    PUBLIC ___rbuf_get_size

;
; リングバッファに入っているデータの数を取得する。(C言語IF)
; int rbuf_get_size(const RBUF *rbuf);
;
rbuf_get_size:
_rbuf_get_size:
___rbuf_get_size:
    ld hl,2
    add hl,sp

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push ix
    push hl
    pop ix

    call as_rbuf_get_size
    pop ix
    
    ret