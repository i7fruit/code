#include <stdio.h>

void display_name(void);
int main(void)
{
    for(int row = 0; row < 3; row++)
    {
    display_name();
    printf("\n");
    }
}

void display_name(void)
{
    printf("Billy");
}
