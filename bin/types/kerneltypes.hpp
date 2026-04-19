#pragma once

// TYPE DEFINITIONS

#define NULL nullptr

typedef unsigned char      uint8_t;                                     // loads in these types otherwise the code will not know what to do with these
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t           uintptr_t;
typedef uint32_t             size_t;

typedef char                int8_t;
typedef short               int16_t;
typedef int                 int32_t;

struct Bsize {
    static const uint32_t bit;
    static const uint8_t byte = 8;
    static const uint32_t KB = 1024;
    static const uint32_t MB = 1024 * KB;
    static const uint32_t GB = 1024 * MB;
};

struct CPUInfo {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
};

struct VBEModeInfo {
    uint16_t attributes;
    uint8_t  winA, winB;
    uint16_t granularity;
    uint16_t winsize;
    uint16_t segmentA, segmentB;
    uint32_t realFctPtr;
    uint16_t pitch;
    uint16_t Xres, Yres;
    uint8_t  Wchar, Ychar, planes, bpp, banks;
    uint8_t  memory_model, bank_size, image_pages;
    uint8_t  reserved0;
    uint8_t  red_mask, red_position;
    uint8_t  green_mask, green_position;
    uint8_t  blue_mask, blue_position;
    uint8_t  rsv_mask, rsv_position;
    uint8_t  directcolor_attributes;
    uint32_t physbase;  // framebuffer address
    uint32_t reserved1;
    uint16_t reserved2;
} __attribute__((packed));


struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
    uint32_t drives_length;
    uint32_t drives_addr;
    uint32_t config_table;
    uint32_t boot_loader_name;
    uint32_t apm_table;
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint32_t vbe_mode;
    uint32_t vbe_interface_seg;
    uint32_t vbe_interface_off;
    uint32_t vbe_interface_len;
    uint64_t framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t  framebuffer_bpp;
} __attribute__((packed));


void commandprompt();
void kernel_panic(uint32_t error);