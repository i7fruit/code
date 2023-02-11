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
void int_to_string(long long i);

int main(void)
{
    long long number = 0;
    short size = 64;

    number = get_integer();

    char string[size];

    int_to_string(string);

    printf("%s\n", string);

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
        printf("Enter an integer: ");
        scanf("%lli", &i);
    }
    while (i < 0);

    return i;
}

/*****************************************
 * int_to_string()
*/
void int_to_string(long long i)
{
    // Computes number of digits in the integer
    long long copy = i;

    short count = 0;

    while (copy != 0)
    {
        copy /= 10;
        count++;
    }

    printf("size is %hi\n", count);
}