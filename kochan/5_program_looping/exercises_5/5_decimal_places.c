/**
 * 5_decimal_places.c
 *
 * Friday, April 15 2022 00:49hrs
 *
 * In printf statements, if a dot ( . ) is placed before the space specifier,
 * it formats the value to decimal places specified by the specifier value
 */
#include <stdio.h>

int main(void)
{
    int dollars = 0, cents = 0;

    // Prompts the user for input twice
    for (short i = 0; i < 2; i++)
    {
        printf("Enter dollars: ");
        scanf("%i", &dollars);

        printf("Enter cents: ");
        scanf("%i", &cents);

        // Prints value to two significant figures and two decimal places
        printf("Amount is: $%.2i.%.2ic\n", dollars, cents);

        // If user entered $1, and 4c, the final printf would be $01.04c
    }

    return 0;
}