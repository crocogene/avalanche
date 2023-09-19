// Copyright 2023 @crocogene
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km croco
qmk flash -kb avalanche/v4 -km croco
*/

#include QMK_KEYBOARD_H
#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE

#include "arbitrary_keycode/include.h"
#include "lang_shift/include.h"
#include "combo/include.h"

enum tap_dance {
    _TD_ESC_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [_TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), // Tap once for Escape, twice for Caps Lock
};

enum layers {
  L_EN = 0,
  L_EN_S,
  L_RU,
  L_RU_S,
  L_RED,
  L_GREN,
  L_VIOL,
  L_GRAY,
  //L_CYAN,
  L_YELW,
  //L_GAM,
  L_NUCL,
};

#define TG_RED TG(L_RED)
#define TG_GREN TG(L_GREN)
#define TG_VIOL TG(L_VIOL)
#define TG_GRAY TG(L_GRAY)
//#define TG_CYAN TG(L_CYAN)
#define TG_YELW TG(L_YELW)
//#define TG_GAME TG(L_GAME)
#define TG_NUCL TG(L_NUCL)

#define MO_RED MO(L_RED)
#define MO_GREN MO(L_GREN)
#define MO_VIOL MO(L_VIOL)
#define MO_GRAY MO(L_GRAY)
//#define MO_CYAN MO(L_CYAN)
#define MO_YELW MO(L_YELW)
//#define MO_GAME MO(L_GAME)
#define MO_NUCL MO(L_NUCL)

#define TT_RED (TT_000 + L_RED)
#define TT_GREN (TT_000 + L_GREN)
#define TT_VIOL (TT_000 + L_VIOL)
#define TT_GRAY (TT_000 + L_GRAY)
//#define TT_CYAN (TT_000 + L_CYAN)
#define TT_YELW (TT_000 + L_YELW)
//#define TT_GAME (TT_000 + L_GAME)
#define TT_NUCL (TT_000 + L_NUCL)

