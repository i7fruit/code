/**
 * 08_uppercase.c
 *
 * Friday, February 10, 2023 23:43hrs
 *
 * This program converts a lowercase letter
 * into its uppercase form.
*/
#include <stdio.h>

// Function prototypes
char get_character(char arr[]);

int main(void)
{
    char character = '@';

    character = get_character("Enter a lowercase character: ");

    // Converts the lowercase character to uppercase
    character = character - 'a' + 'A';

    printf("%c\n", character);

    return 0;
}

/*******************************************************
 * get_character()
*/
char get_character(char arr[])
{
    char c = '@';

    do
    {
        printf("%s\n", arr);

        // Saves character into variable
        c = getchar();

        // Takes the newline character in the buffer
        getchar();
    }
    while (c < 'a' || c > 'z');

    return c;
}