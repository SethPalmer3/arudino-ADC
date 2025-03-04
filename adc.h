#ifndef ARDN_ADC
#define ARDN_ADC

#include <stdint.h>
void init_ADC(void);
void start_conversation(char, char);
unsigned short get_data(void);
char get_small_data(uint8_t);

#endif // !ARDN_ADC
