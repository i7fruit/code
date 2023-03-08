/**
 * copy.c
 *
 * Wednesday, July 04 2018 12:59hrs
 *
 * This program copies the contents
 * of one file to another using the
 * fgetc and fputc functions
 */

 #include <stdio.h>
 #include <stdlib.h>

 #define SIZE 15

 FILE *fptr0, *fptr1;

 int main(void)
 {
     //Arrays to store the names of the files to be worked on
     char *to_cpy, *copied;

     if ((to_cpy = malloc(SIZE)) == 0)
     {
         puts("Not enough memory");
         return 1;
     }

     if ((copied = malloc(SIZE)) == 0)
     {
         puts("Not enough memory");
         return 2;
     }

     //Prompts the user to key in the filenames
     printf("What file would you like to have copied?\n");
     scanf("%s", to_cpy);

     printf("What file do you want to copy to?\n");
     scanf("%s", copied);

     if ((fptr0 = fopen(to_cpy, "r")) == 0)
     {
         puts("Cannot open the file");
         return 3;
     }

     if ((fptr1 = fopen(copied, "w")) == 0)
     {
         puts("Cannot open the file");
         return 4;
     }

     //Copies file if all checks were successful
     int *c = malloc(sizeof(char));

     if (c == NULL)
     {
         puts("Insufficient memory");
         return 5;
     }

     /**
       * Since c points to the memory location the size
       * of a single char, dereference it to get the value
       * stored in that location
       */

     while ((*c = fgetc(fptr0)) != EOF)
         fputc(*c, fptr1);

     //Deallocates used memory and closes all open files
     free(c);
     free(to_cpy);
     free(copied);

     fclose(fptr0);
     fclose(fptr1);

     printf("File(s) successfully copied\n");

     return 0;
 }