//#include "../vga/legacy/screen.hpp"
#include "../types/kerneltypes.hpp"
//#include "../mem/memB.hpp"
#include "../vga/new/newVGA.hpp"


//uint16_t* fb;

uint8_t SCREENPADDING = 8; // this is the padding between the edge of the screen and the start of the text, in pixels

void kernel_panic(uint32_t error) {
    //clear_screen();
    print("********************", SCREENPADDING, 5, 0xFF, 0x00, 0x00, 0x00); // red color
    print("****KERNEL PANIC****", SCREENPADDING, 6, 0xFF, 0x00, 0x00, 0x00);
    print("********************", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);

    switch(error) {
        case 0:
            print("**UKNOWN ERROR**", SCREENPADDING, 9, 0xFF, 0x00, 0x00, 0x00);
            break;
        case 1:
            print("**GDT INITALISATION ERROR**", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);
            break;
        case 2:
            print("**MEMORY INITALISATION ERROR**", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);
            break;
        case 3:
            print("**HEAP ALLOCATION FAULT**", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);
            break;
        case 4:
            print("**VGA MODE ERROR**", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);
            break;
        case 5:
            print("**framebufferflag not set**", SCREENPADDING, 7, 0xFF, 0x00, 0x00, 0x00);
            break;
    }
    for(;;) __asm__ volatile("hlt");
    return;
} 

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

extern "C" void _gdt_flush(unsigned int);  // in boot.asm

bool init_gdt() {
    gdtp.limit = (sizeof(GDTEntry) * 3) - 1;  // 8 bytes * 3 = 24-1 = 23bytes, but it can store up to 65536 -1 bits or 8192 bytes, finally 8 bytes per entry 1024 entries
    gdtp.base  = (uint32_t)&gdt;
    gdt_set_entry(0, 0, 0,          0,    0);    // null
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // code , the limit is the segmentation for what its allowed to access
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // data
    _gdt_flush((uint32_t)&gdtp);
    return true;
}

extern "C" void kmain(multiboot_info* mb) {
    //if (mb->framebuffer_addr == 0) for(;;);
    VBEModeInfo* vbe = (VBEModeInfo*)mb->vbe_mode_info;
    VGAINIT(vbe);
    //colourscreen(0, 0, 255); // blue screen
    //put_pixel(100, 100, 0xFF, 0x00, 0x00); // red pixel at 100,100
    //kcharacterA(100, 100, 0xFF, 0xFF, 0xFF, 0x00); // white 'A' at 100,100 also 0x00 was added cuz intelisense is smoking something
    //kernel::print::characterTest(100, 100, 0xFF, 0xFF, 0xFF, 0x00);
    print("MyOS kernel booted!", SCREENPADDING, 2, 0xFF, 0xFF, 0xFF, 0x00);
    kernel_panic(0);
    //kcharacterAstrisk(212+100, 100, 0xFF, 0xFF, 0xFF, 0x00);
    //kcharacterA(101, 100, 0xFF, 0xFF, 0xFF, 0x00);
    //drawline(50, 50, 0xFF, 0x00, 0x00, 0x00); // red line from (50,50) to (200,200)
    //print("MyOS kernel booted!\n");
    //if (!init_gdt());// kernel_panic(1);
    //print("GDT initialized.\n");
    //print("\n");
    //tempColourOutput(8);
    //if(!kmeminit(128, Bsize::MB)) kernel_panic(2); // Example: Initialize memory management with 128 MB
    //if(kmemalloc(100, 1))
    // initialises the commandprompt function
    //commandprompt();
    for(;;) __asm__ volatile("hlt");
    return;
}