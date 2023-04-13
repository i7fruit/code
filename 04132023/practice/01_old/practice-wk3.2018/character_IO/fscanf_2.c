/**
 * fscanf.c
 *
 * Wednesday, July 04 2018 16:07hrs
 *
 * This program reads digits from a
 * file using the fscanf() function
 * and writes them to another file
 * using the fprintf() function
 *
 * FORMAT OF fscanf:
 * fscanf(<file_pointer> , <format ie %i/%f/etc> , &<variable>);
 */

 #include <stdio.h>

 int main(void)
 {
     short i;

     FILE *fptr0, *fptr1;

     if ((fptr0 = fopen("fin", "r")) == 0)
     {
         puts("Problem trying to open file");
         return 1;
     }

     if ((fptr1 = fopen("write", "w")) == 0)
     {
         puts("Problem trying to open file");
         return 1;
     }

     while ((fscanf(fptr0, "%hi", &i)) != EOF)
         fprintf(fptr1, "%hi ", i);

     //The code before also works
     /**                                **\
      * while (!feof(fptr0))             *
      * {                                *
      *     fscanf(fptr0, "%hi", &i);    *
      *     fprintf(fptr1, "%hi  ", i);  *
      * }                                *
      */                                //

     fclose(fptr0);
     fclose(fptr1);

     return 0;
 }