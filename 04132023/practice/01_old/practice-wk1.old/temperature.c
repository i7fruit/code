#include <stdio.h>
#include <cs50.h>

float fah_to_cel(float input);
float cel_to_fah(float input);

int main(void)
{
    /* Program to convert
     * Fahrenheit to Celcius */
     
     float F, C;
     
     printf("Enter a temperature in Fahrenheit: ");
     
     F = GetFloat();
     C = fah_to_cel(F);
     
     printf("%.1fF is %.1fC\n", F, C);
     
     printf("Enter a temperature in Celcius: ");
     C = GetFloat();
     F = cel_to_fah(C);
     
     printf("%.1fC is %.1fF\n", C, F);
     
}

float fah_to_cel(float input)
{
    return (5.0 / 9.0) * (input - 32); // 5/9 = 0.5556
    /* Also
     * C = (input - 32) / 1.8
     */
}

float cel_to_fah(float input)
{
    return ((9.0 / 5.0) * input) + 32; // 9/5 = 1.8
    /* Also
     * F = (input + 32) * 1.8
     */
}