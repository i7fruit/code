/**
 * 12_string_to_int.c
 *
 * Sunday, September 11 2022 21:53hrs
 *
 * This program converts character digits
 * into integers.
 */
#include <stdio.h>

// Function prototypes
void get_digits(char arr[]);

int main(void)
{
    const int size = 64;

    char digits[size] = "";

    printf("Enter numeric characters: ");
    get_digits(digits);

    printf("%s\n", digits);

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