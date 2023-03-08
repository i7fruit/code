/**
 * insert_node0.c
 *
 * Thurs, Sept 20 2018 18:05hrs
 *
 * This program creates a singly linked list
 * and asks if the user wants to add an additional node
 * to the list. If the user does, the program adds a node
 * to the start of the list--since the list does not need to be sorted
 * this would be a better decision to make programmatically
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "mystruct.h"

// Function prototypes
bool in_list(entry *ptr, int i);
void print_list(entry *ptr);
void deallocate(entry *ptr);
entry *insert(entry *ptr, int x);
bool prompt(void);

int main(void)
{
    while (true)
    {
        int val = get_int("Enter val: ");
        if (val == INT_MAX)
            break;

        // Checks if the value is already in the list
        if (in_list(list_start, val))
        {
            puts("Value already exits. Try again");
            continue;
        }

        else
        {
            // Creates space for the value
            entry *nu = (entry *)malloc(sizeof(entry));
            if (nu == NULL)
            {
                fprintf(stderr, "Insufficient memory\n");
                if (list_start != (entry *)0)
                    free(list_start);

                return -1;
            }
            nu->value = val;
            nu->next = NULL;

            if (list_start != NULL)
            {
                for (entry *ptr = list_start; ptr != NULL; ptr = ptr->next)
                {
                    if (ptr->next == NULL)
                    {
                        ptr->next = nu;
                        break;
                    }
                }
            }

            else
                list_start = nu;
        }
    }

    // Prints the contents of the list
    puts("\nVALUES IN LIST");
    print_list(list_start);

    // Asks the user if he wishes to insert a node
    if (prompt())
    {
        int nu = get_int("Enter value to insert: ");
        list_start = insert(list_start, nu);
        puts("AFTER INSERTION");
        print_list(list_start);
    }

    if (list_start != NULL)
        deallocate(list_start);

    return 0;
}

/******************************************************************************
 * IN_LIST()
 *
 * The in_list() function interates through a linked list checking each entry
 * for a specific value. If it finds the value it returns true to indicate that
 * the value exits in the linked list, and false otherwise
 */
bool in_list(entry *ptr, int i)
{
    for (entry *trav = ptr; trav != NULL; trav = trav->next)
        if (trav->value == i)
            return true;

    return false;
}

/******************************************************************************
 * PRINT_LIST()
 *
 * This function iterates through a linked list and prints the value contained
 * in it's data field
 */
void print_list(entry *ptr)
{
    entry *trav = ptr;
    while (trav != NULL)
    {
        printf("%i ", trav->value);
        trav = trav->next;
    }
}

/******************************************************************************
 * DEALLOCATE()
 *
 * This function recursively deallocates memory allocated to a linked list
 */
void deallocate(entry *ptr)
{
    if (ptr != NULL)
        deallocate(ptr->next);

    free(ptr);
}

/******************************************************************************
 * INSERT()
 *
 * The insert() function adds a new node to the beginning of a linked list
 */
entry *insert(entry *ptr, int x)
{
    entry *extra = (entry *)malloc(sizeof(entry));
    if (extra == NULL)
    {
        fprintf(stderr, "Insufficient memory\n");
        exit(1);
    }

    if (ptr != NULL)
    {
        extra->value = x;
        extra->next = ptr;
        ptr = extra;
    }

    return ptr;
}

bool prompt(void)
{
    bool flag = true;

    while (flag == true)
    {
        printf("\nDo you want to insert a new node?\n");
        char c = get_char("y/n: ");

        c = toupper(c);

        switch(c)
        {
            case 'Y':
            case 'y':
                flag = false;
                break;

            case 'N':
            case 'n':
                return false;

            default:
                puts("Invalid entry");
                break;
        }
    }

    return true;
}