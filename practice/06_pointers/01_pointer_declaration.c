/**
 * 01_pointer_declaration.c
 *
 * Saturday, March 04 2023 16:40hrs
 *
 * This program illustrates the use of
 * pointers. Pointers store the memory
 * address of a variable.
*/
#include <stdio.h>

int main(void)
{
    int value = 50;

    // Delcares a pointer variable
    int *ptr = &value; // <--- Stores the memory address of the value variable

    // *ptr = value of what is located at memory location ptr
    // ptr = memory location ptr
    printf("%i is stored in memory location %p\n", *ptr, ptr);

    return 0;
}