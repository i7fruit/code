/**
 * 04_ascending_sort.c
 *
 * Tuesday, July 04, 2023 14:16hrs
 *
 * This program sorts three numbers
 * in ascending order without the use
 * of arrays
*/
#include <stdio.h>
#include <limits.h>

// Function prototypes
void swap(int *ptr0, int *ptr1);
int get_integer(char *text);

int main(void)
{
    // Variables to store three integers
    int a = 0, b = 0, c = 0;

    if (a <= b && a <= c)
    {
        printf("%i ", a);

        if (b <= c)
            printf("%i %i\n", b, c);
        else
            printf("%i %i\n", c, b);
    }

    if (b <= a && b <= c)
    {
        printf("%i ", b);

        if (a <= c)
            printf("%i %i\n", a, c);
        else
            printf("%i %i\n", c, a);
    }

    if (c <= a && c <= b)
    {
        printf("%i ", c);

        if (a <= b)
            printf("%i %i\n", a, b);
        else
            printf("%i %i\n", b, a);
    }

    return 0;
}

/************************************
 * The swap() function swaps two
 * values
*/
void swap(int *ptr0, int *ptr1)
{
    int temp = *ptr0;
    *ptr0 = *ptr1;
    *ptr1 = temp;
}

/*************************************
 * get_integer()
*/
int get_integer(char *text)
{
    int number = 0;

    do
    {
        printf("%s: ", text);
        scanf("%i", &number);
    }
    while (number < -INT_MAX || number > INT_MAX);

    return number;
}