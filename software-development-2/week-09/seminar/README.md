# Software Development 2 Seminar 09 -- String Manipulation and Assembly

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<script src="https://cdn.jsdelivr.net/npm/mermaid/dist/mermaid.min.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this seminar, the idea is to have students work through string manipulation examples, producing flowcharts, and mapping to the appropriate assembly code. Students should be working in groups on this material.

## Changing All Characters

**Task 1** -- have the students produce the flowchart for changing each character in a string to a Y. An example is:

<div class="mermaid">
flowchart TD;
    id1(READ string)
    id2(LET index = LENGTH OF string - 1)
    id3(SET string[index] = 'Y')
    id4{index > 1}
    id5(SET index = index - 1)
    id6((Stop))
    id1 --> id2 --> id3 --> id4 --> |Yes| id5 --> id3
    id4 --> |No| id6
</div>

The relevant assembly code is as follows:

```c++
auto data = str.c_str();
auto len = str.length();
__asm
{
    mov ecx, len
    mov ebx, data
start_loop:
    mov byte ptr[ebx + ecx - 1], 'Y'
    loop start_loop
}
```

**Walkthrough the code on the whiteboard. Show the values of the registers and memory changing as you work through the code.**

## Changing a String to Lowercase

**Task 2** -- now have the students define the flowchart for changing a string to lowercase.

Next, have students walk through the following code. Let them take the lead in this, possibly as groups.

```c++
auto data = str.c_str();
auto len = str.length();
__asm
{
    mov ecx, len
    mov ebx, data
start_loop:
    mov al, byte ptr [ebx + ecx - 1]
    cmp al, 'A'
    jl end_loop
    cmp al, 'Z'
    jg end_loop
    add al, 32
    mov byte ptr [ebx + ecx - 1], al
end_loop:
    loop start_loop
}
```

**Now ask students to modify the flowchart and code to work for uppercase.**

## Further Examples

The following are further examples to work through. Use the same process as you do.

### Counting Letters

How do we count the letters (i.e., characters A through Z)? Assembly code is:

```c++
auto data = str.c_str();
auto len = str.length();
int count = 0;
__asm
{
    mov ecx, len
    mov ebx, data
start_loop:
    mov al, byte ptr[ebx + ecx - 1]
    cmp al, 'A'
    jl end_loop
    cmp al, 'z'
    jg end_loop
    cmp al, 'Z'
    jl increment
    cmp al, 'a'
    jg increment
    jmp end_loop
increment:
    mov eax, count
    inc eax
    mov count, eax
end_loop:
    loop start_loop
}
```

### Converting a String to a Number

How do we convert a string to the `int` equivalent? Assembly code is:

```c++
auto data = str.c_str();
auto len = str.length();
int num = 0;
int factor = 1;
__asm
{
    mov ecx, len
    mov ebx, data
    mov edx, 0
start_loop:
    xor eax, eax
    mov al, byte ptr[ebx + ecx - 1]
    cmp al, '0'
    jl fail
    cmp al, '9'
    jg fail
    sub al, 48
    imul eax, factor
    add edx, eax
    cmp ecx, 1
    je end_loop
    mov eax, factor
    imul eax, 10
    mov factor, eax
end_loop:
    loop start_loop
    mov num, edx
    jmp finish
fail:
    mov num, 0
finish:
}
```

