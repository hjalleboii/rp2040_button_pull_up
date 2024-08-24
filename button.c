#include "button.h"




RP2040_Button RP2040_Button_init(uint8_t pin)
{
    gpio_init(pin);
    gpio_set_dir(pin,GPIO_IN);
    gpio_pull_up(pin);
    return pin;
}

bool RP2040_Button_get(RP2040_Button button)
{
    return !gpio_get(button);

}
