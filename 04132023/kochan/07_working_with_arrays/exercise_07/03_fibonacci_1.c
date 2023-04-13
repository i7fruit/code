/** 
 * 03_fibonacci_1.c
 * 
 * Tuesday, June 14 2022, 17:26hrs
 * 
 * This program prints the fibonacci sequence
 * without using an array.
 */
#include <stdio.h>

int main(void)
{
    // Variables to track number of digits generated
    short size = 0, tracker = 0;

    do
    {
        printf("How many numbers do you want to generate? ");
        scanf("%hi", &size);
    }
    while (size < 1 || size > 70);

    // Subtracts two to account for the first two numbers printed
    size -= 2;

    // Prints first two numbers
    printf("0 1 ");

    // Prints subsequent numbers
    for (unsigned long i = 0, j = 1, k = 0; tracker < size; i = j, j = k)
    {
        k = i + j;
        printf("%lu ", k);
        tracker++;  
    }

    putchar('\n');

    return 0;
}