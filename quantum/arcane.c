#include "quantum.h"
#include "leader.h"
#include "repeat_key.h"

#ifndef LEADER_MODE_WAIT
  #define LEADER_MODE_WAIT 2000
#endif

#ifndef KEYBOARD_ROWS_PER_SPLIT
  #define KEYBOARD_ROWS_PER_SPLIT 6
#endif

#ifndef ARCANE_TAPPING_TERM
#  define ARCANE_TAPPING_TERM TAPPING_TERM
#endif

bool arcane_leader = false;

void arcane_repeat(void) {
    tap_code16(get_last_keycode());
}

uint16_t get_arcane_last(void) {
	return get_last_keycode();
}

void register_arcane(uint16_t keycode, keyrecord_t* record) {
	set_last_record(keycode, record);
}

void arcane_leader_start(void) {
arcane_leader = false;
leader_start();
}

bool arcane_is_leader(void) {
	return arcane_leader;
}

bool arcane_set_leader_mode(void) {
	arcane_leader = timer_elapsed(get_last_record()->event.time) > LEADER_MODE_WAIT;
	return arcane_is_leader();
}

bool is_main(keyrecord_t* record) {
	if (record->event.key.row < KEYBOARD_ROWS_PER_SPLIT) {
		return true;
	}
	return false;
}

bool is_same_split_side(keyrecord_t* record, keyrecord_t* compare) {
	if ((is_main(record) && is_main(get_last_record()))
			|| (is_main(record) && is_main(get_last_record()))) {
		return true;
	}
	return false;
}

bool is_same_split_side_repeat(keyrecord_t* record) {
	is_same_split_side(record, get_last_record())
	return false;
}

bool is_inside_tapping_term(keyrecord_t* record) {
	return timer_elapsed(record->event.time) < ARCANE_TAPPING_TERM;
}
