    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_wrblk
    PUBLIC _dos1_wrblk
    PUBLIC ___dos1_wrblk
    EXTERN msxlib_doscall


; /* ランダムブロック書き込み */
; int8_t dos1_wrblk(void *fcb, uint16_t rec_num);
;   sp + 2 rec_num
;   sp + 4 fcb
dos1_wrblk:
_dos1_wrblk:
___dos1_wrblk:
    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld h,b
    ld l,c

    ld c,_WRBLK
    call msxlib_doscall

    ld l,a

    ret