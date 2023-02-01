/**
 * 07_string_to_float.c
 *
 * Saturday, January 28, 2023 13:17hrs
 *
 * This program converts character digits
 * into floating point numbers.
 */

#include <stdio.h>
#include <ctype.h>

// Global variable
const int size = 64;

int main(void)
{
    char text[size];

    // Prompts the user for a floating-point number
    get_text(text);

    printf("%s\n", text);

    return 0;
}

/*********************************************
 * get_text()
*/
void get_text(char arr[])
{
    int i = -1;

    char temp[size];

    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    // Terminates the string
    arr[i] = '\0';

    // checks for first legit char
    int j = 0;

    while ((!isdigit(arr[j]) && arr[j] != '-' && arr[j] != '.')
        j++;

    _Bool is_negative = 0, found_decimal = 0;

    if (arr[j] == '-')
        is_negative = 1;
    else if (arr[j] == '.')
        found_decimal = 1;

    while (arr[j] != '\0')
    {
        
    }
}