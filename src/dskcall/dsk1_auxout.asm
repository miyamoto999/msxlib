; /*********************************************************
;  dsk1_auxout.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_auxout.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_auxout
    PUBLIC _dsk1_auxout
    PUBLIC ___dsk1_auxout

; /* 補助出力 */
; void __LIB__ dsk1_auxout(char ch) __smallc;
dsk1_auxout:
_dsk1_auxout:
___dsk1_auxout:
    ld hl,2
    add hl,sp

    ld e,(hl)
    
    ld c,_AUXOUT
    jp BDOS_DSK
