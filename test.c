#include <stdio.h>
#include <limits.h>

int main(void)
{
    char word[12];

    int i = 0;

    do
    {
        word[i] = getchar();
    }
    while (word[i] != '\n');

    printf("%s\n", word);

    return 0;
}