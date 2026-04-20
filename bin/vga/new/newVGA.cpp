#include "newVGA.hpp"

uint8_t SCREENPADDINGx = 8;
uint8_t SCREENPADDINGy = 2;

static VBEModeInfo* vbe;

uint32_t kernel::print::x_cursor = 0, kernel::print::y_cursor = 0;

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

bool kernel::print::charprintmatrix(char ascii, uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    switch (ascii) {
        case 'A': case 'a': kernel::print::kcharacterA(x, y, red, green, blue, alpha); return true;
        case 'B': case 'b': kernel::print::kcharacterB(x, y, red, green, blue, alpha); return true;
        case 'C': case 'c': kernel::print::kcharacterC(x, y, red, green, blue, alpha); return true;
        case 'D': case 'd': kernel::print::kcharacterD(x, y, red, green, blue, alpha); return true;
        case 'E': case 'e': kernel::print::kcharacterE(x, y, red, green, blue, alpha); return true;
        case 'F': case 'f': kernel::print::kcharacterF(x, y, red, green, blue, alpha); return true;
        case 'G': case 'g': kernel::print::kcharacterG(x, y, red, green, blue, alpha); return true;
        case 'H': case 'h': kernel::print::kcharacterH(x, y, red, green, blue, alpha); return true;
        case 'I': case 'i': kernel::print::kcharacterI(x, y, red, green, blue, alpha); return true;
        case 'J': case 'j': kernel::print::kcharacterJ(x, y, red, green, blue, alpha); return true;
        case 'K': case 'k': kernel::print::kcharacterK(x, y, red, green, blue, alpha); return true;
        case 'L': case 'l': kernel::print::kcharacterL(x, y, red, green, blue, alpha); return true;
        case 'M': case 'm': kernel::print::kcharacterM(x, y, red, green, blue, alpha); return true;
        case 'N': case 'n': kernel::print::kcharacterN(x, y, red, green, blue, alpha); return true;
        case 'O': case 'o': kernel::print::kcharacterO(x, y, red, green, blue, alpha); return true;
        case 'P': case 'p': kernel::print::kcharacterP(x, y, red, green, blue, alpha); return true;
        case 'Q': case 'q': kernel::print::kcharacterQ(x, y, red, green, blue, alpha); return true;
        case 'R': case 'r': kernel::print::kcharacterR(x, y, red, green, blue, alpha); return true;
        case 'S': case 's': kernel::print::kcharacterS(x, y, red, green, blue, alpha); return true;
        case 'T': case 't': kernel::print::kcharacterT(x, y, red, green, blue, alpha); kernel::print::x_cursor++; return true;
        case 'U': case 'u': kernel::print::kcharacterU(x, y, red, green, blue, alpha); kernel::print::x_cursor++; return true;
        case 'V': case 'v': kernel::print::kcharacterV(x, y, red, green, blue, alpha); return true;
        case 'W': case 'w': kernel::print::kcharacterW(x, y, red, green, blue, alpha); return true;
        case 'X': case 'x': kernel::print::kcharacterX(x, y, red, green, blue, alpha); return true;
        case 'Y': case 'y': kernel::print::kcharacterY(x, y, red, green, blue, alpha); return true;
        case 'Z': case 'z': kernel::print::kcharacterZ(x, y, red, green, blue, alpha); return true;
        case '0': kernel::print::kcharacter0(x, y, red, green, blue, alpha); return true;
        case '1': kernel::print::kcharacter1(x, y, red, green, blue, alpha); return true;
        case '2': kernel::print::kcharacter2(x, y, red, green, blue, alpha); return true;
        case '3': kernel::print::kcharacter3(x, y, red, green, blue, alpha); return true;
        case '4': kernel::print::kcharacter4(x, y, red, green, blue, alpha); return true;
        case '5': kernel::print::kcharacter5(x, y, red, green, blue, alpha); return true;
        case '6': kernel::print::kcharacter6(x, y, red, green, blue, alpha); return true;
        case '7': kernel::print::kcharacter7(x, y, red, green, blue, alpha); return true;
        case '8': kernel::print::kcharacter8(x, y, red, green, blue, alpha); return true;
        case '9': kernel::print::kcharacter9(x, y, red, green, blue, alpha); return true;

        case '*': kernel::print::kcharacterAstrisk(x, y, red, green, blue, alpha); return true;
        case '!': kernel::print::kcharacterEXCLAMATION(x, y, red, green, blue, alpha); return true;
        case ' ': return true;

        //ascii return sequences               8 is char size 1 is offset 
        case '\n': kernel::print::y_cursor += (8 + 2); kernel::print::x_cursor = SCREENPADDINGx; break;
        case '\r':
        case '\t':
        case '\0': break;

        default: break; // ignore unsupported characters
    }
    return false;
}

void kernel::printM(const char* str, uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    if (kernel::print::x_cursor <= x) kernel::print::x_cursor = x; // checks if the input is less than x to prevent overlap so if its already more it forgets about it type shit
    if (kernel::print::y_cursor <= y * 8) kernel::print::y_cursor = y * 8; // Assuming 8 pixels height for each character
    if (kernel::print::x_cursor < SCREENPADDINGx) kernel::print::x_cursor = SCREENPADDINGx; // Ensure x_cursor does not go below padding
    if (kernel::print::y_cursor < SCREENPADDINGy) kernel::print::y_cursor = SCREENPADDINGy; // Ensure y_cursor does not go below padding

    int i = 0;
    while (str[i] != '\0') {
        char currentchar = str[i];
        if (kernel::print::charprintmatrix(currentchar, kernel::print::x_cursor, kernel::print::y_cursor, red, green, blue, alpha) == true) {
            kernel::print::x_cursor += 8; // Move to the next character position (assuming 8 pixels wide)
        }
        i++;
    }
}

void kernel::print(const char* str, colour col) {
    if (kernel::print::x_cursor < SCREENPADDINGx) kernel::print::x_cursor = SCREENPADDINGx; // Ensure x_cursor does not go below padding
    if (kernel::print::y_cursor < SCREENPADDINGy) kernel::print::y_cursor = SCREENPADDINGy; // Ensure y_cursor does not go below padding
    
    int i = 0;
    while (str[i] != '\0') {
        char currentchar = str[i];
        if (kernel::print::charprintmatrix(currentchar, kernel::print::x_cursor, kernel::print::y_cursor, col.red, col.green, col.blue, col.alpha) == true) {
            kernel::print::x_cursor += 8; // Move to the next character position (assuming 8 pixels wide)
        }
        i++;
    }
}