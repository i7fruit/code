#include <stdio.h>

void print(char *arr, int n);

int main(void)
{
    char values[] = {"one"};
    char *ptr = values;

    print(ptr, 3);

    return 0;
}

void print(char *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", *(arr + i));
}