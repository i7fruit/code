/**
 * puts.c
 *
 * Monday, July 02 2018 00:32hrs
 */

 #include <stdio.h>
 #include <stdlib.h>

 #define BYTES 21

 int main(void)
 {
     char *c = malloc(BYTES);

     if (c == NULL)
     {
         printf("Low memory\n");
         return 0;
     }

     printf("Enter a string\n");

     short i = -1;
     do
     {
         i++;
         *(c + i) = getchar();
     }

     while (*(c + i) != '\n');

     *(c + i) = '\0'; //Gets rid of the newline

     puts(c);

     free(c);

     return 0;
 }