; /*********************************************************
;  dsk1_stime.asm mk_dskcallversion.sh によって自動生成されるファイルなので
;  書き換えないでください。

;   Do not rewrite dsk1_stime.asm as this file is
;  automatically generated by mk_dskcallversion.sh.

;  *********************************************************/

    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dsk1_stime
    PUBLIC _dsk1_stime
    PUBLIC ___dsk1_stime


; /* 時間の設定 */
; uint8_t __LIB__ dsk1_stime(uint8_t hour, uint8_t min, uint8_t sec) __smallc;
;
;   sp + 2  sec
;   sp + 4  min
;   sp + 6  hour
;
dsk1_stime:
_dsk1_stime:
___dsk1_stime:
    ld hl,2
    add hl,sp

    ld d,(hl)
    inc hl
    inc hl

    ld c,(hl)
    inc hl
    inc hl

    ld b,(hl)

    ld h,b
    ld l,c

    ld c, _STIME
    call BDOS_DSK

    ld l,a
    ret