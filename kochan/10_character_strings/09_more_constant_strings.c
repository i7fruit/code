/**
 * 09_more_constant_strings.c
 *
 * Monday, September 05, 2022 23:31hrs
 *
 * More on constant strings.
 */
#include <stdio.h>

int main(void)
{
    // The backslash character can be used to continue string on a separate line
    printf("If this is too long, \
continue on a new line.\n");

    // The C compiler automatically concatenate adjacent strings
    printf("This " "will" " be " "one string of text.\n");

    return 0;
}