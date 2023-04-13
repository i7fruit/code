/**
 * PSET 1
 * mario.c (more comfortable)
 *
 * January 12 2020 16:25 EST
 *
 * This program prompts the user for
 * an integer and prints two trianges
 * on the screen separated by a space
 */
#include <stdio.h>
#include <cs50.h>

// Function prototype
short get_height(void);
void build_pyramid(short b);

int main(void)
{
    // Prompts the user for the height of the pyramids
    short h = get_height();

    // Calls the build_pyramid() function
    build_pyramid(h);

    return 0;
}

/**
 * The get_height() function uses a do-while loop
 * to prompt the user for a positive integer.
 */
short get_height(void)
{
    short i;

    do
    {
        i = get_int("Enter pyramid height: ");
    }
    while (i < 1 || i > 8);

    return i;
}

/**
 * The build_pyramid() function uses a series of for-loops
 * to build two pyramids
 */
void build_pyramid(short b)
{
    // Stores value for spaces count
    short s = b - 1;
    // Stores spaces for pound count
    short p = 1;

    // Builds pyramids
    for (short x = 0; x < b; x++)
    {
        // Builds left half
        for (short y = 0; y < s; y++)
        {
            printf(" ");
        }

        for (short z = 0; z < p; z++)
        {
            printf("#");
        }

        printf("  ");

        // Builds right half
        s--, p++;

        for (short z = 1; z < p; z++)
        {
            printf("#");
        }

        printf("\n");
    }
}