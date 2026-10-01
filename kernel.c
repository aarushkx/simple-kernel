struct IDT_entry
{
    unsigned short offset_lowerbits;
    unsigned short selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short offset_higherbits;
};

void kmain(void)
{
    // Set the video memory address for text mode (at 0xB8000 for x86 VGA text mode)
    volatile unsigned char *video = (volatile unsigned char *)0xB8000;

    const char *message = "Hello from the kernel!";

    // Clear 80 x 25 text-mode cells
    for (unsigned int cell = 0; cell < 80 * 25; cell++)
    {
        video[cell * 2] = ' ';      // Character
        video[cell * 2 + 1] = 0x07; // Attribute byte (light gray)
    }

    // Write the message to the top-left corner of the screen
    for (unsigned int i = 0; message[i] != '\0'; i++)
    {
        video[i * 2] = message[i];
        video[i * 2 + 1] = 0x07;
    }
}