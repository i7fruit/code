/**
 * fread_4.c
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define SIZE 5
 #define W_SIZE 100

 FILE *fptr0, *fptr1, *fptr2, *fptr3;

 int main(int argc, char *argv[])
 {
     // Ensures proper usage
     if (argc != 3)
     {
         fprintf(stderr, "Usage: ./fread_4 rfile wfile\n");
         return 1;
     }

     // Opens readfile, checks for null
     if ((fptr0 = fopen(argv[1], "r")) == 0)
     {
         fprintf(stderr, "Cannot open %s\n", argv[1]);
         return 2;
     }

     // Opens writefile, checks for null
     if ((fptr1 = fopen(argv[2], "w+")) == 0)
     {
         fclose(fptr0);
         fprintf(stderr, "Cannot open %s\n", argv[2]);
         return 3;
     }

     // Allocates heap memory storage for array of ints
     int *values = (int *)malloc(SIZE * sizeof(int));

     // Checks for null value
     if (values == NULL)
     {
         fprintf(stderr, "Not enough memory\n");
         return 4;
     }

     // Reads ints from readfile to buffer
     fread(values, sizeof(int), SIZE, fptr0);

     // Writes ints from buffer to writefile
     fwrite(values, sizeof(int), SIZE, fptr1);

     // Prints contents of array to standard output
     puts("INTEGERS IN THE VALUES ARRAY");
     for (int i = 0; i < SIZE; i++)
         printf("%i ", *(values + i));

     // Closes files, deallocates memory used for array
     fclose(fptr0);
     fclose(fptr1);
     free(values);

     // Opens a third file for reading
     fptr2 = fopen("word", "r");

     // Checks if its file pointer returns null
     if (fptr2 == 0)
     {
         fprintf(stderr, "File cannot be opened\n");
         return 5;
     }

     // Opens a fourth file for writing
     fptr3 = fopen("book", "w");

     // Checks if its pointer returns null
     if (fptr3 == 0)
     {
         fprintf(stderr, "File cannot be opened\n");
         return 5;
     }

     // Allocates memory to store string read from third file
     char *string = malloc(W_SIZE * sizeof(char));

     // Reads from third file, stores in buffer
     fread(string, sizeof(char), W_SIZE, fptr2);

     // Writes from buffer, stores in fourth file
     short s = strlen(string); // Stores value for length of string in buffer

     fwrite(string, sizeof(char), s, fptr3);

     // Closes files, frees memory
     fclose(fptr2);
     fclose(fptr3);
     free(string);

     return 0;
 }