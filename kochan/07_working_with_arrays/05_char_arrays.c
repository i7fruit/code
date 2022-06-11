/**
 * 05_char_arrays.c
 * 
 * Saturday, June 11 2022 10:58hrs
 * 
 * This program illustrates how character arrays are initiated
 */
#include <stdio.h>

#define SIZE 12

int main(void)
{
    char word[] = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!'};

    for (short i = 0; i < SIZE; i++)
        printf("%c", word[i]);

    putchar('\n');

    return 0;
}