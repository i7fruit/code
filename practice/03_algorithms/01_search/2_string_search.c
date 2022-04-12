/**
 * 2_string_search.c
 * Saturday, March 12, 2022 12:29hrs
 * Uses the cs50 library function "string"
 * to store c-strings and search through them
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Stores a list of names
    string names[] = {"Asata", "Ojie", "Osugo"};

    // Prompts the user for their name
    string search_item = get_string("What is your name?: ");

    // Computes the size of the list to search through
    int size = sizeof(names) / sizeof(names[0]);

    for (short i = 0; i < size; i++)
    {
        if (strcmp(names[i], search_item) == 0)
        {
            printf("Welcome, %s.\n", search_item);
            return 0;
        }
    }

    printf("Sorry %s, you are not on the list.\n", search_item);
    return 1;
}