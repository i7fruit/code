/**
 * 02_concatenate_1.c
 *
 * Wednesday, August 11 2022 00:33hrs
 *
 * This program concatenates two strings
 * to form a new string of characters.
 */
#include <stdio.h>

// Function prototypes
void print_array(char arr[]);
void concatenate(char str2[], const char str0[], const char str1[]);

int main(void)
{
    const short size = 32;

    // Strings are automatically null zero terminated
    const char string_0[] = "Hello";
    const char string_1[] = " Earth!";
    char string_2[size];

    // Concatenate's string
    concatenate(string_2, string_0, string_1);

    // Prints contents of the newly concatenated string
    print_array(string_2);

    putchar('\n');

    return 0;
}

/********************************************************************
 * print_array()
 */
void print_array(char arr[])
{
    for (short i = 0; arr[i] != '\0'; i++)
        printf("%c", arr[i]);
}

/********************************************************************
 * concatenate()
 */
void concatenate(char str2[], const char str0[], const char str1[])
{
    int j = 0;

    // Writes str0 to str2
    for (short i = 0; str0[i] != '\0'; i++, j++)
        str2[j] = str0[i];

    // Writes str1 to str2
    for (short k = 0; str1[k] != '\0'; k++, j++)
        str2[j] = str1[k];
}