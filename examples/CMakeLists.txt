add_executable(HelloServo
    HelloServo.cpp
)

# LINK LIBRARIES HERE
target_link_libraries(HelloServo pico-Servo-lib hardware_gpio)

pico_add_extra_outputs(HelloServo)
