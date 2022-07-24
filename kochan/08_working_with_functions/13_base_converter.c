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
#include <stdbool.h>

int main(void)
{
    char base_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    int base = 0, size = 64;
    unsigned long number = 0;
    int converted[size];
    bool is_converting = true;

    while (is_converting)
    {
        do
        {
            printf("Number to convert: ");
            scanf("%lu", &number);

            printf("Base number: ");
            scanf("%i", &base);
        }
        while (base < 2 && base > 16);

        if (number == 0)
        {
            printf("0\n");
            break;
        }

        static int i = 0;

        while (number != 0)
        {
            converted[i++] = number % base;
            number /= base;
        }

        for (--i; i > 0; i--)
        {
            printf("%c", base_digits[converted[i]]);
        }
        putchar('\n');
        
    }
    
    return 0;
}