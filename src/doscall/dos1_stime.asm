    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_stime
    PUBLIC _dos1_stime
    PUBLIC ___dos1_stime
    EXTERN msxlib_doscall


; /* 時間の設定 */
; uint8_t __LIB__ dos1_stime(uint8_t hour, uint8_t min, uint8_t sec) __smallc;
;
;   sp + 2  sec
;   sp + 4  min
;   sp + 6  hour
;
dos1_stime:
_dos1_stime:
___dos1_stime:
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
    call msxlib_doscall

    ld l,a
    ret
