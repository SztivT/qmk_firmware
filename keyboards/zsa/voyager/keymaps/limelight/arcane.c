static keyrecord_t arcane_cache = {0};

uint8_t kbd_rows = 12;

static void process_arcane(uint16_t keycode, keyrecord_t *record);
void set_arcane_cache(uint16_t keycode, keyrecord_t *record);

void set_arcane_cache(uint16_t keycode, keyrecord_t *record) {
	// If The keycode is ARCANE then ignore it
	if (keycode == ARCANE) return;
	// Save keyrecord
	arcane_cache = *record;
}


static void process_arcane(uint16_t keycode, keyrecord_t *record) {

	if ((arcane_cache.event.key.row < kbd_rows / 2
		&& record->event.key.row < kbd_rows / 2)
		|| (arcane_cache.event.key.row >= kbd_rows / 2
			&& record->event.key.row >= kbd_rows / 2)) {
		// repeat
	  uint16_t last_kc = get_last_keycode();
	  tap_code16(last_kc);
	  return;
	}

        SEND_STRING("Arcane");
}
