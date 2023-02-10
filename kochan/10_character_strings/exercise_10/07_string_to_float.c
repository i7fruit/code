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

// Global variable
const int size = 64;

// Function prototypes
void get_text(char arr[]);
float string_to_float(char arr[]);

int main(void)
{
    char text[size];

    // Prompts the user for a floating-point number
    printf("Enter a floating-point value: ");
    get_text(text);

    float converted = 0;

    //converted = string_to_float(text);

    //printf("%.10f\n", converted);

    printf("%s\n", text);

    return 0;
}

/*********************************************
 * get_text()
*/
void get_text(char arr[])
{
    int i = -1;

    // Temporary storage array
    char temp[size];

    // Populates main array with characters from user
    do
    {
        arr[++i] = getchar();
    }
    while (arr[i] != '\n');

    // Terminates the string
    arr[i] = '\0';

    i = 0;

    // Iterates through array until a ligitimate character is found
    int j = 0;

    while ((!isdigit(arr[j]) && arr[j] != '-' && arr[j] != '.'))
        j++;

    // Flags for detecting a digit, decimal, or minus character
    _Bool is_negative = 0, found_decimal = 0, is_digit = 0;

    if (arr[j] == '-')
        is_negative = 1;
    else if (arr[j] == '.')
        found_decimal = 1;
    else if (isdigit(arr[j]))
        is_digit = 1;

    /**
     * Iterates through the array and stores legitimate
     * characters into the temporary array while skipping
     * over alphabets and other special characters and symbols
     * other than the decimal (if not already entered)
    */
    while (arr[j] != '\0')
    {
        if (isdigit(arr[j]) || (arr[j] == '.') || arr[j] == '-')
        {
            if (isdigit(arr[j]) && !is_digit)
            {
                is_digit = 1;
            }

            // Stores a minus sign if encountered for the first time
            if (arr[j] == '-' && !is_digit && !is_negative && !found_decimal)
            {
                is_negative = 1;
                temp[i] = arr[j];
                i++; j++;
            }

            // Adds a minus character if it appears before a digit
            else if (arr[j] == '-' && is_negative && !is_digit && !found_decimal)
            {
                temp[i] =  arr[j];
                i++; j++;
            }

            // Skips over subsequent minus characters
            else if (arr[j] == '-' && is_digit)
                j++;

            // Stores the decimal if encountered for the first time
            else if (arr[j] == '.' && !found_decimal)
            {
                found_decimal = 1;
                temp[i] = arr[j];
                i++; j++;
            }

            else if (arr[j] == '.' && found_decimal && !is_digit)
            {
                temp[i] = arr[j];
                i++; j++;
            }

            // Skips the decimal if already stored
            else if (arr[j] == '.' && found_decimal)
                j++;

            // Stores digits into the temp array
            else
            {
                temp[i] = arr[j];
                i++; j++;
            }
        }
        // Skips over characters not to be used
        else
            j++;
    }

    // Terminates the temp array
    temp[i] = '\0';

    i = 0;

    // Copies temp array into main array
    for (; temp[i] != '\0'; i++)
    {
        arr[i] = temp[i];
    }

    // Terminates the main array
    arr[i] = '\0';
}

/******************************************************************
 * string_to_float()
 */
float string_to_float(char arr[])
{
    // Tracks if converted value will be a negative number
    _Bool is_negative = 0;

    // Tracks if a decimal character has been encountered
    _Bool decimal_found = 0;

    // Marks where decimal point should be
    int count = 0;

    if (arr[0] == '-')
        is_negative = 1;

    // Saves converted value
    float converted = 0.0;

    // Value to subtract from character digit to convert to integer
    const int zero_digit = 48;

    // Iterates through the array
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '.')
        {
            count = 0;
            decimal_found = 1;
            continue;
        }

        if (decimal_found)
        {
            converted = converted * 10 + (arr[i] - zero_digit);
            count++;
        }

        else
            converted = converted * 10 + (arr[i] - zero_digit);
    }

    // Computes decimal places
    const int divisor = pow(10, count);

    converted /= divisor;

    if (is_negative)
        return -converted;

    return converted;
}