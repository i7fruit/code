/**
 * fgetc_2.c
 *
 * Monday, July 02 2018 18:21hrs
 *
 * This program reads characters from
 * the text.txt file one at a time
 * and prints them to standard output
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

     char c;

     while ((c = fgetc(fptr)) != EOF)
         putchar(c);

     fclose(fptr);

     return 0;
 }