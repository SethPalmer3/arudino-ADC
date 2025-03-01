#include "adc.h"
#include "serial.h"
#include <avr/io.h>

#define MUX(pin) pin

void init_ADC() {
  ADMUX = MUX(0);       // setting data pin
  PRR |= 0b11111110;    // Disabling ADC power saving
  ADCSRA |= 0b11111111; // Enabling ADC conversation
}

unsigned short get_data() {
  unsigned short data = 0;
  data |= (ADCL << 8);
  data |= ADCH;
  return data;
}

int main(void) {
  serial_begin(9600);

  char *data = "Test";
  while (1) {
    serial_write(4, data);
  }
}
