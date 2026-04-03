.PHONY: run finalise_compile

CC  = g++
LD  = ld
ASM = nasm
OBCY = objcopy

CFLAGS = -ffreestanding -fno-exceptions -fno-rtti -fno-stack-protector -O2 -m32
OBJFLAGS = -O elf32-i386

BIN_DIR = bin/
BOOTF = bin/boot/
IOF = bin/io/
TYPESF = bin/types/
VGAF = bin/vga/legacy/
MEMF = bin/mem/

OBJ_DIR = out/obj/
PROGF = programs/

run:kernel.bin finalise_compile
	@echo "Done!"
	@echo "You can now run the kernel with 'make runqemu' or 'qemu-system-i386 -kernel kernel.bin -d guest_errors -D qemu.log'"

finalise_compile: $(OBJ_DIR)kernel.bin
	$(OBCY) $(OBJFLAGS) $(OBJ_DIR)kernel.bin kernel.elf

kernel.bin: $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)screen.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)memB.o
	$(LD) -m i386pe -T linker.ld -o $(OBJ_DIR)kernel.bin $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)screen.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)memB.o
	@echo "Kernel compiled successfully!"

$(OBJ_DIR)boot.o: $(BOOTF)boot.asm
	$(ASM) -f elf32 $(BOOTF)boot.asm -o $(OBJ_DIR)boot.o

$(OBJ_DIR)screen.o: $(VGAF)screen.cpp
	$(CC) $(CFLAGS) -c $(VGAF)screen.cpp -o $(OBJ_DIR)screen.o

$(OBJ_DIR)input.o: $(IOF)input.cpp
	$(CC) $(CFLAGS) -c $(IOF)input.cpp -o $(OBJ_DIR)input.o

$(OBJ_DIR)kernel.o: $(BOOTF)kernel.cpp
	$(CC) $(CFLAGS) -c $(BOOTF)kernel.cpp -o $(OBJ_DIR)kernel.o

$(OBJ_DIR)commandPrompt.o: $(PROGF)commandPrompt.cpp
	$(CC) $(CFLAGS) -c $(PROGF)commandPrompt.cpp -o $(OBJ_DIR)commandPrompt.o

$(OBJ_DIR)string.o: $(TYPESF)string.cpp
	$(CC) $(CFLAGS) -c $(TYPESF)string.cpp -o $(OBJ_DIR)string.o

$(OBJ_DIR)memB.o: $(MEMF)memB.cpp
	$(CC) $(CFLAGS) -c $(MEMF)memB.cpp -o $(OBJ_DIR)memB.o

runqemu:
	qemu-system-i386 -kernel kernel.elf -d guest_errors -D qemu.log

clean:
	rm -f *.o *.bin