/**
 * 00_draw.c
 *
 * Friday, February 17 2023, 09:37hrs
 *
 * This program prints a triangle using
 * a recursive function
*/
#include <stdio.h>

// Function prototype
int get_integer(char arr[]);
void draw(int i);

int main(void)
{
    int size = get_integer("Enter size between 1 and 20: ");

    draw(size);

    return 0;
}

/****************************************
 * get_integer() prompts the user for an integer
*/
int get_integer(char arr[])
{
    int i = 0;

    do
    {
        printf("%s\n", arr);
        scanf("%i", &i);
    }
    while (i < 1 || i > 20);

    return i;
}

/********************************************
 * draw()
*/
void draw(int i)
{
    if (i == 0)
        return;

    draw(i - 1);

    for (int j = 0; j < i; j++)
        printf("#");

    putchar('\n');
}