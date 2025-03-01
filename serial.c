#include "serial.h"
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000UL
#define MYUBRR(rate) (FOSC / 16UL / rate - 1)

int serial_begin(unsigned long baudrate) {
  unsigned long myubrr = MYUBRR(baudrate);
  UBRR0H = (unsigned char)(myubrr >> 8);
  UBRR0L = (unsigned char)(myubrr);
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
  return 1;
}

int serial_write(int len, char *data) {
  int i = 0;
  while (i < len) {
    while (!(UCSR0A & (1 << UDRE0))) {
    }
    UDR0 = data[i];
    _delay_ms(1000);
    i++;
  }
  return 0;
}
