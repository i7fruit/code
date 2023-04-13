/**
 * 4_left_justify.c
 *
 * Friday, April 15 2022 00:41hrs
 *
 * Program to calculate the 200th triangular number
 * Introduction of the for statement
 * It uses the minus sign in front of the number before
 * the printf conversion character to left-justify what's
 * printed to the screen by the printf function
 */
#include <stdio.h>
int main(void)
{
    int n, triangularNumber;
    triangularNumber = 0;

    for (n = 1; n <= 200; n = n + 1)
    {
        triangularNumber = triangularNumber + n;

        // Left-justifies digits on the right colume
        printf("%3i %-5i\n", n, triangularNumber);
    }

    // printf("The 200th triangular number is %i\n", triangularNumber);

    return 0;
}
