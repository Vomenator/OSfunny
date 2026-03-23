#include "command.hpp"
#include "io.hpp"
#include "screen.hpp"
#include "string.hpp"

#define BLINK_TIME 7000000
#define MAX_SCREEN_SIZE 2000

bool blink_state = false;
int blink_count = 0;
int cursorNew = 0;
//scancodeMap scan;
char linedchar[MAX_SCREEN_SIZE] = {};


void flushlinedchar(int wcount) {
    for (int i = 0; i <= wcount; i++) {
        linedchar[i] = {'\0'};
    }
    bufferclear();
}

Command parsecommand(const char* input) {
    if (strcmp(input, "print") == 0) return CMD_PRINT;
    if (strcmp(input, "iden") == 0) return CMD_IDENTIFY;
    if (strcmp(input, "cls") == 0) return CMD_CLEAR;
    if (strcmp(input, "\n") == 0) return CMD_UNKNOWN;
    return CMD_UNKNOWN;
}

void printCommand() {
    //strcmp(returnstringBuffer(5, ' '), "-n");
    //if (strcmp(returnstringBuffer(5, ' '), "\0") == 0) return print("not enough args!\n");
    if (strcmp(returnstringBuffer(5, ' '), "-n") != 0) return print("nirs\n");
    print("error\n");
}

void commandCheck(const char* input) {
    switch(parsecommand(input)) {
        case CMD_IDENTIFY:
            print("you dont pay me enough!\n");
            break;
        case CMD_CLEAR:
            clear_screen();
            break;
        case CMD_PRINT:
        printCommand();
            break;
        default:
            print("invalid command!\n");
    }
}


void input() {
    int wcount = 0;
    cursorNew = getcursor();
    uint8_t scancode;
    while (1) {
        if (inb(KEYBOARD_STATUS) & (KEY_BUSY)) {

            scancode = keyboard_read_hold();
            if (!(scancode & KEY_RELEASE)) { // ignore key releases

                linedchar[wcount] = scancode_to_ascii(scancode);               // CAN CLEAN THIS UP AT A LATER DATE
                char strc[2] = {scancode_to_ascii(scancode), '\0'};
                print(strc);
                cursorNew = getcursor();
                wcount++;
            }
        }
        else {
            blink_count++;
            if (blink_count >= BLINK_TIME) {  // tune this number for blink speed
                blink_count = 0;
                blink_state = !blink_state;
                vga[cursorNew] = blink_state ? 0xFF5F : 0x005F;
            }
            if (scancode_to_hex(scancode) == 0x1c && wcount > 0) {
                getCinputCLI(0, 0, 80);
                //print("\nhi: ");
                //print(returnstringBuffer(6, ' '));
                //print("\n");
                commandCheck(returnstringBuffer(0, ' '));
                cursorNew = getcursor();
                flushlinedchar(wcount);
                wcount = 0;
            }
        }
    }
}


void commandprompt() {
    clear_screen();
    print("\n");
   // printdebug(inttochar(10));
    printdebug(inttochar(100));
    print(returnstringBuffer());
    bufferclear();
    input();
}
