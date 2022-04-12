/**
 * 5_temperature_converter.c
 * Tue, Jan 18, 2022
 * 
 * This program converts from
 * fahrenheit to celsius and vice versa
 */
#include <stdio.h>

int main(void)
{
    float temperature = 0;
    char symbol;

    printf("Choose unit of temperature to convert to (F/C): ");
    scanf("%c", &symbol);

    if (symbol == 'C' || symbol == 'c')
    {
        printf("Enter temperature in degrees fahrenheit: ");
        scanf("%f", &temperature);

        float temp_in_celsius = (temperature - 32) / 1.8;
        printf("%.2fF = %.2fC\n", temperature, temp_in_celsius);
    }

    else if (symbol == 'F' || symbol == 'f')
    {
        printf("Enter temperature in degrees celsius: ");
        scanf("%f", &temperature);

        float temp_in_fahrenheit = (temperature * 1.8) + 32;
        printf("%.2fC = %.2fF\n", temperature, temp_in_fahrenheit);
    }

    else
    {
        printf("Invalid unit of converstion");
        return 1;
    }

    return 0;
}