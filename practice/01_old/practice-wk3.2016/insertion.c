/*
 * insertion.c
 */
 
 #include <stdio.h>
 
 #define SIZE 6
 
 int main(void)
 {
     // Declare an array, and populate
     int array[SIZE];
     
     for (int i = 0; i < SIZE; i++)
     {
         // Prompt for input
         printf("Enter an integer\n");
         scanf("%i", &array[i]);
     }
     putchar('\n');
     
     // Prints the unsorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }
     putchar('\n');
     
     // Sorts the array
     for (int i = 0; i < SIZE; i++)
     {
         int j = i;
         
         while ((j > 0) && (array[j - 1] > array[j]))
         {
             // Places array[j] in its proper position in the sorted array
             int tmp = array[j];
             array[j] = array[j - 1];
             array[j - 1] = tmp;
             j--;
         }
     }
     
     // Prints the sorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }
     putchar('\n');
 }