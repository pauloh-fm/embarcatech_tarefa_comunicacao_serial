#include "inc/ssd1306.h"
#include "inc/font.h"
#include "display.h"

ssd1306_t ssd;
// Função para inicializar o display ssd1306
void init_display(i2c_inst_t *i2c_port, uint sda, uint scl) {
    i2c_init(i2c_port, 400 * 1000); // Inicializa o I2C
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_pull_up(scl);

    ssd1306_init(&ssd, 128, 64, false, 0x3C, i2c_port);
    ssd1306_config(&ssd);
}
// exibir caractere no display
void exibir_no_display(char c) {
    ssd1306_fill(&ssd, false);
    ssd1306_draw_char(&ssd, c, 0, 0);
    ssd1306_send_data(&ssd);
}
// exibir estado do led "Ligado" ou "Desligado"
// Função para exibir o estado dos LEDs no display
void exibir_estados_leds(bool estado_verde, bool estado_azul) {
    // Limpa o display
    ssd1306_fill(&ssd, false);

    // Exibe o estado do LED Verde na primeira linha
    const char *mensagem_verde = estado_verde ? "LED VERDE LIGADO" : "LED VERDE DESLIGADO";
    ssd1306_draw_string(&ssd, mensagem_verde, 0, 0);

    // Exibe o estado do LED Azul na segunda linha
    const char *mensagem_azul = estado_azul ? "LED AZUL LIGADO" : "LED AZUL DESLIGADO";
    ssd1306_draw_string(&ssd, mensagem_azul, 0, 16);  // 16 pixels abaixo da primeira linha

    // Envia as informações para o display
    ssd1306_send_data(&ssd);
}
