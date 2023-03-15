/**
 * 04_constant_pointer.c
 *
 * Tuesday, March 14 2023 21:43hrs
 *
 * A pointer that always points to the same
 * address without being changed can be declared
 * as a constant pointer
*/
#include <stdio.h>

int main(void)
{
    char initial = 'm';
    char other_initial = 'n';

    // A constant pointer to the initial variable
    char *const ptr = &initial;

    printf("%c\n", initial);

    // This is not valid
    ptr = &other_initial;

    return 0;
}