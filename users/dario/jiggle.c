#include "quantum.h"
#include "jiggle.h"

static bool mouse_jiggle_mode = false;
static uint16_t counter = 0;

static void jiggle(void) {
  static uint8_t direction = 0;

  switch (direction % 4 ) {
    case 0: tap_code(KC_MS_UP);
    case 1: tap_code(KC_MS_LEFT);
    case 2: tap_code(KC_MS_DOWN);
    default: tap_code(KC_MS_RIGHT);
  }
  direction++;
}

void jiggle_task(void) {
  if (mouse_jiggle_mode && counter < 2) {
    jiggle();
    counter += 3;
  }
  counter++;
  counter &= 0xFFFF;
}

void jiggle_toggle(void) {
  if (!mouse_jiggle_mode) {
    for (uint8_t i = 0; i<8; i++) {
      jiggle();
    }
  }

  counter = 0;
  mouse_jiggle_mode = !mouse_jiggle_mode;
}
