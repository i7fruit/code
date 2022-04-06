/**
 * scanf1_incorrect.c
 *
 * Friday, 06.29.18 19:45hrs
 *
 * Incorrectly gets a string from the user using scanf
 */

 #include <stdio.h>

 int main(void)
 {
     char *s; // Contains garbage values

     /**
      * This code directs scanf to go to some
      * random memory location, in this case s,
      * and put the value entered by the user.
      * This is bad programing. DON'T DO THIS.
      */

     printf("s: ");
     scanf("%s", s);

     printf("s = %s\n", s);

     return 0;
 }