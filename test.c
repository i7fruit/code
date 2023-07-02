#include <stdio.h>

int main(void)
{
    int values[] = {1, 2, 3};
    int *ptr = values;

    printf("%i\n", *(ptr + 2));

    return 0;
}