#include <stdint.h>

extern const uint botao_a; // Botão A GPIO5
extern const uint botao_b; // Botão B GPIO5
void init_botoes(uint botao_pin);
bool button_debounce(uint botao_pin);