/**
 * 00_linear_search.c
 *
 * Sunday, February 12, 2023 21:39hrs
 *
 * Linear search searches an array linearly
 * to find a specific number. It compares the
 * value in each element with the searched number.
*/
#include <stdio.h>

int main(void)
{
    short values[] = {-9, 4, 123, 0, 2};

    short search_item = 123, size = 5;

    for (int i = 0; i < size; i++)
    {
        // Returns 0 if the value was found
        if (values[i] ==  search_item)
        {
             printf("Value found\n");
             return 0;
        }
    }

    // Returns 1 if the value was not found
    printf("Value NOT found\n");

    return 1;
}