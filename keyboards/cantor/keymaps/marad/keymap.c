// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "adpw.h"

#define BASE 0
#define SYMBOLS 1
#define FUNCTIONS 2
#define NUMPAD 3
#define MEDIA 4
#define NAV 5
#define MOUSE 6
#define GAME 7

enum unicode_keys {
    SNEK, XD, GRIN, LOL, ROFL, SMILE, SMILE_UP, SMIRK, SHOCK, HEART, SHRUG
};

const uint32_t unicode_map[] PROGMEM = {
    [SNEK] = 0x1f40d,           // 🐍
    [XD] = 0x1F606,             // 😆
    [GRIN] = 0x1F601,           // 😁
    [LOL] = 0x1F602,            // 😂
    [ROFL] = 0x1F923,           // 🤣
    [SMILE] = 0x1F642,          // 🙂
    [SMILE_UP] = 0x1F643,       // 🙃
    [SMIRK] = 0x1F60F,          // 😏
    [SHOCK] = 0x1F632,          // 😲
    [HEART] = 0x1F49A,          // 💚
    [SHRUG] = 0x1F937           // 🤷
};

enum my_keycodes {
    KC_ADPW = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W,         KC_E, KC_R, KC_T,                               KC_Y, KC_U, KC_I, KC_O, KC_P, LT(SYMBOLS, KC_BSPC),
        QK_LEAD, KC_A, LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,      KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN, LT(NUMPAD,KC_QUOT),
        KC_LGUI, KC_Z, KC_X,         KC_C, KC_V, KC_B,                              KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(FUNCTIONS, CW_TOGG),
                            LT(MEDIA,KC_LGUI), LT(NAV,KC_TAB), LT(MOUSE,KC_SPC),       LT(SYMBOLS,KC_ENT), KC_RALT, MEH_T(KC_DEL)
    ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_ADPW, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,          KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,           LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), KC_NO,
                                     KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_NO, KC_NO
    ),
    [FUNCTIONS] = LAYOUT_split_3x6_3(
        KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO, KC_NO
    ),
    [NUMPAD] = LAYOUT_split_3x6_3(
        KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                           CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                           TG(GAME), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_PDOT, KC_P0, KC_MINS, KC_NO, KC_NO, KC_NO
    ),
    [MEDIA] = LAYOUT_split_3x6_3(
        X(SNEK), X(SHRUG), KC_NO, KC_NO, X(SMILE_UP), KC_NO,                   KC_NO, KC_NO, KC_NO, X(SHOCK), KC_NO, KC_NO,
        KC_NO, X(ROFL), X(LOL), X(GRIN), X(SMILE), X(SMIRK),                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO,
        KC_NO, KC_NO, X(XD), KC_NO, X(HEART), KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                        KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [NAV] = LAYOUT_split_3x6_3(
        KC_NO, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),        KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,
        KC_NO, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,               KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_NO,
                                                       KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC, KC_DEL
    ),
    [MOUSE] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_ACL0,
        KC_NO, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NO,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN3, KC_ACL1,
        QK_MAKE, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_NO,                         KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN4, KC_ACL2,
                                        KC_NO, KC_NO, KC_NO, KC_ENT, KC_BTN1, KC_BTN2
    ),
    [GAME] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_S, KC_D, KC_F, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(GAME),
                                        KC_TRNS, KC_LSFT    , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

uint8_t mods;
static bool delkey_registered; // used for bsp/del key

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mods = get_mods();

    switch (keycode) {
        case KC_ADPW:
            if (record->event.pressed) {
                send_string(ADPW);
            } 
            return false;
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

