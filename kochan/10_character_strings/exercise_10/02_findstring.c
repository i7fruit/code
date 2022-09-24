/**
 * 02_findstring.c
 *
 * Saturday, September 17, 2022 06:37hrs
 *
 * This program tries to find the existence
 * of one string inside another. If a string
 * is found, it returns to the program
 * the starting index where the word begins,
 * otherwise it returns a -1 to indicate that
 * the word does not exist in the string.
 */
#include <stdio.h>

// Function prototypes
void get_text(char arr[]);

int main(void)
{
    const int size = 64;

    // Stores string of text to search
    char string[size] = "";

    // Store string of text to find in the first SOT
    char word[size] = "";

    printf("Enter a string of text\n");
    get_text(string);

    printf("Enter text to find: ");
    get_text(word);

    int index = find_string(string, word);

    if (index != -1)
        printf("Text exists at index %i.\n", index);

    else
        printf("Text does not exist.\n");

    return 0;
}

/*****************************************
 * The get_text() function prompts the user
 * for a string of text using the getchar()
 * function.
 */
void get_text(char arr[])
{
    int i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    arr[i] = '\0';
}

/******************************************************
 * find_string()
 */
int find_string(const char arr_0[], const char arr_1[])
{
    // Computes length of each string
    int a = sizeof(arr_0) / sizeof(arr_0[0]);
    int b = sizeof(arr_1) / sizeof(arr_1[0]);

    if (a > b)
    {
        
    }
}