/**
 * putchar.c
 *
 * Sunday, July 01 2018 20:03hrs
 */

 #include <stdio.h>
 #include <stdlib.h>

 int main(void)
 {
     printf("Enter a character: ");
     char c = getchar();
     getchar(); //Grabs the \n character

     //Prints the character to the screen
     putchar(c);

     //Prints a newline character
     putchar('\n');

     printf("Enter a string of characters\n");

     short i = -1;
     char *s = malloc(31);

     if (s == NULL)
     {
         printf("Not enough memory\n");
         return 0;
     }

     do
     {
         i++;
         *(s + i) = getchar();
         putchar(*(s + i));
     }

     while (*(s + i) != '\n');

     printf("Type two chars together: ");
     char x = getchar();
     char z = getchar();
     getchar(); //Grabs the last newline character

     printf("%c, %c\n", x, z);

     printf("Type one last character: ");
     char be = getchar();

     putchar(be);

     return 0;
 }