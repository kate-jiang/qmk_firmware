// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "lib/song.h"

enum layers {
  _BASE,
  _CTRL,
  _SYM,
  _CONFIG
};

enum custom_keycodes {
    GC_SONG = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_B,    KC_J, KC_L, KC_U, KC_Y,      KC_SCLN, KC_BSPC,
    KC_LGUI, KC_A, KC_R, KC_S, KC_T, KC_G,    KC_M, KC_N, KC_E, KC_I,      KC_O,    KC_ENT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_D, KC_V,    KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, MEH(KC_Q),
               KC_ESC, MO(_CTRL), KC_LSFT,    KC_SPC, MO(_SYM), KC_RALT
  ),

  [_CTRL] = LAYOUT_split_3x6_3(
    KC_BRID,      KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, SGUI(KC_S),    MS_DOWN, MS_RGHT, KC_DOWN, KC_RGHT, _______,        _______,
    CW_TOGG,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           LCTL(KC_B),
    MO(_CONFIG),  MS_BTN2, KC_MRWD, KC_MPLY, KC_MFFD, MS_BTN1,       MS_UP,   MS_LEFT, KC_UP,   KC_LEFT, LGUI(KC_LEFT),  LGUI(KC_RGHT),
                                    _______, _______, _______,       _______, _______, _______
  ),

  [_SYM] = LAYOUT_split_3x6_3(
    _______, _______, _______,    KC_DQUO,   KC_QUOT, KC_PERC,    KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,  KC_PIPE, _______,
    _______, KC_MINS, KC_UNDS,    KC_PLUS,   KC_EXLM, KC_EQL,     KC_GRV,  KC_LCBR, KC_RCBR, KC_ASTR, KC_SCLN, KC_COLN,
    _______, KC_HASH, S(KC_COMM), S(KC_DOT), KC_QUES, KC_AMPR,    KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, KC_TILD,
                                    _______, _______, _______,    _______,  _______, _______
  ),

  [_CONFIG] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,    RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,  QK_BOOT,
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,  GC_SONG,
    _______, _______, _______, _______, _______, _______,    RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,  QK_CLEAR_EEPROM,
                               _______, _______, _______,    _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GC_SONG:
            if (record->event.pressed) {
                PLAY_SONG(gc_song);
            }
            break;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case 2:
            rgb_matrix_set_color_all(20, 60, 20);
            break;
        case 1:
            rgb_matrix_set_color_all(50, 35, 5);
            break;
        default:
            rgb_matrix_set_color_all(60, 20, 20);
            break;
    }
    return false;
}

const uint16_t PROGMEM combo1[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_C, KC_D, KC_X, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_T, KC_N, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, HYPR(KC_M)),
    COMBO(combo2, HYPR(KC_E)),
};

