# Computer Systems Lab 5 - Simple Assembly Programs

The aim of this lab is to write some simple assembly programs and compile them to run on the computer. For this lab session we will use the Linux Azure Labs machine.

## Your First Assembly Program

1. **Create a new subdirectory in the computer-systems folder for lab06 and change into the directory.**
2. **Use nano to enter the following file `hello.asm`**.

```assembly
global main                             ; must be declared for final compilation

SECTION .data                           ; data for the program
    msg db "Hello, world!", 0xa         ; string to be printed
    len equ $ - msg                     ; length of the string

SECTION .text

main:                                   ; tells compiler where the program starts
    mov edx, len                        ; load message length into edx register
    mov ecx, msg                        ; load memory location of message into ecx register
    mov ebx, 1                          ; sets where to write message (stdout)
    mov eax, 4                          ; set system call for performing a write
    int 0x80                            ; call operating system kernel to perform operation
    mov eax, 1                          ; set system call for exit
    int 0x80                            ; call operating system kernel to perform operation
```

3. **Save the program and exit nano.**
4. **To build and run the program perform the following on the commands**:

```bash
student@pc:~/computer-systems/lab06$ nasm -f elf32 hello.asm
student@pc:~/computer-systems/lab06$ gcc -m32 hello.o
student@pc:~/computer-systems/lab06$ ./a.out
Hello, world!
```

We’ve rushed through quite a bit here, so let us take a step back and look at what we’ve done.

### Building an Assembly Program

When we worked with C, the compiler hid most of the detail from us. However, the following steps occurred under the hood:

1. Run the preprocessor which creates the final code file by replacing lines such as `#include <stdio.h>` with the file contents requested.
2. Converts the code file into assembly.
3. Runs the assembler on the assembly file to create an object file.
4. Links the object file with other libraries to allow execution.

