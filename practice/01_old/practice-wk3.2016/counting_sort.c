/**
 * counting_sort.c
 */
 
#include <stdio.h>
#include <cs50.h>

#define SIZE 10
#define LIMIT 10

int main(void)
{
     // Declares an array to hold the numbers
     int numbers[SIZE];
     
     /**
      * Declares a counter array
      * to track the frequency of each number
      */
     int counter[LIMIT];
     
     for (int i = 0; i < LIMIT; i++)
     {
         counter[i] = 0;
     }
     
     // Prompts the user for input.
     printf("Enter positive integers\nPress ctrl d to end\n");
     
     for (int i = 0; i < SIZE; i++)
     {
          printf("numbers[%i] = ", i);
          int n = get_int();
          
          numbers[i] = n;
          counter[n]++;
     }
     
     /**
      * Makes each element of counter a cummulative of
      * itself and the previous element
      */
     
     for (int i = 0; i < LIMIT; i++)
     {
         if (i > 0)
             counter[i] = counter[i - 1] + counter[i];
     }
     
     // Shifts the indices of the counter array to the right ==>
     for (int i = (LIMIT - 1); i >= 0; i--)
     {
          if (i == 0)
          {
              counter[i] = i;
              break;
          }
          counter[i] = counter[i - 1];
     }
     
     // Declares a new array to hold the sorted list
     int sorted[SIZE];
     
     for (int i = 0; i < SIZE; i++)
     {
         sorted[i] = 0;
     }
     
     // Initializes the new array with a sorted list
     for (int k = SIZE - 1; k >= 0 ; k--)
     {
         {
             sorted[counter[numbers[k]]] = numbers[k];
             counter[numbers[k]]++;
         }
     }
     printf("\n");
     
     // Prints the sorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", sorted[i]);
     }
     
     printf("\n");
     
     return 0;
}