    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_verify
    PUBLIC _dos1_verify
    PUBLIC ___dos1_verify


; /* ベリファイフラグのセット・リセット */
; void __LIB__ dos1_verify(BOOL onoff);
dos1_verify:
_dos1_verify:
___dos1_verify:
    ld hl,2
    add hl,sp

    ld e,(hl)

    ld c,_VERIFY
    jp BDOS
