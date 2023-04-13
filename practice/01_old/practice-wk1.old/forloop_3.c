#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i;
    for (int h = 0; h < 5; h++)
    {
        
        for (i = 0; i < h; i++) /* prints *
                                              **/
        {
            printf("*");
        }
        printf("\n");
    }
}
