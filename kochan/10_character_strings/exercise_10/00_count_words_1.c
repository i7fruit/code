/**
 * 00_count_words_1.c
 *
 * Tuesday, September 13 2022 21:29hrs
 *
 * This program counts the number of words
 * in a line of text entered by a user.
 *
 * It also identifies integers separated by
 * commas
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function prototypes
void readline(char arr[], int limit);
int count_words(char array[]);

int main(void)
{
    const short size = 64;
    char string[size];

    printf("Enter a string of text\n");
    readline(string, size - 1);

    int word_count = count_words(string);

    printf("The string contains %i words.\n", word_count);

    return 0;
}

/****************************************************
 * The readline() function takes a character array
 * to store the string captured from standard input,
 * and a second argument of an integer value representing
 * the number of characters the user is limited to storing
 * in the array. This way the user does not exceed the buffer.
 */
void readline(char arr[], int limit)
{
    short i = -1;

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n' && i != limit);

    // Overwrites '\n' with '\0'
    arr[i] = '\0';
}

/*******************************************************
 * The count_words() function iterates through an array
 * of characters by marking the start of a word when it
 * first encounters an alphabetic character, and marks its
 * end when it encounters the first non-alphabetic character.
 * It keeps track of this by updating a counter variable, and
 * repeats the process until the end of the array is reached.
 */
int count_words(char array[])
{
    int count = 0;
    bool is_counting = false;

    for (short i = 0; array[i] != '\0'; i++)
    {
        if ((isalpha(array[i]) || isdigit(array[i])) && !is_counting)
        {
            is_counting = true;
            count++;
        }

        else if (!isalpha(array[i]) && !isdigit(array[i]) && array[i] != '\'' && array[i] != ',')
            is_counting = false;
    }

    return count;
}