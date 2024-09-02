# TODO list

## Issues

- [ ] Mods are not registered, but spam `arcane_cache`

## Chore

- [ ] Dances should be named repsectively
- [ ] `process_arcane()` should be able to handle the
`set_arcane_cache` function, therefore it can be removed, and
`set_arcane_last` can be renamed.

## Keys

### Comma-dot

- `.,` translates to `.<Space>` + OSM Shift
- `,.` translates to `,<Space>`

## Keymapp API

- [ ] make vim and tmux report mode
- [ ] send layer set commands to Keymapp based on reported modes

## Arcane keys

- [x] Implement Arcane keys
- [x] Make Arcane keys switch logic based on keyboard matrix
- [x] Arcane Leader -> After a time between the previous and the ARCANE
record, the key switches to leader mode

## Normal mode

- [ ] Use Arcane logic to implement functionality of `;`, `,`,`n`, `N`
  - [ ] Add direction switch logic for arcane keys (vert/horizontal)
  - [ ] Make `ftFT` and `/?*#` to switch Arcane move direction
  - [ ] Both Arcane keys together switch move direction
- [ ] `"` invokes the alpha layer
- [ ] `<Ctrl>w` should flip to alpha, but the most used functions should
be mapped out respectively.

## Layers

- [x] Digits
- [x] Nav
- [ ] Mouse
- [ ] Terminal
  - [ ] Smart layer for terminal shell
  - [ ] automated enabling with keymapp's smart layers
  - [ ] Should understand view modes:
    - [ ] shell (no tmux, no vim)
    - [ ] tmux modes (should be prior to any other terminal modes; highest layers)
    - [ ] vim modes:
      - [ ] Default normal mode
      - [ ] Insert with triggerability from alpha layer (dynamic key on alpha layer)
      - [ ] visual mode
      - [ ] select mode
    - [ ] The modes should be switch through `raw_hid` communication
      - [ ] At this point the aim is to use keymapps API preferably through Kontrol
      - [ ] Check the behavior of layer on/off capabilities of Kontrol

