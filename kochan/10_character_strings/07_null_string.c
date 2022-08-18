/**
 * 07_null_string.c
 *
 * Wednesday, August 17 2022 22:15hrs
 *
 * This program counts the number of words in a string
 * of text that spans several lines. The user taps the
 * Return/Enter key twice to indicat to the program that
 * data entry has ended.
 */
#include <stdio.h>
#include <stdbool.h>

void readline(char arr[], int limit);

int main(void)
{
    const short size = 64;

    bool is_reading = true;

    // Array to store string of text entered by the user
    char text[size];

    while (is_reading)
    {
        readline(text);
        // Checks for the null string
        if (text[0] == '\0')
            is_reading = false;
    }
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