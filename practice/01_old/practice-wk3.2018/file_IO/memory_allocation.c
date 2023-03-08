/**
 * memory_allocation.c
 *
 * Wednesday, 06.27.18 19:15hrs
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define SIZE 5

 int main(void)
 {
     short *values;

     //Allocates free heap memory of five integers
     values = (short *)malloc(SIZE * sizeof(short));

     //Sanity check to make sure there's memory
     if (values == (short *) 0)
     {
          puts("Insufficient memory");
          return 1;
     }

     //Initializes the values[] array
     for (short i = 0; i < SIZE; i++)
     {
         printf("Enter value %i: ", i + 1);
         scanf("%hi", (values + i));
     }

     printf("\n");

     //Prints its contents to the screen
     for (short i = 0; i < SIZE; i++)
         printf("%i ", *(values + i));

     putchar('\n');

     //Frees up the memory
     free(values);

     return 0;
 }