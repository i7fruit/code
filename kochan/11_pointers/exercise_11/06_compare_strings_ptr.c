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
#include <stdlib.h>

// Function prototypes
char *get_text(const char *prompt, const int limit);

int main(void)
{


    // Pointer
    char *string0 = NULL;
    char *string1 = NULL;

    string0 = get_text("Enter first string: ", (size - 1));
    string1 = get_text("Enter second string: ", (size - 1));

    printf("%s\n%s\n", string0, string1);

    free(string0);
    free(string1);

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
    // Size of the amount of characters to store in a string
    const int size = 64;

    // Temporary array to store text entered by user.
    char temp[size];

    int i = -1;

    do
    {
        temp[++i] = getchar();
    }
    while (temp[i] != '\n' && i <= limit);

    // Allocates memory for string
    char *nu = malloc(sizeof(char) * limit);
    if (!nu)
    {
        fprintf(stderr, "Insufficient memory\n");
        return (char *)0;
    }

    printf("%s", prompt);

    return nu;
}