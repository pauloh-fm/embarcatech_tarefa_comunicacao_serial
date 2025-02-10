
#include "hardware/i2c.h"
#include <stdbool.h>

void init_display(i2c_inst_t *i2c_port, uint sda, uint scl);
void exibir_no_display(char c);
void exibir_estado_led(const char *mensagem, bool estado);

