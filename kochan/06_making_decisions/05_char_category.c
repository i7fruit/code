/**
 * 05_char_category.c
 *
 * Tuesday, May 31 2022 17:11hrs
 *
 * This program classifies a character entered in
 * by a user as either an alphabet, a digit, or a
 * special character.
 */
#include <stdio.h>

int main(void)
{
    char character = ' ';

    printf("Enter an ASCII character: ");
    scanf("%c", &character);

    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
        printf("\"%c\" is an alphabetic character\n", character);
    else if (character >= '0' && character <= '9')
        printf("\"%c\" is a digit character\n", character);
    else
        printf("\"%c\" is a special character\n", character);

    return 0;
}