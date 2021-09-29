bits 16
[org 0x7c00]

boot:
    ; Access more than 1 MB of memory
    mov ax, 0x2401
    int 0x15
    ; Set VGA text mode to 3
    mov ax, 0x3
    int 0x10
    ; Store the disk index. Currently stored in dl register
    mov [disk], dl
    ; We are so low level we are reading the disk by sectors
    ; Tell BIOS we want to read sectors. Set ah register to 0x2
    mov ah, 0x2
    ; Set sectors to read
    mov al, 1
    ; Set cylinder index to read from
    mov ch, 0
    ; Set head index
    mov dh, 0
    ; Set sector index
    mov cl, 2
    ; Set disk to read from
    mov dl, [disk]
    ; Set target pointer
    mov bx, copy_target
    ; Ask the bios to perform the disk read
    int 0x13
    ; Clear interrupt flags
    cli
    ; Load GDT
    lgdt [gdt_pointer]
    ; Activate protected mode
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    ; Set data segment areas
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ; Jump to 32 bit code area
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

; disk index we store
disk:
    db 0x0

; Defines offsets into the GDT structure
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

; Fill first sector
times 510 - ($ - $$) db 0
dw 0xaa55

; Now in second disk sector
copy_target:
; Set 32 bit code
bits 32
; Declare hello message
hello:
    db "Welcome to your second disk sector!",0
boot2:
    ; Set text to print
    mov esi, hello
    ; Set memory to send data to print
    mov ebx, 0xb8000
; Loop writing characters
loop:
    ; Load next character
    lodsb
    ; Check if end of string
    cmp al, 0
    ; If end of string jump to halt
    je halt
    ; Set text colour to white
    or eax, 0x0F00
    ; Load into VGA text buffer
    mov word [ebx], ax
    ; Move to next location in text buffer
    add ebx, 2
    ; Loop
    jmp loop
; Halt the program
halt:
    ; Clear interrupt flags
    cli
    ; Halt
    hlt

; Fill the rest of the disk sector
times 1024 - ($ - $$) db 0