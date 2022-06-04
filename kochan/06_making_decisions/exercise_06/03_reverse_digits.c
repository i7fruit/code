/** 
 * 03_reverse_digits.c
 * 
 * Friday, June 03 2022 10:32hrs
 * 
 * This program takes an integer input
 * from the user and reverses the digits.
 * If the integer is a negative number, it
 * prints a minus sign at the end of the reversed
 * digit.
 */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int value = 0;
    bool is_negative = false;

    printf("Enter an integer: ");
    scanf("%i", &value);

    if (value < 0)
    {
        is_negative = true;
        value = -(value);
    }

    while (value != 0)
    {
        printf("%i", value % 10);
        value /= 10;
    }

    if (is_negative)
        printf("-\n");
    else
        putchar('\n');

    return 0;

}