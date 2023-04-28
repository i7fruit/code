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
    one = (node){1, &two};
    two = (node){2, &three};
    three = (node){3, NULL};

    printf("%i\n%i\n%i\n", one.val, two.val, three.val);

    return 0;
}