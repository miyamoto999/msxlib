
SECTION code_user

PUBLIC print_msg
PUBLIC _print_msg
PUBLIC ___print_msg

EXTERN MSXDOS

defc _STROUT = 9

print_msg:
_print_msg:
___print_msg:
    push ix
    ld c,_STROUT
    ld de,MSG1
    call MSXDOS
    pop ix

    ret

MSG1:		db "MSG1", 0x0d, 0x0a, "$"
