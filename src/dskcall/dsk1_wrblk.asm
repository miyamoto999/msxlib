; /*********************************************************
;  dsk1_wrblk.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_wrblk.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_wrblk
    PUBLIC _dsk1_wrblk
    PUBLIC ___dsk1_wrblk


; /* ランダムブロック書き込み */
; int8_t dsk1_wrblk(void *fcb, uint16_t rec_num);
;   sp + 2 rec_num
;   sp + 4 fcb
dsk1_wrblk:
_dsk1_wrblk:
___dsk1_wrblk:
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
    call BDOS_DSK

    ld l,a

    ret