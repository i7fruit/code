/*
 * valid_triangle.c
 *
 * This program checks if the lengths
 * provided by the user is valid to
 * make a triangle
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 bool valid_triangle(float a, float b, float c);
 
 int main(void)
 {
     // Prompts the user for positive real numbers
     
     // Gets the first length
     
     float length_0;
     
     do
     {
          printf("Enter the first length: ");
          length_0 = get_float();
     }
     while (length_0 <= 0);
     
     // Gets the second length
     
     float length_1;
     
     do
     {
          printf("Enter the second length: ");
          length_1 = get_float();
     }
     while (length_1 <= 0);
     
     // Gets the last length
     
     float length_2;
     
     do
     {
          printf("Enter the third length: ");
          length_2 = get_float();
     }
     while (length_2 <= 0);
     
     // Call the valid_triangle function
     
     printf("%i\n", valid_triangle(length_0, length_1, length_2));
 }
 
 bool valid_triangle(float a, float b, float c)
 {
      if ((a + b > c) && (a + c > b) && (b + c > a))
      {
           return true;
      }
      else
      {
           return false;
      }
 }