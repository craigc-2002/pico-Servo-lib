#include "servo.hpp"
#include "hardware/gpio.h"

Servo servo(9);

int main()
{
    int angle{90};
    bool increasing {true};
    gpio_init(25);
    gpio_put(25, 1);

    while (true)
    {
        if (increasing)
        {
            servo.set_angle(angle);
            angle++;
        }
        else
        {
            servo.set_angle(angle);
            angle--;            
        }

        if (angle == 0)
        {
            increasing = true;
        }else if (angle == 180)
        {
            increasing = false;
        }

        sleep_ms(10);
    }
}
