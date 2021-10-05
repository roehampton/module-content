; Printing strings

; Tell assembler where this code is loaded
[org 0x7c00]

mov bx, hello           ; We use bx to point to where we will print
call print_function     ; Call print_function

jmp $                   ; Loop forever

print_function:
    pusha               ; Push registers onto the stack
    mov ah, 0x0e        ; Scrolling teletype BIOS function
print_char:
    mov al, [bx]        ; Move memory pointed to by bx into al
    cmp al, 0           ; Check if character is zero (end of string)
    je end_print        ; If zero, end print
    int 0x10            ; Call interupt
    inc bx              ; Move to next character
    jmp print_char
end_print:
    popa                ; Pop registers back from the stack
    ret                 ; Return from function

hello:
    db 'Hello, World!',0x0d,0xa,0

times 510 - ($ - $$) db 0
dw 0xaa55