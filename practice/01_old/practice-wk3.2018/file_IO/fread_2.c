/**
 * fread_2.c
 *
 * This program writes an array
 * of integers into a file pointed
 * to by a file pointer using the
 * fwrite function
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 FILE *fptr;

 int main(void)
 {
     if ((fptr = fopen("mydata", "w")) == 0)
     {
         fprintf(stderr, "Cannot open file\n");
         return 1;
     }

     int numbers[] = {2, 34, 93, 0, 18};
     int n = 0;

     n = fwrite(numbers, sizeof(int), 5, fptr);

     printf("Function read %i items\n", n);

     fclose(fptr);

     return 0;
 }