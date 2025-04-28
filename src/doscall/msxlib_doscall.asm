    SECTION code_user
    PUBLIC msxlib_doscall
    EXTERN __bdos

msxlib_doscall:
    push ix
    call __bdos
    pop ix
    ret
