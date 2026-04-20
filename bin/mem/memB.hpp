#pragma once

#include "../types/kerneltypes.hpp"
#include "../types/string.hpp"
#include "../vga/new/newVGA.hpp"

//memory values
extern uint32_t usedMemory;
extern uint32_t freeMemory;
extern uint32_t totalMemory;

//heap values
extern uint32_t heapstart;
extern uint32_t heapsize;
extern uint32_t heapEND;

typedef struct HeapMemNode {
    uintptr_t address;
    uint32_t iden;
    uint32_t debug = 0xDEAD;
    uint32_t size;
    bool isFree;
    HeapMemNode* next;
    HeapMemNode* prev;
} HeapMemNode;


bool kmeminit(uint32_t memsize, uint32_t Bunit);
void* kmemalloc(uint32_t size, uint32_t len);
void heap_dump();