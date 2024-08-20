#ifndef ARCANE_ENABLED
  #define ARCANE_ENABLED
  #include "arcane.c"
#endif

static void process_arcane(void);

void set_arcane_cache(uint16_t keycode, keyrecord_t *record);
void set_arcane_last(uint16_t keycode, keyrecord_t *record);

void on_dance_arcane(tap_dance_state_t *state, void *user_data);
void dance_arcane_finished(tap_dance_state_t *state, void *user_data);
void dance_arcane_reset(tap_dance_state_t *state, void *user_data);
