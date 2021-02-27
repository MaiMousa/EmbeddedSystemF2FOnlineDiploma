# Makefile
# Mai Mousa
# Unit2_Lesson3_Lab2

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=CortexM3_ToggleLED

all: $(Project_name).bin
	@echo "Build is finished ..."  

	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -mthumb -c  $(INCS)  $< -o $@

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@ 

$(Project_name).elf: $(OBJ) $(AsOBJ) 
	$(CC)ld.exe  -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=$(Project_name).Map 


$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin

clean_all:
	rm *.o *.elf *.bin 


