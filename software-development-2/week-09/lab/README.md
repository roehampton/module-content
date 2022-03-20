# Software Development 2 Lab 09 -- String Manipulation in Assembly

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab, we will extend our understanding of assembly by exploring string manipulation. String manipulation is a simple concept -- we iterate through a string and do something with each character.

## Getting Started with String Manipulation

A string is an array of characters. That is, a string is just a sequence of characters in memory. The first character has index zero, and the last character has an index of the length of the string minus one. For example, if we declare the string:

```c++
string name = "kevin";
```

In memory, this is represented as follows:

| **Index**     | 0    | 1    | 2    | 3    | 4    |
| ------------- | ---- | ---- | ---- | ---- | ---- |
| **Character** | k    | e    | v    | i    | n    |

To manipulate a string, we can use a `for` loop. For example:

```c++
for (int i = 0; i < name.length(); ++i)
{
    name[i] = 'X';
}
```

The above code will change all the characters into an `X`, so `name = "XXXXX"`. Although this is easy, it can be slightly faster to undertake such manipulation using assembly. For example, we can use the following code to convert our string to `YYYYY`.

```c++
auto data = str.c_str();
auto len = str.length();
__asm
{
    // Load length into ecx register
    // Used for loop counting
    mov ecx, len
    // Load the memory location into ebx register
    // Used to access correct element in array
    mov ebx, data
start_loop:
    // Set memory location ebx + ecx - 1 to 'Y'
    mov byte ptr[ebx + ecx - 1], 'Y'
    // If ecx > 1, decrement ecx and jump back to start_loop
    loop start_loop
}
```

> **What is `c_str()`?**
>
> At this point, you should be looking up documentation to determine what a function does. However, `c_str` gets the raw character array (the memory) used within the `string`.

> **What is `byte ptr[ebx + ecx - 1]`?**
>
> OK, this one is a bit trickier. Let us start with the value `ebx + ecx - 1`.
>
> - The `ebx` register contains the memory location in which the character array is stored. Let us say it is memory location 100, and `str = "kevin"`. Then:
>   - Location 100 = 'k`
>   - Location 101 = 'e'
>   - Location 102 = 'v'
>   - Location 103 = 'i'
>   - Location 104 = 'n'
> - The `ecx` register is our loop counter. It starts at the string length (for `str = "kevin"` this would mean `ecx` contains 5 initially). As the `loop` operation is executed, `ecx` is decremented.
> - Therefore, `ebx + ecx - 1` changes every loop:
>   - First pass = `ebx + ecx - 1 = 100 + 5 - 1 = 104`, which is the last memory location in the `string`.
>   - Second pass = `ebx + ecx - 1 = 100 + 4 - 1 = 103`, which is the second last memory location in the `string`.
>   - And so on.
>
> `byte ptr` means get the byte pointed to by the memory location. Remembering that `ebx + ecx - 1` will start at 104, and decrement each loop, we the first time we load the character `n` into the `al` register.
>
> **Read this again, and write out what is happening. It will help you.**

To compare to our simple assembly example above, below is what the C++ compiler will produce for our `for` loop version above.

```assembly
001A5215  mov         dword ptr [ebp-8],0  
001A521C  jmp         __$EncStackInitStart+2Bh (01A5227h)  
001A521E  mov         eax,dword ptr [ebp-8]  
001A5221  add         eax,1  
001A5224  mov         dword ptr [ebp-8],eax  
001A5227  mov         ecx,dword ptr [str]  
001A522A  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::length (01A1663h)  
001A522F  cmp         dword ptr [ebp-8],eax  
001A5232  jae         __$EncStackInitStart+49h (01A5245h)  
001A5234  mov         eax,dword ptr [ebp-8]  
001A5237  push        eax  
001A5238  mov         ecx,dword ptr [str]  
001A523B  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator[] (01A10D7h)  
001A5240  mov         byte ptr [eax],58h  
001A5243  jmp         __$EncStackInitStart+22h (01A521Eh)  
```

### Your Task

1. **Create a new project.**
2. **Use the code below.**
3. **Run the project, examining and stepping through the disassembly using the debugging tools.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void change_assembly(string& str)
{
    auto data = str.c_str();
    auto len = str.length();
    __asm
    {
        // Load length into ecx register
        // Used for loop counting
        mov ecx, len
        // Load the memory location into ebx register
        // Used to access correct element in array
        mov ebx, data
    start_loop:
        // Load 'Y' into memory location pointed to by ebx + ecx - 1
        mov byte ptr[ebx + ecx - 1], 'Y'
        // If ecx > 1, decrement ecx and jump back to start_loop
        loop start_loop
    }
}

void change(string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        str[i] = 'X';
    }
}

