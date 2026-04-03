#pragma once

#include "../types/kerneltypes.hpp"
#include "../vga/legacy/screen.hpp"
#include "../types/string.hpp"

//memory values
extern uint32_t usedMemory;
extern uint32_t freeMemory;
extern uint32_t totalMemory;

//heap values
extern uint32_t heapstart;
extern uint32_t heapsize;
extern uint32_t heapEND;

typedef struct listMemNode {
    uintptr_t address;
    uint16_t debug = 0xDEAD;
    uint32_t size;
    bool isFree;
    listMemNode* next;
    listMemNode* prev;
} listMemNode;


bool kmeminit(uint32_t memsize, uint32_t Bunit);