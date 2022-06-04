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

    // Counts digits in integer
    short count = 0;
    int copy = value;
    while (copy != 0)
    {
        short i = copy % 10;
        count++;
        copy /= 10;
    }

    printf("count = %i\n", count);

    return 0;
}

    