#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x5043
#define PRODUCT_ID 0x54A3
#define DEVICE_VER 0x0001
#define PRODUCT Trackball Nano

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 0

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Much more so than a keyboard, speed matters for a mouse. So we'll go for as high
   a polling rate as possible. */
#define USB_POLLING_INTERVAL_MS 1
#define USB_MAX_POWER_CONSUMPTION 100

#define ADNS5050_SCLK_PIN         B7
#define ADNS5050_SDIO_PIN         C6
#define ADNS5050_CS_PIN           B4

#define POINTING_DEVICE_ROTATION_270

#define PLOOPY_DPI_DEFAULT 1
