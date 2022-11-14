/**
 * 03_remove_string.c
 *
 * Wednesday, November 02 2022 16:15hrs
 *
 * This function extracts a string of text from
 * another and prints to standard output the contents
 * of the array where the string of text was extracted from.
 */
#include <stdio.h>
#include <string.h>

// Function prototypes
void get_text(char arr[]);
void remove_string(char arr[], int index, int count);

int main(void)
{
    const short size = 64;

    // Stores string of text
    char text[size] = "";

    // Stores starting index of extraction, and number of characters to extract
    int start = 0, number_of_characters = 0;

    printf("Enter a string of text below\n");
    get_text(text);

    printf("With the first character position being 0, what position in the text do \
you want to start the extraction: ");
    scanf("%i", &start);

    printf("How many characters do you want to extract? ");
    scanf("%i", &number_of_characters);

    remove_string(text, start, number_of_characters);

    printf("%s\n", text);

    return 0;
}

/*************************************************************************/
void get_text(char arr[])
{
    int i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    // Overwrites the newline character with a null zero
    arr[i] = '\0';
}

/***************************************************************************
 * The remove_string() function takes as arguments an array that stores a string
 * of text, and two integers that store values for the starting index of a string
 * to be extracted from the array, and the number of characters that string will contain.
*/
void remove_string(char arr[], int index, int count)
{
    // Computes length of string to extract from
    int size = strlen(arr);
    int j = index + count - 1;

    if (j < size)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = 
        }
    }
}