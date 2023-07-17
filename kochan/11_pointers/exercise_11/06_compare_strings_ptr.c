/**
 * 06_compare_strings_ptr.c
 *
 * Saturday, July 08 2023 21:18hrs
 *
 * This program compares two strings
 * to determine if they're equal, or
 * if one comes before the other alphabetically
 *
 * This function uses pointers.
*/
#include <stdio.h>

// Function prototypes
char *get_text(const char *prompt, const int limit);

int main(void)
{
    // Size of the amount of characters to store in a string
    const int size = 64;

    // Pointer
    char *string0 = NULL;
    char *string1 = NULL;

    string0 = get_text("Enter first string: ");
    string1 = get_text("Enter second string: ");

    return 0;
}

/************************************************
 * The get_text() function uses a do_while loop and
 * the getchar() function to get text from a user
 * and returns a pointer to where that text is stored
 * in memory.
*/
char *get_text(const char *prompt, const int limit)
{
    // Subtracts 1 from limit to account for binary zero ('\0')
    limit--;

    printf("%s", prompt);
}