/**
 * 10_int_to_string.c
 *
 * Saturday, February 11, 2023 15:48hrs
 *
 * This program takes an integer input from
 * the user and converts it to a string.
*/
#include <stdio.h>

// Function prototypes
unsigned long get_integer(void);

int main(void)
{
    unsigned long number = 0;

    printf("Enter an integer to convert to a string: ");
    number = get_integer();

    printf("%lu\n", number);

    return 0;
}

/***************************************
 * get_integer()
*/
unsigned long get_integer(void)
{
    long i = 0;

    do
    {
        scanf("%lu", &i);
    }
    while (i < 0);

    return i;
}