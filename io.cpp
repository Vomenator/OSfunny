#include "io.hpp"
#include "screen.hpp"


char getClineCLI(int Pline) {
    //int Sline = (cursor%80) + 80*Pline;
    int line = 79*Pline;
    //int maxline = cursor - 80*line ;
    print("\n\n");
    for (int i = 0; i < 80; i++) {
        char fin[2] = {linedchar[i+line], '\0'};
        //char fin[2] = {linedchar[0], '\0'};
        print(fin);
    }
    return 'c';
}

// not in use
void clearline() {
    //char input[2] = {(static_cast<char>(sizeof(*str)), '\0')};                // to be diddled later, when print character issue is resolved
    //print(input);
    for (int i; i <= cursor; i++) {
    //linedchar[i] = {};
    }
}

void delay(long int count) {                    // this recieves input number up to 32 bits or 4 bytes long
    while (count--) {
         __asm__ volatile("nop");               // writes no operation code to CPU directly and tells compiler to leave this alone and not optimise it
    }
}

uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ volatile("inb %1, %0" : "=a"(value) : "Nd"(port)); //%1 is the input and % is the output, =a puts the 8 bit result in the AL reg [A=EAX,AX,AL] and = means write only output
    return value;        // also : is a seperator for statement : meaning input section, output section etc    // will store within the variable value, 
}    //"inb is input byte instruction from specified port", "nd" is it has to be 8 bit "N" unsigned const, or must be in DX reg "d"


uint8_t keyboard_read_hold() {                  
    // wait until keyboard buffer has data
    while (!(inb(KEYBOARD_STATUS) & 0x01)); // if the status is NOT outputing keeps looping until 0x01 "has output" is not true
    return inb(KEYBOARD_PORT);              // reads 8 bit return data and returns the output
}

// legacy
//---------------------------------------------------------------------------------------
uint8_t keyboard_read_nowait() {
    if (!(inb(KEYBOARD_STATUS) & 0x01)) return 0;  // no key ready, return 0
    delay(250000000);
    return inb(KEYBOARD_PORT);
}
//----------------------------------------------------------------------------------------

char scancode_to_ascii(uint8_t scancode) {              // gets the scancode input from the keyboard input
    scancodeMap map;
    if (scancode >= sizeof(map.Sall)) return 0;     // if the scancode allowed is not within the scancode map returns 0
    if ((map.Sall[scancode].sentinel) != ';') return map.Sall[scancode].ascii; // else this will return the scancode value found within the table
    else {
        return map.Sall[scancode].hex;
    }
}