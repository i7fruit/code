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

// Global variable
int node_count;

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
int get_position(void);

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
        int position = 0;
        case 'y':
            position = get_position();
            break;
        case 'n':
            printf("No\n");
            break;
        default:
            printf("Invalid entry\n");
            break;
    }

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
void insert_node(entry *start, entry *position)
{

}

/************************************
 * get_position()
*/
int get_position(void)
{
    int i = 0;

    do
    {
        printf("What position would you like to insert the node\n" \
    "Choose between position_%2i and position_%2i\n", 1, node_count);
        scanf("%i", &i);
    }
    while (i < 1 || i > node_count);
}