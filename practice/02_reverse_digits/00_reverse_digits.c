/**
 * reverseDigits.c
 * Thursday, August 26 2021 23:00 hrs
 * 
 * This program takes an integer input from the
 * user, and prints out the digits of the integer
 * in reverse. 
 */
#include <stdio.h>

#define TEN 10

int main(void)
{
    // Variables to store the number and its reverse
    unsigned long long number = 0, reversed = 0;
    
    // Prompts the user for input
    printf("Enter number: ");
    scanf("%llu", &number);
    
    while (number != 0)
    {
        reversed = reversed * TEN + (number % TEN);
        number /= TEN;
    }
    
    // Prints the reversed digits
    printf("%llu", reversed);
    printf("\n");
    
    return 0;
}