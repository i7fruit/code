#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size = 0;
    // printf("How many numbers do you want? ");
    // scanf("%hi", &size);
    size = get_int("Size: ");

    short search_item = 0;
    printf("What value do you wish to search for? ");
    scanf("%hi", &search_item);

    short values[size];

    // Gets numbers from user
    for (short i = 0; i < size; i++)
    {
        printf("value %i: ", i + 1);
        scanf("%hi", &values[i]);
    }

    // Searches array linearly for user-defined value
    for (short i = 0; i < size; i++)
    {
        if (values[i] == search_item)
        {
            printf("%hi found\n", search_item);
            return 0;
        }
    }

    printf("%hi not found\n", search_item);
    return 1;
}