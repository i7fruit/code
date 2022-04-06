#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    printf("Enter a string\n");
    string s = get_string(); /*
                              * get_string may not always return strings.
                              * it can return a value called NULL
                              */
    
    if (s != NULL) // This guarantees that get_string returns nothing but a string
    {
    
        //for (int i = 0; i < strlen(s); i++)
        
        /* val of strlen can be put in a var
         * so that we don't keep calling the
         * function multiple times thru each
         * iteration
         */
         
         // Thus, this updated "for" stmt is better designed
        for (int i = 0, n = strlen(s); i < n; i++)
                                             
        {
            printf("%c\n", s[i]); // Prints the i'th character in the string
        }
    }
        return 0;
}