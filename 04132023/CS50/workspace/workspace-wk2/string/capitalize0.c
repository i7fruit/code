/*
 * capitalize0.c
 *
 * This program capitalizes any lowercase
 * characters in a string provided by the user
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Prompts the user for input
    printf("Enter a string\n");
    string s = get_string();
    
    if (s != NULL) // Ensures that get_string returns characters
    {
        // Iterates over each character up to the length of the string
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // Checks to see if the i'th char is lowercase
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                /*
                 * Capitalizes the lowercase i'th char by subtracting 32,
                 * subracting (lowercase alphbt - uppercase alphbt eg 'a' - 'A'),
                 * or using the "toupper()" function
                 */                
                 printf("%c", s[i] - ('a' - 'A'));
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        
        // Prints a newline irrespective of what branch of the "for" loop executes
        putchar('\n'); // Used putchar just for fun. Printf would also suffice
    }
    return 0;
}