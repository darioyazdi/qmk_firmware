#pragma once

void jiggle_toggle(void);
void jiggle_task(void);
void register_keycode(uint16_t keycode);

bool process_jiggle(uint16_t keycode, keyrecord_t* record);
