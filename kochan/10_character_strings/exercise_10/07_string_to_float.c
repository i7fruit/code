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
int string_to_int(char arr[]);

int main(void)
{
    const int size = 64;

    char digits[size] = "";

    printf("Enter numeric characters: ");
    get_digits(digits);

    //int integer = string_to_int(digits);

    printf("%s\n", digits);

    return 0;
}

/********************************************
 * The get_digits() function prompts the
 * user for character digits '0' through '9',
 * and/or symbols '-' and, '.'
 */
void get_digits(char arr[])
{
    // User is limited to 63 characters
    scanf("%6s", arr);
}

/********************************************
 * string_to_int() This function iterates
 * through an array of character digits
 * and subtracts the value 48 (which represents
 * the ascii character '0' from each digit) to
 * give its integer equivalent.
 */
//int string_to_int(char arr[])
//{
//    int converted = 0, i = 0;
//    char zero = '0';
//    _Bool is_negative = 0;
//    _Bool found_digit = 0;

//    // For negative numbers
//    if (arr[0] == '-')
//    {
//        is_negative = 1;
//        arr[0] = '0';
//        i++;
//    }

//    for (; arr[i] != '\0'; i++)
//    {
//        if (isdigit(arr[i]))
//        {
//            found_digit = 1;

//            int digit = arr[i] - zero;
//            converted = converted * 10 + digit;
//        }
//    }

//    if (!found_digit)
//        printf("No valid digit found.\n");

//    if (is_negative)
//        return -converted;

//    return converted;
//}