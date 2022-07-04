/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*

[_FLAYER] = LAYOUT_planck_grid(
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
),


*/


#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LAYER1,
  _SYMBOLS,
  _NUMS,
  _FLAYER,
  _FLAYER2,
  _MUSIC,
  _MOUSE,
  _OPTIONS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
};

// Tap Dance declarations
enum {
    TD_BRK,
    TD_PAR,
    TD_DOT_COMM,
    TD_PLUS_MIN,
    TD_MUL_DIV,
    TD_MUS_OFF,
    TD_MUS_ON,
    TD_TO_OPTS
};

#define PLUS LSFT(KC_EQL)
#define MULT LSFT(KC_8)

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_BRK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
    [TD_PLUS_MIN] = ACTION_TAP_DANCE_DOUBLE(PLUS, KC_MINS),
    [TD_MUL_DIV] = ACTION_TAP_DANCE_DOUBLE(MULT, KC_SLSH),
    [TD_MUS_OFF] = ACTION_TAP_DANCE_DOUBLE(KC_NO, MU_OFF),
    [TD_MUS_ON] = ACTION_TAP_DANCE_DOUBLE(KC_NO, MU_ON),
    [TD_TO_OPTS] = ACTION_TAP_DANCE_DOUBLE(KC_NO, TO(_OPTIONS))
};


#define BRK TD(TD_BRK)
#define PAR TD(TD_PAR)

#define DOT_COMM TD(TD_DOT_COMM)
#define PLUS_MIN TD(TD_PLUS_MIN)
#define MULT_DIV TD(TD_MUL_DIV)

#define MUS_OFF TD(TD_MUS_OFF)
#define MUS_ON TD(TD_MUS_ON)
#define TO_OPTS TD(TD_TO_OPTS)

#define NUMS LT(_NUMS, KC_SPC)
#define MOUSE MO(_MOUSE)
#define LAYER1 LT(_LAYER1, KC_SPC)
#define SYM MO(_SYMBOLS)

#define SHFT_EN RSFT_T(KC_ENT)
#define SHFT_BS LSFT_T(KC_BSPC)

#define MUSIC TO(_MUSIC)
#define FLAYER MO(_FLAYER)
#define FLAYER2 MO(_FLAYER2)
#define L0 TO(_QWERTY)

#define PLUS LSFT(KC_EQL)
#define MULT LSFT(KC_8)

#define ALT1 OSM(MOD_LALT)
#define SFT1 OSM(MOD_LSFT)
#define GUI1 OSM(MOD_LGUI)
#define CTL1 OSM(MOD_LCTL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | S/bs |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NUM/SP| Enter| Del  | ctrl |MOUSE |Sp/L1 |  GUI |  SYM | Ctrl | Alt  |  |   |S/Entr|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BRK,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    SHFT_BS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
    NUMS,    KC_DEL,  KC_LALT, KC_LCTL, MOUSE,   LAYER1,  KC_LGUI, SYM,     KC_RCTL, KC_RALT, KC_NO,   SHFT_EN
),

/* LAYER1t
 
 */
[_LAYER1] = LAYOUT_ortho_4x12(
    LSFT(KC_TAB), KC_NO,   KC_TAB,       KC_UP,   KC_ENT,        KC_NO,         KC_NO,    KC_WBAK,  KC_WFWD, KC_NO,   KC_NO,   PAR,
    KC_LALT,      KC_LCTL, KC_LEFT,      KC_DOWN, KC_RGHT,       KC_NO,         KC_WH_L,  KC_WH_D,  KC_WH_U, KC_WH_R, KC_PERC, KC_LSFT,
    KC_LSFT,      KC_NO,   LALT(KC_TAB), KC_NO,   LCTL(KC_PGUP), LCTL(KC_PGDN), KC_BSPC,  KC_DEL,   KC_NO,   KC_NO,   KC_DLR,  KC_NO,
    KC_CAPS,      KC_NO,   KC_NO,        KC_NO,   KC_NO,         KC_TRNS,       KC_SPC,   KC_NO,    KC_RCTL, KC_LALT, KC_NO,   KC_NO
),



/* SYMBOLS 

 */
