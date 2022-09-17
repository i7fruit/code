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

int main(void)
{
    const int size = 64;

    // Stores string of text to search
    char string[size] = "";
    // Store string of text to find in the first SOT
    char word[size] = "";

    printf("Enter a string of text\n");
    get_text(string);
}

/************************************************
 * get_text()
 */
void get_text(const char arr[])
{
    int i = -1;
}