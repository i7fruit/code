/**
 * 0_absolute.c
 *
 * Monday, May 30 2022 22:30hrs
 *
 * This program prints out the absolute
 * value of an integer to standard output
 */
#include <stdio.h>

int main(void)
{
    int value = 0;

    printf("Enter an integer: ");
    scanf("%i", &value);

    printf("The absolute value of %i", value);

    // Negates value if negative
    if (value < 0)
        value = -(value);

printf(" is %i\n", value);

return 0;
}