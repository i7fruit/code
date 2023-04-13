/**
 * 1_triangular_number_formular.c
 *
 * Tuesday, April 12 2022 19:39hrs
 *
 * This program uses the formular
 * n (n + 1) / 2
 * to calculate the triangular number
 * of every fifth number between 5 and 50
 */
#include <stdio.h>

int main(void)
{
    unsigned rows = 50, triangular_number = 1;

    printf("Every 5th triangular number between 5 and 50\n");
    printf("-------------------------------------------\n");
    printf("Number     Triangular number\n");

    for (short i = 5; i <= rows; i += 5)
    {
        printf("%2u ", i);
        triangular_number = i * (i + 1) / 2;
        printf("%15u\n", triangular_number);
    }

    return 0;
}