
org 0x0100

GLOBAL DUMP

SECTION code_user

START:
    ld hl, DATA
    ld bc, 10
    call DUMP
    ret

SECTION rodata_user
DATA:   db "0123456789"