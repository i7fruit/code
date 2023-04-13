#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("What is the average number of children ");
    printf("per family in the US?: ");
    
    int nmb = GetInt();
    
    if(nmb == 2)
    {
        printf("That is correct.\n");
    }
    
    else
    {
        printf("Sorry, that is incorrect.\n");
    }
}
