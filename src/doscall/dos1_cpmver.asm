    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_cpmver
    PUBLIC _dos1_cpmver
    PUBLIC ___dos1_cpmver

; /* バージョン番号の取得 */
; uint16_t __LIB__ dos1_cpmver(void) __smallc;
dos1_cpmver:
_dos1_cpmver:
___dos1_cpmver:
    ld c,_CPMVER
    jp BDOS
