/*
Copyright 2023 StenoKeyboards

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

/* brian_rgb_custom */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

enum polyglot_layers {
    _STENO_DEFAULT,
    _QWERTY,
    _RAISE,
    _LOWER,
    _MINI_NUM
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define QWERTY DF(_QWERTY)
#define STENO DF(_STENO_DEFAULT)
#define MINI_NUM MO(_MINI_NUM)


// Colors for QWERTY layer
const rgblight_segment_t PROGMEM my_QWERTY_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED}, // Leftmost LED
  {12, 1, HSV_RED} // Rightmost LED
  );

// Colors for Steno layer
const rgblight_segment_t PROGMEM my_STENO_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_AZURE}, // Leftmost LED
  {12, 1, HSV_AZURE} // Rightmost LED
  );


// Colors for Numbers layer
const rgblight_segment_t PROGMEM my_NUMBER_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 6, HSV_YELLOW} // Left half, roughly
  );

// Colors for Symbols layer
const rgblight_segment_t PROGMEM my_SYMBOL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {6, 6, HSV_YELLOW} // Right half, roughly
  );

// Colors for the MINI_NUM layer
const rgblight_segment_t PROGMEM my_MINI_NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 6, HSV_GOLDENROD} // Left half, roughly
  );


// Now define the array of layers
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_STENO_layer, // layer 0
  my_QWERTY_layer, // layer 1
  my_NUMBER_layer, // layer 2
  my_SYMBOL_layer, // layer 3
  my_MINI_NUM_layer // layer 4
  );

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_layers = my_rgb_layers;
}

// Turn the RGB Light layers on and off accordingly

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _STENO_DEFAULT));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MINI_NUM));
    return state;
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_STENO_DEFAULT] = LAYOUT(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, 					  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MINI_NUM, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, 					 STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LCMD,  KC_SPC,    			        	XXXXXXX,  KC_LEFT, KC_UP, KC_DOWN ,KC_RIGHT,  KC_ENT,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   STN_N1,  STN_A,   STN_O,                       STN_E,   STN_U, STN_N2
                                       //`--------------------------'  `--------------------------'

   ),

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      STENO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE, KC_LSFT,       KC_SPC, LOWER, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_RAISE] = LAYOUT( // From _QWERTY
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, KC_HOME, KC_UP, KC_END,    KC_PGUP,                      KC_DEL,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,                      XXXXXXX, KC_P4,    KC_P5,   KC_P6,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG,                      KC_SPC,    KC_P1,    KC_P2,   KC_P3,  XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,                      KC_P0,   KC_PDOT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( // From _QWERTY
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, _______, _______, _______, _______,                     KC_QUOT,  KC_RBRC, _______, KC_MINS, KC_EQL,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, KC_LBRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,XXXXXXX, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MINI_NUM] = LAYOUT( // From _STENO_DEFAULT
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_DEL,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,                      XXXXXXX, KC_P4,    KC_P5,   KC_P6,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG,                      KC_SPC,  KC_P1,    KC_P2,   KC_P3,  XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, XXXXXXX,                      KC_P0,   KC_PDOT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

