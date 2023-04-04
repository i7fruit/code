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
    int size = 0, element = 0;

    // Prompts the user for input
    while (true)
    {
        int number = get_int("Number: ");

        if (number == INT_MAX)
            break;

        // Adds value to array
        if (element == size)
        {
            int *nu = realloc(values, sizeof(int) * (element + 1));

            // Returns if pointer is null
            if (!nu)
            {
                fprintf(stderr, "Insufficient memory\n");

                // Free memory of array is not null
                if (values)
                {
                    free(values);
                }

                return 1;
            }

            values = nu;
            size++;

            values[element] = number;
            element++;
        }
    }

    putchar('\n');

    // Prints the array
    for (int i = 0; i < size; i++)
        printf("%i ", values[i]);

    putchar('\n');

    // Frees used memory
    free(values);

    return 0;
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