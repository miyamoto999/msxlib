include "msxlib/asm/msxbios.inc"
include "msxlib/asm/msxwork.inc"

            SECTION code_user
            public dos_extrom


; MSX-DatapackにあったMSX-DOS上からSUB-ROMを呼ぶ方法の
; コードそのまま。
; _calsubというシンボルだったけどextromの代わりみたいなもん
; でdosから使うものだからdos_extromにした。
;
;
;       +0    inc    sp
;       +1    inc    sp
;       +2    ld     ix,<sub-ROM entry>
;       +6    nop
;       +7    jp     extrom
dos_extrom:
        exx                          ; Save argument registers over setup
        ex     af,af'
        ld     hl,MSXMAIN_EXTROM
        push   hl
        ld     hl,0c300h             ; jp xxxx, nop
        push   hl
        push   ix                    ; SUB ROM entry
        ld     hl,0x021dd             ; ld ix,xxxx
        push   hl
        ld     hl,0x03333             ; inc sp, inc sp
        push   hl
        ld     hl,0
        add    hl,sp
        ld     a,0xc3
        ld     (MSXWORK_H_NMI),a
        ld     (MSXWORK_H_NMI+1),hl
        ex     af,af'                ; Restore registers
        exx
;
        ld     ix,MSXMAIN_NMI
        ld     iy,(MSXWORK_EXPTBL-1)
        call   MSXMAIN_CALSLT
        ei
;
        ld     hl,10                 ; Throw away the interface routine
        add    hl,sp
        ld     sp,hl
        ret
