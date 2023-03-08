/**
 * link0.c
 *
 * Wed Sept 19 2018 20:00hrs
 *
 * This illustrates a link list
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cs50.h>

#include "mystruct.h"

void deallocate(entry *node);

int main(void)
{
    // Points to the start of the list, but unnecessary cos one exits in header file
    entry *list = NULL;

    while (true)
    {
        // Prompts the user to enter a value
        int nmb = get_int("Enter value: ");
        if (nmb == INT_MAX)
            break;

        // Checks if value was entered previously
        bool flag = false;
        for (entry *ptr = list; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->value == nmb)
            {
                flag = true;
                puts("Value exits. Try again");
                break;
            }
        }

        // Executes if value wasn't previously entered
        if (!flag)
        {
            // Creates memory for new struct
            entry *nu = (entry *)malloc(sizeof(entry));
            if (nu == NULL)
            {
                fprintf(stderr, "Insufficient memory\n");
                free(list);
                return -1;
            }
            // Adds new value to new struct if new location is not null
            nu->value = nmb;
            nu->next = NULL;

            // Adds to the linked list
            if (list != NULL)
            {
                for (entry *ptr = list; ptr != NULL; ptr = ptr->next)
                {
                    if (ptr->next == NULL)
                    {
                        ptr->next = nu;
                        break;
                    }
                }
            }

            else
            {
                list = nu;
            }
        }
    }

    putchar('\n');

    // Prints the list
    entry *ptr0 = list;
    while (ptr0 != NULL)
    {
        printf("%i\n", ptr0->value);
        ptr0 = ptr0->next;
    }

    // Deallocates memory
    // entry *ptr = list;
    // while (ptr != NULL)
    // {
    //     entry *move = ptr->next;
    //     free(ptr);
    //     ptr = move;
    // }

    // Deallocates memory using recursion
    deallocate(list);

    return 0;
}

void deallocate(entry *node)
{
    if (node != NULL)
        deallocate(node->next);

    free(node);
}