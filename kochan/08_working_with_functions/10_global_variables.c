/**
 * 10_global_variables.c
 *
 * Tuesday, June 28 2022 00:31hrs
 *
 * This program converts a number
 * to a base specified by the user.
 * It illustrates the use of global variables.
 */
#include <stdio.h>

// Global variables - Global variable are initialized to zero by default
int converted[64]; // Stores the converted number

// Variables for base and number
int base, index;
unsigned long number;

// Function prototypes
void get_base_and_number(void);
void convert_number(void);
void display_converted(void);

int main(void)
{
    get_base_and_number();

    convert_number();

    display_converted();

    return 0;
}

/********************************
 * get_base_and_number() prompts the
 * user to enter values for base and
 * number which alters the values of
 * the corresponding global variables.
 */
void get_base_and_number(void)
{
    do
    {
        printf("Enter a base between 2 and 16: ");
        scanf("%i", &base);
    }
    while (base < 2 || base > 16);

    do
    {
        printf("Enter a positive integer: ");
        scanf("%lu", &number);
    }
    while (number < 0);
}

/********************************************
 * The convert_number() function converts the
 * number entered by the user to a user-defined
 * base using the modulo and division operators,
 * and stores the number in the converted[] array
 * in reverse order.
 */
void convert_number(void)
{
    while (number != 0)
    {
        converted[index++] = number % base;
        number /= base;
    }
}

/*********************************************
 * The display_converted() function uses
 * a forloop to read the contents of the
 * converted[] array from right to left and
 * displays the converted number in the right
 * order using the printf() function.
 */
void display_converted(void)
{
    const char base_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7',\
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (--index; index >= 0; index--)
        printf("%c", base_digits[converted[index]]);

    putchar('\n');
}