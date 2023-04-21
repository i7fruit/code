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
#include <ctype.h>

// Structure definition
typedef struct entry
{
    int id;
    int value;
    struct entry *next;
}
entry;

// Function prototypes
void get_data(int **id, int **val);
void print_list(entry *list);
int build_list(entry *start, int *id, int *value);

int main(void)
{
    int value = 0, id = 0;

    // Pointer to the start of the linked list
    entry *start = NULL;

    int i = build_list(start, &id, &value);
    fopen("/dev/tty", "r");

    printf("Enter a value for i\n");
    getchar();
    scanf("%i", &i);

    printf("%i\n", i);

    return 0;
}

/*********************************
 * get_data()
*/
void get_data(int **id, int **val)
{
    do
    {
        scanf("%i %i", *id, *val);

        // Exits the do-while loop if the user hits ctrl+d
        if (feof(stdin))
        {

            **val = INT_MAX;
            break;
        }
    }
    while (**id < 1);
}

/***********************************
 * print_list()
*/
void print_list(entry *list)
{
    for (entry *trav = list; trav != NULL; trav = trav->next)
        printf("ID: %3i, Value: %3i\n", trav->id, trav->value);
}

/***********************************
 * build_list()
*/
int build_list(entry *start, int *id, int *value)
{
     while (true)
    {
        // Prompts user for data
        printf("Enter an ID and a value: ");
        get_data(**id, **value);

        // Stops the loop if the user hits ctrl+d
        if (**value == INT_MAX)
        {
            printf("Linked list completed\n");
            break;
        }

        // Checks if the ID has previously been used
        bool is_used = false;

        for (entry *ptr = start; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->id == **id)
            {
                is_used = true;
                break;
            }
        }

        // Appends the data to the list if the ID is unique
        if (!is_used)
        {
            // Create new node for data
            entry *nu = malloc(sizeof(entry));
            if (!nu)
            {
                fprintf(stderr, "Insufficient memory\n");
                return 1;
            }

            // Initializes the node
            nu->id = id;
            nu->value = value;
            nu->next = NULL;

            // Appends node if list isn't null
            if (start)
            {
                nu->next = start;
                start = nu;
            }
            else
                // Appends first node if list is null
                start = nu;
        }
    }

    putchar('\n');
    print_list(start);

    entry *ptr = start;
    while (ptr != NULL)
    {
        entry *trav = ptr->next;
        free(ptr);
        ptr = trav;
    }

    return 0;
}