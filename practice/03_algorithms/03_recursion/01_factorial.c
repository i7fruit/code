/**
 * 01_factorial.c
 *
 * Friday, February 17 2023 23:30hrs
 *
 * The factorial of any number is the product
 * of all the numbers from 1 up to that number.
 * This program uses a recursive function to
 * compute the factorial of any given number
*/
#include <stdio.h>

// Function prototypes
int get_integer(char arr[]);

int main(void)
{
    int number = 0;

    number = get_integer("Number: ");

    return 0;
}

/****************************************
 * get_integer() prompts the user for an integer
*/
int get_integer(char arr[])
{
    int i = 0;

    do
    {
        printf("%s\n", arr);
        scanf("%i", &i);
    }
    while (i < 1 || i > 20);

    return i;
}