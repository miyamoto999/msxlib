    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_cls
    PUBLIC _msxsub_dos_cls
    PUBLIC ___msxsub_dos_cls
    GLOBAL dos_extrom

;;;;; void msxsub_dos_cls();

msxsub_dos_cls:
_msxsub_dos_cls:
___msxsub_dos_cls:
    push ix
    ; 画面クリア
    ld ix, MSXSUB_CLSSUB
    call dos_extrom
    pop ix
    ret
