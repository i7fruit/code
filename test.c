#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct point
{
  int x;
  struct point *next;
}
point;

// Function prototypes
int get_int(char arr[]);
//point *begin(point *new_node, point *list);

int main()
{
    point * mypoint = NULL;

    /**
     * Dynamically allocate a new point
     * struct which mypoint points to here
     */

    while (true)
    {
        int number = get_int("Enter number: ");

        if (number == INT_MAX)
            break;

        // Create space for new node
        point *nu = (point *)malloc(sizeof(point));

        if (!nu)
        {
            fprintf(stderr, "Insufficient memory\n");
            return 1;
        }

        // Populate new node
        nu->x = number;
        nu->next = NULL;

        if (mypoint)
        {
            // Appends new node to list
            point *ptr = mypoint;
            while (ptr != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = nu;
        }
        else
        {
            // Make node first node in list
            mypoint = nu;
        }


        // Adds new node to front of list
        //add = begin(nu, mypoint);
    }

    // Prints list
    for (point *ptr = mypoint; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->x);
    }

    // Frees all nodes
    point *start = mypoint;
    while (start != NULL)
    {
        start->next = mypoint;
        free(start);
        start = mypoint;
    }

    return 0;
}

int get_int(char arr[])
{
    printf("%s", arr);

    int i = 0;

    scanf("%i", &i);

    if (feof(stdin))
        return INT_MAX;

    return i;
}

//point *begin(point *new_node, point *list)
//{
//    // Points new node to same address as start of list
//    new_node = list;
//    list->next = new_node;

//    return list;
//}