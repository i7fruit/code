/**
 * 10_int_to_string.c
 *
 * Saturday, February 11, 2023 15:48hrs
 *
 * This program takes an integer input from
 * the user and converts it to a string.
*/
#include <stdio.h>

// Function prototype

int main(void)
{
    unsigned long number = 0;

    number = get_integer();

    printf("%lu\n", number);

    return 0;
}

/***************************************
 * get_integer()
*/
unsigned long get_integer(void)
{
    unsigned long i = -1;

    scan("%lu", i);

    return i;
}