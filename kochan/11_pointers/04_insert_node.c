/**
 * 04_insert_node.c
 *
 * Monday, March 13 2023 21:19hrs
 *
 * This program illustrates how a node (struct) is
 * added to a linked list. Linked lists usually have
 * a pointer that points to the start of the list, and
 * a null pointer that marks the end of the list.
*/
#include <stdio.h>

// Structure definition
typedef struct entry
{
    int value;
    struct entry *next;
}
entry;

int main(void)
{
    // Structure declaration
    entry first, second, third;
    // Struct pointer to the start of the list
    entry *list_ptr = &first;

    first = (entry){100, &second};
    second = (entry){200, &third};
    third = (entry){300, (struct entry *)0};

    // Traverses the list
    entry *tracker = list_ptr;

    while (tracker != (struct entry *)0)
    {
        printf("%i\n", tracker->value);
        tracker = tracker->next;
    }

    // Inserts a node into the linked list between second and third
    entry inserted = {400, (struct entry *)0};

    // First sets the new node to point to third
    inserted.next = second.next;

    // Sets second to point to new node
    second.next = &inserted;

    // Traverses the new list
    tracker = list_ptr;

    while (tracker != (struct entry *)0)
    {
        printf("%i\n", tracker->value);
        tracker = tracker->next;
    }

    return 0;
}