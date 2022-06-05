/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          10
#define MOUSEKEY_TIME_TO_MAX    45
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY    10

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_DEFAULT_HUE 215
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
    #define RGBLIGHT_SLEEP true
#endif

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 5
    #define RGB_MATRIX_SPD_STEP 10
    
    // Effects
    #define ENABLE_RGB_MATRIX_BREATHING
    #define RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif 

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"