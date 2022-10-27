# Computer Systems Lab 6 - Further Assembly Code

In this lab we will extend our work on assembly programming by examining assembly operations, how we address memory locations, making subroutines, and working with memory. The aim of this lab is for you to develop more complex assembly code programs so you have a better understanding of how the computer operates at a low level.

## Assembly Operations

Assembly instructions can be generalised into three categories: **arithmetical**, **logical**, and **conditional**. The other type of operation is `mov` which moves data around the computer.

### Arithmetic Operations

The below table lists common arithmetic operations.

| **Operation** | **Operands**          | **Description**                                              | **Examples**     |
| ------------- | --------------------- | ------------------------------------------------------------ | ---------------- |
| `inc`         | *destination*         | Increments (adds 1) to the destination.                      | `inc eax`        |
| `dec`         | *destination*         | Decrements (subtracts 1) from the destination.               | `dec [count]`    |
| `add`         | *destination, source* | Adds source to the destination.                              | `add [count], 1` |
| `sub`         | *destination, source* | Subtracts source from the destination.                       | `sub eax, [A]`   |
| `mul`         | *source*              | Multiplies value in `eax` register by the source.            | `mul ebx`        |
| `div`         | *source*              | Divides value in `eax` register by the source. Result is in `eax` and remainder in `edx`. | `div 4`          |

