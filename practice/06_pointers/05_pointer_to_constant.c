/**
 * 05_pointer_to_constant.c
 *
 * Tuesday, March 14 2023 21:54hrs
 *
 * If the value will not change through
 * the pointer variable, the pointer can be
 * declared as pointing to a constant variable
 */
#include <stdio.h>

int main(void)
{
    char initial = 'm';

    const char *ptr = &initial;

    // The value can be changed through the variable like so...
    initial = 'n';

    // ...but cannot be changed through the pointer like so
    *ptr = 'o'; // <--- This will throw an error

    return 0;
}