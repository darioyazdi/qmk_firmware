#include "quantum.h"
#include "jiggle.h"

static uint8_t direction = 0;

void jiggle(void) {
  switch (direction % 4 ) {
    case 0: tap_code(KC_MS_UP);
    case 1: tap_code(KC_MS_LEFT);
    case 2: tap_code(KC_MS_DOWN);
    default: tap_code(KC_MS_RIGHT);
  }
  direction++;
}
