/**
 * fgetc.c
 *
 * Monday, July 02 2018 18:10hrs
 *
 * This program gets a single character
 * from the text.txt file and prints it
 * to standard output
 */

 #include <stdio.h>

 FILE * fptr;

 int main(void)
 {
     fptr = fopen("text.txt", "r");

     if (fptr == 0)
     {
         puts("Cannot open file");
         return 0;
     }

     //Gets the first character in the text.txt file
     char c = fgetc(fptr);

     putchar(c);
     putchar('\n');

     fclose(fptr);

     return 0;
 }