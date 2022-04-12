#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* Get input from the user*/
    
    printf("Enter a number.\n");
    int i = GetInt();
    
    if(i < 0)
    {
        printf("Negative\n");
    }
    
    else if(i > 0)
    {
        printf("Positive\n");   
    }
    
    else
    {
        printf("Zero\n");
    }
}
