/** 
 * 12_recursive_functions.c
 * 
 * Tuesday, June 28 2022 19:52hrs
 * 
 * This program illustrates the use of
 * a recursive function to calculate the
 * factorial of a number given by the user.
 */
#include <stdio.h>

// Function prototypes
int get_integer(void);
unsigned long factorial(int i);

int main(void)
{
    int value = 0;

    value = get_integer();

    printf("%li\n", factorial(value));

    return 0;
}

/******************************
 * get_integer()
 */
int get_integer(void)
{
    auto int i = 0;

    do
    {
        printf("Enter a positive integer: ");
        scanf("%i", &i);
    } 
    while (i < 0);

    return i;
}

/************************************
 * factorial()
 */
unsigned long factorial(int i)
{
    if (i == 0 || i == 1)
        return 1;

    else
    {
        return i * factorial(i - 1);
    }
}