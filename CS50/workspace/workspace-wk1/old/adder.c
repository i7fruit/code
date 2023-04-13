#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* Gets two integers from the user.*/
    
   printf("Enter first integer: ");
   int x = GetInt();
   
   printf("Enter second integer: ");
   int y = GetInt();
   
   /* Sums up both integers and
    * prints result to the standard
    * output device.*/
    
    printf("The sum of X and Y is %i\n", x + y);
   
    
}
