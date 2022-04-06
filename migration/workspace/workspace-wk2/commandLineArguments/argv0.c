/*
 * argv0.c
 *
 * command line arguments
 */
 
 #include <stdio.h>
 
 int main(int argc, char* argv[])
 {
     if (argc == 2)
     {
         printf("Yo, %s\n", argv[1]);
     }
     
     else
     {
         printf("Yo, what's poppin'?\n");
     }
     
     return 0;
 }