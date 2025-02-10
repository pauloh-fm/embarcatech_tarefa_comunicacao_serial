#include "pico/stdlib.h"
#include "leds.h"
#include <stdio.h>

#define LED_BLUE_PIN 12
#define LED_GREEN_PIN 11
#define LED_RED_PIN 13
#define WS2812_PIN 7

static bool estado_led_verde = false;
static bool estado_led_azul = false;

void init_leds() {
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
}

void alternar_led_verde() {
    estado_led_verde = !estado_led_verde;
    gpio_put(LED_GREEN_PIN, estado_led_verde);
}

void alternar_led_azul() {
    estado_led_azul = !estado_led_azul;
    gpio_put(LED_BLUE_PIN, estado_led_azul);
}

bool led_verde_ligado() {
    return estado_led_verde;
}

bool led_azul_ligado() {
    return estado_led_azul;
}