int main(int argc, char** argv)
{
    string test = "kevin";
    change(test);
    cout << test << endl;
    change_assembly(test);
    cout << test << endl;
    return 0;
}
```

## Converting a String to Lowercase

For our next example, we will use inline assembly to convert a `string` into lowercase. A few things to remember:

- Characters are represented via [ASCII code](https://en.wikipedia.org/wiki/ASCII). Each character has a number representation.
- In ASCII, characters `A` through `Z` are represented by the numbers 65 to 90, and `a` through `z` by the numbers 97 to 122. That means, `A - a = 32`.

So, to convert a character to a lowercase one, we have to do the following:

1. Check if the character is between `A` and `Z`.
   - We have to check if it is less than `A` first, then greater than `Z`. This is assembly remember.
2. If it is, we add 32 to the value and store back into memory.

The following code provides an example.

1. **Create a new project.**
2. **Enter the code below.**
3. **Run the program, examining what happens via the debugger.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void lowercase(string& str) 
{
    auto data = str.c_str();
    auto len = str.length();
    __asm
    {
        // Load length into ecx register
        // Used for loop counting
        mov ecx, len
        // Load the memory location into ebx register
        // Used to access correct element in array
        mov ebx, data
    start_loop:
        // Move byte in memory location ebx + exc -1 into al register
        mov al, byte ptr [ebx + ecx - 1]
        // Compare al register to A
        cmp al, 'A'
        // If al less than A jump to end_loop
        jl end_loop
        // Compare al register to Z
        cmp al, 'Z'
        // If al greater than Z jump to end_loop
        jg end_loop
        // If we are here, al contains letter between A and Z
        // Add 32 to al register to convert to lowercase value
        add al, 32
        // Move contents of al register back into memory location
        // pointed to by ebx + ecx - 1
        mov byte ptr [ebx + ecx - 1], al
     end_loop:
       	// Will jump back to start_loop if ecx > 1
        loop start_loop
    }
}

int main(int argc, char** argv)
{
    string test = "HelLO HOW are YOU?";
    lowercase(test);
    cout << test << endl;
    return 0;
}
```

## Counting Letters

We can also count the number of letters (`A` to `Z` and `a` to `z`) in a `string`. Our challenge here is that the characters 91 to 96 are not characters. Therefore we have to test if the value is between `A` and `Z` or between `a` and `z`. **Experiment with the code below.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int count_letters(string& str)
{
    auto data = str.c_str();
    auto len = str.length();
    int count = 0;
    __asm
    {
        // Load length into ecx register
        // Used for loop counting
        mov ecx, len
        // Load the memory location into ebx register
        // Used to access correct element in array
        mov ebx, data
    start_loop:
        // Move byte in memory location ebx + exc -1 into al register
        mov al, byte ptr[ebx + ecx - 1]
        // Compare value in al register to A
        cmp al, 'A'
        // If al is less than A then jump to end_loop
        jl end_loop
        // Compare value in al register to z
        cmp al, 'z'
        // If al is greater than Z then jump to end_loop
        jg end_loop
        // Now we need to check for values between Z and a
        // Compare value in al register to Z
        cmp al, 'Z'
        // If less than Z jump to increment
        jl increment
        // Compare value in al register to a
        cmp al, 'a'
        // If greater than a jump to increment
        jg increment
        // If we are here then not a letter
        // Jump to end_loop
        jmp end_loop
    increment:
        // If we are here, value must be a letter
       	// Move value of count into eax register
        mov eax, count
        // Increment eax register
        inc eax
        // Move value of eax register into count
        mov count, eax
    end_loop:
        // If ecx > 1 then loop
        loop start_loop
    }
    return count;
}

int main(int argc, char** argv)
{
    string test = "how many letters?";
    cout << count_letters(test) << endl;
    return 0;
}
```

## Converting String to Number

We can also use assembly to convert a `string` to a number. The code for this is below.

**As an exercise, we will not explain this code directly. Spend the time walking through the program with the debugger, and reading the code. This is the skillset you are developing and you need to practice.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int to_num(string& str)
{
    auto data = str.c_str();
    auto len = str.length();
    int num = 0;
    int factor = 1;
    __asm
    {
        // Load length into ecx register
        // Used for loop counting
        mov ecx, len
        // Load the memory location into ebx register
        // Used to access correct element in array
        mov ebx, data
        // Set edx to 0. This will be our sum
        mov edx, 0
    start_loop:
        // This will zero the eax register. Think about why.
        xor eax, eax
        // Move byte in memory location ebx + exc -1 into al register
        mov al, byte ptr[ebx + ecx - 1]
        // Compare al register to 0 character  
        cmp al, '0'
        // If less than, not a number character. Fail.
        jl fail
        // Compare al register to 9 character
        cmp al, '9'
        // If greater than, not a number character. Fail.
        jg fail
        // Know it is a number character. Subtract 48 to convert to value
        sub al, 48
        // Multiply by factor
        imul eax, factor
        // Add to edx register (working sum)
        add edx, eax
        // Check if end of loop
        cmp ecx, 1
        // If end of loop, jump to end
        je end_loop
        // Load factor value into eax register
        mov eax, factor
        // Multiply eax by 10
        imul eax, 10
        // Store value in eax register into factor
        mov factor, eax
    end_loop:
        // If ecx > 1 then decrement and jump to start_loop
        loop start_loop
        // Store working sum (edx register) into num
        mov num, edx
        // Jump to finish
        jmp finish
    fail:
        // Failed, load 0 into num
        mov num, 0
    finish:
    }
    return num;
}

int main(int argc, char** argv)
{
	string test = "123";
	cout << to_num(test);
	return 0;
}
```

