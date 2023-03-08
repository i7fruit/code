/**
 * fputc.c
 *
 * Tuesday, July 03 2018 00:14hrs
 *
 * Prints a character into a file
 * pointed to by a file pointer
 */

 #include <stdio.h>

 FILE *fptr;

 int main(void)
 {
     fptr = fopen("text.txt", "w");

     if (fptr == 0)
     {
         puts("Cannot open file");
         return 1;
     }

     fputc('G', fptr);

     fclose(fptr);

     return 0;
 }