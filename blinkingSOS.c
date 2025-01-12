#include "pico/stdlib.h"

#define DOT_DURATION 200
#define DASH_DURATION 800
#define LETTER_SPACE 250
#define SYMBOL_SPACE 125

void morse_led(int pin, bool state) {
    gpio_put(pin, state);
}

void send_morse(char letter, int pin) {
    switch (letter) {
        case 'S': 
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(LETTER_SPACE);
            break;
        case 'O': 
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(LETTER_SPACE);
            break;
    }
}

int main() {
    gpio_init(13);
    gpio_set_dir(13, GPIO_OUT);

    while (true) {
        send_morse('S', 13);
        send_morse('O', 13);
        send_morse('S', 13);

        sleep_ms(3000);
    }
    return 0;
}