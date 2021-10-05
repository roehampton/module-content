; A bootloader that prints a message

mov ah, 0x0e    ; scrolling teletype BIOS function
mov al, 'H'     ; Set character to write
int 0x10        ; Call the BIOS function
mov al, 'e'     ; Set character to write
int 0x10        ; Call the BIOS function
mov al, 'l'     ; Set character to write
int 0x10        ; Call the BIOS function
mov al, 'l'     ; Set character to write
int 0x10        ; Call the BIOS function
mov al, 'o'     ; Set character to write
int 0x10        ; Call the BIOS function

; Loop to current location.
; In other words, infinite loop.
jmp $

; Pad to 510 bytes
times 510 - ($ - $$) db 0

; Add byes to indicate boot sector
dw 0xaa55