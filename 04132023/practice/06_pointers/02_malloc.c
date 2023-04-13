/**
 * 02_malloc.c
 *
 * Monday, March 6 2023 21:19hrs
 *
 * Malloc is used to allocate heap memory
 * to the program and afterward returned to
 * the operating system using Free when the
 * program has completed execution
*/
#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <cs50.h> // For get_string
#include <ctype.h>
#include <string.h>

// Function prototypes
void get_text(char prompt[], char arr[]);

int main(void)
{
    int size = 64;

    char word[size];

    get_text("Enter text: ", word);

    /**
     * malloc returns the memory address of the number of bytes
     * for the string plus 1 for the nul zero
    */
    char *copy = malloc(strlen(word) + 1);

    // Checks to make sure malloc doesn't return null for insufficient memory
    if (copy == NULL)
    {
        printf("Not enough memory\n");
        return 1;
    }

    // Copies the value of word into memory location copy
    strcpy(copy, word);

    // Capitalizes the first word of *copy
    *(copy) = toupper(word[0]);

    printf("word = %s\ncopy = %s\n", word, copy);

    // Frees allocated memory
    free(copy);

    return 0;
}

/******************************************
 * get_text()
*/
void get_text(char prompt[], char arr[])
{
    printf("%s", prompt);

    int i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    arr[i] = '\0';
}