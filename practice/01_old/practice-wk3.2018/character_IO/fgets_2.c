/**
 * fgets_2.c
 *
 * Monday, August 26 2018 17:24hrs
 *
 * Program uses fgets to get input
 * from a file and stores
 * it in the array c[]
 *
 * FORMAT OF fgets()
 *
 * fgets(<char *arr> , <qty> , <FILE *stream>);
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 #define SIZE 81
 #define LENTH 10

 int main(void)
 {
     char *filename = malloc(LENTH * sizeof(char));

     if (filename == 0)
     {
         fprintf(stderr, "Insufficient memory\n");
         return 1;
     }

     char *c = malloc(SIZE * sizeof(char));

     if (c == 0)
     {
         fprintf(stderr, "Insufficient memory\n");
         free(filename);
         return 2;
     }

     printf("Enter file to read from: ");
     scanf("%s", filename);

     FILE *fptr = fopen(filename, "r");

     if (fptr == 0)
     {
         fprintf(stderr, "Cannot open %s\n", filename);
         free(filename);
         free(c);
         return 2;
     }

     while(!feof(fptr))
     {
          fgets(c, SIZE, fptr);
          printf("%s", c);
     }

     free(filename);
     free(c);
     fclose(fptr);

     return 0;
 }