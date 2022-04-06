/*
 * argv2.c
 *
 * This program iterates over strings and
 * characters within strings
 */
 
 #include <stdio.h>
 #include <string.h>
 #include <cs50.h>
 
 int main(int argc, string argv[])
 {
 
    // Iterates over strings in argv
    for (int i = 0; i < argc; i++)
    {
         // Iterates over characters of current string
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
             // Prints the j'th character in i'th string
            printf("%c\n", argv[i][j]);
        }
        
        printf("\n"); // Prints a space between each string
    }
    
    return 0;
 }