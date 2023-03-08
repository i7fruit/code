// Struct represents an entry
typedef struct entry
{
    int value;
    struct entry *next;
}
entry;

// Points to the start of an entry list
entry *list_start;