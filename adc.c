#include "adc.h"
#include "serial.h"
#include <avr/io.h>
#include <stdint.h>

#define MUX(pin) pin
#define MASK(place) ~(1 << place)
#define DISABLE_PIN(pin) ~(1 << pin)
#define ENABLE_PIN(pin) (1 << pin)
#define PRESCALE 0b100
#define F_CPU 16000000UL

void init_ADC() {
  PRR &= 0b11111110; // Disabling ADC power saving
  // ADCSRA = ENABLE_PIN(ADEN) | ENABLE_PIN(ADATE) |
  // PRESCALE; // Enabling ADC conversation and auto trigger
  ADCSRA = 0b10000111;
  ADMUX = 0b01000000;
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
char get_small_data(uint8_t adcx) {
  // ADMUX &= 0xf0;
  // ADMUX |= adcx;
  // ADCSRA |= ENABLE_PIN(ADSC);
  // while (ADCSRA & (1 << ADSC)) {
  //   serial_write(11, "Waiting...\n");
  // }
  // serial_write(5, "Done\n");
  // return ADC;

  ADCSRA |= ENABLE_PIN(ADSC);
  if ((1 << ADSC) & ADCSRA) {
    return ADC;
  }
  return 0;
}
