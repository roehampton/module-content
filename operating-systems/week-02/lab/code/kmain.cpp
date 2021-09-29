extern "C" void kmain()
{
    // Define colour of text (white)
    const short colour = 0x0F00;
    // Define message to print
    const char* hello = "We're now in C++!";
    // Pointer to VGA text memory
    short* vga = (short*)0xb8000;
    // Print out each character one at a time
    for (int i = 0; i < 16; ++i)
    {
        // Set text into VGA memory
        vga[i + 80] = colour | hello[i];
    }
}