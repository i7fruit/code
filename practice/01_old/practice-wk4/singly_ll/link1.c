/**
 * link0.c
 *
 * Thurs Oct 04 2018 17:34hrs
 *
 * This illustrates a link list
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cs50.h>

#include "mystruct.h"

bool search(entry *head, int x);
entry *create(int x);
entry *insert(entry *head, int x);
void deallocate(entry *node);

int main(void)
{
    while (true)
    {
        // Prompts the user to enter a value
        int nmb = get_int("Enter value: ");
        if (nmb == INT_MAX)
            break;

        // Checks if value was entered previously
        if (search(list_start, nmb))
        {
            printf("%i exists in the list. Try again\n", nmb);
            continue;
        }

        // Executes if value wasn't previously entered
        else
        {
            // Creates and inserts a node at the start of the list
            list_start = insert(list_start, nmb);
        }
    }

    putchar('\n');

    // Prints the list
    entry *ptr0 = list_start;
    while (ptr0 != NULL)
    {
        printf("%i\n", ptr0->value);
        ptr0 = ptr0->next;
    }

    // Deallocates memory using recursion
    deallocate(list_start);

    return 0;
}

/******************************************************************************
 * DEALLOCATE()
 *
 * The deallocate() function recursively
 * frees memory starting from the end of
 * the list all the way to the start
 *
 * It iterates through the linked list
 * and frees the node with the null
 * pointer before freeing the ones before it
 */
void deallocate(entry *node)
{
    if (node != NULL)
        deallocate(node->next);

    free(node);
}

/******************************************************************************
 * SEARCH()
 *
 * This function searches a linked list
 * for a specific value. It returns true
 * if the value exits, and false otherwise
 */
bool search(entry *head, int x)
{
    // Creates a traversal pointer
    entry *trav = head;

    for (; trav != NULL; trav = trav->next)
    {
        if (trav->value == x)
            return true;
    }

    return false;
}

/******************************************************************************
 * CREATE()
 *
 * This function creates a new node
 * using the function malloc()
 */
entry *create(int x)
{
    entry *nu = (entry *)malloc(sizeof(entry));
    if (!nu)
    {
        // Prints notification and returns null
        fprintf(stderr, "Insufficient memory\n");
        return (entry *)0;
    }
    nu->value = x;
    nu->next = NULL;

    return nu;
}

/******************************************************************************
 * INSERT()
 *
 * This function inserts a new node
 * into a linked list
 */
entry *insert(entry *head, int x)
{
    entry *trav = head;

    entry *nu = create(x);

    nu->next = trav;

    return nu;
}