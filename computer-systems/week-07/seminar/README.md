# Computer Systems Seminar 7 - Further Assembly

1. What are the two ways we can implement loops in assembly?
2. What is the register used to control the number of iterations in a loop?

The following code is used in the next few questions.

```assembly
something:
    mov eax, something
    jump eax
```

3. Add comments to each line of the code above.
4. What does the name `something` signify in the code?
5. What is the outcome of this code?
6. What type of control instruction is the program using?

The following code is used in the next few questions.

```assembly
    mov eax, '5'
    sub eax, '0'
    mov ecx, '4'
    sub ecx, '0'
label1:
    call procedure_test
    loop label1
    
procedure_test:
    add eax, '2'
    ret
```

7. Add comments to each line of the code above.
8. What is the control statement used in the code?
9. How many times will `procedure_test` be called?
10. What will be the final value of `eax`?
11. What is the role of the `ret` instruction?