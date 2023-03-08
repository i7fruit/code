/*
 * cap1stLtr0.c
 *
 * Program makes the first letter
 * of each word capitalized
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 
 int main(void)
 {
     // Prompts user for input
     printf("Enter your text\n");
     string text = get_string();
     
     if (text != NULL)
     {
         // Iterates over each character in the string
         for (int i = 0, n = strlen(text); i < n; i++)
         {
             if (text[0] >= 'a' && text[0] <= 'z')
             {
                 text[0] = text[0] - 32;
             }
             if ((text[i] == ' ') && (text[i + 1] >= 'a' && text[i + 1] <= 'z'))
             {
                 text[i + 1] = text[i + 1] - 32;
             }
             printf("%c", text[i]);
         }
     }
     return 0;
 }