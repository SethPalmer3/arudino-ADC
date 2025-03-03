#ifndef ARDN_ADC
#define ARDN_ADC

void init_ADC(void);
void start_conversation(char, char);
unsigned short get_data(void);
char get_small_data(void);

#endif // !ARDN_ADC
