#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MO_JIGG
};

bool mouse_jiggle_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME, KC_PGUP, KC_END,  KC_PSCR,   MO(1),
        KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_PGDN, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        LT(1,KC_CAPS),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,        KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT
    ),
    [1] = LAYOUT_all(
        KC_KB_POWER, KC_BRIU, KC_BRID, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,  KC_INS, _______, MO_JIGG, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_NUM, _______, _______, _______,
        _______,     UG_TOGG, _______, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______,          _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
        _______,     _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
        _______,     _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_MS_WH_UP);
    tap_code(KC_MS_WH_DOWN);
  } else {

  }
}

//if you want it to be a toggle switch with a key instead of a hold down function use this instead
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO_JIGG:
      if (record->event.pressed) {
        if (mouse_jiggle_mode) {
            mouse_jiggle_mode = false;
        } else {
            mouse_jiggle_mode = true;
        }
      // SEND_STRING(SS_DELAY(100)); //uncomment if it switches too fast before the button debounces
      } else {}
      break;
  }
  return true;
}
