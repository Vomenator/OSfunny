ENTRY(_start)

SECTIONS
{
    . = 0x100000;

    .multiboot ALIGN(8) :
    {
        KEEP(*(.multiboot))
    }

    .text ALIGN(4096) :
    {
        *(.text)
    }

    .data ALIGN(4096) :
    {
        *(.data)
        *(.rodata*)
    }

    .bss ALIGN(4096) :
    {
        *(COMMON)
        *(.bss)
    }

    /DISCARD/ :
    {
        *(.eh_frame)
        *(.eh_frame_hdr)
        *(.reloc)
        *(.comment)
    }
}