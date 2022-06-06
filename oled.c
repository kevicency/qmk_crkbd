#include QMK_KEYBOARD_H
#include <stdio.h>
#include "layers.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

void oled_render_layer_state(void) {
    // oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("COLEMAK: "), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("GAMING:  "), false);
            break;
    }
    // oled_write_ln_P(PSTR(layer_state), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK:
        case _GAMING:
            oled_write_P(PSTR("Base "), false);
            break;
        case _GAMING_EXT:
            oled_write_P(PSTR("Ext  "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num  "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _UTIL:
            oled_write_P(PSTR("Util "), false);
            break;
        default:
            oled_write_P(PSTR("Unkn "), false);
        break;
    }
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
}

void oled_render_mod_state(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR(""), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR(""), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT  ") : PSTR(""), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD  ") : PSTR(""), false);
}

#ifdef RGBLIGHT_ENABLE
void oled_render_rgb_state(void) {
    static char rgbStatusLine1[26] = {0};
    snprintf(rgbStatusLine1, sizeof(rgbStatusLine1), "RGB: %d ", rgblight_get_mode());
    oled_write(rgbStatusLine1, false);
    static char rgbStatusLine2[26] = {0};
    snprintf(rgbStatusLine2, sizeof(rgbStatusLine2), "%d, %d, %d", rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
    oled_write_ln(rgbStatusLine2, false);
}
#endif

char keylog_str[12] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];

    snprintf(keylog_str, sizeof(keylog_str), "%c: k%-8d",
            name, keycode);
    }
}

void oled_render_keylog(void) {
    oled_write_ln(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_write_ln_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_mod_state();
        oled_render_keylog();
    #ifdef RGBLIGHT_ENABLE
        oled_render_rgb_state();
    #endif
    } else {
        oled_render_logo();
    }
    return false;
}

bool oled_process_record(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}
