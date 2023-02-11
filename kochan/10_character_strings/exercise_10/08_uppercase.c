/**
 * 08_uppercase.c
 *
 * Friday, February 03, 2023 23:43hrs
 *
 * This program converts a lowercase letter
 * into its uppercase form.
*/
#include <stdio.h>

// Function prototypes
char get_character(void);

int main(void)
{
    char character = '@';

    printf("Enter a lowercase character: ");
    character = get_character();

    // Converts the lowercase character to uppercase
    character = character - 'a' + 'A';

    printf("%c\n", character);

    return 0;
}

/*******************************************************
 * get_character()
*/
char get_character(void)
{
    char c = '@';

    do
    {
        // Saves character into variable
        c = getchar();

        // Takes the newline character in the buffer
        getchar();
    }
    while (c < 'a' || c > 'z');

    return c;
}