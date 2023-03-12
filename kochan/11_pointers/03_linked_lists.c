/**
 * 03_linked_lists.c
 *
 * Saturday, March 11 2023 19:54hrs
 *
 * This program creates a linked list using
 * structures that point to each other through
 * one of their members which is a pointer itself
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
    // Declares three struct entry variables
    entry first, second, third = {.value = 300, .next = NULL};

    first = (entry){100, &second};

    second.value = 200;
    second.next = &third;

    // Prints all three values
    printf("%i, %i, %i.\n", first.value, *(first.next.value), second.next->value);

    return 0;
}