enum {
  DANCE_ARCANE = 100
};

static keyrecord_t arcane_last = {0};
static keyrecord_t arcane_cache = {0};

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
