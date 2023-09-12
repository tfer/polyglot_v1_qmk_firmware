# polyglot_v1_qmk_firmware
Customized QMK firmware for my Polyglot v1 steno keyboard. Modified from [Peter Park's original work on the default Polyglot firmware.](https://github.com/petercpark/qmk_firmware/tree/polyglot-v1)

Changes from the default fimware include:

 * Assumes computer is in Dvorak mode
 * Key remappings, such as more convenient navigation arrows and keypad format for numbers
 * RGB enabled for WS2812 LEDs

# To do list
- [ ] Test to see if firmware actually works! (Not yet done!) 

# Layout for brian_rgb_custom
## STENO layer
Only small changes to the navigation arrow area.

<img src="/figs/steno.png" width="600" alt="Key layout for STENO layer"/>

## QWERTY layer
No changes made, despite appearances. My computer is in Dvorak, so what you see printed is what my computer outputs when I type the corresponding key. If I were to switch my computer to Qwerty, it would output usual Qwerty keys.

<img src="/figs/qwerty.png" width="600" alt="Key layout for QWERTY layer"/>

## NUMBER layer
Significant changes.

<img src="/figs/number.png" width="600" alt="Key layout for NUMBER layer"/>

## SYMBOL layer
Some changes. Output is largely influenced by my computer being in Dvorak.

<img src="/figs/symbol.png" width="600" alt="Key layout for SYMBOL layer"/>
