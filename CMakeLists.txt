cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(pzem C CXX ASM)

pico_sdk_init()

add_executable(pzem
        main.cpp
    )

pico_enable_stdio_usb(pzem 1)
pico_enable_stdio_uart(pzem 0)

target_link_libraries(pzem pico_stdlib hardware_uart) #hardware_spi hardware_i2c
pico_add_extra_outputs(pzem)