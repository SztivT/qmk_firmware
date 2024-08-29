#include "action.h"
#include "arcane.h"
#include "repeat_key.h"

bool arcane_hold = false;
bool arcane_hold_main = false;
bool arcane_hold_aux = false;

__attribute__((weak)) bool process_arcane_cast_user(uint16_t keycode) { return true; }
__attribute__((weak)) bool process_arcane_hold_main_user(void) { return true; }
__attribute__((weak)) bool process_arcane_hold_aux_user(void) { return true; }
__attribute__((weak)) bool process_arcane_release_hold_main_user(void) { return true; }
__attribute__((weak)) bool process_arcane_release_hold_aux_user(void) { return true; }

bool process_arcane(uint16_t keycode, keyrecord_t* record) {
	if (keycode != ARCANE) {
		return true;
	}
	if (record->event.pressed && record->tap.count) { // Tap actions
		if (arcane_set_mode()) { // Leader mode
			return false;
		}
		if (is_same_split_side(record)) {
			arcane_repeat();
			return false;
		}
		return process_arcane_cast_user(get_arcane_last());
	}

	if (record->event.pressed && !record->tap.count) { //Hold actions
		if (is_main(record)) {
			arcane_hold_main = true;
			return process_arcane_hold_main_user();
		}
		arcane_hold_aux = true;
		return process_arcane_hold_aux_user();
	}

/* Release actions */
	if (arcane_is_leader()) {
		arcane_leader_start();
		return false;
	}
	if (arcane_hold_main && is_main(record)) {
		arcane_hold_main = false;
		return process_arcane_release_hold_main_user();
	}
	if (arcane_hold_aux && !is_main(record)) {
		arcane_hold_aux = false;
		return process_arcane_release_hold_aux_user();
	}
	register_arcane(get_last_keycode(), get_last_record());
	return true;
}
