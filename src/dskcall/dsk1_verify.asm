; /*********************************************************
;  dsk1_verify.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_verify.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_verify
    PUBLIC _dsk1_verify
    PUBLIC ___dsk1_verify


; /* ベリファイフラグのセット・リセット */
; void __LIB__ dsk1_verify(BOOL onoff);
dsk1_verify:
_dsk1_verify:
___dsk1_verify:
    ld hl,2
    add hl,sp

    ld e,(hl)

    ld c,_VERIFY
    jp BDOS_DSK
