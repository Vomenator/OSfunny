CC  = g++
LD  = ld
ASM = nasm
CFLAGS = -ffreestanding -fno-exceptions -fno-rtti -fno-stack-protector -O2 -m32
OBJ_DIR = out/obj/
BIN_DIR = out/

kernel.bin: $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)command.o $(OBJ_DIR)screen.o $(OBJ_DIR)io.o $(OBJ_DIR)string.o
	$(LD) -m i386pe -T linker.ld -o $(BIN_DIR)kernel.bin $(OBJ_DIR)boot.o $(OBJ_DIR)kernel.o $(OBJ_DIR)command.o $(OBJ_DIR)screen.o $(OBJ_DIR)io.o $(OBJ_DIR)string.o

$(OBJ_DIR)boot.o: boot.asm
	$(ASM) -f elf32 boot.asm -o $(OBJ_DIR)boot.o

$(OBJ_DIR)screen.o: screen.cpp
	$(CC) $(CFLAGS) -c screen.cpp -o $(OBJ_DIR)screen.o

$(OBJ_DIR)io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp -o $(OBJ_DIR)io.o

$(OBJ_DIR)kernel.o: kernel.cpp
	$(CC) $(CFLAGS) -c kernel.cpp -o $(OBJ_DIR)kernel.o

$(OBJ_DIR)command.o: command.cpp
	$(CC) $(CFLAGS) -c command.cpp -o $(OBJ_DIR)command.o

$(OBJ_DIR)string.o: string.cpp
	$(CC) $(CFLAGS) -c string.cpp -o $(OBJ_DIR)string.o

run: kernel.bin
	objcopy -O elf32-i386 kernel.bin kernel.elf

clean:
	rm -f *.o *.bin