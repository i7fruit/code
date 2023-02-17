#include <stdio.h>

int get_integer(char arr[]);

int main(void)
{
    int x = 0;

    x = get_integer("x: ");

    printf("%i\n", x);
}

int get_integer(char arr[])
{
    int i = 0;

    printf("%s", arr);
    scanf("%i", &i);

    return i;
}