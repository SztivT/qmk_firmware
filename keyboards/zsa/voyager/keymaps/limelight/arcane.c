enum {
  DANCE_ARCANE = 100
};

static keyrecord_t arcane_last = {0};
static keyrecord_t arcane_cache = {0};
static tap arcane_dance_state[1];

uint8_t kbd_rows = 12;

static void set_arcane_cache(uint16_t keycode, keyrecord_t *record) {
	// Save keyrecord
	arcane_cache = *record;
}

static void set_arcane_last(uint16_t keycode, keyrecord_t *record) {
	// If The keycode is ARCANE then ignore it
	switch(keycode) {
		case ARCANE:
		case TD(DANCE_ARCANE):
		      	return;
	}
	// Save keyrecord
	arcane_last = *record;
	arcane_last.keycode = keycode;
}

static void process_arcane(void) {
	if ((arcane_cache.event.key.row < kbd_rows / 2
		&& arcane_last.event.key.row < kbd_rows / 2)
		|| (arcane_cache.event.key.row >= kbd_rows / 2
			&& arcane_last.event.key.row >= kbd_rows / 2)) {
		// repeat
	  tap_code16(arcane_last.keycode);
	  return;
	}

        SEND_STRING("Arcane");
}

void on_dance_arcane(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(ARCANE);
        tap_code16(ARCANE);
        tap_code16(ARCANE);
    }
    if(state->count > 3) {
        tap_code16(ARCANE);
    }
}

void dance_arcane_finished(tap_dance_state_t *state, void *user_data) {
    arcane_dance_state[0].step = dance_step(state);
    switch (arcane_dance_state[0].step) {
        case SINGLE_TAP: process_arcane(); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(KC_N); break;
    }
}

void dance_arcane_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (arcane_dance_state[0].step) {
        case SINGLE_HOLD: layer_off(2); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
    }
    arcane_dance_state[0].step = 0;
}
