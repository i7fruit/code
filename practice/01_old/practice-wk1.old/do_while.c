#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declare a variable int
    int n = 0;

    do
    {
        printf("Please enter a positive number: ");
        n = get_int();
    }
    while(n < 1);

    printf("You typed %i\n", n);
}