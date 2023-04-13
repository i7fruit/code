/**
 * 00_triangular.c
 *
 * Tuesday, June 28 2022 23:26hrs
 *
 * Creates a function that calculates
 * a triangular number and returns it
 * to the calling function.
 */
#include <stdio.h>

// Function prototypes
short get_integer(void);
int triangular_number(short value);

int main(void)
{
    short size = 0;

    size = get_integer();

    printf("Triangular number %hi = ", size);

    printf("%i\n", triangular_number(size));

    return 0;
}

/****************************************
 * The get_integer() function prompts
 * the user to give a positive integer.
 */
short get_integer(void)
{
    short size = 0;

    do
    {
        printf("What triangular number do you want to find? ");
        scanf("%hi", &size);
    }
    while (size < 1 || size > 50);

    return size;
}

/*****************************************
 * The triangular_number() function takes
 * a short integer, calculates the triangular
 * number using a forloop, and returns an integer
 * to the calling function.
 */
int triangular_number(short value)
{
    int triangular = 0;

    for (short i = 1; i <= value; i++)
    {
        triangular += i;
    }

    return triangular;
}