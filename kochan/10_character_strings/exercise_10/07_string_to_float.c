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

// Function prototypes
void get_digits(char arr[]);
int string_to_float(char arr[]);

int main(void)
{
    const int size = 64;

    char digits[size] = "";

    printf("Enter numeric characters: ");
    get_digits(digits);

    int real_number = string_to_float(digits);

    printf("%s\n", digits);

    return 0;
}

/********************************************
 * The get_digits() function prompts the
 * user for characters.
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
int string_to_float(char arr[])
{
    int converted = 0, i = 0;
    char zero = '0';
    _Bool is_negative = 0;
    _Bool found_digit = 0;
    _Bool found_decimal = 0;
    int exponent = 1;

    // For negative numbers
    if (arr[0] == '-')
    {
        is_negative = 1;
        arr[0] = '0';
        i++;
    }

    for (; arr[i] != '\0'; i++)
    {
        if (arr[i] == '.' && found_decimal)
            i--; continue;
        else if (arr[i] == '.' && !found_decimal)
        {
            found_decimal = 1;

        }
        if (isdigit(arr[i]))
        {
            found_digit = 1;

            int digit = arr[i] - zero;
            converted = converted * 10 + digit;
        }
    }

    if (!found_digit)
        printf("No valid digit found.\n");

    if (is_negative)
        return -converted;

    return converted;
}