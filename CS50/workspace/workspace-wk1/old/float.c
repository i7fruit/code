#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* Gets a floating point
     * number from the user.*/
     
    printf("X is: ");
    float x = GetFloat();
    
    printf("Y is: ");
    float y = GetFloat();
    
    printf("\n%.2f + %.2f is %.2f\n", x, y, x + y);
    printf("%.2f - %.2f is %.2f\n", x, y, x - y);
    printf("%.2f / %.2f is %.2f\n", x, y, x / y);
}
