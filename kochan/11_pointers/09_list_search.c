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
int get_integer(char arr[]);
entry *ptr find_entry(entry *start, int search_item);

int main(void)
{
    entry first, second, third;
    first = (entry){100, &second};
    second = (entry){200, &third};
    third = (entry){300, (struct entry *) 0};

    int number = get_integer("Number: ");

    entry *ptr = find_entry(&first, number);

    if (ptr)
    {
        printf("%i found.\n", ptr->value);
        return 0;
    }

    printf("%i not found.\n", number);

    return 1;
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

/**************************************************************
 * The find_entry() function takes a pointer to the start of a
 * linked list as well as a value to search for within the list
 * as arguments. If the value is found, it returns a pointer to
 * the node that contains that value, otherwise it returns a
 * null pointer.
*/
entry *ptr find_entry(entry *start, int search_item)
{
    // Traverses through the linked list
    while (start != (struct entry *) 0)
    {
        entry *ptr = start;

        if (ptr->value == number)
            return ptr;

        start = ptr->next;
    }

    return (struct entry *) 0;
}