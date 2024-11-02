    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_iniplt
    PUBLIC _msxsub_dos_iniplt
    PUBLIC ___msxsub_dos_iniplt
    GLOBAL dos_extrom

;;;; void msxsub_dos_iniplt();
msxsub_dos_iniplt:
_msxsub_dos_iniplt:
___msxsub_dos_iniplt:
    push ix
    
    ld ix,MSXSUB_INIPLT
    call dos_extrom
    pop ix
    ret

