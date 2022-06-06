#include QMK_KEYBOARD_H
#include "layers.h"

#define HSV_BLOODORANGE 13, 255, 255

const rgblight_segment_t PROGMEM rgb_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CHARTREUSE},
    {27, 10, HSV_CHARTREUSE}
);

const rgblight_segment_t PROGMEM rgb_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CYAN},
    {27, 10, HSV_CYAN}
);

const rgblight_segment_t PROGMEM rgb_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_YELLOW},
    {27, 10, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM rgb_util_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_BLOODORANGE},
    {27, 10, HSV_BLOODORANGE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_num_layer,
    rgb_sym_layer,
    rgb_nav_layer,
    rgb_util_layer
);

void rgb_set_layer_state(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(1, layer_state_cmp(state, _SYM)); 
  rgblight_set_layer_state(2, layer_state_cmp(state, _NAV)); 
  rgblight_set_layer_state(3, layer_state_cmp(state, _UTIL)); 
}

void rgb_keyboard_post_init(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

