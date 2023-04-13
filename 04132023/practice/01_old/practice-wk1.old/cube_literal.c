#include <stdio.h>
#include <cs50.h>

int cube(int input);

int main(void)
{   
   /* Prints the cube of a given number
    * The Cube function is called within
    * printf */
   
   printf("The cube is %i\n", cube(3));
}

int cube(int input)
{
    return input * input * input;
}
