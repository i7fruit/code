#include <stdio.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node *next;
}
node;

void insert(node *start, node *ptr);

int main(void)
{
    node one, two, three;
    node *list = &one;
    one = (node){1, &two};
    two = (node){2, &three};
    three = (node){3, NULL};

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i ", ptr->val);

    putchar('\n');

    insert(list, list);

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i ", ptr->val);

    return 0;
}

void insert(node *start, node *ptr)
{
    node nu = {40, NULL};

    for (node *trav = start; trav != NULL; trav = trav->next)
    {
        if (trav == ptr)
        {
            nu.next = ptr->next;
            ptr->next = &nu;
            break;
        }
    }
}