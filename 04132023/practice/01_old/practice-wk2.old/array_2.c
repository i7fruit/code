/*
 * array_2.c
 * 06.21.17
 *
 * This program prints the contents of
 * an array of three integers
 */
 
 #include <stdio.h>
 
 int main(void)
 {
     // Declares an array of three ints
     int temperature[] = {68, 87, 30};
     
     // Iterates over the array and prints its contents
     for (int i = 0; i < 3; i++)
     {
         printf("%i\n", temperature[i]);
     }
 }