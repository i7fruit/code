/**
 * noswap.c
 *
 * Friday, 06.29.18 19:16hrs
 *
 * Demonstrates how a function
 * swaps values, but it isn't
 * reflected in the function
 * that called it
 */

 #include <stdio.h>

 void no_swap(short i, short j);

 int main(void)
 {
     short x = 1, y = 2;

     printf("BEFORE\nx = %hi\ny = %hi\n", x, y);

     no_swap(x, y);

     printf("\nAFTER\nx = %hi\ny = %hi\n", x, y);

     return 0;
 }

 /**
  * The no_swap() function takes two integer variables
  * as arguments and is supposed to swap their values by storing
  * one variable in a temporary holding variable,
  * overwriting one variable with the other's value,
  * and then placing the value in the temporary variable
  * in the location of the variable that overwrote one of
  * the other variables.
  *
  * It will fail to do that because it only receives copies of
  * the variables it gets as arguments, and doesn't change the
  * values in the function that called it.
  */

  void no_swap(short i, short j)
  {
      short temp = 0;

      temp = j;
      j = i;
      i = temp;
  }