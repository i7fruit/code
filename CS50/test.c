#include <stdio.h>

int main(void)
{
    unsigned number = 0;

    do
    {
        printf("Enter a positive integer to reverse: ");
        scanf("%u", &number);
    } while (number <= 0);

    printf("%i\n", number);

    return 0;
}