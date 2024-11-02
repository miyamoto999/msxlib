
    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dos_kilbuf
    PUBLIC _msxmain_dos_kilbuf
    PUBLIC ___msxmain_dos_kilbuf

;;;; void msxmain_dos_kilbuf();
msxmain_dos_kilbuf:
_msxmain_dos_kilbuf:
___msxmain_dos_kilbuf:
    push ix
    ; キー入力バッファをクリア
    ld ix, MSXMAIN_KILBUF
    call MSXMAIN_CALSLT
    ei
    pop ix

    ret
