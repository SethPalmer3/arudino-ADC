#include "adc.h"
#include "serial.h"
#include <avr/io.h>
#include <util/delay.h>

#define MUX(pin) pin

int main(void) {
  serial_begin(9600);
  _delay_ms(16000);

  serial_write(12, "Starting...\n");
  init_ADC();

  while (1) {
    char data = get_small_data();
    serial_write(1, &data);
  }
}
