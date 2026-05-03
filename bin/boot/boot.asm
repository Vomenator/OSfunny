global _start
global _gdt_flush
extern kmain

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00000004           ; add 4 at the end later so i can do funny with it
    dd -(0x1BADB002 + 0x00000004)
    dd 0                     ; this is the magic number for the video mode, it puts it to linear mode
    dd 1024                     ; this is the width of the screen, in pixels, which is 640
    dd 768                     ; this is the height of the screen, in pixels, which is 480
    dd 32                     ; this is the bits per pixel, which is 16

section .text
;[bits 16]
[bits 32]
_start:
    mov word [0xB8000], 0x0741  ; A - _start reached
    cli
    mov word [0xB8002], 0x0742  ; B - after cli
    mov esp, stack_top
    mov word [0xB8004], 0x0743  ; C - after stack setup
    push ebx
    mov word [0xB8006], 0x0744  ; D - after push
    call kmain
    mov word [0xB8008], 0x0745  ; E - after kmain (should never reach)                   ; once complete halts the function of the CPU

_gdt_flush:
    mov eax, [esp+4]            ; this ignores 4 bytes of memory and moves it to eax
    lgdt [eax]                  ; loads interrupt descriptor table, containing all interrupt vectors 
    mov ax, 0x10                ; adds 16 to the ax register               
    mov ds, ax                  ; moves 16 to ds, es, fs,gs,ss
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax                  ; this whole function pretty much points to my GDT table instead of grubs bad one, changing the mem addresses to the gdt table of data
    jmp 0x08:.flush             ; this then jumps to the 0x08 segment which is the kernel code, then jumps to .flush afterwards, which returns it      
.flush:                                 ; just a label
    ret                                 ; returns to where it came from     

section .bss
    align 4                                         ; this makes sure that the memory locations are aligned to 4 bytes, making it faster for the CPU to read and write
kernel_stack:
    resb 163840                             ; this reserves 16KB of space for the kernel stack, which is used for function calls and local variables
    ;resb 1024 * 1600                             ; this reserves 16KB of space for the kernel stack, which is used for function calls and local variables
stack_top:     ; This label points to the END of the reserved space
