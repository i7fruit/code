/**
 * 12_array_of_pointers.c
 *
 * Monday, April 10, 2023 16:21hrs
 *
 * This program illustrates the use of
 * pointers to strings of text.
*/
#include <stdio.h>

int main(void)
{
    // Declares and initializes an array of character pointers
    char *days_of_the_week[] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };

    // Computes the size of the array of pointers
    int size = sizeof(days_of_the_week) / sizeof(days_of_the_week[0]);

    // Iterates through the array
    for (int i = 0; i < size; i++)
    {
        // Iterates through each character in each element
        for (char *ptr = days_of_the_week[i]; *ptr != '\0'; ptr++)
            printf("%c ", *ptr);

        putchar('\n');
    }

    return 0;
}