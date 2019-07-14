#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
//  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if 0
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
#else
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   L1   |  1!  |  2@  |   3# |  4$  |  5%  | Esc  |           |  '"  |  6^  |  7&  |  8*  |  9(  |  0)  |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab/L2 |   Q  |   W  |   E  |   R  |   T  |      |           |  =+  |   Y  |   U  |   I  |   O  |   P  |   L1   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  | Enter  |
 * |--------+------+------+------+------+------|  -_  |           |  -_  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | LWin |  `~  | LAlt |  \|  |                                       |  /?  | RCtrl| Left | Down | Right |  
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TtL1 | TtL2 |       |  F7  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Menu |       |  F8  |      |      |
 *                                 | Space| ESC  |------|       |------| BkSp |Space |
 *                                 |      |      |CtrlZ |       |PrtScr|      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        MO(SYMB),         KC_1,            KC_2,     KC_3,     KC_4,     KC_5,   KC_ESC,
        LT(MDIA, KC_TAB), KC_Q,            KC_W,     KC_E,     KC_R,     KC_T,   _______,
        KC_LCTRL,         KC_A,            KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,          KC_Z,            KC_X,     KC_C,     KC_V,     KC_B,   KC_MINS,
        _______,          KC_LGUI,         KC_GRV,  KC_LALT,  KC_BSLS,  
                                                     TT(SYMB), TT(MDIA),
                                                               KC_APP,
                                            KC_SPC,  KC_ESC,   LCTL(KC_Z),
        // right hand
             KC_QUOT,    KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             KC_BSPC,
             KC_EQL,     KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,             MO(SYMB),
                         KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,          KC_ENT,
             KC_MINS,    KC_N,   KC_M,    KC_COMM, KC_DOT, KC_UP,            KC_RSFT,
                                 KC_SLSH, KC_RCTRL, KC_LEFT, KC_DOWN,        KC_RIGHT,
             KC_F7, _______,
             KC_F8,
             KC_PSCR,KC_BSPC, KC_SPC
    ),
#endif


/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  ToBase |  F1  |  F2  |  F3  |  F4  |  F5  |ToBase|           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  Del   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | Esc  | WinE |   {  |   }  |   +  |      |           |      | PgUp | Home |  Up  | End  |  F11 |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |CtrlPS|   (  |   )  |   -  |------|           |------| PgDn | Left | Down | Right|  F12 |        |
 * |---------+------+------+------+------+------|  "   |           |      |------+------+------+------+------+--------|
 * |         | WinD | WinR |   [  |   ]  |   =  |      |           |      |      |      | Ins  |      | PgUp |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | Num+ | Num- |                                       |      |      | Home | PgDn | End   |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |ToBase|------|       |------| Del  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       TO(BASE), KC_F1,        KC_F2,         KC_F3,    KC_F4,    KC_F5,   TO(BASE),
       KC_TRNS, KC_ESC,       LGUI(KC_E),    KC_LCBR,  KC_RCBR,  KC_PLUS,  _______,
       KC_TRNS, KC_TRNS,      LCTL(KC_PSCR), KC_LPRN,  KC_RPRN,  KC_MINUS,
       KC_TRNS, LGUI(KC_D),   LGUI(KC_R),    KC_LBRC,  KC_RBRC,  KC_EQL,   KC_DQT,
       KC_TRNS, KC_TRNS,      KC_TRNS,       KC_PPLS,  KC_PMNS,
                                                                KC_TRNS,KC_TRNS,
                                                                        KC_TRNS,
                                                        KC_TRNS,TO(BASE),KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,    KC_F8,    KC_F9,      KC_F10,    KC_DELT,
       KC_TRNS, KC_PGUP, KC_HOME,  KC_UP,    KC_END,     KC_F11,    KC_TRNS,
                KC_PGDN, KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_F12,   KC_TRNS,
       _______, _______, KC_TRNS,  KC_INS,   KC_TRNS,     KC_PGUP,   KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_HOME,    KC_PGDN,   KC_END,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_DELT, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ToBase |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |MsWhUp|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Btn4 | Btn5 |      |      |           |      |      |      |      |      |VolUp |Ply/Paus|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Btn3 | Btn2 | Btn1 |                                       | Mute |      | Prev |VolDn | Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       TO(BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_MS_WH_UP, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_DOWN,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN4, KC_BTN5, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_MEDIA_PLAY_PAUSE,
                          KC_MUTE, KC_TRNS, KC_MPRV, KC_VOLD,KC_MNXT,
       RGB_TOG, RGB_SLD,
       RGB_MODE_KNIGHT,
       KC_PSCR, RGB_HUD, RGB_HUI
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)  // KC_FN1
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};


/**
 * Change shift+backspace into delete and do not register the shift modifier.
 */
// Based on https://www.reddit.com/r/olkb/comments/63groy/controlbackspace_delete_without_ctrl_macro/dfzvgko
bool process_shiftdel(uint16_t keycode, keyrecord_t *record) {
  static bool control_disabled = false;
  static bool delete_pressed = false;

  if(keycode == KC_BSPC) {
    if (record->event.pressed) {
      if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
        delete_pressed = true;
        control_disabled = true;
        unregister_code(KC_LSFT);
        register_code(KC_DEL);
        return false;
      }
    } else if(delete_pressed) {
      delete_pressed = false;
      unregister_code(KC_DEL);

      if(control_disabled) {
        control_disabled = false;
        register_code(KC_LSFT);
      }
      return false;
    }
  } else if(keycode == KC_LSFT && !record->event.pressed && delete_pressed) {
    delete_pressed = false;
    control_disabled = false;
    unregister_code(KC_DEL);
    register_code(KC_BSPC);
    return false;
  }
  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
/*    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;*/
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }

  if(!process_shiftdel(keycode, record))
    return false;

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
