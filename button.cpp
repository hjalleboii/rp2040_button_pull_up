#include "button.h"



Button::Button(uint pin):pin(pin)
{
    gpio_init(pin);
    gpio_set_dir(pin,GPIO_IN);
    gpio_pull_up(pin);
}

bool Button::get()
{
    return !gpio_get(pin);
}
