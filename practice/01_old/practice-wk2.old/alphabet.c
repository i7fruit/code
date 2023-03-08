/*
 * alphabet.c
 *
 * This program iterates over the letters
 * of the alphabet and assigns them to an array
 */
 
 #include <stdio.h>
 
 int main(void)
 {
     // Declare an array of size 27 (26 characters and 1 null zero)
     char alphabet[27];
     
     for (int i = 0, j = 65; i < 27; i++)
     {
         
         while(j < 123)
         {
             if (j == 91)
             {
                 j = 97;
             }
             
             alphabet[i] = (char)j;
             printf("%c", alphabet[i]);
             j++;
         }
     }
 }