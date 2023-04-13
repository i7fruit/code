/**
 * 08_pointers_as_args.c
 *
 * Thursday, March 16 2023 23:54hrs
 *
 * This program illustrates the use of
 * pointers as arguments to functions. The
 * pointers are passed by value ie they are
 * copied to the function so any changes to
 * the argument does not affect the pointer
 * that was passed to the function. However,
 * the value that that pointer points to can
 * be changed.
*/
#include <stdio.h>

// Function prototype
void mult_by_two(short *pointer);

int main(void)
{
    short value = 40;
    short *ptr = &value;

    printf("%hi x 2 = ", *ptr);

    mult_by_two(ptr);

    printf("%hi\n", *ptr);

    return 0;
}

/********************************************
 * The mult_by_two() function takes a pointer
 * argument that points to an integer. It changes
 * the value in the location pointed to by the pointer
 * by multiplying the value by two.
*/
void mult_by_two(short *pointer)
{
    *pointer *= 2;
}