#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Do you want to proceed?\n");
    char answer = GetChar();
    
    switch(answer)
    {
        case 'Y':
        case 'y':
            printf("YES\n");
            break;
            
        case 'N':
        case 'n':
            printf("No\n");
            break;
            
        default:
            printf("Invalid Response\n");
            break;
    }
}
