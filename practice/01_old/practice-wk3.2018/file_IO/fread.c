/**
 * fread.c
 *
 * Sunday, July 01 2018 15:31hrs
 *
 * This program reads information
 * from a file on disk, and stores
 * them in memory in a buffer,
 * usually an array
 *
 * FORMAT FOR fread()
 * fread(<buffer> , <size> , <qty> , <file_pointer>);
 *
 * <buffer> : a pointer to the location where the information will be stored
 * <size> : how large each unit of information will be
 * <qty> : how many units of information we want to aquire from the file
 * <file_pointer> : a pointer to the file we want to get the information from
 */

 #include <stdio.h>
 #include <stdlib.h>

 #define BYTES 90

 FILE *fptr;

 int main(void)
 {
     //Opens the mydata file for reading
     fptr = fopen("book", "r");

     //Prints an error message if there's a problem trying to open the file
     if (fptr == 0)
     {
         printf("File not accessible\n");
         return 1;
     }

     //Allocates memory to store the information
     char *s = malloc(BYTES * sizeof(char));

     //Checks if there's sufficient memory
     if (s == NULL)
     {
         printf("Insufficient memory\n");
         return 1;
     }

     //Saves content of mydata.dat to the buffer
     fread(s, sizeof(char), BYTES, fptr);

     //Prints the content of the buffer
     printf("%s", s);

     //Deallocates the buffer memory and closes the file read from
     free(s);
     fclose(fptr);

     return 0;
 }