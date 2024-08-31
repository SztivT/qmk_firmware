#include QMK_KEYBOARD_H
#include "version.h"
#include "keycodes.c"
#include "layers.c"
#include "dance.h"
#include "leader.c"
#include "rgb.c"
#define MOON_LED_LEVEL LED_LEVEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ALPHA] = LAYOUT_voyager(
    KC_Q,           KC_F,           KC_Y,           KC_O,           KC_U,           KC_TRANSPARENT,                                 KC_J,           KC_G,           KC_N,           KC_W,           KC_K,           KC_TRANSPARENT,
    TD(DANCE_0),    MT(MOD_LALT, KC_H),KC_I,           MT(MOD_LSFT, KC_E),MT(MOD_LCTL, KC_A),OSL(5),                                         KC_P,           MT(MOD_LCTL, KC_D),MT(MOD_RSFT, KC_R),KC_S,           MT(MOD_LALT, KC_L),KC_Z,           
    KC_TAB,         KC_X,           KC_SCLN,        KC_DOT,         KC_COMMA,       KC_TRANSPARENT,                                 KC_B,           KC_C,           KC_M,           KC_V,           KC_ENTER,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_1),                                    QK_LEAD,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    LT(4,KC_SPACE), ARCANE,                                         ARCANE,         LT(7,KC_T)
  ),
  [STENO] = LAYOUT_voyager(
    STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         STN_N6,                                         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         STN_NC,         
    KC_TRANSPARENT, STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,                                        STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,         
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                        STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_A,          STN_O,                                          STN_E,          STN_U,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, STN_FN
  ),
  [SYMBOL] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_LBRC,        KC_LCBR,        KC_RCBR,        KC_RBRC,        KC_TRANSPARENT,                                 KC_QUES,        KC_TILD,        KC_SLASH,       KC_EXLM,        KC_HASH,        KC_TRANSPARENT, 
    KC_GRAVE,       KC_DLR,         KC_LPRN,        KC_RPRN,        KC_DQUO,        KC_TRANSPARENT,                                 KC_AT,          KC_RABK,        KC_MINUS,       KC_EQUAL,       KC_LABK,        KC_CIRC,        
    QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,       KC_TRANSPARENT,                                 KC_BSLS,        KC_PLUS,        KC_PIPE,        KC_AMPR,        KC_PERC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_COLN,        KC_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_UNDS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [DIGITS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_0,           KC_5,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NAV] = LAYOUT_voyager(
    DM_REC2,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DM_PLY2,                                        KC_TRANSPARENT, KC_HOME,        KC_PAGE_UP,     KC_PGDN,        KC_END,         KC_TRANSPARENT, 
    DM_REC1,        KC_LEFT_ALT,    KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_LEFT_CTRL,   DM_PLY1,                                        KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    DM_RSTP,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,      KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NORMAL] = LAYOUT_voyager(
    KC_TRANSPARENT, TD(DANCE_2),    KC_V,           TD(DANCE_3),    TD(DANCE_4),    KC_DQUO,                                        TD(DANCE_8),    KC_W,           KC_RBRC,        KC_LBRC,        KC_E,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Z,           KC_X,           MT(MOD_LSFT, KC_P),MT(MOD_LCTL, KC_C),TD(DANCE_5),                                    TD(DANCE_9),    MT(MOD_LCTL, KC_T),MT(MOD_LSFT, KC_F),TD(DANCE_10),   KC_B,           KC_G,           
    KC_TRANSPARENT, KC_PERC,        KC_LABK,        KC_RABK,        TD(DANCE_6),    TD(DANCE_7),                                    KC_TRANSPARENT, KC_LPRN,        KC_RCBR,        KC_LCBR,        KC_RPRN,        QK_LLCK,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_O,                                           KC_TRANSPARENT, OSL(6),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_I,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_A
  ),
  [NORMAL_NAV] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PIPE,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MOUSE] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
};

const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	process_arcane(keycode, record);
	switch (keycode) {
		case RGB_SLD:
			if (record->event.pressed) {
				rgblight_mode(1);
			}
			return false;
	  }
	  return true;
}

bool process_arcane_cast_user(uint16_t keycode) {
	switch (keycode) {
		case MT(MOD_RSFT, KC_R):
			tap_code16(KC_N);
			return;
	}
}

void keyboard_post_init_user(void) {
	 debug_enable=true;
         rgb_matrix_enable();
}
