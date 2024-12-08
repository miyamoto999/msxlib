; DTA部分を30バントダンプする。

include "msxlib/asm/msxdos.inc"

org 0x0100

GLOBAL DUMP2

SECTION code_user

START:
    ld hl, DTA
    ld de, hl
    ld bc, 30
    call DUMP2
    ret

