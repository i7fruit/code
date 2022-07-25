/** 
 * 00_date_structure.c
 * 
 * Sunday, July 24 2022 21:11hrs
 * 
 * This illustrates how structures are
 * created and used in C.
 */
#include <stdio.h>

int main(void)
{
    // Struct definition
    struct date
    {
        int month;
        int day;
        int year;
    };

    // Struct declaration
    struct date today;

    // Assigns values to the variable struct date today
    today.month = 7, today.day = 24, today.year = 2002;

    printf("The date is %i.%i.%.2i\n", today.month, today.day, today.year % 100);

    return 0;
}