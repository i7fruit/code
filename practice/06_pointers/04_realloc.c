/**
 * 04_realloc.c
 *
 * Monday, April 03 2023 16:47hrs
 *
 * This program illustrates how an array can be
 * dynamically initialized using realloc
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
int get_int(char *arr);

int main(void)
{
    // Pointer to memory location for array
    int *values = NULL;
    int size = 0;

    // Prompts the user for input
    while (true)
    {
        int number = get_int("Number: ");
    }
}

/*********************************************
 * get_int()
*/
int get_int(char *arr)
{
    printf("%s", arr);
    int i = 0;
    scanf("%i", &i);

    if (feof(stdin))
        return INT_MAX;

    return i;
}