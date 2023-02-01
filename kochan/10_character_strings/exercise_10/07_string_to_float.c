/**
 * 07_string_to_float.c
 *
 * Saturday, January 28, 2023 13:17hrs
 *
 * This program converts character digits
 * into floating point numbers.
 */

#include <stdio.h>

int main(void)
{
    const int size = 64;
    char text[size];

    // Prompts the user for a floating-point number
    get_text(text);

    printf("%s\n", text);

    return 0;
}

/*********************************************
 * get_text()
*/
