/*
 * selection.c
 *
 * This program arranges the values
 * in an array in ascending order by
 * checking for the smallest numbers
 * and placing them at their appropriate positions
 */

 #include <stdio.h>

 #define SIZE 6

 int main(void)
 {
     int array[SIZE];

     // Prompts the user for input
     for (int i = 0; i < SIZE; i++)
     {
         printf("Enter an integer\n");
         scanf("%i", &array[i]);
     }

     // Prints the unsorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }
     putchar('\n');

     // Sorts the array in ascending order
     for (int i = 0; i < (SIZE - 1); i++)
     {
         // Set minimum to i
         int min = i;

         // Find the smallest value
         for (int j = i + 1; j < SIZE; j++)
         {
             if (array[min] > array[j])
             {
                 min = j;
             }
         }

         if (min != i)
         {
             // Swaps the values
             int tmp = array[min];
             array[min] = array[i];
             array[i] = tmp;
         }

     }


     // Prints the sorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }

     putchar('\n');

     return 0;
 }