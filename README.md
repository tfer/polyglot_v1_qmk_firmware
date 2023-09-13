# polyglot_v1_qmk_firmware
Customized QMK firmware for my Polyglot v1 steno keyboard. Modified from [Peter Park's original work on the default Polyglot firmware.](https://github.com/petercpark/qmk_firmware/tree/polyglot-v1)

Changes from the default fimware include:

 * Assumes computer is in Dvorak mode
 * Key remappings, such as more convenient navigation arrows and keypad format for numbers
 * New "mini_num" layer adds a keypad to STENO.
 * RGB enabled for WS2812 LEDs
 * Outer LEDs (extreme left & right) indicate QWERTY or STENO. Activating the NUMBER and SYMBOL layers produces LED change as well

# Layout for brian_rgb_custom

## STENO layer
<img src="/figs/steno.png" width="600" alt="Key layout for STENO layer"/>

## QWERTY layer
My computer is in Dvorak, so what you see printed is what my computer outputs when I type the corresponding key. If I were to switch my computer to Qwerty, it would output usual Qwerty keys.

<img src="/figs/qwerty.png" width="600" alt="Key layout for QWERTY layer"/>

## NUMBER layer
Keypad on right side instead of numbers along the top. WASD-type navigation arrows on left.

<img src="/figs/number.png" width="600" alt="Key layout for NUMBER layer"/>

## SYMBOL layer
Output is largely influenced by my computer being in Dvorak.

<img src="/figs/symbol.png" width="600" alt="Key layout for SYMBOL layer"/>

## MINI_NUM layer

Available only from STENO layer.

<img src="/figs/mini_num.png" width = "600" alt="Key layout for MINI_NUM layer"/>

