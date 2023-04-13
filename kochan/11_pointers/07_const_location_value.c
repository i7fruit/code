/**
 * 07_const_location_value.c
 *
 * Wednesday, March 15 2023 23:18hrs
 *
 * This program illustrates how to declare a pointer
 * when the location it points to is never going to change,
 * and the value at that location will not change either.
*/
#include <stdio.h>

int main(void)
{
    char initial = 'c';

    // Declares a constant pointer to a constant value
    const char *const ptr = &initial;

    printf("%c\n", *ptr);

    // Cannot change value through pointer
    *ptr = 'd';

    // Cannot change location
    char letter = 's';
    ptr = &letter; // <---- Will cause error

    printf("%c\n", *ptr);

    return 0;
}