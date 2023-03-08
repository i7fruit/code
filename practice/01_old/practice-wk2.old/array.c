/*
 * array.c
 *
 * An array of integers where every element
 * in the array is its index
 */
 
 #include <stdio.h>
 
 int main(void)
 {
     /*
      * Iterates over each element of the array and assigns it
      * the value of its index
      */
      
      // Declares an array
      
      int numbers[100];
      
       printf("CONTENTS OF ARRAY \"NUMBERS.\"\n");
      
      for (int i = 0; i < 100; i++)
      {
          numbers[i] = i;
          printf("numbers[%2i] = %2i\n", i, numbers[i]);
      }
      
      return 0;
 }