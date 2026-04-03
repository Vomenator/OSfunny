#include "memB.hpp"

#define KERNEL_LOWER_MAX 0x500000
#define INIT_STACK 16384 + 4        // magic number is to make sure it is aligned appropiately

uint32_t const MAX_MEM = ((128 * Bsize::MB));
uint32_t MEMbitmap[MAX_MEM / 32]; // Bitmap to track used/free memory blocks
uint32_t usedMemory = 0;
uint32_t freeMemory = 0;
uint32_t totalMemory = 0;               // this is used by other functions

//heap stuff
uint32_t heapstart  = 0;
uint32_t heapsize   = 0;


static listMemNode* memoryBlocksHead = NULL;
uint32_t heapEND = 0;

/*void setStack(uint32_t Stackstart) {
    __asm__ volatile(
        "mov esp, %0\n"   // Move the stack pointer to the new stack location
        "xor ebp, ebp\n"  // Clear the base pointer
        :
        : "r"(Stackstart)
    );
}*/

/*void setStackpointer(uint32_t Stackstart) {
    __asm__ volatile("movl %0, %%esp" : : "r"(Stackstart));
}*/

void memTRKalloc(uint32_t size) {
    freeMemory -= size;
    usedMemory += size;
}

static void kmem_set(uint32_t memindex) {                   // this gets the memory idex (ie, if its index 4 it will get the value, )
    MEMbitmap[memindex / 32] |= (1 << (memindex % 32));         // this sets the bit array at available spots, where each bit repersents 4KB
    //if (memindex/32 >= 1) setStackpointer(memindex/32);     // this sets the stack pointer to the new location, which is the index of the memory block, this is because the memory block is 4KB and each bit represents 4KB, so if its index 4 it will be 16KB, which is the same as 0x4000
}


bool kmeminit(uint32_t memsize, uint32_t Bunit) {
    freeMemory = memsize * Bunit;
    totalMemory = freeMemory;

    for (uint32_t i = 0; i < freeMemory / 32; i++) {
        MEMbitmap[i] = 0;
    }
    for (uint32_t i = 0; i < INIT_STACK / 32; i++) {
        kmem_set(i);
    }
    memTRKalloc(INIT_STACK);

    print("Memory management initialized.\n");
    inttochar(memsize); // Debug output of free memory in KB
    print(returnstringBuffer());
    print(" MB total.\n");
    inttochar(freeMemory/ Bsize::KB); // Debug output of free memory in KB
    print(returnstringBuffer());
    print(" KB free.\n");
    inttochar(usedMemory / Bsize::KB); // Debug output of used memory in KB
    print(returnstringBuffer());
    print(" KB used.\n");
    bufferclear();    

    heapstart = 0x100000; // Example starting address for the heap (1 MB)
    heapsize = (memsize * Bunit) - heapstart; // Size of the heap (total memory minus the starting address)
    // this marks the intial block as used
    listMemNode* initialBlock = new listMemNode;
    initialBlock->address = heapstart; // Example starting address (APPROX, 1MB)
    initialBlock->size = sizeof(listMemNode); // Size of the initial block
    initialBlock->isFree = false;
    initialBlock->next = NULL;
    initialBlock->prev = NULL;
    heapEND = heapstart + heapsize; // Set tail to the end of the memory region

    print("HEAP Memory initialized.\n");
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
    // Initialize memory management structures here
    // For example, set up a bitmap for tracking used/free memory blocks
    // or initialize a linked list of free memory blocks.

    return true; // Return true if initialization is successful
}