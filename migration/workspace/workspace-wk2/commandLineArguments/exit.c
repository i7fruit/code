/*
 * exit.c
 *
 * Main() returns an int. In this
 * program, it returns a 0 if everything
 * executes as it should, but a 1 if it
 * doesn't
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(int argc, string argv[])
 {
     // Displays a warning message and tone, and exits the program if argc is not 2
     if (argc != 2)
     {
         printf("\aUSAGE:./programName argv1\n");
         return 1;
     }
     // Prints a message as well as the second string if argc is 2
     printf("Welcome, %s\n", argv[1]);
     return 0;
     
     /*
      * NOTE: TO VIEW THE EXIT CODE OF THE PROGRAM, USE THE LINE
      * echo $?
      */
 }