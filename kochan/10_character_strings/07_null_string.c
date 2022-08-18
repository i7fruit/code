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

int main(void)
{
    const short size = 64;

    bool is_reading = true;

    // Array to store string of text entered by the user
    char text[size];

    while (is_reading)
    {
        readline(text)
    }
}