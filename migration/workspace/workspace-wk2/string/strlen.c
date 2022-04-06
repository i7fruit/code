/*
 * strlen.c
 *
 * This program determines how long
 * a particular string is
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
     // Get user input
     printf("Enter your string\n");
     string s = get_string();
     
     // Declare a variable
     int n = 0;
     
     while (s[n] != '\0')
     {
         n++;
     }
     
     printf("%i characters\n", n);
     
     return 0;
 }