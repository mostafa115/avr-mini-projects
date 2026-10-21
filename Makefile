MCU     ?= atmega128
F_CPU   ?= 16000000UL

CC      := avr-gcc
OBJCOPY := avr-objcopy
SIZE    := avr-size
CFLAGS  := -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -std=gnu99 -Wall

APPS    := calculator countdown-timer motor-dashboard ping-pong

.PHONY: all clean
.SECONDARY:

all: $(APPS:%=build/%.hex)
	$(SIZE) $(APPS:%=build/%.elf)

.SECONDEXPANSION:
build/%.elf: $$(wildcard $$*/*.c) $$(wildcard $$*/*.h)
	@mkdir -p build
	$(CC) $(CFLAGS) -I$* $(filter %.c,$^) -o $@

build/%.hex: build/%.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -rf build
