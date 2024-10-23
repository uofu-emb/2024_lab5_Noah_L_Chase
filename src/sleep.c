#include <stdio.h>
#include <pico/stdlib.h>
#include "realtime.h"

int main(void)
{
    int toggle = 0;
    stdio_init_all();
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);

    while (true) {
        toggle = !toggle;
        gpio_put(OUT_PIN, toggle);
        for (int i = 0; i < 8000; i++) {
            for (int j = 2; j <= i/2; j++) {
                if (i % j == 0) {
                    i++;
                    break;
                }
            }
        }
        sleep_ms(DELAY_MS);
    }
}
