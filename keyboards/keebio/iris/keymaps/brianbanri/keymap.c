 #include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _LAYER1,
  _SYMBOLS,
  _NUMS,
  _MOUSE,
  _OPTIONS,
  _GAMING,
  _LOWER,
  _RAISE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

// Tap Dance declarations
enum {
    TD_BRK,
    TD_PAR,
    TD_RH,
    TD_MALT,
    TD_F1_6,
    TD_F2_7,
    TD_F3_8,
    TD_F4_9,
    TD_F5_10,
    TD_DOT_COMM,
    TD_PLUS_MIN,
    TD_MUL_DIV
};

#define PLUS LSFT(KC_EQL)
#define MULT LSFT(KC_8)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_BRK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_RH] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_H),
    [TD_MALT] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_LALT),
    [TD_F1_6] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F6),
    [TD_F2_7] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F7),
    [TD_F3_8] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F8),
    [TD_F4_9] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F9),
    [TD_F5_10] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),
    [TD_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
    [TD_PLUS_MIN] = ACTION_TAP_DANCE_DOUBLE(PLUS, KC_MINS),
    [TD_MUL_DIV] = ACTION_TAP_DANCE_DOUBLE(MULT, KC_SLSH)
};

#define BRK TD(TD_BRK)
#define PAR TD(TD_PAR)

#define RH TD(TD_RH)
#define MALT TD(TD_MALT)

#define F1_6 TD(TD_F1_6)
#define F2_7 TD(TD_F2_7)
#define F3_8 TD(TD_F3_8)
#define F4_9 TD(TD_F4_9)
#define F5_10 TD(TD_F5_10)

#define DOT_COMM TD(TD_DOT_COMM)
#define PLUS_MIN TD(TD_PLUS_MIN)
#define MULT_DIV TD(TD_MUL_DIV)

#define NUMS MO(_NUMS)
#define MOU MO(_MOUSE)
#define L1 LT(_LAYER1, KC_SPC)
#define SYM MO(_SYMBOLS)

#define SHFT_EN RSFT_T(KC_ENT)
#define SHFT_BS LSFT_T(KC_BSPC)

#define R_TAB LSFT(KC_TAB)

#define W_TAB_F LCTL(KC_PGUP)
#define W_TAB_B LCTL(KC_PGDN)
#define Q_TAB LALT(KC_TAB)


#define L0 TO(_QWERTY)
#define OPTS TO(_OPTIONS)
#define GAME TO(_GAMING)

#define CTRLZ LCTL(KC_Z)
#define CTRLX LCTL(KC_X)
#define CTRLC LCTL(KC_C)
#define CTRLV LCTL(KC_V)
/*
#define ALT1 OSM(MOD_LALT)
#define SFT1 OSM(MOD_LSFT)
#define GUI1 OSM(MOD_LGUI)
#define CTL1 OSM(MOD_LCTL)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  [_LAYER1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, KC_NO,                     KC_NO,   KC_RCTL, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
*/


  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_DEL,  KC_F13,  KC_F14,  KC_F15,  KC_LBRC, KC_RBRC,                            KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_MINUS,KC_EQUAL, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BRK,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SHFT_BS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,          KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SHFT_EN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, NUMS,    L1,                        KC_LGUI, SYM,     KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYER1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     R_TAB,   KC_NO,   KC_TAB,   KC_UP,  KC_ENT,  KC_NO,                              KC_NO,   KC_WBAK, KC_WFWD, KC_NO,   KC_MPLY, PAR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                              KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_PERC, KC_LSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   Q_TAB,   KC_NO,   W_TAB_F, W_TAB_B, MOU,              KC_LALT, KC_BSPC, KC_DEL,  KC_NO,   KC_NO,   KC_DLR,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_NO,   KC_TRNS,                   KC_SPC,  KC_NO,   KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_BRIU, KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPRV, KC_MNXT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BRID, KC_NO,   KC_NO,   KC_EQL,  KC_AMPR, KC_TILD,                            KC_NO,   KC_UNDS, KC_ASTR, KC_PIPE, PLUS,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F11,  KC_AT,   KC_NO,   KC_MINS, KC_F2,   KC_GRV,                             KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F5,   KC_NO,   KC_CALC, KC_NO,   KC_NO,   KC_EXLM, KC_LALT,          KC_LALT, KC_NO,   KC_HASH, KC_NO,   KC_CIRC, KC_BSLS, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_NO,   KC_NO,                     KC_NO,   KC_TRNS, KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    PLUS_MIN,KC_PAUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,                              KC_NO,   KC_4,    KC_5,    KC_6,    MULT_DIV,KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, CTRLZ,   CTRLX,   CTRLC,   CTRLV,   KC_NO,   KC_NO,            KC_LSFT, KC_BSPC, KC_1,    KC_2,    KC_3,    DOT_COMM,KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_TRNS, KC_NO,                     KC_SPC,  KC_0,    KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_SLEP,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_F21,  KC_F22,  KC_F23,  KC_F24,  GAME,                               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OPTS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,          OPTS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   KC_NO,   KC_TRNS,                   KC_NO,   KC_NO,   KC_NO 
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_OPTIONS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,   DEBUG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              RGB_M_SW,RGB_TOG, RGB_HUI, RGB_VAI, RGB_SAI, RGB_M_P,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     L0,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, L0,                        KC_NO,   KC_RCTL, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               F1_6,    F2_7,    F3_8,    F4_9,    F5_10,   L0,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BRK,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,          KC_F15,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SHFT_EN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    MALT,    KC_H,    KC_SPC,                    KC_BSPC, KC_RCTL, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}