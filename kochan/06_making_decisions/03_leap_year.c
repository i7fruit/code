/**
 * 03_leap_year.c
 *
 * Tuesday, May 31 2022 00:30hrs
 *
 * Program usese compound relational tests
 * to determine if a year is a leap year or not.
 */
#include <stdio.h>

#define FOUR 4
#define HUNDRED 100
#define FOUR_HUNDRED 400

int main(void)
{
    short year = 0;

    do
    {
        printf("Enter a leap year between 1900 and 3000 inclusive: ");
        scanf("%hi", &year);
    }
    while (year < 1800 || year > 3000);

    if ((year % FOUR == 0 && year % HUNDRED != 0) || year % FOUR_HUNDRED == 0)
        printf("%i is a leap year\n", year);
    else
        printf("%i is NOT a leap year\n", year);

    return 0;
}