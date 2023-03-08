/*
 * array_4.c
 * June 21 2017
 *
 * This program prints out the
 * contents of an array called name
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
     // Declare an array to hold a string of names
     string name[] = {"Li", "Shaka", "Paul"};
     
     // Iterates over the array of strings
     for (int i = 0; i < 3; i++)
     {
         printf("%s\n", name[i]);
     }
 }