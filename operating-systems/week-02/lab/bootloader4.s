bits 16
[org 0x7c00]

boot:
    ; Active 20th address line.
    ; Now have access to more than 1MB of memory
    mov ax, 0x2401
    int 0x15
    ; Set VGA text mode to 3
    mov ax, 0x3
    int 0x10
    ; Clear the interrupt flag. Get us into a normal state
    cli
    ; To enter 32-bit mode we have to enter protected mode.
    ; To do this, we have to describe the memory areas.
    ; We do this by declaring a global descriptor table (see below).
    ; We have to load this using lgdt (load global descriptor table).
    lgdt [gdt_pointer]
    ; Now we need to set protected mode on the CPU.
    ; First, get the CPU register
    mov eax, cr0
    ; Then enable protected mode bit in this value
    ; Remember what or does in binary
    or eax, 0x1
    ; Then store the new value back into the CPU register.
    ; This will enable protected mode.
    mov cr0, eax
    ; Now jump to the 32-bit part of our code
    jmp CODE_SEG:boot2

; Global Descriptor Table
; Don't worry about these values unless you are interested
gdt_start:
    dq 0x0
gdt_code:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0
gdt_data:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0
gdt_end:

gdt_pointer:
    ; Size of the GDT structure
    dw gdt_end - gdt_start
    ; Location in memory of the GDT structure
    dd gdt_start

; Defines offsets into the GDT structure
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

; Now tell NASM to output 32 bit code
bits 32
; This is where our initial boot loader jumps to
boot2:
    ; Now we need to set the segments to point to where our data
    ; segment has been defined.
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    ; Now load the location of where our message is
    mov esi, hello
    ; Set memory location of VGA text buffer. This is 0xb8000
    mov ebx, 0xb8000

; Now loop until end of string
loop:
    ; Load next character
    lodsb
    ; Check if end of string
    cmp al, 0
    ; If end, jump to halt
    je halt
    ; Set text colour to blue
    or eax, 0x0100
    ; Load data to display into VGA memory
    mov word [ebx], ax
    ; Increment location to write to next
    add ebx, 2
    ; Loop
    jmp loop
halt:
    ; Clear interrupt flags
    cli
    ; Halt
    hlt

; String to display
hello:
    db "Hello world!",0x0

; Fill up to 510th byte
times 510 - ($ - $$) db 0
; Add bootloader bytes
dw 0xaa55