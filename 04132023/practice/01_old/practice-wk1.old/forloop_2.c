#include <stdio.h>

int main(void)
{
    for (int h = 0; h < 5; h++)
    {
        for (int i = 0; i < 5; i++) // prints *****
        {
            printf("*");
        }
        printf("\n");
    }
}
