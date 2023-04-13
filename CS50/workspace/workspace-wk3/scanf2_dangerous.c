/**
 * scanf_1.c
 *
 * Friday, 06.29.18 19:53hrs
 *
 * Dangerously gets a string from the user using scanf
 */

 #include <stdio.h>

 #define SIZE 5

 int main(void)
 {
     //Sets aside five bytes of memory for the array, s[]
     char s[SIZE];

     /**
      * The DANGER here is that, using scanf,
      * if the user types in characters that
      * will be too much for the allocated
      * memory, the extra characters will
      * overwrite data in other parts of memory you
      * didn't allocate. DON'T DO THIS
      */

     printf("s: ");

     /**
      * To be safe with scanf in this situation,
      * you can limit the no of chars scanf takes
      * by putting an integer after the % in the
      * character converter, per the below
      */

     scanf("%4s", s); // Save one byte for binary 0

     printf("s = %s\n", s);

     return 0;
 }