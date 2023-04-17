/**
 * 00_insert_node.c
 *
 * Sunday, April 16 2023 21:55hrs
 *
 * This program prompts the user for a position
 * to insert a node into a linked list
*/
#include <stdio.h>

// Structure definition
typedef struct entry
{
    int id;
    int value;
    struct entry *next;
}
entry;

int main(void)