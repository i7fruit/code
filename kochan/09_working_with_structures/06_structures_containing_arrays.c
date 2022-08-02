/** 
 * 06_structures_containing_arrays.c
 * 
 * Tuesday, August 02 2022 00:46hrs
 * 
 * This program illustrates how a structure
 * can have as one of its members an array
 * of characters.
 */
#include <stdio.h>

// Structure definition
struct month
{
    int number_of_days;
    char name[4];
};

// Function prototype
void print_struct(const struct month value[]);

int main(void)
{
    // Declares an array of twelve month structures
    const struct month a_year[] =
    {
        {31, "Jan"}, {28, "Feb"}, {31, "Mar"}, {30, "Apr"}, {31, "May"}, {30, "Jun"},
        {31, "Jul"}, {31, "Aug"}, {30, "Sep"}, {31, "Oct"}, {30, "Nov"}, {31, "Dec"}
    };

    print_struct(a_year);

    return 0;
}

/********************************************************************
 * print_struct()
 */
void print_struct(const struct month value[])
{
    for (short i = 0; i < 12; i++)
        printf("%s has %i days\n", value[i].name, value[i].number_of_days);
}