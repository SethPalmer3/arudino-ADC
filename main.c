#include "adc.h"
#include "serial.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define MUX(pin) pin

int main(void) {
  serial_begin(9600);
  _delay_ms(16000);
  char str[4];

  serial_write(12, "Starting...\n");
  init_ADC();

  while (1) {
    char data = get_small_data(0);
    sprintf(str, "%u", data);
    serial_write(4, str);
    serial_write(1, "\r");
  }
}
