; /*********************************************************
;  dsk1_setdta.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_setdta.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_setdta
    PUBLIC _dsk1_setdta
    PUBLIC ___dsk1_setdta


; /* ディスク転送アドレスのセット */
; void dos_setdta(void *dta);

dsk1_setdta:
_dsk1_setdta:
___dsk1_setdta:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c, _SETDTA
    jp BDOS_DSK
