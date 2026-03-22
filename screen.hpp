#pragma once
#include "kernelforward.hpp"

// VGA text mode buffer
//volatile unsigned short* vga = (volatile unsigned short*)0xB8000;       //vga memory location, this is pretty much setting the first byte (end location) SECOND CONTAINING COLOR
extern volatile unsigned short* vga;
static int cursor = 0;                                                  // static meaning it will sustain its value, starts at 0



void clear_screen();
void putchar(char c);
void print(const char* str);
void funnycolour(unsigned char colour, int Cblock);
void tempColourOutput(int top);
int getcursor();
