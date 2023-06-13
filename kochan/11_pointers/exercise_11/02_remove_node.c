/**
 * 02_remove_node_dll.c
 *
 * Sunday, June 04 2023 21:33hrs
 *
 * This program prompts the user for a position
 * to remove a node from, or insert a node into a
 * linked list using a doubly-linked list
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

// Global variables
int node_count;
int insertion_point;
bool add_at_end;
bool add_at_01;

// Structure definition
typedef struct entry
{
    int id;
    int value;
    struct entry *prev;
    struct entry *next;
}
entry;

// Function prototypes
void get_data(int *id, int *val);
void print_list(entry *list);
entry *get_position(entry *list);
entry *insert_node(entry *start, entry *position);

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
             nu->prev = NULL;
             nu->next = NULL;

             // Appends node if list isn't null
             if (start)
             {
                 nu->next = start;
                 start->prev = nu;
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

     // Asks the user if they wish to continue with other operations
     printf("\nOPTIONS MENU\nInsert node (i)\nRemove node (r)\nQuit (q)\n\nSelect option: ");
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
         case 'i':
         {
            entry *position = NULL;
            position = get_position(start);
            start = insert_node(start, position);
            break;
         }
         case 'r':
         {
            entry *position = NULL;
            position = get_position(start);
            //start = insert_node(start, position);
            break;
         }
         case 'q':
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

 /***************************************************************************************************
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

 /***************************************************************************************************
  * print_list()
 */
 void print_list(entry *list)
 {
     for (entry *trav = list; trav != NULL; trav = trav->next)
         printf("ID: %2i, Value: %3i\n", trav->id, trav->value);
 }

 /***************************************************************************************************
  * insert_node()
 */
 entry *insert_node(entry *start, entry *position)
 {
     // Prompts user for data to insert
     int id = 0, val = 0;
     bool is_present = true;
     entry *trav = NULL;

     do
     {
        printf("Enter data for node to insert: ");
        get_data(&id, &val);

        // Checks if ID already exists in the list
        for (trav = start; trav != NULL; trav = trav->next)
        {
            if (trav->id == id)
                break;
        }

        if (!trav)
            is_present = false;
     }
     while (is_present);

     // Allocates memory for the new node
     entry *nu = malloc(sizeof(entry));
     if (!nu)
     {
         fprintf(stderr, "Insufficient memory\n");
         exit(1); // <--- Check if this line causes a memory leak <<<<<<<<<<<<<<<<<<<<<<<<<<|||||||||||||
     }

     // Initializes the node
     nu->id = id;
     nu->value = val;
     nu->prev = NULL;
     nu->next = NULL;

     if (position == start)
     {
         if (add_at_01)
         {
             nu->next = start;
             start = nu;
         }

         else
         {
             nu->next = start->next;
             start->next = nu;
             nu->prev = start;
         }
     }

     else if (add_at_end)
     {
         position->next = nu;
         nu->prev = position;
     }

     else
     {
         nu->next = position->next;
         position->next = nu;
         nu->prev = position;
     }

     return start;
 }

 /***************************************************************************************************
  * get_position()
 */
 entry *get_position(entry *list)
 {
     int j = node_count + 1;
     add_at_01 = false, add_at_end = false;

     do
     {
         printf("Enter element to insert node (Element_%.2i - Element_%.2i): ", (insertion_point + 1), j);
         scanf("%i", &insertion_point);
     }
     while (insertion_point < 1 || insertion_point > j);

     /**
      * Turns on the add_at_01 flag and returns
      * a pointer to the start of the list if user
      * wants to insert node at start of list
      */
     if (insertion_point == 1)
     {
         add_at_01 = true;
         return list;
     }

     /**
      * Otherwise, returns pointer to start of list
      * if insertion is at second node in list
      */
     else if (insertion_point == 2)
         return list;

     // Finds node to return if insertion point is beyond the second node
     entry *ptr = NULL, *prev = NULL;
     for (ptr = list; ptr != NULL; ptr = ptr->next)
     {
         static int count = 1;

         // Returns node prior to insertion point
         if (count == insertion_point)
             return ptr->prev;

         count++;
         prev = ptr->prev;
     }

     // Returns last node in list if insertion is after last node in list
     add_at_end = true;
     return prev;
 }

  /***************************************************************************************************
  * remove_node()
 */
 entry *remove_node(entry *start, entry *position)
 {
     // Prompts user for node to remove
     int id = 0, val = 0;
     printf("Enter data for node to delete: ");
     get_data(&id, &val);

     // Allocates memory for the new node
     entry *nu = malloc(sizeof(entry));
     if (!nu)
     {
         fprintf(stderr, "Insufficient memory\n");
         exit(1); // <--- Check if this line causes a memory leak <<<<<<<<<<<<<<<<<<<<<<<<<<|||||||||||||
     }

     // Initializes the node
     nu->id = id;
     nu->value = val;
     nu->prev = NULL;
     nu->next = NULL;

     if (position == start)
     {
         if (add_at_01)
         {
             nu->next = start;
             start = nu;
         }

         else
         {
             nu->next = start->next;
             start->next = nu;
             nu->prev = start;
         }
     }

     else if (add_at_end)
     {
         position->next = nu;
         nu->prev = position;
     }

     else
     {
         nu->next = position->next;
         position->next = nu;
         nu->prev = position;
     }

     return start;
 }