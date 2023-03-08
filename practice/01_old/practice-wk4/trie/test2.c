#include <stdio.h>
#include "dict.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // Ends program if argc is incorrect
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s dictionary_name\n", argv[0]);
        return 1;
    }

    // Loads the dictionary into the trie
    if (load(argv[1]))
        puts("Sucessfully loaded");

    else
        puts("Dictionary not loaded");

    printf("Dictionary contains %i words\n", size());

    puts("What word are you looking for?");
    char search[LEN];
    scanf("%s", search);

    // Checks if the word exits in the trie
    if (check(search))
        puts("Word exists");

    else
        puts("No such word in the dictionary");

    // Deallocates allocated memory
    if (unload())
        puts("Sucessfully unloaded dictionary");

    else
        puts("Unable to unload dictionary");

    return 0;
}


/******************************************************************************
 * LOAD()
 *
 * Loads dictionary into memory, returning true if successful, else false
 */
bool load(const char *dictionary)
{
    // Creates the root node
    root = create();
    for (short i = 0; i < MAX; i++)
    {
        root->children[i] = NULL;
        root->is_word = false;
    }

    FILE *fptr = fopen(dictionary, "r");
    if (!fptr)
    {
        fprintf(stderr, "Cannot open dictionary\n");
        return false;
    }

    node *trav = root;
    char c;
    while ((c = fgetc(fptr)) != EOF)
    {
        if (c != '\n')
        {
            if (c != '\'')
            {
                if (trav->children[c - CASE] == NULL)
                {
                    trav->children[c - CASE] = create();
                    trav = trav->children[c - CASE];
                }

                else
                {
                    trav = trav->children[c - CASE];
                }
            }

            else if (c == '\'')
            {
                if (trav->children[MAX - 1] == NULL)
                {
                    trav->children[MAX - 1] = create();
                    trav = trav->children[MAX - 1];
                }

                else
                {
                    trav = trav->children[MAX - 1];
                }
            }
        }

        else
        {
            trav->is_word = true;
            ctr++;
            trav = root;
        }
    }

    fclose(fptr);

    return true;
}

/******************************************************************************
 * CREATE()
 *
 * Creates a new node
 */
node *create(void)
{
    node *n = (node *)malloc(sizeof(node));
    if (!n)
    {
        fprintf(stderr, "Insufficient memory\n");
        return (node *)0;
    }
    for (short i = 0; i < MAX; i++)
                    {
                        n->children[i] = NULL;
                        n->is_word = false;
                    }

    return n;
}

/******************************************************************************
 * CHECK()
 *
 * Returns true if word is in dictionary else false
 */
bool check(const char *word)
{
    node *trav = root;
    short i = 0;
    char c;

    while ((c = tolower(word[i])) != '\0')
    {
        if (c != '\'')
        {
            if (trav->children[c - CASE] == NULL)
            {
                return false;
            }

            else
            {
                trav = trav->children[c - CASE];
                i++;
            }
        }

        else if (c == '\'')
        {
            if (trav->children[MAX - 1] == NULL)
            {
                return false;
            }

            else
            {
                trav = trav->children[MAX - 1];
                i++;
            }
        }
    }
    return trav->is_word;
}

/******************************************************************************
 * UNLOAD()
 *
 * Unloads the dictionary
 */
bool unload(void)
{
    if (root != NULL)
    {
        deallocate(root);
    }

    return true;
}

/******************************************************************************
 * DEALLOCATE()
 *
 * Deallocates memory alloted to every node in the trie
 */
void deallocate(node *letter)
{
    for (short i = 0; i < MAX; i++)
    {
        if (letter->children[i] != NULL)
        {
            deallocate(letter->children[i]);
        }
    }

    free(letter);
}

/******************************************************************************
 * SIZE()
 *
 * Calculates the size of the dictionary
 */
unsigned int size(void)
{
    return ctr;
}