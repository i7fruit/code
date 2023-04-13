/**
 * 2_table_of_factorials.c
 *
 * Thursday, April 14 2022 10:10hrs
 *
 * This program prints a table of ten factorials
 */
#include <stdio.h>

int main(void)
{
    printf("Table of factorials from 0 through 10\n");
    printf("--------------------------------------\n");
    printf(" n        n!\n");

    long factorial = 1;

    for (short i = 0; i <= 10; i++)
    {
        if (i > 1)
        {
            factorial *= i;
            printf("%2hi %8li\n", i, factorial);
        }

        else
        {
            printf("%2hi %8li\n", i, factorial);
        }
    }

    return 0;
}