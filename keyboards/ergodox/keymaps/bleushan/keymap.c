#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4   |   5  |  6   |           |  7   |   8  |   9  |   0  |   -  |   =  |  ~L1   |
 * |--------+------+------+------+-------+------+------|           |------+------+------+------+------+------+--------|
 * |  ~L2   |   Q  |   W  |   E  |   R   |   T  | Shift|           | Tab  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+-------+------| -Tab |           |      |------+------+------+------+------+--------|
 * |  ~L1   |   A  |   S  |   D  |   F   |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | LGui/' |
 * |--------+------+------+------+-------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V   |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+-------+-------------'           `-------------+------+------+------+------+--------'
 *   | Eject|   `  |   \  | Left | Right |                                       |  Up  | Down |   [  |   ]  |   ~L2  |
 *   `-----------------------------------'                                       `------------------------------------'
 *                                        ,--------------.      ,--------------.
 *                                        | LGui  | LAlt |      | RAlt | RCtrl |
 *                                 ,------+-------+------|      |------+-------+------.
 *                                 |      |       | Home |      | PgUp |       |      |
 *                                 | BkSp |  Del  |------|      |------| Enter | Space|
 *                                 |      |       | End  |      | PgDn |       |      |
 *                                 `---------------------'      `---------------------'
 */
// If it accepts an argument (i.e, is a 3function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,            KC_1,          KC_2,      KC_3,     KC_4,    KC_5,    KC_6,
        KC_FN2,            KC_Q,          KC_W,      KC_E,     KC_R,    KC_T,    LSFT(KC_TAB),
        KC_FN1,            KC_A,          KC_S,      KC_D,     KC_F,    KC_G,
        KC_LSFT,           CTL_T(KC_Z),   KC_X,      KC_C,     KC_V,    KC_B,    ALL_T(KC_NO),
        KC_EJCT,           KC_GRV,        KC_BSLS,   KC_LEFT,  KC_RGHT,
                                                     KC_LGUI, KC_LALT,
                                                              KC_HOME,
                                            KC_BSPC, KC_DELT, KC_END,
        // right hand
        KC_7,          KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_FN1,
        KC_TAB,        KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSLS,
                       KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, GUI_T(KC_QUOT),
        MEH_T(KC_NO),  KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,
                       KC_UP,   KC_DOWN, KC_LBRC,  KC_RBRC, KC_FN2,
        KC_RALT,       KC_RCTL,
        KC_PGUP,
        KC_PGDN,       KC_ENT,  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   \  |      |           |      |   Up |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Left | Right|   <  |   >  |                                       |   0  |    . |   =  |   +  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_BSLS, KC_TRNS,
       KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,
       KC_TRNS, KC_LEFT, KC_RGHT, KC_LABK, KC_RABK,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12,  KC_TRNS,
       KC_TRNS, KC_UP,   KC_7,   KC_8,   KC_9,   KC_PSLS, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,   KC_6,   KC_PAST, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,   KC_3,   KC_PMNS, KC_TRNS,
                         KC_0,   KC_DOT, KC_EQL, KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F13  | F14  | F15  | F16  | F17  | F18  |           |  F19 | F20  | F21  | F22  | F23  | F24  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Next |      | MsUp |      |VolUp |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Prev |MsLeft|MsDown|MsRght|VolDn |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Play | LClk | MClk | RClk | Mute |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
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
[MDIA] = KEYMAP(
       KC_TRNS, KC_F13,  KC_F14,  KC_F17,  KC_F16,  KC_F17,  KC_F18,
       KC_TRNS, KC_MNXT, KC_TRNS, KC_MS_U, KC_TRNS, KC_VOLU, KC_TRNS,
       KC_TRNS, KC_MPRV, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD,
       KC_TRNS, KC_MPLY, KC_BTN1, KC_BTN3, KC_BTN2, KC_MUTE, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F19,   KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

   // Symbol layer turns on red light
   if(layer_state & (1UL<<SYMB)) {
       ergodox_right_led_1_on();
   } else {
       ergodox_right_led_1_off();
   }

   // Media layer turns on green light
   if(layer_state & (1UL<<MDIA)) {
       ergodox_right_led_2_on();
   } else {
       ergodox_right_led_2_off();
   }

};
