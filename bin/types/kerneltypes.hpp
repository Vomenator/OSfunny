#pragma once

// TYPE DEFINITIONS

#define NULL nullptr

typedef unsigned char      uint8_t;                                     // loads in these types otherwise the code will not know what to do with these
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t           uintptr_t;

struct Bsize {
    static const uint32_t bit;
    static const uint8_t byte = 8;
    static const uint32_t KB = 1024;
    static const uint32_t MB = 1024 * KB;
    static const uint32_t GB = 1024 * MB;
};

struct VBEInfoBlock {
    uint16_t attributes;
    uint8_t  winA, winB;
    uint16_t granularity;
    uint16_t winsize;
    uint16_t segmentA, segmentB;
    uint32_t realFctPtr;
    uint16_t pitch;

    uint16_t xres, yres;
    uint8_t  wchar, ychar, planes, bpp, banks;
    uint32_t vramSize;
    uint16_t colors[256];
};

struct CPUInfo {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
};

void commandprompt();