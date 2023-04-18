/**
 * 00_insert_node.c
 *
 * Sunday, April 16 2023 21:55hrs
 *
 * This program prompts the user for a position
 * to insert a node into a linked list
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// Structure definition
typedef struct entry
{
    int id;
    int value;
    struct entry *next;
}
entry;

// Function prototypes
void get_data(int *id, int *val);

int main(void)
{
    int value = 0, id = 0;

    // Pointer to the start of the linked list
    entry *start = NULL;

    while (true)
    {
        // Prompts user for data
        printf("Enter an ID and a value: ");
        get_data(&id, &value);

        if (value == INT_MAX)
            break;
    }

    printf("%i %i\n", id, value);

    return 0;
}

/*********************************
 * get_data()
*/
void get_data(int *id, int *val)
{
    do
    {
        scanf("%i %i", id, val);

        if (feof(stdin))
        {
            *val = INT_MAX;
            break;
        }
    }
    while (*id < 1);
}