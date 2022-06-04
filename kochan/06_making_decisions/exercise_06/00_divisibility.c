/** 
 * 00_divisibility.c
 * 
 * Wednesday, June 01 2022 12:41hrs
 * 
 * This program tests two integers to see
 * if the first integer is evenly divisible
 * by the second.
 */
#include <stdio.h>

int main(void)
{
    int value0, value1 = 0;

    printf("Enter two values to test: ");
    scanf("%i%i", &value0, &value1);

    // Tests if value0 is evenly divisible by value1
    if (value0 % value1 == 0)
        printf("%i is evenly divisible by %i\n", value0, value1);
    else
        printf("%i is NOT evenly divisible by %i\n", value0, value1);

    return 0;
}