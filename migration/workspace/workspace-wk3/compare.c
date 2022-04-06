/**
 * compare.c
 *
 * Friday, 06.29.18 02:14hrs
 *
 * The program compares two strings
 */

 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>

 int main(void)
 {
     char *s = get_string("s:");
     char *t = get_string("t:");

     short flag = strcmp(s, t);

     printf("Flag is %hi\n", flag);

     if (flag == 0)
         printf("Strings are the same\n");

     else
         printf("Strings are different\n");

     return 0;
 }