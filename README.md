# pico-Servo-lib

Basic library to interface the Raspberry Pi Pico with a servo motor

## Usage

- Clone the pico-Servo-lib as a submodule into the project such as in a lib directory

- Add the subdirectory containing the pico-Servo-lib to you main project CMakeLists.txt

- Add pico-Servo-lib library to the executable in the appropriate CMakeLists.txt file

- Add ```#include "servo.hpp"``` to the top of the file

- Create a Servo object on the GPIO pin the servo's control pin is attached to
e.g. for pin 9```Servo servo(9);```

- Set the servo angle using ```servo.set_angle(angle);```

Note: the logic level control pin for the servo operates on 3.3V, but the servo's VCC pin should be connected to 5V. This can be connected to pin 40 if powering the Pico with a USB cable.
