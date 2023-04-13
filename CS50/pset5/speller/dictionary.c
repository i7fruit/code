// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Number of words in file
unsigned int count = 0;

void deallocate(node *ptr);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hashes word to obtain a hash value
    unsigned int index = hash(word);

    // Access linked list at the index that matches the hash value
    for (node *ptr = table[index], *temp = NULL; ptr != NULL; ptr = temp)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }

        temp = ptr->next;
    }

    // Traverses list looking for matching word
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (islower(*word))
    {
        return *word - 'a';
    }

    return *word - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char buffer[LENGTH + 1];

    // Opens file for reading
    FILE *fptr = fopen(dictionary, "r");
    if (!fptr)
    {
        return false;
    }

    // Reads from dictionary file
    while (fscanf(fptr, "%s", buffer) != EOF)
    {
        // Creates a node for the word
        node *string = malloc(sizeof(node));
        if (!string)
        {
            fprintf(stderr, "Insufficient Memory\n");
            fclose(fptr);
        }

        // Populates the node
        strcpy(string->word, buffer);
        string->next = NULL;

        // Tracks number of words read
        count++;

        unsigned int index = hash(buffer);

        // Adds to hash table
        for (unsigned int i = 0; i < N; i++)
        {
            if (i == index)
            {
                if (table[index])
                {
                    string->next = table[index];
                    table[index] = string;
                }

                else if (!table[index])
                {
                    table[index] = string;
                }
            }
        }
    }

    fclose(fptr);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    unsigned int i = 0;

    while (i < N)
    {
        deallocate(table[i]);
        i++;
    }

    return true;
}

void deallocate(node *ptr)
{
    if (ptr)
    {
        for (node *trav = ptr, *tmp = NULL; trav != NULL; trav = tmp)
        {
            tmp = trav->next;
            free(trav);
        }
    }
}