#pragma once

#include "../bin/io/input.hpp"
#include "../bin/vga/legacy/screen.hpp"
#include "../bin/types/string.hpp"
#include "../bin/mem/memB.hpp"


enum Command {
    CMD_EXIT,
    CMD_IDENTIFY,
    CMD_CLEAR,
    CMD_HELLO,
    CMD_PRINT,
    CMD_MEMINFO,
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

inline void getmeminfo() {
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

    print("HEAP information:\n");
    inttochar(heapsize / Bsize::KB); // Debug output of heap size in KB
    print(returnstringBuffer());
    print(" KB available for heap. \n");
    print( "heap is between: ");
    inttochar(heapstart/ Bsize::KB); // Debug output of heap start address in KB
    print(returnstringBuffer());
    print(" KB and ");
    bufferclear();
    inttochar(heapEND / Bsize::KB); // Debug output of heap end address in KB
    print(returnstringBuffer());
    print(" KB.\n");      
}

Command parsecommand(const char* input) {
    if (strcmp(input, "print") == 0) return CMD_PRINT;
    if (strcmp(input, "iden") == 0) return CMD_IDENTIFY;
    if (strcmp(input, "cls") == 0) return CMD_CLEAR;
    if (strcmp(input, "memi") == 0) return CMD_MEMINFO;
    if (strcmp(input, "hello") == 0) return CMD_HELLO;
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
        case CMD_EXIT:
            exit(0);
            break;
        default:
            print("invalid command!\n");
    }
    bufferclear();
}