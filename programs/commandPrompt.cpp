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
    kernel::print("! ");
}

char getCinputCLI(int Pline, int linestart, int lineend) {                                  // this whole function is a mess pure spaghetti
    //int Sline = (cursor%80) + 80*Pline;
    int line = 79*Pline;
    //int maxline = cursor - 80*line ;
    for (int i = linestart; i < lineend; i++) {
        //buffer[2] = {linedchar[i+line]};
        stringstore(linedchar[i + line]);                                           // dont love this
    }
    return 'c';
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
                //kernel::print(inttochar(sizeof(linedchar)));
                kernel::print(strc);
                cursorNew = getcursor();
                wcount++;
            }
        }
        else {
            blink_count++;
            if (blink_count >= BLINK_TIME) {  // tune this number for blink speed
                blink_count = 0;
                blink_state = !blink_state;
                //blink_state ? 0xFF5F : 0x005F;
            }
            if (scancode_to_hex(scancode) == 0x1c && wcount > 0) {
                getCinputCLI(0, 0, 80);
                //kernel::print(linedchar);
                commandCheck(returnstringBuffer(0, ' '));
                //commandCheck(linedchar);
                linestartC();
                cursorNew = getcursor();
                flushlinedchar(wcount);
                wcount = 0;
            }
        }
    }
}


void commandprompt() {
    clear_screen();//clear_screen();
    kernel::print("hello world!");
    kernel::print("\n");
    input();
    //colourscreen(255,255,255);
    kernel::print("goodbye!\n");
}
