    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_curdrv
    PUBLIC _dos1_curdrv
    PUBLIC ___dos1_curdrv
    EXTERN msxlib_doscall

; /* カレントドライブの取得 */
; uint8_t __LIB__ dos1_curdrv(void) __smallc;
dos1_curdrv:
_dos1_curdrv:
___dos1_curdrv:
    ld c,_CURDRV
    jp msxlib_doscall
