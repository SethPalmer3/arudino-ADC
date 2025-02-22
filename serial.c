#include "serial.h"
#include <avr/io.h>

int serial_begin();
int serial_write(int, char *);

Serial init_serial(int baud) {
  Serial s = {.baudrate = baud, .begin = serial_begin, .write = serial_write};
  return s;
}

int serial_begin() {
  unsigned long myubrr = 16000000UL / 16UL / baudrate - 1;
  UBRR0H = (unsigned char)(myubrr >> 8);
  UBRR0L = (unsigned char)(myubrr);
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
  return 1;
}

int serial_write(int len, char *data) {
  int i = 0;
  while (i++ < len) {
    while ((UCSR0A & (1 << UDRE0)) == 0)
      ;
    UDR0 = data;
  }
  return 0;
}