// Этот макрос нужен, чтобы задавать одинаковые слои (в том числе и шифтовый слой) для английского и русского языка. В итоге их отличия будут только в буквах.
#define LANG_TWO_LAYERS(\
  L_DEFAULT, L_SHIFT,\
  \
  /* Left hand */ \
       LU1, LU2, LU3, LU4, LU5, \
  LH0, LH1, LH2, LH3, LH4, LH5, \
       LD1, LD2, LD3, LD4, LD5, \
  /* Right hand */ \
  RU1, RU2, RU3, RU4, RU5, \
  RH1, RH2, RH3, RH4, RH5, RH6, RH0, \
  RD1, RD2, RD3, RD4, RD5, \
  \
  /* ---------------------------- Shift layer ---------------------------- */ \
  /* Left hand */ \
        SLU1, SLU2, SLU3, SLU4, SLU5, \
  SLH0, SLH1, SLH2, SLH3, SLH4, SLH5, \
        SLD1, SLD2, SLD3, SLD4, SLD5, \
  /* Right hand */ \
  SRU1, SRU2, SRU3, SRU4, SRU5, \
  SRH1, SRH2, SRH3, SRH4, SRH5, SRH6, SRH0, \
  SRD1, SRD2, SRD3, SRD4, SRD5 \
) \
  /*-------------------------------------------------------------------------*/ \
  [L_DEFAULT] = LAYOUT( \
				 KC_ESC,  AG_UNDS, CMB_SCL, CMB_GRV, CMB_EXL, CMB_ASR,											 CMB_EQL, CMB_CLN, CMB_CMM, CMB_QUE, CMB_SLS, CT_Z, \
				 CMB_PLS, LU1,     LU2,     LU3,     LU4,     LU5,      										 RU1,     RU2,     RU3,     RU4,     RU5,     AG_MINS, \
		LH0,     SFT_N_O, LH1,     LH2,     LH3,     LH4,     LH5,												 RH1,     RH2,     RH3,     RH4,     RH5,     RH6, 	   RH0, \
				 CMB_LYG, LD1,     LD2,     LD3,     LD4,     LD5,	   CMB_CTL, CMB_BSP, /**/  CMB_ALT, CMB_DOT, RD1,     RD2,     RD3,     RD4,     RD5,     _______, \
                                            TT_GRAY, CMB_RED, CMB_LYV, CMB_SFT, CMB_ENT, /**/  CMB_LAN, CMB_SPC, AG_3DOT, CMB_RED, TT_NUCL \
  ), \
  /*-------------------------------------------------------------------------*/ \
  [L_SHIFT] = LAYOUT( \
    /* LEFT HALF */ \
                 _______, _______, _______, _______, _______, AG_CMNT,                                           _______, AG2COLN, AG_COMM, _______, AG2SLSH, CT_Y, \
                 _______, SLU1,    SLU2,    SLU3,    SLU4,    SLU5,                                              SRU1,    SRU2,    SRU3,    SRU4,    SRU5,    _______, \
        SLH0,    _______, SLH1,    SLH2,    SLH3,    SLH4,    SLH5,                                              SRH1,    SRH2,    SRH3,    SRH4,    SRH5,    SRH6,    SRH0, \
                 _______, SLD1,    SLD2,    SLD3,    SLD4,    SLD5,    _______, _______, /**/  _______, _______, SRD1,    SRD2,    SRD3,    SRD4,    SRD5,    _______, \
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______ \
  ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LANG_TWO_LAYERS(
    L_EN, L_EN_S,

    /* Left hand */
             AC_GRV,  EN_X,    EN_Y,    EN_P,    EN_S_I,
    XXXXXXX, EN_A,    EN_O,    EN_E,    EN_U,    EN_I,
             AC_ACT,  EN_Q,    EN_J,    EN_K,    AC_CIRC,

    /* Right hand */
    EN_F,    EN_G,    EN_C,    EN_R,    EN_L,
    EN_D,    EN_H,    EN_T,    EN_N,    EN_S,    XXXXXXX, AC_TILD,
    EN_B,    EN_M,    EN_W,    EN_V,    EN_Z,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             AC_GRV,  EN_S_X,  EN_S_Y,  EN_S_P,  EN_S_I,
    _______, EN_S_A,  EN_S_O,  EN_S_E,  EN_S_U,  EN_S_I,
             AC_ACT,  EN_S_Q,  EN_S_J,  EN_S_K,  AC_CIRC,

    /* Right hand */
    EN_S_F,  EN_S_G,  EN_S_C,  EN_S_R,  EN_S_L,
    EN_S_D,  EN_S_H,  EN_S_T,  EN_S_N,  EN_S_S,  _______, _______,
    EN_S_B,  EN_S_M,  EN_S_W,  EN_S_V,  EN_S_Z
    )

    LANG_TWO_LAYERS(
    L_RU, L_RU_S,

    /* Left hand */
             RU_J,    RU_TS,   RU_U,    RU_JE,   RU_F,
    XXXXXXX, RU_K,    RU_M,    RU_V,    RU_A,    RU_P,
             RU_JA,   RU_CH,   RU_S,    RU_I,    RU_Y,

    /* Right hand */
    RU_SC,   RU_Z,    RU_T,    RU_N,    RU_G,
    CMS_R,   RU_O,    RU_L,    RU_D,    RU_ZH,   RU_E, RU_JO,
    CMS_SH,  RU_SF,   RU_B,    RU_JU,   RU_H,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             RU_S_J,  RU_S_TS, RU_S_U,  RU_S_JE, RU_S_F,
    _______, RU_S_K,  RU_S_M,  RU_S_V,  RU_S_A,  RU_S_P,
             RU_S_JA, RU_S_CH, RU_S_S,  RU_S_I,  RU_S_Y,

    /* Right hand */
    RU_S_SC, RU_S_Z,  RU_S_T,  RU_S_N,  RU_S_G,
    CMS_S_R, RU_S_O,  RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E, RU_S_JO,
    CMS_SSH, RU_S_SF, RU_S_B,  RU_S_JU, RU_S_H
    )

    [L_RED] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

    [L_GREN] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

    [L_VIOL] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

    [L_GRAY] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

    [L_YELW] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

    [L_NUCL] = LAYOUT(
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______, _______, /**/  _______, _______, _______, _______, _______
    ),

};

// Combos
const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    static const char PROGMEM ball_empty[] = {
        0,  0,  0,  0,  0,  0,  0,  0,224, 24,  4,  2,  2,  1,  1,  1,  1,  1,  2,  2,  4, 24,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 12, 16, 32, 32, 64, 64, 64, 64, 64, 32, 32, 16, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    static const char PROGMEM ball_full[] = {
        0,  0,  0,  0,  0,  0,  0,  0,224,248,252,254,254,255,255,255,255,255,254,254,252,248,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 31, 63, 63,127,127,127,127,127, 63, 63, 31, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    int position = 14;

    int layer = get_highest_layer(layer_state) - 1;

    for (int i = 0; ( i < sizeof(keymaps)/sizeof(keymaps[0]) - 1 ) && position >= 0; i++)
    {
        oled_set_cursor(0, position);
;
        if (layer >= 0 && layer >= i)
        {
            oled_write_raw_P(ball_full, sizeof(ball_full));
        }
        else
        {
            oled_write_raw_P(ball_empty, sizeof(ball_empty));
        }

        position -= 2;
    }

    return false;
}
#endif

