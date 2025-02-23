#include "adc.h"
#include "serial.h"

int main(void) {
  Serial s = init_serial(9600);
  s.begin();
  start_conversation(PRADC, ADSC);
  unsigned short data = get_data();
  s.write(2, (char *)&data);
}
