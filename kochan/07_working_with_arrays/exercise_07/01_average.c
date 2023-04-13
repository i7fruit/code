/** 
 * 01_average.c
 * 
 * Tuesday, June 14 2022 00:12hrs
 * 
 * This program calculates the average
 * of ten floating-poing numbers
 */
#include <stdio.h>

int main(void)
{
    const short size = 10;
    float total, value;
    total = value = 0;

    for (short i = 0; i < size; i++)
    {
        printf("Enter a floating-point number: ");
        scanf("%f", &value);

        total += value;
    }

    // Computes average
    printf("Average is %.3f\n", total / size);

    return 0;
}