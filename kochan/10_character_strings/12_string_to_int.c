/**
 * 12_string_to_int.c
 *
 * Sunday, September 11 2022 21:53hrs
 *
 * This program converts character digits
 * into integers.
 */
#include <stdio.h>
#include <ctype.h>

// Function prototypes
void get_digits(char arr[]);

int main(void)
{
    const int size = 64;

    char digits[size] = "";

    printf("Enter numeric characters: ");
    get_digits(digits);

    int integer = string_to_int(digits);

    return 0;
}

/********************************************
 * The get_digits() function promts the
 * user for characters digits '0' through '9'
 */
void get_digits(char arr[])
{
    // User is limited to 63 characters
    scanf("%63s", arr);
}

/********************************************
 * string_to_int() This function iterates
 * through an array of character digits
 * and subtracts the value 48 (which represents
 * the ascii character '0' from each digit) to
 * give its integer equivalent.
 */
int string_to_int(const char arr[])
{
    int converted = 0;
    char zero = '0';

    while (is_digit(arr[i]))
    {
        int digit = arr[i] - zero;

        converted *= 10 + (digit);
    }
}