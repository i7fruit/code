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

// Function prototype
int get_int(char *arr);

int main(void)
{
    // Creates a pointer to the start of the list
    entry *list_start = NULL;

    while (true)
    {
        // Prompts user for input
        int number = get_int("Number: ");

        // Stop prompting for numbers if user hits ctrl+d
        if (number == INT_MAX)
            break;

        // Creates a node in the list
        entry *node = (entry *)malloc(sizeof(entry));

        // Checks if pointer is null
        if (!node)
        {
            // Prints error to standar error
            fprintf(stderr, "Insufficient memory\n");
            return 1;
        }

        // Initializes the node
        node->value = number;
        node->next = NULL;

        // Adds the node to beginning of the list
        if (list_start)
        {
            // First points to first node on list...
            node = list_start;
            // ...then points start of list to new node
            list_start->next = node;
        }
        // Otherwise, create first node of the list
        else
        {
            list_start = nu;
        }
    }

    // Prints the list
    for (entry *ptr = list_start; ptr != NULL; ptr = ptr->next)
        printf("%i ", ptr->value);

    // Frees all nodes
    entry *ptr = list_start;
    while (ptr != NULL)
    {
        // Creats a pointer to traverse the list
        entry *trav = ptr->next;
        free(ptr);
        ptr = trav;
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

    return i;
}