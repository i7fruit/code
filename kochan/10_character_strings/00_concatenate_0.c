/**
 * 00_concatenate_0.c
 *
 * Tuesday, August 09 2022 23:32hrs
 *
 * This program concatenates two strings
 * to form a new string of characters.
 */
#include <stdio.h>

// Function prototypes
void print_array(char arr[], int n);
void concatenate(char str2[], const char str0[], int n, const char str1[], int m);

int main(void)
{
    const int size_0 = 5, size_1 = 7;

    const char string_0[] = {'H', 'e', 'l', 'l', 'o'};
    const char string_1[] = {' ', 'w', 'o', 'r', 'l', 'd', '!'};
    char string_2[size_0 + size_1];

    // Concatenate's string
    concatenate(string_2, string_0, size_0, string_1, size_1);

    // Prints contents of the newly concatenated string
    print_array(string_2, (size_0 + size_1));

    putchar('\n');

    return 0;
}

/********************************************************************
 * print_array()
 */
void print_array(char arr[], int n)
{
    for (short i = 0; i < n; i++)
        printf("%c", arr[i]);
}

/********************************************************************
 * concatenate()
 */
void concatenate(char str2[], const char str0[], int n, const char str1[], int m)
{
    int j = 0;

    // Writes str0 to str2
    for (short i = 0; i < n; i++, j++)
        str2[j] = str0[i];

    // Writes str1 to str2
    for (short k = 0; k < m; k++, j++)
        str2[j] = str1[k];
}