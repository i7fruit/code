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

    for (int i = 0; i < 7; i++)
        printf("%s\n", days_of_the_week[i]);

    return 0;
}