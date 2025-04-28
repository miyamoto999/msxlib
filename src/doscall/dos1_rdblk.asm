    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_rdblk
    PUBLIC _dos1_rdblk
    PUBLIC ___dos1_rdblk
    EXTERN msxlib_doscall


; /* ランダムブロック読み込み */
; uint8_t dos1_rdblk(void *fcb, uint16_t rec_num, uint16_t *read_size);
;   sp + 2 read_size
;   sp + 4 rec_num
;   sp + 6 fcb
dos1_rdblk:
_dos1_rdblk:
___dos1_rdblk:
    ld hl,4
    add hl,sp

    ; rec_numを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ; fcbを取り出す
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ex hl,de

    ld c,_RDBLK
    call msxlib_doscall

    ex hl,de
    ld b,a

    ; read_sizeに読み込んだサイズを設定する。
    ld hl,2
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    ld (hl),e
    inc hl
    ld (hl),d

    ld l,b

    ret