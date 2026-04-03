global _start
global _gdt_flush
extern _kmain

section .multiboot
    dd 0x1BADB002               ; this is the magic number i.e the mem entry point into multiboot
    dd 0x00                     ; im not requesting additional options from GRUB
    dd -(0x1BADB002 + 0x00)     ; grub likes to check if the data checks out otherwise it may ignore it

section .text

_start:
    cli                         ; this disables interrupts which makes sure this squence is ran uninterrupted
    mov esp, stack_top          ; move stack top to the esp register
    call _kmain                 ; begins the kmain function within the kernel
    ;hlt                         ; once complete halts the function of the CPU 

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
    resb 16384                             ; this reserves 16KB of space for the kernel stack, which is used for function calls and local variables
    ;resb 1024 * 1600                             ; this reserves 16KB of space for the kernel stack, which is used for function calls and local variables
stack_top:     ; This label points to the END of the reserved space