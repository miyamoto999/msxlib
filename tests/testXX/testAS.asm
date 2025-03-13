		include "msxlib/asm/msxdos.inc"
		include "msxlib/asm/msxbios.inc"
		include "msxlib/asm/msxwork.inc"

			ORG 0x0100
			
			LD DE,MSG1
			LD C,_STROUT
			CALL BDOS

			ld de,MSG2
			ld b,1
			ld hl,13
			ld c,_WRITE
			call BDOS

			ld b,2
			ld de,MSG3
			ld hl,20
			ld c,_WRITE
			call BDOS

			ld hl,MSG4
LOOP1:
			ld a,(hl)
			inc hl
			or a
			jr z,EXIT_LOOP

			push hl
			; 1文字出力する
			ld ix, MSXMAIN_CHPUT
			; メインスロットを取り出す。
			ld iy,(MSXWORK_EXPTBL - 1)
			call MSXMAIN_CALSLT
			ei
			pop hl

			jr LOOP1
EXIT_LOOP:

			RET
			
MSG1:		db "DOS1 _STROUT", 0x0d, 0x0a, "$"
MSG2:		db "DOS2 _WRITE", 0x0d, 0x0a, 0	
MSG3:		db "DOS2 _WRITE stderr", 0x0d, 0x0a, 0	
MSG4:		db "_CHPUT", 0x0d, 0x0a, 0
			