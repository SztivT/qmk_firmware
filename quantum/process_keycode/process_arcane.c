#include "action.h"
#include "matrix.h"
#include "leader.h"

#ifndef ARCANE_LEAD_TIME
#  define ARCANE_LEAD_TIME 500
#endif

keyrecord_t* arcane_last_record;

bool arcane_leader_engaged;

__attribute__((weak)) bool process_arcane_tap_user(uint16_t keycode) { return true; }

bool process_arcane(uint16_t keycode, keyrecord_t* record) {
    if (keycode != QK_ARCANE) { return true; }

    /*
     * Compare elapsed time since the last registered record with the leader mode activation timeout on keypress.
     */
    if (record->event.pressed && timer_elapsed(arcane_last_record->event.time) > ARCANE_LEAD_TIME) {
        arcane_leader_engaged = true;

        return false;
    }

    /*
     * Decide which side sent arcane
     */
    if (record->event.pressed && !arcane_leader_engaged) {
        if ((record->event.key.row < matrix_rows() / 2
               && arcane_last_record->event.key.row < matrix_rows() / 2)
          || (record-> event.key.row >= matrix_rows() / 2
               && arcane_last_record->event.key.row >= matrix_rows() / 2)) {
            tap_code(KC_R);
            return false;
        }
        tap_code(KC_O);
        return false;
    }

    /*
     * Starts leader sequence on release when engaged
     */

    if (!record->event.pressed && arcane_leader_engaged) {
        arcane_leader_engaged = false;
        leader_start();
        return false;
    }

    return false;
}
