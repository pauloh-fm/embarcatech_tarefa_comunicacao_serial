#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "botao.h"
#include "display.h"
#include "leds.h"
#include <stdio.h>
#include "matriz_leds.h"
#include "numeros.h"

// Definições dos pinos
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

// Variáveis globais
volatile bool atualizar_display = false;

int main() {
    stdio_init_all();

    // Inicializa componentes
    init_leds();
    init_display(I2C_PORT, I2C_SDA, I2C_SCL);
    init_botoes(botao_a);
    init_botoes(botao_b);
    npInit(LED_PIN_WS2812);
    // Configura interrupções para os botões
    gpio_set_irq_enabled_with_callback(botao_a, GPIO_IRQ_EDGE_FALL, true, gpio_callback);
    gpio_set_irq_enabled(botao_b, GPIO_IRQ_EDGE_FALL, true);

    printf("Sistema iniciado. Aguarde interação.\n");

    char input_char;

    while (true) {
        // Lê entrada do Serial Monitor
        if (scanf("%c", &input_char) == 1) {
            printf("Recebido: %c\n", input_char);

            if (input_char >= '0' && input_char <= '9') {
                // Exibir número no display e na matriz de LEDs
                atualizar_matriz_leds(input_char);
                exibir_no_display(input_char);

            } else {
                // Exibir outros caracteres apenas no display
                exibir_no_display(input_char);
            }
        }

        sleep_ms(100);  // Delay para evitar sobrecarga no loop
    }

    return 0;
}
