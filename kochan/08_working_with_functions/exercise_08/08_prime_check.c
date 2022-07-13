/** 
 * 08_prime_check.c
 * 
 * Monday, July 11, 2022 09:41hrs
 * 
 * This program simply prints a 1 if
 * the argument to a function is prime,
 * and 0 otherwise.
 */
#include <stdio.h>
#include <stdbool.h>

// Function prototype.
int get_number(void);
bool is_prime(int value);

int main(void)
{
    int number = 0;

    number = get_number();

    if (is_prime(number))
        printf("%i is a prime number.\n", number);
    else
        printf("%i is not a prime number.\n", number);
}

/***************************
 * get_number()
 */
int get_number(void)
{
    int i = 0;

    do
    {
        printf("Enter a positive integer greater than 1: ");
        scanf("%i", &i);
    }
    while (i < 2);

    return i;
}

/****************************
 * is_prime()
 */
bool is_prime(int value)
{
    if (value == 2)
        return 1;
    
    else if (value % 2 != 0)
        return 1;

    return 0;
}