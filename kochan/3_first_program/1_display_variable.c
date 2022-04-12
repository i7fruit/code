/**
 * 1_display_variable.c
 * Monday, January 10 2022 20:39hrs
 * 
 * Displays variables to the screen
 */
#include <stdio.h>

int main(void)
{
    short value0 = 30, value1 = 9;
    short z = value0 + value1;

    printf("%hi + %hi = %i\n", value0, value1, value0 + value1);

    return 0;
}