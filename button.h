#include "pico/stdlib.h"
class Button{
    uint pin;
    public:
    Button(uint pin);
    bool get();

};