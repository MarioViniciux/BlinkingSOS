#include "pico/stdlib.h"

// Define o tempo para ponto, traço e espaçamento (em milissegundos)
#define DOT_DURATION 200
#define DASH_DURATION 800
#define LETTER_SPACE 250
#define SYMBOL_SPACE 125

// Função para acionar o LED
void morse_led(int pin, bool state) {
    gpio_put(pin, state);
}

// Função para trasnformar a letra em código morse (no caso, somente S e O)
void send_morse(char letter, int pin) {
    switch (letter) {
        case 'S': // Em morse, S é representado por "..."
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DOT_DURATION); morse_led(pin, false); sleep_ms(LETTER_SPACE);
            break;
        case 'O': // Em morse, O é representado por "---"
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(SYMBOL_SPACE);
            morse_led(pin, true); sleep_ms(DASH_DURATION); morse_led(pin, false); sleep_ms(LETTER_SPACE);
            break;
    }
}

int main() {
    // Inicia o sistema GPIO
    gpio_init(13); // Usando o pino 13
    gpio_set_dir(13, GPIO_OUT); 

    while (true) {
        // Chama a função criada acima, para passar as letras para o código morse
        send_morse('S', 13);
        send_morse('O', 13);
        send_morse('S', 13);

        // Aguarda 3 segundos antes de repetir
        sleep_ms(3000);
    }
    return 0;
}