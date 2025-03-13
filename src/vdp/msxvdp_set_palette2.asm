    include "msxlib/asm/msxwork.inc"
    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC msxvdp_set_palette2
    PUBLIC _msxvdp_set_palette2
    PUBLIC ___msxvdp_set_palette2
    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_write_port_2

; void msxvdp_setPalette2(uint8_t pal, uint8_t r, uint8_t g, uint8_t b);
;   sp + 2 b
;   sp + 4 g
;   sp + 6 r
;   sp + 8  pal   
msxvdp_set_palette2:
_msxvdp_set_palette2:
___msxvdp_set_palette2:
    ; VDPレジスタ R16にパレット番号を設定
    ld a,(_g_msxvdp_write_port_1)
    ld c,a
    ld hl, 8
    add hl, sp

    di
    MAC_VDP_SET_REG 16, (hl)    ; VDPレジスタ16に値をセット
    ei

    ld a,(hl)
    ld (MSXWORK_RG16SAV),a  ; レジスタ16に設定する値を保存
    
    ; rgb値を書き込むポートをcに準備
    ld a,(_g_msxvdp_write_port_2)
    ld c,a

    ; r取り出し
    ld hl, 6
    add hl, sp
    ld a,(hl)
    ; 4ビットシフト
    sla a
    sla a
    sla a
    sla a
    ld d,a

    ; b取り出し
    ld hl, 2
    add hl,sp
    ld a,(hl)
    or d

    ; r,bをセット
    out (c),a    

    ; g取り出し
    ld hl,4
    add hl, sp
    ld a,(hl)

    ; gをセット
    out (c),a

    ret