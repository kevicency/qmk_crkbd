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
#include "layers.h"
#include "tap_dance.h"

#ifdef OLED_ENABLE
    #include "oled.h"
#endif

#ifdef RGBLIGHT_ENABLE
    #include "rgb.h"
#endif

// Base Layers
#define COLEMAK DF(_COLEMAK)
#define GAMING  DF(_GAMING)

#define TO_DFLT TO(0)
#define TO_UTIL TO(_UTIL)
#define TO_NAV  TO(_NAV)

// Other Layers
#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)

#define T_NUM TT(_NUM)
#define S_NUM MO(_NUM)

#define S_NAV MO(_NAV)
#define T_NAV TT(_NAV)
#define S_UTIL MO(_UTIL)
#define T_UTIL TT(_UTIL)

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
#define MT_SLSH MT(MOD_LALT, KC_SLSH)

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
       TD_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_R,    MT_S,    MT_T,    KC_G,                         KC_M,    MT_N,    MT_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MT_EQL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, TD_SLSH,  MT_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM_LSFT,   T_NUM,  MT_SPC,    KC_BSPC,   T_SYM, OSM_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

//   [_GAMING] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//        KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LALT,  EXT_SL,  MT_SPC,    KC_BSPC,   EXT_SL, KC_RALT
                                       //`--------------------------'  `--------------------------'
//   ), 
  
//   [_GAMING_EXT] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_GRV,    KC_1,    KC_2, _______,    KC_3,    KC_4,                      _______, _______, _______, _______, _______, _______,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______,    KC_5, _______, _______, _______,    KC_6,                      _______, _______, _______, _______, _______, _______,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       _______,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,                      _______, _______, _______, _______, _______, _______,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                        _______,   _______,  _______,    _______, TO_UTIL, _______
                                       //`--------------------------'  `--------------------------'
//   ),      

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_B,    KC_U,    KC_8,    KC_9,    KC_0, KC_MINS,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_H,    KC_J,    KC_I,    KC_O,    KC_P, KC_LBRC,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_N,    KC_M,    KC_K,    KC_L, KC_SCLN, KC_QUOT,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, KC_LCTL, EXT_SL,    KC_BSPC,   TO_UTIL, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  [_GAMING_EXT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LCTL(KC_6),LALT(KC_U),LALT(KC_8),LALT(KC_9),LALT(KC_0),KC_EQL,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Y,    KC_7,LALT(KC_I),LALT(KC_O),LALT(KC_P),KC_RBRC,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_COMM, KC_LALT,  KC_DOT, KC_BSPC, KC_SPC,  KC_BSLS,                        KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, KC_LCTL, EXT_SL,    KC_BSPC,   EXT_SL, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ), 

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_COLN, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_PIPE,                      KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR,   KC_GT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_EQL, KC_PLUS, KC_MINS, KC_TILD,   KC_0, KC_LEFT,                      KC_RGHT,    KC_1, KC_COMM,  KC_DOT, KC_SLSH,  KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, _______, _______,    _______,   S_SYM, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, KC_LPRN, KC_UP,   KC_RPRN, KC_PGUP,                         KC_R,    KC_7,    KC_8,    KC_9, KC_PLUS, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_EQL, KC_UNDO,  KC_CUT,  KC_CPY,  TD_DOT,  KC_PST,                         KC_0,    KC_1,    KC_2,    KC_3, KC_SLSH,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   S_NUM, _______,    _______, _______, KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD_TAB, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                      NAV_BCK, TAB_BCK, TAB_FWD, NAV_FWD, TAB_CLS,  TO_NAV,      
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                       TO_NAV, KC_BTN1, KC_BTN2, KC_BTN3, KC_RGUI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDO,  KC_CUT, KC_COPY,  TD_DOT,  KC_PST,                      TO_UTIL, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, _______, _______,    _______, _______, KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [_UTIL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_BRMU, KC_MPRV, KC_VOLU, KC_MNXT,  GAMING,                      TO_DFLT, QK_MAKE, QK_FLSH, XXXXXXX, XXXXXXX, TO_DFLT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BRMD, KC_MPLY, KC_VOLD, KC_MSTP, COLEMAK,                      TO_DFLT, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       EE_CLR, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      TO_DFLT, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
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

    #ifdef RGBLIGHT_ENABLE
        rgb_set_layer_state(state);
    #endif

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
        oled_process_record(keycode, record);
    #endif
    return true;
}

void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
        rgb_keyboard_post_init();
    #endif
}

