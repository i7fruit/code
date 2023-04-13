/*
 * shift.c
 */
 
 #include <stdio.h>
 
 int main(void)
 {
     // Declare an array
     int array[5] = { 5, 6, 4, 2, -1};
     
     int tmp;
     
     for (int i = 0, j = 0; i < 5; i++, j++)
     {
         while ((j > 0) && (array[j] < array[j-1]))
         {
             tmp = array[j];
             array[j] = array[j - 1];
             array[j - 1] = tmp;
             j--;
         }
         if (j == 0)
         {
             j = i;
         }
     }
     
     //prints the array
     for (int i = 0; i < 5; i++)
     {
         printf("%i ", array[i]);
     }
 }