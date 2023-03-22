#include <stdio.h>
#include <limits.h>

int get_int(char arr[]);

int main(void)
{
    int numbers[5];

    int i = 0, count = 0;

    while (i < 5)
    {
        int number = get_int("Number: ");

        if (number == INT_MAX)
            break;

        numbers[i] = number;
        count++;

        i++;
    }

    for (int j = 0; j < count; j++)
        printf("%i ", numbers[j]);
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