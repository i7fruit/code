/*
 * bubble.c
 */

 #include <stdio.h>
 #include <ctype.h>
 #include <cs50.h>

 #define SIZE 6

 int main(void)
 {
     // Declares an array and populates with values from the user
     int array[SIZE];

     // Prompts the user for input
     for (int i = 0; i < SIZE; i++)
     {
         printf("Enter an integer\n");
         scanf("%i", &array[i]); // NOTE: A char array will not require an "&" for scanf
     }

     // Prints the contents of the array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }

     printf("\n");

     /*
      * Initializes a counter variable to a non-zero value
      * and initializes a temporary holding variable
      */
     int counter = 1;

     do
     {
         // Resets the counter variable
         counter = 0;

         // Iterates over the array
         for (int i = 0, j = 1; i < (SIZE - 1); i++, j++)
         {
             if (array[i] >= array[j])
             {
                 int tmp = array[j];
                 array[j] = array[i];
                 array[i] = tmp;
                 counter++;
             }
         }
     }
     while (counter > 0);


     // Prints the sorted array
     for (int i = 0; i < SIZE; i++)
     {
         printf("%i ", array[i]);
     }

     printf("\n"); // Prints a newline
 }