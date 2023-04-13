/*
 * The following program describes
 * the effect of a numeric overflow,
 * also known as integer overflow.
 */

#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int main(void)
{
    int n = 5;
    while(true) /* Condition statement can say 1 or true */
    {
        printf("n is %i\n", n);
        n += 250000000;
        sleep(1); // Pauses the program for specified seconds
    }
}
