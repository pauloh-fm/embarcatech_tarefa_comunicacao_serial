#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>


int main()
{
    // Inicializa a UART para saída serial
    stdio_init_all();

    // Loop principal
    while (true)
    {

        sleep_ms(1000);
    }

    return 0;
}
