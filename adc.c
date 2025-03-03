#include "adc.h"
#include "serial.h"
#include <avr/io.h>

#define MUX(pin) pin
#define DISABLE_PIN(pin) ~(1 << pin)
#define ENABLE_PIN(pin) (1 << pin)
#define PRESCALE 0b0
#define F_CPU 16000000UL

void init_ADC() {
  ADMUX = MUX(0);    // setting data pin
  PRR &= 0b11111110; // Disabling ADC power saving
  ADCSRA = ENABLE_PIN(ADEN) | ENABLE_PIN(ADATE) |
           PRESCALE; // Enabling ADC conversation and auto trigger
}

unsigned short get_data() {
  ADCSRA |= ENABLE_PIN(ADSC);
  while (ADCSRA & (1 << ADSC))
    ;
  unsigned short data = 0;
  data |= (ADCH << 8);
  data |= ADCL;
  return data;
}
char get_small_data() {
  ADCSRA |= ENABLE_PIN(ADSC);
  while (ADCSRA & (1 << ADSC)) {
    serial_write(11, "Waiting...\n");
  }
  serial_write(5, "Done\n");
  return ADCL;
}
