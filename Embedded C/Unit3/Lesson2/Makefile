#copyright : Mai Mousa

CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g 
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=lab1

all: $(Project_name).bin
	@echo "Build is finished ..."  
	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c  $(INCS)  $< -o $@

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@ 

$(Project_name).elf: $(OBJ) $(AsOBJ) 
	$(CC)ld.exe  -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=outMap.map 


$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin

clean_all:
	rm *.o *.elf *.bin 


