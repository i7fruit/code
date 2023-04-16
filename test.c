#include <stdio.h>
#include <limits.h>

int main(void)
{
    char string[] = "Constant string.";

    printf("%s\n", **string);

    return 0;
}