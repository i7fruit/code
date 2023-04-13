/**
 * 04_sign_function.c
 *
 * Tuesday, May 31 2022 17:02hrs
 *
 * This program prompts the user for
 * an integer and then prints a -1, 0,
 * or 1 if the integer is less than 0,
 * equal to 0, or greater than 0, respectively.
 */
#include <stdio.h>

#define ZERO 0

int main(void)
{
    int value = 0;

    printf("Enter an integer: ");
    scanf("%i", &value);

    if (value < ZERO)
        printf("-1\n");
    else if (value == ZERO)
        printf("0\n");
    else
        printf("+1\n");

    return 0;
}