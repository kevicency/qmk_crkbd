#include QMK_KEYBOARD_H

const key_override_t ctrl_f = ko_make_basic(MOD_MASK_CTRL, KC_F, C(KC_RGHT)); //MocOS Desktop Navigation
const key_override_t ctrl_n = ko_make_basic(MOD_MASK_CTRL, KC_N, C(KC_UP));  //MocOS Desktop Navigation
const key_override_t ctrl_p = ko_make_basic(MOD_MASK_CTRL, KC_P, C(KC_DOWN));  //MocOS Desktop Navigation
const key_override_t ctrl_b = ko_make_basic(MOD_MASK_CTRL, KC_B, C(KC_LEFT));  //MocOS Desktop Navigation
const key_override_t bsp_del = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);  //  Shift+Bksp sends Delete

const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_f,
    &ctrl_n,
    &ctrl_p,
    &ctrl_b,
    &bsp_del,
    NULL
};