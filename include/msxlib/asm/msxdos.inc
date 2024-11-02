BDOS:       equ     0x0005
BDOS_DSK:   equ     0xf37d

_CONOUT:    equ     0x02
_DIRIO:     equ     0x06
_CONST:     equ     0x0b
_FOPEN:     equ     0x0f
_FCLOSE:    equ     0x10
_FMAKE:     equ     0x16
_SETDTA:    equ     0x1a
_WRBLK:     equ     0x26
_RDBLK:     equ     0x27
_OPEN:      equ     0x43
_CREATE:    equ     0x44
_CLOSE:     equ     0x45
_READ:      equ     0x48
_WRITE:     equ     0x49
_PARSE:     equ     0x5b        ; パス名の解析
_PFILE:     equ     0x5c        ; ファイル名の解析
_DEFAB:     equ     0x63
_DEFER:     equ     0x64
_DOSVER:    equ     0x6f