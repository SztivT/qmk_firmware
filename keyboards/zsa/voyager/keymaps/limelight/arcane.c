enum {
  DANCE_ARCANE = 100
};

static keyrecord_t arcane_cache = {0};

uint8_t kbd_rows = 12;

static void set_arcane_cache(uint16_t keycode, keyrecord_t *record) {
	// Save keyrecord
	arcane_cache = *record;
	arcane_cache.keycode = keycode;
}

static void process_arcane(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case ARCANE:
	if (record->event.pressed) {
		if ((record->event.key.row < kbd_rows / 2
			&& arcane_cache.event.key.row < kbd_rows / 2)
			|| (record->event.key.row >= kbd_rows / 2
				&& arcane_cache.event.key.row >= kbd_rows / 2)) {
			// repeat
			tap_code16(arcane_cache.keycode);
			return;
		}
		//Spells to cast
		switch (arcane_cache.keycode) {
			case MT(MOD_RSFT, KC_R):
				tap_code16(KC_N);
				return;
		}
		return;
	}
	}
	if (keycode == ARCANE) return;
	set_arcane_cache(keycode, record);
}
