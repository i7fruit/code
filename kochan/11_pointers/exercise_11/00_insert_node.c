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

        // Checks if the ID has previously been used
        bool is_used = false;

        for (entry *ptr = start; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->id == id)
            {
                is_used = true;
                break;
            }
        }

        if (!is_used)
        {
            // Create new node for data
            entry *nu = malloc(sizeof(entry));
            if (!nu)
            {
                fprintf(stderr, "Insufficient memory\n");
                return 1;
            }

            if (start)
            {
                nu->next = start;
                start = nu;
            }
            else
                start = nu;
        }
    }

    // Free nodes
    entry *ptr = start;
    while (ptr != NULL)
    {
        entry *trav = ptr->next;
        free(ptr);
        ptr = trav;
    }

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