There is more detail to these operations which you can find [here](https://www.tutorialspoint.com/assembly_programming/assembly_arithmetic_instructions.htm). Let us write a simple program that uses some of these operations. We will right an application that checks if a number is divisible by three and five. If it is divisible by neither, then the number is printed. If it is only divisible by three, we print `fizz`. If it is only divisible by five we print `buzz`. And if it is divisible by both we print `fizzbuzz`. The code is below:

```assembly
global main
extern printf

SECTION .data
    printnum db "%d",0xa,0x0
    printfizz db "fizz",0xa,0x0
    printbuzz db "buzz",0xa,0x0
    printfizzbuzz db "fizzbuzz",0xa,0x0
    number dd 15

SECTION .text

main:
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; place number in eax
    mov ebx, 3          ; mov 3 into ebx
    div ebx             ; divide eax by ebx (3)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jz FIZZ             ; if 0 jump to FIZZ
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; place number in eax
    mov ebx, 5          ; mov 5 into ebx
    div ebx             ; divide eax by ebx (5)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jz BUZZ             ; if 0 jump to buzz
PRINTNUM:               ; number is not divisible by either
    mov eax, [number]   ; place number in eax
    push eax            ; push eax onto the stack
    push printnum       ; push printnum message onto the stack
    call printf         ; call printf
    jmp END             ; jump to end
FIZZ:                   ; number divisible by 3
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; place number in eax
    mov ebx, 5          ; mov 5 into ebx
    div ebx             ; divide eax by ebx (5)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jz FIZZBUZZ         ; if 0 jump to FIZZBUZZ
    push printfizz      ; push printfizz message onto the stack
    call printf         ; call printf
    jmp END             ; jump to end
BUZZ:                   ; number is only divisible by 5
    push printbuzz      ; push printbuzz message onto the stack
    call printf         ; call printf
    jmp END             ; jump to end
FIZZBUZZ:               ; number divisible by 3 and 5
    push printfizzbuzz  ; push printfizzbuzz message onto the stack
    call printf         ; call printf
    jmp END             ; jump to end
END:
    mov eax, 1          ; set system exit call
    int 0x80            ; call operating system
```

#### Exercises

1. Experiment with different numbers to see that the program works as expected.
2. Can you draw a state machine for this program?

### Logical Operations

The table below lists the common logical operations.

| **Operation** | **Operands**          | **Description**                                              | **Examples**          |
| ------------- | --------------------- | ------------------------------------------------------------ | --------------------- |
| `and`         | *destination, source* | Performs a logical *AND* operation on each bit of the destination against the source. | `and eax, ebx`        |
| `or`          | *destination, source* | Performs a logical *OR* operation on each bit of the destination against the source. | `or ecx, [D]`         |
| `xor`         | *destination, source* | Performs a logical *XOR* operation on each bit of the destination against the source. | `xor eax, 0xFFFFFFFF` |
| `test`        | *destination, source* | The same as `and` but does not store the result in *destination.* It just sets jump flags. | `test al, 0x1`        |
| `not`         | *destination*         | Inverts each bit of the destination.                         | `not eax`             |

For a test application, let us write a program that prints whether a number is even or odd, and also prints its negative form.

> To test if a number is even we only need to know if it is divisible by two. As we are working in binary, all even numbers will not use the **least-significant-digit**; that is the right-most binary digit representing 1. If this digit is 0, then the number is even. We can test this using an AND operation.
>
> For example, five is 0101 in binary and six is 0110. Let us perform an and against 0001 on these numbers:
>
> 0101 `and` 0001 = 0001, and therefore the number is odd (not even)
>
> 0110 `and` 0001 = 0000, and therefore the number is even.

To convert a number to its negative version we will just apply two’s compliment - invert the digits and add one. The code is below:

```assembly
global main
extern printf

SECTION .data
    odd db "%d is odd",0xa,0x0
    even db "%d is even",0xa,0x0
    negative db "%d times -1 is %d",0xa,0x0
    num dd 29753

SECTION .text

main:
    mov eax, [num]      ; mov num into eax
    mov ebx, 1          ; mov 1 into ebx
    and eax, ebx        ; logical and on eax and ebx
    jz EVEN             ; if 0 then num is even
ODD:                    ; number is odd
    mov eax, [num]      ; mov num into eax
    push eax            ; push eax onto stack
    push odd            ; push odd message onto stack
    call printf         ; call printf
    pop ebx             ; clear stack
    pop ebx
    jmp NEGATIVE        ; jump to negative
EVEN:                   ; number is even
    mov eax, [num]      ; mov num into eax
    push eax            ; push eax onto stack
    push even           ; push even message onto stack
    call printf         ; call printf
    pop ebx             ; clear stack
    pop ebx
    jmp NEGATIVE        ; jump to negative
NEGATIVE:
    mov eax, [num]      ; mov num into eax
    not eax             ; invert bits of eax
    inc eax             ; add 1 to eax
    push eax            ; push eax (negative num) onto stack
    mov eax, [num]      ; mov num into eax
    push eax            ; push eax onto stack
    push negative       ; push negative message onto stack
    call printf         ; call printf
    mov eax, 1          ; set call for system exit
    int 0x80            ; call operating system
```

**Enter and compile this program. Change the value of `num` to check that it works. It will also work for negative numbers.**

#### Exercise

Change this program so it uses `test` rather than `and`. Can you work out which lines of code you can remove now that you are using `test`? Hint - remember that `test` does not change the *destination* value.

### Conditional Operations

Conditional operations are our jumps. NASM assembly provides a few different jumps based on the outcome of operations and comparisons. Some of these are listed in the following table, as well as the `cmp` operation.

| **Operation** | **Operands**          | **Description**                                              | **Example**    |
| ------------- | --------------------- | ------------------------------------------------------------ | -------------- |
| `cmp`         | *destination, source* | Compares the destination and source setting flags inside the processor based on the outcome of the comparison. | `cmp eax, ebx` |
| `jmp`         | *label*               | Jumps to the label in the program.                           | `jmp LOOP`     |
| `je`          | *label*               | Jumps if the compared values were equal.                     | `je LOOP`      |
| `jz`          | *label*               | Jumps if the last operation led to zero result.              | `jz LOOP`      |
| `jg`          | *label*               | Jumps if the *destination* was greater than *source* in the comparison. | `jg LOOP`      |
| `jge`         | *label*               | Jumps if the *destination* was greater than or equal to *source* in the comparison. | `jge LOOP`     |
| `jl`          | *label*               | Jumps if the *destination* was less than the *source* in the comparison. | `jl LOOP`      |

There are further jump types you can find out about [here](https://www.tutorialspoint.com/assembly_programming/assembly_conditions.htm). For example, there are `jne` for *jump when not equal* and `jnl` for *jump not less than*. We have already used jumps extensively so we won’t revisit these here.

## Subroutines

So far, we’ve used jumps to move around our program, although we have called C functions as well. We can define our own subroutines which we can call in assembly. This is done using labels and two special operations: `call` and `ret`. `call` calls the subroutine by jumping to the label, whereas `ret` returns back to where we called the subroutine.

Let us look at how we can update our `fizzbuzz` application from earlier to use subroutines.

```assembly

global main
extern printf

SECTION .data
    printnum db "%d",0x0
    printfizz db "fizz",0x0
    printbuzz db "buzz",0x0
    endprint db 0xa,0x0
    number dd 15
    flag db 0

SECTION .text

main:
    call fizz
    call buzz
    call print
    call end

print:
    mov eax, [flag]     ; move flag into eax
    cmp eax, 0          ; check if flag is set
    jne END_PRINTNUM    ; if flag is set don't print
    mov eax, [number]   ; move number into eax
    push eax            ; push eax onto the stack
    push printnum       ; push printnum message onto the stack
    call printf         ; call printf
    pop ebx
    pop ebx
END_PRINTNUM:
    ret                 ; return

fizz:
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; move number into eax
    mov ebx, 3          ; move 3 into ebx
    div ebx             ; divide eax by ebx (3)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jnz END_FIZZ        ; if not 0 then end call
    inc byte [flag]     ; add 1 to flag - divisible by 3
    push printfizz      ; push printfizz message onto the stack
    call printf         ; call printf
    pop ebx             ; clear stack
END_FIZZ:
    ret                 ; return

buzz:
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; move number into eax
    mov ebx, 5          ; move 5 into ebx
    div ebx             ; divide eax by ebx (5)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jnz END_BUZZ        ; if not 0 then end call
    inc byte [flag]     ; add 1 to flag - divisible by 5
    push printbuzz      ; push printbuzz message onto the stack
    call printf         ; call printf
    pop ebx             ; clear stack
END_BUZZ:
    ret                 ; return

end:
    push endprint       ; end print
    call printf         ; call printf
    mov eax, 1          ; set system exit call
    int 0x80            ; call operating system
    ret
```

There are a few changes we’ve made to this version of the program:

- Notice that the strings (e.g., `printfizz`) no longer have `0xa` for a line feed. This is so we can print `fizz` and `buzz` before outputting a new line. However, this also means we need an `endprint` to complete the output.
- We use `flag` to check if either `fizz` or `buzz` has been printed. This saves us checking again when we call `print`.
- Staying with the flag, we use `inc byte [flag]` to increment the data in memory rather than moving it into a register and back. We have to say `byte` because the compiler doesn’t know exactly how much memory area we want to increment at `flag` - to it everything is just memory.

**Enter and compile this program as before, and test different numbers to check if it works.**

### Loops

Although this version of FizzBuzz is perhaps more complex, it does let us extend it easily to use loops. `loop` is a special command in NASM that allows us to perform looping easily by keeping a count in the `ecx` register. The `loop` operator will automatically decrement `ecx` for us, although we’ll want to store it on the stack between operations. Let us extend our FizzBuzz program to use looping.

```assembly
global main
extern printf

SECTION .data
    printnum db "%d",0x0
    printfizz db "fizz",0x0
    printbuzz db "buzz",0x0
    printtest db "test",0xa,0x0
    endprint db 0xa,0x0
    number dd 1
    flag db 0

SECTION .text

main:
    mov ecx, 20         ; set counter to 20
ll:
    push ecx            ; store ecx on the stack
    call fizz
    call buzz
    call print
    push endprint
    call printf
    pop ebx
    inc DWORD [number]  ; increment number
    mov byte [flag], 0  ; clear flag
    pop ecx             ; retrieve counter from the stack
    loop ll
    call end

print:
    mov eax, [flag]     ; move flag into eax
    cmp eax, 0          ; check if flag is set
    jne END_PRINTNUM    ; if flag is set don't print
    mov eax, [number]   ; move number into eax
    push eax            ; push eax onto the stack
    push printnum       ; push printnum message onto the stack
    call printf         ; call printf
    pop ebx             ; clear stack
    pop ebx             ; clear stack
END_PRINTNUM:
    ret                 ; return

fizz:
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; move number into eax
    mov ebx, 3          ; move 3 into ebx
    div ebx             ; divide eax by ebx (3)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jnz END_FIZZ        ; if not 0 then end call
    inc byte [flag]     ; set flag to 1 - divisible by 3
    push printfizz      ; push printfizz message onto the stack
    call printf         ; call printf
    pop ebx             ; clear stack
END_FIZZ:
    ret                 ; return

buzz:
    mov edx, 0          ; set edx to 0
    mov eax, [number]   ; move number into eax
    mov ebx, 5          ; move 5 into ebx
    div ebx             ; divide eax by ebx (5)
    cmp edx, 0          ; check if edx is 0 (no remainder)
    jnz END_BUZZ        ; if not 0 then end call
    inc byte [flag]     ; set flag to 1 - divisible by 5
    push printbuzz      ; push printbuzz message onto the stack
    call printf         ; call printf
    pop ebx             ; clear stack
END_BUZZ:
    ret                 ; return

end:
    mov eax, 1          ; set system exit call
    int 0x80            ; call operating system
    ret
```

All we’ve done in this example is modify the `main` section to use looping. Otherwise it is the same as our previous example.

**Enter and compile this program. Modify the counter value to see that the program works correctly for values up to 500.**

## Memory

We’ve been working with memory throughout our work with assembly, although on a basic level. Let us  look at three different types of memory we can work with:

- **Constants**.
- **Variables**.
- **Uninitialised space.**

### Constants

Values defined with `equ` are constants. They take the following form:

```assembly
CONSTANT_NAME equ expression
```

Constants are very basic in assembly, and they are just placeholders for values and therefore only really basic types such as numbers can be used. For example:

```assembly
LENGTH equ 50
WIDTH equ 20
AREA equ LENGTH * WIDTH
```

### Variables

We have extensively used variables throughout our work on assembly. A variable is declared as follows:

```assembly
VARIABLE_NAME size initial
```

The following table defines the data sizes we can define in NASM assembly:

| **Size directive** | **Purpose**        | **Storage space**        |
| ------------------ | ------------------ | ------------------------ |
| `db`               | Define byte        | allocates 1 byte value.  |
| `dw`               | Define word        | allocates 2 byte value.  |
| `dd`               | Define double word | allocates 4 byte value.  |
| `dq`               | Define quad word   | allocates 8 byte value.  |
| `dt`               | Define ten bytes   | allocates 10 byte value. |

### Space Allocation

One area we haven’t examined is allocating space for future values. We do this in another section of our assembly program called `.bss`. The format of such an allocation is as follows:

```assembly
VARIABLE_NAME size amount
```

`size` refers to the data size of the values allocated, and `amount` is the number of values of this type. `size` can be the following:

| **Size directive** | **Purpose**         | **Storage space**       |
| ------------------ | ------------------- | ----------------------- |
| `resb`             | Reserve byte        | reserves 1 byte value.  |
| `resw`             | Reserve word        | reserves 2 byte value.  |
| `resd`             | Reserve double word | reserves 4 byte value.  |
| `resq`             | Reserve quad word   | reserves 8 byte value.  |
| `rest`             | Reserve ten bytes   | reserves 10 byte value. |

The following program will prompt the user for their name and then print out `Hello, <name>`.

```assembly
global main
extern printf

SECTION .data
    prompt db "Enter your name: ",0xa,0x0
    hello db "Hello, %s",0xa,0x0

SECTION .bss
    name resb 40

SECTION .text

main:
    push prompt         ; push prompt onto stack
    call printf         ; call printf
    pop ebx             ; clear stack
    mov eax, 3          ; set system call for read input
    mov ebx, 1          ; set input to standard input
    mov ecx, name       ; set read location to name
    mov edx, 40         ; set length of read to 40 characters
    int 0x80            ; call operating system
    push name           ; push name on stack
    push hello          ; push hello message on stack
    call printf         ; call printf
    mov eax, 1          ; set system call for exit
    int 0x80            ; call operating system
```

**Enter and compile this program. What happens when you enter a name greater than 40 characters?**

## Addressing Memory Locations

To finish our work on assembly, we will examine how we address different areas of memory in NASM assembly.

### Register Addressing

Register addressing is where we use the registers (e.g., `eax`, `ebx`, `ecx`, etc.) for our operations. We’ve been using whole registers in these tutorials, but you can use parts of a register (such as `ax`). See [here](https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm) for further discussion on registers.

### Immediate Addressing

This addressing is when we use values in our operations (e.g., `mov eax, 1`). In this addressing mode, the first operand defines the size of the operation. If the first operand is memory, then we need to tell the assembler what we mean (e.g., `mov byte [count], 1`).

### Memory Addressing

When we access memory we have a few different options:

- **Direct memory addressing** where we access memory locations as defined in the `.data` or `.bss` sections. For example, `push name` pushes the address of the `name` variable onto the stack. **It does not push the value of `name` onto the stack.** For example, if *Kevin* is the name, and it is stored in location 256, then `push name` pushes 256 onto the stack, not *Kevin.*
- **Direct offset addressing** accesses offsets from our memory locations. For example, if `name` is *Kevin*, and I want to access the third letter (*v*), I can do so with `name[2]`. The first letter is accessed as 0.
- **Indirect memory addressing** is where we access values within memory. For this we use square brackets, e.g., `mov eax, [number]`. If we did `mov eax, number` we would get the memory location of number stored in `eax`, not the value.

## Summary

Through these two labs you have covered the majority of the common operations that the processor can perform. Other operations are normally specialised for particular functions or particular hardware. But, fundamentally, they come down to these basic elements. **This is all the computer can really do.** Between your study of number representation, logic circuits, state machines, von Neumann machines, and assembly you know most of how a simple computer operates. Well done!

## Further Study

It is recommend you try the [*TutorialsPoint*](https://www.tutorialspoint.com/assembly_programming/index.htm) NASM tutorial to further study assembly programming. It goes into far more detail than we can present across these labs.
