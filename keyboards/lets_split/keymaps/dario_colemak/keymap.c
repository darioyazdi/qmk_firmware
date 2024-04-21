#include QMK_KEYBOARD_H
#include "users/dario/achordion.h"
#include "users/dario/jiggle.h"

#define _COLEMAK 0
#define _NUMPAD 1
#define _SYM 2
#define _MOUSE 3
#define _EXTRA 4

bool mouse_jiggle_mode = false;
uint16_t counter = 0;

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  NUMPAD,
  SYM,
  MOUSE,
  EXTRA,
  MS_TO_JIG,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MS_TO_JIG:
      if (record->event.pressed) {
        if (!mouse_jiggle_mode) {
          for (uint8_t i = 0; i<8; i++) {
            jiggle();
          }
        }

        counter = 0;
        mouse_jiggle_mode = !mouse_jiggle_mode;
      }
      break;
    case RALT_T(KC_N):
        // disable home row mod for certain chords

        /*
        Detect the tap.
        We're only interested in overriding the tap behavior
        in a certain cicumstance. The hold behavior can stay the same.
        */
        if (record->event.pressed) {
            // Detect right Shift
            if (get_mods() & MOD_BIT(KC_RGUI)) {
                // temporarily disable right Shift
                // so that we can send KC_E and KC_N
                // without Shift on.
                unregister_mods(MOD_BIT(KC_RGUI));
                tap_code(KC_E);
                tap_code(KC_N);
                // restore the mod state
                add_mods(MOD_BIT(KC_RGUI));
                // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
                return false;
            }
        }
    case KC_M:
       // disable home row mod for certain chords

       /*
       Detect the tap.
       We're only interested in overriding the tap behavior
       in a certain cicumstance. The hold behavior can stay the same.
       */
       if (record->event.pressed) {
           // Detect right Shift
           if (get_mods() & MOD_BIT(KC_RGUI)) {
               // temporarily disable right Shift
               // so that we can send KC_E and KC_N
               // without Shift on.
               unregister_mods(MOD_BIT(KC_RGUI));
               tap_code(KC_E);
               tap_code(KC_M);
               // restore the mod state
               add_mods(MOD_BIT(KC_RGUI));
               // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
               return false;
           }
       }
  }
  return true;
}

void matrix_scan_user(void) {
  if (mouse_jiggle_mode && counter < 2) {
    jiggle();
    counter += 3;
  }
  counter++;
  counter &= 0xFFFF;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_ortho_4x12(
    KC_ESC          , KC_Q       , KC_W         , KC_F        , KC_P           , KC_G          ,              KC_J    , KC_L         , KC_U        , KC_Y   , KC_SCLN , KC_BSPC ,
    KC_LCTL         , KC_A       , KC_R         , LGUI_T(KC_S), LALT_T(KC_T)   , KC_D          ,              KC_H    , RALT_T(KC_N) , RGUI_T(KC_E), KC_I   , KC_O    , KC_ENT  ,
    KC_TAB          , KC_Z       , KC_X         , KC_C        , KC_V           , KC_B          ,              KC_K    , KC_M         , KC_COMM     , KC_DOT , KC_SLSH , KC_QUOT ,
    KC_NO           , KC_NO      , KC_NO        , MO(_MOUSE)  , MO(_NUMPAD)    , KC_LSFT       ,              KC_SPC  , MO(_SYM)     , MO(_EXTRA)  , KC_NO  , KC_NO   , KC_NO)  ,
  [_NUMPAD] = LAYOUT_ortho_4x12(
    KC_F1        , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                                           KC_ASTR , KC_7   , KC_8   , KC_9    , KC_0    , KC_TRNS ,
    LCTL_T(KC_F7), KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,                                           KC_EQL  , KC_4   , KC_5   , KC_6    , KC_UNDS , KC_DEL  ,
    KC_AT        , KC_DLR  , KC_PERC , KC_CIRC , KC_PIPE , KC_HASH ,                                           KC_MINS , KC_1   , KC_2   , KC_3    , KC_SLSH , KC_GRV   ,
    KC_TRNS      , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                           KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS ),
  [_SYM] = LAYOUT_ortho_4x12(
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_AMPR    , KC_EXLM ,                        KC_TRNS , KC_LPRN , KC_RPRN , KC_BSLS , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TILD ,                        KC_TRNS , KC_LCBR , KC_RCBR , KC_LT   , KC_GT    , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_PLUS ,                        KC_TRNS , KC_LBRC , KC_RBRC , KC_TRNS , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS),
  [_MOUSE] = LAYOUT_ortho_4x12(
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , MS_TO_JIG     , KC_WH_D      , KC_MS_BTN2  , KC_MS_BTN1 , KC_WH_U ,                        KC_LEFT   , KC_DOWN   , KC_UP   , KC_RGHT    , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_LGUI    , KC_TRNS ,                        KC_MPRV   , KC_MPLY   , KC_MNXT , KC_TRNS    , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS   , KC_TRNS   , KC_TRNS , KC_TRNS    , KC_TRNS  , KC_TRNS),
  [_EXTRA] = LAYOUT_ortho_4x12(
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS    ,
    KC_TRNS      , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS ,                        KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _COLEMAK, _NUMPAD, _ARROW);
// }
