#include "action.h"
#include "arcane.h"
#include "repeat_key.h"

bool arcane_hold = false;
bool arcane_hold_main = false;
bool arcane_hold_aux = false;

keyrecord_t arcane_tapping_record;

__attribute__((weak)) bool process_arcane_tap_user(uint16_t keycode) { return true; }

__attribute__((weak)) bool process_arcane_cast_user(uint16_t keycode) { return true; }
__attribute__((weak)) bool process_arcane_hold_main_user(void) { return true; }
__attribute__((weak)) bool process_arcane_hold_aux_user(void) { return true; }
__attribute__((weak)) bool process_arcane_release_hold_main_user(void) { return true; }
__attribute__((weak)) bool process_arcane_release_hold_aux_user(void) { return true; }

bool process_arcane_tap(uint16_t keycode, keyrecord_t* record) {
	if (!process_arcane_tap_user) {
		return false;
	}

	//TODO: Impelement check for sides action
	arcane_repeat();

	register_arcane(get_last_keycode(), record); //TODO: Rename this function to shadow as it's intention to shadow the last last keyrecord but with arcane positions of the record;
	return false;
}

bool process_arcane(uint16_t keycode, keyrecord_t* record) {
	/* Early return if not arcane key */
	if (keycode != ARCANE) {
		/* Interrupts arcane tap sequence. */
		arcane_tapping_record.tap.interrupted = true;
		if (!is_inside_tepping_term(*arcane_tapping_record)) {
			return true;
		}
	}

	/* Resetting arcane tapping if it is in interrupted state */
	if (arcane_tapping_record.tap.interrupted && keycode == ARCANE) {
		arcane_tapping_record = &record;
	}

	/* Opposite Arcane interruption */
	if (!is_same_split_side(record, *arcane_tapping_record)
			&& record->event.pressed) {
		arcane_tapping_record.tap.interrupted = true;
	}
        
	/* Tap count logic */
	if (is_inside_tapping_term(record)
			&& !arcane_tapping_record.tap.interrupted
			&& !record->event.pressed) {
			arcane_tapping_record.tap.count++;
			return false;
		}

	/*  Tap decisions */
	if (!record->event.pressed) {
		switch(arcane_tapping_record.tap.count) {
			case 1:
				if (arcane_set_leader_mode) {
					return false;
				}
				return process_arcane_tap();
		}
	}

	/* Hold decisions */



	if (record->event.pressed && record->tap.count) { // Tap actions
		if (is_same_split_side_repeat(record)) {
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
	return true;
}
