#include <stdio.h>
#include <limits.h>

int main(void)
{
    char string[] = "Constant string.";

    char *ptr = string;

    ptr = "New";

    printf("%s\n", string);

    return 0;
}