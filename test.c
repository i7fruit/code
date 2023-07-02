#include <stdio.h>

void print(char *arr[], int n);

int main(void)
{
    char values[][10] = {"one", "two", "three"};
    char *ptr = values;

    print(ptr, 3);

    return 0;
}

void print(char *arr[], int n)
{
    for (int i = 0; i < n; i++)
       for(int j = 0; *(arr + (i*j)) != '\0'; j++)
            printf("%c ", *(arr + (i*j));

        putchar('\0');
}