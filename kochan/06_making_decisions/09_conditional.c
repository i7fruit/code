/**
 * 09_conditional.c
 *
 * Tuesday, May 31 2022 23:26hrs
 *
 * This program illustrates the use of
 * the ternary (conditional) operator ?: in C.
 */
#include <stdio.h>

#define ZERO 0

int main(void)
{
    short value = 0, sign = 0;

    do
    {
        printf("Enter a value between -20 and +20: ");
        scanf("%hi", &value);
    }
    while (value < -20 || value > 20);

    sign = value < ZERO ? -1 : (value > ZERO ? 1 : 0);

    printf("Sign is %i\n", sign);

    // Another use of the conditional operator
    unsigned short balls = 0;

    printf("How many balls do you have? ");
    scanf("%hu", &balls);

    printf("You have %hu ball%s\n", balls, (balls == 1? ".":"s."));

    return 0;
}