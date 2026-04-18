#pragma once

#include "../bin/io/input.hpp"
#include "../bin/vga/legacy/screen.hpp"
#include "../bin/types/string.hpp"
#include "../bin/mem/memB.hpp"

// foward delcarations
void hexdump(const void* data, size_t size, int width = 2);

enum Command {
    CMD_EXIT,
    CMD_IDENTIFY,
    CMD_CLEAR,
    CMD_HELLO,
    CMD_PRINT,
    CMD_MEMINFO,
<<<<<<< HEAD
    CMD_HEXDUMP,
=======
    CMD_HEAPDUMP,
>>>>>>> osfunny
    CMD_UNKNOWN
};

int exit(int type) {
    extern bool exitS;
    exitS = true;
    return type;
}

inline void printCommand() {                                                                           // TO BE MOVED LATER, AS THIS NEED TO BE WITH ITS FAMILY <3
    //strcmp(returnstringBuffer(5, ' '), "-n");
    if (strcmp(returnstringBuffer(5, '\0'), " ") == 0) return print("not enough args!\n");
    if (strcmp(returnstringBuffer(6, ' '), "-n") == 0) return print("nirs\n");
    print("error use of print function\n");
}

<<<<<<< HEAD
inline void hexdumpcommand() {                                                                           // TO BE MOVED LATER, AS THIS NEED TO BE WITH ITS FAMILY <3
    //strcmp(returnstringBuffer(5, ' '), "-n");
    if (strcmp(returnstringBuffer(5, '\0'), " ") == 0) return print("not enough args!\n");
    if (strcmp(returnstringBuffer(8, ' '), "-S") == 0) {
        int start = 0;
    }
    print("error use of hexdump function\n");
}
                                                                                        // will change this terrible system once file directories are existent, because then
inline void getmeminfo() {                                                              // i can base it off file name and decentralise this process but it works for now
    print("Memory Information:\n");
    inttochar(totalMemory); // Debug output of total memory in MB
    print(returnstringBuffer());
    print(" MB total.\n");
    inttochar(freeMemory/ Bsize::KB); // Debug output of free memory in KB
    print(returnstringBuffer());
    print(" KB free.\n");
    inttochar(usedMemory / Bsize::KB); // Debug output of used memory in KB
    print(returnstringBuffer());
    print(" KB used.\n");
=======
inline void getmeminfo() {
    print("Memory Information:\n   ");
    print(inttochar(totalMemory / Bsize::KB));
    print(" KB total\n   ");
    print(inttochar(freeMemory / Bsize::KB));
    print(" KB free.\n   ");
    print(inttochar((usedMemory) / Bsize::KB));
    print(" KB used\n");
>>>>>>> osfunny

    print("HEAP information:\n   ");
    print(inttochar(heapsize / Bsize::MB));
    print(" MB total\n   ");
    print(inttochar(heapstart / Bsize::KB));
    print(" KB free.\n   ");
    print(inttochar((heapEND) / Bsize::KB));
    print( " KB used\n");        
}

Command parsecommand(const char* input) {
    if (strcmp(input, "print") == 0) return CMD_PRINT;

    if (strcmp(input, "iden") == 0) return CMD_IDENTIFY;
    if (strcmp(input, "cls") == 0) return CMD_CLEAR;
    if (strcmp(input, "memi") == 0) return CMD_MEMINFO;
    if (strcmp(input, "heapdump") == 0) return CMD_HEAPDUMP;
    if (strcmp(input, "hello") == 0) return CMD_HELLO;
    if (strcmp(input, "hexdump") == 0) return CMD_HEXDUMP;
    if (strcmp(input, "exit") == 0) return CMD_EXIT;
    return CMD_UNKNOWN;
}

inline void commandCheck(const char* input) {
    switch(parsecommand(input)) {
        case CMD_IDENTIFY:
            print("you dont pay me enough!\n");
            break;
        case CMD_CLEAR:
            clear_screen();
            break;
        case CMD_PRINT:
            printCommand();
            break;
        case CMD_HELLO:
            print("HI THERE!\n");
            break;
        case CMD_MEMINFO:
            getmeminfo();
            break;
<<<<<<< HEAD
        case CMD_HEXDUMP:
            //hexdump((void*)0x7FFFFFF, 256); // Example: Dump the first 256 bytes of the heap
            hexdumpcommand();
=======
        case CMD_HEAPDUMP:
            heap_dump();
>>>>>>> osfunny
            break;
        case CMD_EXIT:
            exit(0);
            break;
        default:
            print("invalid command!\n");
    }
    bufferclear();
}