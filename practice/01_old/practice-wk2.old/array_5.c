/*
 * array_5.c
 * June 22 2017
 *
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
     char word[5] = {'\0', '\0', '\0', '\0', '\0',};
     
     for (int i = 0; i < 1; i++)
     {
         for (int j = 65; j < 123; j++)
         {
             if (j == 91)
             {
                 j = 97;
             }
             word[i] = (char)j;
             printf("%c\n", word[i]);
         }
     }
     
     for (int i = 0; i < 1; i++)
     {
         for (int j = 65; j < 123; j++)
         {
             if (j == 91)
             {
                 j = 97;
             }
             word[i] = (char)j;
             for (int k = 65; k < 123; k++)
             {
                 if (k == 91)
                 {
                     k = 97;
                 }
                 word[i + 1] = (char)k;
                 printf("%c%c\n", word[i], word[i + 1]);
             }
         }
     }
     
     // For 3
     for (int i = 0; i < 1; i++)
     {
         for (int j = 65; j < 123; j++)
         {
             if (j == 91)
             {
                 j = 97;
             }
             word[i] = (char)j;
             for (int k = 65; k < 123; k++)
             {
                 if (k == 91)
                 {
                     k = 97;
                 }
                 word[i + 1] = (char)k;
                 for (int l = 65; l < 123; l++)
                 {
                     if (l == 91)
                     {
                         l = 97;
                     }
                     word[i + 2] = (char)l;
                     printf("%c%c%c\n", word[i], word[i + 1], word[i + 2]);
                 }
             }
         }
     }
     
     // For 4
     for (int i = 0; i < 1; i++)
     {
         // Iterates over element 0
         for (int j = 65; j < 123; j++)
         {
             if (j == 91)
             {
                 j = 97;
             }
             word[i] = (char)j;
             
             // Iterates over element 1
             for (int k = 65; k < 123; k++)
             {
                 if (k == 91)
                 {
                     k = 97;
                 }
                 word[i + 1] = (char)k;
                 
                 // Iterates over element 2
                 for (int l = 65; l < 123; l++)
                 {
                     if (l == 91)
                     {
                         l = 97;
                     }
                     word[i + 2] = (char)l;
                     
                     // Iterates over element 3
                     for (int m = 65; m < 123; m++)
                     {
                         if (m == 91)
                         {
                             m = 97;
                         }
                         word[i + 3] = (char)m;
                         printf("%c%c%c%c\n", word[i], word[i + 1], word[i + 2], word[i + 3]);
                     }
                 }
             }
         }
     }
     
     return 0;
 }