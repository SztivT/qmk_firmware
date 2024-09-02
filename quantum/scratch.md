# Arcane flow

## Modes

> Every mode has to be individually enabled/disabled.

### Leader mode

> Trigger: `ARCANE` Tap event (any hand) registered and the last keystroke was later
then `ARCANE_LEADER_WAIT_TIME`.
> Default: Activates leader sequence
> Hooks: No
> Dependencies: Enabled `LEADER_KEY`

### Tap same hand

> Trigger: `ARCANE` Tap event registered from the same split side of the matrix as the
previous keystroke.
> Default: Repeat last keystroke

### Tap opposite hand

> Trigger: `ARCANE` Tap event registered from the opposite split side of the
matrix as the previous keystroke.
> Default: Cast Nordrassil spells

### Tap same hand same interrupt

> Trigger: `ARCANE` Tap event registered from the same split side of the matrix
as the previous keystroke and got interrupted by the same hand within `ARCANE_TAPPING_TERM`.

### Tap same hand opposite interrupt

### Tap opposite hand same interrupt

> Trigger: `ARCANE` Tap event registered from the opposite split side of the matrix
as the previous keystroke and got interrupted by the opposite hand within `ARCANE_TAPPING_TERM`.

### Tap opposite hand opposite interrupt

### Tap opposite Arcane interrupt

### Long-Tap Main

> Default: OSL(Symbol)

### Long-Tap Aux

> Default: OSL(DIGITS)

### Long-Tap other hand interrupt

### Hold main

> Default: OSL(Symbol)

### Hold aux

### Hold and hit opposite Arcane

> Default: Layer lock

### {Multi-}Tap (+Hold)

> Default double tap: Shift layer sets on long taps by Multi-state logic.

- User defined tap/hold decisions

### Multi-state

> Can be altered by consecutive same/opposite hand Arcane taps.

## Hooks

- All mode needs `_user` hooks.
- Pre/Post-process hooks
- Tap hook for tap actions
- Press/Release hooks for hold actions

## Config

- Every mode should be configured to act on same/opposite or main/aux

## Decision logic

On keypress if the keycode is not arcane, an interruption's being sent for the
Arcane keyrecord, and if the keypress was outside of the `ARCANE_TAPPING_TERM`,
then the processing is finished, and the function returns with true to signal
quantum to further process the keycode.

On Arcane keypress, the logic firstly checks if the cached record is interrupted.
If it is, then it overwrites the record with the one's being evaluted.

Interruption is used to denote if a tap hold decision should conclude before
`ARCANE_TAPPING_TERM`.

A tap decision can be also interrupted by the opposite Arcane key.

Every time on an `ARCANE(up)` event coming from the same matrix position within
the `ARCANE_TAPPING_TERM`, if the stored record is not yet interrupted, the
logic increments its tap count.

Once the logic is concluded it will evaluated as it's described under the modes.