[_SYMBOLS] = LAYOUT_ortho_4x12(
    KC_LALT, KC_NO,    KC_NO,  KC_EQL,   KC_AMPR,  KC_TILD,  KC_NO,   KC_UNDS,  KC_ASTR,  KC_PIPE,  LSFT(KC_EQL),    LCTL(KC_EQL),
    KC_F11,  KC_AT,    KC_NO,  KC_MINS,  KC_F2,    KC_GRV,   FLAYER2,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,        LCTL(KC_MINS),
    KC_LSFT, KC_LCTL,  KC_NO,  KC_CALC,  KC_NO,    KC_EXLM,  FLAYER,  KC_HASH,  KC_NO,    KC_CIRC,  KC_BSLS,         KC_NO,
    KC_F5,   KC_NO,    KC_NO,  KC_RCTL,  KC_NO,    KC_SPC,   KC_NO,   KC_TRNS,  KC_RCTL,  KC_SLEP,  KC_NO,           KC_F19
),

/* NUMS

 */
[_NUMS] = LAYOUT_ortho_4x12(
    KC_NLCK,KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU,     KC_MPLY,KC_NO,  KC_7, KC_8,    KC_9,   PLUS_MIN, KC_INS,
    KC_NO,  KC_NO,   KC_NO,   KC_LSFT, KC_NO,       KC_NO,  KC_NO,  KC_4, KC_5,    KC_6,   MULT_DIV, KC_PAUS,
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   LSFT(KC_INS),KC_NO,  KC_BSPC,KC_1, KC_2,    KC_3,   DOT_COMM, KC_NO,
    KC_TRNS,KC_NO,   KC_LALT, KC_LCTL, KC_NO,       KC_SPC, KC_SPC, KC_0, KC_NO,   KC_NO,  KC_NO,    KC_ENT  
),



/* FLAYER

 */
[_FLAYER] = LAYOUT_ortho_4x12(
    KC_NO,   KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_NO,        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    SFT1,    KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_NO,        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    ALT1,    KC_F9,  KC_F10, KC_F11, KC_F12,  TO(_OPTIONS), KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_LCTL, KC_NO,        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
),



/* FLAYER2

 */
[_FLAYER2] = LAYOUT_ortho_4x12(
    KC_NO,   KC_F13,  KC_F14,  KC_F15,  KC_F16,   KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,   KC_F17,  KC_F18,  KC_F19,  KC_F20,   KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,   KC_F21,  KC_F22,  KC_F23,  KC_F24,   KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCTL,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
),



/* MUSIC
 
 */
[_MUSIC] = LAYOUT_ortho_4x12(
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO_OPTS, MUS_ON,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   MUS_OFF,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO
),

/* MOUSE
 
 */
[_MOUSE] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_PGUP,     LCTL(KC_PGUP),  KC_UP,        LCTL(KC_PGDN), KC_NO,   KC_NO,          KC_WBAK,      KC_WFWD,   KC_NO, KC_PSCR,  KC_NO,
    LCTL_T(KC_ESC),  KC_PGDN,     KC_LEFT,        KC_DOWN,      KC_RGHT,       KC_NO,   KC_MS_L,        KC_MS_D,      KC_MS_U, KC_MS_R, KC_BTN1,  KC_BTN2,
    KC_LSFT,         LCTL(KC_Z),  LCTL(KC_X),     LCTL(KC_C),   LCTL(KC_V),    KC_NO,   KC_NO,          KC_NO,        KC_NO,   KC_NO,   KC_NO,    KC_NO,
    KC_SPC,          KC_NO,       KC_NO,          KC_NO,        KC_TRNS,       KC_NO,   KC_NO,          KC_NO,        KC_NO,   KC_NO,   KC_NO,    KC_NO
),


[_OPTIONS] = LAYOUT_ortho_4x12(
    RESET,  MUV_IN, KC_NO,   MU_ON,    AU_ON,    KC_NO, KC_NO, KC_NO,   RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_TOG,
    DEBUG,  MUV_DE, MU_MOD,  MU_OFF,   AU_OFF,   KC_NO, KC_NO, KC_NO,   RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_MOD,
    KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
    AG_NORM, AG_SWAP,KC_NO,   KC_NO,    KC_NO,    L0,    MUSIC, KC_NO,   KC_NO,    KC_NO,    TERM_ON,  TERM_OFF
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    default:
      return true;
  }
}
