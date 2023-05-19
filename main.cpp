//#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pzem.cpp"

#define ALLWAYS_HIGHT 16
#define I1 17


int main() {
    stdio_init_all();

    gpio_init(ALLWAYS_HIGHT);
    gpio_set_dir(ALLWAYS_HIGHT, GPIO_OUT);
    gpio_put(ALLWAYS_HIGHT, 1);
    
    gpio_init(I1);
    gpio_set_dir(I1, GPIO_IN);
    gpio_pull_down(I1);
    
    pzem::init();

    while(true) {
        if (gpio_get(I1)) {
            printf("as\n");
            pzem::test();
            sleep_ms(1000);
        }

    }

    return 0;
}