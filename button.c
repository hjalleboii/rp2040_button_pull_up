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


bool RP2040_Button_Get_Once_timeout(RP2040_Button *button, uint32_t * current_timeout_us, uint32_t dt_us, uint32_t set_timeout_us){

    uint8_t pressed = (*button)&(0x80);

    bool v = false;

    uint8_t pin = (*button) & 0x3F;
    if(!gpio_get(pin)){
        if((!pressed) && (*current_timeout_us == 0)){
            *button = pin | 0x80;
            *current_timeout_us = set_timeout_us;
            v = true;
        }

    }else{
        if (*current_timeout_us > dt_us) {
            *current_timeout_us -= dt_us;     // Safe subtraction — no underflow
        } else {
            *current_timeout_us = 0;       // Clamp to zero when dt >= timeout
        }
        *button = pin;
    }

    return v;
    

}