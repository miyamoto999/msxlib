    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos_scode
    PUBLIC _dos_scode
    PUBLIC ___dos_scode
    EXTERN msxlib_doscall


; /* 自作Z80エミュレータ用に拡張した終了コードを設定するファンクションコール */
; void __LIB__ dos_scode(uint8_t exit_code) __smallc;
dos_scode:
_dos_scode:
___dos_scode:

    ld hl,2
    add hl,sp

    ld e,(hl)
    ld c,_SCODE
    jp msxlib_doscall
