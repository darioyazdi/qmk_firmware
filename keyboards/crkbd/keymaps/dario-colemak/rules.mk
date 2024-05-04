MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
COMMAND_ENABLE = no        # Commands for debug and configuration

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
VIA_ENABLE = no
OLED_ENABLE = no
LTO_ENABLE = no
WPM_ENABLE = no

#BOOTLOADER = rp2040

SRC += users/dario/achordion.c
SRC += users/dario/jiggle.c
