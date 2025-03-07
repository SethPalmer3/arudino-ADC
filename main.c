#include "adc.h"
#include "serial.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define MUX(pin) pin
#define F_CPU 16000000UL

int main(void) {
  w2_serial_begin(9600);
  _delay_ms(16000);
  char str[4];

  USB_serial_write(12, "Starting...\n");
  init_ADC();

  while (1) {
    char data = get_small_data(0);
    sprintf(str, "%u", data);
    USB_serial_write(4, str);
    USB_serial_write(2, "\r\n");
    _delay_ms(1000);
  }
}
