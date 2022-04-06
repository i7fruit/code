/*
 * capitalize1.c
 *
 * This program capitalizes any lowercase
 * characters in a string provided by the user
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h> // To get access to the toupper() function

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
                /*
                 * Capitalizes the lowercase i'th char by subtracting 32,
                 * subracting (lowercase alphbt - uppercase alphbt eg 'a' - 'A'),
                 * or using the "toupper()" function
                 */
                 
                printf("%c", toupper(s[i])); /*
                                              * Toupper: if its argument is a lowercase letter, it changes it to upper...
                                              * otherwise, it just prints the uppercase as is. This eliminates the need...
                                              * for an "if-else" stmnt as in capitalize0.c
                                              */
            
        }
        
        // Prints a newline irrespective of what branch of the "for" loop executes
        putchar('\n');// printf can also suffice
    }
    return 0;
}