#include <stdio.h>

/**
* main - Avoids an infinite loop
* Return: 0
*/
int main(void)
{
    int i;

    printf("Infinite loop incoming :(\n");

    i = 0;

    while (i < 10)
    {
        putchar('0' + i);  // Print the character representation of the digits 0-9
        i++;              // Increment i to avoid the infinite loop
    }

    printf("Infinite loop avoided! \\o/\n");

    return (0);
}

