# Computer Systems Seminar 6 - Introduction to Assembly

1. Below is the code to execute a division operation.
   - Correctly comment on each line with details of the instruction.
   - What is the output for this code?

```assembly
global main

SECTION .data
    msg db "The result is ",0xa,0xd
    len equ $ - msg
    
SECTION .bss
    res resb 1
    
SECTION .text

main:
    mov ax, '8'
    sub ax, '0'
    mov bl, '2'
    sub bl, '0'
    div bl
    add ax, '0'
    mov [res], ax
    mov ecx, msg
    mov edx, len
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov ecx, res
    mov edx, 1
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov eax, 1
    int 0x80
```

2. Write the assembly statement that will declare a constant value equal to 100.
3. Write three lines of assembly that will add two variables.
4. Write a line of assembly to determine the length of a variable `“School”`.
5. Study the code below and answer the following questions.
   - What is the error in this code?
   - What is the output of this code?

```assembly
global main

SECTION .data
    grt db Interesting Seminar',0xa
    len equ $ - grt
    
SECTION .text

main:
    mov edx, 1
    mov ecx, grt
    mov eax, 4
    int 0x80
    mov eax, 1
    int 0x80
```

