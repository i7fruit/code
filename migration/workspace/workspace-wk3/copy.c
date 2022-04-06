/**
 * copy.c
 *
 * Friday, 06.29.18 17:29hrs
 *
 * This program copies a string
 */

 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>

 int main(void)
 {
     // Declares a pointer to hold the address of a string of text
     char *s = get_string("Enter a string: ");

     // Returns 1 if the value of the address is NULL
     if (!s)
         return 1;

     // Allocates memory for another string
     char *t = malloc((strlen(s) + 1) * sizeof(char));

     // If the value of the address is NULL, return 1
     if (t == NULL)
         return 1;

     // Copies string located at s to string located at t
     for (short i = 0, n = strlen(s); i <= n; i++)
         t[i] = s[i];

     // Capitalizes the first character of the copy string
     if (strlen(t) > 0)
         t[0] = toupper(t[0]);

     printf("s = %s\nt = %s\n", s, t);

     // Deallocates memory allocated to t
     free(t);

     return 0;
 }