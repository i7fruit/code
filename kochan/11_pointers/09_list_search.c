/**
 * 09_list_search.c
 *
 * Friday, March 17 2023 17:46hrs
 *
 * This program traverses through a linked list
 * searching for a specific entry. Once the entry
 * is found, it returns a pointer to that entry.
*/
#include <stdio.h>
#include <limits.h>

// Struct definition
typedef struct entry
{
    int value;
    struct entry *next;
}
entry;

// Function prototypes


int main(void)
{
    entry first, second, third;
    first = (entry){100, &second};
    second = (entry){200, &third};
    third = (entry){300, (struct entry *) 0};

    int number = get_integer("Number: ");

    // Traverses through the linked list
    entry *list_start = &first; // Points to the start of the list

    while (list_start != (struct entry *) 0)
    {
        entry *ptr = list_start;
        if (ptr->)
    }
}

/*************************************************************
 * The get_integer() function returns an integer entered by
 * the user
*/
int get_integer(char arr[])
{
    printf("%s", arr);

    int i = 0;

    do
    {
        scanf("%i", &i);
    }
    while (i < 0 || i > INT_MAX);

    return i;
}