/**
 * fopen.c
 *
 * Wednesday, 06.27.18 23:21hrs
 *
 * FORMAT OF fopen()
 *
 * FILE *<file_ptr_name> = fopen("<file_path>" , "<operation>");
 *
 * where <operation> can be write (w), read (r), or append (a)
 */

 #include <stdio.h>
 #include <stdlib.h>

 // Sets up a file pointer
 FILE *fptr;

 int main(void)
 {
     /**
      * Assigns the disk location of the file mydata.dat
      * to the pointer fptr, and opens the file for
      * writing to, with the fopen function
      */
     fptr = fopen("mydata.dat", "w");

     // Prints an error message if the file pointer is null
     if (fptr == 0)
     {
         printf("ERROR\n");
         exit(1);
     }

     char s[] = "I'd like to get better";
     char c = '\n';

     // Uses fprintf, fputs, and fputc to write information to the file mydata.dat
     fprintf(fptr, "I've done so much work\n");
     fprintf(fptr, "I feel like a better programmer today.\n");
     fputc(c, fptr);
     fputs(s, fptr);
     fputc('\n', fptr);
     fputs("I will.", fptr);

     // Closes the file when done
     fclose(fptr);

     return 0;
 }