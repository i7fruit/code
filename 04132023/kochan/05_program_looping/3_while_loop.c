/**
 *  3_while_loop.c
 *  Monday, April 11 2022 19:53hrs
 *  Prints from 1 through 5 using a
 *  while loop
 */
#include <stdio.h>

int main(void)
{
    short counter = 1;

    while (counter < 6)
    {
        printf("%hi ", counter);
        counter++;
    }

    printf("\n");

    return 0;
}