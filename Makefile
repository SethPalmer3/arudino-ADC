# Target: Upload the program
upload:
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing -c adc.c -o adc.o
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing -c serial.c -o serial.o
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing -c main.c -o main.o
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing main.o serial.o adc.o -o main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:main.hex:i

# Clean the project
clean:
	rm -f *.o *.elf *.hex
