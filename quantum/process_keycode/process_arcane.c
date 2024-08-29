#include "action.h"
#include "arcane.h"
#include "repeat_key.h"

__attribute__((weak)) bool process_arcane_cast_user(uint16_t keycode) { return true; }

bool process_arcane(uint16_t keycode, keyrecord_t* record) {
	if (keycode != ARCANE) {
		return true;
	}
	if (record->event.pressed) {
		if (arcane_set_mode()) {
			return false;
		}
		if (is_same_split_side(record)) {
			arcane_repeat();
			return false;
		}
		return process_arcane_cast_user(get_arcane_last());
	}
	if (arcane_is_leader()) {
		arcane_leader_start();
		return false;
	}
	register_arcane(get_last_keycode(), get_last_record());
	return true;
}
