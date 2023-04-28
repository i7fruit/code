#include <stdio.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node *next;
}
node;

int main(void)
{
    node one, two, three;
    node *list = &one;
    one = (node){1, &two};
    two = (node){2, &three};
    three = (node){3, NULL};

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("%i ", ptr->val);

    insert()

    return 0;
}