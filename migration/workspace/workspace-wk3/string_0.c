/**
 * string0.c
 *
 * Friday, 06.29.18 18:50hrs
 *
 * This program prints the contents
 * of a string to stdout using
 * array notation
 */

 #include <stdio.h>
 #include <string.h>
 #include <cs50.h>

 int main(void)
 {
     char *s = get_string("Enter string: ");

     if (!s)
         return 1;

     // Prints the string using array notation
     for (short i = 0, n = strlen(s); i < n; i++)
         printf("%c", s[i]);

     putchar('\n');

     return 0;
 }