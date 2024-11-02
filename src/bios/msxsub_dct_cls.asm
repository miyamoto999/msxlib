    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dct_cls
    PUBLIC _msxsub_dct_cls
    PUBLIC ___msxsub_dct_cls

;;;;; void msxsub_dos_cls();

msxsub_dct_cls:
_msxsub_dct_cls:
___msxsub_dct_cls:
    push ix
    ; 画面クリア
    ld ix, MSXSUB_CLSSUB
    call MSXMAIN_EXTROM
    pop ix

    ret
