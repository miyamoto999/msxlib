    include "msxlib/asm/rbuf.inc"

    SECTION code_user
    PUBLIC as_rbuf_add_data
    GLOBAL as_rbuf_get_size

; リングバッファにデータを追加
;   ix <- rbuf
;   a <- data
; 戻り値
;   a <- 0:失敗、1:成功
;
; BOOL rbuf_add_data(RBUF *rbuf, const char data)
; {
;     if(((rbuf->write_idx + 1) & rbuf->buf_mask) == rbuf->read_idx) {
;         return FALSE;
;     }
;     rbuf->buf[rbuf->write_idx] = data;
;     rbuf->write_idx = (rbuf->write_idx + 1) & rbuf->buf_mask;

;     return TRUE;
; }

as_rbuf_add_data:
    push af
    call as_rbuf_get_size

    ld a,(ix+RBUF_BUF_MASK_OFFSET+1)
    xor h
    jr nz,ADD_DATA
    ld a,(ix+RBUF_BUF_MASK_OFFSET)
    xor l
    jr z,FALSE_END
ADD_DATA:
    pop af
    ld l,(ix+RBUF_BUF_OFFSET)
    ld h,(ix+RBUF_BUF_OFFSET+1)
    ld e,(ix+RBUF_WRITE_IDX_OFFSET)
    ld d,(ix+RBUF_WRITE_IDX_OFFSET+1)
    add hl,de
    ld (hl),a

    inc de
    ld a,(ix+RBUF_BUF_MASK_OFFSET)
    and e
    ld (ix+RBUF_WRITE_IDX_OFFSET),a
    ld a,(ix+RBUF_BUF_MASK_OFFSET+1)
    and d
    ld (ix+RBUF_WRITE_IDX_OFFSET+1), a

    ld a,1
    ret

FALSE_END:
    pop af
    xor a
    ret
