    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fclose
    PUBLIC _dos1_fclose
    PUBLIC ___dos1_fclose
    EXTERN msxlib_doscall


; /* ファイルのクローズ */
; int8_t dos1_fclose(void *dta);
dos1_fclose:
_dos1_fclose:
___dos1_fclose:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FCLOSE
    jp msxlib_doscall
