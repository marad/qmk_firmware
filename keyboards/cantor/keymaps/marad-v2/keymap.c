// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "adpw.h"

#define BASE 0
#define SYMBOLS 1
#define NUMPAD 2
#define NAV 3
#define QTM 4
#define GAME 5
#define EMP 6

enum my_keycodes {
    KC_ADPW = SAFE_RANGE
};

const uint16_t PROGMEM temp_numkey[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM temp_funkey[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(temp_numkey, MO(NUMPAD)),
    COMBO(temp_funkey, MO(NUMPAD)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC       , KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        OSM(MOD_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G,      KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LGUI      , KC_Z, KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, QK_LEAD,
                   LT(NAV, KC_TAB), KC_LSFT, KC_SPC,      KC_ENT, MO(SYMBOLS), KC_LALT
    ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_GRV  , KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, PB_1   , _______, TO(GAME),
        KC_TILD , _______, KC_LABK, KC_RABK, KC_MINS, KC_PLUS,       KC_NUHS, KC_LCBR, KC_RCBR, KC_PIPE, KC_COLN, KC_DQUO,
        TO(BASE), _______, KC_LBRC, KC_RBRC, KC_UNDS,  KC_EQL,       KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, _______, TO(QTM),
                                    TO(NAV), CW_TOGG, KC_UNDS,       _______, _______, _______
    ),
    [NUMPAD] = LAYOUT_split_3x6_3(
        _______ ,  KC_F12,  KC_F11,  KC_F10,   KC_F9, KC_COMM,        KC_DOT,    KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______ ,   KC_F8,   KC_F7,   KC_F6,   KC_F5, _______,       KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PAST, _______,
        TO(BASE),   KC_F4,   KC_F3,   KC_F2,   KC_F1, _______,       KC_PMNS,    KC_1,    KC_2,    KC_3, _______, KC_PEQL,
                                    _______, _______, _______,       _______, TO(NAV),    _______
    ),
    [NAV] = LAYOUT_split_3x6_3(
        _______ , KC_ACL2, KC_WH_L, KC_MS_U, KC_WH_R, _______,       KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______,
        _______ , KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,       KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, _______, _______,
        TO(BASE), KC_ACL0, KC_WH_D, _______, KC_WH_U, KC_BTN2,       KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
                                    _______, _______, _______,       _______, TO(NUMPAD), _______
    ),
    [QTM] = LAYOUT_split_3x6_3(
        TO(BASE), _______, _______, _______, _______, _______,       DB_TOGG, _______, _______, _______, _______, _______,
        _______ , _______, _______, _______, QK_BOOT, _______,       QK_MAKE, QK_RBT , _______, _______, _______, _______,
        TO(BASE), _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,       _______, _______, _______
    ),
    [GAME] = LAYOUT_split_3x6_3(
        _______ , KC_T   , KC_Q   , KC_W   , KC_E   , KC_R   ,       _______, _______, _______, _______, _______, TO(BASE),
        KC_LCTL , KC_G   , KC_A   , KC_S   , KC_D   , KC_F   ,       _______, _______, _______, _______, _______, _______,
        TO(BASE), KC_B   , KC_Z   , KC_X   , KC_C   , KC_V   ,       _______, _______, _______, _______, _______, _______,
                                    KC_TAB , KC_LSFT, _______,       _______, _______, _______
    ),
    [EMP] = LAYOUT_split_3x6_3(
        _______ , _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______ , _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        TO(BASE), _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,       _______, _______, _______
    )
    // TG(GAME) - nakłada warstwę do grania
    // KC_ADPW - wpisuje hasło AD
    // KC_HOME/KC_END - to mogłoby być zrobione prze długie przyciśnięcie H/L
    // KC_PGDN/KC_PGUP - nie używam tego raczej więc chyba zostanie bez
    // LALT(KC_1/2/...) - te się przydają w intellij, ale teraz nie ma sposobu, żeby ich użyć :(
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool handle_custom_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_ADPW:
            if (record->event.pressed) {
                send_string(ADPW);
            }
            return false;
        default:
            return true;
    }
}


uint8_t mods;
static bool delkey_registered; // used for bsp/del key
bool shift_and_bsp_to_del(uint16_t keycode, keyrecord_t *record) {
    mods = get_mods();

    switch (keycode) {
        case KC_BSPC:
            // SFT + BSP -> DEL
            if (record->event.pressed) {
                if (mods & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    delkey_registered = true;
                    set_mods(mods);
                    return false;
                }
            } else {
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            return true;
        default:
            return true;
    }

}

static bool alt_held = false;
static bool alt_registered = false;
bool alt_juggling(uint16_t keycode, keyrecord_t *record) {
    // sadly - this does not work, and for some reason registers ctrl (?!)
    // for now I'll just get back to having ralt by default

    switch (keycode) {
        case KC_LALT:
            if (record->event.pressed) {
                alt_held = true;
            } else {
                if (!alt_registered) {
                    register_code(KC_LALT);
                    // register_mods(MOD_LALT);
                }
                unregister_mods(MOD_MASK_ALT);
                // unregister_code(KC_LALT);
                // unregister_code(KC_RALT);
                alt_held = false;
                alt_registered = false;
            }
            return false;

        // switch left alt for right alt to make polish letters: ąćęłńóśźż
        case KC_A: case KC_C: case KC_E: case KC_L: case KC_N:
        case KC_O: case KC_S: case KC_X: case KC_Z:
            if (/*record->event.pressed &&*/ alt_held) {
                register_code(KC_RALT);
                // add_mods(MOD_RALT);
                alt_registered = true;
            }
            return true;
        default:
            if (alt_held) {
                register_code(KC_LALT);
                // add_mods(MOD_LALT);
                alt_registered = true;
            }
            return true;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return
        alt_juggling(keycode, record)
        && handle_custom_keycodes(keycode, record)
        && shift_and_bsp_to_del(keycode, record);
}


void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_G)) {
        // Leader, f => Activates the GAME layer
        layer_invert(GAME);
    // } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        // SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_two_keys(KC_W, KC_E)) {
        SEND_STRING(WORK_MAIL);
    } else if (leader_sequence_two_keys(KC_W, KC_L)) {
        SEND_STRING(WORK_LOGIN);
    } else if (leader_sequence_three_keys(KC_W, KC_P, KC_W)) {
        SEND_STRING(ADPW);
    } else if (leader_sequence_three_keys(KC_H, KC_P, KC_W)) {
        SEND_STRING(BISCUIT);
    // } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Opens google.com
        // SEND_STRING(SS_LCTL("r"));
        // SEND_STRING("https://google.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}

