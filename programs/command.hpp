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
    print("Memory Information:\n   ");
    print(inttochar(totalMemory / Bsize::KB));
    print(" KB total\n   ");
    print(inttochar(freeMemory / Bsize::KB));
    print(" KB free.\n   ");
    print(inttochar((usedMemory) / Bsize::KB));
    print(" KB used\n");

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