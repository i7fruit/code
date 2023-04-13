/**
 * 06_simple_expressions.c
 *
 * Tuesday, May 31 2022, 19:47hrs
 *
 * Program prompts user to key in two
 * decimal values and an operator symbol
 * to evaluate simple arithmetic expressions.
 */
#include <stdio.h>

int main(void)
{
    float value0, value1;
    value0 = value1 = 0;
    char operator = ' ';

    printf("Enter an expression to evaluate\n");
    scanf("%f %c%f", &value0, &operator, &value1);

    if (operator == '+')
        printf("%.2f %c %.2f = %.2f\n", value0, operator, value1, value0 + value1);
    else if (operator == '*')
        printf("%.2f %c %.2f = %.2f\n", value0, operator, value1, value0 * value1);
    else if (operator == '-')
        printf("%.2f %c %.2f = %.2f\n", value0, operator, value1, value0 - value1);
    else if (operator == '/')
    {
        // Exits the program if trying to divide by 0
        if (value1 == 0)
        {
            printf("Cannot divide by 0\n");
            return 1;
        }
        else
            printf("%.2f %c %.2f = %.2f\n", value0, operator, value1, value0 / value1);
    }
    else
    {
        printf("Invalid operator\n");
        return 1;
    }

    return 0;    
}