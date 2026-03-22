#include "kernelforward.hpp"

#define KEYBOARD_PORT 0x60              // port of keyboard input/output
#define KEYBOARD_STATUS 0x64            // current status of keyboard/commands will read busy if sending data, good for detecting when its reciving input

extern char linedchar[2000];
// will change this garbage in the future into an enum
/*const char scancode_map[] = {                                                   // key map repersenting allowed keys i.e acts as the pass which allows the hex codes of these values
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',     // through
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
    '*', 0, ' '
};*/

struct scanCode{
    uint8_t hex;
    unsigned char ascii;
    unsigned char sentinel;
};

struct scancodeMap{ // 0x00 is null, 0x01 is esc, 0x01d is left control, 0x2A is left shift, 0x36 is right shift, 0x38 is left alt, 0x3A is CAPS LOCK, 0x45 is NUMLOCK, 0x46 is SCROLL LOCK
    static constexpr scanCode Sall[] = { // 0x4f = END, 0x50 is keypad down, 0x51 is pgdwn, 0x52 is ins, 0x53 del

    {0x00, '\0', ';'},{0x01, '\0', ';'}, {0x02, '1'}, {0x03, '2'}, {0x04, '3'}, {0x05, '4'}, {0x06, '5'}, {0x07, '6'}, {0x08, '7'}, {0x09, '8'}, {0x0A, '9'},
    {0x0B, '0'}, {0x0C, '-'}, {0x0D, '='}, {0x0E, '\b'}, {0x0F, '\t'}, {0x10, 'q'}, {0x11, 'w'}, {0x12, 'e'}, {0x13, 'r'}, {0x14, 't'}, {0x15, 'y'}, {0x16, 'u'},
    {0x17, 'i'}, {0x18, 'o'}, {0x19, 'p'}, {0x1A, '['}, {0x1b, ']'}, {0x1c, '\n'}, {0x1d, '\0', ';'}, {0x1e, 'a'}, {0x1f, 's'}, {0x20, 'd'}, {0x21, 'f'}, {0x22, 'g'}, 
    {0x23, 'h'}, {0x24, 'j'}, {0x25, 'k'}, {0x26, 'l'}, {0x27, ';'}, {0x28, '\''}, {0x29, '`'}, {0x2A, '\0'}, {0x2b, '\\'}, {0x2c, 'z'}, {0x2d, 'x'}, {0x2e, 'c'}, 
    {0x2f, 'v'}, {0x30, 'b'}, {0x31, 'n'}, {0x32, 'm'}, {0x33, ','}, {0x34, '.'}, {0x35, '/'}, {0x36, '\0'}, {0x37, '*'}, {0x38, '\0'}, {0x39, ' '}, {0x3A, '\0'}, 
    {0x3B, '\0'}, {0x3c, '\0'}, {0x3d, '\0'}, {0x3e, '\0'}, {0x3f, '\0'}, {0x40, '\0'}, {0x41, '\0'}, {0x42, '\0'}, {0x43, '\0'}, {0x44, '\0'}, // function keys up to F10 in order
    {0x45, '\0'}, {0x46, '\0'}, {0x47}, {0x48}, {0x49}, {0x4A},{0x4b}, {0x4c}, {0x4d}, {0x4e}, {0x4f, '\0'}, {0x50, '\0'}, {0x51, '\0'}, {0x52, '\0'}, {0x53, '\0'}, 
    {0x54}, {0x55, '?'}, {0x56, '?'}, {0x57, '\0'}, {0x58, '\0'}, {0x59}, {0x5A}, {0x5b},{0x5c}, {0x5d}    //add more in the future  
};
    //uint8_t SC_2 = 0x03;
};


uint8_t keyboard_read_hold();                         
char scancode_to_ascii(uint8_t scancode);
void delay(long int count);
uint8_t inb(uint16_t port);

// temp
void clearline();
char getClineCLI(int Pline);