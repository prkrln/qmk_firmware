// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_SLSH,
    TD_DOT_GRV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
    [TD_DOT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_GRV),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x10(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT(MOD_LGUI, KC_A),    MT(MOD_LALT, KC_S),    MT(MOD_LSFT, KC_D),    MT(MOD_LCTL, KC_F),    KC_G,    KC_H,    MT(MOD_RCTL, KC_J),    MT(MOD_RSFT, KC_K),    MT(MOD_RALT, KC_L),    MT(MOD_RGUI, KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, TD(TD_DOT_GRV),  TD(TD_SLSH),
        LT(1, KC_SPC), LT(1, KC_BSPC)
    ),
    [1] = LAYOUT_ortho_3x10(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MT(MOD_LGUI, KC_LBRC),    MT(MOD_LALT, KC_RBRC),    MT(MOD_LSFT, KC_QUOT),    MT(MOD_LCTL, KC_MINS),    KC_EQL,    KC_LEFT,    MT(MOD_RCTL, KC_DOWN),    MT(MOD_RSFT, KC_UP),    MT(MOD_RALT, KC_RGHT),    MT(MOD_RGUI, KC_TAB),
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_ESC, KC_ENT
    )
};
