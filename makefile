.PHONY: run finalise_compile

CC  = g++
LD  = ld
ASM = nasm
OBCY = objcopy

#CFLAGS = -ffreestanding -fno-pic -fno-exceptions -fno-rtti -fno-stack-protector -O2 -m32
CFLAGS = -ffreestanding -fno-pic -fno-exceptions -fno-rtti -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -O2 -m32
FCFLAGS = -ffreestanding -fno-pic -fno-exceptions -fno-rtti -fno-stack-protector -O2 -m32 -fpermissive
OBJFLAGS = -O elf32-i386

BIN_DIR = bin/
BOOTF = bin/boot/
IOF = bin/io/
TYPESF = bin/types/
VGAF = bin/vga/legacy/
VGANEWF = bin/vga/new/
MEMF = bin/mem/

COMMANDSF = bin/commands/

OBJ_DIR = out/obj/
PROGF = programs/

GRUBBY = ./GRUBBY/
GRUBGRUB = GRUBBY/boot/grub/

run:kernel.bin grub
	@echo "Done!"
	@echo "You can now run the kernel with 'make runqemu' or 'qemu-system-i386 -kernel kernel.bin -d guest_errors -D qemu.log'"

grub: 
	@echo "Creating GRUB bootable ISO..."
	grub-mkrescue -o output.iso $(GRUBBY)

#elfontheshelf_conversion: $(OBJ_DIR)kernel.bin grub
#	$(OBCY) $(OBJFLAGS) $(OBJ_DIR)kernel.bin $(GRUBBY)boot/kernel.elf

kernel.bin: $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)newVGA.o $(OBJ_DIR)VBEkernelcharacters.o $(OBJ_DIR)VBEkernelspecial.o $(OBJ_DIR)memB.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)hexdump.o
	$(LD) -m elf_i386 -T linker.ld -o $(GRUBBY)boot/kernel.elf $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)newVGA.o $(OBJ_DIR)VBEkernelcharacters.o $(OBJ_DIR)VBEkernelspecial.o $(OBJ_DIR)memB.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)hexdump.o
	@echo "Kernel compiled successfully!"

#ernel.bin: $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)newVGA.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)memB.o $(OBJ_DIR)hexdump.o $(OBJ_DIR)VBEkernelcharacters.o $(OBJ_DIR)VBEkernelspecial.o
#	$(LD) -m elf_i386 -T linker.ld -o $(GRUBBY)boot/kernel.elf $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)commandPrompt.o $(OBJ_DIR)newVGA.o $(OBJ_DIR)input.o $(OBJ_DIR)string.o $(OBJ_DIR)memB.o $(OBJ_DIR)hexdump.o $(OBJ_DIR)VBEkernelcharacters.o $(OBJ_DIR)VBEkernelspecial.o
#	@echo "Kernel compiled successfully!"

$(OBJ_DIR)boot.o: $(BOOTF)boot.asm
	$(ASM) -f elf32 $(BOOTF)boot.asm -o $(OBJ_DIR)boot.o


$(OBJ_DIR)screen.o: $(VGAF)screen.cpp
	$(CC) $(CFLAGS) -c $(VGAF)screen.cpp -o $(OBJ_DIR)screen.o

$(OBJ_DIR)newVGA.o: $(VGANEWF)newVGA.cpp
	$(CC) $(CFLAGS) -c $(VGANEWF)newVGA.cpp -o $(OBJ_DIR)newVGA.o

$(OBJ_DIR)VBEkernelcharacters.o: $(VGANEWF)VBEkernelcharacters.cpp
	$(CC) $(CFLAGS) -c $(VGANEWF)VBEkernelcharacters.cpp -o $(OBJ_DIR)VBEkernelcharacters.o

$(OBJ_DIR)VBEkernelspecial.o: $(VGANEWF)VBEkernelspecial.cpp
	$(CC) $(CFLAGS) -c $(VGANEWF)VBEkernelspecial.cpp -o $(OBJ_DIR)VBEkernelspecial.o


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

$(OBJ_DIR)hexdump.o: $(COMMANDSF)hexdump.cpp
	$(CC) $(CFLAGS) -c $(COMMANDSF)hexdump.cpp -o $(OBJ_DIR)hexdump.o

runqemu:
	qemu-system-i386 -cdrom output.iso -vga std -d guest_errors -D qemu.log

runqemuB:
	qemu-system-i386 -cdrom output.iso -vga std -d guest_errors,int -D qemu.log

clean:
	rm -f $(OBJ_DIR)*.o $(OBJ_DIR)*.bin
	rm -f output.iso
	rm -f $(GRUBBY)boot/kernel.elf