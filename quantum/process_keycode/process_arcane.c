#include "action.h"

bool process_arcane(uint16_t keycode, keyrecord_t* record) {
    if (keycode != QK_ARCANE) { return true; }

    tap_code(KC_A);
    return false;
}
