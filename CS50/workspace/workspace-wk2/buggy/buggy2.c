/*
 * Introduces eprintf as a debugging tool
 * for the cs50 course
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for (int i = 0; i < 10; i++) // Original bug was at i <= 10
    {
        printf("#\n");
        eprintf("I is now %i.\n", i); // This is to be used temporarily. Shouldn't be with final product
    }
}