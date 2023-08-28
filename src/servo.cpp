#include "servo.hpp"

#include "hardware/gpio.h"
#include "hardware/pwm.h"

/* pico-Servo-lib
 * Craig Cochrane, 2023
 *
 * Library to drive a servo motor from the Raspberry Pi Pico
 *
 * The angle of the servo motor is set by a PWM signal: (from servo motor datasheet)
 * The PWM signal has a period of 20ms (50Hz)
 * The angle is set by the pulse width
 * 0 degrees (1ms) -> 90 degrees (1.5ms) -> 180 degrees (2ms)
*/

Servo::Servo(int pin)
{
    _servo_pin = pin;

    gpio_set_function(pin, GPIO_FUNC_PWM);
    int slice = pwm_gpio_to_slice_num(pin);
    
    /* Set the PWM output to have a period of 20ms (f_pwm = 50Hz)
     * the Raspberry Pi Pico has a default clock frequency of 125MHz
     * set clock divider so that the pwm top register can be as high as possible to maximise resolution
     * 
     * f_clk = 125MHz, max_count = 65535
     * clock divider = f_clk / (max_count * f_pwm) = 38.15
     */
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 38.15);
    pwm_init(slice, &config, true);

    set_angle(0);
}

void Servo::set_angle(int angle)
{
    float pulse_width = (angle / 90.0f) + 0.5f;
    float duty_cycle = pulse_width / 20.0f;
    unsigned int ccr_val = duty_cycle * _pwm_top;
    pwm_set_gpio_level(_servo_pin, ccr_val);
}
