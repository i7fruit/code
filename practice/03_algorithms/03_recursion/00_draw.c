/**
 * 00_draw.c
 *
 * Friday, February 17 2023, 09:37hrs
 *
 * This program prints a triangle using
 * a recursive function
*/
#include <stdio.h>

// Function prototype
void draw(int i);

int main(void)
{
    draw(3);
}

/********************************************
 * draw()
*/
void draw(int i)
{
    if (i == 1)
    {
        return;
    }

    else
    {
        draw(i - 1);
    }

    for (int j = 0; j < i; j++)
        printf("#");
}