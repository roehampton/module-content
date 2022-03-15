# Software Development 2 Seminar 08 -- Reading Assembly Code

The aim of this seminar is to enable students to read assembly code. Start with the first example, and walk through it on the board, noting updated values and registers. Then let the students work through the other examples in small groups.

### Example 1

```c++
int main(int argc, char **argv)
{
    int x = 500;
    int y = 0;

    __asm
    {
        mov eax, x
        mov y, eax
    }

    return 0;
}
```

## Example 2

```c++
int main(int argc, char **argv)
{
	int x = 0;
	__asm
	{
		mov x, 500
	}
	return 0;
}
```

## Example 3

```c++
int main(int argc, char **argv)
{
	int x = 500;
	int y = 200;
	int z = 0;
	
	__asm
	{
		mov ecx, x
		add ecx, y
		mov z, ecx
	}
    	
	return 0;
}
```

## Example 4

For this example, come back to the whiteboard and walk through what is happening on the stack.

```c++
int main(int argc, char **argv)
{
	int x = 500;
	int y = 200;
	
	__asm
	{
		push x
		push y
		pop x
		pop y
	}
    
	return 0;
}
```

## Example 5

For this final example, also do on the board and demonstrate how the stack is set up for the function call. Note that the call will be `sub(200, 500)` as the stack is setup in reverse.

```c++
int sub(int x, int y)
{
	return x - y;
}

int main(int argc, char **argv)
{
	int result = 0;
	
	__asm
	{
		push 500
		push 200
		call sub
		mov result, eax
		pop ebx
		pop ebx
	}   
	
	return 0;
}
```

