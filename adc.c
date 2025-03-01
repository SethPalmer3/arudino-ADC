#include "adc.h"
#include <avr/io.h>

#define MUX(pin) pin

void init_ADC() {
  ADMUX = MUX(0);    // setting data pin
  PRR |= 0b11111110; // Disabling ADC power saving
  ADCSRA =
      (1 << ADEN) | (1 << ADATE); // Enabling ADC conversation and auto trigger
}

unsigned short get_data() {
  ADCSRA |= (1 << ADSC);
  while (ADCSRA & (1 << ADSC))
    ;
  unsigned short data = 0;
  data |= (ADCL << 8);
  data |= ADCH;
  return data;
}
