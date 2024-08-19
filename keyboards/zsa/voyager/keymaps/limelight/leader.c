void leader_end_user(void) {
  if (leader_sequence_one_key(KC_H)) {
	  register_code(KC_LCTL);
	  tap_code(KC_B);
	  unregister_code(KC_LCTL);
  }
}
