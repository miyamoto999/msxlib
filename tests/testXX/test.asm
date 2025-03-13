    include "msxlib/asm/msxdos.inc"

    SECTION code_user
    PUBLIC test_msg1, _test_msg1, ___test_msg1


test_msg1:
_test_msg1:
___test_msg1:
    ld c,_STROUT
    ld de,MSG1
    call BDOS
    ret

MSG1:		db "MSG1", 0x0d, 0x0a, "$"
