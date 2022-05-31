/**
 *
 */
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0;

    do
    {
        i = get_int("Enter value: ");
    } while (i < 1);

    printf("%i\n", i);

    return 0;
}