Here we are performing steps 3 and 4. We use [**NASM**](https://www.nasm.us/) as an assembler. The `-f elf32` tells the assembler what output to produce - *an Executable and Linkable Format* for a 32-bit machine. 32-bit is easier to explain and manage as 64-bit machines can be optimised for performance. The assembler creates an object file, `hello.o`, which we can ask GCC to build for us. The `-m32` option is required as we want a 32-bit executable.

You don’t have to worry about fully understanding these steps as you can reuse them. You may come across these again later in your studies depending which degree you are taking.

### Assembly Code

There is quite a bit of code to explain, so let us start at the top:

- `global` is used by NASM to declare externally visible values. As the program requires a place to start running from, we declare `main` as global. `main` is just a label we put in the program.
- `SECTION` is used to define different sections of the code. This allows the assembler to recognise different parts of the program. We have two sections: `.text` is for the code, and `.data` is for the data (variables).
- We have used two operations in this program:
  - `mov` moves data into a location from another location. The format is `mov destination, source`.
  - `int` is an interrupt, where we ask the operating system to do something for us.
- In the `.data` section we declare any values, such as our message, `msg`, to print and its length, `len`.
  - `db` means *Declare Bytes*. The NASM assembler will convert the text into bytes for us. Look up the ASCII table to learn what `0xa` is.
  - `equ` declares a constant value. `$` represents the current memory position in the assembly, so `$ - msg`, where `msg` is the memory address where our string was declared, tells us how long the message is in bytes.

Most of the details of these operations can always be looked up if you forget them. These are simple operations that can be reused to perform these printing and program exit operations.

### Exercises

1. Change the output to *I wrote this code* and execute the program.
2. Change the `len` variable to 7 at line 5 (i.e., change `mov edx, len` to `mov edx, 7`). What happened?
3. Change line 5 to have the exact number of characters in *I wrote this code*. What happened this time?

## Using C Code from Assembly

As we’ve already seen, performing some actions in assembly require multiple operations. To save us some work, and cheat a little, we will use C from our assembly code. Particularly, we are trying to overcome the problems of outputting numbers in assembly.

We’ve already used C so we won’t cover the details of the C functions, but we will discuss how we interact with these functions.

For our first application, let us prompt the user for their name and say hello to them. This code is as follows:

```assembly
global main
extern printf                   ; ask to include printf function

SECTION .data
    msg db "Hello, <name>",0xa,0x0

SECTION .text

main:
    push msg                    ; push memory location of prompt onto the stack
    call printf                 ; call printf
    mov eax, 1                  ; set system call for exit
    int 0x80                    ; call operating system
```

We are doing a few new things in this example:

- Our string `msg` ends with `0x0` which is a null-terminator. This is used to indicate the end of the string to `printf`. We don’t need the length of the string anymore.
- We have asked to use the `printf` function using `extern printf`.
- We have set the parameters for `printf` using `push`. The computer operates something called the **stack** which is used for storing temporary values and parameters for function calls. Here, we put `msg` on the stack. If we wrote this in C we would write `printf(msg);`
- We use `call` to call a function, in this case `printf`.

Compile and run this program as shown above:

```bash
student@pc:~/computer-systems/lab06$ nasm -f elf32 name.asm
student@pc:~/computer-systems/lab06$ gcc -m32 name.o
student@pc:~/computer-systems/lab06$ ./a.out
Hello, <name>
```

**Modify the program so it prints out your name instead of `<name>`**.

## Adding Two Numbers

The following assembly code will add two numbers in memory and output the result using `printf`.

```assembly
global main
extern printf

SECTION .data
    A dd 20
    B dd 31
    msg db "20 + 31 = %d",0xa,0x0

SECTION .text

main:
    mov eax, [A]        ; load A into eax register
    add eax, [B]        ; add B to eax register
    push eax            ; push value in eax register onto the stack
    push msg            ; push memory location of msg onto the stack
    call printf         ; call printf
    mov eax, 1          ; set system call for exit
    int 0x80            ; call operating system
```

There are some additional items of note here:

- We use `dd` to declare 32-bit integer values for `A` and `B`. Remember, `db` is to declare bytes - 8-bit values.

- To move values into a register we surround the variable with `[ ]`. If we did not do this, the assembler would think we meant the memory location of `A` or `B` rather than the data.

- Notice the order we push values onto the stack:

  1. `eax` which is equal to `A + B`.
  2. `msg`.

  This is equivalent to `printf(msg, eax);` (note the reverse order). If we actually wrote this in C we would just write `printf("20 + 30 = %d\n", A + B);`.

**Compile and run this program as normal.**

## Subtracting Two Numbers

Subtracting two numbers is similar to adding.

```assembly
global main
extern printf

SECTION .data
    A dd 45
    B dd 23
    msg db "45 - 23 = %d",0xa,0x0

SECTION .text

main:
    mov eax, [A]
    sub eax, [B]
    push eax
    push msg
    call printf
    mov eax, 1
    int 0x80
```

**Compile and run this program.**

## Decision Making

Let us now use branching logic within our assembly program. We will again find which is the largest number given two inputs.

```assembly
global main
extern printf

SECTION .data
    A dd 280
    B dd 250
    msg db "%d is largest.",0xa,0x0

SECTION .text

main:
    mov eax, [A]                ; load A into eax register
    mov ebx, [B]                ; load B into ebx register
    cmp eax, ebx                ; compare eax and ebx
    jg A_GREATER                ; jump if eax is greater to A_GREATER
    push ebx                    ; push ebx onto the stack
    jmp PRINT                   ; jump to PRINT
A_GREATER:
    push eax                    ; push eax onto the stack
PRINT:
    push msg                    ; push message onto the stack
    call printf                 ; call printf
    mov eax, 1                  ; set system call for exit
    int 0x80                    ; call the operating system
```

This is different to how we approach the problem with the *Little Man Computer.* LMC has limited operations. In standard assembly we can compare two values using `cmp`. This sets various flag values on the CPU based on the outcome of that comparison. One of these flags is if the first value is greater than the second value in the `cmp`. We can jump (branch) if it is using `jg` which means *jump if greater.* There are various jump conditions we can use. We can also use an unconditional `jmp` as we do here.

**Compile and run the program as normal.**

### Exercises

1. Make `B` greater than `A` and test the program again.
2. Remove the `jmp PRINT` operation and explain what happens.

## Creating a Countdown

Now we know how to perform branching we can recreate the countdown timer in assembly.

```assembly
global main
extern printf

SECTION .data
    A dd 10
    msg db "%d",0xa,0x0

SECTION .text

main:
    mov ebx, [A]
LOOP:
    push ebx
    push msg
    call printf
    pop ecx             ; clear msg from the stack
    pop ecx             ; clear ebx from the stack
    dec ebx             ; decrement ebx
    jz END
    jmp LOOP
END:
    push ebx
    push msg
    call printf
    mov eax, 1
    int 0x80
```

Notice we now clean up the stack using `pop`. Before we were not writing good code as we exited straight after `printf` was called. Now we are clearing the stack properly.

We use another two new operations in this example:

- `dec` will decrement (subtract 1) from the value in a register.
- `jz` jumps if the last operation lead to a zero value.

1. **Compile and run this program.**
2. **Modify the program so it counts down by 2 rather than 1.**

## Multiplication of Two Numbers

Thankfully, there is a multiplication operation we can use rather than performing multiple adds.

```assembly
global main
extern printf

SECTION .data
    A dd 4
    B dd 4
    msg db "4 * 4 = %d",0xa,0x0

SECTION .text

main:
    mov eax, [A]
    mov ebx, [B]
    mul ebx             ; multiply eax by value in ebx. Stored in eax
    push eax
    push msg
    call printf
    mov eax, 1
    int 0x80
```

`mul` only works on one operand. Which ever value is in `eax` is multiplied by this value.

### Exercise

Can you find and use the division operator in NASM assembly?
