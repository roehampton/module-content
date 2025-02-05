# Computer Systems Lab 4 - Simple Assembly Programs

The aim of this lab is to write some simple assembly programs and compile them using JDoodle, with NASM IDE.

Open JDoodle by clicking on https://www.jdoodle.com/. Click on Let’s code and select NASM as your language and start coding

## Your First Assembly Programme

### Programme 1: Hello World

```
; hello world in nasm

; this section holds the declared variables, we can use 'segment' instead of 'section'
section .data
msg db 'hello world!', 0ah      ; assign msg variable with string, 0ah is the new-line character

len equ $ - msg			; assign the length of the msg to len variable
                        ; '$ - msg' means current address of the assembler ($) minus the address of msg 
                        ; which is the length of the string
                        ; $ is used to refer to the current address
                        ; $$ is used to refer to the address of the start of current section in assembly.
                        ; EQU defines a symbol to a given constant value
                        ; This definition is absolute, and cannot change later


 ; this section contains the main code of the program and instructions
 section .text
 global _start              ; defined an entry point for the program

 _start:                    ; start of the entry point
    mov     edx, len        ; edx holds the length of the message for printing (could use binary value 13)
    mov     ecx, msg        ; ecx holds the message
    mov     ebx, 1          ; 1 is for writing to STDOUT file
    mov     eax, 4          ; invokes SYS_WRITE (kernel opcode 4), eax executes the syscalls by opcode
    int     80h             ; execute the instructions, actually invoke a software interrupt

    mov     ebx, 0	    ; return exit status 0 - indicating no errors
    mov     eax, 1          ; invokes SYS_EXIT (kernel opcode 1) to exit the program gracefully
    int     80h
```

**Exercises**
1. Change the output to “I wrote this code” and execute the program.
2. Change the len variable to 7 at line 5 (i.e., change mov edx, len to mov edx, 7). What happened?
3. Change line 5 to have the exact number of characters in “I wrote this code”. What happened this time?


### Programme 2: Hard-coded addition

```assembly
; add two hard coded variables and print the sum
; trick:
; for converting ascii to decimal --> sub '0'
; for converting decimal to ascii --> add '0'

section .data
msg db "sum: "
len equ $ - msg

section .bss
sum resb 1

section .text
global _start

_start:
mov	eax, '3'	; put ascii '3' into eax
sub	eax, '0'	; convert ascii '3' to decimal 3
mov	ebx, '4'
sub	ebx, '0'

; add two values
add	eax, ebx
add	eax, '0'	; convert eax value back to ascii code for printing
mov	[sum], eax	; store the value in 'sum'

; print the message
mov	ecx,msg
mov	edx, len
mov	ebx, 1
mov	eax, 4
int	80h

; print the sum
mov	ecx, sum
mov	edx, 1
mov	ebx, 1
mov	eax, 4
int	80h

mov	eax, 1
mov	ebx, 0
int	80h
```

**Exercise**
    
4.  Comment out every line adding or subtracting '0'. What do you observe in the result?
5. Change '3' and '4', which are strings, for 3 and 4 (integers). Does it work now? Can you fix it in case it doesn't?


### Programme 3: Input/Output

```assembly
; take a number as input and print it

section .data
input_msg	db	'enter a number: '
len_input_msg equ $ - input_msg
display_msg	db	'entered value: '
len_display_msg equ $ - display_msg


section .bss
value resb 5		; variable to hold input value, 5 bytes in size, 1 byte for sign

section .text
global	_start

_start:

; prompt for input
mov	eax, 4
mov	ebx, 1
mov	edx, len_input_msg
mov	ecx, input_msg
int	80h

; read and store input
mov	eax, 3		; system call for sys_read (opcode 3)
mov	ebx, 2		; set ebx  for size_t count
mov	ecx, value	; store the value in 'value' variable
mov	edx, 5		; size of input to accept (5 bytes)
int	80h

; print the output message
mov	eax, 4
mov	ebx, 1
mov	edx, len_display_msg
mov	ecx, display_msg
int	80h

; print the output value
mov	eax, 4
mov	edx, 5
mov	ebx, 1
mov	ecx, value
int	80h

; exit code
mov	eax, 1
mov	ebx, 0
int	80h
```