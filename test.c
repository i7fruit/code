#include <stdio.h>

int main(void)
{
    int values[] = {1, 2, 3};
    int *ptr = values;

    for (int i = 0; i < 3; i++)
        printf("%i ", *(ptr + i));

    return 0;
}