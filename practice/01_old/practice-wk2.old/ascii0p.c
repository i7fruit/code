/*
 * ascii0p.c
 *
 * This program prints the lowercase letters of the alphabet
 * in reverse order
 */
 
#include <stdio.h>

int main(void)
{
    // Iterate over the characters in reverse order
    
    for (int i = 122; i > 122 - 26; i--)
    {
        printf("%c is %i\n", (char)i, i);
    }
    return 0;
}