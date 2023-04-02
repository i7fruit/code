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

      // Adds new node to front of list
      for (point *ptr = mypoint; ptr != NULL; ptr = ptr->next)
      {
          // If the current node has a null pointer, connect new node to it
          if (ptr->next == NULL)
          {
              ptr->next = nu;
              break;
          }
      }
  }

      // Prints the list
      for (point *ptr = mypoint; ptr != NULL; ptr = ptr->next)
          printf("%i ", ptr->x);

      // Free nodes
      point *track = mypoint;
      while (track != NULL)
      {
          point *ptr = track->next;
          free(track);
          track = ptr;
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