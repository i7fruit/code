/**
 * 02_odd_even.c
 *
 * Tuesday, May 31 2022 00:13hrs
 *
 * The program tests to see if an
 * integer is odd or even by checking
 * to see if the number is evenly divided by 2.
 */
 #include <stdio.h>

 int main(void)
 {
     int value = 0;

     do
     {
         printf("Enter value between 0 and 65000: ");
         scanf("%i", &value);
     }
     while (value < 1 || value > 64999);

     if (value % 2 == 0)
         printf("%i is even.\n", value);
     else
         printf("%i is odd.\n", value);
         
     return 0;
 }