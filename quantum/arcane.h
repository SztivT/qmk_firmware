#pragma once

#include "arcane.c"

/*
 * Sends the last keycode registered for repeat.
 */
void arcane_repeat(void);

bool arcane_is_leader(void);

uint16_t get_arcane_last(void);

void register_arcane(uint16_t keycode, keyrecord_t* record);

/*
 * Defines Arcane mode
 */
bool arcane_set_mode(void);

bool is_same_split_side(keyrecord_t* record);

void arcane_leader_start(void);
