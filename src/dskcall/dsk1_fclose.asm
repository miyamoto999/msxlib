; /*********************************************************
;  dsk1_fclose.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_fclose.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_fclose
    PUBLIC _dsk1_fclose
    PUBLIC ___dsk1_fclose


; /* ファイルのクローズ */
; int8_t dsk1_fclose(void *dta);
dsk1_fclose:
_dsk1_fclose:
___dsk1_fclose:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FCLOSE
    jp BDOS_DSK
