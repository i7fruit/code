/**
 * fputc_2.c
 *
 * Tuesday, July 03 2018 00:20hrs
 */

 #include <stdio.h>

 //Declares pointers to two separate files
 FILE *fptr, *pointer;

 int main(void)
 {
     //Opens the text file for reading
     fptr = fopen("text.txt", "r");

     //Prints an error message if the file cannot be opened
     if (fptr == 0)
     {
         puts("Cannot open file");
         return 1;
     }

     //Opens the write file for writing
     pointer = fopen("write.doc", "w");

     //Prints an error message if the file cannot be opened
     if (pointer == 0)
     {
         puts("Cannot open file");
         return 1;
     }

     //Declares a variable to store each char gotten from the read file
     char c;

     /**
      * If an attempt has not been made to read past
      * the last character, then the char gotten from
      * the read file with fgetc(), is written to the
      * write file with fputc()
      */

     while ((c = fgetc(fptr)) != EOF)
     {
         fputc(c, pointer);
     }

     //Closes both files
     fclose(fptr);
     fclose(pointer);

     return 0;
 }