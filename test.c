#include <stdio.h>
#include <limits.h>

int main(void)
{
    char string[] = "Constant string.";

    char *ptr = string;

    printf("%c\n", *(ptr+3));

    return 0;
}