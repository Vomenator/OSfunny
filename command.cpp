#include "io.hpp"
#include "screen.hpp"

bool blink_state = false;
int blink_count = 0;
int cursorNew = 0;
//scancodeMap scan;
char linedchar[2000] = {};

void input() {
    int wcount = 0;
    cursorNew = getcursor();
    while (1) {
        if (inb(KEYBOARD_STATUS) & (0x01)) {
            uint8_t scancode = keyboard_read_hold();
            if (!(scancode & 0x80)) { // ignore key releases
                linedchar[wcount] = scancode_to_ascii(scancode);               // CAN CLEAN THIS UP AT A LATER DATE
                char strc[2] = {scancode_to_ascii(scancode), '\0'};
                print(strc);
                cursorNew = getcursor();
                wcount++;
            }
        }
        else {
            blink_count++;
            if (blink_count >= 7000000) {  // tune this number for blink speed
                blink_count = 0;
                blink_state = !blink_state;
                vga[cursorNew] = blink_state ? 0xFF5F : 0x005F;
            }
            if (wcount >= 90) {
                getClineCLI(0);
                wcount = 0;
            }
        }
    }
}


void commandprompt() {
    //clear_screen();
    print("\n");
    input();
}

// this is to be put as a userspace program in the future as it is indeed a user space program and is in not in anyway in n