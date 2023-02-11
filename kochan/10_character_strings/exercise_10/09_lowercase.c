/**
 * 08_uppercase.c
 *
 * Saturday, February 11, 2023 00:05hrs
 *
 * This program converts an uppercase letter
 * into its lowercase form.
*/
#include <stdio.h>

// Function prototypes
char get_character(void);

int main(void)
{
    char character = '@';

    printf("Enter an uppercase character: ");
    character = get_character();

    // Converts the lowercase character to uppercase
    character = character - 'A' + 'a';

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
    while (c < 'A' || c > 'Z');

    return c;
}