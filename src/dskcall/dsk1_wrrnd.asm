; /*********************************************************
;  dsk1_wrrnd.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_wrrnd.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_wrrnd
    PUBLIC _dsk1_wrrnd
    PUBLIC ___dsk1_wrrnd

; /* ランダム書き込み(FCB) */
; uint8_t __LIB__ dsk1_wrrnd(MSX_FCB *fcb) __smallc;
dsk1_wrrnd:
_dsk1_wrrnd:
___dsk1_wrrnd:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_WRRND
    jp BDOS_DSK
