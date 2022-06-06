#pragma once

#include QMK_KEYBOARD_H

enum tap_dance_codes {
    DANCE_DOT_COMM,
    DANCE_TAB,
    DANCE_SLSH_TILDE
};

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
