#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_2x2u(
        KC_Q,         KC_W,    KC_F,    KC_P,   KC_B,  KC_TAB,  CW_TOGG,   KC_J,  KC_L,    KC_U,    KC_Y,    KC_BSPC,
        LCTL_T(KC_A), KC_R,    KC_S,    KC_T,   KC_G,  KC_LGUI, KC_ENT,    KC_M,  KC_N,    KC_E,    KC_I,    RCTL_T(KC_O),
        KC_Z,         KC_X,    KC_C,    KC_D,   KC_V,  KC_LCTL, MEH(KC_Q), KC_K,  KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL,      KC_LGUI, KC_ESC, MO(1), KC_LSFT, KC_SPC,    MO(2), KC_RALT, KC_MUTE, KC_VOLU
    ),
    [1] = LAYOUT_planck_2x2u(
        KC_BRID, KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, SGUI(KC_S), MS_DOWN, MS_RGHT, KC_DOWN, KC_RGHT, LGUI(KC_MINS), LGUI(KC_EQL),
        KC_1, KC_2, KC_3, KC_4, KC_5, _______, LCTL(KC_B), KC_6, KC_7, KC_8, KC_9, KC_0,
        _______, MS_BTN2, KC_MRWD, KC_MPLY, KC_MFFD, MS_BTN1, MS_UP, MS_LEFT, KC_UP, KC_LEFT, LGUI(KC_LEFT), LGUI(KC_RGHT),
        MO(3), _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_planck_2x2u(
        KC_GRV,  KC_TILD, KC_DQUO, KC_QUOT, KC_PERC, _______, _______, KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR, KC_PIPE,
        KC_MINS, KC_UNDS, KC_PLUS, KC_EXLM, KC_EQL,  _______, _______, KC_LCBR, KC_RCBR, KC_ASTR, KC_SCLN, KC_COLN,
        KC_HASH, KC_LT,   KC_GT,   KC_QUES, KC_AMPR, _______, _______, KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_planck_2x2u(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, EE_CLR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM combo1[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_C, KC_D, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, HYPR(KC_M)),
    COMBO(combo2, HYPR(KC_E)),
};

