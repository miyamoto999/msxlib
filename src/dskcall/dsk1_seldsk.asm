; /*********************************************************
;  dsk1_seldsk.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_seldsk.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_seldsk
    PUBLIC _dsk1_seldsk
    PUBLIC ___dsk1_seldsk


; /* ディスクの選択 */
; uint8_t __LIB__ dsk1_seldsk(uint8_t drv) __smallc;
dsk1_seldsk:
_dsk1_seldsk:
___dsk1_seldsk:
    ld hl,2
    add hl,sp

    ld e,(hl)

    ld c,_SELDSK
    jp BDOS_DSK