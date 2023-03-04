/**
 * 00_address_of.c
 *
 * Saturday, February 04 2023 16:19hrs
 *
 * This program illustrates the use of
 * the address-of operator (&) to print
 * the hexadecimal memory address of a
 * variable in memory.
*/
#include <stdio.h>

int main(void)
{
    int value = 50;

    // Prints the memory address of the variable value
    printf("%i is located at memory address %p\n", value, &value);

    return 0;
}