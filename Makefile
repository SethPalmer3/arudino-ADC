# Target: Upload the program
upload:
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing -c main.c
	avr-gcc -mmcu=atmega328p -Os -Wall -fno-strict-aliasing main.o -o main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:main.hex:i

# Clean the project
clean:
	rm -f *.o *.elf *.hex
