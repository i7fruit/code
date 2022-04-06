/**
 * swap.c
 *
 * Friday, 06.29.18 19:31hrs
 *
 * Demonstrates how a function
 * swaps values, and it is
 * reflected in the function
 * that called it
 */

 #include <stdio.h>

 void swap(short *i, short *j);

 int main(void)
 {
     short x = 1, y = 2;

     printf("BEFORE\nx = %hi\ny = %hi\n", x, y);

     swap(&x, &y);

     printf("\nAFTER\nx = %hi\ny = %hi\n", x, y);

     return 0;
 }

 /**
  * The swap() function takes two integer pointers
  * as arguments and swaps the values they point to
  * by storing one value in a temporary holding variable,
  * then overwriting one value with the other's,
  * and then placing the value in the temporary variable
  * in the location of the variable that overwrote one of
  * the other variables.
  *
  * It will succeed to do this because it doesn't receive copies of
  * the variables it gets as arguments, but points to the actual values
  * themselves, and as such can manipulate them directly.
  */

  void swap(short *i, short *j)
  {
      short temp = 0;

      temp = *j;
      *j = *i;
      *i = temp;
  }