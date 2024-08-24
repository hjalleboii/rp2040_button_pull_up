#include "pico/stdlib.h"
#include "stdint.h"

extern "C"{

typedef uint8_t RP2040_Button;

RP2040_Button RP2040_Button_init(uint8_t);
bool RP2040_Button_get(RP2040_Button);

}