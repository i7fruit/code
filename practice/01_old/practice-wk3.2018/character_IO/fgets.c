/**
 * fgets.c
 *
 * Monday, July 02 2018 13:28hrs
 *
 * Program uses fgets to get input
 * from the user rather than scanf
 * or getchar
 *
 * FORMAT OF fgets()
 *
 * fgets(<char *arr> , <qty> , <FILE *stream>);
 */

 #include <stdio.h>
 #include <string.h>

 #define SIZE 81

 int main(void)
 {
     char c[SIZE];

     printf("Enter a string of characters\n");

     fgets(c, SIZE, stdin); //stdin : input comes from the keyboard

     c[strlen(c) - 1] = '\0'; //Removes the '\n' put by fgets....

     printf("%s.\n", c); //....so that the '.' after the %s appears on the same line.

     return 0;
 }