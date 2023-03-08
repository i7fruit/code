/*
 * factorial.c
 *
 * This program returns the factorial
 * of any number entered by the user
 */
 
 #include <stdio.h>
 
 int factorial(int n);
 
 int main(void)
 {
     // Prompt the user for input
     int i;
     
     do
     {
         printf("Enter an integer\n");
         scanf("%i", &i);
     }
     while (i < 0);
    
     // Calls the factorial function
     printf("%i! = %i\n", i , factorial(i));
 }
 
 /*
  * A factorial function that takes
  * a number and finds its factorial
  * by multiplying the number by the
  * factorial itself less than one, and
  * so on
  */
  
  int factorial(int n)
  {
      // form the base to prevent and infinite recursion
      if (n <= 1)
      {
          return 1;
      }
      
      else
      {
          return n * factorial(n - 1);
      }
  }