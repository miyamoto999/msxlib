; /*********************************************************
;  dsk1_fdel.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_fdel.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_fdel
    PUBLIC _dsk1_fdel
    PUBLIC ___dsk1_fdel


; /* ファイルの削除(FCB) */
; uint8_t __LIB__ dsk1_fdel(MSX_FCB *fcb) __smallc;
dsk1_fdel:
_dsk1_fdel:
___dsk1_fdel:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FDEL
    jp BDOS_DSK