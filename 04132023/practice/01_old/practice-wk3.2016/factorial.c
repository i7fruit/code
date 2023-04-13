/*
 * factorial.c
 *
 * This calculates the factorial of any number
 * it's a recursive function
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 signed long int factorial(signed long int x);
 
 int main(void)
 {
     // Asks the user for a positive integer
     signed long int i;
     
     do
     {
         printf("Enter an integer\n");
         i = get_int();
     }
     while (i < 0);
     
     // Calls the factorial function
     printf("%li! = %li\n", i, factorial(i));
 }
 
 /*
  * The factorial function finds the factorial
  * of any number, by multiplying that number
  * by the value of itself minus one, and calling
  * itself again until a base case is reached
  */
 
 signed long int factorial(signed long int x)
 {
     if (x <= 1)
     {
         return 1;
     }
     
     else
     {
         return x * factorial(x - 1);
     }
 }