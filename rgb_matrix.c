
// extern led_config_t g_led_config;
// void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_type) {
//     HSV hsv = {hue, sat, val};
//     if (hsv.v > rgb_matrix_config.hsv.v) {
//         hsv.v = rgb_matrix_config.hsv.v;
//     }

//     RGB rgb = hsv_to_rgb(hsv);
//     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
//         if (HAS_FLAGS(g_led_config.flags[i], led_type) || i == 6 || i == 33) {
//             rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
// }

// void check_default_layer(uint8_t type) {
//     switch (get_highest_layer(default_layer_state)) {
//         case _COLEMAK:
//             rgb_matrix_layer_helper(HSV_MAGENTA, type);
//             break;
//         case _GAMING:
//             rgb_matrix_layer_helper(HSV_RED, type);
//             break;
//     }
// }


// void rgb_matrix_indicators_user(void) {
//     user_config.rgb_layer_change = true;
//     if (user_config.rgb_layer_change) {
//     switch (get_highest_layer(layer_state)) {
//         case _GAMING_EXT:
//             rgb_matrix_layer_helper(HSV_PURPLE, LED_FLAG_UNDERGLOW);
//             break;
//         case _SYM:
//             rgb_matrix_layer_helper(HSV_GOLDENROD, LED_FLAG_UNDERGLOW);
//             break;
//         case _NAV:
//             rgb_matrix_layer_helper(HSV_SPRINGGREEN, LED_FLAG_UNDERGLOW);
//             break;
//         case _UTIL:
//             rgb_matrix_layer_helper(HSV_PINK, LED_FLAG_UNDERGLOW);
//             break;
//         case _NUM:
//             rgb_matrix_layer_helper(HSV_CORAL, LED_FLAG_UNDERGLOW);
//             break;
//         default: {
//             check_default_layer(LED_FLAG_UNDERGLOW);
//             break;
//         }
//     }}
// }