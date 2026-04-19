#pragma once

#include "../../types/kerneltypes.hpp"

namespace kernel {
    class print {
    public:
        static uint32_t x_cursor, y_cursor;

        static void characterTest(uint32_t x, uint32_t y, char red, char green, char blue, char alpha);
        static void charprintmatrix(char ascii, uint32_t x, uint32_t y, char red, char green, char blue, char alpha);

    private:
        static void kcharacterA(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterB(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterC(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterD(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterE(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterF(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterG(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterH(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterI(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterJ(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterK(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterL(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterM(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
        static void kcharacterN(uint32_t x, uint32_t y, char red, char green,char blue,char alpha=0x00);
        static void kcharacterO(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterP(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterQ(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterR(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterS(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterT(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterU(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterV(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterW(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterX(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterY(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterZ(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);

        //special characters
        static void kcharacterAstrisk(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterEXCLAMATION(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacterEMPTY(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);

        //numbers
        static void kcharacter0(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter1(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter2(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter3(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter4(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter5(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter6(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter7(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter8(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
        static void kcharacter9(uint32_t x,uint32_t y,char red,char green,char blue,char alpha=0x00);
    };
}

//foward declarations
void put_pixel(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
bool VGAINIT(VBEModeInfo* vbe);
int colourscreen(char red, char green, char blue);


void print(const char* str, uint32_t x, uint32_t y, char red = 0xFF, char green = 0xFF, char blue = 0xFF, char alpha = 0x00);

//VBE CHARACTERS FORWARD DECLARATIONS

//void put_char(uint32_t x, uint32_t y, char c, char red, char green, char blue);
//void put_string(uint32_t x, uint32_t y, const char* str, char red, char green, char blue);
//void characterTest(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);