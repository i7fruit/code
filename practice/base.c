/**
 * base.c
 * Thursday, August 26 2021 22:45 hrs
 * 
 * This program converts an integer in base-10
 * to its equivalent in any base between 2 and 16
 */
#include <stdio.h>

#define LOWER_BOUND 2
#define EIGHT 8
#define UPPER_BOUND 16

int main(void)
{
    long number = 0;
    short container[64];
    const char baseDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    printf("Enter number to convert: ");
    scanf("%li", &number);
    
    short base = 0;
    
    do
    {
        printf("Enter base to convert to: ");
        scanf("%hi", &base);
    }
    while (base < LOWER_BOUND || base > UPPER_BOUND);
    
    if (base == EIGHT)
        printf("%i", 0);
    if (base == UPPER_BOUND)
        printf("%s", "0x");

    short index = 0;
    
    while (number > 0)
    {
        container[index++] = number % base;
        number /= base;
    }


    for (--index; index >= 0; index--)
        printf("%c", baseDigits[container[index]]);
    
    printf("\n");

    return 0;
}