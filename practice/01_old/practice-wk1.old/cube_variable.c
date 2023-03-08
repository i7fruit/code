#include <stdio.h>
#include <cs50.h>

int cube(int input);
int main(void)
{
    /* Declare a variable */
    
   int n;
    
    /* Get input from the user */
    
    do
    {
        printf("Chose an integer to find ");
        printf("its cube.\n");
        n = GetInt();
    }
    while(n < 0);
    
    /* I've called the function
     * within the printf function */
    
    printf("The cube of %i is %i\n", n, cube(n));

}

int cube(int input)
{
    return input * input * input;
}
