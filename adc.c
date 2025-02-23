#include "adc.h"

void start_conversation(char power_redc, char adc_conv) {
  power_redc = 0;
  adc_conv = 1;
}

unsigned short get_data() {
  unsigned short data = 0;
  data |= (ADCL << 8);
  data |= ADCH;
  return data;
}
