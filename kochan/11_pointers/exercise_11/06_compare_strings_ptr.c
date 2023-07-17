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
#include <string.h>

// Global variables
const int size = 64;

// Function prototypes
char *get_text(const char *prompt, const int limit);
int compare_strings(const char *str0, const char *str1);

int main(void)
{
    // Pointer to memory location to store string
    char *string0 = NULL;
    char *string1 = NULL;

    string0 = get_text("Enter first string: ", size);
    string1 = get_text("Enter second string: ", size);

    // Checks to make sure pointer doesn't return a null value
    if (!string0)
    {
        fprintf(stderr, "Insufficient memory\n");
        return 1;
    }

    // Checks to make sure pointer doesn't return a null value
    if (!string1)
    {
        // Returns heap memory for first string if pointer for storing second string returns null
        if (string0)
        {
            free(string0);
            return 1;
        }
    }

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
    // Temporary array to store text entered by user.
    char temp[size];

    printf("%s", prompt);

    int i = -1;

    do
    {
        temp[++i] = getchar();
    }
    while (temp[i] != '\n' && i <= (limit - 1));

    // Terminates string
    temp[i] = '\0';

    // Calculates length of string entered
    int length = strlen(temp);

    // Allocates memory for string
    char *nu = malloc(sizeof(char) * length);
    if (!nu)
        return (char *)0;

    // Copies string from tempoary array to alloted location
    strcpy(nu, temp);

    return nu;
}

/*************************************************************
 * The compare_string() function compares two strings to see
 * if they're both equal. The function returns 0 if they're
 * equal, -1 if the first string comes before the second, and
 * +1 if it comes after the second
*/
int compare_strings(const char *str0, const char *str1)
{
    int i = 0;

    while ((*(str0 + i) == *(str1 + i)) && *(str0 + i) != '\0')
        i++;

    // Checks if they're both equal
    if (*(str0 + i) == *(str1 + i))
        return 0;

    if (*(str0 + i) < *(str1 + i))
        return -1;

    return 1;
}