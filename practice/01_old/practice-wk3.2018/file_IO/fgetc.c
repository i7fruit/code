/**
 * fgetc.c
 *
 * Sunday, July 01 2018 14:24hrs
 *
 * This program prints the contents
 * of a file to the screen using
 * the fgetc() function.
 *
 * This function reads the next character
 * in a file and stores it in a variable
 *
 * FORMAT OF fgetc()
 * char c = fgetc(<file_pointer>);
 */

 #include <stdio.h>

 FILE *fptr;

 int main(void)
 {
     fptr = fopen("mydata.dat", "r");

     if (fptr == NULL)
     {
         printf("Cannot access file\n");
         return 1;
     }

     char c;

     //Iterates through the file until it gets to the end
     while ((c = fgetc(fptr)) != EOF)
         printf("%c", c);

     putchar('\n');

     fclose(fptr);

     return 0;
 }