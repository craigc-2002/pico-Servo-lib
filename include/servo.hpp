#ifndef SERVO_H
#define SERVO_H

#include "pico/stdlib.h"

class Servo
{
public:
    Servo(int pin);

    void set_angle(int angle);

private:
    int _servo_pin;
    static const uint16_t _pwm_top {65535}; // maximum PWM top register value
    static constexpr uint16_t _ccr_1ms {_pwm_top / 20}; // counter compare register value for a pulse of 1ms
};

#endif
