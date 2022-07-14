/**
 * 09_array_sum.c
 *
 * Tuesday, July 12 2022 17:59hrs
 *
 * This program calculates the sum of the
 * values of elements of an array and returns
 * it to Main.
 */
#include <stdio.h>

// Function prototypes
int get_integer(void);
void fill_array(int array[]);
void print_array(int array[]);

int main(void)
{
    int size = 0;

    printf("Enter array size: ");
    size = get_integer();

    int values[size];

    fill_array(values);
    print_array(values);
}

/***************************
 * get_integer()
 */
int get_integer(void)
{
    int temp = 0;

    scanf("%i", &temp);

    return temp;
}

/*************************
 * fill_array()
 */
void fill_array(int array[])
{
    int size = sizeof(array) / sizeof(array[0]);

    for (short i = 0; i < size; i++)
        scanf("%i", &array[i]);
}

/**************************
 * print_array()
 */
void print_array(int array[])
{
    int size = sizeof(array) / sizeof(array[0]);

    for (short i = 0; i < size; i++)
        printf("%i ", array[i]);

    putchar('\n');
}