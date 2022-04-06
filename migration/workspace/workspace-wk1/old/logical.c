#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /* Prompt the user for a response*/
    
    printf("Do you want to proceed? ");
    char response = GetChar();
    
    /* 
     * Display Yes, or No, to standard output
     * depending on what response is given
     * by the user
     */
    
    if((response == 'Y') || (response == 'y'))
    {
        printf("YES\n");
    }
    else if((response == 'N') || (response == 'n'))
    {
        printf("NO\n");
    }
    else
    {
        printf("Invalid Response\n");
    }
}
