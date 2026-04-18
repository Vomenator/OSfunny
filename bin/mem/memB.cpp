#include "memB.hpp"

#define KERNEL_LOWER_MAX 0x500000
#define INIT_STACK 16384 + 4        // magic number is to make sure it is aligned appropiately

uint32_t const MAX_MEM = ((128 * Bsize::MB));
uint32_t MEMbitmap[MAX_MEM / 32]; // Bitmap to track used/free memory blocks

//trackers
uint32_t usedMemory = 0;
uint32_t freeMemory = 0;
uint32_t totalMemory = 0;               // this is used by other functions

//heap stuff
uint32_t heapstart  = 0;
uint32_t heapsize   = 0;
uint32_t previousAddr = 0;


static HeapMemNode* memoryBlocksHead = NULL;
uint32_t heapEND = 0;


// this sets the stack pointer

/*void setStackpointer(uint32_t Stackstart) {
    __asm__ volatile("movl %0, %%esp" : : "r"(Stackstart));
}*/

// this sets the used memory crap
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

    print("Memory Management Intialised. \n   ");
    print(inttochar(memsize));
    print(" MB total\n   ");
    print(inttochar(freeMemory / Bsize::MB));
    print(" KB free.\n   ");
    print(inttochar((usedMemory) / Bsize::KB));
    print( " KB used\n");

    // this sets the actual table which contains the addresses to particular "programs"
    //heapstart = 0x7f00000;                    // Example starting address for the heap (1 MB) out of 1280000
    heapstart = 0x100000;
    heapsize = (memsize * Bunit) - heapstart; // Size of the heap (total memory minus the starting address)

    //setStackpointer(heapstart);
    HeapMemNode* memoryBlocksHead = new HeapMemNode;
    memoryBlocksHead->address = heapstart;        // Example starting address (APPROX, 127MB)
    memoryBlocksHead->iden = 0;                   //block identity 
    memoryBlocksHead->size = sizeof(HeapMemNode); // Size of the initial block
    memoryBlocksHead->isFree = false;
    memoryBlocksHead->next = NULL;
    memoryBlocksHead->prev = NULL;
    heapEND = heapstart + sizeof(memoryBlocksHead);           // Set tail to the end of the memory region
    
    print( "\nHEAP Memory Intialised.\n   ");
    print(inttochar(heapsize / Bsize::KB));
    print( " KB available for heap \n");
    print( " heap is between: ");
    print(inttochar(heapstart / Bsize::KB));
    print( " KB and ");
    print(inttochar(heapEND /Bsize::KB));
    print( " KB used ");

    // Initialize memory management structures here
    // For example, set up a bitmap for tracking used/free memory blocks
    // or initialize a linked list of free memory blocks.
    return true; // Return true if initialization is successful
}

void* kmemalloc(uint32_t size, uint32_t len) {
    size *= len;
    //print(inttochar(size));
    if (!size) print("\n**warning**: invalid memory size\n"); return NULL;
    size = (size+3) & ~3;
    HeapMemNode* init = memoryBlocksHead;

    while (init) {
        if(init->debug != 0xDEAD) kernel_panic(3);

        if(init->isFree == true && init->size >= size) {
            if (init->size >= size + sizeof(HeapMemNode) + 4) {
                HeapMemNode* new_memnode = (HeapMemNode*)((uint8_t*)init + sizeof(HeapMemNode) + size);
            
                new_memnode->size = init->size - sizeof(HeapMemNode);
                new_memnode->isFree = false;
                new_memnode->next = init->next;
                new_memnode->prev = init;


                if(init->next) init ->next->prev = new_memnode;
                init->size;
            }
            init->isFree = false;
            return (void*)((uint8_t*)init + sizeof(HeapMemNode));
        }
        init = init->next;
    }
    print("\n\n**WARNING** RAN OUT OF MEMORY\n\n");
    return NULL;
}


void heap_dump() {
    print("[HEAP] Dump:\n");
    HeapMemNode* dump = memoryBlocksHead;
    int i = 0;
    while (dump) {
        print("  addr=");
        print(inttochar((uint32_t)dump->address));
        print("  size=");
        print(inttochar(dump->size));
        print((dump->isFree ? "FREE" : "USED"));
        i++;
        dump = dump->next;
    }
}

/*class __HEAP {
    public:
        inline HeapMemNode heap_create(char name[4], uint32_t size) {
            HeapMemNode* h;
            return;
        }
};*/