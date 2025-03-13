    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC msxvdp_get_status, _msxvdp_get_status, ___msxvdp_get_status
    PUBLIC msxvdp_get_status_ndi, _msxvdp_get_status_ndi, ___msxvdp_get_status_ndi
    GLOBAL _g_msxvdp_write_port_1, _g_msxvdp_read_port_1

; /* ステータスレジスタの読み込み */
; uint8_t __LIB__ msxvdp_get_status(uint8_t st_reg) __smallc;
msxvdp_get_status:
_msxvdp_get_status:
___msxvdp_get_status:
    ; st_reg を取り出す。
    ld hl,2
    add hl,sp
    ld a,(hl)   ; st_regを読み込む

    di
    MAC_VDP_GET_STATUS l, a     ; VDPステータスレジスタの読み込み
    ei

    ret

; /* ステータスレジスタの読み込み */
; uint8_t __LIB__ msxvdp_get_status(uint8_t st_reg) __smallc;
msxvdp_get_status_ndi:
_msxvdp_get_status_ndi:
___msxvdp_get_status_ndi:
    ; st_reg を取り出す。
    ld hl,2
    add hl,sp
    ld a,(hl)   ; st_regを読み込む

    MAC_VDP_GET_STATUS l, a     ; VDPステータスレジスタの読み込み

    ret
