#include "screen.hpp"

volatile unsigned short* vga = (volatile unsigned short*)0xB8000;       //vga memory location, this is pretty much setting the first byte (end location) SECOND CONTAINING COLOR

int getcursor(){
    return cursor;
}

//check
void clear_screen() {
    for (int i = 0; i < 80 * 25; i++)                                           // for 2000 pixels
        vga[i] = 0x07; // space, light gray on black, assimidly a color hex   // sets them to gray on black
    cursor = 0;                                                                 // cursor reset to 0, redundancy
}


//check
void putchar(char c) {
    const unsigned short WHITE_ON_BLACK = 0x0F00;                               // sets color hex which is white on black shows 16 bit last 2 bits need to be 00
    if (c == '\n') {
        cursor = ((cursor / 80) + 1) * 80;                                      // this moves to the new line using the set constraints of screen
    } 
    else {
        //vga[cursor++] = WHITE_ON_BLACK | (unsigned char)c;                      // prints at cursor white on black character OR unsigned character
        vga[cursor++] = WHITE_ON_BLACK + (unsigned char)c;                        // adds the two values together amounting to two bites which changes the screen to add the characters
    }
}

void putint(uint16_t num) {
    // to be changed will need table in order to sort the hex values out so it does not print out a traditional hex value, but an array of them otherwise will get unexpected results
    // need bit manipulation
}

/*void print(const char* str ...) {                   // this gathers the string using a character pointer and making it constant
    __builtin_va_list args;
    __builtin_va_start(args, str);
    for (int i; i <= sizeof(*str); i++) {
        if (*str == '%')
        switch(*str++) {
            case 'd':
            uint32_t c = __builtin_va_arg(args, uint32_t);

            break;
        }
        putchar(*str);
        //if (*str == ' ' || *str == '\n') *str++;
    }
    __builtin_va_end(args);
}*/

void print(const char* str) {
    while(*str) putchar(*str++);
}

void funnycolour(unsigned char colour, int Cblock) {;                    // last bits need to be 00 for data to be parsed correctly
        const unsigned char SPACE = 0x20;
        unsigned short block = (colour << 8) + SPACE;
        int i = 0;
        
    while (i < Cblock) {
        vga[cursor++] = block;
        i++;
    }
}

void tempColourOutput(int top) {
    unsigned char value = 0x00;
    int i = 0;
    int ia = 0;
    while (ia <= top) {
        while (i <= 15){
            funnycolour(value, 4);
            value = value + 16;
            i++;
        }
        cursor = ((cursor / 80) + 1) * 80;
        i = 0;
        ia++;
    }
}

void printdebug(char input) {
    char test[2] = {input, '\0'};           //USELESSS FOR NOW
    //print(test);
}