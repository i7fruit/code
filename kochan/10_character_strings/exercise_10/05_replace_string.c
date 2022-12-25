/**
 * 05_replace_string.c
 *
 * Saturday, December 24, 2022 21:48hrs
 *
 * This program scans through a string of
 * characters to identify a substring to
 * be replaced, and replaces that substring
 * with a new string of characters.
 */
#include <stdio.h>

// Function prototypes
void get_text(char arr[]);

int main(void)
{
    const int size = 64;

    char text[size] = "";
    char str_to_delete[size] = "";
    char str_to_insert[size] = "";

    // Prompts the user for input
    get_text(text);

    printf("%s\n", text);

    return 0;
}

/***********************************************
 * The get_text() function uses the getchar() function
 * to get a string of text from the user and stores
 * it in an array using a do-while loop
 */
void get_text(char arr[])
{
    int i = -1;

    do
    {
        arr[i++] =  getchar();
    }
    while (arr[i] != '\n');

    arr[i] = '\0';
}