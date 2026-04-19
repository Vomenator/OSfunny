#include "newVGA.hpp"

void kerncharacterEMPTY(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'Y'
    const uint16_t empty[8] = {
        0b00000000,             //                      //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00000000,             //                     // ultimately making 0b00000000
        0b00000000,             //                      // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00000000,             //                           //
        0b00000000,             //                           //
        0b00000000,             //                         //
        0b00000000,             //                          //
        0b00000000              //                      //  
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (empty[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterAstrisk(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'Y'
    const uint16_t astrisk[8] = {
        0b00000000,             //                      //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01001001,             //   #  #  #            // ultimately making 0b00000000
        0b00111110,             //    #####             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00001000,             //      #               //
        0b00001000,             //      #               //
        0b00111110,             //    #####             //
        0b01001001,             //   #  #  #            //
        0b00000000              //                      //  
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (astrisk[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterEXCLAMATION(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    const uint16_t exc[8] = {
        0b00010000,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00010000,             //  #    #             // ultimately making 0b00000000
        0b00010000,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00010000,             //  #    #             //
        0b00010000,             //   ####              //
        0b00000000,             //                      //
        0b00010000,             //  #    #             //
        0b00010000              //   #### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (exc[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

// ---------------------------------------------- numbers ---------------------------------------------------------------


// numbers!!!

void kerncharacter0(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '0'
    const uint16_t zero[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000110,             //  #   ##             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01001010,             //  #  # #             //
        0b01010010,             //  # #  #             //
        0b01100010,             //  ##   #             //
        0b01000010,             //  #    #             //
        0b00111100              //   #### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (zero[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter1(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '1'
    const uint16_t one[8] = {
        0b00010000,             //    ##                //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00110000,             //   ###                // ultimately making 0b00000000
        0b00010000,             //    ##                // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00010000,             //    ##                //
        0b00010000,             //    ##                //
        0b00010000,             //    ##                //
        0b00010000,             //    ##                //
        0b00111000              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (one[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter2(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '2'
    const uint16_t two[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b00000010,             //       #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00000100,             //      #              //
        0b00001000,             //     #               //
        0b00010000,             //    #                //
        0b00100000,             //   #                 //
        0b01111110              //  ######
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (two[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter3(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '3'
    const uint16_t three[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b00000010,             //       #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00011100,             //    ###              //
        0b00000010,             //       #             //
        0b00000010,             //       #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (three[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter4(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '4'
    const uint16_t four[8] = {
        0b00000100,             //      #              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00001100,             //     ##              // ultimately making 0b00000000
        0b00010100,             //    # #              // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00100100,             //   #  #              //
        0b01000100,             //  #   #              //
        0b01111110,             //  ######             //
        0b00000100,             //      #              //
        0b00000100              //      #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (four[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter5(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '5'
    const uint16_t five[8] = {
        0b01111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000000,             //  #                  // ultimately making 0b00000000
        0b01000000,             //  #                  // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b00000010,             //       #             //
        0b00000010,             //       #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (five[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter6(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '6'
    const uint16_t six[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000000,             //  #                  // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (six[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter7(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '7'
    const uint16_t seven[8] = {
        0b01111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00000010,             //       #             // ultimately making 0b00000000
        0b00000100,             //      #              // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00001000,             //     #               //
        0b00010000,             //    #                //
        0b00100000,             //   #                 //
        0b01000000,             //  #                  //
        0b01000000              //  #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (seven[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter8(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '8'
    const uint16_t eight[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00111100,             //   ####              //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (eight[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacter9(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter '9'
    const uint16_t nine[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00111110,             //   #####             //
        0b00000010,             //       #             //
        0b00000010,             //       #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (nine[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}


//---------------------------------------------------------------------- cspecial ---------------------------------------------------------------

void kernel::print::kcharacterAstrisk(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterAstrisk(x, y, red, green, blue, alpha);
    //kerncharacterAstrisk(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterEXCLAMATION(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterEXCLAMATION(x, y, red, green, blue, alpha);
    kerncharacterEXCLAMATION(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterEMPTY(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterEMPTY(x, y, red, green, blue, alpha);
    kerncharacterEMPTY(x+1, y, red, green, blue, alpha);
}


//------------------------------------------------------------------------ numbers ---------------------------------------------------------------
void kernel::print::kcharacter0(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter0(x, y, red, green, blue, alpha);
    kerncharacter0(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter1(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter1(x+1, y, red, green, blue, alpha);
    kerncharacter1(x+2, y, red, green, blue, alpha);
}

void kernel::print::kcharacter2(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter2(x, y, red, green, blue, alpha);
    kerncharacter2(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter3(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter3(x, y, red, green, blue, alpha);
    kerncharacter3(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter4(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter4(x, y, red, green, blue, alpha);
    kerncharacter4(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter5(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter5(x, y, red, green, blue, alpha);
    kerncharacter5(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter6(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter6(x, y, red, green, blue, alpha);
    kerncharacter6(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter7(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter7(x, y, red, green, blue, alpha);
    kerncharacter7(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter8(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter8(x, y, red, green, blue, alpha);
    kerncharacter8(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacter9(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacter9(x, y, red, green, blue, alpha);
    kerncharacter9(x+1, y, red, green, blue, alpha);
}


