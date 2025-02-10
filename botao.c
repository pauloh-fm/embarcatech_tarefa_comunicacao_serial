#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "botao.h"
#include "leds.h"
#include "display.h"
#include <stdio.h>

// Constante para o pino do botão A
const uint botao_a = 5;
const uint botao_b = 6;

// Função para inicializar o botão
void init_botoes(uint botao_pin) {
    gpio_init(botao_pin);
    gpio_set_dir(botao_pin, GPIO_IN);    // Configura o pino como entrada
    gpio_pull_up(botao_pin);           // Habilita o pull-down interno
}

// Função para verificar se o botão foi pressionado (com debounce)
bool button_debounce(uint botao_pin) {
    static uint32_t last_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    // Verifica se o botão foi pressionado (nível alto em pull-down)
    if (gpio_get(botao_pin)== 0) {
        if (current_time - last_time > 800) {  // Delay de debounce de 800ms
            last_time = current_time;
            return true;
        }
    }

    return false;
}
// Função para lidar com as interrupções dos botões
void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == botao_a) {
        alternar_led_verde();
        exibir_estado_led("LED VERDE", led_verde_ligado());
        printf("LED Verde %s\n", led_verde_ligado() ? "LIGADO" : "DESLIGADO");
    }

    if (gpio == botao_b) {
        alternar_led_azul();
        exibir_estado_led("LED AZUL", led_azul_ligado());
        printf("LED Azul %s\n", led_azul_ligado() ? "LIGADO" : "DESLIGADO");
    }
}
