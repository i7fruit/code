/*
 * array_3.c
 * 06.21.17
 *
 * This program prints out the scores of five
 * students and stores them in an array
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 #define CLASS_SIZE 5
 
 int main(void)
 {
     // Declares an array to store the scores
     int scores[CLASS_SIZE];
     
     // Prints the score of each of the five students
     for (int i = 0; i < 5; i++)
     {
         printf("Enter the students score\n");
         scores[i] = get_int();
         printf("STUDENT %i scored %i\n", i, scores[i]);
     }
 }