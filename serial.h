#ifndef ARDN_SERIAL
#define ARDN_SERIAL

int serial_begin(unsigned long);
int serial_write(int, char *);

#endif // !ARDN_SERIAL
