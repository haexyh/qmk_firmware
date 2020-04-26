#include QMK_KEYBOARD_H


enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
         SEND_STRING("Hallo wie geht es dir ");       // when keycode QMKBEST is released
      }
      break;

  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPACE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_EXLM,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, 
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSHIFT, KC_RSHIFT,
        KC_LCTL, MO(1), KC_LALT,                   _______,   KC_SPC, _______,                           KC_RALT, KC_RCTL, _______, KC_RGUI, TG(2) 
    ),

	[1] = LAYOUT_all(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, RGB_TOG, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_PSCR, _______, _______, _______,
        _______, RGB_MOD, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
    ),
    
    	[2] = LAYOUT_all(
        RESET,   _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, _______, _______, _______, KC_BSPACE,
        _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5 ,   KC_6, 	  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______)

};
