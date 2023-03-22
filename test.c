#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int get_int(char arr[]);

int main(void)
{
    int *numbers = NULL;
    int capacity = 0;


    int size = 0;

    while (true)
    {
        int number = get_int("Number: ");

        if (number == INT_MAX)
            break;

        int *nu = realloc(numbers, sizeof(int) * (size + 1));

        if (!nu)
        {
            fprintf(stderr, "Insufficient memory\n");
            if (numbers)
               free(numbers);
            return 1;
        }

        numbers = nu;
        capacity++;

        numbers[size] = number;
        size++;
    }

    for (int z = 0; z < size; z++)
        printf("%i ", numbers[z]);

    putchar('\n');

    return 0;
}

int get_int(char arr[])
{
    printf("%s", arr);

    int i = 0;
    scanf("%i", &i);

    if (feof(stdin))
        return INT_MAX;

    return i;
}