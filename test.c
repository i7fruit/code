#include <stdio.h>
#include <limits.h>

typedef strut node
{
    int val;
    struct node 
}

int main(void)
{
    char word[] = "   ";

    int i = 0;

    do
    {
        word[i] = getchar();
    }
    while (word[i++] != '\n');

    printf("%s\n", word);

    return 0;
}