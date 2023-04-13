#include <stdio.h>

int main(void)
{
    for (char c = 'A'; c <= 'z'; c++)
    {
        if ((c > 90) && (c < 97))
        {
            c++;
            if (c == 96)
            {
                putchar('\n');
            }
        }
        
        else
        {
            printf("%c is %i\n", c , c); // Can also be written as
                                     // printf("%c is %c\n", c , (int)c);
        }
    }
    return 0;
}