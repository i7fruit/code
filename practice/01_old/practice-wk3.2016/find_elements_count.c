/*
 * size_of_array.c
 */
 
 #include <stdio.h>
 
 int main(void)
 {
     int array[] = {5, 2, 0, 4, 8, -3, 321};
     
     int count = sizeof(array) / sizeof(array[0]);
     
     printf("Array count is %i\n", count);
 }