/*
 * capInitials0.c
 *
 * This program prints out the initials
 * of the user's name in capital letters
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 
 #define CHANGE_CHAR_CASE 32 // The difference between the upper and lowercase of a particular alphabet
 
 int main(void)
 {
     // Prompts user for input
     printf("What is your name?\n");
     string full_name = get_string();
     
     // This first "if" statement ensures get_string gets a string
     if (full_name != NULL)
     {
        
         // Prints the first initial
         if (full_name[0] >= 'a' && full_name[0] <= 'z')
         {
             full_name[0] = full_name[0] - CHANGE_CHAR_CASE;
             printf("%c", full_name[0]);
         }
         else if (full_name[0] >= 'A' && full_name[0] <= 'Z')
         {
             printf("%c", full_name[0]);
         }
         
         // Iterates over other characters in the string
         for (int i = 1, n = strlen(full_name); i < n; i++)
         {
             // If i'th char is a space or hyphen, and next char is lowercase, then capitalize next char
             if ((full_name[i] == ' ' || full_name[i] == '-') && (full_name[i + 1] >= 'a' && full_name[i] <= 'z'))
             {
                 full_name[i + 1] = full_name[i + 1] - CHANGE_CHAR_CASE;
                 
                 // Prints capitalized character after a space or hyphen
                 printf("%c", full_name[i + 1]);
             }
             
             // Prints initial as the user typed it
             else if ((full_name[i] == ' ' || full_name[i] == '-') && (full_name[i + 1] >= 'A' && full_name[i] <= 'Z'))
             {
                 printf("%c", full_name[i + 1]);
             }
         }
         
     }
     
     return 0;
 }