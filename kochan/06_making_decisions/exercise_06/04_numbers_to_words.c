/**
 * 04_numbers_to_words.c
 *
 * Saturday, June 04 2022 10:42hrs
 *
 * This program gets an integer from the user
 * and prints the digits out in words to the screen.
 */
#include <stdio.h>

int main(void)
{
    int value = 0;

    printf("Enter an integer: ");
    scanf("%i", &value);

    printf("%i\n", value);

    if (value == 0)
    {
        printf("Zero\n");
        return 0;
    }

    if (value < 0)
    {
        printf("Minus ");
        value = -(value);
    }

    // Makes a copy of the value so it is not altered
    int copy = value;

    // Counts digits in integer
    short count = 0;

    while (copy != 0)
    {
        short i = copy % 10;
        count++;
        copy /= 10;
    }

    // Computes divisor
    int divisor = 1;

    for (short i = 1; i < count; i++)
    {
        divisor *= 10;
    }

    while (count > 0)
    {
        if (value > 0 && count > 0)
        {
            short digit = value / divisor;
            // Resets the value
            value %= divisor;

            // Resets the divisor
            divisor /= 10;

            // Prints the digit in words
            switch (digit)
            {
                case 0:
                    printf("Zero ");
                    break;
                case 1:
                    printf("One ");
                    break;
                case 2:
                    printf("Two ");
                    break;
                case 3:
                    printf("Three ");
                    break;
                case 4:
                    printf("Four ");
                    break;
                case 5:
                    printf("Five ");
                    break;
                case 6:
                    printf("Six ");
                    break;
                case 7:
                    printf("Seven ");
                    break;
                case 8:
                    printf("Eight ");
                    break;
                case 9:
                    printf("Nine ");
                    break;
                default:
                    printf("Invalid entry\n");
                    break;
            }
            count--;
        }
        else
            break;
    }

    while (count > 0)
    {
        printf("Zero ");
        count--;
    }

    putchar('\n');

    return 0;
}

