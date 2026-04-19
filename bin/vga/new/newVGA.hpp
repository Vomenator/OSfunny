#pragma once

#include "../../types/kerneltypes.hpp"


//foward declarations
void put_pixel(uint32_t x, uint32_t y, char red, char green, char blue, char alpha = 0x00);
bool VGAINIT(VBEModeInfo* vbe);
int colourscreen(char red, char green, char blue);