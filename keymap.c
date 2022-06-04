/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _COLEMAK = 0,
    _GAMING,
    _GAMING_EXT,
    _SYM,
    _NUM,
    _NAV,
    _UTIL,
};

enum tap_dance_codes {
    DANCE_DOT_COMM,
    DANCE_TAB,
    DANCE_SLSH_TILDE
};

// Base Layers
#define COLEMAK DF(_COLEMAK)
#define GAMING  DF(_GAMING)

#define TO_COLE TO(_COLEMAK)
#define TO_GAME TO(_GAMING)
#define TO_UTIL TO(_UTIL)

// Other Layers
#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)

#define T_NUM TT(_NUM)
#define S_NUM MO(_NUM)

#define S_NAV MO(_NAV)
#define S_UTIL MO(_UTIL)

#define EXT_SL LT(_GAMING_EXT, KC_SLSH)

#define TAB_FWD RCTL(KC_TAB)
#define TAB_BCK LCTL(LSFT(KC_TAB))
#define TAB_CLS LGUI(KC_W)
#define NAV_FWD LGUI(KC_RBRACKET)
#define NAV_BCK LGUI(KC_LBRACKET)

#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT) 
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RCTL OSM(MOD_RCTL)

#define QK_FLSH LSFT(QK_MAKE)

#define MT_SPC MT(MOD_LCTL, KC_SPACE)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_T MT(MOD_LGUI, KC_T)
#define MT_N MT(MOD_LGUI, KC_N)
#define MT_E MT(MOD_LALT, KC_E)
#define MT_EQL MT(MOD_MEH, KC_EQL)
#define MT_GRV MT(MOD_RCTL, KC_GRV)

#define KC_CPY LGUI(KC_C)
#define KC_CUT LGUI(KC_X)
#define KC_UNDO LGUI(KC_Z)
#define KC_PST LGUI(KC_V)
#define KC_EUR ALGR(KC_5)   

#define TD_DOT TD(DANCE_DOT_COMM)
#define TD_TAB TD(DANCE_TAB)
#define TD_SLSH TD(DANCE_SLSH_TILDE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_R,    MT_S,    MT_T,    KC_G,                         KC_M,    MT_N,    MT_E,    KC_I,    KC_O,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MT_EQL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, TD_SLSH,  MT_GRV,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LSFT,   T_NUM,  MT_SPC,    KC_BSPC,   T_SYM, OSM_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  EXT_SL,  MT_SPC,    KC_BSPC,   EXT_SL, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ), 
  
  [_GAMING_EXT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2, _______,    KC_3,    KC_4,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_5, _______, _______, _______,    KC_6,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       _______,   _______,  _______,    _______, TO_UTIL, _______
                                      //`--------------------------'  `--------------------------'
  ),      

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_COLN, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_PIPE,                      KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR,   KC_GT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PLUS, KC_MINS,  KC_EUR ,   KC_0, KC_LEFT,                      KC_RGHT,    KC_1, KC_COMM,  KC_DOT, KC_SLSH, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, _______, _______,    _______,   S_SYM, _______
                                      //`--------------------------'  `--------------------------'
  ),
 
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, KC_LPRN, KC_UP,   KC_RPRN, KC_PGUP,                         KC_R,    KC_7,    KC_8,    KC_9, KC_MINS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDO,  KC_CUT,  KC_CPY,  TD_DOT,  KC_PST,                         KC_0,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   S_NUM, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD_TAB, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                      NAV_BCK, TAB_BCK, TAB_FWD, NAV_FWD, TAB_CLS,   S_NAV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                      XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDO,  KC_CUT, KC_COPY,  TD_DOT,  KC_PST,                      TO_UTIL, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, _______, _______,    _______, _______, KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_UTIL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_BRMU, KC_MPRV, KC_VOLU, KC_MNXT,  GAMING,                      TO_GAME, QK_MAKE, QK_FLSH, XXXXXXX, XXXXXXX,  S_UTIL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BRMD, KC_MPLY, KC_VOLD, KC_MSTP, COLEMAK,                      TO_COLE, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_SLEP, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      TO_COLE, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            state = update_tri_layer_state(state, _SYM, _NUM, _NAV);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE
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
                oled_write_ln_P(PSTR("Base "), false);
                break;
            case _GAMING_EXT:
                oled_write_ln_P(PSTR("Ext  "), false);
                break;
            case _SYM:
                oled_write_ln_P(PSTR("Sym  "), false);
                break;
            case _NUM:
                oled_write_ln_P(PSTR("Num  "), false);
                break;
            case _NAV:
                oled_write_ln_P(PSTR("Nav  "), false);
                break;
            case _UTIL:
                oled_write_ln_P(PSTR("Util "), false);
                break;
            default:
                oled_write_P(PSTR("Unkn "), false);
            break;
        }
        oled_write_P(PSTR("\n"), false);

        uint8_t modifiers = get_mods();

        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR(""), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR(""), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT  ") : PSTR(""), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD  ") : PSTR(""), false);
    }


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
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%c: k%2d",
            name, keycode);
    }

    void oled_render_keylog(void) {
        oled_write(keylog_str, false);
    }

    void render_bootmagic_status(bool status) {
        /* Show Ctrl-Gui Swap options */
        static const char PROGMEM logo[][2][3] = {
            {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
            {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
        };
        if (status) {
            oled_write_ln_P(logo[0][0], false);
            oled_write_ln_P(logo[0][1], false);
        } else {
            oled_write_ln_P(logo[1][0], false);
            oled_write_ln_P(logo[1][1], false);
        }
    }

    void oled_render_logo(void) {
        static const char PROGMEM crkbd_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
            0};
        oled_write_P(crkbd_logo, false);
    }

    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
            oled_render_keylog();
        } else {
            oled_render_logo();
        }
        return false;
    }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    #endif
    return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);
uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_tab(qk_tap_dance_state_t *state, void *user_data);
void dance_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_tab_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_tab(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_HOLD: layer_move(_UTIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}

void on_dance_slsh(qk_tap_dance_state_t *state, void *user_data);
void dance_slsh_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_slsh_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_slsh(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
	}
	if(state->count > 3) {
		tap_code16(KC_SLASH);
	}
}

void dance_slsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
	switch (dance_state[1].step) {
		case SINGLE_TAP: register_code16(KC_SLASH); break;
		case SINGLE_HOLD: register_code16(S(KC_TILDE)); break;
		case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
	}
}

void dance_slsh_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state[1].step) {
		case SINGLE_TAP: unregister_code16(KC_SLASH); break;
		case SINGLE_HOLD: unregister_code16(S(KC_TILDE)); break;
		case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
	}
	dance_state[1].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
    [DANCE_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_tab, dance_tab_finished, dance_tab_reset),
    [DANCE_SLSH_TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_slsh, dance_slsh_finished, dance_slsh_reset),
};