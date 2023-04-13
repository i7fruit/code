/**
 * 8_fix_negative.c
 *
 * Sunday, May 29 01:08hrs
 *
 * The commented-out program will print
 * a negative sign before each reversed
 * digit. The program below it fixes this
 * by detecting when a user has entered a
 * negative digit and negates it, then prints
 * a minus sign. If the user enters a positive
 * integer, the program reserves the digits without
 * first printing a minus sign
 */

#include <stdio.h>

// int main(void)
// {
//     short number = 0, right_digit = 0;

//     printf("Enter your number.\n");
//     scanf ("%i", &number);

//     while (number != 0)
//     {
//         right_digit = number % 10;
//         printf("%i", right_digit);
//         number = number / 10;
//     }

//     printf ("\n");
    
//     return 0;
// }

int main(void)
{
    short number = 0, right_digit = 0;

    printf("Enter your number.\n");
    scanf ("%hi", &number);

    _Bool is_negative = 0;

    if (number < 0)
    {
        is_negative = 1;
        number = -(number);
        printf("-");
    }

    while (number != 0)
    {
        right_digit = number % 10;
        printf("%i", right_digit);
        number = number / 10;
    }

    printf ("\n");
    
    return 0;
}