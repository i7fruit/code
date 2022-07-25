/** 
 * 13_base_converter.c
 * 
 * Saturday, July 23 2022 22:57hrs
 * 
 * This program converts multiple values
 * to a specified base. It terminates when
 * the user keys in a zero as a number to
 * be converted.
 */
#include <stdio.h>

// Function prototype
void converter(unsigned long value, int base);

int main(void)
{
    int base = 0;
    unsigned long number = 0;

    // Continually prompts user for number to convert until zero is entered
    while (1)
    {
        do
        {
            printf("Number to convert: ");
            scanf("%lu", &number);

            printf("Base number: ");
            scanf("%i", &base);
        }
        while (base < 2 || base > 16);

        // Stops prompting for numbers when user types in a zero to convert
        if (number == 0)
        {
            printf("0\nEnd of conversion\n");
            break;
        }

        converter(number, base);
    }
    
    return 0;
}

/***********************************
 * converter()
 */
void converter(unsigned long value, int base)
{
    // Array to store digits for base characters
    char base_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    const short size = 64;
    int converted[size];

    // Initializes the converted[] array with zeros
    for (short i = 0; i < size; i++)
        converted[i] = 0;

    int i = 0;

    while (value != 0)
    {
        converted[i++] = value % base;
        value /= base;
    }

    for (--i; i >= 0; i--)
        printf("%c", base_digits[converted[i]]);
    
    putchar('\n');    
}