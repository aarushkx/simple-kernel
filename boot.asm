bits 32                 ; generate 32-bit code

section .text           ; the following code belongs to the code section

align 4                 ; align to 4 bytes
dd 0x1BADB002           ; magic
dd 0                    ; flags
dd 0xE4524FFE           ; checksum

global _start           ; make _start visible outside the assembly file
extern kmain            ; there exists a symbol called kmain, but it's somewhere else

_start:
    cli                 ; clear the interrupt-enable flag
    mov esp, stack_top  ; esp stores the stack pointer
    call kmain          ; call kmain (will be complied separately by GCC)
    hlt                 ; halt the CPU until an interrupt occurs

section .bss            ; the following data belongs to the bss section
    resb 8192           ; reserve 8KB (8192 bytes) for the stack

stack_top:              ; address immediately after the 8KB stack (stack grows downward)
