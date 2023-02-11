/**
 * 08_uppercase.c
 *
 * Friday, February 03, 2023 23:43hrs
 *
 * This program converts a lowercase letter
 * into its uppercase form.
*/
#include <stdio.h>

int main(void)
{
    char character = '@';

    character = uppercase(character);

    printf("%c\n", character);
}