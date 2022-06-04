/** 
 * 02_printing_calculator.c
 * 
 * Friday, June 03 2022 01:04hrs
 * 
 * This program performs simple calculations on
 * numbers keyed in by the user using a set of
 * operators.
 */
#include <stdio.h>

int main(void)
{
    float accumulator = 0, value = 0;
    char operator = ' ';

    do
    {
        printf("Begin Calculations\n");
        scanf("%f %c", &value, &operator);
    }
    while (operator != 'S' && operator != 's');

    // Sets the value for the accumulator
    accumulator = value;
    printf("%.3f\n", accumulator);
    
    while (operator != 'E' && operator != 'e')
    {
        scanf("%f %c", &value, &operator);

        switch (operator)
        {
            case '+':
                accumulator += value;
                printf("%.3f\n", accumulator);
                break;
            case '-':
                accumulator -= value;
                printf("%.3f\n", accumulator);
                break;
            case '*':
                accumulator *= value;
                printf("%.3f\n", accumulator);
                break;
            case '/':
                if (value == 0)
                {
                    printf("Cannot divide by 0\n");
                    return 1;
                }
                else
                    accumulator /= value;
                    printf("%.3f\n", accumulator);
                    break;
            case 'S':
            case 's':
                accumulator = value;
                printf("%.3f\n", accumulator);
                break;
            case 'E':
            case 'e':
                printf("%.3f\n", accumulator);
                printf("End of Calculations\n");
                break;
            default:
                printf("Invalid Operator\n");
                break;
        }
    }

    return 0;
}