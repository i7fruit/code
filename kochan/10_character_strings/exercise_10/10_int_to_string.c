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
long long get_integer(void);

int main(void)
{
    long long number = 0;

    printf("Enter an integer to convert to a string: ");
    number = get_integer();

    printf("%lli\n", number);

    return 0;
}

/***************************************
 * get_integer()
*/
long long get_integer(void)
{
    long long i = 0;

    do
    {
        scanf("%lli", &i);
    }
    while (i < 0);

    return i;
}