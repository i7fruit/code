/*
 * factorial_2.c
 *
 * This program calculates the sum
 * of all the numbers from 1 to that
 * entered by the user
 */
 
 #include <stdio.h>
 
 int sigma(int n);
 
 int main(void)
 {
     // Prompt user for input
     int i;
     
     do
     {
         printf("Enter an integer\n");
         scanf("%i", &i);
     }
     while (i <= 0);
     
     // Prints results to the screen
     printf("The sum of numbers from 1 to %i is %i\n", i, sigma(i));
 }
 
 /*
  * This function takes an integer
  * and adds it to a value less than
  * it by one, and then calls itself
  */
  
  int sigma(int n)
  {
      if (n <= 1)
      {
          return 1;
      }
      else
      {
          return n + sigma(n - 1);
      }
  }