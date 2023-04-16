/**
 * 14_pointer_to_function.c
 *
 * Friday, April 14 2023 20:18hrs
 *
 * This program illustrates the use of pointers
 * to functions.
*/
#include <stdio.h>

// Function prototypes
int get_values(int num, int mult);

int main(void)
{
    int value = 2;
    int multiplier = 7;

    // Creates a pointer to the get_values function
    int (*fnptr) (int, int);

    int result = fnptr;

    //int result = get_values(value, multiplier);

    printf("%i\n", result);

    return 0;
}

/**********************************************
 * get_values()
*/
int get_values(int num, int mult)
{
    return num * mult;
}