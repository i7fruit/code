/**
 * 05_count_words_2.c
 *
 * Thursday, July 06 2023 23:26hrs
 *
 * This program counts the number of words
 * in a line of text entered by a user.
 *
 * It also identifies integers separated by
 * commas
 */
/**
 * 07_null_string.c
 *
 * Wednesday, August 17 2022 22:15hrs
 *
 * This program counts the number of words in a string
 * of text that spans several lines. The user taps the
 * Return/Enter key twice to indicate to the program that
 * data entry has ended.
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void readline(char arr[], int limit);
int count_words(char array[]);

int main(void)
{
    const short size = 64;
    int count = 0;

    bool is_reading = true;

    // Array to store string of text entered by the user
    char text[size];

    printf("Enter text\n\n");

    while (is_reading)
    {
        readline(text, size - 1);

        // Checks for the null string
        if (text[0] == '\0')
            is_reading = false;

        else
            // Counts words in each line
            count += count_words(text);
    }

    printf("Count = %i\n", count);

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
        if (isalpha(array[i]) && !is_counting)
        {
            is_counting = true;
            count++;
        }

        else if (!isalpha(array[i]))
            is_counting = false;
    }

    return count;
}