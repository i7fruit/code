/*
 * linear.c
 *
 * This program searches an array
 * checking each element for a specified
 * item. If the item is found, the algorithm
 * stops, otherwise it moves to the next
 * element until all the elements in the array
 * have been searched
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 
 #define SIZE 6
 
 int main(void)
 {
     int array[SIZE] = { 11, 23, 8, 14, 30, 9};
     int nmb_2_find;
     
     // Prompts the user for input
     printf("What number are you looking for?\n");
     scanf("%i", &nmb_2_find);
     
     // Searches the array
     for (int i = 0; i < SIZE; i++)
     {
         if (array[i] == nmb_2_find)
         {
             printf("Number was found\n");
             return true;
         }
     }
     
     printf("Not found\n");
     
     return false;
 }