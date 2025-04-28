    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_close
    PUBLIC _dos2_close
    PUBLIC __dos2_close
    EXTERN msxlib_doscall


; /* ファイルハンドルのクローズ */
; uint8_t dos2_close(uint8_t handle);
dos2_close:
_dos2_close:
__dos2_close:
    ld hl,2
    add hl,sp

    ld b,(hl)

    ld c,_CLOSE
    call msxlib_doscall

    ld l,a
    
    ret