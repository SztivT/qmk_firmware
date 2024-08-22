# Arcane functions

This is the first implementation of
[empressabyss](https://github.com/empressabyss)'s Arcane key concept.

This proof of Concept introduces the ability for the Arcane key to be aware of
whether or not the last keycode has been sent from the same split side.

While the
[original implementation](https://github.com/empressabyss/nordrassil?tab=readme-ov-file#implementation)
cultivates the keys to understand the split sides, it suggest to use the
keymatrix to achieve the Arcane functionality.

## Proof of Concept

The logic in the poc requeries `REPEAT_KEY_ENABLE = yes` presenting in the
`rules.mk` file.  The PoC is not aiming to further configure the keys, just
adds the behavior.

## Usage

Assuming the familairity with the original implementation's logic, and qmk's way
to define custom keycodes I leave this part for the other well-documented
sources and you to figure it out.

Other than that you should incorporate the following in your keymap configuration:

- `bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
uint8_t* remembered_mods) {}`:

``` c
switch (keycode) {
    case ARCANE:
        return false;
}
```

- `bool process_record_user(uint16_t keycode, keyrecord_t *record) {}`:

```c
process_arcane(keycode, record);
```

- `static keyrecord_t arcane_cache = {0};`, somewhere early, because this
is the one holding the keyrecord information which is needed to be able to
compare. The repeat logic itself does not exposes the keyrecord.

- `uint8_t kbd_rows = 12;` this only used by the process function so it
does not need to be defined long before it, but as a rule of thumb, just
group it with `arcane_cache`. If by any chance your keyboard behaves weird
consider to look into your matrix layout. The logic follows the general
matrix implementation of
[splits](https://docs.qmk.fm/features/split_keyboard#layout-macro).
If your board does not follow the 4 rows + 2 thumb rows layout, then
adjust the value of this respectively.

- `void post_process_record_user(uint16_t keycode, keyrecord_t *record) {}`

```c
set_arcane_cache(keycode, record);
```

- you need to define the above mentioned functions for those calls:

```c
void process_arcane(uint16_t keycode, keyrecord_t *record) {
    if (arcane_cache.event.key.row < kbd_rows / 2
        && record.event.key.row < kbd_rows / 2)
        || (arcane_cache.event.key.row < kbd_rows / 2
            && record.event.key.row < kbd_rows / 2) {
        tap_code16(get_last_keycode());
        return;
    }
    SEND_STRING("Cast");
}
```

```c
set_arcane_cache(uint16_t keycode, keyrecord_t *record) {
    if (keycode == ARCANE) return;
    arcane_cache = *record;
}
```

## Implementation Details

In this implementation as the logic relies on the repeat logic of QMK and not handles
it's own, I simply decided to not deal with cases when the Arcane key is
repeated, or it's casted, but I simply excluded it from repeat logic.

> Maybe it worth a shot to look into the possibilities of arcane repeats.

On every keypress the logic puts the keyrecord (with the corresponding keycode) into
the `arcane_cache` - if it is not Arcane key - by overwriting it. This runs as a
post-process to minimize the number of conditionals in `process_record_*` functions.

The processing itself lives on the presumption, that the splits are symetrical
to each other row-wise.
If the keyrecord contains a row number which is less than the half of
`kbd_rows`, it considered coming from the master half, while if it is more than
or equal it is consiedered to be received from the slave half.
