#include "serial.h"
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000UL
#define MYUBRR(rate) (FOSC / 16UL / rate - 1)

int USB_serial_begin(unsigned long baudrate) {
  unsigned long myubrr = MYUBRR(baudrate);
  UBRR0H = (unsigned char)(myubrr >> 8);
  UBRR0L = (unsigned char)(myubrr);
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
  return 1;
}

int USB_serial_write(int len, char *data) {
  int i = 0;
  while (i < len) {
    while (!(UCSR0A & (1 << UDRE0))) {
    }
    UDR0 = data[i];
    // _delay_ms(1000);
    i++;
  }
  return 0;
}

int w2_serial_begin(unsigned long baudrate) {
  unsigned long myubrr = MYUBRR(baudrate);
  // Setting baud rate
  UBRR0H = (unsigned char)(myubrr >> 8);
  UBRR0L = (unsigned char)(myubrr);
  // Enabling transmitter and receiver
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  // Setting frame format: 8 data, 2 stop bit
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
  return 1;
}

int w2_serial_write(int len, char *data) { return USB_serial_write(len, data); }
