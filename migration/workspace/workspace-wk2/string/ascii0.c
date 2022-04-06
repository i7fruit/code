#include <stdio.h>

int main()
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", (char)i, i); // Typecasts the int as a char to get its equivalent ASCII char
                                          // However, printf can implicitly cast the int as a char if you don't typecast
    }
    
    return 0;
}