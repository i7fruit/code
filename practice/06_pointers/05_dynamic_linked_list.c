/**
 * 05_dynamic_linked_list.c
 *
 * Friday, April 07 2023 00:12hrs
 *
 * This program illustrates the dynamic
 * allocation of memory to build a linked
 * list.
*/
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Structure definition
typedef struct entry
{
    int value;
    struct entry *next;
}
entry;

int main(void)
{
    // Creates a pointer to the start of the list
    entry *list_start = NULL;

    while (true)
    {
        // Prompts user for input
        int number = get_int("Number: ");
    }

    return 0;
}

/******************************************************
 * get_int()
*/
int get_int(char *arr)
{
    printf("%s", arr);

    int i = 0;

    scanf("%i", &i);

    // If the user hits ctrl+d, return 2147483647
    if (feof(stdin))
        return INT_MAX;
}