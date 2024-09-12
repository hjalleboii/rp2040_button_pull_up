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
    return !gpio_get(button & 0x3F);

}

bool RP2040_Button_Get_Once(RP2040_Button *button){
    uint8_t pressed = (*button)&(0x80);


    uint8_t pin = (*button) & 0x3F;
    if(!gpio_get(pin)){
        if(!pressed){
            *button = pin | 0x80;
            return true;
        }
    }else{
        *button = pin;
    }

    return false;
    

}