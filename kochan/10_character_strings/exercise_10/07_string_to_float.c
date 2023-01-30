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
#include <math.h>

// Function prototypes
void get_digits(char arr[]);
double string_to_float(char arr[]);

int main(void)
{
    const int size = 64;

    char digits[size] = "";

    printf("Enter numeric characters: ");
    get_digits(digits);

    double real_number = string_to_float(digits);

    printf("%.4f\n", real_number);

    return 0;
}

/********************************************
 * The get_digits() function prompts the
 * user for characters.
 */
void get_digits(char arr[])
{
    int size = 64;
    char temp[size];
    // User is limited to 63 characters
    scanf("%63s", temp);

    
}

/********************************************
 * string_to_int() This function iterates
 * through an array of character digits
 * and subtracts the value 48 (which represents
 * the ascii character '0' from each digit) to
 * give its integer equivalent.
 */
double string_to_float(char arr[])
{
    double converted = 0.0, set_decimal_point = 1.0, fraction = 0;
    char zero = '0';
    _Bool is_negative = 0;
    _Bool found_digit = 0;
    _Bool found_decimal = 0;
    int i = 0, decimal_marker = 0, count = 0;

    /**
     * Tracks if user typed in a negative sign
    */
    if (arr[0] == '-')
    {
        is_negative = 1;
        arr[0] = '0';
        i++;
    }

    // Iterates through the array of digits
    for (; arr[i] != '\0'; i++)
    {
        // Ignores subsequent '.' characters entered by the user
        if (arr[i] == '.' && found_decimal)
        {
            i--;
            continue;
        }

        // Flags the element that has the '.' char and sets the found_decimal flag to on
        else if (arr[i] == '.' && !found_decimal)
        {
            found_decimal = 1;
            decimal_marker = i;
        }

        // Converts character digits found into integers
        if (isdigit(arr[i]))
        {
            found_digit = 1;

            int digit = arr[i] - zero;
            converted = converted * 10 + digit;
            count++;
        }
    }

    if (!found_digit)
        printf("No valid digit found.\n");

    // Sets decimal point
    int mark = count - decimal_marker; // Determines the power of ten to compute divisor

    // Accounts for negative sign
    if (is_negative)
        mark += 1;

    set_decimal_point = pow(10, mark); // Computes value to divide converted value by, to get proper floating-point value

    converted /= set_decimal_point; // Computes floating-point value

    if (is_negative)
        return -converted;

    return converted;
}