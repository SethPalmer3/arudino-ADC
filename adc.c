#include "adc.h"

#define MUX(pin) pin

void init_ADC() {
  ADMUX = MUX(0);       // setting data pin
  PPR |= 0b11111110;    // Disabling ADC power saving
  ADCSRA |= 0b11111111; // Enabling ADC conversation
}

unsigned short get_data() {
  unsigned short data = 0;
  data |= (ADCL << 8);
  data |= ADCH;
  return data;
}
