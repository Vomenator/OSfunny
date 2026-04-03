#include "command.hpp"

#define BLINK_TIME 7000000
#define MAX_SCREEN_SIZE 2000

bool exitS = false;

bool blink_state = false;
int blink_count = 0;
int cursorNew = 0;
//scancodeMap scan;
char linedchar[MAX_SCREEN_SIZE] = {};


void flushlinedchar(int wcount) {
    for (int i = 0; i <= wcount; i++) {
        linedchar[i] = {'\0'};
    }
    //bufferclear();
}

void linestartC() {
    print(">: ");
}


void input() {
    bufferclear();
    linestartC();
    int wcount = 0;
    cursorNew = getcursor();
    uint8_t scancode;
    while (exitS == false) {
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
                commandCheck(returnstringBuffer(0, ' '));
                linestartC();
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
    input();
    clear_screen();
    print("goodbye!\n");
}
