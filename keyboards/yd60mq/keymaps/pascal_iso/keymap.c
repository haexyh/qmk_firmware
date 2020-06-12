#include QMK_KEYBOARD_H


enum custom_keycodes {
  TX_SPLTH = SAFE_RANGE,
   TX_SPLTV,
   TX_NXT_P,
};

void tmux_command(void) {
  register_code(KC_LCTL);
  register_code(KC_B);
  unregister_code(KC_LCTL);
  unregister_code(KC_B);
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
  case TX_SPLTV:
    if (record -> event.pressed) {
      tmux_command();
      register_code(KC_LSFT);
      register_code(KC_5);
      unregister_code(KC_LSFT);
      unregister_code(KC_5);
    }
    break;
    
  case TX_SPLTH:
    if (record -> event.pressed) {
      tmux_command();
      register_code(KC_LSFT);
      register_code(KC_2);
      unregister_code(KC_LSFT);
      unregister_code(KC_2);
      
    }
    break;
    
  case TX_NXT_P:
    if (record -> event.pressed) {
      tmux_command();
      tap_code(KC_O);
    }
    break;
    
    
  }
  return true;
};
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPACE,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, _______,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, 
        KC_LSFT,       KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSHIFT, KC_RSHIFT,
        LT(1,KC_WAKE), KC_LCTL, KC_LALT,          _______, LT(1,KC_SPC),     _______,                   KC_RALT, KC_RCTL, _______, KC_LGUI, MO(2) 
    ),

	[1] = LAYOUT_all(
        RESET,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, _______, KC_DEL,
       	RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, TX_NXT_P, TX_SPLTV, TX_SPLTH, _______,
        RGB_MOD, _______, KC_PSCR, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  _______, _______,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,	_______, _______,  _______, _______,   _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                    _______, _______,   _______, _______, _______
    ),
    
    [2] = LAYOUT_all(
        DM_RSTP, DM_PLY1, DM_PLY2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPACE,
        _______, DM_REC1, DM_REC2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,                   _______, _______, _______, _______, _______
    
        )
};
