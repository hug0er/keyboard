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
#include "quantum.h"

enum custom_keycodes {
    MOD_LAYER_1,
    MOD_LAYER_2,
    MO2_ENTER,
    TD_CTRL_ESC = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_ESC), // on  mantain pressed control and esc on tap
    [MO2_ENTER] = ACTION_TAP_DANCE_DOUBLE(MOD_LAYER_2, KC_ENT), // on  mantain pressed enter and MOD_LAYER_2 on tap
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  TD_CTRL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI,   MOD_LAYER_1,  KC_SPC,     KC_SPC,   MO2_ENTER, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_UNDS, KC_LT,                         KC_GT, KC_MINUS, KC_GRV, KC_LBRC, KC_RBRC, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PPLS, KC_EQL, KC_BSLS, KC_LCBR, KC_RCBR, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
 
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
  )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
    // Verificar si ambas teclas están siendo presionadas simultáneamente
    if (keyboard_report->mods & get_mods(MOD_LAYER_1) && keyboard_report->mods & get_mods(MOD_LAYER_2)) {
        layer_on(3);

    }
    // Verificar si solo MOD_LAYER_1 está siendo presionada
    else if (keyboard_report->mods & get_mods(MOD_LAYER_1)) {
        layer_on(1);

    }
    // Verificar si solo MOD_LAYER_2 está siendo presionada
    else if (keyboard_report->mods & get_mods(MOD_LAYER_2)) {
        layer_on(2);
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
}