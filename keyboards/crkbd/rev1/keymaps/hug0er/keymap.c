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

// Home row mods
#define HM_A    MT(MOD_LGUI, KC_A)
#define HM_S    MT(MOD_LALT, KC_S)
#define HM_D    MT(MOD_LSFT, KC_D)
#define HM_F    MT(MOD_LCTL, KC_F)

// Home row mods - mirror
#define HM_J    MT(MOD_RCTL, KC_J)
#define HM_K    MT(MOD_RSFT, KC_K)
#define HM_L    MT(MOD_RALT, KC_L)
#define HM_SCLN MT(MOD_RGUI, KC_SCLN)

// Tap Dance
#define TD_ESC  TD(TD_HYPER_ESC)    // Tap: Escape, Hold: Hyper (All mods)

enum custom_keycodes {
    TD_HYPER_ESC = 0,
};

void ctrl_super_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) {
        // Activar todas las teclas modificadoras cuando se mantiene presionado
        register_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
    } else {
        // Enviar Escape cuando se toca
        tap_code(KC_ESC);
    }
}

void ctrl_super_reset(tap_dance_state_t *state, void *user_data) {
    // Desactivar todas las teclas modificadoras cuando se suelta
    unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL));
}

// Eliminar el array anterior y reemplazarlo con este
tap_dance_action_t tap_dance_actions[] = {
    [TD_HYPER_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_super_finished, ctrl_super_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TD_ESC,   HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_COMM,   KC_DOT, KC_SLSH,  KC_RSFT,
  //|---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,   KC_SPC,   LT(2, KC_ENTER), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_QUES, KC_PLUS, KC_UNDS, KC_LT,                         KC_GT, KC_MINUS, KC_GRV, KC_LBRC, KC_RBRC, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PPLS, KC_EQL, KC_BSLS, KC_LCBR, KC_RCBR, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PLUS, KC_1, KC_2, KC_3, KC_MINUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_ASTR, KC_4, KC_5, KC_6, KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_7, KC_8, KC_9, KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI,                      KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI,                      KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TRNS, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI,                      KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_LGUI, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
};
