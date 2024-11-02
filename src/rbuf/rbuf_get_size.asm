    include "msxlib/asm/rbuf.inc"


    SECTION code_user
    PUBLIC as_rbuf_get_size


;
; リングバッファに入っているデータの数を取得する。
;
; int rbuf_get_size(const RBUF *rbuf)
; {
;     return (rbuf->write_idx - rbuf->read_idx) & rbuf->buf_mask;
; }
;
;   ix <- rbufのアドレス
;
; 戻り値
;   hl <- データ数
;
as_rbuf_get_size:
; (rbuf->write_idx - rbuf->read_idx)を計算する。
    ld l,(ix+RBUF_WRITE_IDX_OFFSET)         ;19
    ld h,(ix+RBUF_WRITE_IDX_OFFSET+1)       ;19
    ld e,(ix+RBUF_READ_IDX_OFFSET)          ;19
    ld d,(ix+RBUF_READ_IDX_OFFSET+1)        ;19

    or a                                    ;4
    sbc hl,de                               ;15
; & rbuf->buf_mask;を計算する。
    ld a,(ix+RBUF_BUF_MASK_OFFSET)          ;19
    and l                                   ;4
    ld l,a
    ld a,(ix+RBUF_BUF_MASK_OFFSET+1)        ;19
    and h                                   ;4
    ld h,a
    ret                                     ;10
                                            ;176
