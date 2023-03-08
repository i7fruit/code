/*
 * swap.c
 *
 * This program takes the value of one
 * variable, and swaps it with the value
 * of another
 */

 #include <stdio.h>
 #include <cs50.h>

 void swap(int a, int b);

 int main(void)
 {
     // Prompts the user for input
     printf("Enter 1st num: ");
     int x = get_int();

     printf("\nEnter 2nd num: ");
     int y = get_int();

     // Prints the output
     printf("%i , %i swapped is ", x, y);

     swap(x, y);

     return 0;
 }

 /*
  * The swap function takes two variables,
  * and creates one as a temporary holding
  * space. It swaps the variables by storing
  * the value of the first one in the holding
  * variable, overwriting it with the value of the
  * second variable, and then overwriting that second
  * variable with the value in the holding variable
  */
 void swap(int a, int b)
 {
     int tmp;
     tmp = a;
     a = b;
     b = tmp;

     // Prints the result to the screen
     printf("%i , %i\n", a, b);
 }