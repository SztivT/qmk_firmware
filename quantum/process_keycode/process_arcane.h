#pragma once

bool process_arcane_cast_user(uint16_t keycode);
bool process_arcane_hold_user(bool main);
bool process_arcane_release_hold_user(bool main);

bool process_arcane(uint16_t keycode, keyrecord_t* record);
