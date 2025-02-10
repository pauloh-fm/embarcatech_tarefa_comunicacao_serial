#include "ssd1306.h"
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
void exibir_estado_led(const char *mensagem, bool estado) {
    ssd1306_fill(&ssd, false);
    ssd1306_draw_string(&ssd, estado ? strcat(mensagem, " Ligado") : strcat(mensagem, " Desligado"), 0, 0);
    ssd1306_send_data(&ssd);
}
