#include "newVGA.hpp"

void kerncharacterA(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'A'
    const uint16_t A[8] = {
        0b00011000,             //    ##                //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00100100,             //   #  #               // ultimately making 0b00000000
        0b01000010,             //  #    #
        0b01000010,             //  #    #
        0b01111110,             //  ######
        0b01000010,             //  #    #
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (A[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterB(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'B'
    const uint16_t B[8] = {
        0b01111100,             //  #####               //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #              // ultimately making 0b00000000
        0b01000010,             //  #    #
        0b01111100,             //  #####               // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #
        0b01000010,             //  #    #
        0b01000010,             //  #    #
        0b01111100              //  ##### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (B[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterC(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'C'
    const uint16_t C[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000000,             //  #                  // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000000,             //  #                  
        0b01000000,             //  #                  
        0b01000000,             //  #                  
        0b01000010,             //  #    #             
        0b00111100              //   #### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (C[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterD(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'D'
    const uint16_t D[8] = {
        0b01111000,             //  ####               //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000100,             //  #   #              // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #
        0b01000010,             //  #    #
        0b01000010,             //  #    #
        0b01000100,             //  #   #             
        0b01111000              //  #### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (D[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterE(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'E'
    const uint16_t E[8] = {
        0b01111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000000,             //  #                   // ultimately making 0b00000000
        0b01000000,             //  #                   // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01111110              //  ###### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (E[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterF(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'F'
    const uint16_t F[8] = {
        0b01111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000000,             //  #                   // ultimately making 0b00000000
        0b01000000,             //  #                   // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000              //  # 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (F[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterG(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'G'
    const uint16_t G[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000000,             //  #                  // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01001110,             //  #  ###              //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00111100              //   #### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (G[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterH(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'H'
    const uint16_t H[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111110,             //  ######              //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (H[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterI(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'I'
    const uint16_t I[8] = {
        0b00111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00001000,             //    ##                // ultimately making 0b00000000
        0b00001000,             //    ##                // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00001000,             //    ##                //
        0b00001000,             //    ##                // 
        0b00001000,             //    ##                //
        0b00001000,             //    ##                //
        0b00111110              //  ######
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (I[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterJ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'J'
    const uint16_t J[8] = {
        0b00011110,             //    ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00000100,             //      #               // ultimately making 0b00000000
        0b00000100,             //      #               // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00000100,             //      #               //
        0b00000100,             //      #               //
        0b01000100,             //  #   #               //
        0b01000100,             //  #   #               //
        0b00111000              //   ### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (J[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterK(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'K'
    const uint16_t K[8] = {
        0b01000010,             //  #    ##             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000100,             //  #   ##              // ultimately making 0b00000000
        0b01001000,             //  #  ##               // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01110000,             //  ###                 //
        0b01010000,             //  #  ##               //
        0b01001000,             //  #  ##               //
        0b01000100,             //  #   ##             //
        0b01000010              //  #    ##
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (K[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterL(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'L'
    const uint16_t L[8] = {
        0b01000000,             //  #                   //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000000,             //  #                   // ultimately making 0b00000000
        0b01000000,             //  #                   // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01111110              //  ###### 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (L[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterM(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'M'
    const uint16_t M[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01100110,             //  ##  ##             // ultimately making 0b00000000
        0b01011010,             //  # ## #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (M[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterN(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'N'
    const uint16_t N[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01100010,             //  ##   #             // ultimately making 0b00000000
        0b01010010,             //  # #  #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01001010,             //  #  # #             //
        0b01000110,             //  #   ##             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (N[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterO(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'O'
    const uint16_t O[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (O[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterP(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'P'
    const uint16_t P[8] = {
        0b01111100,             //  #####               //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #              // ultimately making 0b00000000
        0b01000010,             //  #    #              // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000,             //  #                   //
        0b01000000              //  #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (P[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterQ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'Q'
    const uint16_t Q[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01010010,             //  # #  #             //
        0b01001010,             //  #  # #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (Q[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterR(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'R'
    const uint16_t R[8] = {
        0b01111100,             //  #####               //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #              // ultimately making 0b00000000
        0b01000010,             //  #    #              // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01111100,             //  #####               //
        0b01001000,             //  #  #               //
        0b01000100,             //  #   #              //
        0b01000010,             //  #    #             //
        0b01000001              //  #     #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (R[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterS(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'S'
    const uint16_t S[8] = {
        0b00111100,             //   ####              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000000,             //  #                  // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00111100,             //   ####              //
        0b00000010,             //       #             //
        0b00000010,             //       #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (S[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterT(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'T'
    const uint16_t T[8] = {
        0b011111111,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b000011000,             //    ##                // ultimately making 0b00000000
        0b000011000,             //    ##                // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b000011000,             //    ##                //
        0b000011000,             //    ##                //
        0b000011000,             //    ##                //
        0b000011000,             //    ##                //
        0b000011000              //    ##
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (T[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterU(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'U'
    const uint16_t U[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00111100              //   ####
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (U[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterV(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'V'
    const uint16_t V[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01000010,             //  #    #             //
        0b00100100,             //   #  #              //
        0b00100100,             //   #  #              //
        0b00011000              //    ## 
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (V[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterW(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'W'
    const uint16_t W[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b01000010,             //  #    #             // ultimately making 0b00000000
        0b01000010,             //  #    #             // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b01000010,             //  #    #             //
        0b01011010,             //  # ## #             //
        0b01100110,             //  ##  ##             //
        0b01000010,             //  #    #             //
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (W[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterX(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'X'
    const uint16_t X[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00100100,             //   #  #              // ultimately making 0b00000000
        0b00011000,             //    ##                // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00011000,             //    ##                //
        0b00011000,             //    ##                //
        0b00011000,             //    ##                //
        0b00100100,             //   #  #              //
        0b01000010              //  #    #
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (X[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterY(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'Y'
    const uint16_t Y[8] = {
        0b01000010,             //  #    #             //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00100100,             //   #  #              // ultimately making 0b00000000
        0b00011000,             //    ##                // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00011000,             //    ##                //
        0b00011000,             //    ##                //
        0b00011000,             //    ##                //
        0b00011000,             //    ##                //
        0b00011000              //    ##
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (Y[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kerncharacterZ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    // Example: Draw a simple 8x8 pixel representation of the letter 'Z'
    const uint16_t Z[8] = {
        0b01111110,             //  ######              //bitmap orientation is 0b 0000 is the x coord and 0000 is the y coord 
        0b00000010,             //       #             // ultimately making 0b00000000
        0b00000100,             //      #              // values dont mean anything its just the drawing where each bit repersents a pixel on the screen so it follows a weird boundary system
        0b00001000,             //     #               //
        0b00010000,             //    #                //
        0b00100000,             //   #                 //
        0b01000000,             //  #                  //
        0b01111110              //  ######
    };

    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            if (Z[j] & (1 << (7 - i))) { // Check if the bit is set
                put_pixel(x + i, y + j, red, green, blue, alpha);
            }
        }
    }
}

void kernel::print::kcharacterA(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterA(x, y, red, green, blue, alpha);
    kerncharacterA(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterB(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterB(x, y, red, green, blue, alpha);
    kerncharacterB(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterC(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterC(x, y, red, green, blue, alpha);
    kerncharacterC(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterD(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterD(x, y, red, green, blue, alpha);
    kerncharacterD(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterE(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterE(x, y, red, green, blue, alpha);
    kerncharacterE(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterF(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterF(x, y, red, green, blue, alpha);
    kerncharacterF(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterG(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterG(x, y, red, green, blue, alpha);
    kerncharacterG(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterH(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterH(x, y, red, green, blue, alpha);
    kerncharacterH(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterI(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterI(x, y, red, green, blue, alpha);
    kerncharacterI(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterJ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterJ(x, y, red, green, blue, alpha);
    kerncharacterJ(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterK(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterK(x, y, red, green, blue, alpha);
    kerncharacterK(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterL(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterL(x, y, red, green, blue, alpha);
    kerncharacterL(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterM(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterM(x, y, red, green, blue, alpha);
    kerncharacterM(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterN(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterN(x, y, red, green, blue, alpha);
    kerncharacterN(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterO(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterO(x, y, red, green, blue, alpha);
    kerncharacterO(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterP(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterP(x, y, red, green, blue, alpha);
    kerncharacterP(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterQ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterQ(x, y, red, green, blue, alpha);
    kerncharacterQ(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterR(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterR(x, y, red, green, blue, alpha);
    kerncharacterR(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterS(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterS(x, y, red, green, blue, alpha);
    kerncharacterS(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterT(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterT(x+1, y, red, green, blue, alpha);
    //kerncharacterT(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterU(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterU(x, y, red, green, blue, alpha);
    kerncharacterU(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterV(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterV(x, y, red, green, blue, alpha);
    kerncharacterV(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterW(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterW(x, y, red, green, blue, alpha);
    kerncharacterW(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterX(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterX(x, y, red, green, blue, alpha);
    kerncharacterX(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterY(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterY(x, y, red, green, blue, alpha);
    kerncharacterY(x+1, y, red, green, blue, alpha);
}

void kernel::print::kcharacterZ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kerncharacterZ(x, y, red, green, blue, alpha);
    kerncharacterZ(x+1, y, red, green, blue, alpha);
}

void kernel::print::characterTest(uint32_t x, uint32_t y, char red, char green, char blue, char alpha) {
    kernel::print::kcharacterA(x, y, red, green, blue, alpha);
    kernel::print::kcharacterB(x+8, y, red, green, blue, alpha);
    kernel::print::kcharacterC(x+16, y, red, green, blue, alpha);
    kernel::print::kcharacterD(x+24, y, red, green, blue, alpha);
    kernel::print::kcharacterE(x+32, y, red, green, blue, alpha);
    kernel::print::kcharacterF(x+40, y, red, green, blue, alpha);
    kernel::print::kcharacterG(x+48, y, red, green, blue, alpha);
    kernel::print::kcharacterH(x+56, y, red, green, blue, alpha);
    kernel::print::kcharacterI(x+64, y, red, green, blue, alpha);
    kernel::print::kcharacterJ(x+72, y, red, green, blue, alpha);
    kernel::print::kcharacterK(x+80, y, red, green, blue, alpha);
    kernel::print::kcharacterL(x+88, y, red, green, blue, alpha);
    kernel::print::kcharacterM(x+96, y, red, green, blue, alpha);
    kernel::print::kcharacterN(x+104, y, red, green, blue, alpha);
    kernel::print::kcharacterO(x+112, y, red, green, blue, alpha);
    kernel::print::kcharacterP(x+120, y, red, green, blue, alpha);
    kernel::print::kcharacterQ(x+128, y, red, green, blue, alpha);
    kernel::print::kcharacterR(x+136, y, red, green, blue, alpha);
    kernel::print::kcharacterS(x+144, y, red, green, blue, alpha);
    kernel::print::kcharacterT(x+152, y, red, green, blue, alpha);
    kernel::print::kcharacterU(x+161, y, red, green, blue, alpha);
    kernel::print::kcharacterV(x+169, y, red, green, blue, alpha);
    kernel::print::kcharacterW(x+177, y, red, green, blue, alpha);
    kernel::print::kcharacterX(x+185, y, red, green, blue, alpha);
    kernel::print::kcharacterY(x+193, y, red, green, blue, alpha);
    kernel::print::kcharacterZ(x+201, y, red, green, blue, alpha);

    kernel::print::kcharacterAstrisk(x+209, y, red, green, blue, alpha);
    kernel::print::kcharacterEXCLAMATION(x+217, y, red, green, blue, alpha);

    kernel::print::kcharacter0(x+225, y, red, green, blue, alpha);
    kernel::print::kcharacter1(x+233, y, red, green, blue, alpha);
    kernel::print::kcharacter2(x+241, y, red, green, blue, alpha);
    kernel::print::kcharacter3(x+249, y, red, green, blue, alpha);
    kernel::print::kcharacter4(x+257, y, red, green, blue, alpha);
    kernel::print::kcharacter5(x+265, y, red, green, blue, alpha);
    kernel::print::kcharacter6(x+273, y, red, green, blue, alpha);
    kernel::print::kcharacter7(x+281, y, red, green, blue, alpha);
    kernel::print::kcharacter8(x+289, y, red, green, blue, alpha);
    kernel::print::kcharacter9(x+297, y, red, green, blue, alpha);
    //x_cursor = (x + 297 + 8); // Move cursor to the end of the last character
}