#include <stdio.h>
#include <cs50.h>

void hi_there(int n);

int main(void)
{
    int n;
    do
    {
        printf("Please enter a number: ");
        n = get_int();
    }
    while(n < 0);

    hi_there(n);

    printf("\n");
}

void hi_there(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("What's up! ");
    }
}
