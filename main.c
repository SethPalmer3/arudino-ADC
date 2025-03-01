#include "adc.h"
#include "serial.h"
#include <avr/io.h>

#define MUX(pin) pin

int main(void) {
  serial_begin(9600);
  init_ADC();

  while (1) {
    char data = (char)get_data();
    serial_write(1, &data);
  }
}
