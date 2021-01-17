/*
Copyright 2019 Sekigon

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

////
//A01:LowerとRaiseにF13とF14を割り当て
////

#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include <stdio.h>

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    LOWER,                /* Layer  keycode                       */
    RAISE,                /* Layer  keycode                       */
};


extern keymap_config_t keymap_config;

enum {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Layer related keycodes
#define ADJUST  MO(_ADJUST)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
/*keycord変換*/
#define KC_TGMSC TG(_MOUSECURSOR)	//MSCレイヤに切り替え
#define KC_MOMSC MO(_MOUSECURSOR)	//押している間MSCレイヤ
#define KC_CTLC LCTL(KC_C)			//Ctrl+C
#define KC_CTLV LCTL(KC_V)			//Ctrl+V
#define KC_CTLZ LCTL(KC_Z)			//Ctrl+Z
#define KC_CTLX LCTL(KC_X)			//Ctrl+X
#define SPC_MSC LT(_MOUSECURSOR,KC_SPC)
#define ALT_SPC ALT_T(KC_SPC)   //HOLDでALT、TAPでSPC
#define ALT_TAB RALT(KC_TAB)    //ALT+TAB
#define KC_HNKN LALT(KC_GRV)       //ALT+"`"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,        KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,        KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               KC_LGUI,  KC_LALT, LOWER,   KC_SPC,         KC_ENT,  RAISE,   KC_RALT, ADJUST \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_LOWER] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
      KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_GRV,\
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LPRN,        KC_RPRN, KC_PMNS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_LBRC,        KC_RBRC, KC_UNDS, KC_PPLS, KC_LCBR, KC_RCBR, KC_PIPE, KC_RSFT,\
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               KC_DEL, KC_BSPC, _______, KC_ENT,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_RAISE] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
      KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,\
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,KC_LPRN,         KC_RPRN,KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_WH_U, KC_BSPC,\
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_PSCR, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,KC_LBRC,         KC_RBRC, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_WH_D, KC_RSFT,\
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT ( \
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, AD_WO_L, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, DELBNDS, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, BATT_LV, ENT_SLP, ENT_DFU, RESET,   XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  )

};

//A01 From
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;
//A01 To

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {

        lower_pressed = true;//A01
      	lower_pressed_time = record->event.time;//A01

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//A01 From
        if (lower_pressed){
      		register_code(KC_LANG2); //for MacOS
      		//register_code(KC_MHEN);
      		register_code(KC_F13);
      		unregister_code(KC_LANG2);//for MacOS
      		unregister_code(KC_F13);
      		//unregister_code(KC_MHEN);
      	}
        lower_pressed = false;
//A01 To
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;//A01
      	raise_pressed_time = record->event.time;//A01

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

//A01 From
        if (raise_pressed){
      		register_code(KC_LANG1); //for MacOS
      		//register_code(KC_HENK);
      		register_code(KC_F16);
      		unregister_code(KC_LANG1);//for MacOS
      		unregister_code(KC_F16);
      		//unregister_code(KC_HENK);
      	}
      	raise_pressed = false;
//A01 To
      }
      return false;
      break;
//A01 From
    default:
      if (record->event.pressed){
        //reset the flag
        lower_pressed = false;
        raise_pressed = false;
        }
//A01 To
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;
