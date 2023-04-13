/* 
 * This program displays
 * cough a number of times
 * as set by the user
 */

#include <stdio.h>
#include <cs50.h>

void cough(void);
 
int main(void)
{
    /* 
     * Prompts the user for a
     * positive integer
     */
    
    int n;
    
    do
    {
        printf("Enter an integer: ");
        n = GetInt();
    }
    while(n < 0);
    
    for(int i = 0; i < n; i++)
    {
        cough();
    }
}

void cough(void)
{
    printf("Cough ");
}
