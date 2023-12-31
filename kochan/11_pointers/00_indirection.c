/**
 * 00_indirection.c
 *
 * Friday, March 10 2023 21:51hrs
 *
 * This program illustrates the use
 * of pointers
 */
#include <stdio.h>

int main(void)
{
    int value = 10;

    // Declares a pointer to the variable, value
    int *ptr = &value;

    /**
     * Declares a variable and sets its value to the
     * value of what's contained in the variable
     * pointed to by the pointer variable ptr
     */
    int x = *ptr;

    printf("value = %i\nx = %i\n", *ptr, x);

    return 0;
}