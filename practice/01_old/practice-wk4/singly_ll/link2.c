/**
 * link2.c
 *
 * Fri Oct 05 2018 22:56hrs
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 20

// Struct definition
typedef struct resident
{
    char name[MAX];
    int blk;
    int flt;
    struct resident *next;
}
res;

res *head = NULL;

// Function prototypes
res *get_data(void);
res *insert(res *start, res *node);
void deallocate(res *start);

int main(void)
{
    res *n = NULL;
    while (true)
    {
        // Prompts the user for input
        char c = 0;
        puts("New node? y/n");
        scanf(" %c", &c);
        getchar(); // Gets rid of '\n' from entering char

        if (tolower(c) == 'y')
            n = get_data();

        else if (tolower(c) == 'n')
            break;

        else
            continue;

        if (n == NULL)
            break;

        head = insert(head, n);
    }

    res *trav = head;
    while (trav != NULL)
    {
        printf("Name: %s\n", trav->name);
        printf("Block %i\n", trav->blk);
        printf("Flat %i\n\n", trav->flt);
        trav = trav->next;
    }

    if (n)
        deallocate(n);

    return 0;
}

/**************************************
 * GET_DATA()
 *
 * Gets input from the user and returns
 * a pointer to a node with populated
 * data.
 */
res *get_data(void)
{
    res *nu = (res *)malloc(sizeof(res));
    if (!nu)
    {
        fprintf(stderr, "Insufficient memory\n");
        return NULL;
    }

    printf("Enter resident's name\n");
    // short i = 0;
    // do
    // {
    //     nu->name[i] = getchar();
    // }
    // while (nu->name[i++] != '\n');
    // nu->name[--i] = '\0';
    fgets(nu->name, MAX, stdin);
    nu->name[strlen(nu->name) - 1] = '\0';

    puts("Enter resident's block number");
    scanf("%i", &nu->blk);

    puts("Enter resident's flat number");
    scanf("%i", &nu->flt);

    nu->next = NULL;

    return nu;
}

/**************************************
 * INSERT()
 *
 * The insert function inserts a node
 * to a linked list
 */
res *insert(res *start, res *node)
{
    // Inserts a node with data to the start of a linked list
    node->next = start;

    return node;
}

/**************************************
 * DEALLOCATE()
 *
 * Frees allocated memory one node at a
 * time, recursively
 */
void deallocate(res *start)
{
    if (start != NULL)
        deallocate(start->next);

    free(start);
}