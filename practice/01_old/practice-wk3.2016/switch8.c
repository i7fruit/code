/*
 * octal.c
 *
 * This program calculates numbers
 * using octal notation ie numbers
 * in base-8
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declares variables
    signed int num0, num1, ans;
    char c;
    
    // Prompts user for input
    printf("Enter an integer in base-10\n");
    num0 = get_int();
    
    printf("Enter a second integer in base-10\n");
    num1 = get_int();
    
    printf("What operation do you wish to carry out?\n");
    c = get_char();
    
    switch(c)
    {
        case '*':
            ans = num0 * num1;
            printf("%i %c %i = %#o(base-8)\n", num0, c, num1, ans);
            break;
    
    
        case '/':
            ans = num0 / num1;
            printf("%i %c %i = %#o(base-8)\n", num0, c, num1, ans);
            break;
    
        case '+':
            ans = num0 + num1;
            printf("%i %c %i = %#o(base-8)\n", num0, c, num1, ans);
            break;
    
        case '-':
            ans = num0 - num1;
            printf("%i %c %i = %#o(base-8)\n", num0, c, num1, ans);
            break;
    
        default:
            printf("%c is not a valid operator.\nUse +,-,* or /\n", c);
            break;
    }

    /*
     * Using the %o character converter would display
     * octal numbers without the preceeding zeros.
     *
     * To display preceeding zeros, use %#o
     */
    
    
    return 0;
}
