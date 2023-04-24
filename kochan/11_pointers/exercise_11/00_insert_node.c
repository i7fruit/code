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

// Global variables
int node_count;
int insertion_point;

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
void print_list(entry *list);
entry *get_position(entry *list);
bool insert_node(entry *start, entry *position);

int main(void)
{
    int value = 0, id = 0;

    // Pointer to the start of the linked list
    entry *start = NULL;

    while (true)
    {
        // Prompts user for data
        printf("Enter an ID and a value. Press ctrl+d to quit entering data.\n");
        get_data(&id, &value);

        // Stops the loop if the user hits ctrl+d
        if (value == INT_MAX)
        {
            printf("\nLinked list completed\n");
            break;
        }

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
                node_count++;
            }
            else
            {
                // Appends first node if list is null
                start = nu;
                node_count++;
            }
        }
    }

    // Prints the list
    putchar('\n');
    print_list(start);

    // Asks the user if they wish to insert a new node
    printf("Do you want to insert a new node? (y/n): ");
    int size = 10;
    char temp[size];
    char answer[size];
    fgets(temp, size, stdin);

    // Clears non-alphabets from entered text
    int i = -1, j = -1;
    while (temp[++i] != '\0')
    {
        if (!isalpha(temp[i]))
            continue;

        answer[++j] = temp[i];
    }

    switch (tolower(answer[0]))
    {
        case 'y':
        {
            entry *position = NULL;
            position = get_position(start);
            bool quit = insert_node(start, position);

            // Quits the switch and frees the list if pointer is null
            if (quit)
                break;
            break;
        }
        case 'n':
            printf("You have chosen to make no insertions to the linked list.\n");
            break;
        default:
            printf("Invalid entry\n");
            break;
    }

    print_list(start);

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

        // Exits the do-while loop if the user hits ctrl+d
        if (feof(stdin))
        {
            // Clears the EOF indicator for the stdin so that further input can be made if needed
            clearerr(stdin);
            *val = INT_MAX;
            break;
        }
    }
    while (*id < 1);
}

/***********************************
 * print_list()
*/
void print_list(entry *list)
{
    for (entry *trav = list; trav != NULL; trav = trav->next)
        printf("ID: %3i, Value: %3i\n", trav->id, trav->value);
}

/************************************
 * insert_node()
*/
bool insert_node(entry *start, entry *position)
{
    // Creates new node to insert
    entry *nu = malloc(sizeof(entry));
    if (!nu)
    {
        fprintf(stderr, "Insufficient memory\n");
        return 1;
    }

    int id = 0, val = 0;
    while (true)
    {
        printf("Enter an ID and a value: ");
        get_data(&id, &val);

        // Checks for id in list
        bool in_list = false;
        for (entry *ptr = start; ptr != NULL; ptr = ptr->next)
            if (ptr->id == id)
            {
                in_list = true;
                break;
            }

        if (!in_list)
        {
            if (insertion_point > 1 && insertion_point < node_count)
            {
                nu->id = id;
                nu->value = val;
                nu->next = position->next;
                position->next = nu;
                break;
            }
            else if (insertion_point == 0)
            {
                nu->id = id;
                nu->value = val;
                nu->next = start;
                start = nu;
                break;
            }
            else
            {
                nu->id = id;
                nu->value = val;
                position->next = nu;
                nu->next = NULL;
                break;
            }
        }
    }
    return 0;
}

/************************************
 * get_position()
*/
entry *get_position(entry *list)
{
    //int i = 0;

    do
    {
        printf("What position would you like to insert the node\n" \
    "Choose any position from position_%.2i to position_%.2i\n", 1, node_count);
        scanf("%i", &insertion_point);
    }
    while (insertion_point < 1 || insertion_point > node_count);

    // Iterates through the list to find a pointer to the node before the insertion point
    for (entry *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        static int count = 0;

        if (insertion_point == 1)
            return list;

        else if (insertion_point == node_count)
            return ptr->next;

        else if (count + 1 == insertion_point)
            return ptr;

        count++;
    }

    // To silence error warning in compiler
    return (entry *)0;
}