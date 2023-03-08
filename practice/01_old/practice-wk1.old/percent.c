#include <stdio.h>
#include <cs50.h>

float to_percent(int input, int input_2);

int main(void)
{
    /* Program to convert
     * fractions to percentages */
     
     int numerator, denominator;
     float p;
     
     /* Prompt the user for input */
     
     do
     {
        printf("Enter a positive numerator: ");
        numerator = GetInt();
     }
     while(numerator < 1);
     
     do
     {
        printf("Enter a positive denominator: ");
        denominator = GetInt();
     }
     while(denominator < 1);
     
     /* Call the percent function
      * and display result to standard output */
     
     p = to_percent(numerator, denominator);
     
     printf("%i / %i = %4.0f%%\n", numerator, denominator, p);
}

float to_percent(int input, int input_2)
{
    return ((float)input / input_2) * 100;
}
