#include <stdio.h>

int main(void)
{
    int *numbers = NULL;
    int capacity = 0;

    int size = 0;

    while (true)
    {
        int number = get_int("Number: ");
    }
}

int get_int(char arr[])
{
    printf("%s", arr);

    int i = 0;
    scanf("%s", &i);

    if (i == INT_MAX)
       return INT_MAX;
}