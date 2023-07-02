#include <stdio.h>

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%i ", *(arr + i));
}

int main(void)
{
    int values[] = {1, 12, 300};
    int *ptr = values;

    print(ptr, 3);

    return 0;
}