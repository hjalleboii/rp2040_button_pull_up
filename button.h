#include "pico/stdlib.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"{
#endif
typedef uint8_t RP2040_Button;

RP2040_Button RP2040_Button_init(uint8_t);
bool RP2040_Button_get(RP2040_Button);
bool RP2040_Button_Get_Once(RP2040_Button *button);

bool RP2040_Button_Get_Once_timeout(RP2040_Button *button, uint32_t *current_timeout_us, uint32_t dt_us, uint32_t set_timeout_us);

#ifdef __cplusplus
}
#endif
