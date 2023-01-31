/**
 * 07_string_to_float.c
 *
 * Saturday, January 28, 2023 13:17hrs
 *
 * This program converts character digits
 * into floating point numbers.
 */

// Save pre-decimal digits in one array and post-decimal digits in another array.
// Find lenght of second array and set it to power of ten and compute value
// convert digits in second array to int, and divide by value computed from power of ten
// Add value of both arrays
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char text[] = "12.98";

    float pre_decimal = 0.0;
    float post_decimal = 0.0;

    int i = 0;

    for (; text[i] != '\0'; i++)
    {
        if (text[i] == '.')
        {
            i++;
            break;
        }

        int digit = text[i] - 48;

        pre_decimal = pre_decimal * 10 + digit;
    }

    static int count = 0;

    for (; text[i] != '\0'; i++)
    {

        int digit = text[i] - 48;

        post_decimal = post_decimal * 10 + digit;

        count++;
    }

    int power = pow(10, (count + 1));

    post_decimal /= power;

    printf("%.f\n", (pre_decimal + post_decimal));

    return 0;
}