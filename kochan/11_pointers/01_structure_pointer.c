/**
 * 01_structure_pointer.c
 *
 * Saturday, March 11 2023 11:58hrs
 *
 * This program illustrates how the pointer indirection operator
 * is used to get at the value of a structure variable pointed to
 * by a structure pointer.
*/
#include <stdio.h>

// Structure definition
typedef struct
{
    int month;
    int day;
    int year;
}
date;

int main(void)
{
    // Declares a struct date variable
    date today = {10, 0, 0};

    // Declares a structure pointer and sets it to the address of today
    date *date_ptr = &today;

    // Initializes the today struct date variable
    /**
     * (*date...) is used rather than *(date..) because
     * the structure member reference operator (.) has a higher preference
     * than the pointer indirection operator (*)
     *
     * Alternatively, one can use the pointer to structure member reference
     * operator (->) to overcome this. Thus (*date_ptr).month would be written
     * as date_ptr->month
     */
    (*date_ptr).month = 3;
    (*date_ptr).day = 11;
    (*date_ptr).year = 2023;

    printf("The date is %.2i.%.2i.%.2i\n", today.month, (*date_ptr).day, ((*date_ptr).year)% 100);

    return 0;
}