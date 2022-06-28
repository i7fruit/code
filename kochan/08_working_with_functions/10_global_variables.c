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

int main(void)
{
    get_base_and_number();

    convert_number();

    printf("%i, %i, %lu, %i\n", index, base, number, converted[2]);

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
        converted[index] = number % base;
        number /= base;
        index++;
    }
}