// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LEN 45

// Max number of valid characters.
#define MAX 27

// Needed to calculate node subscript
#define CASE 'a'

// Tracks number of words in the dictionary
unsigned int ctr;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

// Struct definition
typedef struct node
{
    bool is_word;
    struct node *children[MAX];
}
node;

node *root;

// Creates a new node
node *create(void);

void deallocate(node *letter);

#endif // DICTIONARY_H
