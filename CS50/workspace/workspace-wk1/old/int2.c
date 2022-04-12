#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Gets two numbers from the user
    printf("X is: ");
    int x = GetInt();
    
    printf("Y is: ");
    int y = GetInt();
    
    /* Makes basic math calculations
     * on both numbers.*/
     
     printf("\n%i - %i = %i\n", x, y, x - y);
     printf("%i / %i = %i\n", x, y, x / y);
     printf("%i MOD %i = %i\n", x, y, x % y);
     printf("%i * %i = %i\n", x, y, x * y);
    
}
