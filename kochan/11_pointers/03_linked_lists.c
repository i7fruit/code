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
    entry *next;
}
entry;

int main(void)
{
    // Declares 
}