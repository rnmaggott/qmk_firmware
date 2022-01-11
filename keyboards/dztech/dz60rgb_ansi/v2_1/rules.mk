# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = lufa-ms
BOOTLOADER_SIZE = 6144

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

MOUSEKEY_ENABLE = yes          # Mouse keys
EXTRAKEY_ENABLE = yes          # Audio control and System control
CONSOLE_ENABLE = no            # Console for debug
COMMAND_ENABLE = no            # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no          # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no           # Enable keyboard RGB underglow
AUDIO_ENABLE = no              # Audio output
RGB_MATRIX_ENABLE = yes        # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3733
LTO_ENABLE = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no          # Breathing sleep LED during USB suspend
# if this doesn't work, see here httpsgithub.comtmktmk_keyboardwikiFAQ#nkro-doesnt-work
BLUETOOTH_ENABLE = no          # Enable Bluetooth
NO_USB_STARTUP_CHECK = yes      # Disable initialization only when usb is plugged in
VIA_ENABLE = yes
WAIT_FOR_USB = yes
