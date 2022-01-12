#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _NUMPAD 1
#define _ARROW 2

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  NUMPAD,
  ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_ortho_4x12(
    KC_GESC         , KC_Q       , KC_W         , KC_F       , KC_P    , KC_G          , KC_J          , KC_L   , KC_U    , KC_Y   , KC_SCLN , KC_BSPC         ,
    KC_LCTL         , KC_A       , KC_R         , KC_S       , KC_T    , KC_D          , KC_H          , KC_N   , KC_E    , KC_I   , KC_O    , KC_QUOT         ,
    LSFT_T(KC_LBRC) , KC_Z       , KC_X         , KC_C       , KC_V    , KC_B          , KC_K          , KC_M   , KC_COMM , KC_DOT , KC_SLSH , RSFT_T(KC_RBRC) ,
    KC_NO           , KC_NO      , KC_NO        , TT(_ARROW) , KC_LGUI , LT(1, KC_SPC) , LT(1, KC_SPC) , KC_ENT , KC_BSLS , KC_NO  , KC_NO   , KC_NO) ,
  [_NUMPAD] = LAYOUT_ortho_4x12(
    KC_GRV  , KC_TRNS , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS , KC_7    , KC_8 , KC_9    , KC_TRNS , KC_DEL   ,
    KC_TAB  , KC_TRNS , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_EQL  , KC_4    , KC_5 , KC_6    , KC_TRNS , KC_TRNS  ,
    KC_LBRC , KC_LPRN , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_MINS , KC_1    , KC_2 , KC_3    , KC_RPRN , KC_RBRC  ,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_LALT , KC_TRNS , KC_TRNS , KC_TRNS , KC_0 , KC_TRNS , KC_TRNS , KC_TRNS) ,
  [_ARROW] = LAYOUT_ortho_4x12(
    KC_TRNS      , KC_TRNS , KC_TRNS      , KC_TRNS     , KC_WH_U    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , RESET   , KC_TRNS    ,
    KC_TRNS      , KC_TRNS , KC_TRNS      , KC_MS_BTN2  , KC_MS_BTN1 , KC_TRNS , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_TRNS , KC_TRNS    ,
    KC_TRNS      , KC_TRNS , KC_TRNS      , KC_TRNS     , KC_WH_D    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS    ,
    KC_TRNS      , KC_TRNS , KC_TRNS      , TO(_COLEMAK), KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS)};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _COLEMAK, _NUMPAD, _ARROW);
// }
