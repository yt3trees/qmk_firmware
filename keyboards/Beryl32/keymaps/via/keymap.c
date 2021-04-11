#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  LOWER,
  RAISE,
  KANJI,
};

// enum tapdances{
//   TD_CODO = 0,
//   TD_SLRO,
// };

// Layer Mode aliases
#define KC_MLAD  MO(3)

// Base layer mod tap
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_A_CT  LCTL_T(KC_A)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
//#define KC_SSCT  RCTL_T(KC_SLSH)
//#define KC_ENSF  RSFT_T(KC_ENT)
#define KC_SCCT  RCTL_T(KC_SCLN)
#define KC_SLSF  RSFT_T(KC_SLSH)
#define KC_DOAL  RALT_T(KC_DOT)
#define KC_COGU  RGUI_T(KC_COMM)

// Lower layer mod tap
//#define KC_1CT  LCTL_T(KC_1)
#define KC_QUSF  RSFT_T(KC_QUOT)//---------------
//#define KC_6SF  LSFT_T(KC_6)
//#define KC_7AL  LALT_T(KC_7)//-----

// Raise layer mod tap
#define KC_F11SF  LSFT_T(KC_F11)

// Adjust layer mod tap
// Layer tap
#define KC_ENRA  LT(MO(2), KC_ENT)
#define KC_SPLO  LT(MO(1), KC_SPC)

// Tap dance
// #define KC_CODO  TD(TD_CODO)
// #define KC_SLRO  TD(TD_SLRO)

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
//   [TD_SLRO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RO),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_A_CT,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCCT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_Z_SF,  KC_X_AL,  KC_C_GU,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COGU,  KC_DOAL,  KC_SLSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_SPLO,  KC_ENRA
  //                                        `---------|---------'`
  ),

  [1] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  XXXXXXX,  XXXXXXX,  KC_TILD,   KC_GRV,  KC_PMNS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  KC_LALT,  KC_LGUI,   KC_TAB,   KC_ESC,  KC_UNDS,  KC_PPLS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_TRNS,  KC_MLAD
  //                                        `---------|---------'`
  ),

  [2] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_DEL,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
         KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_BSPC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_F11SF,   KC_F12,  KC_LGUI,  XXXXXXX,   KC_ESC,  KC_MINS,  KC_PGDN,  KC_PGUP,   KC_DOT,  KC_MINS,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_MLAD,  KC_TRNS
  //                                        `---------|---------'`
  ),

  [3] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
        RESET,    RGBRST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TILD,   KC_GRV,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WH_U,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_PSCR,  XXXXXXX,  XXXXXXX,  KC_LGUI,  KC_WH_D,  KC_QUSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_TRNS,  KC_TRNS
  //                                        `---------|---------'`
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //case KC_BSLO:
    //  return TAPPING_LAYER_TERM;
    //case KC_SPRA:
    //  return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }
  return result;
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}
