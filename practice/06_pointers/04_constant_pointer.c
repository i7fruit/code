/**
 * 04_constant_pointer.c
 *
 * Tuesday, March 14 2023 21:43hrs
 *
 * A pointer that always points to the same
 * variable without being changed can be declared
 * as a constant pointer
*/
#include <stdio.h>

int main(void)
{
    char initial = 'm';
    char other_initial = 'n';

    // A constant pointer to a character
    char *const ptr = &initial; // <--- ptr will always point to initial

    printf("%c\n", initial);

    // This is not valid
    ptr = &other_initial;  // <--- cannot point ptr to a different variable

    return 0;
}