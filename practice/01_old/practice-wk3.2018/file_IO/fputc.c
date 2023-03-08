/**
 * fputc.c
 *
 * Sunday, July 01 2018 14:45hrs
 *
 * This program writes data to
 * a file saved on disk one character
 * at a time using the fputc() function
 *
 * FORMAT OF fputc()
 * fputc(<character> , <file_pointer>);
 */

 #include <stdio.h>

 //Declares pointers to two separate files
 FILE *fptr, *fptr_2;

 int main(void)
 {
     //Opens the mydata file for reading
     fptr = fopen("mydata.dat", "r");

     if (fptr == 0)
     {
         printf("Cannot open file\n");
         return 1;
     }

     //Opens the work file for writing
     fptr_2 = fopen("work.txt", "w");

     if (fptr_2 == 0)
     {
         printf("Cannot open file\n");
         return 1;
     }

     char c;

     /**
      * Iterates through the mydata.dat file
      * until it gets to the end, while writing
      * each character to the work.txt file
      */

     while ((c = fgetc(fptr)) != EOF)
         fputc(c, fptr_2);

     //Closes both files
     fclose(fptr);
     fclose(fptr_2);

     return 0;
 }