/**
 * fscanf.c
 *
 * Wednesday, July 04 2018 15:53hrs
 *
 * This program reads digits from a
 * file using the fscanf() function
 * and prints them to the screen
 * using printf()
 *
 * FORMAT OF fscanf:
 * fscanf(<file_pointer> , <"%i/%f/etc"> , &<variable>);
 */

 #include <stdio.h>

 int main(void)
 {
     int i;

     FILE *fptr;

     if ((fptr = fopen("fin", "r")) == 0)
     {
         puts("Problem trying to open file");
         return 1;
     }

     while ((fscanf(fptr, "%i", &i)) != EOF)
         printf("%i\n", i);

     fclose(fptr);

     return 0;
 }