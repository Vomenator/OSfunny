#include "../vga/legacy/screen.hpp"
#include "../types/kerneltypes.hpp"
#include "../mem/memB.hpp"

// GDT entry structure
struct GDTEntry {                               
    unsigned short limit_low;           //setting values 2 BYTES
    unsigned short base_low;            // 2 BYTES
    unsigned char  base_mid;            // 1 BYTE
    unsigned char  access;              // 1 BYTE
    unsigned char  granularity;         // 1 BYTE
    unsigned char  base_high;           // 1 BYTE       8 BYTES TOTAL
} __attribute__((packed));                          // this tells the compiler to leave this structure alone so it can assumidly not get lost and be accessed easily and as is

struct GDTPointer {
    uint16_t limit;                     // 16 bit int = 2 bytes
    uintptr_t   base;                   // 32 bits or 4 bytes
} __attribute__((packed));

GDTEntry gdt[3];                        // initialises the structures
GDTPointer gdtp;

void gdt_set_entry(int i, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran) {    // this sets the table, ie, i acts as an index
    gdt[i].base_low    = base & 0xFFFF;         // this ignores the left side of the 32 bit system effectively restricting it to using 16 bits using the limit
    gdt[i].base_mid    = (base >> 16) & 0xFF;   // shifts it over by 16 bits in which now it will get the last 8 bits, i.e if its 'ab 12 cc dd' it would then be '00 00 ab 12'
    gdt[i].base_high   = (base >> 24) & 0xFF;   // shifts it but this time by 3 bytes getting the top byte, in which it will read it
    gdt[i].limit_low   = limit & 0xFFFF;       // this once again sets it to the last 16 bits
    gdt[i].granularity = ((limit >> 16) & 0x0F) | (gran & 0xF0); // shifts it by 16 geting 16-19 bits (getting top half(bottom half)) OR it compares the gran to a series of flags, OR memory locations which makes it do certain things!!!! ie this gets the flags alone, since the flags takes 2 bytes
    gdt[i].access      = access;                                // this determines what can access it, if it has the same access code it will be able to access the other memory of the same code, like an pass
}

extern "C" void gdt_flush(unsigned int);  // in boot.asm

void init_gdt() {
    gdtp.limit = (sizeof(GDTEntry) * 3) - 1;  // 8 bytes * 3 = 24-1 = 23bytes, but it can store up to 65536 -1 bits or 8192 bytes, finally 8 bytes per entry 1024 entries
    gdtp.base  = (uint32_t)&gdt;
    gdt_set_entry(0, 0, 0,          0,    0);    // null
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // code , the limit is the segmentation for what its allowed to access
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // data
    gdt_flush((uint32_t)&gdtp);
}

extern "C" void kmain() {
    clear_screen();
    print("MyOS kernel booted!\n");
    init_gdt();
    print("GDT initialized.\n");
    print("\n");
    tempColourOutput(8);
    kmeminit(3, Bsize::MB); // Example: Initialize memory management with 128 MB starting at 3 MB

    // initialises the commandprompt function
    commandprompt();
    for(;;) __asm__ volatile("hlt");
    return;
}