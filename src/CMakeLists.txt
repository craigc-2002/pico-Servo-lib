cmake_minimum_required(VERSION 3.13)

file(GLOB FILES *.cpp *.hpp)
add_library(pico-Servo-lib ${FILES})

# LINK LIBRARIES HERE
target_link_libraries(pico-Servo-lib pico_stdlib hardware_gpio hardware_pwm)

target_include_directories(pico-Servo-lib PUBLIC ../include)
