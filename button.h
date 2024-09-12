#include "pico/stdlib.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"{
#endif
typedef uint8_t RP2040_Button;

RP2040_Button RP2040_Button_init(uint8_t);
bool RP2040_Button_get(RP2040_Button);
bool RP2040_Button_Get_Once(RP2040_Button *button);

#ifdef __cplusplus
}
#endif
