#ifndef ARDN_SERIAL
#define ARDN_SERIAL

int USB_serial_begin(unsigned long);
int USB_serial_write(int, char *);

int w2_serial_begin(unsigned long);
int w2_serial_write(int, char *);

#endif // !ARDN_SERIAL
