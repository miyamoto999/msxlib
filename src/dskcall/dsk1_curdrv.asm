; /*********************************************************
;  dsk1_curdrv.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_curdrv.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_curdrv
    PUBLIC _dsk1_curdrv
    PUBLIC ___dsk1_curdrv

; /* カレントドライブの取得 */
; uint8_t __LIB__ dsk1_curdrv(void) __smallc;
dsk1_curdrv:
_dsk1_curdrv:
___dsk1_curdrv:
    ld c,_CURDRV
    jp BDOS_DSK
