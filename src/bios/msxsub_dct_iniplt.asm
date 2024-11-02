    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dct_iniplt
    PUBLIC _msxsub_dct_iniplt
    PUBLIC ___msxsub_dct_iniplt

;;;; void msxsub_dct_iniplt()

msxsub_dct_iniplt:
_msxsub_dct_iniplt:
___msxsub_dct_iniplt:

    push ix
    ld ix,MSXSUB_INIPLT

    call MSXMAIN_EXTROM
    pop ix
    
    ret