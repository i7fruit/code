/**
 * array_a0.c
 *
 * Saturday, September 15 2018 16:51hrs
 *
 * This program just declares and populates
 * a regular array of a predetermined size,
 * with non-repetitive values
 */

#include <stdio.h>

int main(void)
{
    const short size = 3;
    short array[size];

    // Prompts the user for input
    for (short i = 0, j = 0; i < size; i++, j = 0)
    {
        printf("Enter value %hi: ", i);
        scanf("%hi", &array[i]);

        while (j < i)
        {
            if (array[j] == array[i])
            {
                i--;
                break;
            }

            j++;
        }
    }

    // Prints the array
    for (short i = 0; i < size; i++)
        printf("%hi ", array[i]);

    putchar('\n');

    return 0;
}