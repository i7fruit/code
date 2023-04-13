#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float i, C;
    float F = 20;
    
    for(i = 0; i < 20; i++)
    {
        C = (5.0/9.0) * (F - 32);
        printf("%6.1fF%9.1fC\n", F, C);
        F+= 20;
    }
}
