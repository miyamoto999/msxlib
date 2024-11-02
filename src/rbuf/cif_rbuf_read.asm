    SECTION code_user
    PUBLIC rbuf_read
    PUBLIC _rbuf_read
    PUBLIC ___rbuf_read
    GLOBAL as_rbuf_read

;
; リングバッファに入っているデータを取得する。(C言語IF)
;
; int rbuf_read(RBUF *rbuf, char *buf, int size);
;
rbuf_read:
_rbuf_read:
___rbuf_read:
    ; sizeを取り出す
    ld hl,2
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; bufを取り出す
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ; rbufを取り出す
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    push ix
    push hl
    pop ix

    ld h,b
    ld l,c

    call as_rbuf_read
    pop ix

    ret