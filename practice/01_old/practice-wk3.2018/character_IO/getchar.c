/**
 * getchar.c
 *
 * Sunday, July 01 2018 19:46hrs
 */

 #include <stdio.h>

 int main(void)
 {
     char c, d, e, f, g;

     printf("Enter a character: ");
     c = getchar();

     printf("%c\n", c);

     getchar(); //Gets rid of the '\n' from ENTER after typing in the character

     printf("\nEnter two characters (Press Enter after a character)\n");
     d = getchar();
     getchar();
     e = getchar();
     getchar();

     printf("%c, %c\n", d, e);

     printf("\nEnter two characters together: ");
     f = getchar();
     g = getchar();
     getchar();

     printf("%c, %c\n", f, g);

     return 0;
 }