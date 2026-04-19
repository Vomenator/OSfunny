#include "newVGA.hpp"

static VBEModeInfo* vbe;

bool VGAINIT(VBEModeInfo* vbe1) {
    vbe = vbe1;
    //if (vbe->framebuffer_addr == 0) return false;
    return true;
}

void put_pixel(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    //uint8_t* fb = (uint8_t*)(uint32_t)vbe->framebuffer_addr;
    uint8_t* fb = (uint8_t*)vbe->physbase; // QEMU VBE framebuffer
    uint32_t bytes_per_pixel = 4;
    uint32_t pitch = vbe->pitch;
    uint32_t offset = y * pitch + x * bytes_per_pixel;
    
    fb[offset]     = blue;  // blue
    fb[offset + 1] = green; // green
    fb[offset + 2] = red;   // red
    fb[offset + 3] = alpha; // alpha
}


int colourscreen(char red, char green, char blue) {
    // fill entire screen with specified color
    for (uint32_t y = 0; y < vbe->Yres; y++) {
        for (uint32_t x = 0; x < vbe->Xres; x++) {
            put_pixel(x, y, red, green, blue);
        }
    }
    return 0;
}