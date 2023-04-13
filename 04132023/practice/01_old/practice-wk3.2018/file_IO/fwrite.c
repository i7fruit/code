/**
 * fwrite.c
 *
 * Tuesday, July 03 2018 15:15hrs
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define SIZE 100

 FILE *from, *to;

 int main(void)
 {
     from = fopen("mydata.dat", "r");

     if (from == 0)
     {
         puts("Cannot open file");
         return 1;
     }

     to = fopen("numbers.dat", "w");

     if (to == 0)
     {
         fclose(from);
         printf("Cannot open file\n");
         return 1;
     }

     char *s = malloc(SIZE);

     if (s == NULL)
     {
         puts("Not enough memory");
         return 1;
     }

     fread(s, sizeof(char), SIZE, from);

     fwrite(s, sizeof(char), strlen(s), to);

     fclose(from);
     fclose(to);
     free(s);

     return 0;
 }