# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically

#RGBLIGHT_ENABLE = yes  # LED underglow (Enable WS2812 RGB underlight.)
# Other selectable option
#IOS_DEVICE_ENABLE = yes      # connect to IOS device (iPad,iPhone)
VIA_ENABLE = yes

#ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
#    OPT_DEFS += -DLED_ANIMATIONS
#endif

#ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
#    OPT_DEFS += -DIOS_DEVICE_ENABLE
#endif
