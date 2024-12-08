    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_seldsk
    PUBLIC _dos1_seldsk
    PUBLIC ___dos1_seldsk


; /* ディスクの選択 */
; uint8_t __LIB__ dos1_seldsk(uint8_t drv) __smallc;
dos1_seldsk:
_dos1_seldsk:
___dos1_seldsk:
    ld hl,2
    add hl,sp

    ld e,(hl)

    ld c,_SELDSK
    jp BDOS
