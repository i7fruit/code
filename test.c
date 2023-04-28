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
    node three = {1, &two}, two = {2, &three}, one = {3, NULL};

    printf("%i\n%i\n%i\n", one->val, two->val, three->val);

    return 0;
}