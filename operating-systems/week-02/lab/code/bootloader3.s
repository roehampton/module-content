; Tell nasm to produce 16 bit code
bits 16
; Memory offset from where the bootloader is loaded
[org 0x7c00]

; Main boot
boot:
    ; Point si register to our message
    mov si, hello
    ; Set character teletype mode
    mov ah, 0x0e
; Loop for printing
loop:
    ; Load next byte pointed to be si register
    lodsb
    ; Check if end of string
    cmp al, 0
    ; If end, jump to halt
    je halt
    ; Ask BIOS to print character
    int 0x10
    ; Loop
    jmp loop
; End of program
halt:
    ; Clear interrupt flag
    cli
    ; Halt execution
    hlt

; Hello message
hello:
    db "Hello, world!",0xd,0xa,0

; Fill rest of boot sector
times 510 - ($ - $$) db 0
dw 0xaa55