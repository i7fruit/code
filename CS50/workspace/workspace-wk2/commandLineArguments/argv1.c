/*
 * argv1.c
 *
 * The program prints out the strings
 * in the argument vector of the program
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(int argc, string argv[])
 {
     // Iterates over the string of the command line arguments
     for (int i = 0; i < argc; i++)
     {
         printf("%s ", argv[i]);
     }

     putchar('\n');
     
     return 0;
 }